#include <SFML/Graphics.hpp>
#include "Character.cpp"
#include <iostream>
#include <string>

class inputHandler{
    public:
    
    

        static void mainLoop()
    {
        std::string filePath = "MainAfter.jpg";

        auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
        window.setFramerateLimit(60);

        sf::Texture texture;

        if(!texture.loadFromFile("MainAfter.jpg", sf::IntRect(10, 10, 32, 32)))
        {
            std::cout << "Fel vid inladdning av texture";
        }

        auto newCharacter = Character(100, texture, "Lord Erik");

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
