#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
void draw3DRect(int x1, int y1, int x2, int y2, int z)
{
    rectangle(x1, y1, x2, y2);

    rectangle(x1 + z, y1 - z, x2 + z, y2 - z);

    line(x1, y1, x1 + z, y1 - z);
    line(x2, y1, x2 + z, y1 - z);
    line(x1, y2, x1 + z, y2 - z);
    line(x2, y2, x2 + z, y2 - z);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, z;
    int tx, ty, tz;

    cout << "Enter 3D rectangle coordinates (x1 y1 x2 y2 z): ";
    cin >> x1 >> y1 >> x2 >> y2 >> z;

    cout << "Enter translation factors (tx ty tz): ";
    cin >> tx >> ty >> tz;

    // Original object
    setcolor(WHITE);
    draw3DRect(x1, y1, x2, y2, z);
    outtextxy(x1, y1 - 15, "Original");

    // Translated object
    setcolor(RED);
    draw3DRect(x1 + tx, y1 + ty, x2 + tx, y2 + ty, z + tz);
    outtextxy(x1 + tx, y1 + ty - 15, "Translated");

    getch();
    closegraph();
    return 0;
}
