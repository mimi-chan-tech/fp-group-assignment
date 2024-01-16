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

void frame_init(Frame* frame, int width, int height, Color color);

void frame_export(Frame* frame);

void frame_set_pixel(Frame* frame, int x, int y, Color color);

#endif  // _frame_H_
