#pragma once

#include <cassert>

namespace path {

class Move;

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
bool checkAndUpdateMoves(Move & move1_p, Move & move2_p);


}

}
