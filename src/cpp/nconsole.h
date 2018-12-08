#include <jni.h>

#ifndef JNI_LIBRARY_H
#define JNI_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_JCurses_add(JNIEnv *env, jobject obj, jint num);
JNIEXPORT jint JNICALL Java_JCurses_initscr(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_JCurses_endwin(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_JCurses_move(JNIEnv *env, jobject obj, jint x,jint y);
JNIEXPORT jint JNICALL Java_JCurses_getch(JNIEnv *env, jobject obj);
/*
 * Class:     JCurses
 * Method:    printw
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_JCurses_printw(JNIEnv *, jobject, jstring);

JNIEXPORT jint JNICALL Java_JCurses_init_pair(JNIEnv *env, jobject obj, jint pair, jint fg, jint bg);
JNIEXPORT jint JNICALL Java_JCurses_attron(JNIEnv *env, jobject obj, jint pair);
JNIEXPORT jint JNICALL Java_JCurses_attroff(JNIEnv *env, jobject obj, jint pair);
JNIEXPORT jint JNICALL Java_JCurses_clear(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_JCurses_clrtobot(JNIEnv *env, jobject obj);
JNIEXPORT jint JNICALL Java_JCurses_clrtoeol(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif

#endif