#include <iostream>

#include "entity/Entity.hpp"
#include "entity/Move.hpp"

#include "tools/Utils.hpp"

int main()
{
    using namespace path;

    Vector<double> vector_l;    vector_l.x = 2.1;    vector_l.y = 5.2;
    Entity entity_l(vector_l, 3.1);

    Move move_l(entity_l, vector_l);

    std::cout<<"Hello"<<std::endl;
    std::cout<<entity_l<<std::endl;
    std::cout<<move_l<<std::endl;

    std::cout<<tools::f_sqrt(144)<<std::endl;
    return 0;
}
