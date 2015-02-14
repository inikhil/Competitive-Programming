#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct obj{
    string s;
    long long n;
};

//int a[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

long long buildinput(string s,int a[]){
    long long ans=0;
    int i;
    //cout<<s<<" ";
    for(i=0;i<s.length();i++){
        ans=(long long)ans*10+a[s[i]-'a'];
    }
    //cout<<ans<<" ";
    return ans;
}

string smallconv(string t){
    int i;
    for(i=0;i<t.length();i++){
        if(65<=t[i] && t[i]<=90){
            t[i]=t[i]+32;
        }
    }
    return t;
}

bool sortbynum(obj c, obj d){
    //if(c.n==d.n){return c.s>d.s;}
    return c.n>d.n;
}

int main(){
    int n,i;
    string t;
    cin>>n;
    //stringform();
    //int *a=new int[26];
    int a[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    //for(i=0;i<26;i++){cout<<a[i]<<" ";}
    obj *b=new obj[n];
    for(i=0;i<n;i++){
        cin>>t;
        t=smallconv(t);
        b[i].s=t;
        b[i].n=buildinput(t,a);
    }
    sort(b,b+n,sortbynum);
    for(i=0;i<n;i++){
        cout<<b[i].s<<" "<<b[i].n<<endl;
    }
}

