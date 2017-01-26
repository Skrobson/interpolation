#include "MathUtils.h"

void parallelNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x)
{
	x.clear();
	double h = (upRange - downRange) / nodesAmount;
	for (size_t i = 0; i <= nodesAmount; ++i)
	{
		x.push_back(downRange + i*h);
	}
}

void czebyszewNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x)
{
	x.clear();
	double temp = 0.0;
	double tmp = 0.0;
	for (size_t i = 0; i <= nodesAmount; ++i)
	{
		tmp = (2 * (double)i + 1);
		tmp /= (2 * nodesAmount + 2);
		tmp *= PI;
		tmp = cos(tmp);
		temp = (upRange - downRange) / 2;
		temp*= cos(((2 *(double) i + 1) / (2 * nodesAmount + 2))*PI);
		//temp *= tmp;
		temp += (downRange + upRange) / 2;
		x.push_back(temp);
	}
}
