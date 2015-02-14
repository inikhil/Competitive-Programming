#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int n){
    int i;
    if(n%2==0){return false;}
    for(i=3;i<=sqrt(n);i=i+2){
        if(n%i==0){return false;}
    }
    return true;
}
int main(){
    int nt,x,y,m,z,i;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&x,&y);
        z=x+y;m=0;
        for(i=1;m!=1;i++){
            if(is_prime(z+i)==true){m=1;printf("%d\n",i);}
        }
    }

}
