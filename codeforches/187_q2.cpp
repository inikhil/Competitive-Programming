#include<iostream>
using namespace std;
int main(){
    int n,i,j,t,m,cunt=0;
    cin>>n;
    int **a =new int*[n];
    for(i=0;i<n;i++){
        a[i]=new int[2];
    }
    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        t=a[i][0];
        m=0;
        for(j=0;j<n;j++){
            if(i!=j){
                if(a[j][1]==t){
                    m=1;
                }
            }
        }
        if(m==0){
            cunt++;
        }
    }
    cout<<cunt<<endl;
}
