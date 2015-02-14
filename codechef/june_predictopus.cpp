#include<iostream>
using namespace std;
int main(){
    int t,i;
    double p,m;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>p;
        if(p>0.5){
            //m=1.04*10000-2*p*10000+9800*p+4900;
            m=(3*p-2*p*p)*10000;
        }
        else{
            //m=9800*p+4900;
            m=(1+p-2*p*p)*10000;
        }
        printf("%0.6f",m);
    }
    return 0;
}
