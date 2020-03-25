#include "logic.h"
#include "stdio.h"
#include "gba.h"
#include "game.h"
#include "images/pusheen.h"
#include "images/background.h"
#include "images/start.h"
#include "images/cake.h"
#include "images/donut.h"
#include "images/cookie.h"

Food food[30];
Player player;
int score;
int screen = 0;

void initialize(void) {
	//randomly generate brick colors and draw them on the game screen
    for (int i = 0; i < 30; i++) {
        food[i].exists = 0;
    }
    score = 0;
    screen = 0;
	// foodGen();
    const u16 *foods[] = {cake, cookie, donut};
	int numFood = 3;

	int initrow = 5;
	int initcol = 5;
	int width = 20;
	int height = 20;
    player.width = 30;
    player.height = 40;
	//5 bricks per row, 3 rows, 15 bricks
	int count = 0;
	for (int i = 0; i < 6; i++) {
        int num = rand() % 5;
        int color = rand() % numFood;
        // int vis = rand() % 2;
		for (int j = 0; j < num + 1; j++) {
			food[count].row = initrow + (width*i*2);
			food[count].col = initcol + (height*j);
			food[count].exists = 1;
			food[count].width = 20;
			food[count].height = 20;
            food[count].image = foods[color];
            food[count].exists = 1;
			count++;
		}
	}

    for (int i = 0; i < count; i++) {
        if (food[i].exists) {
		    drawImageDMA(food[i].row, food[i].col, food[i].width, food[i].height, food[i].image);
        }
	}
    // drawImageDMA(initrow,initcol,width,height,donut);
    drawImageDMA(100,130,30,30,pusheen);
    player.col = 100;
    player.row = 130;
}

void foodGen(void) {
    const u16 *foods[] = {cake, cookie, donut};
	int numFood = 3;

	int initrow = 5;
	int initcol = 5;
	int width = 20;
	int height = 20;
	//5 bricks per row, 3 rows, 15 bricks
	int count = 0;
	for (int i = 0; i < 6; i++) {
        int num = rand() % 5;
        int start = rand() % 3;
        int color = rand() % numFood;
        int vis = rand() % 2;
		for (int j = start; j < num + start; j++) {
			food[count].row = initrow + (width*i*2);
			food[count].col = initcol + (height*j);
			food[count].exists = vis;
			food[count].width = 20;
			food[count].height = 20;
            food[count].image = foods[color];
            food[count].eaten = 0;
			count++;
		}
	}

    for (int i = 0; i < count; i++) {
        if (food[i].exists) {
		    drawImageDMA(food[i].row, food[i].col, food[i].width, food[i].height, food[i].image);
        }
	}
    drawImageDMA(player.col ,player.row,30,30,pusheen);
}

void movePlayer(u32 currentButtons, u32 previousButtons) {
    waitForVBlank();
    if (KEY_JUST_PRESSED(BUTTON_RIGHT, currentButtons, previousButtons)) {
        // press up
        waitForVBlank();
        if (player.col + 10 < 210) {
            // drawRectDMA(0, 110, 240, 60 ,BLACK);
            drawRectDMA(player.col, player.row, 30, 30 ,BLACK);
            player.col += 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
        // if (player.row + player )
    } else if (KEY_JUST_PRESSED(BUTTON_LEFT, currentButtons, previousButtons)) {
        waitForVBlank();
        if (player.col - 10 > 0) {
            // drawRectDMA(0, 110, 240, 60 ,BLACK);
            drawRectDMA(player.col, player.row, 30, 30 ,BLACK);
            player.col -= 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    } else if (KEY_JUST_PRESSED(BUTTON_UP, currentButtons, previousButtons)) {
        waitForVBlank();
        if (player.row - 10 > 115) {
            // drawRectDMA(0, 110, 240, 60 ,BLACK);
            drawRectDMA(player.col, player.row, 30, 30 ,BLACK);
            player.row -= 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    } else if (KEY_JUST_PRESSED(BUTTON_DOWN, currentButtons, previousButtons)) {
        waitForVBlank();
        // drawRectDMA(0,130,240,120 ,BLACK);
        if (player.row + 10 < 160) {
            drawRectDMA(player.col, player.row, 30, 30 ,BLACK);
            player.row += 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    }
    // foodGen();
    moveFood();
}

int getScore(void) {
    return score;
}

void display(void) {
    drawRectDMA(0,0,240,10,BLACK);
    char buf[12];

    for (int i = 0; i < 12; i++) {
        snprintf(buf, 12, "Score:_%d", score); // puts string into buffer
        // printf("%s\n", buf); // outputs so you can see it
    }
    drawCenteredString(0, 0, SCREEN_WIDTH, 10, buf, WHITE);
}

void moveFood(void) {
    drawRectDMA(0,10,240,player.row - 10,BLACK);
    // int i = player.col;
    if(player.col != 0){
        drawRectDMA(0,120, player.col ,40,BLACK);
    }
    drawRectDMA(player.col + 30,120, 210,40,BLACK);
    drawRectDMA(0,player.row + 30,240,40,BLACK);
    drawRectDMA(0,120,240, 60 - player.row,BLACK);
    // drawImageDMA(player.col ,player.row,30,30,pusheen);
    // int renew = 0;
	for (int i = 0; i < 30; i++) {
        int flag = eat(food[i], player);
        if (!flag) {
            food[i].eaten = 1;
        }
        if (food[i].exists && flag) {
            if (food[i].col + 1 < 140) {
                food[i].col +=1;
                drawImageDMA(food[i].row, food[i].col, food[i].width, food[i].height, food[i].image);
            }
        }
        // if (food[i].row > 180) {
        //     renew = 1;
        // }
    }
    screen += 1;
    if (screen > 160) {
        for (int i = 0; i<30 ; i++) {
            if (food[i].eaten) {
                score += 10;
            } else {
                score --;
            }
        }
        foodGen();
        screen = 0;
    }
}

int eat(Food food, Player player) {
// x: row y: col  width:

// (food.row < player.col + player.width &&
//    food.row + food.width > player.col &&
//    food.col < player.row + player.height &&
//    food.col + food.height > player.row)

    // food.row = rect1.x
    // food.col = rect1.y
    // player.col = rect2.x
    // player.row = rect2.y

    // drawRectDMA(food.row,food.col, 20,20,BLUE);
    // drawRectDMA(player.col,player.row, 30,30,BLUE);
    if (food.row < player.col + player.width &&
   food.row + food.width > player.col &&
   food.col < player.row + player.height &&
   food.col + food.height > player.row) {
       return 0;
    }
    return 1;
}