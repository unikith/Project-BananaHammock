#ifndef WINDOW_H
#define WINDOW_H

#include "Drawable.h"

namespace SDLE
{
	class Window
	{
	public:
		Window();
		~Window();

		void clear();
		void display();
		bool draw(const SDLE::Drawable& objectToDraw);
		bool isOpen() { return mWindow != nullptr; }
		void screenPause(long millisecondsPause) { SDL_Delay(millisecondsPause); }

	private:
		SDL_Window * mWindow;
		SDL_Renderer * mRenderer;
		double mXPos;
		double mYPos;
		double mWidth;
		double mHeight;
		std::string mWindowName;
	};
} // !SDLE

#endif // !WINDOW_H
