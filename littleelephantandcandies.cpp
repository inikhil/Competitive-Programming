#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int nt,n,c,i,m,t;
    scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&n,&c);t=0;
        for(i=0;i<n;i++){scanf("%d",&m);t=t+m;}
        if(c>=t){printf("Yes\n");}
        else{printf("No\n");}
    }
}
