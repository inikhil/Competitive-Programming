#include<iostream>
using namespace std;

int solve(int *a,int n,int k){
    int i;
    int st=0;
    int curr=a[st];
    int ot=1;
    int res=n;
    for(i=1;i<n;i++){
        if(k>=curr){curr=curr+a[i];ot++;}
        else if(k<curr){curr=curr-a[st];st++;res=min(res,ot);ot--;}
    }
    return res;
}

int main(){
    int n,i,k;
    cin>>n>>k;
    int *a=new int[n];
    for(i=0;i<n;i++){cin>>a[i];}
    int m=solve(a,n,k);
    cout<<m<<endl;
}
