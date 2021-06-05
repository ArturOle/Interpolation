#include <iostream>
#include "Interpolate.cpp"

using namespace std;


int main( int argc, char** argv )
{
	std::vector<std::pair<double, double>> xy = {{9, -2}, {7, 1}, {5, -1}, {3, 4}, {1, 2}};
    Interpolation inter(xy); 
    double x = xy[0].first;
    double step = 0.1;

    std::clog << "\nValues x, y of the interpolation:" << std::endl;
    while(x >= xy[xy.size()-1].first) 
    {
        std::clog << x << ",\t" << inter.value_in_x(x) << std::endl;
        x -= step;
    }

	return 0;
}


