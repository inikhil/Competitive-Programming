#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class stone{
public:
    int w;
    int c;
};

bool sortbyval(stone a, stone b){
    return a.c<b.c;
}

int main(){
    int nt,n,m,x,i,j,i1,d,t,k;
    cin>>nt;
    while(nt--){
        cin>>n>>m>>x;
        stone *a=new stone[n+1];
        a[0].w=-1;a[0].c=-1;i1=1;d=0;
        for(i=1;i<=n;i++){cin>>a[i].w;}
        for(i=1;i<=n;i++){cin>>a[i].c;}
        int *prev=new int[x+1];
        int *next=new int[x+1];
        for(i=0;i<=x;i++){prev[i]=0;next[i]=0;}
        sort(a,a+n,sortbyval);
        for(j=1;j<=m;j++){
            if(j==1){
                for(i=i1;i<=n;i++){
                    if(a[i].c==1 && x-a[i].w>=0){prev[x-a[i].w]=1;}
                    if(a[i].c!=1){i1=i;break;}
                }
            }
            else{
                for(i=i1;i<=n;i++){
                    if(a[i].c==j){
                        t=a[i].w;
                        for(k=0;k<=x;k++){
                            if(prev[k]==1 && k-t>=0){
                                next[k-t]=1;
                            }
                        }
                    }
                    else{
                        i1=i;break;
                    }
                }
                for(k=0;k<=x;k++){prev[k]=next[k];next[k]=0;}
            }
            for(i=0;i<=x;i++){cout<<prev[i]<<" ";}
            cout<<"\n";
        }
        for(i=0;i<=x;i++){if(prev[i]==1){cout<<i<<endl;d=1;break;}}
        if(d==0){cout<<-1<<endl;}
    }
}
