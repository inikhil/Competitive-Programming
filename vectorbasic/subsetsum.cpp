#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

void sumdet(int *a, int ind,int n,int &cnt,int sum,int t){
    int i;
    if(t==sum){cnt++;return;}
    if(t>sum){return;}
    for(i=ind;i<n;i++){
        sumdet(a,i+1,n,cnt,sum,t+a[i]);
    }
}

int main(){
    int a[15]={3,9,8,4,5,7,10,-1,2,-1,0,-2,12,13,4};
    int sum=15;
    int cnt=0;
    sort(a,a+15);
    sumdet(a,0,15,cnt,sum,0);
    cout<<cnt;
}
