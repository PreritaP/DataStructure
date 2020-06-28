#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int countAllPath(int dr, int dc){
    int dp[dr+1][dc+1];
    for(int r=dr; r>=0; r--){
        for(int c=dc; c>=0; c--){
            if(r == dr && c == dc)
                dp[r][c] = 1;
            else if(r == dr)
                dp[r][c] = dp[r][c+1];
            else if(c == dc)
                dp[r][c] = dp[r+1][c];
            else
                dp[r][c] = dp[r+1][c] + dp[r][c+1];
        }
    }
    return dp[0][0];
}

int min(int a, int b){
    if(a<b)
        return a;
    return b;
}

void minCostPath(int cost[3][3]){
    int dr = 2;
    int dc = 2;
    int minCost[dr+1][dc+1];
    string path[dr+1][dc+1];
    for(int r=dr; r>=0; r--){
        for(int c=dc; c>=0; c--){
            if(r == dr && c == dc){
                minCost[r][c] = cost[r][c];
                path[r][c] = "%";
            }
            else if(r == dr){
                minCost[r][c] = cost[r][c] + minCost[r][c+1];
                path[r][c] = "H" + path[r][c+1];                
            }
            else if(c == dc){
                minCost[r][c] = cost[r][c] + minCost[r+1][c];
                path[r][c] = "V" + path[r+1][c];                
            }
            else{
                minCost[r][c] = cost[r][c] + min(minCost[r+1][c], minCost[r][c+1]);
                if(minCost[r+1][c] < minCost[r][c+1])
                    path[r][c] = "V" + path[r+1][c];
                else
                    path[r][c] = "H" + path[r][c+1];
            }
        }
    }
    
    cout<<"Minimun Cost : "<<minCost[0][0];
    cout<<"\nMinimun Cost Path : "<<path[0][0];
}

int minSteps(int source, int step, int dest){
    if(abs(source) > dest)   return INT_MAX;
    if(source == dest) return step;
    
    int pos = minSteps(source + step + 1, step + 1, dest); 
    int neg = minSteps(source - step - 1, step + 1, dest);
    
    return (pos < neg) ? pos : neg;
}

void countPalindromeSubstrings(string str){
    int pal[str.length()][str.length()] = {0};
    int count = 0;
    int maxLength = 0;
    for(int d = 0; d < str.length(); d++){
        int si = 0;
        int ei = d;
        while(ei < str.length()){
            if(d == 0) {
                pal[si][ei] = 1;
                maxLength = 1;                
            }
            else if (d == 1){
                if(str[si] == str[ei]) {
                    pal[si][ei] = 1;
                    maxLength = 2;
                } else
                    pal[si][ei] = 0;
            } else {
                if(str[si] == str[ei] && pal[si+1][ei-1] == 1) {
                    pal[si][ei] = 1;
                    if(ei-si+1 > maxLength)
                        maxLength = ei-si+1;
                }
                else
                    pal[si][ei] = 0;
            }
            
            if(pal[si][ei] == 1)
                count++;
            si++;
            ei++;
        }
    }
    cout<<"\nMax Length palindrome : "<<maxLength;
    cout<<"\nCount of all palindromic substrings : "<<count;
}

void longestIncreasingSequence(int a[], int n){
    int lis[n];
    vector<int> plis[n];
    int cmax = 0;
    int maxindex ;
    int sol[n];
    
    for(int i=0 ; i<n; i++) {
        lis[i]=1;
        sol[i]=i;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i-1; j++){
            if(a[j] < a[i] && lis[i] <= lis[j]){
                lis[i] = lis[j]+1;
                sol[i] = j;
            }
            if(lis[i] > cmax){
                cmax = lis[i];
                maxindex = i;
            }
        }
    }
    cout<<cmax<<endl;
    int j = maxindex;
    int i = maxindex;
    do{
        i = j;
        cout<<a[i] <<" ";
        j = sol[i];
    }while (j != i);

}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int lcs(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int lcs[m+1][n+1] = {0};
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0)
                lcs[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++)
    //         cout<<lcs[i][j]<<" ";
    //     cout<<endl;
    // }
    return lcs[m][n];
}

int main() {
    
	/* DYNAMIC PROGRAMMING */
	cout<<"\nCount all paths from top left to bottom right in m X n matrix : "<<countAllPath(2,2);
	
	int cost[3][3] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };
	cout<<"\nMinimum Cost Path from top left to bottom right in m X n matrix : ";
	minCostPath(cost);
	
	cout<<"\nMinimum steps to reach the destination : "<<minSteps(0,0,11);
	
	string s = "forgeeksskeegfor";
	cout<<"\nCount all the palindromic substrings : ";
	countPalindromeSubstrings(s);
	
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	cout<<"\nLongest increasing subsequence : ";
	longestIncreasingSequence(arr,8);

    string s1 = "AGGTAB"; 
    string s2 = "GXTXAYB";
    cout<<"\nLongest Common subsequence : "<<lcs(s1, s2);
	return 0;
}