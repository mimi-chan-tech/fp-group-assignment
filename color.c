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

Color color_hex(char *color_code) {
    Color color;
    char hex_full[7] = "";
    unsigned int hex_value;

    if (color_code[0] != '#' ||
        (strlen(color_code) != 7 && strlen(color_code) != 4)) {
        color_code = "ffffff";
    } else {
        color_code++;

        if (strlen(color_code) == 3) {
            snprintf(hex_full, sizeof(hex_full), "%c%c%c%c%c%c", color_code[0],
                     color_code[0], color_code[1], color_code[1], color_code[2],
                     color_code[2]);
        } else {
            strncpy(hex_full, color_code, sizeof(hex_full));
        }
    }

    sscanf(hex_full, "%x", &hex_value);

    if (hex_value == 0) {
        hex_value = 0xFFFFFF;
    }

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