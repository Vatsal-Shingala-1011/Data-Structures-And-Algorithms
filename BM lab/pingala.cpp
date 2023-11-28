#include <iostream>
using namespace std;

int fib(int n){
    if(n==1 || n==2) return 1;
    int p1=1;
    int p2=1;
    int temp;
    n--;
    while(n--){
        temp=p1;
        p1=p1+p2;
        p2=temp;
    }
    return p2;
}

int main() {
    int n;
    cout << "Enter the Number:  ";
    cin >> n;
    cout << fib(n)<<endl;
    return 0;
}
