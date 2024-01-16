#ifndef _DRAW_H_
#define _DRAW_H_

#include "color.h"
#include "frame.h"

void draw_point(Frame* frame, double x, double y, Color color);

void draw_background(Frame* frame, Color color);

void draw_line(Frame* frame, double start_x, double start_y, double end_x,
               double end_y, double width, Color color);

void draw_rect(Frame* frame, double start_x, double start_y, double end_x,
               double end_y, Color color);

void draw_fillcircle(Frame* frame, double center_x, double center_y,
                     double radius, Color color);

void draw_triangle(Frame* frame, double x_1, double y_1, double x_2, double y_2,
                   double x_3, double y_3, Color color);

#endif  // _DRAW_H_