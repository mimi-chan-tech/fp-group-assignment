#include "header.h"

int main(void) {
    image image;

    image_init(&image, 512, 256, color_rgb(255, 255, 255));
    image_set_pixel(&image, 300, 50, color_rgb(255, 0, 0));
    image_export(&image);

    return 0;
}