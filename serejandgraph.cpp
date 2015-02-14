#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int nt,n,m,i,j,p,q,k=0;scanf("%d",&nt);
    while(nt--){
        scanf("%d %d",&n,&m);
        int **a=new int*[n];k=0;
        for(i=0;i<n;i++){a[i]=new int[n];}
        for(i=0;i<n;i++){for(j=0;j<n;j++){a[i][j]=0;}}
        if(n%2!=0){while(m--){scanf("%d %d",&p,&q);}printf("NO\n");k=1;}
        else{
        while(m--){
            scanf("%d %d",&p,&q);
            if(a[p-1][q-1]==0){
                for(i=0;i<n;i++){a[i][p-1]=-1;a[i][q-1]=-1;}
                for(i=0;i<n;i++){a[p-1][i]=-1;a[q-1][i]=-1;}
                a[p-1][q-1]=1;
            }
        }
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(a[i][j]==0){printf("NO\n");k=1;}
                    break;
                }
                break;
            }
            if(k!=1){printf("YES\n");}
        }
    }

}
