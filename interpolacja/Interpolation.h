#pragma once
#include <vector>
class Interpolation
{
public:
	Interpolation();
	~Interpolation();
	std::vector<double> mX;
	std::vector<double> mY;
	std::vector<double> mLx;
	void setNodes(int n);
	
	double newton(double x);
private:
	int nodes;
	

	double factorPolynomialial(int degree, double x);//wi
	double differentialQuotient(int n);//an
};

