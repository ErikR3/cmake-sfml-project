#include "inputHandler.cpp"
#include <iostream>

int main()
{
    inputHandler::mainLoop();
    std::cout << "Window closed, exiting program." << std::endl;
    return 0;
}
