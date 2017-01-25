#include "MathUtils.h"

int factorial(int n)
{
	int tempFactorial = 1;
	for (int i = n; i > 1; --i)
		tempFactorial *= i;
	return tempFactorial;
}

double newtonSymbol(int n, int k)
{
	if ((k > 0) && (k < n))
		return factorial(n) / (factorial(k)*factorial(n - k));
	else if ((k == 0) || (k == n))
		return 1;
	else
		//dobr¹ opcj¹ jest zrobienie tutaj wyj¹tku który po prostu przerwa³by program bez dalszych ceregieli
		//i w mainie ponad g³ówn¹ pêtl¹ zaj¹æ siê wszystkimi wyj¹tkami, dla dzielenia przez 0 na przyk³ad kod -1
		//tu jest te¿ zamieszczony wypadek kiedy n < k lub któreœ jest niedodatnie
		//throw -1 ;
		return -1;
}

void parallelNodes(int nodesAmount, double downRange, double upRange, std::vector<double>& x)
{
	x.clear();
	double h = (upRange - downRange) / nodesAmount;
	for (unsigned i = 0; i <= nodesAmount; ++i)
	{
		x.push_back(downRange + i*h);
	}
}

void czebyszewNodes(int nodesAmount, double downRange, double upRange, std::vector<double>& x)
{
}
