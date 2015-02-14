#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long a;
    int t;scanf("%lld",&a);
    t=a%6;
    if(t==0||t==1||t==3){printf("yes\n");}
    else{printf("no");}

}
