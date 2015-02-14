#include<iostream>
using namespace std;
int main(){
    int n,m,i,op,i1,j1,i3,i2,j;
    cin>>n;
    cin>>m;
    int *a= new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<m;i++){
        cin>>op;
        if(op==1){
             cin>>i1;
             cin>>j1;
             a[i1-1]=j1;
        }
        if(op==2){
            cin>>i2;
            for(j=0;j<n;j++){
                a[j]=a[j]+i2;
            }
        }
        if(op==3){
             cin>>i3;
             cout<<a[i3-1]<<endl;
        }
    }
    return 0;
}

