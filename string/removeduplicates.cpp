#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char s[255];
    int i,n;
    gets(s);
    n=strlen(s);
    int *a=new int[26];
    for(i=0;i<n;i++){a[s[i]-97]++;}
    for(i=0;i<n;i++){
        if(a[s[i]-97]>0){a[s[i]-97]=0;cout<<s[i];}
    }
}
