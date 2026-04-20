#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

// 3D to 2D projection function
void project3D(float x, float y, float z, int &X, int &Y, int xc, int yc)
{
    X = xc + x + z * 5;
    Y = yc - (y - z * 5);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x, y, z;
    int choice;

    cout << "Enter 3D point (x y z): ";
    cin >> x >> y >> z;

    cout << "Reflect about:\n";
    cout << "1. XY-plane\n";
    cout << "2. YZ-plane\n";
    cout << "3. ZX-plane\n";
    cout << "4. Origin\n";
    cout << "Enter choice: ";
    cin >> choice;

    float xr = x, yr = y, zr = z;

    // Reflection logic
    if (choice == 1)
        zr = -z;
    else if (choice == 2)
        xr = -x;
    else if (choice == 3)
        yr = -y;
    else if (choice == 4)
    {
        xr = -x;
        yr = -y;
        zr = -z;
    }

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    
    
    int X1, Y1, X2, Y2;

    // Project original point
    project3D(x, y, z, X1, Y1, xc, yc);

    // Project reflected point
    project3D(xr, yr, zr, X2, Y2, xc, yc);
    
    
    // Draw original
    setcolor(RED);
    circle(X1, Y1, 8);
    outtextxy(X1 + 5, Y1, "Original");

    // Draw reflected
    setcolor(WHITE);
    circle(X2, Y2, 8);
    outtextxy(X2 + 5, Y2, "Reflected");

    getch();
    closegraph();
    return 0;
}
