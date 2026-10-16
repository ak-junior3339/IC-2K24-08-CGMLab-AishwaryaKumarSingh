/*
 * CGM Lab Assignment - 2
 * Question: Write a C/C++ program using a graphics library or tool to implement the Digital Differential
    Analyzer (DDA) Line Drawing Algorithm to draw a straight line between two given points.
    Requirements
    • Accept the starting point (x■, y■) and ending point (x■, y■) as input.
    • Calculate the differences ∆x and ∆y.
    • Determine the number of steps using the formula below.
    • Calculate the x and y increments for each step.
    • Generate intermediate points using the calculated increments and plot them on the screen.
    • Display the final line using the graphics library.
 *
 * SUBMITTED BY : AISHWARYA KUMAR SINGH
 * Roll No      : IC-2K24-08
*/

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int roundOff(float v)
{
    return (int)floor(v + 0.5f);
}

void ddaLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = 0 ;
    /* steps = max(|dx|, |dy|) */
    if (abs(dx) > abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }

    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;

    float x = (float)x1;
    float y = (float)y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(roundOff(x), roundOff(y), color);
        x += xInc;
        y += yInc;
    }
}

int main()
{
    int x1, y1, x2, y2;
    char buf[100];

    
    printf("=== DDA Line Drawing Algorithm ===\n");
    printf("Drawing area: x = 20 to 620, y = 110 to 430\n\n");
    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point   (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    /* ---- Calculations (shown in console too) ---- */
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    printf("\ndx = %d, dy = %d, steps = %d\n", dx, dy, steps);
    if (steps != 0)
        printf("x_increment = %.3f, y_increment = %.3f\n",
               (float)dx / steps, (float)dy / steps);

    /* ---- Graphics ---- */
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(140, 25, (char*)"CGM LAB ASSIGNMENT - 02");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(190, 55, (char*)"DDA Line Drawing Algorithm");
    outtextxy(140, 80, (char*)"Name: Aishwarya Kumar Singh  |  Roll No: IC-2K24-08");

    /* Drawing area border */
    setcolor(RED);
    rectangle(20, 110, 620, 430);

    /* Draw the line using DDA */
    ddaLine(x1, y1, x2, y2, WHITE);

    /* Mark the end points */
    setcolor(YELLOW);
    circle(x1, y1, 3);
    circle(x2, y2, 3);

    /* Show input values and calculated values at the bottom */
    setcolor(WHITE);
    sprintf(buf, "P1 = (%d, %d)   P2 = (%d, %d)", x1, y1, x2, y2);
    outtextxy(30, 440, buf);

    sprintf(buf, "dx = %d   dy = %d   steps = %d", dx, dy, steps);
    outtextxy(30, 455, buf);

    closegraph();

    return 0;
}