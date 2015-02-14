#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
    vector<int> a;
    int i,j;
    int temp,x;
    int n=2000;
    int *b=new int[n];
    b[0]=1;b[1]=1;
    a.push_back(1);
    for(i=2;i<n;i++){
        temp=0;
        b[i]=0;
        for(j=0;j<a.size();j++){
            x=a[j]*i+temp;
            a[j]=x%10;
            b[i]=b[i]+a[j];
            temp=x/10;
        }
        while(temp!=0){
            a.push_back(temp%10);
            b[i]=b[i]+temp%10;
            temp=temp/10;
        }
        //cout<<b[i]<<" ";
    }
    cout<<a.size();
}
