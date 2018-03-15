#pragma once

#include "Vector.hpp"

namespace path {

class Entity;

/**
 * @brief A simple class that store information about a
 * Entity moving. Stores an Entity and a move vector
 */
class Move
{
public:
    Move(Entity const & entity_p, Vector<double> const & vector_p);
    Move(Move const & other_p);

    Entity const & getEntity() const;
    Vector<double> const & getVector() const;
    Vector<double> & getVector();

private:
    Entity const & _entity;
    Vector<double> _vector;
};

std::ostream & operator<<(std::ostream & ostream_p, Move const & move_p);

}