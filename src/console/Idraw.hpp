#pragma once

#include <iostream>

class Idraw
{
public:

    Idraw() = default;
    ~Idraw() = default;

    Idraw(const Idraw& object) = default;
    Idraw& operator=(const Idraw& object) = default;

    Idraw(Idraw&& object) = default;
    Idraw& operator=(Idraw && object) = default;

    virtual void draw() = 0;

}