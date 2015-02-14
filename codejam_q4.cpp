#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream myfile;
FILE  *myfile1;
void dwar(double *nao,double *ken,int t,int n){
    int i,d1,d2,m=0;
    for(i=0;i<t;i++){
        if(nao[i]>ken[t-i-1]){break;}
        else if(nao[i]<ken[t-i-1]){m++;}
    }
    d1=t-i;
    d2=d1-m;
    cout<<d1<<" "<<d2<<endl;
}
void solve(int n){
    int t,i;
    myfile>>t;
    double *nao=new double[t];
    double *ken=new double[t];
    for(i=0;i<t;i++){myfile>>nao[i];}
    for(i=0;i<t;i++){myfile>>ken[i];}
    sort(nao,nao+t);sort(ken,ken+t);
    dwar(nao,ken,t,n);
}

int main(){
    int nt,i;
    myfile1=fopen("bb.txt","w");
    myfile.open("aa.txt");
    myfile>>nt;
    for(i=1;i<=nt;i++){
        solve(i);
    }
}
