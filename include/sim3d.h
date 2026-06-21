#ifndef SIM3D_H
#define SIM3D_H

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>

int pos();
int render();

class LTexture{
private:
	SDL_Texture* mTexture;

	int mWidth, mHeight;


public:
	LTexture();

	~LTexture();

	bool loadFromFile(std::string path);

	void destroy();

	void render(float, float);

	int getWidth();
	int getHeight();
	bool isLoaded();
};


extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern LTexture gPngTexture;

constexpr int kScreenWidth{ 900 };
constexpr int kScreenHeight{ 900 };

#endif 
