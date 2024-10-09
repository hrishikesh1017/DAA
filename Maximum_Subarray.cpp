#include<iostream>
using namespace std;

int maxSubArraySum(int a[], int size){
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i=0;i<size;i++){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main(){
    int arr[] = {1,-2,3,-4,-5,6,7,-8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Maximum Sum Is" << maxSubArraySum(arr,n);

    return 0;
}