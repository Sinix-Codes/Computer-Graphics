#include <stdio.h>
#include <graphics.h>

void boundryFill(int x, int y, int f_color, int b_color) {
    if (getpixel(x, y) == b_color && getpixel(x, y) != f_color) {
        putpixel(x, y, f_color);
        boundryFill(x + 1, y, f_color, b_color); // left
        boundryFill(x, y + 1, f_color, b_color); // up
        boundryFill(x - 1, y, f_color, b_color); // right
        boundryFill(x, y - 1, f_color, b_color); // down
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Colorado\\cs1300\\bgi");

    getch();
    x1 = 100;
    x2 = 300;
    y1 = 100;
    y2 = 250;

    rectangle(x1, y1, x2, y2);
    boundryFill((x1 + x2) / 2, (y1 + y2) / 2, WHITE, BLACK);

    getch();

    return EXIT_SUCCESS;
}
