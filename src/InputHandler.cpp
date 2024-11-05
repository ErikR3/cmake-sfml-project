#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class InputHandler{


    float speedX = 0;
    float speedY = 0;

    std::string playerName;

    InputHandler(std::string playerName)
        : playerName(playerName)
    {

    }
    
    int checkInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            return 8;
        } else {
            return 0;
        }
    }
};