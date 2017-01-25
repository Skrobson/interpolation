#pragma once
#pragma once
#include <vector>

const double PI = 3.141592653589793238463;

int factorial(int n);

double newtonSymbol(int n, int k);

void parallelNodes(int nodesAmount, double downRange, double upRange, std::vector<double>& x);
void czebyszewNodes(int nodesAmount, double downRange, double upRange, std::vector<double>& x);

template<typename function>
void czebyszew(int nodesAmount, double downRange, double upRange, std::vector<double>& x, std::vector<double>& y, function f)
{
	double temp = 0.0;
	for (int i = 0; i <= nodesAmount; ++i)
	{
		temp = (upRange - downRange) / 2;
		temp *= cos((2 * i + 1) / (2 * nodesAmount + 2)*PI);
		temp += (downRange + upRange) / 2;
		x.push_back(temp);
		y.push_back(f(temp));
	}
}
