#pragma once
#include <vector>
#include "mathUtils.h"
#include <algorithm>

const double PI = 3.141592653589793238463;


void parallelNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x);
void czebyszewNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x);

///blad bezwzgledny
double absoluteError(double fx, double Lx);

class NewtonInterpolation
{
public:
	NewtonInterpolation(const std::vector<double>& x,const std::vector<double>& y);
	NewtonInterpolation(const double* x, const double* y, size_t n);
	~NewtonInterpolation();

	void setArrays(const std::vector<double>& x, const std::vector<double>& y);
	void setArrays(const double* x, const double* y, size_t n);
	double compute(double x);
private:
	std::vector<double> mX;
	std::vector<double> mY;
	std::vector<double> mAi;
	size_t mNodes;
	///wielomian czynnikowy wi
	///stopnia deegre
	double factorPolynomialial(size_t degree, double x);
	///iloraz roznicowy ai
	///rzedu n
	double differentialQuotient(size_t  n);
	///tworzy wektor ilorazow
	void differentialQuotient();

};

