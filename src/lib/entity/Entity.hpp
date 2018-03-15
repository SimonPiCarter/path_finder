#pragma once

#include "Vector.hpp"

namespace path {
/**
 * @brief This class is an object with a position and a radius.
 * It is used for basic 2D collision detection
 **/
class Entity
{
public:
    Entity();
    Entity(Entity const & other_p);
    Entity(Vector<double> const &vector_p, double const & radius_p);

    Vector<double> const & getPosition() const;
    void setPosition(Vector<double> const & position_p);

    double const & getRadius() const;
    void setRadius(double const & radius_p);

private:
    Vector<double> _position;
    double _radius;
};

std::ostream & operator<<(std::ostream & ostream_p, Entity const & entity_p);

}

