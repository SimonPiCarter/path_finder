#pragma once

#include <cassert>

namespace path {

namespace tools {

// fast sqrt
double inline __declspec (naked) __fastcall f_sqrt(double n)
{
	__asm fld qword ptr [esp+4]
	__asm fsqrt
	__asm ret 8
}

/**
 * @brief will check if the comination of two moves is legal.
 * If not will update vectors in order to have maximum move
 * without collision
 **/
bool checkAndUpdateMoves(Move & move1_p, Move & move2_p)
{
    double const & r1(move1_p.getEntity().getRadius());
    double const & r2(move2_p.getEntity().getRadius());
    Vector<double> const & p1(move1_p.getEntity().getPosition());
    Vector<double> const & p2(move2_p.getEntity().getPosition());
    Vector<double> & v1(move1_p.getVector());
    Vector<double> & v2(move2_p.getVector());
    double dx(p1.x-p2.x);
    double dy(p1.y-p2.y);
    double dvx(v1.x-v2.x);
    double dvy(v1.y-v2.y);
    double R(r1+r2);

    double a(dvx*dvx + dvy*dvy);
    double b(2*dx*dvx + 2*dy*dvy);
    double c(dx*dx+dy*dy-R*R);


    double delta(b*b-4*a*c);
    if ( delta >= 0.0 )
    {
        double t((-b-f_sqrt(delta))/2.0/a);
        if ( t>= 0.0 && t<= 1.0 ) {
            move1_p.getVector() = t * move1_p.getVector();
            move2_p.getVector() = t * move2_p.getVector();
            return true;
        } else
        {
            return false;
        }
    } else
    {
        return false;
    }
}


}

}
