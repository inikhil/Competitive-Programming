#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int nt,n,m,x,i,j,t,k,d;
    cin>>nt;
    while(nt--){
        cin>>n>>m>>x;
        int *w=new int[n+1];
        int *c=new int[n+1];
        w[0]=0;c[0]=0;d=0;
        for(i=1;i<=n;i++){cin>>w[i];}
        for(i=1;i<=n;i++){cin>>c[i];}
        int *prev=new int[x+1];
        int *next=new int[x+1];
        for(i=0;i<=x;i++){prev[i]=0;next[i]=0;}
        for(j=1;j<=m;j++){
            if(j==1){
                for(i=1;i<=n;i++){
                    if(c[i]==1 && x-w[i]>=0){prev[x-w[i]]=1;}
                }
            }
            else{
                for(i=1;i<=n;i++){
                    if(c[i]==j){
                        t=w[i];
                        for(k=0;k<=x;k++){
                            if(prev[k]==1 && k-t>=0){
                                next[k-t]=1;
                            }
                        }
                    }
                }
                for(k=0;k<=x;k++){prev[k]=next[k];next[k]=0;}
            }
            //for(i=0;i<=x;i++){cout<<prev[i]<<" ";}
            //cout<<"\n";
        }
        for(i=0;i<=x;i++){if(prev[i]==1){cout<<i<<endl;d=1;break;}}
        if(d==0){cout<<-1<<endl;}
    }
}
