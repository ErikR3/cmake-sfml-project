#include <SFML/Graphics.hpp>
#include "CharacterHandler.cpp"
#include <iostream>
#include <string>
#include <vector>

class WindowHandler{

    private: 
        CharacterHandler CH;
        sf::Texture texture;
        std::vector<sf::Sprite> SPV;

    public:
    
        WindowHandler()
        {
            if(!texture.loadFromFile("assets/1/Run.png")){
                std::cout << "Couldnt load texture";
            }

            

            CH = CharacterHandler();
            CH.createSprite(texture, "Erik");
        }
    

        void mainLoop()
    {

        auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
        window.setFramerateLimit(60);


        while (window.isOpen())
        {
            for (auto event = sf::Event(); window.pollEvent(event);)
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();

            SPV = CH.getSprites();
            CH.setAnimationRect("Erik");
            window.draw(CH.getSprite("Erik"));
            CH.printRect();
            SPV.clear();
            
            window.display();
        }
    }
};
