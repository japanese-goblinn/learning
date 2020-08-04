//
//  Responce.swift
//  GitstWithOAuth
//
//  Created by Kirill Gorbachyonok on 8/30/19.
//  Copyright © 2019 saisuicied. All rights reserved.
//

import Foundation

struct ResponseGist: Decodable {
    let access_token: String
    let scope: String
    let token_type: String
}
