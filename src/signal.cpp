#include "signal.h"
#include "SMA.h"

std::string signal(std::vector <double> _close, int _k, double _T1, double _T2, double _T3, double _T4, double _T5, double _T6, double _T7, double _T8)
{
if ((SMA(_close, _k, _T1) > SMA(_close, _k, _T2)) and (SMA(_close, _k, _T3) > SMA(_close, _k, _T4))) return "buy";
else if ((SMA(_close, _k, _T5) < SMA(_close, _k, _T6)) and (SMA(_close, _k, _T7) < SMA(_close, _k, _T8))) return "sell";
else return "hold";
}
