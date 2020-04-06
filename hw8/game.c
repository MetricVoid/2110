#include "game.h"

#include <stdio.h>
#include <stdlib.h>

#include "gba.h"
/* TODO: */
// Include any header files for title screen or exit
// screen images generated by nin10kit. Example for the provided garbage
// image:
// #include "images/garbage.h"

/* TODO: */
// Add any additional states you need for your app.
typedef enum {
  START,
  PLAY,
  WIN,
  LOSE,
} GBAState;

int main(void) {
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //

  // Save current and previous state of button input.
  u32 previousButtons = BUTTONS;
  u32 currentButtons = BUTTONS;

  // Load initial game state
  GBAState state = START;

  while (1) {
    currentButtons = BUTTONS;  // Load the current state of the buttons

    /* TODO: */
    // Manipulate the state machine below as needed //
    // NOTE: Call waitForVBlank() before you draw

    switch (state) {
      case START:

        // state = ?
        waitForVBlank();
        break;
      case PLAY:

        // state = ?
        break;
      case WIN:

        // state = ?
        break;
      case LOSE:

        // state = ?
        break;
    }

    previousButtons = currentButtons;  // Store the current state of the buttons
  }

  UNUSED(previousButtons);  // You can remove this once previousButtons is used

  return 0;
}