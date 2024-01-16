#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color color_rgb(unsigned char, unsigned char, unsigned char);

Color color_hex(char* color_code);

Color color_mix(Color color_1, Color color_2);

#endif  // _COLOR_H_