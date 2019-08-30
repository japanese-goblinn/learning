//
//  GistModel.swift
//  GitstWithOAuth
//
//  Created by Kirill Gorbachyonok on 8/28/19.
//  Copyright © 2019 saisuicied. All rights reserved.
//

import Foundation


struct Gist: Decodable {
    let created_at: String
    let `public`: Bool
    let comments: Int
    let files: [String: GistFile]
    let owner: Owner
}

struct Owner: Decodable {
    let login: String
    let id: Int
}

struct GistFile: Decodable {
    let filename: String
    let type: String
    let language: String
    let size: Int
}

