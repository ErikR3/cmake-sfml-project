#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Character{
    private:
        bool facingRight;
        bool isShooting;
        std::string playerName;
        float hp;
        float stamina;
        sf::Texture texture;
        sf::Sprite sprite; 
        sf::IntRect rect;
        sf::Vector2f position;
    
    public:
        Character(sf::Texture& texture, std::string playerName)
            : hp(100), stamina(2), texture(texture), playerName(playerName), facingRight(true), isShooting(false)
        {
            sprite.setTexture(texture);
            // Left, Top, Width, Height
            rect = {0, 0, 42, 42};
            sprite.setTextureRect(rect);
            sprite.setPosition(500, 500);
        }


        float getHp() const {return hp;}
        void setHp(float newHp) { hp = newHp; }

        float getStamina() const { return stamina; }
        void setStamina(float newStamina) { stamina = newStamina; }

        void setTextRect( sf::IntRect newTex ) { sprite.setTextureRect(newTex); }

        void setSpriteNextAnimationFrame(int animationFrame) 
        { 
            sf::IntRect newRect = rect;
            if(animationFrame == 0) {
                newRect.left = 42;
            } else if (animationFrame == 5) {
                newRect.left = 0;
            } else {
                newRect.left = animationFrame * 42;
            }
            setTextRect(newRect);
        }
        const sf::Sprite getSprite() const { return sprite; }

        const std::string getPlayerName() const {return playerName; }

        const bool getFacingRight() const { return facingRight; }
        void setFacingRight( bool newFacingRight ) { facingRight = newFacingRight; }

        const bool getIsShooting() const { return isShooting; }
        void setIsShooting( bool newIsShooting ) { isShooting = newIsShooting; }

        const sf::Vector2f getPosition() const { return position; }
        void setPosition(sf::Vector2f newPos) { position = newPos; sprite.setPosition(position); }
};