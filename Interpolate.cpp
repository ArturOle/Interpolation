#include <vector>
#include <utility>
#include <iostream>


std::vector<double> backward_operators(std::vector<std::pair<double, double>> &xy, int n);
std::vector<double> generate_polynominal(std::vector<std::pair<double, double>> &xy, std::vector<double> &operators ,int n, double h);

std::vector<double> interpolation(std::vector<std::pair<double, double>> xy)
{
    int n = xy.size();
    double h = std::abs(xy[0].first - xy[1].first);
    std::vector<double> operators = backward_operators(xy, n);
    std::vector<double> polynominal = generate_polynominal(xy, operators, n, h);
    std::cout << "The degree of the polynominal: " << n << std::endl;
    return operators;
}


std::vector<double> backward_operators(std::vector<std::pair<double, double>> &xy, int n)
{
    std::vector<double> operators;
    operators.push_back(xy[0].second - xy[1].second);

    
    std::cout << "The beckward operators for polynominal generator:\n" << operators[0] << std::endl;
    for (int i = 1; i < xy.size()-1; i++)
    {   
        operators.push_back(operators[i-1] - (xy[i+1].second - xy[i].second));
        std::cout << operators[i] << std::endl;
    }

    return operators;
}


std::vector<double> generate_polynominal(std::vector<std::pair<double, double>> &xy, std::vector<double> &operators ,int n, double h)
{
    /// The function responsible for generating the Newton polynominal  
    ///
    ///
    ///
    std::vector<double> polynominal;
    double factorial = 1;
    double inverse_h = 1/h;
    double attribute = xy[0].first;

    polynominal.push_back(xy[0].second);
    std::cout << "Polynominal coefficients:" << std::endl;
    std::cout << polynominal[0] << std::endl;

    for (int i = 1; i < n; i++)
    {
        polynominal.push_back((1/factorial)* inverse_h * operators[i-1]);
        inverse_h = inverse_h * inverse_h;
        factorial = factorial * i;
        std::cout << polynominal[i] << std::endl;
    }

    std::cout << "" << std::endl;
}