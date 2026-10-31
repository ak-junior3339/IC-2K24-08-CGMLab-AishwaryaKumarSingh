
/*
 * CGM Lab Assignment - 2
 * Question: Write a C/C++ program using a graphics library or tool
 * to implement the Digital Differential Analyzer (DDA) Line Drawing
 * Algorithm to draw a straight line between two given points.
 *
 * SUBMITTED BY : AISHWARYA KUMAR SINGH
 * Roll No      : IC-2K24-08
*/

#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

// Function to round off floating-point values
int roundOff(float v)
{
    return (int)floor(v + 0.5f);
}

// DDA Line Drawing Algorithm
void ddaLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate number of steps
    int steps;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    // Handle case when both points are identical
    if (steps == 0)
    {
        putpixel(x1, y1, color);
        return;
    }

    // Calculate increments
    float xInc = (float)dx / steps;
    float yInc = (float)dy / steps;

    float x = (float)x1;
    float y = (float)y1;

    // Generate and plot intermediate points
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

    // Accept starting and ending points
    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Validate coordinates
    if (x1 < 20 || x1 > 620 || x2 < 20 || x2 > 620 ||
        y1 < 110 || y1 > 430 || y2 < 110 || y2 > 430)
    {
        printf("\nCoordinates must be within the drawing area!\n");
        return 0;
    }

    // Calculate differences and steps
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    printf("\ndx = %d, dy = %d, steps = %d\n", dx, dy, steps);

    if (steps != 0)
    {
        printf("x_increment = %.3f, y_increment = %.3f\n",
               (float)dx / steps, (float)dy / steps);
    }
    else
    {
        printf("Both points are identical. Only one pixel will be plotted.\n");
    }

    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Display heading
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(140, 25, (char*)"CGM LAB ASSIGNMENT - 02");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);

    outtextxy(190, 55, (char*)"DDA Line Drawing Algorithm");
    outtextxy(140, 80,
              (char*)"Name: Aishwarya Kumar Singh | Roll No: IC-2K24-08");

    // Draw boundary of drawing area
    setcolor(RED);
    rectangle(20, 110, 620, 430);

    // Draw line using DDA algorithm
    ddaLine(x1, y1, x2, y2, WHITE);

    // Mark starting and ending points
    setcolor(YELLOW);
    circle(x1, y1, 3);
    circle(x2, y2, 3);

    // Display input and calculated values
    setcolor(WHITE);

    sprintf(buf, "P1 = (%d, %d)   P2 = (%d, %d)", x1, y1, x2, y2);
    outtextxy(30, 440, buf);

    sprintf(buf, "dx = %d   dy = %d   steps = %d", dx, dy, steps);
    outtextxy(30, 455, buf);

    // Wait for a key press before closing graphics
    getch();

    closegraph();

    return 0;
}
