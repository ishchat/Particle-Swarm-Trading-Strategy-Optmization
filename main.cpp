#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <boost/tokenizer.hpp>
#include <cmath>
#include <string>
#include "SMA.h"
#include "MMPSO.h"

//http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

double Global_best_fitness=0;
double Global_best_position[8];

double Capital = 100000;
double holding_capital = Capital;
std::string State = "holding capital";

int main()
{
    using namespace std;
    using namespace boost;
    string data("/home/ishan/Downloads/table.csv");

    ifstream in(data.c_str());
    if (!in.is_open()) return 1;

    typedef tokenizer< escaped_list_separator<char> > Tokenizer;
    vector< string > vec;
    vector <double > close;
    string line;
    std::string::size_type sz;

    getline(in,line);//so that header line is not read into while loop read it beforehand

    while (getline(in,line))
    {
        Tokenizer tok(line);
        vec.assign(tok.begin(),tok.end());
        cout<<vec[6]<<endl;
        close.push_back(std::stod(vec[6], &sz));

        // vector now contains strings from one row, output to cout here
        //copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "|"));

       // cout << "\n----------------------" << endl;
    }
    //std::vector <double> vec1(10,100);

    //double sma=SMA(vec1, 3, 4);

    //cout<<"sma: "<<sma<<endl;

    MMPSO(close);

    //cout<<"nan()<nan(): "<<(nan("1")<nan("2"))<<endl;

    //SMA(vec1,3);
    /*
    for (std::vector<double>::iterator it = sma.begin(); it != sma.end(); ++it)
    std::cout << ' ' << *it;
    */
/*
int _lookback=3;
for (std::size_t i=0; i < _lookback; i++)
{
//http://en.cppreference.com/w/cpp/numeric/math/NAN
//http://en.cppreference.com/w/cpp/numeric/math/isnan
//http://pubs.opengroup.org/onlinepubs/009695399/basedefs/math.h.html
//http://linux.die.net/man/3/nan
sma.push_back(nan("1"));nan("1");*/
//std::cout<<sma[i];
//}

}
