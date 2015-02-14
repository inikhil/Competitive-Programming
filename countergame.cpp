#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int nt,i;
    scanf("%d",&nt);
    unsigned long long int *a=new unsigned long long int[64];
    a[0]=1;
    for(i=1;i<64;i++){
        a[i]=2*a[i-1];
        printf("%llu ",a[i]);
       // cout<<a[i]<<" ";
    }
    unsigned long long int n;
    int cnt=0;
    while(nt--){
        scanf("%lld",&n);
        while(n!=1){
            i=0;
            while(n>a[i]){i++;}
            n=n-a[i-1];cnt++;
        }
        if(cnt%2==0){printf("Richard\n");}
        else{printf("Louise\n");}
    }
}
