#include "color.h"

#include <stdio.h>

color color_rgb(unsigned char r, unsigned char g, unsigned char b) {
    color color;

    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}