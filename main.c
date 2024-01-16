#include "fp15_all.h"

int main(void) {
    Frame fr;

    frame_init(&fr, 512, 256, color_rgb(255, 255, 255));

    draw_background(&fr, color_hex("#f00"));

    frame_export(&fr);

    return 0;
}