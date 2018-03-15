
#include "DirectionEntity.hpp"

namespace path
{

DirectionEntity::DirectionEntity() : Entity(), _direction() {}
DirectionEntity::DirectionEntity(DirectionEntity const & other_p) : Entity(other_p), _direction(other_p._direction) {}
DirectionEntity::DirectionEntity(Vector<double> const &direction_p, Vector<double> const &vector_p, double const & radius_p)
    : Entity(vector_p, radius_p), _direction(direction_p)
    {}

DirectionEntity::~DirectionEntity() {}

Vector<double> const & DirectionEntity::getDirection() const
{
    return this->_direction;
}
void DirectionEntity::setDirection(Vector<double> const & direction_p)
{
    this->_direction = direction_p;
}

}
