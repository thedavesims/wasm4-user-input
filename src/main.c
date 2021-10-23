#include "wasm4.h"

//Also defined as MOUSE_X in wasm4.h
#define MOUSE_MEMORY 0x001a;

struct mouse_data {
    int16_t x;
    int16_t y;
    uint8_t buttons;
};

const uint8_t cursor[] = {
    0b00000011,
    0b00000011,
    0b00001111,
    0b00000111,
    0b00100011,
    0b00110001,
    0b11111000,
    0b11111100,
};

void update () {

    static struct mouse_data* m = (struct mouse_data*)MOUSE_MEMORY;

    *DRAW_COLORS = 3;
    text("Mouse Test", 10, 10);

    *DRAW_COLORS = 2;
    if(m->buttons & 0x1)
    {
        text("Left Button", 10, 20);
    }

    if(m->buttons & 0x2)
    {
        text("Right Button", 10, 30);
    }

    if(m->buttons & 0x4)
    {
        text("Middle Button", 10, 40);
    }

    blit(cursor, m->x, m->y, 8, 8, BLIT_1BPP);
}
