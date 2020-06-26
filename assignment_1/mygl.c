#include "mygl.h"

Coordinate setCoordinate(int x, int y) {
    Coordinate coord;
    coord.x = x;
    coord.y = y;

    return coord;
}

Color setColor(int red, int green, int blue, int alpha) {
    Color color;
    color.red = red;
    color.green = green;
    color.blue = blue;
    color.alpha = alpha;

    return color;
}

Pixel setPixel(Coordinate coord, Color color) {
    Pixel p;
    p.coord.x = coord.x;
    p.coord.y = coord.y;
    p.color = color;

    return p;
}

Color getGradientColor(Pixel p1, Pixel p2, Pixel p) {
    double dt = sqrt(pow((p2.coord.x - p.coord.x), 2) + pow((p2.coord.y - p.coord.y), 2));
    double dp = sqrt(pow((p2.coord.x - p1.coord.x), 2) + pow((p2.coord.y - p1.coord.y), 2));
    double d = dp/dt;

    Color color;
    color.red = (p1.color.red * d) + ((p2.color.red) * (1 - d));
    color.green = (p1.color.green * d) + ((p2.color.green) * (1 - d));
    color.blue = (p1.color.blue * d) + ((p2.color.blue) * (1 - d));
    color.alpha = (p1.color.alpha * d) + ((p2.color.alpha) * (1 - d));

    return color;
}

Coordinate getRandomCoordinate() {
    Coordinate coord;
    coord.x = (rand() % IMAGE_WIDTH);
    coord.y = (rand() % IMAGE_HEIGHT);

    return coord;
}

Color getRandomColor() {
    Color color;
    color.red = (rand() % 255); 
    color.green = (rand() % 255); 
    color.blue = (rand() % 255); 
    color.alpha = 255; 
    
    return color;
}

void PutPixel(Pixel p, Color color) {
    fb_ptr[4 * (p.coord.x) + 4 * (p.coord.y) * IMAGE_WIDTH + 0] = color.red;
	fb_ptr[4 * (p.coord.x) + 4 * (p.coord.y) * IMAGE_WIDTH + 1] = color.green;
	fb_ptr[4 * (p.coord.x) + 4 * (p.coord.y) * IMAGE_WIDTH + 2] = color.blue;
	fb_ptr[4 * (p.coord.x) + 4 * (p.coord.y) * IMAGE_WIDTH + 3] = color.alpha;
}

void DrawLine(Pixel p1, Pixel p2) {
    Color color;
    Pixel p;
    p.coord = p1.coord;

    int w = p2.coord.x - p1.coord.x;
    int h = p2.coord.y - p1.coord.y;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    
    if(w < 0) dx1 = -1; else if (w > 0) dx1 = 1;
    if(h < 0) dy1 = -1; else if (h > 0) dy1 = 1;
    if(w < 0) dx2 = -1; else if (w > 0) dx2 = 1;

    int longest = abs(w);
    int shortest = abs(h);

    if(!(longest > shortest)) {
        longest = abs(h) ;
        shortest = abs(w) ;
        if(h < 0) {
            dy2 = -1;  
        } else if(h > 0) {
            dy2 = 1;
        }
        dx2 = 0;
    }

    int numerator = longest >> 1;
    
    for(int i = 0; i <= longest; i++) {
        color = getGradientColor(p1, p2, p);
        PutPixel(p, color);
        numerator += shortest;
        if(!(numerator < longest)) {
            numerator -= longest;
            p.coord.x += dx1;
            p.coord.y += dy1;
        } else {
            p.coord.x += dx2;
            p.coord.y += dy2;
        }
    }
}

void DrawTriangle(Pixel p1, Pixel p2, Pixel p3) {
	DrawLine(p1, p2);
	DrawLine(p2, p3);
	DrawLine(p1, p3);
}

void MyGlDraw(void) {
    //Below you can set the coordinate(x, y) of each pixel
    //on p_coord and the color(r, g, b, a) on p_color

    Coordinate p1_coord = setCoordinate(100, 100);
    Color p1_color = setColor(255, 0, 0, 255);
    Pixel p1 = setPixel(p1_coord, p1_color);

    Coordinate p2_coord = setCoordinate(300, 200);
    Color p2_color = setColor(0, 255, 0, 255);
    Pixel p2 = setPixel(p2_coord, p2_color);

    Coordinate p3_coord = setCoordinate(200, 350);
    Color p3_color = setColor(0, 0, 255, 255);
    Pixel p3 = setPixel(p3_coord, p3_color);

    DrawTriangle(p1, p2, p3);

    //Uncomment the line below to enable the extra function
    //DrawFancyStar();
}

void DrawFancyStar() {
    //This extra function draws a star and also draws pixels
    //continuously in random coordinates with random colors

    Coordinate p1_coord = setCoordinate(2*(IMAGE_WIDTH/4), 0);
    Color p1_color = getRandomColor();
    Pixel p1 = setPixel(p1_coord, p1_color);

    Coordinate p2_coord = setCoordinate(0, 2*(IMAGE_HEIGHT/6));
    Color p2_color = getRandomColor();
    Pixel p2 = setPixel(p2_coord, p2_color);

    Coordinate p3_coord = setCoordinate(IMAGE_WIDTH, 2*(IMAGE_HEIGHT/6));
    Color p3_color = getRandomColor();
    Pixel p3 = setPixel(p3_coord, p3_color);

    Coordinate p4_coord = setCoordinate(0, IMAGE_HEIGHT);
    Color p4_color = getRandomColor();
    Pixel p4 = setPixel(p4_coord, p4_color);

    Coordinate p5_coord = setCoordinate(IMAGE_WIDTH, IMAGE_HEIGHT);
    Color p5_color = getRandomColor();
    Pixel p5 = setPixel(p5_coord, p5_color);
    
    DrawLine(p1, p4);
    DrawLine(p1, p5);
    DrawLine(p5, p2);
    DrawLine(p2, p3);
    DrawLine(p3, p4);

    Pixel p = setPixel(getRandomCoordinate(), getRandomColor());
    PutPixel(p, p.color);
}
