#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        int a=1+d;
        int b;
        int i=0;
        while(1){
            b=a+d+i;
            if(gcd(a,b)==1){
                cout<<a*b<<endl;
                break;
            }
            i++;
        }
    }
}