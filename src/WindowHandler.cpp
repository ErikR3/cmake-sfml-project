#include <SFML/Graphics.hpp>
#include "CharacterHandler.cpp"
#include <iostream>
#include <string>

class WindowHandler{

    private: 
        CharacterHandler CH;

    public:
    
        WindowHandler()
        {
            CH = CharacterHandler();
        }
    

        static void mainLoop()
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
            window.display();
        }
    }
};
