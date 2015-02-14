#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int kad(int *c,int n){
    int sum_now=c[0];
    int track=c[0];
    int i;
    for(i=1;i<n;i++){
        track=max(track+c[i],c[i]);//cout<<track<<" ";
        if(track>sum_now){sum_now=track;}
    }
    //cout<<sum_now<<endl;
    return sum_now;
}

int main(){
    int n,i,j,jj,p,k;
    scanf("%d",&n);
    int **a=new int*[n];
    for(i=0;i<n;i++)
        a[i]=new int[n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ***b=new int**[n];
    for(i=0;i<n;i++){
        b[i]=new int*[n];
        for(j=0;j<n;j++){
            b[i][j]=new int[n];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                b[i][j][k]=0;
                //printf("%d ",b[i][j][k]);
            }
        }
        //printf("\n");
    }
   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            b[i][j][j]=a[i][j];
            //cout<<b[i][j][j]<<" ";
        }
        for(p=0;p<n;p++){
            for(j=0,k=p+1;k<n;j++,k++){
                b[i][j][k]=b[i][j+1][k]+b[i][j][k-1]-b[i][j+1][k-1];
                //cout<<b[i][j][k]<<" ";
            }
        }
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                printf("%d ",b[i][j][k]);
            }
        }
        printf("\n");
    }*/
    int *c=new int[n];
    int sum=0;
    for(j=0;j<n;j++){
        for(k=j;k<n;k++){
            for(i=0;i<n;i++){
                c[i]=b[i][j][k];
                //cout<<c[i]<<" ";
            }
            sum=max(sum,kad(c,n));
        }
    }
    cout<<sum<<endl;

}
