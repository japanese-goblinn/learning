//
//  GistTableViewCell.swift
//  GitstWithOAuth
//
//  Created by Kirill Gorbachyonok on 8/29/19.
//  Copyright © 2019 saisuicied. All rights reserved.
//

import UIKit

class GistTableViewCell: UITableViewCell {

    @IBOutlet weak var isPublicLabel: UILabel!
    
    @IBOutlet weak var commentsAmountLabel: UILabel!
    
    @IBOutlet weak var dateLabel: UILabel!
    
    
    override func awakeFromNib() {
        super.awakeFromNib()
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }

}
