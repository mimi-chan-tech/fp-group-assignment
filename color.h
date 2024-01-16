#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

color color_rgb(unsigned char, unsigned char, unsigned char);

color color_mix(color color_1, color color_2);

#endif  // _COLOR_H_