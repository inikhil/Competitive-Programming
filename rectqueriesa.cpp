#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i,j,q,x1,y1,x2,y2,t,cnt,m,k,p;
    scanf("%d",&n);
    int **a=new int*[n];
    for(i=0;i<n;i++){a[i]=new int[n];}
    t=n*n;
    int **b=new int*[t];
    for(i=0;i<t;i++){b[i]=new int[10];}
    for(i=0;i<t;i++){
        for(j=0;j<10;j++){
            b[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            m=i*n+j;
            k=a[i][j]%10;
            b[m][k]=b[m][k]+1;
            if(m>0){for(p=0;p<10;p++){b[m][p]=b[m-1][p]+b[m][p];}}
            //for(p=0;p<10;p++){cout<<b[m][p]<<" ";}
            //cout<<"\n";
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        cnt=0;
        x1=x1-1;y1=y1-1;x2=x2-1;y2=y2-1;
        t=x1*n+y1;
        m=x2*n+y2;
        for(i=0;i<10;i++){
            if(t>0){k=b[m][i]-b[t-1][i];}
            if(t==0){k=b[m][i];}
            //cout<<k<<" ";
            if(k>0){cnt++;}
        }
       // printf("\n");
        printf("%d\n",cnt);
    }

}

