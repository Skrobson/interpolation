#include "Interpolation.h"
#include <iostream>

NewtonInterpolation::NewtonInterpolation(const std::vector<double>& x, const std::vector<double>& y):mX(x),mY(y)
{
	mNodes = mX.size()-1;
	differentialQuotient();
}

NewtonInterpolation::NewtonInterpolation(const double * x, const double * y, size_t n):mNodes(n-1)
{
	for (size_t i = 0; i < n; ++i)
	{
		mX.push_back(x[i]);
		mY.push_back(y[i]);
	}
	differentialQuotient();
}

NewtonInterpolation::~NewtonInterpolation()
{
}


double NewtonInterpolation::factorPolynomialial(size_t degree, double x)
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


double NewtonInterpolation::differentialQuotient(size_t n )
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
	//std::cout << "iloraz roznicowy stopnia " << n << " " << sum << std::endl;
	return sum;
}

void NewtonInterpolation::differentialQuotient()
{
	mAi.clear();
	for (size_t i = 0; i <= mNodes; ++i)
	{
		mAi.push_back(differentialQuotient(i));
	}
}



void NewtonInterpolation::setArrays(const std::vector<double>& x, const std::vector<double>& y)
{
	mNodes = mX.size() - 1;
	mX.clear();
	mX = x;
	mY.clear();
	mY = y;
	differentialQuotient();
}

void NewtonInterpolation::setArrays(const double * x, const double * y, size_t size)
{
	mX.clear();
	mY.clear();
	mNodes = size-1;
	for (size_t i = 0; i <size; ++i)
	{
		mX.push_back(x[i]);
		mY.push_back(y[i]);
	}
	differentialQuotient();
}

double NewtonInterpolation::compute(double x)
{
	double temp = 0.0;
	for (size_t i = 0; i <= mNodes; ++i)
	{
		temp += (mAi[i]*factorPolynomialial(i, x));
	}
	
	return temp;
}

double absoluteError(double fx, double Lx)
{
	return abs(fx-Lx);
}
