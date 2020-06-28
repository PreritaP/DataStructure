#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[256] = {0};


char nonRepeatingChar(string s){
    int count[256] = {0};
    for(int i=0; i<s.size(); i++){
        count[s[i]]++;
    }
    for(int i=0;i<s.size();i++){
        if(count[s[i]] == 1)
            return s[i];
    }
    return '0';
}


void nonRepeat(char s, int len){
    arr[s - 'a']++;
    for(int i=0;i<=256;i++){
        if(arr[i] == 1){
        	char ch = i + 97;
            cout<<"\nFirst non-repeating character so far is : "<<ch;
            return;
        }
    }
}

void nonRepeatingInStream(){
    // string stream = "geeksforgeeksandgeeksquizfor";
    // for(int i=0; i<stream.size(); i++){
    //     cout<<"\nReading "<<stream[i]<<" from stream of character-->";
    //     nonRepeat(stream[i], i);
    // }

    char ch;
    int i=0;
    while(i != 10 ) {
        
        char alphabet[] = "geeksforgeeksandgeeksquizfor";
        ch = alphabet[rand()%28];
        cout<<"\nReading "<<ch<<" from input stream"<<endl;
        nonRepeat(ch, i);
        i++;
    }
}

string findSubString(string str, string pat){
    int len1 = str.length(); 
    int len2 = pat.length(); 
  
    if (len1 < len2) { 
        cout << "No such window exists"; 
        return ""; 
    } 
  
    int hash_pat[256] = {0}; 
    int hash_str[256] = {0}; 
  
    for (int i = 0; i < len2; i++) 
        hash_pat[pat[i]]++; 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
    int count = 0;
    
    for (int j = 0; j < len1 ; j++) { 
        hash_str[str[j]]++; 
  
        if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]] ) 
            count++; 
  
        if (count == len2) {
            while ( hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) { 
  
                if (hash_str[str[start]] > hash_pat[str[start]]) 
                    hash_str[str[start]]--; 
                start++; 
            } 

            int len_window = j - start + 1; 
            if (min_len > len_window) { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    if (start_index == -1) { 
    cout << "No such window exists"; 
    return ""; 
    } 

    return str.substr(start_index, min_len);
}

int main() {

    /* Problem 1 : Print the first non repeating character from the string */
	string s = "geeksforgeels";

    /* In a string */
	cout<<nonRepeatingChar(s);
	
    /* In a stream of characters */
	nonRepeatingInStream();

    /* Problem 2 : Find the smallest window in a string containing all the characters of another string */
    string s1 = "this is a test string";
    string s2 = "tist";
    cout<<findSubString(s1,s2);
    
	return 0;
}
