#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

bool check(string s,int n,int m){
    int i=n,j=m;
    while(i<j){
        if(s[i]!=s[j]){return false;}
        i++;j--;
    }
    return true;
}

void solve(string s){
    int i=0;
    int j=s.length()-1;
    int cnt=0;
    while(i<j){
        if(s[i]==s[j]){i++;j--;}
        else if(cnt==0){
            if(s[i]==s[j-1]||s[i+1]==s[j]){
                if(check(s,i,j-1)==true){cout<<"YES"<<endl;return;}
                if(check(s,i+1,j)==true){cout<<"YES"<<endl;return;}
                else{ cout<<"NO"<<endl;return;}
            }
            else{
                cout<<"NO"<<endl;return;
            }
        }
        else{
            cout<<"NO"<<endl;return;
        }
    }
    cout<<"YES"<<endl;return;
}

int main(){
    string s;
    int i,nt;
    cin>>nt;
    while(nt--){
        cin>>s;
        solve(s);
    }
}
