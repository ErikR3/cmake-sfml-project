#include <SFML/Graphics.hpp>
#include "Character.cpp"
#include <vector>
#include <string>

class CharacterHandler{
    private: 
        int rectDifference = 42;
        sf::Clock animationTimer;
        sf::IntRect rect;
        std::vector<Character> characterList;


    public:
        CharacterHandler()
        {
            animationTimer = sf::Clock();
            
        }

        int getTime()
        {
            int frameIndex = static_cast<int>(animationTimer.getElapsedTime().asSeconds() / 0.2) % 6;

            return frameIndex;
        }

        void setAnimationFrame(std::string playerName)
        {
           
            for(auto& ChEntry : characterList)
            {
                if( ChEntry.getPlayerName() == playerName)
                {
                    ChEntry.setTextRect(rect);
                }
            }
        }

        void setAnimationRect(std::string playerName)
        {
            int frameIndex = getTime();

            sf::IntRect newRect = rect;
            newRect.left = frameIndex * rectDifference;

            rect = newRect;

            std::cout << rect.left << "\n";
            setAnimationFrame(playerName);

            if(frameIndex == 6){
                animationTimer.restart();
            }
        }

        void createSprite(sf::Texture& texture, std::string playerName)
        {
            Character newChar = Character(texture, playerName);
            characterList.push_back(newChar);
        }

        void getSprite(Character c)
        {
            c.getSprite();
        }

        std::vector<Character> getCharacterList()
        {
            return characterList;
        }

        std::vector<sf::Sprite> getSprites()
        {
            std::vector<sf::Sprite> spriteList;
            for(auto& chEntry : characterList)
            {
                spriteList.push_back(chEntry.getSprite());
            }

            return spriteList;
        }

        void printName(){
            for (auto& chEntry : characterList){
                	std::cout << chEntry.getPlayerName() << "\n";
            }
        }

        void setPosition(sf::Vector2f newpos){
            newpos = {200, 200};
            for(auto& chEntry : characterList)
            {
                chEntry.setPosition(newpos);
            }
        }

        sf::Sprite getSprite(std::string name)
        {
            sf::Sprite sp;
            for(auto& chEntry : characterList)
            {
                if(chEntry.getPlayerName() == name){
                    sp = chEntry.getSprite();
                }
            }

            return sp;
        }

};