#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int m=1000000007;
unsigned long long a[100001];

int power(int x, unsigned int y)
{
    unsigned long long t;
    if(x==1)
        return 1;
    else if( y == 0)
        return 1;
    else if (y%2 == 0)
        t=(unsigned long long) (power(x, y/2)%m) * (power(x, y/2)%m);
    else{
        t= (unsigned long long)  (power(x, y/2)%m) * (power(x, y/2)%m);
        t=(unsigned long long) (t%m) * (x%m);
    }
    return t%m;
}

void fact(){
    int i;
    a[0]=1;
    for(i=1;i<=100000;i++){
       a[i]=((unsigned long long)a[i-1]*i)%m;
    }
}

int main(){
    string s;
    cin>>s;
    int i,t;
    unsigned long long ans;
    int *b=new int[26];
    for(i=0;i<26;i++){b[i]=0;}
    int n=s.length();
    for(i=0;i<n;i++){b[s[i]-97]++;}
    fact();
    ans=a[n/2];
    for(i=0;i<26;i++){
        if(b[i]>1){
            ans=((unsigned long long)ans*power(a[b[i]/2],m-2))%m;
        }
    }
    cout<<ans;
}

