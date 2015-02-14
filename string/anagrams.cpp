#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

class twoarr{
    public:
        string t;
        int a;
};

bool sortstr(const twoarr &lhs, const twoarr &rhs) { return lhs.t < rhs.t; }


int main(){
    int n,i,m;
    cin>>n;
    twoarr xyz[n];
    string *s=new string[n];
    for(i=0;i<n;i++){
        cin>>s[i];
        xyz[i].a=i;xyz[i].t=s[i];
        sort(xyz[i].t.begin(),xyz[i].t.end());
        //cout<<xyz.t[i];
    }
    sort(xyz,xyz+n,sortstr);
    //for(i=0;i<n;i++){cout<<xyz[i].t<<" ";}
    //for(i=0;i<n;i++){cout<<xyz[i].a<<" ";}
    for(i=0;i<n;i++){cout<<s[xyz[i].a]<<" ";}
}

