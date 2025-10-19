# force rebuild, while deps isn't working
.PHONY: libgba.so clean run runc

all: libgba.so main

EMBEDFLAGS=-O3 -fvisibility=hidden -static-libstdc++ -fPIC -Wfatal-errors -Werror -Wno-narrowing
# CFLAGS=-fvisibility=hidden -ffreestanding -nostdlib -fPIC -O3 -Wfatal-errors -Werror
SRCS := $(wildcard src/gba/*.c)
libgba.so: libgba.c corelib.h
	time $(CC) $(CFLAGS) $(EMBEDFLAGS) -I include/ -I src/ -shared -o libgba.so libgba.c $(SRCS)
	cp libgba.so libapu.so
	echo "libgba done"

main: main.c corelib.h
	time $(CXX) -O3 -o main main.c -L. -l:libgba.so -lSDL2 -lc -lm ${WARN}
	echo "main done"

clean:
	rm -f libgba.so main

gdb:
	LD_LIBRARY_PATH=$(shell pwd) gdb --args ./main "$(ROM)"
run:
	LD_LIBRARY_PATH=$(shell pwd) ./main "$(ROM)"
runc:
	LD_LIBRARY_PATH=$(shell pwd) ./main "$(ROM)" c
	
