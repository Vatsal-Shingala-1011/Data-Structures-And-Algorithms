#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.

  string line;
  int index = 1;
  int n;
  while (!cin.eof()) {
    // getline(cin, line);
    // cout << "line[" << index++ << "]:" << line << "\n";
    cin>>n;
    for(int i=0;i<n;i++){
      int q;
      cin>>q;
      int a[n]={0};
      int b[n]={0};
      if(q==1){
        int aa,bb;
        cin>>aa>>bb;
        for(int i=0;i<n;i++){
            if(a[i]<aa&&b[i]<=bb){
                a[i]=aa;
                b[i]=bb;
            }
        }
      }
      else{
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==0&&b[i]==0){
                cnt++;
            }
            cout<<cnt<<endl;
        }
      }
    }
    }
  return 0;
}
