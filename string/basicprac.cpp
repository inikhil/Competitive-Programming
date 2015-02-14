#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(){
    string s;
    int i;
   // while(cin.good()){
        getline(cin,s);
        string t=s;
        int m=s.find('|');
        t=t.substr(0,m);
        s=s.substr(m+1,string::npos);
        /*t="";
        for(i=0;i<s.length();i++){
            if(s[i]=='|'){
                t[i]='\n';
                break;
            }
            else{
                t+=s[i];
            }
        }
        s=s.substr(i+1,string::npos);*/
        cout<<t<<endl;
        cout<<s<<endl;
    //}///////
}
