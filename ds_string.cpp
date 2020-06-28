#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(string s, int n, int m){
    char temp;
    while(n<m){
        temp = s[n];
        s[n] = s[m];
        s[m] = temp;
        n++;
        m--;
    }
}

int isRotated(string s1, string s2){
    if(s1.length() != s2.length()) 
        return 0;
    // reverse using inbuilt function 
    // reverse(s1.begin(), s1.begin()+2);
    // reverse(s1.begin()+2, s1.end());
    // reverse(s1.begin(), s1.end());
    
    //reverse using own function
    reverse(s1, 0, 1);
    reverse(s1, 1, s1.length());
    reverse(s1, 0, s1.length());
    
    if(s1 == s2)
        return 1;
    else
        return 0;
}

void printPermutation(string s, int l, int r){
    if(l == r) {
        cout<<s<<"\n";
    } else {
        for(int i=l; i<=r; i++){
            swap(s[l], s[i]);
            printPermutation(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}

string stringReverse(string s){
    string res = "";
    stack<string> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' ')
            res += s[i];
        else {
            stk.push(res);
            res = "";
        }
    }
    stk.push(res);
    s ="";
    while(!stk.empty()){
        s += stk.top() + ' ';
        stk.pop();
    }
    return s;
}

string stringReverseWord(string s){
    string res = "";
    stack<char> stk;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' ')
            stk.push(s[i]);
        else {
            while(!stk.empty()){
                res += stk.top();
                stk.pop();
            }
            res += " ";
        }
    }
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

string LCPUtil(string s1, string s2){
    string result = "";
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i=0, j=0; i<n1, j<n2; i++, j++){
        if(s1[i] != s2[j])
            break;
        result += s1[i];
    }
    return result;
}

string LCP(vector<string> A){
    string prefix = A[0];
    for(int i=0; i<A.size(); i++)
        prefix = LCPUtil(prefix, A[i]);
    return prefix;
}

int findEqualpt(string s){
    int len = s.length();
    int open[len], close[len];
    
    if(s[0] == '(')
        open[0] = 1;
    if(s[len-1] == ')')
        close[len-1] = 1;
    for(int i=1;i<len;i++){
        if(s[i] == '(')
            open[i] = open[i-1] + 1;
        else
            open[i] = open[i-1];
    }
    
    for(int i=len-2; i>=0; i--){
        if(s[i] == ')')
            close[i] = close[i+1]+1;
        else
            close[i] = close[i+1];
    }
    
    for(int i=0; i<len; i++){
        if(open[i] == close[i])
            return i;
    }
    return -1;
}

int max (int a, int b){
    return (a>b)?a:b;
}

int longestSubstring(string s){
    int characters[256];
    for(int i=0;i<256;i++)
        characters[i] = 0;
    int res = 0;
    for(int i=0; i<s.length();i++){
        for(int j=i; j<s.length(); j++){
            if(characters[s[j]] == 1)
                break;
            else{
                res = max(res, j-i+1);
                characters[s[j]] = 1;
            }
        }
        characters[s[i]] = 0;
    }
    return res;
}

int main() {
	string s1 = "amazon";
	string s2 = "azjhgfonam";
	cout<<s2<<" can be obtained by rotating a"<<s1<<" 2 places?? "<<isRotated(s1,s2);

    string s1 = "abc";
    cout<<"\n Print all permuation of "<<s1<<"\n";
    printPermutation(s1,0,s1.length()-1);
    
    string s = "the sky is blue";
    cout<<"\n Reverse string word by word : ";
    cout<<stringReverse(s);
    
    cout<<"\n Reverse each word of a string : ";
    cout<<stringReverseWord(s);
    
    vector<string> s = {"abcdefgh", "abcefghijk", "abcefgh"};
    cout<<"\n Longest Common Prefix by string matching : "<<LCP(s);

    string str = "(()))(()()())))"; 
    cout<<"find the equal point\n";
    cout<<findEqualpt(str);
    
    string s1 = "geeksforgeeks";
    cout<<"\n find the length of the longest substring without repeatig the character:\n";
    cout<<longestSubstring(s1);
    
    
    
	return 0;
}