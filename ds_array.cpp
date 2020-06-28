#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int first = 0;
    int last = n-1;
    int mid;
    while(first<=last){
        mid = (first+last)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key)
            last = mid-1;
        else
            first = mid+1;
    }
    return -1;
}

int sortedBinarySearch(int arr[], int n, int key){
    int first = 0;
    int last = n-1;
    int mid;
    while(first<=last) {
        mid = (first+last)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] > key){
            if(arr[first] > key)
                first = mid + 1;
            else
                last = mid - 1;
        } else {
            if(arr[last] > key)
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1;
}

void pairWithGivenProduct(int arr[], int n, int prod) {
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        if(prod % arr[i] == 0){
            if(s.find(prod/arr[i]) != s.end()) {
                cout<<arr[i]<<" "<<prod/arr[i]<<endl;
                return;
            } else 
                s.insert(arr[i]);
        }    
    }
    cout<<"No pair with product "<<prod<<" exists."<<endl;
    return;
}

void pairWithGivenSum(int arr[], int n, int sum){
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        if(s.find(sum-arr[i]) != s.end()) {
            cout<<arr[i]<<" "<<sum-arr[i]<<endl;
            return;
        }
        s.insert(arr[i]);
    }
    cout<<"No pair with sum = "<<sum<<" exists."<<endl;
    return;
}

void nearestSmallestNumber(int arr[], int n){
    //Method1 O(n^2)
    cout<<"_ ";
    for(int i=1; i<n; i++) {
        int j;
        for(j=i-1; j>=0; j--){
            if(arr[j] < arr[i]) {
                cout<<arr[j]<<" ";
                break;
            }
        }
        if(j==-1)
            cout<<"_ ";
    }
    //Method2 O(n)
    // stack<int> s;
    // for(int i=0; i<n; i++){
        
    //     while(!s.empty() && s.top() >= arr[i])
    //         s.pop();
        
    //     if(s.empty())
    //         cout<<"_ ";
    //     else
    //         cout<<s.top()<<" ";
    //     s.push(arr[i]);
    // }
}

int countTriplet(int arr[], int n, int sum){
    int count = 0;
    //Method1 O(n^3)
    // for(int i=0; i<n-2; i++){
    //     for(int j=i+1; j<n-1; j++){
    //         for(int k=j+1; k<n; k++){
    //             if(arr[i]+arr[j]+arr[k] < sum) {
    //                 cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
    //                 count++;
    //             }
    //         }
    //     }
    // }
    
    //Method2 O(n^2)
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        int j = i+1, k = n-1;
        
        while(j<k){
            if(arr[i]+arr[j]+arr[k] >= sum)
                k--;
            else{
                count += (k-j);
                j++;
            }
        }
    }
    
    return count;
}

int kthSmallLarge(int arr[], int n, int k){
    //Method1 O(nlogn)
    sort(arr,arr+n);
    return arr[n-k];
}

int max(int a, int b){
    return (a>b) ? a : b;
}

int findMaxSum(int arr[], int n){
    int incl = arr[0];
    int excl = 0;
    int excl_new = 0;
    for(int i=1; i<n; i++){
        excl_new = max(incl,excl);
        incl = excl + arr[i];
        excl = excl_new;
    }
    return max(incl, excl);
}

void swap(char *a, char *b) { 
    char temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void findNext(char arr[], int n){
    int i;
    for(i=n-1; i>=0; i--){
        if(arr[i] > arr[i-1])
            break;
    }
    if(i == 0){
        cout<<"Not possible";
        return;
    }
    int x = arr[i-1], smallest = i;
    for(int j=i+1; j<n; j++){
        if(arr[j]>x && arr[j]<smallest)
            j=smallest;
    }
    swap(&arr[smallest], &arr[i-1]);
    sort(arr+1, arr+n);
    cout<<arr;
}

int main() {

    /* Binary search in sorted array */
    int n = 10;
    int arr[] = {1, 2, 3, 6, 8, 10, 11, 14, 15, 16};
    cout<<binarySearch(arr, n, 55)<<endl;
    	
    /* Binary search in rotated array */
    int arr[] = {10, 11, 14, 55, 89, 101, 1, 3, 6 ,8};
    cout<<sortedBinarySearch(arr, n, 55);

    /* Find a pair with given product */
    pairWithGivenProduct(arr, n, 60);

    /* Find a pair with given sum */
    pairWithGivenSum(arr, n, 100);

    /*  Nearest smallest number on left side in the array */    
    int arr[] = {1, 6, 4, 10, 2, 5};
    cout<<endl;
    nearestSmallestNumber(arr,6);

    /* Count triplets with sum smaller than the given value */
    int arr[] = {-2, 0, 1, 3};
    int sum = 2;
    int n = 4;
    cout<<countTriplet(arr, n,sum);
    
    /* Kth Smallest and largest element */
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout<<kthSmallLarge(arr,n,k);

    /* Max sum in arr[] such that no two elements are adjacent */    
    int arr[] = {5,  5, 10, 40, 50, 35};
    int n = 6; 
    cout<<findMaxSum(arr,n);
    
    /* Next greater number from a set of digits */
    char digits[] = "534976"; 
    int n = strlen(digits);
    findNext(digits, n); 
	return 0;
}