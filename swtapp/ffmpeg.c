//
//  ffmpeg.c
//  swtapp
//
//  Created by 陈辉 on 2021/3/22.
//

#include "ffmpeg.h"


void callFFmpeg (){
    printf("c ... call\r\n");
    
    int ret = 0;
    char errors[1024];
    AVFormatContext *fmt_ctx = NULL;
    //[[video device]:[audio device]]
    char *devicename = ":0";
    
    //register all device
    avdevice_register_all();
    
    //get format
    AVInputFormat  *iFormat = av_find_input_format("avfoundation");
    
    ret = avformat_open_input(&fmt_ctx, devicename, iFormat, NULL);
    
    if (ret <0 ) {
        av_strerror(ret, errors, 1024);
        printf(stderr," Failed to open audio device, [%d] %s\n",ret,errors);
        return;
    }
    
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "HW ffmpeg log...\n");
    
    return;
}
