#include "Move.hpp"

#include "Entity.hpp"

namespace path {

Move::Move(Entity const & entity_p, Vector<double> const & vector_p) : _entity(entity_p), _vector(vector_p) {}
Move::Move(Move const & other_p) : _entity(other_p._entity), _vector(other_p._vector) {}

Entity const & Move::getEntity() const
{
    return _entity;
}
Vector<double> const & Move::getVector() const
{
    return _vector;
}

std::ostream & operator<<(std::ostream & ostream_p, Move const & move_p)
{
    return ostream_p<<"Move["<<move_p.getEntity()<<", vector="<<move_p.getVector()<<"]";
}

}