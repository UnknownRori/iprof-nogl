# Iprof by Sean Barrett without OpenGL dependency

Based on https://www.silverspaceship.com/src/iprof/

What we did in here is got rid of the dependency on OpenGL so you can use any graphical backend 
by implementing callbacks `draw_text`, `text_width`, `draw_rectangle`, and `draw_line`.

## Quick Start

Tested only on Linux and Windows 11 so far.

```console
$ meson setup builddir
$ meson compile -C builddir
$ ./builddir/iprof
```
