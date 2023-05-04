#include <iostream>
#include <string>
#include <cmath>


#define PI 3.14159265

using namespace std;


double f(double x) {
	double arr[4] = { 0.333333333333333, 0.13333333333333, 0.0539682539682, 0.0218694885361 };
	double res = 0;
	__asm {
		finit
		fld1 //для суммы
		fld1 //для x*x
		fld qword ptr x
		fmul st(2), st(0)

		fmul st(1), st(0)
		fmul st(1), st(0)

		mov edi, 0
		lea eax, arr
		mov esi, 1
		mov ebx, 4
		FOR :
		cmp esi, ebx
			jge NEXT

			fmul st(0), st(1)

			fld qword ptr[eax][esi * 8]

			fmul st(0), st(1)
			faddp st(3), st(0)

			inc esi
			jmp FOR

			NEXT :
		fld st(2)
			fstp qword ptr res
	}
	return res;
}



int main()
{

	cout << f(PI / 6) << "\n";
	cout << tan(PI / 6);
}