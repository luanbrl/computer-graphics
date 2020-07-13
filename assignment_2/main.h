#ifndef MAIN_H
#define MAIN_H

// Workaround for compile on macOS
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#endif  // MAIN_H
