#include<iostream>
using namespace std;
int main(){
    int i,j,t;
    int **a=new int*[3];
    for(i=0;i<3;i++){
        cin>>t;
        a[i]=new int[t+1];
        a[i][0]=t;
        for(j=1;j<=t;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<3;i++){
        for(j=1;j<=a[i][0];j++){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}
