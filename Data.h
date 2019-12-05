//
// Created by stein on 12/4/2019.
//

#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H


using namespace std;
#include <string>
#include <fstream>
#include <iostream>


class Data{
public:
    Data();
    Data(string region, string type, int id, int units, int profit);
    friend bool operator<=(const Data& nm, const Data& dt);
    friend bool operator<(const Data& nm, const Data& dt);
    friend bool operator>(const Data& nm, const Data& dt);
    friend ostream& operator<<(ostream& os, const Data data);

    string country;
    string itemType;
    int orderId;
    int unitSold;
    int totalProfit;
};

#endif //PROJECT9_DATA_H
