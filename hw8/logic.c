#include "logic.h"
#include "gba.h"
#include "images/pusheen.h"
#include "images/background.h"
#include "images/start.h"
#include "images/cake.h"
#include "images/donut.h"
#include "images/cookie.h"

Food food[30];
Player player;
int score = 0;
int life = 3;
int screen = 0;

void initialize(void) {
	//randomly generate brick colors and draw them on the game screen
    for (int i = 0; i < 30; i++) {
        food[i].exists = 0;
    }
	// foodGen();
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
    drawImageDMA(player.col ,player.row,30,30,pusheen);
}

void movePlayer(u32 currentButtons, u32 previousButtons) {
    waitForVBlank();
    if (KEY_JUST_PRESSED(BUTTON_RIGHT, currentButtons, previousButtons)) {
        // press up
        waitForVBlank();
        if (player.col + 10 < 225) {
            drawRectDMA(0, 110, 240, 60 ,BLACK);
            player.col += 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
        // if (player.row + player )
    } else if (KEY_JUST_PRESSED(BUTTON_LEFT, currentButtons, previousButtons)) {
        waitForVBlank();
        if (player.col - 10 > 15) {
            drawRectDMA(0, 110, 240, 60 ,BLACK);
            player.col -= 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    } else if (KEY_JUST_PRESSED(BUTTON_UP, currentButtons, previousButtons)) {
        waitForVBlank();
        if (player.row - 10 > 100) {
            drawRectDMA(0, 110, 240, 60 ,BLACK);
            player.row -= 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    } else if (KEY_JUST_PRESSED(BUTTON_DOWN, currentButtons, previousButtons)) {
        waitForVBlank();
        // drawRectDMA(0,130,240,120 ,BLACK);
        if (player.row + 10 < 160) {
            drawRectDMA(0, 110, 240, 60 ,BLACK);
            player.row += 10;
            drawImageDMA(player.col ,player.row,30,30,pusheen);
        }
    }
    // foodGen();
    moveFood();
}

void moveFood(void) {
    drawRectDMA(0,0,240,120,BLACK);
    // int renew = 0;
	for (int i = 0; i < 30; i++) {
        if (food[i].exists) {
            if (food[i].col + 1 < 100) {
                food[i].col +=1;
                drawImageDMA(food[i].row, food[i].col, food[i].width, food[i].height, food[i].image);
            }
        }
        // if (food[i].row > 180) {
        //     renew = 1;
        // }
    }
    screen += 1;
    if (screen > 100) {
        foodGen();
        screen = 0;
    }
    
	

	// int brickCollision = brickCollide();
	// if(ball.row > 159) {
	// 	showEndScreen();
	// } else if(brickCollision != 0) {
	// 	ball.row = brickCollision;
	// 	ball.rowdel = -ball.rowdel;
	// } else if (ball.row <= 0) {
	// 	ball.row = 0;
	// 	ball.rowdel = -ball.rowdel;
	// } else if((ball.row >= (paddle.row - SMILEYFACE_HEIGHT)) && ((ball.col + (int)(SMILEYFACE_WIDTH / 2) - 1) > paddle.col) && ((ball.col  + (int)(SMILEYFACE_WIDTH / 2)) <= (paddle.col + paddle.width))) {
	// 	ball.row = paddle.row - SMILEYFACE_HEIGHT;
	// 	ball.rowdel = -ball.rowdel;
	// }
	// if(ball.col < 0) {
	// 	ball.col = 0;
	// 	ball.coldel = -ball.coldel;
	// }
	// if(ball.col > 239 - SMILEYFACE_WIDTH + 1) {
	// 	ball.col = 239 - SMILEYFACE_WIDTH + 1;
	// 	ball.coldel = -ball.coldel;
	// }

	// drawRectangle(ball.oldrow, ball.oldcol, SMILEYFACE_WIDTH, SMILEYFACE_HEIGHT, BLACK);
	// drawImage3(ball.row, ball.col, SMILEYFACE_WIDTH, SMILEYFACE_HEIGHT, smileyFace);
}