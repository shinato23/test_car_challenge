#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

using namespace std;

const int FPS = 144;
const float FRAME_SEC = 1.0 / FPS;
const clock_t FRAME_CLOCKS = FRAME_SEC * CLOCKS_PER_SEC;

enum OBJECT {
    CAR1 = 0,
    TREE = 1,
    SUN = 2,
    BACKGROUND = 3,
    CAR2 = 4,
};

void draw(int obj, int x, int y) {
    if (obj == CAR1) {
        setlinestyle(3,0x1010,3);
        rectangle(x, y, x + 50, y + 100);
        rectangle(x+15,y+35,x+35,y+65);
    }
    if (obj == CAR2){

    }

    if (obj == TREE) {

    }

    if (obj == BACKGROUND){

    }
}

void draw() {
    //ve vach ke duong
	setlinestyle(0,0x1010,1);
	line(0,0,0,1000);
	line(1000,0,1000,1000);
	line(200,200,200,1000);
	line(800,200,800,1000);

	setlinestyle(3,0x1010,1);
	line(400,200,400,1000);
	line(600,200,600,1000);

	// ve duong chan troi ngan cach
	setlinestyle(0,0x1010,1);
	line(0,200,1000,200);
	line(0,0,1000,0);

	return;
}

int main()
{
	/*int gd = DETECT ,gm;
	initgraph(&gd ,&gm , " ");*/
	initwindow(1000,1000,"The Window");

	int x, y, vel;
	x = 300;
	y = 400;
	vel = 10;

	bool isRunning = true;
	while (isRunning) {
        clock_t current_tick = clock();

        cleardevice();
        draw();
        draw(CAR1, x, y);

        clock_t tick = clock();
        float frame_sec = (tick - current_tick) / CLOCKS_PER_SEC;
        if (frame_sec < FRAME_CLOCKS) {
            float delay_sec = FRAME_SEC - frame_sec;
            cout << delay_sec << '\n';
            sleep(delay_sec);
        }

        cout << 1.0 / FRAME_SEC << '\n';

       /* if (kbhit()){
            char key = getch();

            if (key == 'w') {
                y -= vel;
            }

            if (key == 'a') {
                x -= vel;
            }

            if (key == 's') {
                y += vel;
            }

            if (key == 'd') {
                x += vel;
            }

            if (key == 'p') {
                isRunning = false;
            }
            } */
            if (y<=500)
            {
                y  += vel;
        }
	}

	closegraph();
	return 0;
}
