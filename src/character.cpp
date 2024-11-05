#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

class Character{
    private:

        // förklarar hur gubben ser ut
        bool facingRight;
        bool isShooting;
        
        //Player status
        float hp;
        float stamina;

        //Typ id kan man säga
        std::string playerName;

        //Allt som har med sprite att göra
        sf::Texture texture;
        std::vector<sf::Texture> textureList;
        sf::Sprite sprite; 
        sf::IntRect rect;
        sf::Vector2f position;
        std::string state;
    
    public:
        Character(sf::Texture& texture, std::string playerName)
            : hp(100), stamina(2), texture(texture ), playerName(playerName), facingRight(true), isShooting(false)
        {
            // Left, Top, Width, Height
            rect = {0, 0, 42, 42};
            sprite = sf::Sprite(texture, rect);
            sprite.setPosition(500, 500);
            initiateTextures("1");
        }

        void invertSprite()
        {
            sprite.setScale(1.f, -1.f);
        }

        void revertSprite()
        {
            sprite.setScale(1.f, 1.f);
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

        void setStateTexture(int index){ 
            sf::Texture newTexture;
            newTexture = textureList[index];
            sprite.setTexture(newTexture);
        }

        void initiateTextures(std::string playerModel){
            std::ifstream file("textures.txt");
            if(!file){
                std::cout << "File couldn't open" << std::endl;
            }

            std::vector<std::string> ord;
            std::string str;

            while(file >> str){
                ord.push_back(str);
            }

            for (auto& text : ord){
                sf::Texture newTexture;
                text = "assets/" + playerModel + "/" + text + ".png";

                if(!newTexture.loadFromFile(text)){
                    std::cout << "Texture model: " << text << " couldn't load" << std::endl;
                }
                textureList.push_back(newTexture);

            }

            file.close();
        }
};