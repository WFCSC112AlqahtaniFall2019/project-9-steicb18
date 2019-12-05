//
// Created by stein on 12/4/2019.
//

#include "Data.h"
#include <ostream>
using namespace std;

//Default constructor
Data::Data() {
    totalProfit = 0;
    unitSold = 0;
    orderId = 0;
    itemType = " ";
    country = " ";
}

Data::Data(string region, string type, int id, int units, int profit) {
    country = region;
    itemType = type;
    orderId = id;
    unitSold = units;
    totalProfit = profit;
}

ostream& operator<<(ostream& os, const Data data){
    os<<data.country<<","<<data.itemType<<","<<data.orderId<<","<<data.unitSold<<","<<data.totalProfit<<endl;
    return os;
}

bool operator<=(const Data& nm, const Data& dt){
    return nm.totalProfit>dt.totalProfit;
}
bool operator<(const Data& nm, const Data& dt){
    return nm.totalProfit<dt.totalProfit;
}
bool operator>(const Data& nm, const Data& dt){
    return nm.totalProfit>dt.totalProfit;
}
