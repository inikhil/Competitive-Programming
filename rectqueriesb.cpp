#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i,j,k,t,m,q,x1,x2,y1,y2,cnt;
    scanf("%d",&n);
    int **a=new int*[n];
    for(i=0;i<n;i++){a[i]=new int[n];}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    t=10*n;
    int **b=new int*[t];
    for(i=0;i<t;i++){b[i]=new int[n];}
    for(i=0;i<t;i++){
        for(j=0;j<n;j++){b[i][j]=-1;}
    }
    for(k=0;k<10;k++){
        for(i=0;i<n;i++){
           m=0;
           for(j=0;j<n;j++){
                if(a[i][j]%10==k){
                    t=k*n+i;
                    b[t][m]=j;m++;
                }
           }
        }
    }
    /*for(i=0;i<n*10;i++){
        for(j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        cnt=0;
        x1=x1-1;y1=y1-1;x2=x2-1;y2=y2-1;
        for(k=0;k<10*n;k=k+n){
            m=0;
            for(i=x1+k;i<=x2+k;i++){
                for(j=0;j<n;j++){
                    if(b[i][j]>=y1 && b[i][j]<=y2){cnt++;m=1;break;}
                    if(b[i][j]==-1){break;}
                }
                if(m==1){break;}
            }
           //cout<<cnt<<endl;
        }
        printf("%d\n",cnt);
    }
}
