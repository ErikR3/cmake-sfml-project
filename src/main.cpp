#include "WindowHandler.cpp"
#include <iostream>

int main()
{
    WindowHandler::mainLoop();
    std::cout << "Window closed, exiting program." << std::endl;
    return 0;
}
