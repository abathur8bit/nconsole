//
// Created by lee on 12/29/2018.
//

#include <jni.h>

#ifndef NCONSOLE_NCONSOLE_WIN_H
#define NCONSOLE_NCONSOLE_WIN_H

#define MAX_PAIRS 		8
#define COLOR_BLACK		0
#define COLOR_RED		FOREGROUND_RED
#define COLOR_GREEN		FOREGROUND_GREEN
#define COLOR_YELLOW	(FOREGROUND_RED|FOREGROUND_GREEN)
#define COLOR_BLUE		FOREGROUND_BLUE
#define COLOR_MAGENTA	(FOREGROUND_RED|FOREGROUND_BLUE)
#define COLOR_CYAN		(FOREGROUND_GREEN|FOREGROUND_BLUE)
#define COLOR_WHITE		0xF


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

#endif //NCONSOLE_NCONSOLE_WIN_H
