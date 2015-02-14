#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int nt,l,d,s,c,i,m;scanf("%d",&nt);
    long long t;
    while(nt--){
        scanf("%d %d %d %d",&l,&d,&s,&c);t=s;m=0;
        if(d>=31){printf("ALIVE AND KICKING\n");}
        else if(d==1 && s>=l){printf("ALIVE AND KICKING\n");}
        else{
                for(i=1;i<d;i++){t=(long long)t*(1+c);if(t>=l){printf("ALIVE AND KICKING\n");m=1;break;}}
                if(m!=1){printf("DEAD AND ROTTING\n");}
        }
    }
}
