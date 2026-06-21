/* ---------------------------------------------------------------------- */
/*                            Rendering Cube                              */
/* ---------------------------------------------------------------------- */

#include "sim3d.h"


LTexture::LTexture(){

	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture(){
	destroy();
}


void LTexture::render(float x, float y){

	SDL_FRect dstRect {
		x, y,
		static_cast<float>(mWidth), static_cast<float>(mHeight)
	};

	SDL_RenderTexture( gRenderer, mTexture, nullptr, &dstRect );

}

int LTexture::getWidth(){
	return mWidth;
}

int LTexture::getHeight(){
	return mHeight;
}

bool LTexture::isLoaded(){
	return mTexture != nullptr;
}




int render() {
	return 2;



}
