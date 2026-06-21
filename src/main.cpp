#include "sim3d.h"


SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
LTexture gPngTexture;



bool LTexture::loadFromFile(std::string path){

	// remove any existing surface
	destroy();
	SDL_Surface* loadedSurface;

	if (loadedSurface = IMG_Load("src/preview.png"); loadedSurface == nullptr){
		SDL_Log("Image not loaded! %s", SDL_GetError());
	}
	else {
		if ( mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface); mTexture == nullptr ) {
			SDL_Log("texture not rendered! %s", SDL_GetError());
		}
		else {
			mWidth = mTexture->w;
			mHeight = mTexture->h;
		}

		SDL_DestroySurface(loadedSurface);
	}

	return mTexture != nullptr;
}

void LTexture::destroy(){
	SDL_DestroyTexture(mTexture);
	mWidth = 0;
	mHeight = 0;
	mTexture = nullptr;
}


bool init(){
	bool success {true};

	if (SDL_Init( SDL_INIT_VIDEO ) == false){
		SDL_Log("Failed to initialize! %s", SDL_GetError());
		success = false;
	}
	else {
		if (SDL_CreateWindowAndRenderer("SDL3 rendering", kScreenWidth, kScreenWidth, 0, &gWindow, &gRenderer) == false){
			SDL_Log("Failed to create window and renderer! %s", SDL_GetError());
			success = false;
		}
	}

	return success;
}

bool loadMedia(){

	bool success { true };


	if (gPngTexture.loadFromFile("src/preview.png") == false){
		SDL_Log("Failed to load png! %s", SDL_GetError());
		success = false;
	}

	return success;
}

void close(){
	gPngTexture.destroy();

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
		if (loadMedia() == false) {
			SDL_Log("Failed to load media! %s", SDL_GetError());
			exitCode = 2;
		}
		else {

			bool quit { false };

			SDL_Event e;
			SDL_zero(e);

			while ( quit == false ){
				while (SDL_PollEvent(&e) == true) {
					if (e.type == SDL_EVENT_QUIT){
						quit = true;
					}
				}

				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				gPngTexture.render(0.f, 0.f);

				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close();

	return exitCode;
}
