#include "sim3d.h"


SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;



bool init(){
	bool success {true};

	if (SDL_Init( SDL_INIT_VIDEO ) == false){
		SDL_Log("Failed to initialize! %s", SDL_GetError());
		success = false;
	}
	else {
		if (SDL_CreateWindowAndRenderer("Cube Simulator", kScreenWidth, kScreenWidth, 0, &gWindow, &gRenderer) == false){
			SDL_Log("Failed to create window and renderer! %s", SDL_GetError());
			success = false;
		}
	}

	return success;
}


void close(){

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}



int main(){
	int exitCode {};


	if (init() == false) {
		SDL_Log("Couldn't initialize program! %s", SDL_GetError());
		exitCode = 1;
	}
	else {

		bool quit { false };

		// screen does not follow cartesian plane, (0, 0) at bottom left
		cube Cube({
			{490, 490}, 
			{510, 490},
			{510, 510},
			{490, 510}
		});

		SDL_Event e;
		SDL_zero(e);

		while ( quit == false ){

			// Event loop
			while (SDL_PollEvent(&e) == true) {
				if (e.type == SDL_EVENT_QUIT){
					quit = true;
				}

				else if (e.type == SDL_EVENT_KEY_DOWN) {
					if (e.key.key == SDLK_UP){
						Cube.updatePos(Directions::UP);
					}
					else if (e.key.key == SDLK_DOWN) {
						Cube.updatePos(Directions::DOWN);
					}
					else if (e.key.key == SDLK_RIGHT) {
						Cube.updatePos(Directions::RIGHT);
					}
					else if (e.key.key == SDLK_LEFT) {
						Cube.updatePos(Directions::LEFT);
					}
					else {
						continue;
					}
				}

				/*
				else if (e.type == SDL_EVENT_KEY_UP) {

				}
				*/
			}

			SDL_Color bgColor {0xFF, 0xFF, 0xFF, 0xFF};
			SDL_SetRenderDrawColor(gRenderer, bgColor.r, bgColor.g, bgColor.b, 0xFF);

			SDL_RenderClear(gRenderer);
			Cube.render();
			SDL_RenderPresent( gRenderer );
		}
		
	}

	close();

	return exitCode;
}
