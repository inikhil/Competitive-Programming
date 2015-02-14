#include<iostream>
#include<cstdio>
using namespace std;
long long* recount(int *a, long long *b,int n){
    int i;b[0]=a[0];
    for(i=1;i<n;i++){b[i]=a[i]+b[i-1];}
    return b;
}
int main(){
    int n,q,i,l,r,t=1;
    char s;
    scanf("%d %d",&n,&q);
    int *a=new int[n];
    long long *b=new long long[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
    while(q--){
        scanf("%s", &s);
        switch(s){
        case 'S':
            scanf("%d %d",&l,&r);
            if(t==1){b=recount(a,b,n);t=0;}
            if(l==0){printf("%lld\n",b[r]);}
            else{printf("%lld\n",b[r]-b[l-1]);}
            break;
        case 'G':
            scanf("%d %d",&l,&r);
            a[l]=a[l]+r;
            t=1;
            break;
        case 'T':
            scanf("%d %d",&l,&r);
            a[l]=a[l]-r;
            t=1;
            break;
        }
    }
}
