//
//  Sprite.hpp
//  Summer Game
//
//  Created by Christian Burke on 5/19/17.
//  Copyright © 2017 Christian Burke. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

//#include <SDL2_image/SDL_image.h>
#include "Drawable.hpp"

class Sprite : public Drawable {
public:
    Sprite(Window * window = nullptr, const std::string &path = "");
    ~Sprite();
    /*
        Loads the texture onto the sprite given the following path.
     */
    void loadTexture(Window * window, const std::string &path);
    /*
        Should be used for sprite sheets. Doesn't work by the way.
     */
    void loadTexture(Window * window, SDL_Texture * texture); //FIX THIS
    /*
        Sets the absolute position of the image to the x, y pixel in the window.
     */
    void setPosition(int x, int y);
    /*
        Moves the sprite on the window the given amount of pixels in x, y.
     */
    void move(int x, int y);
    /*
        Sets the angle of rotation of the image.
     */
    void setAngle(double deg);
    /*
        Rotates the image the given amount of degrees relative to its
        current rotation.
     */
    void rotate(double deg);
    /*
        Scalar multiplies the width and height. For example (1, 1.5) keeps
        width the same and height 1.5 times larger.
     */
    void scale(float widthScalar, float heightScalar);
    /*
        Scales the image to the specified pixels lengths.
     */
    void scaleToPixel(int widthPixels, int heightPixels);
    /*
        Crops the image to only display the given rect relative to the image.
        For example {.x = 10, .y = 0, .w = 100, .h = 200} would make this sprite
        display the rectangle 100 wide, 200 high and it's top left corner at (10,0)
        in the original image
     */
    void crop(const SDL_Rect &cRect);
    /*
        Removes crop and restores sprite to the original full image.
     */
    void unCrop();
    /*
        Sets the point on the image that is rotated around and position set to.
     */
    void setOrigin(int x, int y);
    /*
        Flips the image horizontally. Flipping twice results in the original image.
     */
    void flipHorizontal();
    /*
        Flips the image vertically. Flipping twice results in the original image.
     */
    void flipVertical();
    /*
        Draws the sprite to the window.
     */
    virtual void draw();
    
    //GETTERS
    double getAngle() const {return angle;}
    int getWidth() const {return dstRect.w;}
    int getHeight() const {return dstRect.h;}
    
    
private:
    //Functions
    /*
        Keeps the angle between 0 and 360.
     */
    void normalizeAngle();
    
    //MEMBER VARIABLES
    SDL_Texture *texture;
    SDL_Rect cropRect;
    SDL_Rect dstRect;
    SDL_Point origin;
    int flipFlags; //SDL_RendererFlip
    bool ifCropped;
    double angle;
    
protected:
    Window * window;
};

#endif /* Sprite_hpp */
