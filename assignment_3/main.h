#ifndef MAIN_H
#define MAIN_H

#define GLEW_STATIC

// Workaround for compile on macOS
#ifdef __APPLE__
#include <GL/glew.h>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "../third_party/glm/glm/gtc/type_ptr.hpp"
#include "../third_party/glm/glm/mat4x4.hpp"

// The debug function/macro below were extracted from:
//     https://stackoverflow.com/a/11258474/6107321
void CheckOpenGLError(const char* stmt, const char* fname, int line) {
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        printf("OpenGL error %08x, at %s:%i - for %s\n", err, fname, line,
               stmt);
        abort();
    }
}

#ifdef DEBUG
#define GL_CHECK(stmt)                               \
    do {                                             \
        stmt;                                        \
        CheckOpenGLError(#stmt, __FILE__, __LINE__); \
    } while (0)
#else
#define GL_CHECK(stmt) stmt
#endif

#endif  // MAIN_H
