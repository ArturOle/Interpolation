#include <iostream>
#include "Interpolate.cpp"

using namespace std;


int main()
{

    //std::vector<std::pair<double, double>> x = {{9, -2}, {7, 1}, {5, -1}, {3, 4}, {1, 2}};
    std::vector<std::pair<double, double>> x = {{3, 0}, {2.5, 2}, {2, 4}, {1.5, 3}, {1, 1}};
    interpolation(x);



    // int i, j, n;

    // /* Input Section */
    // cout << "Enter number of data? " << endl;
    // cin >> n;

    // cout << "Enter data: " << endl;
    // for (i = 0; i < n; i++)
    // {
    //     cout << "x[" << i << "] = ";
    //     cin >> x[i];
    //     cout << "y[" << i << "] = ";
    //     cin >> y[i][0];
    // }

    // /* Generating Backward Difference Table */
    // for (i = 1; i < n; i++)
    // {
    //     for (j = n - 1; j > i - 1; j--)
    //     {
    //         y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    //     }
    // }

    // /* Displaying Backward Difference Table */
    // cout << endl
    //      << "BACKWARD DIFFERENCE TABLE" << endl;

    // for (i = 0; i < n; i++)
    // {
    //     cout << x[i];
    //     for (j = 0; j <= i; j++)
    //     {
    //         cout << "\t" << y[i][j];
    //     }
    //     cout << endl;
    // }

    return 0;
}


