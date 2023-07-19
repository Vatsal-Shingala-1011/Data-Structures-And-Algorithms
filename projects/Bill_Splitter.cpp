#include <bits/stdc++.h>
using namespace std;
void input(map <string,int>&namee,int n){
	for(int i=0;i<n;i++){
		cout<<"Enter the name : ";
		string d;
		cin >>d;
		pair<string,int>p;
		p.first=d;
		p.second=i;
		namee.insert(p);
		cout <<endl;
	}
}
int find_label(map <string,int>&namee,int n,string d){
	auto it=namee.begin();
	auto it1=namee.find(d);
	return it1->second;
}
string find_name(map <string,int>&m,int n,int value){
	auto it = std::find_if(m.begin(), m.end(),
						[&value](const std::pair<string, int> &p) {
							return p.second == value;
						});
	//auto it=namee.begin();
	//auto it1=namee.find(d);
	string xyz=it->first;
	return xyz;
}
int main(){
	int n=0; //number of person
	cout <<"Enter the number of persons : ";
	cin>>n;
	map <string,int> name;
	cout<<endl;
	//input is a pair of name and its label in adj matrix
	input(name,n);
	int test=0;
	int arr[n][n]={0};
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++){
	// 		arr[i][j]=0;
	// 	}	
	// }
	while(test!=-1){
		int m;
		string p;
		cout << "What's the expense? : ";
		cin>>m;
		cout << "WHO PAID IT? : ";
		cin >>p;
		int x=find_label(name,n,p);
		//x contains index of who paid it in adj matrix
		int expense=m/n;
		//pick x row and iterate through x row
		//cout << "x is" <<x;
		for(int i=0;i<n;i++){
			if(i==x) arr[x][x]=0;
			else
				arr[x][i]+=expense;
		}
		cout << "Press -1 to stop OR press any to continue : ";
		cin >> test;
	}
	cout<< "\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << arr[i][j]<<" ";
		}
		cout <<endl;
	}
	int y,v1,v2,diff,x;
	cout<< "\n\n\n\n";
	for(int i=0;i!=n-1;i++){
		 x=i;
		for(int j=i+1;j<n;j++){
			 y=j;
			// cout<< "\n";
			 //cout << "x is "<<x<<endl;
			 //cout <<"y is" <<y<<endl;
			 //cout<< "\n";
			 v1=arr[x][y];
			 v2=arr[y][x];
			 diff =v1-v2;
			string name_x=find_name(name,n,x);
			string name_y=find_name(name,n,y);
			if(diff == 0){
				cout << name_x<<" "<<name_y<<"  no payment";
				//cout << "No payment";
			}
			else if(diff<0){
				cout << name_x<<"  needs to pay "<<name_y;
				//cout<< "\n";
				//cout << x << " needs to pay "<<y;
				cout <<"  " <<abs(diff);
				cout<< "\n";
			}
			else{
				cout << name_y<<"  needs to pay Rs."<<name_x;
				//cout<< "\n";cout << x << " "<<y;
				cout <<"  " <<abs(diff);
				cout<< "\n";
			}
		}
	}
	return 0;
}
