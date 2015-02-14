#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n,m,i,k,j,x,ans=0;
    scanf("%d %d",&n,&m);
    int *s=new int[m];
    int *f=new int[m];
    for(i=0;i<m;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&x);
            if(j==0){s[i]=x;}
            if(j==k-1){f[i]=x;}
        }
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(f[j]<f[i]){x=f[i];f[i]=f[j];f[j]=x;x=s[i];s[i]=s[j];s[j]=x;}
        }
    }
    /*for(i=0;i<m;i++){cout<<s[i]<<" "<<f[i]<<endl;}*/
    x=f[0];ans++;
    for(i=1;i<m;i++){
        if(s[i]>x){x=f[i];ans++;}
    }
    printf("%d\n",ans);
}
