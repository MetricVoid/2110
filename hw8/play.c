

void showStartScreen() {
	int startNotPressed = TRUE;
	drawImage3(0,0,STARTSCREEN_WIDTH, STARTSCREEN_HEIGHT, StartScreen);
	//wait and don't draw anything else until the start key is pressed
	while(startNotPressed) {
		if(KEY_DOWN_NOW(BUTTON_START)) {
			startNotPressed = FALSE;
		}
	}
	drawRectangle(0,0,STARTSCREEN_WIDTH, STARTSCREEN_HEIGHT, BLACK);
}