// DDA (Digital Differential Algorithm) algorithm


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
    putpixel(x,y,4);

    for ( i = 0; i < step; i++)
    {
        x=x+xinc;
        y=y+yinc;
        putpixel(x,y,4);
    }
    getch();
    closegraph();
   return 0;
}