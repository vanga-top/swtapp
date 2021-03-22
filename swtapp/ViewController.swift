//
//  ViewController.swift
//  swtapp
//
//  Created by 陈辉 on 2021/3/22.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.setFrameSize(NSSize(width: 320, height: 240))
        let btn = NSButton.init(title: "button", target: nil, action: nil)
        btn.frame = NSRect(x: 320/2-40, y: 240/2-15, width: 80, height: 30)
        btn.bezelStyle = .rounded
        btn.setButtonType(.pushOnPushOff)
        
        btn.target = self
        btn.action = #selector(myFunc)
        
        self.view.addSubview(btn)
    }
    
    @objc
    func myFunc() {
        callFFmpeg()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

