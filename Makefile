main: main.c
	clang -O0 -ggdb -I./raylib-6.0_linux_amd64/include/ -Wall -Wextra -Wno-missing-field-initializers -Wno-unused-variable -o main main.c prof_gather.c prof_process.c prof_draw.c prof_linux.c -L./raylib-6.0_linux_amd64/lib/ -l:libraylib.a -lm -lX11

.PHONY: run
run: main
	./main
