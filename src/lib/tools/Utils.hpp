#pragma once

namespace path {

namespace tools {

double inline __declspec (naked) __fastcall f_sqrt(double n)
{
	__asm fld qword ptr [esp+4]
	__asm fsqrt
	__asm ret 8
}

}

}
