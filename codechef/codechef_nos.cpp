#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long x1,x2,x3,upp,d,t,cunt;
    int nt,m,n,i;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>upp>>d>>m>>n;
        cunt=0;
        for(x1=0;x1<=upp;x1++){
            for(x2=0;x2<=upp;x2++){
                for(x3=0;x3<=upp;x3++){
                    t=pow(x3,d)+pow(x2,d)+pow(x1,d);
                    if(t%n==m){
                        cunt++;
                    }
                }
            }
        }
        cout<<cunt%1000000007<<endl;
    }

}
