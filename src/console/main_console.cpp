#include "Menu.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;


int main()
{
    std::unique_ptr<Menu> menu_1 = std::make_unique<Menu>();
    menu_1 -> screenRefresh();
}