#include <graphics.h>
#include <conio.h>

int main() {
    // Initialize graphics window (width, height)
    int gd = DETECT, gm;
    
     initgraph(&gd, &gm, "");

    int x = 0; // Starting position of car
    while (x < 600) { // Move across screen
        // Draw sky/background
        setviewport(0, 0, 800, 600, 1);
        clearviewport();

        // Draw ground
        setcolor(GREEN);
        rectangle(0, 350, 800, 400);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1, 351, GREEN);

        // Draw Car Body
        setcolor(WHITE);
        rectangle(x, 250, x + 100, 300);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + 1, 251, WHITE);

        // Draw Car Top
        rectangle(x + 20, 220, x + 80, 250);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        floodfill(x + 21, 221, WHITE);

        // Draw Wheels
        circle(x + 25, 310, 15);
        circle(x + 75, 310, 15);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(x + 25, 310, WHITE);
        floodfill(x + 75, 310, WHITE);

        // Animation logic
        delay(50); // Pause for movement effect
        x += 5;    // Move car right
    }

    getch();
    closegraph();
    return 0;
}
