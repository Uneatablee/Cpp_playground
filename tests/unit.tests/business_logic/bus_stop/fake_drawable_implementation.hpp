#pragma once

#include "Idrawable.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;

class fake_drawable_implementation : public Idrawable
{

public:

    fake_drawable_implementation() = default;
    virtual ~fake_drawable_implementation() = default;

    bool draw(int, std::string) override;
};
