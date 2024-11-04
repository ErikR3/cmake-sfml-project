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
            : hp(100), stamina(2), texture(texture ), playerName(playerName), facingRight(true), isShooting(false)
        {
            // Left, Top, Width, Height
            rect = {0, 0, 42, 42};
            sprite = sf::Sprite(texture, rect);
            sprite.setPosition(500, 500);
        }


        float getHp() const {return hp;}
        void setHp(float newHp) { hp = newHp; }

        float getStamina() const { return stamina; }
        void setStamina(float newStamina) { stamina = newStamina; }

        void setTextRect( sf::IntRect& newTex ) 
        { 
            rect = newTex;
            sprite.setTextureRect(rect); 
        }

        void printRect(){
            std::cout << rect.left << " " << rect.top << " " << rect.height << " " << rect.width << std::endl;
        }

        sf::Sprite& getSprite() { return sprite; }

        const std::string getPlayerName() const {return playerName; }

        const bool getFacingRight() const { return facingRight; }
        void setFacingRight( bool newFacingRight ) { facingRight = newFacingRight; }

        const bool getIsShooting() const { return isShooting; }
        void setIsShooting( bool newIsShooting ) { isShooting = newIsShooting; }

        const sf::Vector2f getPosition() const { return position; }
        void setPosition(sf::Vector2f newPos) { position = newPos; sprite.setPosition(position); }
};