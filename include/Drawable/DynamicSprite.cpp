#include "DynamicSprite.h"

DynamicSprite::DynamicSprite(std::string texture, int x, int y, int width, int height, float scale):
Sprite(texture,x,y,width,height,scale)
{
    // initialise sprite to play idle animation
    currentFrame = 0;
    numFrames = 7;
    row = 0;
}

void DynamicSprite::updateAnimation(int numFrames, int row)
{
    /* change the animation values such that the new values 
    represent a new animation within the sprite sheet */
    currentFrame = 0;
    this->numFrames = numFrames;
    this->row = row;
}

bool DynamicSprite::animation(bool repeat, bool death)
{
    // check whether the current time since the last update is greater than 0.1 seconds
    if (clock.getElapsedTime().asSeconds() > 0.08f)
    
    {
        // if true, restart the clock and update the current frame of the texture rectangle
        clock.restart();

        /* if the current animation is not finished, such that its current frame does not equal the
        number of frames in the animation, update the texture rectangle and iterate the frame+1 */
        if (currentFrame != numFrames)
        {
            /* while the current frame is less than 8, its currently within its first row of animation. 
            update the texture rectangle such that it moves to the right 1 'size' sprite. Keep
            repeating this until it has moved 8 times. */ 

            // increase the row height by 1 every 8 frames
/*             if (currentFrame > 8)
            {
                sprite->setTextureRect(sf::IntRect(width * currentFrame, height * row + height, width, height));
                currentFrame++;
            } */
            if (currentFrame > 8 && currentFrame < 17)
            {
                sprite->setTextureRect(sf::IntRect(width *(currentFrame-9), height * row + height, width, height));
                currentFrame++;
            }
            else if (currentFrame > 16)
            {
                sprite->setTextureRect(sf::IntRect(width *(currentFrame-17), height * row + 2*height, width, height));
                currentFrame++;
            }
            else
            {
                sprite->setTextureRect(sf::IntRect(width * currentFrame, height * row, width, height));
                currentFrame++;
            }  
            
        }
        /* if the current animation is finished, use the parameter 'repeat' to either repeat the current animation
        or set update the animation values such that the idle animation is played instead */
        else
        {
            if (repeat == true)
            {
                // set current frame to 0 IF the animation needs to be repeated
                currentFrame=0;
            }
            else if(death == false)
            {
                // if not repeated, play idle animation
                updateAnimation(7, 0);
                return true;
            }
            /* if the death animation is being played, dont update the current animation
            and instead idle on the last frame*/
            else {}
        }
        
    }
    return false;
}

DynamicSprite::~DynamicSprite(){}