#include <bits/stdc++.h>
using namespace std;

void printSet(int table[][100],int i,int j,int arr[],vector<int>stk){
	if(j==0){
		for(int i=0;i<stk.size();i++)
			cout<<stk[i]<<" ";
		cout<<endl;
		return;
	}

	if(table[i-1][j]){
		printSet(table,i-1,j,arr,stk);
	}
	if(table[i-1][j-arr[i-1]]){
		stk.push_back(arr[i-1]);
		printSet(table,i-1,j-arr[i-1],arr,stk);
		stk.pop_back();
	}
}
int main(){
	int arr[]={1,6,11,6,2};

	int sum=0;

	int n=5;

	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(sum%2==0){
		sum=sum/2;
	}
	else{
		cout<<"Not possible"<<endl;
		return 0;
	}
	cout<<sum<<endl;
	int table[100][100];

	for(int i=0;i<sum+1;i++)
		table[0][i]=0;
	for(int i=0;i<n+1;i++)
		table[i][0]=1;

	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]==j){

				table[i][j]=1;
			}
		
			table[i][j]=table[i-1][j] || table[i-1][j-arr[i-1]];
			
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}



	cout<<"sum is "<<table[n][sum]<<endl;


	cout<<"The partition subset are "<<endl;
	std::vector<int > stk;
	printSet(table,n,sum,arr,stk);
}