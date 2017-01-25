#include "Interpolation.h"
#include <iostream>


Interpolation::Interpolation()
{
}


Interpolation::~Interpolation()
{
}

double Interpolation::factorPolynomialial(int degree, double x)
{
	if (degree == 0)
		return 1;

	double tmp = 1;
	for (int i = 1; i <= degree; ++i)
	{
		tmp *=( x - mX[i-1]);
	}
	//std::cout << "wielomian czynnikowy stopnia " << degree << " " << tmp << std::endl;
	return tmp ;
}

double Interpolation::differentialQuotient(int n )
{
	double sum = 0.0;
	for (int i = 0; i <= n; ++i)
	{
		double quotient=1.0;
	
		for (int j = 0; j <= n; ++j)
		{
			if (i != j)
			{
				quotient *= (mX[i] - mX[j]);
			}
		}
		sum += (mY[i] / quotient);
	}
	std::cout << "iloraz roznicowy stopnia " << n << " " << sum << std::endl;
	return sum;
}

void Interpolation::setNodes(int n)
{
	nodes = n;
}

double Interpolation::newton(double x)
{
	double temp = 0.0;
	for (int i = 0; i <= nodes; ++i)
	{
		temp += (differentialQuotient(i)*factorPolynomialial(i, x));
	}
	
	return temp;
}
