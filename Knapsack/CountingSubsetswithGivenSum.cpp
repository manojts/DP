#include <bits/stdc++.h>
using namespace std;

int main(){
	
	
	int arr[]={2,3,5,7,14};
	int sum=14;
	int n=5;
	int table[6][15];
	vector<int>stk;
	
	for(int i=0;i<sum+1;i++)
	{	
		table[0][i]=0;
	}
	
	for(int i=0;i<n+1;i++)
	{
		table[i][0]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]==j){
				table[i][j]=1;
			}
			//else{
			table[i][j]=(table[i-1][j-arr[i-1]]) + ( table[i-1][j]);
			//}
			//cout<<table[i][j]<<" ";
		}
		//cout<<endl;
	}

	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}


	
	cout<<"Count is "<<table[n][sum]<<endl;


}
