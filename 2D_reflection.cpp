#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int maxY;

    cout << "Enter rectangle coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    maxY = getmaxy();

    // Original rectangle
    setcolor(WHITE);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 10, "Original");

    // Reflected about X-axis (FIXED)
    setcolor(RED);
    rectangle(x1, maxY - y2, x2, maxY - y1);
    outtextxy(x1, maxY - y2 - 10, "Reflected (X-axis)");

    getch();
    closegraph();
    return 0;
}
