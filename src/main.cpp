#include <iostream>

#include "entity/Entity.hpp"
#include "entity/Move.hpp"

double inline __declspec (naked) __fastcall sqrt14(double n)
{
	__asm fld qword ptr [esp+4]
	__asm fsqrt
	__asm ret 8
}

int main()
{
    using namespace path;

    Vector<double> vector_l;    vector_l.x = 2.1;    vector_l.y = 5.2;
    Entity entity_l(vector_l, 3.1);

    Move move_l(entity_l, vector_l);

    std::cout<<"Hello"<<std::endl;
    std::cout<<entity_l<<std::endl;
    std::cout<<move_l<<std::endl;
    return 0;
}
