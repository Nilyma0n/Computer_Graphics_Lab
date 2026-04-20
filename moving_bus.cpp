#include <graphics.h>
#include <conio.h>
int main() {
    int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

    int x = 0;

    while (x < 600) {
        clearviewport();

        // Road
        setcolor(GREEN);
        rectangle(0, 350, 800, 400);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(1, 351, GREEN);

        // Bus body 
        setcolor(WHITE);
        rectangle(x, 250, x + 180, 320);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(x + 1, 251, WHITE);

        //  windows
        
            setcolor(WHITE);
            rectangle(x + 10, 260, x + 40, 290);
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            floodfill(x + 11 , 261, WHITE);
        
         setcolor(WHITE);
            rectangle(x + 50, 260, x + 80, 290);
            setfillstyle(SOLID_FILL, LIGHTBLUE);
            floodfill(x + 51 , 261, WHITE);
            
            
        // Wheels
        setcolor(WHITE);
        circle(x + 40, 330, 15);
        circle(x + 140, 330, 15);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(x + 40, 330, WHITE);
        floodfill(x + 140, 330, WHITE);

        delay(50);
        x += 5;
    }

    getch();
    closegraph();
    return 0;
}
