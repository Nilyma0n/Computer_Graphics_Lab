#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 0;

    while (!kbhit()) {
        cleardevice();

        // ?? Draw Sun
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(500, 80, 40);
        floodfill(500, 80, YELLOW);

        // ?? Draw Ground
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        rectangle(0, 300, 640, 480);
        floodfill(10, 310, GREEN);

        // ?? Draw Clouds (group of circles)
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);

        // Cloud 1
        circle(x + 50, 100, 20);
        circle(x + 70, 90, 25);
        circle(x + 90, 100, 20);

        floodfill(x + 50, 100, WHITE);
        floodfill(x + 70, 90, WHITE);
        floodfill(x + 90, 100, WHITE);

        // Cloud 2
        circle(x + 200, 120, 20);
        circle(x + 220, 110, 25);
        circle(x + 240, 120, 20);

        floodfill(x + 200, 120, WHITE);
        floodfill(x + 220, 110, WHITE);
        floodfill(x + 240, 120, WHITE);

        // Move clouds slowly
        x += 2;

        // Reset position when clouds go off screen
        if (x > 640)
            x = -250;

        delay(100);
    }

    getch();
    closegraph();
    return 0;
}
