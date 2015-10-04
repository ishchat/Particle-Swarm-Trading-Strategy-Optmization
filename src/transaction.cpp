#include <iostream>
#include "transaction.h"
#include "signal.h"

extern double Capital ;
extern double holding_capital;
extern std::string State;

double transaction(std::vector <double> _close, double _T1, double _T2, double _T3, double _T4, double _T5, double _T6, double _T7, double _T8)
{
const double transaction_cost = 0;
double Vol_of_holding_stock;
//double Capital = 100000;
//double holding_capital = Capital;
//std::string State = "holding capital";
//std::cout<<"Capital: "<<Capital;
//std::cout<<"holding_capital: "<<holding_capital;
//std::cout<<"State: "<<State;

for(int _k=0; _k < _close.size(); _k++)
{
std::string _signal = signal(_close, _k, _T1, _T2, _T3, _T4, _T5, _T6, _T7, _T8);
//std::cout<<"_signal :"<<_signal<<"\n";
if ((State == "holding capital") and (_signal == "buy"))
{
Vol_of_holding_stock = Capital/(_close[_k]*(1+transaction_cost));
State = "holding stock";
}
else if ((State == "holding stock") and (_signal == "sell"))
{
holding_capital = (_close[_k]*Vol_of_holding_stock)-transaction_cost;
State = "holding capital";
}
}
if ((State == "holding stock"))
{
holding_capital = (_close[_close.size()-1]*Vol_of_holding_stock)-transaction_cost;
}
Capital = holding_capital;
return Capital;
}
