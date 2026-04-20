#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Structure for each ball
struct Ball {
    int x, y;   // position
    int r;      // radius
    int dx, dy; // speed
    int color;  // color
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxX = getmaxx();
    int maxY = getmaxy();

    const int n = 5; // number of balls

    Ball b[n] = {
        {200, 200, 20, 4, 3, WHITE},
        {100, 100, 15, 3, 2, RED},
        {300, 150, 18, 2, 4, GREEN},
        {250, 250, 12, 5, 3, YELLOW},
        {400, 200, 16, 3, 5, CYAN}
    };

    while (!kbhit()) {
        cleardevice();

        // Loop through all balls
        for (int i = 0; i < n; i++) {

            // Draw ball
            setcolor(b[i].color); // boundary color
            circle(b[i].x, b[i].y, b[i].r);

            setfillstyle(SOLID_FILL, b[i].color); // fill color
            floodfill(b[i].x, b[i].y, b[i].color); // boundary color

            // Move ball
            b[i].x += b[i].dx;
            b[i].y += b[i].dy;

            // Collision with Left/Right wall
            if (b[i].x + b[i].r >= maxX || b[i].x - b[i].r <= 0) {
                b[i].dx = -b[i].dx;
            }

            // Collision with Top/Bottom wall
            if (b[i].y + b[i].r >= maxY || b[i].y - b[i].r <= 0) {
                b[i].dy = -b[i].dy;
            }
        }

        delay(20);
    }

    getch();
    closegraph();
    return 0;
}
