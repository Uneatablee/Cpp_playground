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

    screen(const char b) : background_sign(b)
    {
        screen_content += '@' + std::string(width - 2,'-') + '@' + '\n'; // top border
        for(unsigned int i = 0; i < height - 7; i++)
        {
            screen_content += '|' + std::string(width - 2, background_sign) + '|' + '\n';
        }

        screen_content += '@' + std::string((width - 7)/2,'-') +'|' + "MENU" + '|' + std::string((width - 7)/2,'-') + '@' + '\n'; // menu border

        for(unsigned int i = 0; i < 7; i++)
        {
            screen_content += '|' + std::string(width - 2, background_sign) + '|' + '\n';
        }
        screen_content += '@' + std::string(width - 2,'-') + '@' + '\n'; // bottom border
    }

    void outputScreen()
    {
        std::cout << screen_content;
    }

};