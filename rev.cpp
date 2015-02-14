#include<iostream>
#include<cmath>
using namespace std;
int rev(int n){
    int t=n,m=0,m2=0,k;
    while(t!=0){
        m++;
        t=t/10;
    }
    t=n;
    while(t!=0){
        k=t%10;
        //cout<<k<<" ";
        m2=m2+k*pow(10.0,m-1);
        //cout<<m2<<" ";
        m--;
        t=t/10;
    }
    return m2;
}
int main(){
    int nt,i,m1,m2,n1,n2,m;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>m1>>n1;
        m2=rev(m1);
   //     cout<<m2<<" ";
        n2=rev(n1);
     //   cout<<n2<<" ";
        m=m2+n2;
        cout<<rev(m)<<endl;
   }
}
