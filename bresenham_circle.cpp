#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int xc, yc, r;
    int x = 0, y;
    int p;

    
    cout << "Enter center of circle (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter radius of circle: ";
    cin >> r;

    y = r;
    p = 3 - 2 * r;

    initwindow(800, 800);

    while (x <= y)
    {
        
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            p = p + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    getch();
    closegraph();
    return 0;
}
