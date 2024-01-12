#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "color.h"

#define IMAGE_MAX_WIDTH 1980
#define IMAGE_MAX_HEIGHT 1080

typedef struct {
    int width;
    int height;
    int frame_count;
    color image[IMAGE_MAX_HEIGHT][IMAGE_MAX_WIDTH];
} image;

void image_init(image*, int, int, color);

void image_export(image*);

void image_set_pixel(image*, int, int, color);

#endif  // _IMAGE_H_
