#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    int nt,i,n;
    double R,r,ang;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>R>>n;
        ang=(double)(360*.01745329)/(n*2);
        r=(double)(R*sin(ang))/(1+sin(ang));
        cout<<"Scenario #"<<i+1<<":"<<endl;
       // cout<<r<<endl;
        printf("%0.3f",r);
        cout<<"\n"<<endl;
    }
}
