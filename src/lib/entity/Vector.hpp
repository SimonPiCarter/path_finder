#pragma once

#include <iostream>

namespace path {

template<typename T>
struct Vector
{
    T x;
    T y;
};

template<typename T>
std::ostream & operator<<(std::ostream & ostream_p, Vector<T> const & vector_p)
{
    return ostream_p<<"("<<vector_p.x<<";"<<vector_p.y<<")";
}

template<typename T>
Vector<T> operator*(T const factor_p, Vector<T> const &vector_p)
{
    Vector<T> newVect_l;
    newVect_l.x = vector_p.x * factor_p;
    newVect_l.y = vector_p.y * factor_p;
    return newVect_l;
}

template<typename T>
Vector<T> operator*(Vector<T> const &vector_p, T const factor_p)
{
    return factor_p * vector_p;
}

template<typename T>
Vector<T> operator+(Vector<T> const &vectorA_p, Vector<T> const &vectorB_p)
{
    Vector<T> newVect_l;
    newVect_l.x = vectorA_p.x + vectorB_p.x;
    newVect_l.y = vectorA_p.y + vectorB_p.y;
    return newVect_l;
}

}