#include "draw.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void draw_point(frame* frame, double x, double y, color color) {
    frame_set_pixel(frame, x, y, color);
}

void draw_background(frame* frame, color color) {
    for (int x = 1; x <= (*frame).width; x++) {
        for (int y = 1; y <= (*frame).height; y++) {
            frame_set_pixel(frame, x, y, color);
        }
    }
}

void draw_line(frame* frame, double start_x, double start_y, double end_x,
               double end_y, double width, color color) {
    double min_x, max_x, min_y, max_y;

    if (start_x > end_x) {
        min_x = end_x;
        max_x = start_x;
    } else {
        min_x = start_x;
        max_x = end_x;
    }

    if (start_y > end_y) {
        min_y = end_y;
        max_y = start_y;
    } else {
        min_y = start_y;
        max_y = end_y;
    }

    if (start_x == end_x) {
        for (int x = (int)(start_x - width / 2);
             x <= (int)(start_x + width / 2); x++) {
            for (int y = (int)(min_y); y <= (int)(max_y); y++) {
                frame_set_pixel(frame, x, y, color);
            }
        }
    } else {
        double inlination = (end_y - start_y) / (end_x - start_x);

        for (int x = (int)(min_x); x <= (int)(max_x); x++) {
            for (int y = (int)(min_y); y <= (int)(max_y); y++) {
                if (inlination * (x - start_x) + start_y - width / 2 <= y &&
                    y <= inlination * (x - start_x) + start_y + width / 2) {
                    frame_set_pixel(frame, x, y, color);
                }
            }
        }
    }
}

void draw_rect(frame* frame, double start_x, double start_y, double end_x,
               double end_y, color color) {
    for (int x = start_x; x <= end_x; x++) {
        for (int y = start_y; y <= end_y; y++) {
            frame_set_pixel(frame, x, y, color);
        }
    }
}

void draw_fillcircle(frame* frame, double center_x, double center_y,
                     double radius, color color) {
    int x_min = (int)(center_x - radius);
    int x_max = (int)(center_x + radius);

    int y_min = (int)(center_y - radius);
    int y_max = (int)(center_y + radius);

    for (int x = x_min; x <= x_max; x++) {
        for (int y = y_min; y <= y_max; y++) {
            if ((center_x - x) * (center_x - x) +
                    (center_y - y) * (center_y - y) <=
                radius * radius) {
                frame_set_pixel(frame, x, y, color);
            }
        }
    }
}

void draw_triangle(frame* frame, double x_1, double y_1, double x_2, double y_2,
                   double x_3, double y_3, color color) {
    double x_args[] = {x_1, x_2, x_3};
    double y_args[] = {y_1, y_2, y_3};

    double start_x = min_coord(x_args);
    double end_x = max_coord(x_args);

    double start_y = min_coord(y_args);
    double end_y = max_coord(y_args);

    for (int x = (int)(start_x); x <= (int)(end_x); x++) {
        for (int y = (int)(start_y); y <= (int)(end_y); y++) {
            bool sign_1 = sign(x, y, x_1, y_1, x_2, y_2) < 0.0f;
            bool sign_2 = sign(x, y, x_2, y_2, x_3, y_3) < 0.0f;
            bool sign_3 = sign(x, y, x_3, y_3, x_1, y_1) < 0.0f;

            if (sign_1 == sign_2 && sign_2 == sign_3) {
                frame_set_pixel(frame, x, y, color);
            }
        }
    }
}

// return max record of coordination list
double max_coord(double array[]) {
    double max;
    for (max = *array; *array; array++) {
        if (*array > max) {
            max = *array;
        }
    }
    return max;
}

// return min record of coordination list
double min_coord(double array[]) {
    double min;
    for (min = *array; *array; array++) {
        if (*array < min) {
            min = *array;
        }
    }
    return min;
}

// return sign of 3 coordination
double sign(double x_0, double y_0, double x_1, double y_1, double x_2,
            double y_2) {
    return (x_0 - x_2) * (y_1 - y_2) - (x_1 - x_2) * (y_0 - y_2);
}