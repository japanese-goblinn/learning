//
//  ViewController.swift
//  GitstWithOAuth
//
//  Created by Kirill Gorbachyonok on 8/28/19.
//  Copyright © 2019 saisuicied. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var tableView: UITableView!
    
    private var gists: [Gist]?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let vc = AuthenticationViewController()
        vc.delegate = self
        navigationController?.pushViewController(vc, animated: true)
    }
    
    private func getToken(for code: String) {
        guard var component = URLComponents(string: "https://github.com/login/oauth/access_token" ) else { return }
        component.queryItems = [
            URLQueryItem(name: "client_id", value: Constants.client_id.rawValue),
            URLQueryItem(name: "client_secret", value: Constants.client_secret.rawValue),
            URLQueryItem(name: "code", value: code)
        ]
        guard let url = component.url else { return }
        var request = URLRequest(url: url)
        request.httpMethod = "POST"
        request.setValue("application/json", forHTTPHeaderField: "Accept")
        URLSession.shared.dataTask(with: request) { [weak self] (data, response, error) in
            guard let response = response as? HTTPURLResponse else {
                print("BAD RESPONSE")
                return
            }
            switch response.statusCode {
            case 200..<300:
                print("OK")
            default:
                print("BAD STATUS CODE \(response.statusCode)")
            }
            guard let data = data else { return }
            let json = try! JSONDecoder().decode(ResponseGist.self, from: data)
            guard let self = self else {
                print("self is nil")
                return
            }
            self.getGists(for: json.access_token)
        }
        .resume()
    }
    

    private func getGists(for token: String) {
        guard let url = URL(string: "https://api.github.com/gists") else {
            print("BAD URL")
            return
        }
        var request = URLRequest(url: url)
        request.setValue("token \(token)", forHTTPHeaderField: "Authorization")
        let requestTask = URLSession.shared.dataTask(with: request) { [weak self] (data, response, error) in
            guard let data = data else {
                 print("BAD DATA")
                return
            }
            let gistJson = try? JSONDecoder().decode([Gist].self, from: data)
            guard let gists = gistJson else {
                print("BAD JSON")
                return
            }
            DispatchQueue.main.async { [weak self] in
                guard let self = self else {
                    print("BAD SELF")
                    return
                }
                self.gists = gists
                self.tableView.reloadData()
            }
        }
        requestTask.resume()
    }
    
    private func normalFormat(for date: String) -> String? {
        let dateFormater = DateFormatter()
        dateFormater.dateFormat = "yyyy-MM-dd'T'HH:mm:ssZ"
        guard let fixedDate = dateFormater.date(from: date) else {
            return nil
        }
        dateFormater.dateFormat = "d MMM, yyyy"
        return dateFormater.string(from: fixedDate)
    }
}

extension ViewController: Tokenable {
    func handleToken(for code: String) {
        getToken(for: code)
    }
}

extension ViewController: UITableViewDataSource, UITableViewDelegate {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return gists?.count ?? 0
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 100.0
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath) as! GistTableViewCell
        guard let gist = gists?[indexPath.row] else {
            return cell
        }
        cell.commentsAmountLabel.text = "Amount of comments: \(gist.comments)"
        cell.dateLabel.text = normalFormat(for: gist.created_at) ?? ""
        cell.isPublicLabel.text = "Public: \(gist.public)"
        return cell
    }
}
