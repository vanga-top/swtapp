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
    let btn_audio = NSButton.init(title: "button", target: nil, action: nil)
    
    let btn_vdieo = NSButton.init(title: "录制视频", target: nil, action: nil)
    var recVideoStatus :Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.setFrameSize(NSSize(width: 320, height: 240))
        
        //audio record
        btn_audio.title = "录制音频";
        btn_audio.frame = NSRect(x: 320/2-10, y: 240/2-15, width: 80, height: 30)
        btn_audio.bezelStyle = .rounded
        btn_audio.setButtonType(.pushOnPushOff)
        
        btn_audio.target = self
        btn_audio.action = #selector(recAudioAction)
        
        self.view.addSubview(btn_audio)
        
        //video record
        btn_vdieo.frame = NSRect(x: 320/2-100, y: 240/2-15, width: 80, height: 30)
        btn_vdieo.bezelStyle = .rounded
        btn_vdieo.setButtonType(.pushOnPushOff)
        btn_vdieo.target = self
        btn_vdieo.action = #selector(recVideoAction)
        
        self.view.addSubview(btn_vdieo)
        
    }
    
    @objc
    func recVideoAction()  {
        
    }
    
    @objc
    func recAudioAction() {
        self.recStatus = !self.recStatus
        if recStatus {
            thread = Thread.init(target: self, selector:#selector(self.recAudio),object:nil)
            thread?.start()
            self.btn_audio.title = "停止音频";
        }else {
            set_rec_status(0)
            self.btn_audio.title = "录制音频";
        }
    }
    
    @objc
    func recAudio()  {
        rec_audio()
        //rec_video()
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }


}

