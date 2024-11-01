#include <SFML/Graphics.hpp>
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
    
    public:
        Character(float hp, sf::Texture& texture, std::string playerName)
            : hp(hp), stamina(2), texture(texture), playerName(playerName)
        {
            sprite.setTexture(texture);
        }


        float getHp() const {return hp;}
        void setHp(float newHp) { hp = newHp; }

        float getStamina() const { return stamina; }
        void setStamina(float newStamina) { stamina = newStamina; }

        void setTexture(const sf::Texture newTex) { texture = newTex; }

        const sf::Sprite getSprite() const { return sprite; }

        const std::string getPlayerName() const {return playerName; }

        const bool getFacingRight() const { return facingRight; }
        void setFacingRight( bool newFacingRight ) { facingRight = newFacingRight; }

        const bool getIsShooting() const { return isShooting; }
        void setIsShooting( bool newIsShooting ) { isShooting = newIsShooting; }
};