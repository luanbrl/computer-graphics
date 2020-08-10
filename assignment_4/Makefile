CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -O0 -g3 -DDEBUG
SOURCES = main.cpp
OUTPUT = shading_gl

# Workaround for compile on macOS
OS := $(shell uname)
ifeq ($(OS),Darwin)
LFLAGS = -framework GLUT -framework OpenGL -framework CoreVideo -lm -lGLEW -L/usr/local/lib-Wno-deprecated
else
LFLAGS = -lglut -lGLEW -lGLU -lGL
endif

all:
	$(CC) $(CFLAGS) $(SOURCES) $(LFLAGS) -o $(OUTPUT)

clean:
	rm shading_gl
