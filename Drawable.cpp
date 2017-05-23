#include "Drawable.h"



SDLE::Drawable::Drawable()
{
	this->mTexture = nullptr;
}


SDLE::Drawable::~Drawable()
{
	SDL_DestroyTexture(mTexture);
}
