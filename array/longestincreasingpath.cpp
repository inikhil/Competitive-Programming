#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int solve(int **a,int row,int col){
	int i,j;
	int dp[row][col];
	memset(dp,0,sizeof(dp));
	dp[row-1][col-1]=1;
	for(i=row-1;i>=0;i--){
		for(j=col-1;j>=0;j--){
			if(i>0 && a[i-1][j]<a[i][j] && dp[i-1][j]<=dp[i][j]){dp[i-1][j]=1+dp[i][j];}
			else if(i>0 && dp[i-1][j]==0){dp[i-1][j]=1;}
			if(j>0 && a[i][j-1]<a[i][j] && dp[i][j-1]<=dp[i][j]){dp[i][j-1]=1+dp[i][j];}
			else if(j>0 && dp[i][j-1]==0){dp[i][j-1]=1;}
		}
	}
	return dp[0][0];
}

int main()
{
    int nt,cnt,row,col,i,j;
    cin>>nt;
    while(nt--){
    	cnt=0;
    	cin>>row>>col;
    	int **a=new int*[row];
    	for(i=0;i<row;i++){
    		a[i]=new int[col];
    		for(j=0;j<col;j++){
    			cin>>a[i][j];
    		}
    	}
    	cout<<solve(a,row,col)<<endl;
    }
}

