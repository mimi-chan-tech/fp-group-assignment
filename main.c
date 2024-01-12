#include <stdio.h>

#include "color.h"

int main(void) {
    color c;
    init_color(&c);
    set_color(&c, get_color(0, 0, 0));

    printf("%d, %d, %d\n", c.r, c.g, c.b);

    return 0;
}