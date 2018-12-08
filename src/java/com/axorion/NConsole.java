public class NConsole {
    public native int add(int n);
    public native int getch();
    public native int initscr();
    public native int move(int x,int y);
    public native int endwin();
    public native int printw(String s);
    public native int init_pair(int pair,int fg,int bg);
    public native int attron(int pair);
    public native int attroff(int pair);
    public native int clear();
    public native int clrtobot();
    public native int clrtoeol();

    public static int COLOR_BLACK=0;
    public static int COLOR_RED=1;
    public static int COLOR_GREEN=2;
    public static int COLOR_YELLOW=3;
    public static int COLOR_BLUE=4;
    public static int COLOR_MAGENTA=5;
    public static int COLOR_CYAN=6;
    public static int COLOR_WHITE=7;

    //java -Djava.library.path=cmake-build-debug NConsole
    public static void main( String[] args ) {
        boolean running = true;
        System.out.println("Hello, loading native lib");
        System.loadLibrary("jni");
        JCurses app = new JCurses();
        int result = app.add(5);
        System.out.println("Result from native call is " + result);

        app.initscr();
//        app.init_pair(1,COLOR_YELLOW,COLOR_BLUE);
//        app.init_pair(2,COLOR_WHITE,COLOR_RED);
//        app.attron(1);
//        app.clear();
//        app.attroff(1);
        app.move(20,20);
        int ch = -1;
        do {
            ch = app.getch();
            app.move(0,0);
            app.printw("typed ["+ch+"]");
            if(ch == 'q')
                running = false;
        } while(running);
        app.endwin();

        System.out.println("Typed ["+ch+"]");
    }
}
