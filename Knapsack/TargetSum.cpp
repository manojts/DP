/*
	Given an array and the sum value

	find the number of ways to find the the sum by assigning the signs to 
	array elements(-/+)

	arr[]={1,1,2,3}
	sum=1;
	output:3

	+1 -1 -2 +3

	+1 +1 +2 -3

	-1 +1 -2 +3





*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,2,3,1};
	int sum=1;
	int n=4;
	int range;
	for(int i=0;i<n;i++){
		range+=arr[i];
	}
	int table[n+1][range+1];

	for(int i=0;i<range+1;i++)
		table[0][i]=0;
	for(int i=0;i<n+1;i++){
		table[i][0]=1;
	}

	for(int i=1;i<n+1;i++){
		for(int j=1;j<range+1;j++){
			if(arr[i-1]==j){
				table[i][j]=1;
			}
			table[i][j]=table[i-1][j] + table[i-1][j-arr[i-1]];

			cout<<table[i][j]<<" ";

		}
		cout<<endl;
	}

	for(int i=0;i<range+1;i++){
		if(range-(2*i)==sum){
			cout<<table[n][i]<<endl;
			break;
		}
	}

	
}