#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,k,q,i,t,sum,j;
    scanf("%d",&n);
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);sum=0;
        for(i=0;i<n;i++){
            t=a[i];
            for(j=i;j<n;j++){
                t=min(t,a[j]);
                if(t==k){sum++;}
            }
        }
        printf("%d\n",sum);
    }

}
