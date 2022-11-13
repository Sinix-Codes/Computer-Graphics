# DDA algorithm

The DDA algorithm is a simple algorithm for drawing lines. It is very fast, but it has some problems. It is not suitable for drawing thick lines, and it is not suitable for drawing lines with a slope of 1 or -1. It is also not suitable for drawing lines with a slope of 0 or infinity.

## Algorithm

The DDA algorithm is very simple. It is based on the following formula:

$$
x = x_0 + t \cdot \Delta x
$$

$$
y = y_0 + t \cdot \Delta y
$$

where $t$ is a parameter that varies from 0 to 1. The values of $x$ and $y$ are calculated for each value of $t$. The values of $x$ and $y$ are rounded to the nearest integer, and the pixel at that location is set to the desired color.

## Implementation

The DDA algorithm is implemented in the `dda` function in the `line` module. The function takes the following parameters:

* `x0` and `y0`: The coordinates of the first point.
* `x1` and `y1`: The coordinates of the second point.
* `color`: The color of the line.

The function calculates the values of $dx$ (change in x) and $dy$ (change in y), and then it calculates the value of `t` that will be used to calculate the values of `x` and `y`. The function then iterates from $t = 0$ to $t = 1$, calculating the values of `x` and `y` for each value of `t`. The values of `x` and `y` are rounded to the nearest integer, and the pixel at that location is set to the desired color.

## Example

The following example draws a line from `(0, 0)` to `(100, 100)` using the DDA algorithm:

```c
// DDA (Digital Differential Algorithm) algorithm
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<math.h>

int main(){
    int gd = DETECT, gm;
    int x, y, x1, x2, y1, y2;
    int dx, dy, step, xinc, yinc, i;

    initgraph(&gd, &gm, "C:\\Program Files (x86)\\Colorado\\cs1300\\bgi");

    printf("Enter the staring Co-ordinates : ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the end Co-ordinates : ");
    scanf("%d %d", &x2, &y2);

    dx = (x2 - x1);
    dy = (y2 - y1);

    if ( abs(dx) >= abs(dy) )
        step = abs(dx);
    else
        step = abs(dy);

    xinc = dx / step;
    yinc = dy / step;

    x = x1;
    y = y1;
    putpixel(x, y, 4);

    for ( i = 0; i < step; i++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, 4);
    }

    getch();
    closegraph();

    return 0;
}
```