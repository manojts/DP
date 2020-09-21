#include <bits/stdc++.h>
using namespace std;



void printAllSubset(int table[][15],int i,int j,int arr[],vector<int>stk){

	if(j==0){
		for(int it=0;it<stk.size();it++){
			cout<<stk[it]<<" ";
		}
		cout<<endl;
		return ;
	}
	if(table[i-1][j]){
		printAllSubset(table,i-1,j,arr,stk);
	}
	if(table[i-1][j-arr[i-1]]){
		//cout<<arr[i-1]<<" ";
		stk.push_back(arr[i-1]);
		printAllSubset(table,i-1,j-arr[i-1],arr,stk);
		stk.pop_back();

	}
	//cout<<endl;
}

void display(int table[10][15],int n,int sum){
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
}
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
			table[i][j]=(table[i-1][j-arr[i-1]]) || ( table[i-1][j]);
			//}
			//cout<<table[i][j]<<" ";
		}
		//cout<<endl;
	}
	display(table,n,sum);

	

	printAllSubset(table,n,sum,arr,stk);

	cout<<"Sum is "<<table[n][sum]<<endl;


}







// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 1 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 0 0 1 0 1 0 1 0 0 1 0 1
// 1 1 1 0 0 1 0 1 0 1 0 0 1 0 1
// 1 1 1 0 1 1 1 1 1 1 0 1 1 1 1