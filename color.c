#include "color.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

color color_rgb(unsigned char r, unsigned char g, unsigned char b) {
    color color;

    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}

color color_mix(color color_1, color color_2) {
    color color;
    color.r = (color_1.r + color_2.r) / 2;
    color.g = (color_1.g + color_2.g) / 2;
    color.b = (color_1.b + color_2.b) / 2;
}