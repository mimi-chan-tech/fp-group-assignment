#include "frame.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void frame_init(Frame* frame, int width, int height, Color color) {
    frame->width = width;
    frame->height = height;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            frame->frame[y][x] = color;
        }
    }

    return;
}

void frame_export(Frame* frame) {
    char file_name[256];

    mkdir("./out", 0777);
    sprintf(file_name, "./out/frame%d.ppm", ++(*frame).frame_count);

    FILE* f = fopen(file_name, "wb");

    if (f == NULL) {
        fprintf(stderr, "Unable to open file : %s\n", file_name);
        exit(1);
    }

    fprintf(f, "P6\n%d %d\n255\n", frame->width, frame->height);

    for (int y = 0; y < frame->height; y++) {
        for (int x = 0; x < frame->width; x++) {
            fwrite(&(*frame).frame[y][x].r, sizeof((*frame).frame[y][x].r), 1,
                   f);
            fwrite(&(*frame).frame[y][x].g, sizeof((*frame).frame[y][x].b), 1,
                   f);
            fwrite(&(*frame).frame[y][x].b, sizeof((*frame).frame[y][x].b), 1,
                   f);
        }
    }

    fclose(f);

    return;
}

void frame_set_pixel(Frame* frame, int x, int y, Color color) {
    if (x <= 0 || frame->width < x || y <= 0 || frame->height < y) {
        return;
    }

    frame->frame[(*frame).height - y][x - 1] = color;

    return;
}