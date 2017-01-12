# Ref: https://github.com/googlesamples/android-ndk/blob/master/hello-libs/app/src/main/cpp/CMakeLists.txt
# Ref: http://www.jianshu.com/p/1dec1ae3da6b/comments/5003158

cmake_minimum_required(VERSION 3.4.1)

set(lib_src_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})

add_library(avcodec-lib SHARED IMPORTED)
set_target_properties(avcodec-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavcodec.so)

add_library(avdevice-lib SHARED IMPORTED)
set_target_properties(avdevice-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavdevice.so)

add_library(avfilter-lib SHARED IMPORTED)
set_target_properties(avfilter-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavfilter.so)

add_library(avformat-lib SHARED IMPORTED)
set_target_properties(avformat-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavformat.so)

add_library(avresample-lib SHARED IMPORTED)
set_target_properties(avresample-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavresample.so)

add_library(avutil-lib SHARED IMPORTED)
set_target_properties(avutil-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libavutil.so)

add_library(postproc-lib SHARED IMPORTED)
set_target_properties(postproc-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libpostproc.so)

add_library(swresample-lib SHARED IMPORTED)
set_target_properties(swresample-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libswresample.so)

add_library(swscale-lib SHARED IMPORTED)
set_target_properties(swscale-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libswscale.so)

add_library(x264-lib SHARED IMPORTED)
set_target_properties(x264-lib PROPERTIES IMPORTED_LOCATION ${lib_src_DIR}/libx264.so)

add_library(native-lib SHARED ${CMAKE_SOURCE_DIR}/src/main/jni/native-lib.c)

target_include_directories(native-lib PRIVATE
                           ${CMAKE_SOURCE_DIR}/src/main/jni/include)

target_link_libraries(native-lib
                      log
                      android
                      avcodec-lib
                      avdevice-lib
                      avfilter-lib
                      avformat-lib
                      avresample-lib
                      avutil-lib
                      postproc-lib
                      swresample-lib
                      swscale-lib
                      x264-lib)
