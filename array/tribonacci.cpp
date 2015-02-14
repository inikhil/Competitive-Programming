#include<iostream>
#include<cstdio>
using namespace std;
int m=1000000007;

int** mult(int **a,int **b){
    int i,j,k;
    int **c=new int*[3];
    for(i=0;i<3;i++){
        c[i]=new int[3];
    }
    long long t;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j]=0;
            for(k=0;k<3;k++){
                t=(long long)a[i][k]*b[k][j];t=t%m;
                t=t+c[i][j];t=t%m;
                c[i][j]=t;
            }
        }
    }
    return c;
}

int** powc(int **a,int n){
    int i,j;
    if(n==1){
        return a;
    }
    int **c=new int*[3];
    for(i=0;i<3;i++){
        c[i]=new int[3];
    }
    c=powc(a,n/2);
    c=mult(c,c);
    if(n%2==0){return c;}
    return mult(c,a);
}

int main(){
    int i,j;
    int **a=new int*[3];
    for(i=0;i<3;i++){
        a[i]=new int[3];
    }
    int **b;
    a[0][0]=1;a[0][1]=1;a[0][2]=0;
    a[1][0]=1;a[1][1]=0;a[1][2]=1;
    a[2][0]=1;a[2][1]=0;a[2][2]=0;
    int n;
    cin>>n;
    b=powc(a,n);
    cout<<b[1][0]<<" ";
}
