#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void output(char* d, string t){
    int i,m,k;
    char a;
    for(i=0;i<t.length();i++){
        m=(int)t[i];
        if(m>=97 && m<=122){cout<<d[m-97];}
        else if(m>=65 && m<=90){
            k=(int)d[m-65]-32;
            a=k;cout<<a;
        }
        else{cout<<t[i];}
    }
    cout<<"\n";
}
int main(){
    int nt,i,m,j,c,i1,k;
   std::string s,t,ss;
    int *a=new int[26];
    int *b=new int[26];
    char *d=new char[26];
    cin>>nt;cin.ignore();
    while(nt--){
        std::getline(cin,s);k=26;
        std::getline(cin,t);
        for(i=0;i<26;i++){a[i]=0;b[i]=-1;d[i]='-';}
        for(i=0;i<t.length();i++){
            m=int(t[i]);
            if(m>=65 && m<=90){a[m-65]++;}
            if(m>=97 && m<=122){a[m-97]++;}
        }
        while(k--){
            c=0;
            for(i=0;i<26;i++){
                if(a[i]>=c){c=a[i];i1=i;}
            }
            if(c==0){break;}
            else{b[k]=i1;a[i1]=0;}
        }
        for(i=25;i>=0;i--){
            if(b[i]==-1){break;}
            else{d[b[i]]=s[i];}
        }
        output(d,t);
    }

}
