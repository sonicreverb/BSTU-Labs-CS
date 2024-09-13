#pragma once
#include "iostream"

static class Lab1 {
public: 
	static void task1()
	{
		long int a = 9, b = a, c, C;
		c = a + b;

		__asm {
			mov eax, a     // eax register = a
			add eax, b     // eax += b
			mov C, eax     // c = eax
		}

		__asm {
			jo ERR
		}

		std::cout << c << " " << C << std::endl;

	CONT:
		return;
	ERR:
		std::cout << "overflow" << std::endl;
		goto CONT;
	}

	static void task2()
	{
		// ax2+bx+c=0
		// (x+2)(x-3.5) = 0
		// x2 - 1.5x - 7 = 0
		// a = 1, b = -1.5, c = -7

		double  a = 1, b = -1.5, c = -7;
		double _2 = 2, _4 = 4, sqrD, x1, x2;

		__asm {
			// discriminant calculation
			fld b
			fmul b // b^2
			fld _4
			fmul a
			fmul c // 4ac
			fsub // b^2 - 4ac (discriminant)
			fsqrt
			fstp sqrD // sqr of discriminant
		}

		__asm {
			// x1 calculation (-b -sqrD) / 2a
			fld b
			fchs
			fld sqrD
			fsub
			fld _2
			fdiv
			fld a
			fdiv
			fstp x1
		}

		_asm {
			// x2 calculation (-b + sqrD) / 2a
			fld b
			fchs
			fld sqrD
			fadd
			fld _2
			fdiv
			fld a
			fdiv
			fstp x2
		}

		std::cout << "x1: " << x1 << "; x2: " << x2 << std::endl;
		return;
	}
};