/*
 * CGM Lab Assignment - 2
 * Question: Write a C/C++ program using a graphics library or tool to implement
 *           the Digital Differential Analyzer (DDA) Line Drawing Algorithm to
 *           draw a straight line between two given points.
 *
 * SUBMITTED BY : AISHWARYA KUMAR SINGH
 * Roll No      : IC-2K24-08
 */

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roundOff(float v)
{
    return (int)floor(v + 0.5f);
}

void ddaLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = 0;

    /* steps = max(|dx|, |dy|) */
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
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
    /* Hardcoded input points */
    int x1 = 60,  y1 = 150;
    int x2 = 580, y2 = 400;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    /* Name */
    setcolor(WHITE);
    outtextxy(140, 30, (char*)"Name: Aishwarya Kumar Singh  |  Roll No: IC-2K24-08");

    /* DDA line */
    ddaLine(x1, y1, x2, y2, WHITE);

    getch();
    closegraph();

    return 0;
}