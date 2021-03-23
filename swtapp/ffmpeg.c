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
    char errors[1024] = {0,};
    AVFormatContext *fmt_ctx = NULL;
    //[[video device]:[audio device]]
    char *devicename = ":0";
    AVDictionary *option = NULL;
    
    //av packet
    int count = 0;
    AVPacket pkt;
    
    //register all device
    avdevice_register_all();
    
    //get format
    AVInputFormat  *iFormat = av_find_input_format("avfoundation");
    
    //open  input
    if ((ret = avformat_open_input(&fmt_ctx, devicename, iFormat,
                                   &option)) < 0 ) {
        av_strerror(ret, errors, 1024);
        av_log(NULL, AV_LOG_ERROR, " Failed to open audio device, [%d] %s\n",ret,errors);
        return;
    }
    
    //av init
    av_init_packet(&pkt);
  
    while (count++<500) {
        ret = av_read_frame(fmt_ctx, &pkt);
        if (ret >=0) {
            av_log(NULL, AV_LOG_INFO,
                                 "packet size is %d(%p)\n",
                                 pkt.size, pkt.data);
        }
        av_packet_unref(&pkt);
    }
    
//    while ((ret = av_read_frame(fmt_ctx, &pkt)) == 0 &&
//           count++ <500) {
//        av_log(NULL, AV_LOG_INFO,
//                     "packet size is %d(%p)\n",
//                     pkt.size, pkt.data);
//        av_packet_unref(&pkt);
//    }
    
    avformat_close_input(&fmt_ctx);
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "HW ffmpeg log...\n");
    
    return;
}
