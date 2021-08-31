#include <iostream>
#include <numeric>
#include <algorithm>

#include "functions.hpp"

using namespace std;


void multVector(vector<double> *a, double b)
{
    std::transform((*a).begin(), (*a).end(), (*a).begin(), [b](double i) -> double { return i * b; });
}

void addVector(vector<double> *a, vector<double> *b)
{
    transform((*a).cbegin(), (*a).cend(), (*b).cbegin(), (*a).begin(), plus<double>());
}

double randomFloat(double min, double max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}