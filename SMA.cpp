#include "SMA.h"
#include <cmath>
#include <iostream>


double SMA(std::vector<double> _close, int _k , int _lookback)
{
using namespace std;

//http://stackoverflow.com/questions/409348/iteration-over-vector-in-c

double sma;

//cout<<"Before nan"<<endl;

if (_k < (_lookback - 1)) return nan("1");

//cout<<"After nan"<<endl;

double sum=0;

//int i = _k;

//cout<<"i :"<<i<<endl;
//cout<<"(_k - _lookback) :"<<(_k - _lookback)<<endl;
//cout<<"i > (_k - _lookback)"<< (i >(_k - _lookback))<<endl;

for (int i = _k; i > (_k - _lookback) ; i--)
{
sum = sum+_close[i];
//cout<<"sum: "<<sum;
}

sma = sum/_lookback;

return sma;
}
