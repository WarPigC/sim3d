#include "sim3d.h"
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>


SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
LTexture gUpTexture, gDownTexture, gLeftTexture, gRightTexture, gWhiteTexture;



bool LTexture::loadFromFile(std::string path){

	// remove any existing surface
	destroy();
	SDL_Surface* loadedSurface;

	if (loadedSurface = IMG_Load(path.c_str()); loadedSurface == nullptr){
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
		if (SDL_CreateWindowAndRenderer("SDL3 keyboard", kScreenWidth, kScreenWidth, 0, &gWindow, &gRenderer) == false){
			SDL_Log("Failed to create window and renderer! %s", SDL_GetError());
			success = false;
		}
	}

	return success;
}

bool loadMedia(){

	bool success { true };

	if (gUpTexture.loadFromFile("src/up.jpg") == false){
		SDL_Log("Coultn't load up image! %s", SDL_GetError());
		success = false;
	}
	if (gDownTexture.loadFromFile("src/down.png") == false){
		SDL_Log("Coultn't load down image! %s", SDL_GetError());
		success = false;
	}
	if (gLeftTexture.loadFromFile("src/left.jpg") == false){
		SDL_Log("Coultn't load left image! %s", SDL_GetError());
		success = false;
	}
	if (gRightTexture.loadFromFile("src/right.jpg") == false){
		SDL_Log("Coultn't load right image! %s", SDL_GetError());
		success = false;
	}
	if (gWhiteTexture.loadFromFile("src/white.jpg") == false){
		SDL_Log("Coultn't load white image! %s", SDL_GetError());
		success = false;
	}

	return success;
}

void close(){
	gUpTexture.destroy();
	gDownTexture.destroy();
	gLeftTexture.destroy();
	gRightTexture.destroy();
	gWhiteTexture.destroy();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}



int main(){
	int exitCode {};

	LTexture* currentTexture = &gWhiteTexture;

	SDL_Color bgColor { 0xFF, 0xFF, 0xFF, 0xFF };


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

					else if (e.type == SDL_EVENT_KEY_DOWN) {
						if (e.key.key == SDLK_UP){
							currentTexture = &gUpTexture;
						}
						else if (e.key.key == SDLK_DOWN){
							currentTexture = &gDownTexture;
						}
						else if (e.key.key == SDLK_LEFT){
							currentTexture = &gLeftTexture;
						}
						else if (e.key.key == SDLK_RIGHT){
							currentTexture = &gRightTexture;
						}
					}
					else if (e.type == SDL_EVENT_KEY_UP) {
						currentTexture = &gWhiteTexture;
					}

				}

				// set white
				bgColor.r = 0xFF;
				bgColor.g = 0xFF;
				bgColor.b = 0xFF;


				SDL_SetRenderDrawColor(gRenderer, bgColor.r, bgColor.g, bgColor.b, 0xFF);
				SDL_RenderClear(gRenderer);

				currentTexture->render( (kScreenWidth - currentTexture->getWidth()) * 0.5f, (kScreenHeight - currentTexture->getHeight()) * 0.5f);

				SDL_RenderPresent( gRenderer );
			}
		}
	}

	close();

	return exitCode;
}
