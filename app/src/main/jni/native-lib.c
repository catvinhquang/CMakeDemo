#include <jni.h>
#include "libavcodec/avcodec.h"

//
// Created by quangcat on 09/12/2016.
//

JNIEXPORT jstring JNICALL
                 Java_vn_com_vng_quangcv_cmakedemo_MainActivity_stringFromJNI(JNIEnv *env,
                                                                              jobject instance)
{
    char info[10000] = { 0 };
    sprintf(info, "%s\n%s", "Hello from FFmpeg!", avcodec_configuration());
    return (*env)->NewStringUTF(env, info);
}