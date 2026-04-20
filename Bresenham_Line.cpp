#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int dx, dy, p, x, y;

    cout << "Enter starting point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter ending point (x2 y2): ";
    cin >> x2 >> y2;

    initwindow(800, 800);

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x <= x2)
    {
        putpixel(x, y, WHITE);

        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * dy - 2 * dx;
            y++;
        }
        x++;
    }

    getch();
    closegraph();
    return 0;
}
