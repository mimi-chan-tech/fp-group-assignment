# FP Group Assignment

FP#15 group assignment project.

## Fromatter Config

### VS Code

#### C/C++ Extensions

https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

#### Config

```
{
    "editor.formatOnType": true,
    "editor.formatOnSave": true,
    "C_Cpp.clang_format_style": "{BasedOnStyle: Google, IndentWidth: 4}"
}
```

## Build

```
$ make
```

to build.

```
$ make clean
```

to delete object and depend files.

```
$ ./a.out
```

to run app.

## How to Use

Sample Code

```
#include "fp15_all.h"

int main(void) {
    Frame fr;

    // init frame
    frame_init(&fr, 512, 256, color_rgb(255, 255, 255));

    // draw object
    draw_background(&fr, color_hex("#fff"));

    // export frame
    frame_export(&fr);

    return 0;
}
```

## Drawing Object Function

```
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
```
