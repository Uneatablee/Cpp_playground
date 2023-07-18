#include "../include/diagonal_throw_functions.hpp"

namespace cpp_playground
{
    namespace pg_business_logic
    {

        namespace diagonal_throw
        {

            double throw_draw(int a, int b)
            {
                std::cout <<"Drawing throw" <<std::endl;
                return a*b/2;
            }

        }
    }
}