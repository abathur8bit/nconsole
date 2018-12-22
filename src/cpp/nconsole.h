#include <jni.h>

#ifndef JNI_LIBRARY_H
#define JNI_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_add(JNIEnv *env, jobject obj, jint num);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initscr(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_hasColors(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_endwin(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_move(JNIEnv *env, jobject obj, jint x,jint y);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getch(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_timeout(JNIEnv *env, jobject obj,jint delayms);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenWidth(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenHeight(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_refresh(JNIEnv *env, jobject obj);
/*
 * Class:     NConsole
 * Method:    printw
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printw(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenter(JNIEnv *, jobject, jstring);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenterX(JNIEnv *, jobject, jint, jstring);

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initPair(JNIEnv *env, jobject obj, jint pair, jint fg, jint bg);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attron(JNIEnv *env, jobject obj, jint pair);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attroff(JNIEnv *env, jobject obj, jint pair);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clear(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtobot(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtoeol(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif

#endif