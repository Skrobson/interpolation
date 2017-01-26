#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "mathUtils.h"
#include "Interpolation.h"

void reportMini(std::ostream& output, const std::vector<double>& x, const std::vector<double>& y);

void report(std::ostream& output,  const std::vector<double>&  x, const std::vector<double>& y,const std::vector<double>& Lx,const std::vector<double>& error);

int main()
{
	//zadana funkcja
	auto fx = [](double x) {return abs(cos(x)*x); };

	int downRange=-3, upRange=3;
	size_t n = 7;
	size_t np = 150;
	std::vector<double> x;
	std::vector<double> y;
	std::vector<double> Ly;
	std::vector<double> error;//nazwa robocza
	std::stringstream sstream;

	
	std::cout << "Podaj dolny zakres:";
	std::cin >> downRange;
	std::cout << "Podaj gorny zakres:";
	std::cin >> upRange;
	std::cout << "Podaj liczbe wezlow:";
	std::cin >> n;
	sstream << "(" << downRange << "'" << upRange << ")n" << n << ".txt";
	std::string fileName = sstream.str();
	std::cout << fileName<<"\n";
	//std::cout << "Podaj nazwe pliku dla raportu :";
	//std::cin >> fileName;

	//obliczanie wezlow rownoleglych
	parallelNodes(n, downRange, upRange, x);	
	for (auto obj : x) {
		y.push_back(fx(obj));
	}
	NewtonInterpolation I(x, y);

	std::fstream raportFile(fileName, std::fstream::out);
	if (raportFile.is_open())
	{
		raportFile << "Wielomian interpolacyjny Newtona w punktach le¿¹cych w przedziale <" << downRange << "," << upRange<<">\n";
		raportFile << "dla funkcji f(x)=|cos(x)*x|\n";
		raportFile << "Wezly rownolegle n=" << n<<"\n";
		raportFile << "Wartosci w wezlach:\n";
		reportMini(raportFile, x, y);
	}
	reportMini(std::cout, x, y);

	//obliczanie wartosci funkcji interpolowanej i interpolujacej w rownoleglych wezlach
	parallelNodes(np, downRange, upRange, x);
	Ly.clear();
	y.clear();
	error.clear();
	for (auto obj : x) {
		Ly.push_back(I.compute(obj));
		y.push_back(fx(obj));
		error.push_back(absoluteError(y.back(), Ly.back()));
	}
	if(raportFile.is_open())
		report(raportFile, x, y, Ly, error);
	//report(std::cout, x, y, Ly, error);




	czebyszewNodes(n, downRange, upRange, x);
	y.clear();
	for (auto obj : x) {
		y.push_back(fx(obj));
	}
	I.setArrays(x, y);

	if (raportFile.is_open())
	{
		raportFile << "\nWezly optymalne n=" << n << "\n";
		raportFile << "Wartosci w wezlach:\n";
		reportMini(raportFile, x, y);
	}
	reportMini(std::cout, x, y);

	//obliczanie wartosci funkcji interpolowanej i interpolujacej w optymalnych wezlach
	parallelNodes(np, downRange, upRange, x);
	Ly.clear();
	y.clear();
	error.clear();
	for (auto obj : x) {
		Ly.push_back(I.compute(obj));
		y.push_back(fx(obj));
		error.push_back(absoluteError(y.back(), Ly.back()));
	}
	if (raportFile.is_open())
		report(raportFile, x, y, Ly, error);
	//report(std::cout, x, y, Ly, error);



	raportFile.close();
	std::cout << "\nWcisnij dowolny klawisz..";
	_getch();
	return 0;
}

void reportMini(std::ostream & output, const std::vector<double>& x, const std::vector<double>& y)
{
	size_t n = x.size();

	for (size_t i = 0; i < n; ++i)
	{

		output << "x" << i << ": " << std::left << std::setw(20) << x[i];//<<std::scientific
		output << "y" << i << ": " << y[i] << "\n";// << std::scientific
	}
}

void report(std::ostream & output, const std::vector<double>& x, const std::vector<double>& y, const std::vector<double>& Lx, const std::vector<double>& error)
{
	size_t n = x.size();
	output << "\nWartosci w " << n-1 << " wezlach\n";
	output<< std::left << std::setw(6) << "i" ;
	output<< std::left << std::setw(8 )<< "x" ; 
	output<< std::left << std::setw(20) << "f(x)"  ;
	output<< std::left << std::setw(20) << "L(x)"  ;
	output << "error\n";
	for (size_t i = 0; i < n; ++i)
	{
		output<< std::left << std::setw(6) << i;
		output<< std::left << std::setw(8) << x[i];//<<std::scientific
		output<< std::left << std::setw(20) << y[i] ;// << std::scientific
		output<< std::left << std::setw(20) << Lx[i] ;
		output<< std::left << std::setw(20) << error[i]<<"\n";
	}
}
