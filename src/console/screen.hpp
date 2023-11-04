#pragma once
#include <string>
#include <iostream>

class screen
{
public:

    unsigned int width = 130;
    unsigned int height = 40;
    const char background_sign;
    std::string screen_content;

    screen(const char b);
    void outputScreen();

};