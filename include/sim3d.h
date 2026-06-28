#ifndef SIM3D_H
#define SIM3D_H

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>

int pos();
int render();

class cube {
	private:
		int x1, y1, x2, y2;
	public:
		cube(int, int, int, int);

		// rule of 5
		cube(cube&) = delete;
		cube(cube&&) = delete;

		cube& operator=(const cube&) = delete;
		cube& operator=(cube&&) = delete;

		int getX();
		int getY();
		int getSideLen();

		~cube();
};


extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

constexpr int kScreenWidth{ 1280 };
constexpr int kScreenHeight{ 600 };

#endif 
