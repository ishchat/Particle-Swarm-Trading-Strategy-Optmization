#include "SMA.h"
#include <cmath>
#include <iostream>

using namespace std;

std::vector<double> SMA(std::vector<double> _close, int _lookback)
//void SMA(std::vector<double> _close, int _lookback)
{
//http://stackoverflow.com/questions/409348/iteration-over-vector-in-c

std::vector <double> sma;

for (std::size_t i=0; i < _lookback-1; i++)
{
//http://en.cppreference.com/w/cpp/numeric/math/NAN
//http://en.cppreference.com/w/cpp/numeric/math/isnan
//http://pubs.opengroup.org/onlinepubs/009695399/basedefs/math.h.html
//http://linux.die.net/man/3/nan
sma.push_back(nan("1"));
//std::cout<<sma[i]<<endl;
}

for (std::size_t i=_lookback-1; i < _close.size(); i++)
{
double sum=0;
for (std::size_t j=i-_lookback+1; j < i; j++)
{
sum=sum+_close[j];
}
sma.push_back(sum/_lookback);
//std::cout<<sma[i]<<endl;
}
return sma;
}
