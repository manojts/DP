#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
void printSet(int table[][100],int i,int j,int arr[],vector<int>stk){
    if(j==0){
        //cout<<"hello"<<endl;
        for(int i=0;i<stk.size();i++)
            cout<<stk[i]<<" ";
        cout<<endl;
        return;
    }

    if(table[i][j]==table[i-1][j]){
       // cout<<arr[i-1]<<endl;
        printSet(table,i-1,j,arr,stk);
    }
    if(table[i][j]==table[i][j-1]){
        //cout<<arr[i-1]<<endl;
        printSet(table,i,j-1,arr,stk);
    }
   
    if(table[i][j]>table[i-1][j] && table[i][j]>table[i][j-1]){
        stk.push_back(arr[i-1]);
        printSet(table,i-1,j-arr[i-1],arr,stk);
        stk.pop_back();
    }

    // if(table[i][j]==table[i-1][j]){
    //     //stk.push_back(arr[i-1]);
    //     printSet(table,i-1,j,arr,stk);
    //     //printSet(table,i-1,j-arr[i-1],arr,stk);
    //     //stk.pop_back();
    // }
    // else if(table[i][j]==table[i][j-1]){
    //     printSet(table,i,j-1,arr,stk);
    // }
    // else{
    //     stk.push_back(arr[i-1]);
    //     printSet(table,i-1,j-arr[i-1],arr,stk);
    //     //printSet(table,i-1,j-arr[i-1],arr,stk);
    //     stk.pop_back();
    // }

}

int main(int argc, char const *argv[])
{
    int wt[]={1,3,4,5,2};
    int val[]={1,4,5,8,2};
    int capacity=7;
    int n=5   ;//size of weight array
    int w=capacity;//value of capacity
    int table[100][100];

    for(int i=0;i<n+1;i++){
        table[i][0]=0;
    }
    for(int i=0;i<w+1;i++){
        table[0][i]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                table[i][j]=max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
            }
            else{
                table[i][j]=table[i-1][j];
            }

        }
    }
    cout<<"Maximum profit "<<table[n][w]<<endl;

    std::vector<int> stk;
    printSet(table,n,w,wt,stk);
    return 0;
}