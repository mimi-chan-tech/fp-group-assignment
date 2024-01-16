#include "header.h"

int main(void) {
    frame fr;

    frame_init(&fr, 512, 256, color_rgb(255, 255, 255));

    frame_export(&fr);

    return 0;
}