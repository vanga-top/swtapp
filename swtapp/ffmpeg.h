//
//  ffmpeg.h
//  swtapp
//
//  Created by 陈辉 on 2021/3/22.
//

#ifndef ffmpeg_h
#define ffmpeg_h

#include <stdio.h>
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswresample/swresample.h"

void callFFmpeg(void);
void set_rec_status(int status);

#endif /* ffmpeg_h */
