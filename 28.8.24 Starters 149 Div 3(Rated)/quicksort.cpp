#include<bits/stdc++.h>
using namespace std;



int main(){
    int arr[9] = {4, 5, 2, 3, 1, -4, 7, 9, 3};  
    quicksort(arr, 9);
    cout <<"Sorted array : ";
    for(int i = 0; i < 9; i++) cout << arr[i] << " ";
    return 0;
}
