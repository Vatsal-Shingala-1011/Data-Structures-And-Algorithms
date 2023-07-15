


#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int l;
	    cin>>l;
	    string s;
	    cin>>s;
	    if( l% 3 ==1){
	        cout<<"YES"<<endl;
	        continue;
	    }
	    bool flag = false;
	    for( char ch = 'a'; ch<='z';ch=ch+1){
	        int firstindex=l+1,lastindex=-1;
	        for(int i=0; i<l;i++){
	            if(i%3==0 && s[i]==ch){
	                firstindex =i;
	                break;
	            }
	        }
	        for( int i= l -1; i>=0;i--){
	            int x=l-1-i;
	            if(x%3==0 && s[i]==ch){
	                lastindex=i;
	                break;
	            }}
	            if(firstindex < lastindex){
	                flag =true;
	                break;
	            }
	    }
	    if(flag)
	    cout<<"YES"<<endl;
	    else
	    cout<<"NO"<<endl;
	}
	return 0;
} 


// Problem
// You are given a string 
// �
// S of length 
// �
// N.
// Your task is to convert the string into a non-empty palindrome using the following operation any (possibly zero) number of times:

// Choose an index 
// 1
// <
// �
// <
// ∣
// �
// ∣
// 1<i<∣S∣, where 
// ∣
// �
// ∣
// ∣S∣ denotes the current length of string;
// Remove the characters at indices 
// (
// �
// −
// 1
// )
// (i−1), 
// �
// i, and 
// (
// �
// +
// 1
// )
// (i+1) from the string and concatenate remaining part(s) of the string.
// Print YES if it is possible to convert the string into a non-empty palindrome and NO otherwise.

// Input Format
// The first line of input will contain a single integer 
// �
// T, denoting the number of test cases.
// Each test case consists of two lines of input.
// The first line of each test case contains 
// �
// N - the length of string.
// The next line contains string 
// �
// S.
// Output Format
// For each test case, print on a new line, YES, if it is possible to convert the given string into a non-empty palindrome, otherwise print NO.

// Each character of the output may be printed in either uppercase or lowercase, i.e, the strings Yes, YES, yes, and yEs will be treated as identical.

// Constraints
// 1
// ≤
// �
// ≤
// 1
// 0
// 5
// 1≤T≤10 
// 5
 
// 1
// ≤
// �
// ≤
// 2
// ⋅
// 1
// 0
// 5
// 1≤N≤2⋅10 
// 5
 
// �
// S consists of lowercase english alphabets only.
// The sum of 
// �
// N over all test cases won't exceed 
// 5
// ⋅
// 1
// 0
// 5
// 5⋅10 
// 5
//  .
// Sample 1:
// Input
// Output
// 3
// 5
// aaaaa
// 5
// abcde
// 5
// aabcd
// YES
// NO
// YES
// Explanation:
// Test case 
// 1
// 1: The given string is already a palindrome. Thus, we need 
// 0
// 0 operations.

// Test case 
// 2
// 2: It is not possible to convert the string abcde into a palindrome using any number of operations.

// Test case 
// 3
// 3: Choose 
// �
// =
// 4
// i=4 and delete the characters at indices 
// 3
// ,
// 4
// ,
// 3,4, and 
// 5
// 5. Thus, the string aabcd becomes aa, which is a palindrome.





