#include "color.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Color color_rgb(unsigned char r, unsigned char g, unsigned char b) {
    Color color;

    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}

Color color_hex(char *color_hex) {
    Color color;
    char hex_full[7] = "";
    unsigned int hex_value;

    if (color_hex[0] != '#' ||
        (strlen(color_hex) != 7 && strlen(color_hex) != 4)) {
        color_hex = "ffffff";
    } else {
        color_hex++;

        if (strlen(color_hex) == 3) {
            snprintf(hex_full, sizeof(hex_full), "%c%c%c%c%c%c", color_hex[0],
                     color_hex[0], color_hex[1], color_hex[1], color_hex[2],
                     color_hex[2]);
        } else {
            strncpy(hex_full, color_hex, sizeof(hex_full));
        }
    }

    sscanf(hex_full, "%x", &hex_value);

    color.r = (hex_value >> 16) & 0xFF;
    color.g = (hex_value >> 8) & 0xFF;
    color.b = hex_value & 0xFF;

    return color;
}

Color color_mix(Color color_1, Color color_2) {
    Color color;
    color.r = (color_1.r + color_2.r) / 2;
    color.g = (color_1.g + color_2.g) / 2;
    color.b = (color_1.b + color_2.b) / 2;
    return color;
}