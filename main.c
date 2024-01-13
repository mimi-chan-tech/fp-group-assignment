#include "header.h"

int main(void) {
    image filed;

    image_init(&filed, 512, 256, color_rgb(255, 255, 255));
    image_set_pixel(&filed, 300, 50, color_rgb(255, 0, 0));
    image_export(&filed);

    return 0;
}