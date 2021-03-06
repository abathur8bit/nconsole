package com.axorion;

public class NConsole {
    private int width,height;
    private boolean screenSizeChanged;

    public native int add(int n);
    public native int getch();
    /** Sets the timeout for getch() call. -1 blocks, 0 non blocking, >0 milliseconds to wait. */
    public native int timeout(int delayms);
    public native int initscr();
    public native int hasColors();
    /** Move cursor to the specified location. Note that it is x,y not y,x like curses. */
    public native int move(int x,int y);
    public native int endwin();
    public native int printw(String s);
    public native int printCenter(String s);
    public native int printCenterX(int y,String s);
    public native int initPair(int pair,int fg,int bg);
    public native int attron(int pair);
    public native int attroff(int pair);
    public native int clear();
    public native int clrtobot();
    public native int clrtoeol();
    public native int refresh();

    private native int getScreenWidth();
    private native int getScreenHeight();

    public static int COLOR_BLACK=0;
    public static int COLOR_RED=1;
    public static int COLOR_GREEN=2;
    public static int COLOR_YELLOW=3;
    public static int COLOR_BLUE=4;
    public static int COLOR_MAGENTA=5;
    public static int COLOR_CYAN=6;
    public static int COLOR_WHITE=7;

    public void home() {
        move(0,0);
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public boolean updateSize() {
        boolean screenSizeChanged = false;
        int newWidth = getScreenWidth();
        int newHeight = getScreenHeight();
        if(newWidth != width || newHeight != height) {
            screenSizeChanged = true;
            width = newWidth;
            height = newHeight;
        }
        return screenSizeChanged;
    }

    public NConsole() {
        System.loadLibrary("nconsole");
        updateSize();
    }

    //java -Djava.library.path=cmake-build-debug NConsole
    public static void main( String[] args ) {
        int ch;
        boolean running = true;
        NConsole app = new NConsole();
        int result = app.add(5);
        System.out.println("Result from native call is " + result);


        app.initscr();
        app.initPair(1,7,COLOR_BLUE);
        app.initPair(2,COLOR_WHITE,COLOR_RED);

        String title = "NCursor Test";
        String msg = "Screen Size: ["+app.getScreenWidth()+"x"+app.getScreenHeight()+"]";
        app.attron(1);
        app.printCenter(title);
        app.attroff(1);
        app.printCenterX(app.getScreenHeight()/2+2,msg);

        app.home();
        do {
            ch = app.getch();
            app.printw("typed ["+ch+"]");
            if(ch == 'q')
                running = false;
        } while(running);

        app.endwin();

        System.out.println("Typed ["+ch+"]");
    }
}
