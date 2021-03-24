//
//  ffmpeg.c
//  swtapp
//
//  Created by 陈辉 on 2021/3/22.
//

#include "ffmpeg.h"

static int rec_status = 0;

void callFFmpeg (){
    printf("c ... call\r\n");
    
    int ret = 0;
    char errors[1024] = {0,};
    AVFormatContext *fmt_ctx = NULL;
    //[[video device]:[audio device]]
    char *devicename = ":0";
    AVDictionary *option = NULL;
    
    //av packet
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
    
    
    //create file
    char *out ="/Users/chenhui/qiniu/temp/1.pcm";
    FILE *outFile = fopen(out, "wb+");
    
    
    //av init
    av_init_packet(&pkt);
    
    rec_status = 1;
    
    //重采样
    SwrContext *swr_ctx = NULL;
    swr_ctx = swr_alloc_set_opts(NULL, AV_CH_LAYOUT_STEREO,AV_SAMPLE_FMT_S16, 44100, AV_CH_LAYOUT_STEREO, AV_SAMPLE_FMT_FLT, 44100, 0, NULL);
  
    if (!swr_ctx) {
        return;
    }
    if (swr_init(swr_ctx)!=0) {
        return;
    }
    
    
    while (rec_status > 0) {
        ret = av_read_frame(fmt_ctx, &pkt);
        if (ret >=0) {
            av_log(NULL, AV_LOG_INFO, "packet size is %d(%p)\n", pkt.size, pkt.data);
            fwrite(pkt.data, pkt.size, 1, outFile);
            fflush(outFile);
        }
        av_packet_unref(&pkt);
    }
    
    fclose(outFile);
    
    
    avformat_close_input(&fmt_ctx);
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "stop record audio........\n");
    
    return;
}


void set_rec_status(int status) {
    rec_status = status;
}
