#include "gba.h"

volatile unsigned short *videoBuffer = (volatile unsigned short *)0x6000000;
u32 vBlankCounter = 0;

void waitForVBlank(void) {
  // TODO: IMPLEMENT

  // (1)
  // Write a while loop that loops until we're NOT in vBlank anymore:
  // (This prevents counting one VBlank more than once if your app is too fast)

  // (2)
  // Write a while loop that keeps going until we're in vBlank:

  // (3)
  // Finally, increment the vBlank counter:
    while (SCANLINECOUNTER > 160)
        ;
    while (SCANLINECOUNTER < 160)
        ;
    vBlankCounter ++;
}

static int __qran_seed = 42;
static int qran(void) {
  __qran_seed = 1664525 * __qran_seed + 1013904223;
  return (__qran_seed >> 16) & 0x7FFF;
}

int randint(int min, int max) { return (qran() * (max - min) >> 15) + min; }

void setPixel(int row, int col, u16 color) {
  // TODO: IMPLEMENT
  videoBuffer[OFFSET(col, row, SCREEN_WIDTH)] = color;
}

void drawRectDMA(int x, int y, int width, int height, volatile u16 color)
{
  //TODO: IMPLEMENT
    for (int row = 0; row < height; row++)
    {
        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET(y + row, x, SCREEN_WIDTH)];
        DMA[3].cnt = width | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}

void drawFullScreenImageDMA(const u16 *image) {
  // TODO: IMPLEMENT
  DMA[3].src = image;
  DMA[3].dst = videoBuffer;
  DMA[3].cnt = (SCREEN_HEIGHT * SCREEN_WIDTH) | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
}
void drawFullScreenImagePortionDMA(int x, int y, int width, int height, const u16 *image)
{
    for (int row = 0; row < height; row++)
    {
        DMA[3].src = &image[x + (y + row) * SCREEN_WIDTH];
        DMA[3].dst = &videoBuffer[OFFSET(y + row, x, SCREEN_WIDTH)];
        DMA[3].cnt = width | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}

void drawImageDMA(int x, int y, int width, int height, const u16 *image) {
  // TODO: IMPLEMENT
  for (int row = 0; row < height; row++)
  {
      DMA[3].src = &image[row * width];
      DMA[3].dst = &videoBuffer[OFFSET(y + row, x, SCREEN_WIDTH)];
      DMA[3].cnt = width | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
  }
}

void fillScreenDMA(volatile u16 color) {
  // TODO: IMPLEMENT
  DMA[3].src = &color;
  DMA[3].dst = videoBuffer;
  DMA[3].cnt = SCREEN_HEIGHT * SCREEN_WIDTH | DMA_SOURCE_FIXED | DMA_ON;
}

void drawChar(int col, int row, char ch, u16 color)
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (fontdata_6x8[OFFSET(r, c, 6) + ch * 48])
            {
                setPixel(col + c, row + r, color);
            }
        }
    }
}

void drawString(int col, int row, char *str, u16 color)
{
    while (*str)
    {
        drawChar(col, row, *str++, color);
        col += 6;
    }
}

void drawCenteredString(int x, int y, int width, int height, char *str, u16 color)
{
    u32 len = 0;
    char *strCpy = str;
    while (*strCpy)
    {
        len++;
        strCpy++;
    }

    u32 strWidth = 6 * len;
    u32 strHeight = 8;

    int col = x + ((width - strWidth) >> 1);
    int row = y + ((height - strHeight) >> 1);
    drawString(col, row, str, color);
}

void delay(int n) {
    volatile int size = 0;
    for(int i=0; i<n*4000; i++)
    {
        size = size + 1;
    }
}