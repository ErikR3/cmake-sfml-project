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
            rect = {0,0,42,42};
        }

        int getTime()
        {
            int frameIndex = static_cast<int>(animationTimer.getElapsedTime().asSeconds() / 0.2) % 6;

            return frameIndex;
        }

        void setAnimationFrame(std::string playerName)
        {
           std::vector<Character> newCharList = characterList;

            for(auto& ChEntry : newCharList)
            {
                if( ChEntry.getPlayerName() == playerName)
                {
                    ChEntry.setTextRect(rect);
                }
            }

            characterList = newCharList;
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

        void setPosition(sf::Vector2f& newpos){
            newpos = {200, 200};
            for(auto& chEntry : characterList)
            {
                chEntry.setPosition(newpos);
            }
        }

        sf::Sprite& getSprite(const std::string& name) {
            for (auto& chEntry : characterList) {
                if (chEntry.getPlayerName() == name) {
                    return chEntry.getSprite();
                }
            }
            throw std::runtime_error("Character not found");
        }

        void printRect()
        {
            for (auto& chEntry : characterList) {
                if (chEntry.getPlayerName() == "Erik")
                {
                    chEntry.printRect();
                }
            }
        }

};