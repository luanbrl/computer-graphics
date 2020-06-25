#ifndef MAIN_H
#define MAIN_H

// Workaround for compile on macOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "mygl.h"

#endif  // MAIN_H
