#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int nt,i,m=0,j,j1,t;
    string s;char c;
    cin>>nt;
    while(nt--){
        /*cin>>s;
        t=s.length();
        m=0;c='{';
        for(i=t-1;i>=0;i--){
            if(i==0){cout<<"no answer"<<endl;m=1;break;}
            if(s[i-1]<s[i]){break;}
        }
        if(m!=1){
            for(j=i;j<t;j++){
                if(s[j]<c && s[j]>s[i-1]){c=s[j];j1=j;}
            }
            s[j1]=s[i-1];
            s[i-1]=c;
            sort(s.begin()+i,s.end());
            cout<<s<<endl;
        }*/
        cin>>s;
        next_permutation(s.begin(),s.end());
        cout<<s<<endl;
    }
}
