#include <graphics.h>
#include <conio.h>

#define MAX_CARS 3

// Structure
struct Car {
    int x, y;
    int speed;
    int color;
    int direction; // 1 = right, -1 = left
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Multiple cars
    struct Car cars[MAX_CARS] = {
        {0,   250, 5, RED, 1},     // moving right
        {700, 300, 3, BLUE, -1},   // moving left
        {200, 200, 2, YELLOW, 1}   // slower right
    };

    while (!kbhit()) {

        // Background
        setviewport(0, 0, 800, 600, 1);
        clearviewport();

        // Ground
        setcolor(GREEN);
        rectangle(0, 350, 800, 400);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1, 351, GREEN);

        // Loop for all cars
        for (int i = 0; i < MAX_CARS; i++) {

            int x = cars[i].x;
            int y = cars[i].y;

            // Car Body
            setcolor(WHITE);
            rectangle(x, y, x + 100, y + 50);
            setfillstyle(SOLID_FILL, cars[i].color);
            floodfill(x + 1, y + 1, WHITE);

            // Car Top
            rectangle(x + 20, y - 30, x + 80, y);
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            floodfill(x + 21, y - 29, WHITE);

            // Wheels
            circle(x + 25, y + 60, 15);
            circle(x + 75, y + 60, 15);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(x + 25, y + 60, WHITE);
            floodfill(x + 75, y + 60, WHITE);

            // Movement
            cars[i].x += cars[i].speed * cars[i].direction;

            // Boundary reset
            if (cars[i].x > 800) cars[i].x = 0;
            if (cars[i].x < 0) cars[i].x = 800;
        }

        delay(50);
    }

    getch();
    closegraph();
    return 0;
}
