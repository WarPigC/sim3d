#ifndef SIM3D_H
#define SIM3D_H

#include <iostream>
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>


struct Point {
	float x, y;
};

typedef std::vector<Point> Coordinates;

enum Directions {
	UP, DOWN, LEFT, RIGHT
};


extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

constexpr int kScreenWidth{ 1000 };
constexpr int kScreenHeight{ 1000 };


constexpr float moveDelta { 5 };

class cube {
	private:
		Point A, B, C, D;
	public:
		cube(Coordinates);

		cube(cube&) = delete;
		cube(cube&&) = delete;

		cube& operator=(const cube&) = delete;
		cube& operator=(cube&&) = delete;

		Coordinates getCoordinates();
		int getSideLen();

		void render();
		void updatePos(Directions);
};

#endif 
