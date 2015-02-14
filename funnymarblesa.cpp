#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,q,i,l,r,t=-1;
    char s;long long m;
    scanf("%d %d",&n,&q);
    int *a=new int[n];
    int *b=new int[n];
    int *c=new int[q];
    int *d=new int[q];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    b[0]=a[0];
    for(i=1;i<n;i++){b[i]=a[i]+b[i-1];}
    while(q--){
        scanf("%s", &s);
        switch(s){
        case 'S':
            scanf("%d %d",&l,&r);
            if(l==0){m=b[r];}
            else{m=b[r]-b[l-1];}
            for(i=0;i<=t;i++){
                if(c[i]<=r && c[i]>=l){m=m+d[i];}
            }
            printf("%lld\n",m);
            break;
        case 'G':
            scanf("%d %d",&l,&r);
            t++;
            c[t]=l;d[t]=r;
            break;
        case 'T':
            scanf("%d %d",&l,&r);
            t++;
            c[t]=l;d[t]=-1*r;
            break;
        }
    }
}

