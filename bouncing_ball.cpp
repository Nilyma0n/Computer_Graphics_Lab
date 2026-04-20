#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    // Ball properties
    int x = 200, y = 200;   // initial position
    int r = 20;             // radius
    int dx = 4, dy = 3;     // speed (velocity)

    int maxX = getmaxx();
    int maxY = getmaxy();

    while (!kbhit()) {
        cleardevice();

        // Draw ball
        setcolor(WHITE);
        circle(x, y, r);
        floodfill(x, y, WHITE);

        // Move ball
        x += dx;
        y += dy;

        // ?? Collision with walls

        // Left or Right wall
        if (x + r >= maxX || x - r <= 0) {
            dx = -dx;  // reverse direction
        }

        // Top or Bottom wall
        if (y + r >= maxY || y - r <= 0) {
            dy = -dy;  // reverse direction
        }

        delay(20);
    }

    getch();
    closegraph();
    return 0;
}
