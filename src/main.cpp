//============================================================================
// Name        : SDL_Basic.cpp
// Author      : JackSoft
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace jacksoft;

int main() {

	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		cout << "Error initializing SDL: screen.init failed" << endl;
	}

	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;
	Uint32 color = screen.rgbColor(red, green, blue);
	cout << setfill('0') << setw(8) << hex << color << endl;

	int size = 50;
	int offsetX = 0;
	int oldOffsetX = 0;
	int oldOffsetY = 0;
	int offsetY = 0;
	bool dirX = true;
	bool dirY = true;
	float angleR = 0.0;
	float angleG = 0.0;
	float angleB = 0.0;

	Swarm swarm;

	while (true) {

		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);
		unsigned char green =
				(unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0004)) * 128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0006)) * 128);

		const Particle * const pParticles = swarm.getParticles();

//		screen.clear();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2;
			screen.setPixel(x, y, red, green, blue);
//			screen.setPixel(x+1, y, red, green, blue);
//			screen.setPixel(x, y+1, red, green, blue);
//			screen.setPixel(x+1, y+1, red, green, blue);
		}

		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages/events
		if (!screen.processEvents()) {
			break;
		}

	}

	screen.close();

	return 0;
}
