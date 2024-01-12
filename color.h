#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

void init_color(color*);

void set_color(color*, color);

color get_color(unsigned char, unsigned char, unsigned char);

#endif  // _COLOR_H_