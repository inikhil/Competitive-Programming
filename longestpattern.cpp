#include<iostream>
#include<cstdio>
using namespace std;
int solve(string s, string t){
    int k,sum=0,i;
    int *x=new int[62];
    int *y=new int[62];
    for(i=0;i<62;i++){x[i]=0;y[i]=0;}
    for(i=0;i<s.length();i++){
        k=(int)s[i];
        if(k>=97){x[k-71]++;}
        else{
            if(k>=65){x[k-65]++;}
            else{x[k+4]++;}
        }
    }
    for(i=0;i<t.length();i++){
        k=(int)t[i];
        if(k>=97){y[k-71]++;}
        else{
            if(k>=65){y[k-65]++;}
            else{y[k+4]++;}
        }
    }
    //for(i=0;i<=61;i++){cout<<x[i]<<" ";}
    for(i=0;i<=61;i++){sum+=min(x[i],y[i]);}
    delete[] x;
    delete[] y;
    return sum;
}

int main(){
    int nt;
    string s,t;
    scanf("%d",&nt);
    while(nt--){
        cin>>s>>t;
        printf("%d\n",solve(s,t));
    }
}
