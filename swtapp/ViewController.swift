//
//  ViewController.swift
//  swtapp
//
//  Created by 陈辉 on 2021/3/22.
//

import Cocoa

class ViewController: NSViewController {
    
    var recStatus :Bool = false
    var thread :Thread?
    let btn = NSButton.init(title: "button", target: nil, action: nil)
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.setFrameSize(NSSize(width: 320, height: 240))
        
        btn.title = "录制";
        btn.frame = NSRect(x: 320/2-40, y: 240/2-15, width: 80, height: 30)
        btn.bezelStyle = .rounded
        btn.setButtonType(.pushOnPushOff)
        
        btn.target = self
        btn.action = #selector(myFunc)
        
        self.view.addSubview(btn)
    }
    
    @objc
    func myFunc() {
        self.recStatus = !self.recStatus
        if recStatus {
            thread = Thread.init(target: self, selector:#selector(self.recAudio),object:nil)
            thread?.start()
            self.btn.title = "停止";
        }else {
            set_rec_status(0)
            self.btn.title = "录制";
        }
    }
    
    @objc
    func recAudio()  {
        callFFmpeg()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

