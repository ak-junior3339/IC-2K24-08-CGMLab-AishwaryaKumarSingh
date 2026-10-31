# CGM Lab Assignment 2 – DDA Line Drawing Algorithm
##  Aim
To implement the DDA (Digital Differential Analyzer) Line Drawing Algorithm using C++ and the graphics.h graphics library.
## Description
The program:

Accepts the starting point (x1, y1).
Accepts the ending point (x2, y2).
Calculates dx and dy.
Calculates the required number of steps.
Calculates the increments in the x and y directions.
Plots the line pixel-by-pixel using putpixel().

## DDA Algorithm
dx = x2 - x1
dy = y2 - y1

steps = max(|dx|, |dy|)

xIncrement = dx / steps
yIncrement = dy / steps

x = x1
y = y1

Repeat steps + 1 times:
    Plot pixel(round(x), round(y))
    x = x + xIncrement
    y = y + yIncrement

    
## Aishwarya Kumar Singh
## Lab - 02
## IC-2K24-08
