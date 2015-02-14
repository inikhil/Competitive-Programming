#include<iostream>
using namespace std;
int main(){
    int n,i,t,cunt=0,j,m;
    cin>>n;
    for(i=1;i<=n/2+1;i++){
        t=i;
        m=0;
        for(j=i+1;m!=1;j++){
            t+=j;
            if(t>n){
                m=1;
            }
            if(t==n){
                cunt++;
            }
        }
    }
    cout<<cunt+1<<endl;
}
