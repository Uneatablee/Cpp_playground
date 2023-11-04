#include "screen.hpp"

screen::screen(const char b) : background_sign(b)
{
    screen_content += '@' + std::string(width - 3,'-') + '@' + '\n'; // top border
    for(unsigned int i = 0; i < height - 10; i++)
    {
        screen_content += '|' + std::string(width - 3, background_sign) + '|' + '\n';
    }

    screen_content += '@' + std::string((width - 9)/2,'-') +'|' + "MENU" + '|' + std::string((width - 8)/2,'-') + '@' + '\n'; // menu border

    std::string vehicle_text = "[1] -> Vehicle section.";
    std::string route_text = "[2] -> Route section.";
    std::string exit_text = "[0] -> Exit.";

    for(unsigned int i = 0; i < 7; i++)
    {
        screen_content += '|' + std::string(width - 3, background_sign) + '|' + '\n';
    }
    screen_content += '@' + std::string(width - 3,'-') + '@' + '\n'; // bottom border

    screen_content.replace(33 * width + 1, vehicle_text.length(), vehicle_text,0,vehicle_text.length());
    screen_content.replace(35 * width + 1, route_text.length(), route_text,0,vehicle_text.length());
    screen_content.replace(37 * width + 1, exit_text.length(), exit_text,0,exit_text.length());
}

void screen::outputScreen()
{
    std::cout << screen_content << std::flush;
}