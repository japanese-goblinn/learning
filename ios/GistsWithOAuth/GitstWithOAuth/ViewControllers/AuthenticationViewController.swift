//
//  AuthenticationViewController.swift
//  GitstWithOAuth
//
//  Created by Kirill Gorbachyonok on 8/28/19.
//  Copyright © 2019 saisuicied. All rights reserved.
//

import UIKit
import WebKit

protocol Tokenable: AnyObject {
    func handleToken(for code: String)
}

class AuthenticationViewController: UIViewController {
    
    weak var delegate: Tokenable?
    
    private let webView = WKWebView()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        setupViews()
        guard let request = authGetRequest() else { return }
        webView.load(request)
        webView.navigationDelegate = self
    }
    
    private func authGetRequest() -> URLRequest? {
        guard var components = URLComponents(string: "https://github.com/login/oauth/authorize") else {
            return nil
        }
        components.queryItems = [
            URLQueryItem(name: "client_id", value: Constants.client_id.rawValue),
            URLQueryItem(name: "scope", value: "gist")
        ]
        guard let url = components.url else {
            return nil
        }
        return URLRequest(url: url)
    }
    
    private func setupViews() {
        view.backgroundColor = .white
        
        webView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(webView)
        NSLayoutConstraint.activate([
            webView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            webView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            webView.topAnchor.constraint(equalTo: view.topAnchor),
            webView.bottomAnchor.constraint(equalTo: view.bottomAnchor)
        ])
    }
}

extension AuthenticationViewController: WKNavigationDelegate {
    
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        if let url = navigationAction.request.url, url.scheme == "gists" {
            let targetString = url.absoluteString.replacingOccurrences(of: "#", with: "?")
            guard let components = URLComponents(string: targetString) else { return }
            
            if let code = components.queryItems?.first(where: { $0.name == "code" })?.value {
                delegate?.handleToken(for: code)
            }
            self.navigationController?.popViewController(animated: true)
        }
        do {
            decisionHandler(.allow)
        }
    }
}
