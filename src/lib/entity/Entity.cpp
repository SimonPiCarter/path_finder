#include "Entity.hpp"

namespace path {

Entity::Entity() : _position(), _radius(0.0) {}
Entity::Entity(Entity const & other_p) : _position(other_p._position), _radius(other_p._radius) {}
Entity::Entity(Vector<double> const &vector_p, double const & radius_p) : _position(vector_p), _radius(radius_p) {}

Vector<double> const & Entity::getPosition() const
{
    return this->_position;
}
void Entity::setPosition(Vector<double> const & position_p)
{
    this->_position = position_p;
}

double const & Entity::getRadius() const
{
    return this->_radius;
}
void Entity::setRadius(double const & radius_p)
{
    this->_radius = radius_p;
}

std::ostream & operator<<(std::ostream & ostream_p, Entity const & entity_p)
{
    return ostream_p<<"Entity[pos="<<entity_p.getPosition()<<", rad="<<entity_p.getRadius()<<"]";
}

}