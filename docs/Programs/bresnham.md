## Bresnham Line Drawing Algorithm

The Bresnham line drawing algorithm is an algorithm that is used to draw a line between two points on a computer screen. The algorithm is based on the DDA algorithm, but it is more efficient than the DDA algorithm. The Bresnham algorithm is implemented in the `bresnham` function in the `line` module.

## Algorithm

The Bresnham algorithm is based on the following formula:

```math
x = x_0 + t \cdot \Delta x
```

```math

y = y_0 + t \cdot \Delta y
```

where `t` is a parameter that varies from 0 to 1. The values of `x` and `y` are calculated for each value of `t`. The values of `x` and `y` are rounded to the nearest integer, and the pixel at that location is set to the desired color.

## Implementation

The Bresnham algorithm is implemented in the `bresnham` function in the `line` module. The function takes the following parameters:

* `x0` and `y0`: The coordinates of the first point.
* `x1` and `y1`: The coordinates of the second point.
* `color`: The color of the line.

The function calculates the values of `dx` and `dy`, and then it calculates the value of `t` that will be used to calculate the values of `x` and `y`. The function then iterates from `t = 0` to `t = 1`, calculating the values of `x` and `y` for each value of `t`. The values of `x` and `y` are rounded to the nearest integer, and the pixel at that location is set to the desired color.

## Example

The following example draws a line from `(0, 0)` to `(100, 100)` using the Bresnham algorithm:

```c
    // Bresnham Line Drawing Algorithm

    #include<stdio.h>
    #include<string.h>
    #include<graphics.h>
    #include<math.h>

    int main(){
    int gd=DETECT,gm,x,y,x1,x2,y1,y2,dx,dy,step,xinc,yinc,i;

    initgraph(&gd,&gm,"C:\\Program Files (x86)\\Colorado\\cs1300\\bgi");

    printf("Enter the staring Co-ordinates : ");
    scanf("%d %d",&x1,&y1);

    printf("Enter the end Co-ordinates : ");
    scanf("%d %d",&x2,&y2);

    dx=(x2-x1);
    dy=(y2-y1);

    if(abs(dx)>=abs(dy))
        step=abs(dx);
    else
        step=abs(dy);

    xinc=dx/step;
    yinc=dy/step;

    x=x1;
    y=y1;

    putpixel(x,y,WHITE);

    for(i=0;i<step;i++){
        x=x+xinc;
        y=y+yinc;
        putpixel(x,y,WHITE);
    }

    getch();
    closegraph();
    return 0;
    }
```