#include "image.h"

#include <stdio.h>
#include <stdlib.h>

void image_init(image* image, int width, int height, color color) {
    (*image).width = width;
    (*image).height = height;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            (*image).image[y][x] = color;
        }
    }

    return;
}

void image_export(image* image) {
    char file_name[256];
    sprintf(file_name, "image%d.ppm", ++(*image).frame_count);

    FILE* f = fopen(file_name, "wb");

    if (f == NULL) {
        fprintf(stderr, "Unable to open file : %s\n", file_name);
        exit(1);
    }

    fprintf(f, "P6\n%d %d\n255\n", (*image).width, (*image).height);

    for (int y = 0; y < (*image).height; y++) {
        for (int x = 0; x < (*image).width; x++) {
            fwrite(&(*image).image[y][x].r, sizeof((*image).image[y][x].r), 1,
                   f);
            fwrite(&(*image).image[y][x].g, sizeof((*image).image[y][x].b), 1,
                   f);
            fwrite(&(*image).image[y][x].b, sizeof((*image).image[y][x].b), 1,
                   f);
        }
    }

    fclose(f);

    return;
}

void image_set_pixel(image* image, int x, int y, color color) {
    if (x < 0 || (*image).width <= x || y < 0 || (*image).height <= y) {
        return;
    }

    (*image).image[(*image).height - y - 1][x] = color;

    return;
}