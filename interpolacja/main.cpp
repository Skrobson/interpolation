#include <cmath>
#include "mathUtils.h"
#include "Interpolation.h"
#include <iostream>
#include <conio.h>



int main()
{
	auto fx = [](double x) {return abs(cos(x)*x); };

	Interpolation I;
	size_t n = 3;

	//czebyszew(8, -3, 3, I.mX, I.mY,fx);
	
	I.setNodes(n);
	parallelNodes(n, -3, 3, I.mX);
	I.mY.clear();
	for (auto obj : I.mX) {
		I.mY.push_back(fx(obj));
	}
	std::cout << cos(0);
	for (unsigned i = 0; i <= n; ++i)
	{
		std::cout << I.mX[i] << " " << I.mY[i] << " " << I.newton(I.mX[i]) << std::endl;

	}
	_getch();

	return 0;
}