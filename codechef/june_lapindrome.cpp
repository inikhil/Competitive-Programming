#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int lapindrome(int *a,int leng){
    int j,l,m,k;
    for(j=0;j<leng/2;j++){
        l=a[j];
        a[j]=0;
        m=0;
        for(k=leng/2;m!=1;k++){
            if(k==leng){
                cout<<"NO"<<endl;
                m=1;
                return 0;
            }
            if(a[k]==l){
                a[k]=0;
                m=1;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
int lapindromeodd(int *a,int leng){
    int j,l,m,k;
    for(j=0;j<leng/2;j++){
        l=a[j];
        a[j]=0;
        m=0;
        for(k=leng/2+1;m!=1;k++){
            if(k==leng){
                cout<<"NO"<<endl;
                m=1;
                return 0;
            }
            if(a[k]==l){
                a[k]=0;
                m=1;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
int main(){
    int i,j,leng,*a,l,t;
    cin>>t;
    string s;
    for(i=0;i<t;i++){
        cin>>s;
        leng=s.size();
        a=new int[leng];
        for(j=0;j<leng;j++){
            a[j]=int(s[j]);
        }
        if(leng%2==0){
            l=lapindrome(a,leng);
        }
        else{
            l=lapindromeodd(a,leng);
        }
        delete a;
    }
}
