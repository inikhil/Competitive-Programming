#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<cstring>
using namespace std;
ifstream myfile;
ofstream myfile1;
void solve(int n){
    double c,f,x,ans=0,m=2;
    int t,i;
    myfile>>c;myfile>>f;myfile>>x;
    t=(double)x/c;ans=(double)c/m;
    for(i=2;i<=t;i++){
        ans+=(double)c/(m+t);
        m=m+t;
    }
    ans+=(double)x/m;
    myfile1<<ans<<endl;
}
int main(){
    int n;
    myfile1.open("bb.txt");
    myfile.open("aa.txt");
    myfile>>nt;
    for(i=1;i<=nt;i++){
        solve(i);
    }
}
