#include <iostream>

#include "entity/Entity.hpp"
#include "entity/DirectionEntity.hpp"
#include "entity/Move.hpp"

#include "tools/Utils.hpp"

#include "Window.hpp"

void delVector(std::vector<path::Entity *> const & _vEntities)
{
    for ( path::Entity * ent_l : _vEntities )
    {
        delete ent_l;
    }
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

    std::cout<<tools::f_sqrt(144)<<std::endl;

    Vector<double> dir_l;    dir_l.x = 1.0;    dir_l.y = 0.0;
    std::vector<path::Entity *> vEntities_l;
    vector_l.x = 2.1;    vector_l.y = 5.2;
    vEntities_l.push_back(new DirectionEntity(dir_l, vector_l, 2.0));
    vector_l.x = 12.1;    vector_l.y = 15.2;
    vEntities_l.push_back(new Entity(vector_l, 2.0));
    Window window_l(20.0, vEntities_l);
    if ( window_l.init(800,600) )
    {
        do
        {
            window_l.display();
        } while(window_l.handleEvents());
    } else
    {
        delVector(vEntities_l);
        return 1;
    }
    delVector(vEntities_l);
    return 0;
}
