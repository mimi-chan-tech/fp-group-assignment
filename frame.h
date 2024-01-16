#ifndef _FRAME_H_
#define _FRAME_H_

#include "color.h"

#define FRAME_MAX_WIDTH 1980
#define FRAME_MAX_HEIGHT 1080

typedef struct {
    int width;
    int height;
    int frame_count;
    color frame[FRAME_MAX_HEIGHT][FRAME_MAX_WIDTH];
} frame;

void frame_init(frame*, int, int, color);

void frame_export(frame*);

void frame_set_pixel(frame*, int, int, color);

#endif  // _frame_H_
