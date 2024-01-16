#ifndef _DRAW_H_
#define _DRAW_H_

#include "color.h"
#include "frame.h"

void draw_point(frame* frame, double x, double y, color color);

void draw_background(frame* frame, color color);

void draw_line(frame* frame, double start_x, double start_y, double end_x,
               double end_y, double width, color color);

void draw_rect(frame* frame, double start_x, double start_y, double end_x,
               double end_y, color color);

void draw_fillcircle(frame* frame, double center_x, double center_y,
                     double radius, color color);

void draw_triangle(frame* frame, double x_1, double y_1, double x_2, double y_2,
                   double x_3, double y_3, color color);

double max_coord(double array[]);

double min_coord(double array[]);

double sign(double x_0, double y_0, double x_1, double y_1, double x_2,
            double y_2);

#endif  // _DRAW_H_