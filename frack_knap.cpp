#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>

using namespace std;

bool compare(vector<int>&a, vector<int>&b){
    double ratio1 = (double)a[0]/a[1];
    double ratio2 = (double)b[0]/b[1];
    return ratio1>ratio2;
}

double frac_sack(int capacity, vector<vector<int>>& items){
    sort(items.begin(), items.end(), compare);
    double total = 0.0;
    for(auto item: items){
        if(capacity<=0){
            break;
        }
    if (item[1] <= capacity){
        total+=item[0];
        capacity-=item[1];
    }
    else{
        total+=item[0]*((double)capacity/item[1]);
        capacity = 0;
    }
    }
    return total;
}

int main() {
    int capacity = 50; // Maximum weight capacity of the knapsack
    vector<vector<int>> items = {
        {60, 10},  // Item 1: Value 60, Weight 10
        {100, 20}, // Item 2: Value 100, Weight 20
        {120, 30}  // Item 3: Value 120, Weight 30
    };

    double maxValue = frac_sack(capacity, items);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}