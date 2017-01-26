#pragma once
#pragma once
#include <vector>
#include <cmath>


const double PI = 3.141592653589793238463;


void parallelNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x);
void czebyszewNodes(size_t nodesAmount, double downRange, double upRange, std::vector<double>& x);

