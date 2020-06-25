#ifndef MYGL_H
#define MYGL_H

#include "core.h"
#include "frame_buffer.h"

#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
} Color;

typedef struct {
    Coordinate coord;
    Color color;
} Pixel;

Coordinate setCoordinate(int x, int y);
Color setColor(int red, int green, int blue, int alpha);
Pixel setPixel(Coordinate coord, Color color);
Color getGradientColor(Pixel p1, Pixel p2);

void PutPixel(Pixel p, Color color);
void DrawLine(Pixel p1, Pixel p2);
void DrawTriangle(Pixel p1, Pixel p2, Pixel p3);
void MyGlDraw(void);

#endif  // MYGL_H
