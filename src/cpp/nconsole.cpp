#include "nconsole.h"

#include <string.h>
#include <curses.h>

int screenWidth=0,screenHeight=0;

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_add(JNIEnv *env, jobject obj, jint num)
{
    return num+num;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initscr(JNIEnv *env, jobject obj)
{
    printf("Hello from native\n");
    initscr();
    raw();
    noecho();
    if(has_colors()) {
        move(0,0);
        printw("Has colors");
        getch();
        start_color();
    } else {
        move(0,0);
        printf("No colors");
        getch();
    }
    printf("Good bye from native\n");

    getmaxyx(stdscr,screenHeight,screenWidth);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_hasColors(JNIEnv *env, jobject obj)
{
    return has_colors();
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_endwin(JNIEnv *env, jobject obj)
{
    return endwin();
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_move(JNIEnv *env, jobject obj, jint x,jint y)
{
    return move(y,x);
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getch(JNIEnv *env, jobject obj)
{
    return getch();
}


JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printw(JNIEnv * env, jobject obj, jstring string)
{

    const char *str = env->GetStringUTFChars(string, 0);
    int retval = printw("%s",str);
    env->ReleaseStringUTFChars(string, str);

    return retval;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenter(JNIEnv * env, jobject obj, jstring string)
{
    const char *str = env->GetStringUTFChars(string, 0);
    move(screenHeight/2,screenWidth/2-strlen(str)/2);
    printw(str);
    env->ReleaseStringUTFChars(string, str);
    return 0;
}


JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenterX(JNIEnv * env, jobject obj, jint y, jstring string)
{
    const char *str = env->GetStringUTFChars(string, 0);
    move(y,screenWidth/2-strlen(str)/2);
    printw(str);
    env->ReleaseStringUTFChars(string, str);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initPair(JNIEnv *env, jobject obj, jint pair, jint fg, jint bg)
{
    return init_pair(pair,fg,bg);
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clear(JNIEnv *env, jobject obj)
{
    return clear();
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attron(JNIEnv *env, jobject obj, jint pair)
{
    return  (COLOR_PAIR(pair));
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attroff(JNIEnv *env, jobject obj, jint pair)
{
    return attroff(COLOR_PAIR(pair));;
}

/**
 * The clrtobot and wclrtobot routines erase from the cursor to the end of screen.
 * That is, they erase all lines below  the  cursor in the window.  Also, the
 * current line to the right of the cursor, inclusive, is erased.
 */
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtobot(JNIEnv *env, jobject obj)
{
    return clrtobot();
}
/**
 * The clrtoeol and wclrtoeol routines erase the current line to the right of the cursor,
 * inclusive, to the end of the current line.
 */
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtoeol(JNIEnv *env, jobject obj)
{
    return clrtoeol();
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenWidth(JNIEnv *env, jobject obj)
{
//    getmaxyx(stdscr,screenHeight,screenWidth);
    return screenWidth;
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenHeight(JNIEnv *env, jobject obj)
{
//    getmaxyx(stdscr,screenHeight,screenWidth);
    return screenHeight;
}
