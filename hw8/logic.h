#include <stdlib.h>
#include "gba.h"

typedef struct brick{
	int row;
	int col;
    int width;
	int height;
    int oldrow;
    int oldcol;
	const u16 *image;
	int exists;
	int eaten;
} Food;

typedef struct {
	int col;
	int row;
	int height;
	int width;
} Player;

void initialize(void);
void movePlayer(u32 currentButtons, u32 previousButtons);
void foodGen(void);
void moveFood(void);
void display(void);
int eat(Food food, Player player);
int getScore(void);