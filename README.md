# nconsole
JNI console library, to provide native console access. This isn't meant to be an implementation of ncurses. 
It's just to give some common console control, like colors and cursor control. Under macOS and Linux, this 
does end up using ncurses. 

.idea - idea project directory for C++ part of the project.

nconsole.iml is the IntelliJ Java project file.

## Windows 
No build for Windows yet. Planning to add that soon. Would like to use the native Windows console API.

Build a DLL in Windows: 

```
cl -I\java\jdk1.8.0_45\include -I\java\jdk1.8.0_45\include\win32 -LD nconsole.cpp -Fenconsole.dll
```

[Console programming on Windows](https://docs.microsoft.com/en-us/windows/console/console-reference)

# Building 
Build the shared library first, then the Java library you will use for other projects.

## Shared library
When building on Linux if you don't have cmake: 

```
g++ -shared -o libnconsole.so -fPIC -I/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.9.x86_64/include -I/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.9.x86_64/include/linux -lncurses ncurses.cpp
```

When building on Linux with cmake:

```
cmake CMakeLists.txt
make
```

## Java library
Then build the java lib, which results in nconsole.jar put in the current directory:

```
mkdir -p classes
javac -d classes src/java/com/axorion/NConsole.java
jar cvf nconsole.jar -C classes .
```

[garfield]: https://github.com/abathur8bit/garfield
[nconsole]: https://github.com/abathur8bit/nconsole
