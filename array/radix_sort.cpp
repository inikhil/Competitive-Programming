#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void print(int *a,int n){
    int i;
    for(i=0;i<=n;i++){cout<<a[i]<<" ";}
    cout<<"\n";
}

void countsort(int *a, int base, int exp, int len){
    int i,j;
    int *cnt=new int[base];
    int *oput=new int[len+1];
    for(i=0;i<base;i++){cnt[i]=0;}
    for(i=0;i<=len;i++){oput[i]=-1;}
    for(i=0;i<=len;i++){cnt[(a[i]/exp)%base]++;}
    for(i=1;i<base;i++){cnt[i]=cnt[i]+cnt[i-1];}
    for(i=len;i>=0;i--){oput[cnt[(a[i]/exp)%base]-1]=a[i];cnt[(a[i]/exp)%base]--;}
    j=0;
    for(i=0;i<=len;i++){a[i]=oput[i];}
}

void radixsort(int *a,int n){
    int base=10;
    int d=3,i;
    for(i=0;i<d;i++){countsort(a,base,pow(10.0,i),n);}
}
int main(){
    int n,i;
    cin>>n;
    int *a=new int[n];
    for(i=0;i<n;i++){cin>>a[i];}
    radixsort(a,n-1);
    print(a,n-1);
}
