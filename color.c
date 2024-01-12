#include "color.h"

#include <stdio.h>

void init_color(color* p_color) {
    (*p_color).r = 255;
    (*p_color).g = 255;
    (*p_color).b = 255;
}

void set_color(color* p_color, color rgb) {
    (*p_color).r = rgb.r;
    (*p_color).g = rgb.g;
    (*p_color).b = rgb.b;
}

color get_color(unsigned char r, unsigned char g, unsigned char b) {
    color color;

    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}
