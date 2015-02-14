#include<iostream>
#include<cstdio>
#include<list>
#include<cstring>
#include<algorithm>
using namespace std;

struct abc{
    int cnt;
    int index;
} ;

bool sortbycnt(abc a,abc b){
    return a.cnt<b.cnt;
}

void solve(string s,string t){
    int i,m,j,tt,k,sum;
    cin>>m;
    int **d=new int*[26];
    int **e=new int*[26];
    for(i=0;i<26;i++){
        d[i]=new int[26];
        e[i]=new int[26];
        for(j=0;j<26;j++){
            d[i][j]=0;
            e[i][j]=0;
        }
    }
    string c;
    for(i=0;i<m;i++){
        cin>>c;
        tt=c[0]-'a';
        k=c[3]-'a';
        d[k][tt]=1;
        e[tt][k]=1;
    }
    //cout<<"x";
    for(i=25;i>=0;i--){
        for(j=0;j<26;j++){
            if(d[i][j]>0){
                for(k=0;k<26;k++){
                    if(e[i][k]==1){d[k][j]=1;e[j][k]=1;}
                }
            }
        }
    }
    for(i=0;i<s.length();i++){
        tt=s[i]-'a';
        k=t[i]-'a';
        if(s[i]!=t[i]){
            if(d[k][tt]!=1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main(){
    int nt;
    cin>>nt;
    string s,t;
    while(nt--){
        cin>>s;cin>>t;
        if(s.length()!=t.length()){cout<<"NO"<<endl;}
        else{solve(s,t);}
    }
}
