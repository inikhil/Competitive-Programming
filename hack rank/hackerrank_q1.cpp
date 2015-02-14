#include<iostream>
using namespace std;
int main(){
    int n,k,i,j,t,cunt=0;
    cin>>n>>k;
    int *a=new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
               t=a[j];
               a[j]=a[i];
               a[i]=t;
            }
        }
        cunt+=a[i];
        if(cunt>k){
            cout<<i;
            return 0;
        }
    }
}
