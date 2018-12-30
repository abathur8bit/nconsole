//
// Created by lee on 12/29/2018.
//

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "nconsole-win.h"


HANDLE hStdout, hStdin;
CONSOLE_SCREEN_BUFFER_INFO csbi;
DWORD fdwOldMode;
WORD wOldColorAttrs;

int screenWidth=0,screenHeight=0;
int bufferWidth=0,bufferHeight=0;
int pairs[8][2];

void updateScreenSize() {
    CONSOLE_SCREEN_BUFFER_INFO i;
    if (!GetConsoleScreenBufferInfo(hStdout, &i)) {
//        MessageBox(NULL, TEXT("GetConsoleScreenBufferInfo"),TEXT("Console Error"), MB_OK);
        return;
    }

    screenWidth=i.srWindow.Right+1;
    screenHeight=i.srWindow.Bottom+1;
    bufferWidth=i.dwSize.X;
    bufferHeight=i.dwSize.Y;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_add(JNIEnv *env, jobject obj, jint num)
{
    return num+num;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initscr(JNIEnv *env, jobject obj)
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hStdin = GetStdHandle(STD_INPUT_HANDLE);

    if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
//        MessageBox(NULL, TEXT("GetConsoleScreenBufferInfo"),TEXT("Console Error"), MB_OK);
        return 0;
    }

    wOldColorAttrs = csbi.wAttributes;
    screenWidth=csbi.srWindow.Right+1;
    screenHeight=csbi.srWindow.Bottom+1;
    bufferWidth=csbi.dwSize.X;
    bufferHeight=csbi.dwSize.Y;

    if (!GetConsoleScreenBufferInfo(hStdout, &csbi)) {
//        MessageBox(NULL, TEXT("GetConsoleScreenBufferInfo"),TEXT("Console Error"), MB_OK);
        return 0;
    }

    wOldColorAttrs = csbi.wAttributes;
    screenWidth=csbi.srWindow.Right+1;
    screenHeight=csbi.srWindow.Bottom+1;
    bufferWidth=csbi.dwSize.X;
    bufferHeight=csbi.dwSize.Y;


    // Turn off the line input and echo input modes
    if (!GetConsoleMode(hStdin, &fdwOldMode)) {
//        MessageBox(NULL, TEXT("GetConsoleMode"), TEXT("Console Error"),MB_OK);
        return 0;
    }
    DWORD fdwMode = fdwOldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    if (!SetConsoleMode(hStdin, fdwMode)) {
//        MessageBox(NULL, TEXT("SetConsoleMode"), TEXT("Console Error"),MB_OK);
        return 0;
    }

    return 1;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_hasColors(JNIEnv *env, jobject obj)
{
    return 1;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_endwin(JNIEnv *env, jobject obj)
{
    SetConsoleMode(hStdin, fdwOldMode);					// Restore the original console mode.
    SetConsoleTextAttribute(hStdout, wOldColorAttrs);	// Restore the original text colors.
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_move(JNIEnv *env, jobject obj, jint x,jint y)
{
    COORD coordScreen = { (SHORT)x, (SHORT)y };    // home for the cursor
    SetConsoleCursorPosition(hStdout, coordScreen);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_timeout(JNIEnv *env, jobject obj,jint delayms)
{
    return 1;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getch(JNIEnv *env, jobject obj)
{
    CHAR chBuffer[256];
    DWORD cRead, fdwMode, fdwOldMode;

    if (!GetConsoleMode(hStdin, &fdwOldMode)) {
//        MessageBox(NULL, TEXT("GetConsoleMode"), TEXT("Console Error"),MB_OK);
        return -1;
    }

    fdwMode = fdwOldMode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    if (!SetConsoleMode(hStdin, fdwMode)) {
//        MessageBox(NULL, TEXT("SetConsoleMode"), TEXT("Console Error"),MB_OK);
        return -1;
    }

    ReadFile(hStdin, chBuffer, 1, &cRead, NULL);
    return chBuffer[0];
}


JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printw(JNIEnv * env, jobject obj, jstring string)
{

    const char *str = env->GetStringUTFChars(string, 0);
    printf("%s",str);
    env->ReleaseStringUTFChars(string, str);

    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenter(JNIEnv * env, jobject obj, jstring string)
{
    const char *str = env->GetStringUTFChars(string, 0);
    Java_com_axorion_NConsole_move(NULL,NULL,screenHeight/2,screenWidth/2-strlen(str)/2);
    printf(str);
    env->ReleaseStringUTFChars(string, str);
    return 0;
}


JNIEXPORT jint JNICALL Java_com_axorion_NConsole_printCenterX(JNIEnv * env, jobject obj, jint y, jstring string)
{
    const char *str = env->GetStringUTFChars(string, 0);
    Java_com_axorion_NConsole_move(NULL,NULL,screenWidth/2-strlen(str)/2,y);
    printf(str);
    env->ReleaseStringUTFChars(string, str);
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_initPair(JNIEnv *env, jobject obj, jint pair, jint fg, jint bg)
{
    if(pair<MAX_PAIRS) {
        pairs[pair][0] = fg;
        pairs[pair][1] = bg;
    }
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clear(JNIEnv *env, jobject obj)
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    DWORD dwConSize = bufferWidth*bufferHeight;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(
            hStdout,        // Handle to console screen buffer
            (TCHAR) ' ',     // Character to write to the buffer
            dwConSize,       // Number of cells to write
            coordScreen,     // Coordinates of first cell
            &cCharsWritten))// Receive number of characters written
    {
        return 1;
    }

    if (!FillConsoleOutputAttribute(
            hStdout,         // Handle to console screen buffer
            wOldColorAttrs, // Character attributes to use
            dwConSize,        // Number of cells to set attribute
            coordScreen,      // Coordinates of first cell
            &cCharsWritten)) // Receive number of characters written
    {
        return 1;
    }

    SetConsoleCursorPosition(hStdout, coordScreen);     // Put the cursor at its home coordinates.
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attron(JNIEnv *env, jobject obj, jint pair)
{
    SetConsoleTextAttribute( hStdout, pairs[pair][0] | (pairs[pair][1]*0x10) );
    return 0;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_attroff(JNIEnv *env, jobject obj, jint pair)
{
    SetConsoleTextAttribute(hStdout,wOldColorAttrs);
    return 0;
}

/**
 * The clrtobot and wclrtobot routines erase from the cursor to the end of screen.
 * That is, they erase all lines below  the  cursor in the window.  Also, the
 * current line to the right of the cursor, inclusive, is erased.
 */
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtobot(JNIEnv *env, jobject obj)
{
    return 0;
//    return clrtobot();
}
/**
 * The clrtoeol and wclrtoeol routines erase the current line to the right of the cursor,
 * inclusive, to the end of the current line.
 */
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_clrtoeol(JNIEnv *env, jobject obj)
{
    return 0;//clrtoeol();
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenWidth(JNIEnv *env, jobject obj)
{
    updateScreenSize();
    return screenWidth;
}
JNIEXPORT jint JNICALL Java_com_axorion_NConsole_getScreenHeight(JNIEnv *env, jobject obj)
{
    updateScreenSize();
    return screenHeight;
}

JNIEXPORT jint JNICALL Java_com_axorion_NConsole_refresh(JNIEnv *env, jobject obj)
{
    return 0;//refresh();
}
