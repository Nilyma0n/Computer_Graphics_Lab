#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x, y, z;
    float angle;
    int choice;

    cout << "Enter 3D point (x y z): ";
    cin >> x >> y >> z;

    cout << "Enter rotation angle (in degrees): ";
    cin >> angle;

    cout << "Rotate about:\n";
    cout << "1. X-axis\n2. Y-axis\n3. Z-axis\n";
    cout << "Enter choice: ";
    cin >> choice;

    float rad = angle * 3.14159 / 180;

    float xr = x, yr = y, zr = z;

    if (choice == 1) // X-axis
    {
        yr = y * cos(rad) - z * sin(rad);
        zr = y * sin(rad) + z * cos(rad);
    }
    else if (choice == 2) // Y-axis
    {
        xr = x * cos(rad) + z * sin(rad);
        zr = -x * sin(rad) + z * cos(rad);
    }
    else if (choice == 3) // Z-axis
    {
        xr = x * cos(rad) - y * sin(rad);
        yr = x * sin(rad) + y * cos(rad);
    }

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;

    // Draw original point
    setcolor(RED);
    circle(xc + x, yc - y, 10);
    outtextxy(xc + x + 5, yc - y, "Original");

    // Draw rotated point
    setcolor(WHITE);
    circle(xc + xr, yc - yr, 10);
    outtextxy(xc + xr + 5, yc - yr, "Rotated");

    getch();
    closegraph();
    return 0;
}
