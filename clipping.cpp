#include <graphics.h>
#include <iostream>
using namespace std;

// Region codes
#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

float xmin = 100, ymin = 100, xmax = 300, ymax = 300;

int computeCode(float x, float y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

bool cohenSutherlandClip(float &x1, float &y1, float &x2, float &y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            float x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    return accept;
}

int main()
{
    float x1, y1, x2, y2;

    cout << "Enter line coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Original Line
    initwindow(500, 500, "Original Line", 0, 0);

    rectangle(xmin, ymin, xmax, ymax);

    setcolor(RED);
    line(x1, y1, x2, y2);

    //Perform Clipping
    bool accepted = cohenSutherlandClip(x1, y1, x2, y2);

    //Window 2 : Clipped Line
    initwindow(500, 500, "Clipped Line", 550, 0);

    rectangle(xmin, ymin, xmax, ymax);

    if (accepted)
    {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
        outtextxy(150, 50, "Line Accepted and Clipped");
    }
    else
    {
        outtextxy(150, 50, "Line Rejected");
    }

    getch();
    closegraph();
    return 0;
}
