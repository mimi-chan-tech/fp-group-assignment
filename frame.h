#ifndef _FRAME_H_
#define _FRAME_H_

#include "color.h"

#define FRAME_MAX_WIDTH 1980
#define FRAME_MAX_HEIGHT 1080

typedef struct {
    int width;
    int height;
    int frame_count;
    Color frame[FRAME_MAX_HEIGHT][FRAME_MAX_WIDTH];
} Frame;

void frame_init(Frame*, int, int, Color);

void frame_export(Frame*);

void frame_set_pixel(Frame*, int, int, Color);

#endif  // _frame_H_
