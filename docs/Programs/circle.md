// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <stdio.h>
#include <dos.h>
#include <graphics.h>

// Function to put pixels
// at subsequence points
void drawCircle(int xc, int yc, int x, int y)
{
    
	putpixel(xc+x, yc+y, 3);
	putpixel(xc-x, yc+y, 3);
	putpixel(xc+x, yc-y, 3);
	putpixel(xc-x, yc-y, 3);
	putpixel(xc+y, yc+x, 3);
	putpixel(xc-y, yc+x, 3);
	putpixel(xc+y, yc-x, 3);
	putpixel(xc-y, yc-x, 3);
}

// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		// for each pixel we will
		// draw all eight pixels
		
		x++;

		// check for decision parameter
		// and correspondingly
		// update d, x, y
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
		delay(100);
	}
}


// Driver code
int main()
{
	int xc = 100, yc = 100, r = 80;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); // initialize graph
    outtextxy(70,80,"Bresenham Circle");
	circleBres(xc, yc, r); // function call
    delay(5000);
	return 0;
}
