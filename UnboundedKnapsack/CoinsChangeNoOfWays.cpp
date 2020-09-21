#include <bits/stdc++.h>
using namespace std;
int main(){
	int coins[]={2,3,5,10};
	int sum=15;
	int len=4;

	int table[len+1][sum+1]={0};

	for(int i=0;i<=len;i++)
		table[i][0]=1;
	
	for(int i=1;i<=sum;i++)
		table[0][i]=0;

	for(int i=1;i<=len;i++){
		for(int j=1;j<=sum;j++){
			if(coins[i-1]<=j)
				table[i][j]=table[i][j-coins[i-1]]+table[i-1][j];
			else
				table[i][j]=table[i-1][j];
		}
	}


	for(int i=0;i<=len;i++){
		for(int j=0;j<=sum;j++){
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}


}