#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>
#include <string>

namespace SDLE
{
	class Drawable
	{
	public:
		Drawable();
		~Drawable();
		bool loadTexture(const std::string & filePath);

	private:
		SDL_Texture * mTexture;
		SDL_Rect mTexSource;
		SDL_Rect mTexDestination;
	};
} //!SDLE

#endif // !DRAWABLE_H
