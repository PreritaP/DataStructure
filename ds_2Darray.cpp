#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 3

void rotateMatrix(int arr[][n]){
    for(int i=0; i< n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][n-1-i];
            arr[j][n-1-i] = arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j] = arr[n-1-i][i];
            arr[n-1-j][i] = temp;
        }
    }
}

void printMatrix(int arr[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main() {

    /* Inplace rotation of square matrix by 90 degree */
	int arr[n][n] = {
            	    {1, 2, 3},
            	    {4, 5, 6},
            	    {7, 8, 9}
            	  };
    rotateMatrix(arr);
    printMatrix(arr);
	return 0;
}