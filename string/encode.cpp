#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){
    char *s=new char[1000];
    gets(s);
    int i,j=0,cnt=0,k;
    char *p=new char[1000];
    char *d=new char[10];
    for(i=0;i<strlen(s);i++){
        p[j++]=s[i];
        while(i+1<strlen(s) && s[i]==s[i+1]){i++;cnt++;}
        sprintf(d,"%d",cnt+1);cnt=0;
        for(k=0;k<strlen(d);k++){p[j++]=d[k];}
    }
    cout<<p;
}
