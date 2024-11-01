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
            vector<Character> newCharList = characterList;
            for(auto& ChEntry : newCharList)
            {
                if( ChEntry.getPlayerName() == playerName)
                {
                    
                }
            }

        }

        void createSprite(sf::Texture& texture, std::string playerName)
        {
            Character newChar = Character(texture, playerName);
            characterList.push_back(newChar);
        }
};