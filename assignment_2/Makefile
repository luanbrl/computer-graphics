CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -O0
SOURCES = main.c
OUTPUT = moderngl_hello_world

# Workaround for compile on macOS
OS := $(shell uname)
ifeq ($(OS),Darwin)
LFLAGS = -framework GLUT -framework OpenGL -Wno-deprecated
else
LFLAGS = -lglut -lGLU -lGL
endif

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LFLAGS) -o $(OUTPUT)

clean:
	rm $(OUTPUT)

