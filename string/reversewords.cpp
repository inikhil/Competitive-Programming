#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*void reversewords(string &s){
    //cout<<s<<endl;
    vector<string> p;
    string r="";
    int t,i=0;
    while(s.find(' ')!=string::npos){
        t=s.find(' ');
        p.push_back(s.substr(0,t));
        s=s.substr(t+1);
    }
    p.push_back(s);
    r+= p[p.size()-1];
    for(i=p.size()-2;i>=0;i--){
       r=r+' '+p[i];
    }
    //cout<<s<<endl;
    //cout<<r<<endl;
    s=r;
    cout<<s<<endl;
}
int main(){
    //char s[100];
    /*string s;
    getline(cin,s);
    //char *p=new char[100];
    string p[100];
    int t,i=0;
    //cout<<s;
    while(s.find(' ')!=string::npos){
        t=s.find(' ');
        p[i]=s.substr(0,t);
        s=s.substr(t+1);
        cout<<p[i]<<" ";i++;
    }
    p[i]=s;
    cout<<p[i]<<endl;
    string s;
    //vector<string> s;
    getline(cin,s);
    /*char c;
    string s1 = "";
    while (c!='\0'){
        cin>>c;
        s1=s1+c;
    }
    s.push_back(s1);
    reversewords(s);
}*/

int main(){
    string s;
    int i;
    string p="";
    string q="";
    getline(cin,s);
    int t=s.length();
    for(i=0;i<t;i++){
        if(s[i]==' '){
            if(q=="" && p!=""){q=p+q;}
            else if(p!=""){q=p+' '+q;}
            p="";
        }
        else{
            p=p+s[i];
        }
    }
    if(q=="" && p!=""){q=p+q;}
    else if(p!=""){q=p+' '+q;}
    s=q;
    cout<<s<<endl;
}
