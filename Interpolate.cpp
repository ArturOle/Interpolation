#include <vector>
#include <utility>
#include <iostream>


unsigned int factorial( unsigned int n );
double non_general_newton_symbol( double n, int k );


class Interpolation
{
	int degree;
	double h;
	double x0;
	std::vector<std::pair<double, double>> xy;
	std::vector<std::vector<double>> ops;

public:

	Interpolation(std::vector<std::pair<double, double>> xy_in)
	{
		this->xy = xy_in;
		this->x0 = xy[0].first;
		this->degree = xy.size();
    	this->h = std::abs(xy[0].first - xy[1].first);
		this->ops = this->operators();
	}


	std::vector<std::vector<double>> operators()
	{
		std::vector<std::vector<double>> op (this->degree, std::vector<double>( this->degree, 0 ));

		for( int i = 0; i < this->degree; i++ ) 
		{
			op[0][i] = xy[i].second;
		}

		for( int i = 1; i < this->degree; i++ ) 
		{
			for( int j = 0; j < this->degree - i; j++ ) 
			{
				op[i][j] = op[i-1][j] - op[i-1][j+1];
			}
		}

		std::clog << "Difference operators:" << std::endl;
		
		for( int i = 0; i < this->degree; i++ ) 
		{
			for( int j = 0; j < this->degree - i; j++ ) 
			{
				std::clog << op[j][i] << "\t"; 
			}
			std::clog << std::endl;
		}
		return op;
	} 


	double value_in_x(double x) 
	{
		/// Calculating the value of interpolated function at given x.
		///
		/// op - Difference operators of our function
		/// x  - argument of the dunction for which we are calcualting the value
		/// x0 - first known value
		///
		/// Returns approximate value f(x)

		double sum = 0.0;
		double t = (x - this->x0) / h;

		for( int i = 0; i < this->ops.size(); i++ ) 
		{
			sum += non_general_newton_symbol(t, i) * ops[i][0];
		}

		return sum;
	}
};



// double value_in_x(
// 	std::vector<std::vector<double>> &op,
// 	double x, double x0, double h
// );

// std::vector<std::vector<double>> operators(
// 	std::vector<std::pair<double, double>> &xy,
// 	int n
// );

// std::vector<double> generate_polynomial(
// 	std::vector<std::pair<double, double>> &xy,
// 	std::vector<std::vector<double>> &operators,
// 	int n, double h
// );

unsigned int factorial( unsigned int n ) 
{
    /// Recursive implementation of factorial
    /// n - degree of factorial
    /// Returns current n * function of n-1

	if( n == 0 )
		return 1;
	return( n * factorial( n-1 ));
}

double non_general_newton_symbol( double n, int k ) 
{
    /// Calculating the value of Newton symbol of n choose k and
    /// adding plus one to every iteration to obtain the equation 
    ///
    /// n - quantity of possible choices
    /// k - how many times are we choosing one from n
    ///
    /// Returns - gow many possible choices there are for choosing k from n

	double o = 1;

	for( int i = 0; i < k; i++ ) 
    {
		o = o * (n + i);
	}

	return( o / factorial( k ));
}

// double interpolation(std::vector<std::pair<double, double>> xy, double x)
// {
//     /// Implementation of Newton interpolation with backward operator 
//     ///
//     /// xy - collection of points with parameters x and y as a pairs
//     /// x  - argument of the dunction for which we are calcualting the value
//     ///
//     /// Returns the result for given agument

//     int n = xy.size();
//     double h = std::abs(xy[0].first - xy[1].first);
//     std::vector<std::vector<double>> op = operators(xy, n); // variable can't have the same name as method
//     double x0 = xy[0].first;
// 	double result = value_in_x( op, x, x0, h );
//     std::clog << "Value in x = " << x << ":\n" << result << "\n";

//     return result;
// }

// std::vector<std::vector<double>> operators(std::vector<std::pair<double, double>> &xy, int n) 
// {
//     /// Generating the table of difference table
//     ///
//     /// xy - collection of points with parameters x and y
//     /// n  - size of xy container
//     ///
//     /// Return the table of operators

// 	std::vector<std::vector<double>> op (n, std::vector<double>( n, 0 ));

// 	for( int i = 0; i < n; i++ ) 
//     {
// 		op[0][i] = xy[i].second;
// 	}

// 	for( int i = 1; i < n; i++ ) 
//     {
// 		for( int j = 0; j < n - i; j++ ) 
//         {
// 			op[i][j] = op[i-1][j] - op[i-1][j+1];
// 		}
// 	}

// 	std::clog << "Difference operators:" << std::endl;
	
//     for( int i = 0; i < n; i++ ) 
//     {
// 		for( int j = 0; j < n - i; j++ ) 
//         {
// 			std::clog << op[j][i] << "\t"; 
// 		}
// 		std::clog << std::endl;
// 	}
// 	return op;
// }

// double value_in_x(
// 	std::vector<std::vector<double>> &op,
// 	double x, double x0, double h
// ) 
// {
// 	/// Calculating the value of interpolated function at given x.
// 	///
// 	/// op - Difference operators of our function
// 	/// x  - argument of the dunction for which we are calcualting the value
// 	/// x0 - 
// 	///

// 	double sum = 0.0;
// 	double t = (x - x0) / h;

// 	for( int i = 0; i < op.size(); i++ ) 
//     {
// 		sum += non_general_newton_symbol(t, i) * op[i][0];
// 	}

// 	return sum;
// }
