#include<stdio.h>
#include <algorithm>
#include<iostream>

using namespace std;

struct Item{
    int value,weight;
    Item(int value, int weight)
        : value(value), weight(weight)
    {
    }
};

bool cmp(struct Item a, struct Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1>r2;
}

double FractionalKnapsack(struct Item arr[],int N, int size){
    sort(arr,arr+size,cmp);
    int currWeight = 0;
    double finalValue = 0.0;
    for(int i=0;i<size;i++){
        if (currWeight+arr[i].weight<N){
            currWeight+=arr[i].weight;
            finalValue+=arr[i].value;
        }
        else{   
            int remain = N-currWeight;
            finalValue+= arr[i].value* ((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;      
}

int main() 
{ 
    // Weight of knapsack 
    int N = 60; 
  
    // Given weights and values as a pairs 
    Item arr[] = { { 100, 10 }, 
                   { 280, 40 }, 
                   { 120, 20 }, 
                   { 120, 24 } }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    // Function Call 
    cout << "Maximum profit earned = "
         << FractionalKnapsack(arr, N, size); 
    return 0; 
}

