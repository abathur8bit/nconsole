# nconsole
JNI console library, to provide some native console access.

This isn't meant to be an implementation of ncurses. It's just to give some common console cursor control.

.idea - idea project directory for C++ part of the project.

nconsole.iml is the IntelliJ Java project file.

## Windows 
[Console programming on Windows](https://docs.microsoft.com/en-us/windows/console/console-reference)

# Building
Building on Linux if you don't have cmake

```
g++ -shared -o libnconsole.so -fPIC -I/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.9.x86_64/include -I/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.9.x86_64/include/linux -lncurses ncurses.cpp
```


[garfield]: https://github.com/abathur8bit/garfield
[nconsole]: https://github.com/abathur8bit/nconsole
