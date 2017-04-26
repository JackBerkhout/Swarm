/*
 * Screen.h
 *
 *  Created on: Apr 25, 2017
 *      Author: jacksoft
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace jacksoft {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

public:
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	Uint32 getPixel(int x, int y, Uint8 *red, Uint8 *green, Uint8 *blue);
	Uint32 rgbColor(Uint8 red, Uint8 green, Uint8 blue);
	void update();
	void clear1();
	void clear2();
	void close();
	void boxBlur();
};

} /* namespace jacksoft */

#endif /* SCREEN_H_ */
