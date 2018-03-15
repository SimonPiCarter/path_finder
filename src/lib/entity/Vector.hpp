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

}