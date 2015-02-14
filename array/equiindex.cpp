#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(){
    int n,nt,i,sum,t,m;
    cin>>nt;
    while(nt--){
        cin>>n;
        t=0;sum=0;m=0;
        int *a=new int[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        for(i=0;i<n;i++){
            if(i>0){
                t=t+a[i-1];
                if(sum-a[i]==2*t){
                    cout<<i<<endl;
                    m=1;
                }
            }
            else{
                if(sum-a[i]==t){
                    cout<<i<<endl;
                }
            }
        }
        if(m==0){cout<<-1<<endl;}
    }
}
