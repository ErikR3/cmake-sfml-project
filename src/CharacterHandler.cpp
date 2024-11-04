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
            return animationTimer.getElapsedTime().asSeconds() > 1.0f;
        }

        void setAnimationFrane(std::string playerName)
        {
            std::vector<Character> newCharList = characterList;
            for(auto& ChEntry : newCharList)
            {
                if( ChEntry.getPlayerName() == playerName)
                {
                    ChEntry.setTextRect(rect);
                }
            }
        }

        void setAnimationFrame(int clockTime)
        {
            sf::IntRect newRect = rect;
            if(getTime() == 0)
            {
                newRect.left = 42;
            } else if (clockTime == 5) {
                newRect.left = 0;
            } else {
                newRect.left = clockTime * 42;
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
};