#include <vector>
#include <utility>
#include <iostream>


std::vector<std::vector<double>> operators(
	std::vector<std::pair<double, double>> &xy,
	int n
);

std::vector<double> generate_polynomial(
	std::vector<std::pair<double, double>> &xy,
	std::vector<std::vector<double>> &operators,
	int n, double h
);

std::vector<double> interpolation(
	std::vector<std::pair<double, double>> xy
) {
    int n = xy.size();
    double h = std::abs(xy[0].first - xy[1].first);
    std::vector<std::vector<double>> op = operators(xy, n); // variable can't have the same name as method
    std::vector<double> polynomial = generate_polynomial(xy, op, n, h);
    std::cout << "The degree of the polynomial: " << n << std::endl;
    return polynomial;
}


std::vector<std::vector<double>> operators(
	std::vector<std::pair<double, double>> &xy,
	int n
) {
	std::vector<std::vector<double>>
		op(xy.size(), std::vector<double>( xy.size(), 0 ));

	for( int i = 0; i < xy.size(); i++ ) {
		op[0][i] = xy[i].second;
	}

	for( int i = 1; i < xy.size(); i++ ) {
		for( int j = 0; j < xy.size() - i; j++ ) {
			op[i][j] = op[i-1][j] - op[i-1][j+1];
		}
	}

	std::clog << "Difference operators:" << std::endl;
	for( int i = 0; i < xy.size(); i++ ) {
		for( int j = 0; j < xy.size() - i; j++ ) {
			std::clog << op[j][i] << "\t"; 
		}
		std::clog << std::endl;
	}
	return op;

    // std::vector<double> operators;
    // operators.push_back(xy[0].second - xy[1].second);

    // 
    // std::cout << "The beckward operators for polynomial generator:\n" << operators[0] << std::endl;
    // for (int i = 1; i < xy.size()-1; i++)
    // {   
    //     operators.push_back(operators[i-1] - (xy[i+1].second - xy[i].second));
    //     std::cout << operators[i] << std::endl;
    // }

    // return operators;
}


std::vector<double> generate_polynomial(
	std::vector<std::pair<double, double>> &xy,
	std::vector<std::vector<double>> &operators,
	int n, double h
) {
    /// The function responsible for generating the Newton polynomial  
    ///
    std::vector<double> polynomial;
    double factorial = 1;
    double inverse_h = 1/h;
    double attribute = xy[0].first;

    polynomial.push_back(xy[0].second);
    std::cout << "polynomial coefficients:" << std::endl;
    std::cout << polynomial[0] << std::endl;

    for (int i = 1; i < n; i++)
    {
        polynomial.push_back((1/factorial)* inverse_h * operators[i-1][0]);
        inverse_h = inverse_h * inverse_h;
        factorial = factorial * i;
        std::cout << polynomial[i] << std::endl;
    }

    std::cout << "" << std::endl;
    return std::vector<double>();
}
