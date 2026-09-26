/*
 * CGM Lab Assignment - 1
 * Question: Write a C/C++ program using a graphics library/tool to draw 
 *           the following basic graphics primitives in a single program:
 *           1. A straight line
 *           2. A circle
 *           3. A rectangle
 *           4. A triangle
 *
 * SUBMITTED BY : AISHWARYA KUMAR SINGH 
 * Roll No      : IC-2K24-08
 */

#include <graphics.h>
#include <conio.h>
#include <string.h>

int main()
{
   
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(140, 25, (char*)"CGM LAB ASSIGNMENT - 01");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    outtextxy(200, 55, (char*)"Basic Shapes");
    outtextxy(140, 80, (char*)"Name: Aishwarya Kumar Singh  |  Roll No: IC-2K24-08");

    setcolor(RED);
    rectangle(20, 110, 620, 430); 
    line(320, 110, 320, 430);     
    line(20, 270, 620, 270);     

    setcolor(WHITE);
    outtextxy(40, 125, (char*)"Straight Line");
    line(60, 190, 280, 190);

    setcolor(WHITE);
    outtextxy(340, 125, (char*)"2. Circle");
    circle(470, 190, 45);

    setcolor(WHITE);
    outtextxy(40, 285, (char*)"3. Rectangle");
    rectangle(70, 320, 270, 400);

    setcolor(WHITE);
    outtextxy(340, 285, (char*)"4. Triangle");
    int tx1 = 470, ty1 = 310; 
    int tx2 = 390, ty2 = 400;
    int tx3 = 550, ty3 = 400; 
    line(tx1, ty1, tx2, ty2);
    line(tx2, ty2, tx3, ty3);
    line(tx3, ty3, tx1, ty1);
    getch();
    closegraph();

    return 0;
}
