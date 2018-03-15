#pragma once

#include "Entity.hpp"

namespace path
{

class DirectionEntity : public Entity
{
public:
    DirectionEntity();
    DirectionEntity(DirectionEntity const & other_p);
    DirectionEntity(Vector<double> const &direction_p, Vector<double> const &vector_p, double const & radius_p);

    virtual ~DirectionEntity();

    Vector<double> const & getDirection() const;
    void setDirection(Vector<double> const & direction_p);
private:
    Vector<double> _direction;
};

}
