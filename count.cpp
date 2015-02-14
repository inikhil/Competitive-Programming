#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int nt,i,j,n;
    cin>>nt;
    for(i=1;i<=nt;i++){
        cin>>n;
        int *a=new int[n];
        for(j=0;j<n;j++){cin>>a[j];}
        sort(a,a+n);
        cout<<"Case "<<i<<": "<<a[n-1]+a[n-2]+a[n-3]<<endl;
    }
}

