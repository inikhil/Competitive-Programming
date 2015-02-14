#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
    int i,t,m,j,k=-1,n;
    char aa;
    ifstream myfile;
    myfile.open("h.txt");
    string s[100];
    i=0;
    while(!myfile.eof()){
        myfile>>s[i];
        //cout<<s[i]<<" ";
        i++;
    }
    t=i;
    int a[26];
    for(i=0;i<26;i++){
        a[i]=0;
    }
    for(i=0;i<t;i++){
        for(j=0;j<s[i].length();j++){
            m=int(s[i][j]-65);
            a[m]++;
        }
    }
    /*for(i=0;i<26;i++){
       cout<<a[i]<<" ";
    }*/
    while(k!=0){
        for(i=0;i<26;i++){
            if(a[i]>=k){
                k=a[i];
                n=i;
            }
        }
        for(i=0;i<26;i++){
            if(a[i]!=k){
                cout<<" "<<" ";
            }
            else{
                cout<<"*"<<" ";
                a[i]=a[i]-1;
            }
        }
        cout<<"\n";
        k--;
    }
    for(i=65;i<=90;i++){
        aa=i;
        cout<<aa<<" ";
    }
}
