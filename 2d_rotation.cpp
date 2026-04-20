#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    float angle;

    cout << "Enter first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second point (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Enter rotation angle (in degrees): ";
    cin >> angle;

    float rad = angle * 3.14159 / 180;

    int rx1 = x1 * cos(rad) - y1 * sin(rad);
    int ry1 = x1 * sin(rad) + y1 * cos(rad);

    int rx2 = x2 * cos(rad) - y2 * sin(rad);
    int ry2 = x2 * sin(rad) + y2 * cos(rad);

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    setcolor(WHITE);
    line(midx + x1, midy - y1, midx + x2, midy - y2);
    outtextxy(midx + x1, midy - y1 - 10, "Original");

    setcolor(RED);
    line(midx + rx1, midy - ry1, midx + rx2, midy - ry2);
    outtextxy(midx + rx1, midy - ry1 - 10, "Rotated");

    getch();
    closegraph();
    return 0;
}
