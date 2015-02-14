#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int ***b, int m ,int n){
    int i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                cout<<b[i][j][k]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}

int main() {
    int n,m,i,j,k;
    cin>>n>>m;
    int **a=new int*[m];
    for(i=0;i<m;i++){
        a[i]=new int[n];
        for(j=0;j<n;j++){cin>>a[i][j];}
    }
    int ***b=new int**[m];
    for(i=0;i<m;i++){
        b[i]=new int*[n];
        for(j=0;j<n;j++){
            b[i][j]=new int[n];
            for(k=0;k<n;k++){
                b[i][j][k]=0;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){b[i][j][j]=a[i][j];}
        for(k=1;k<n;k++){
            for(j=0;j<n-k;j++){
                b[i][j][j+k]=b[i][j][j+k-1]+b[i][j+1][j+k]-b[i][j+1][j+k-1];
            }
        }
    }
    cout<<"\n";
    //print (b,m,n);
    int *c=new int[n];
    for(i=0;i<n;i++){
        c[i]=b[m-1][i][n-1];
        //cout<<c[i]<<" ";
    }
    //cout<<"\n";
    for(k=m-2;k>=0;k--){
        for(j=0;j<n;j++){
            for(i=j;i<n;i++){
                if(i+1<n && j-1>0){
                    c[j]=min(min(b[k][j][i]+b[k+1][i+1][n-1],c[j]),b[k+1][0][j-1]);
                }
                else if(i+1<n){
                    c[j]=min(c[j],b[k][j][i]);
                }
                //cout<<c[j]<<" ";
            }
            //cout<<"\n";
        }
        //for(i=0;i<n;i++){cout<<c[i]<<" ";}
        //cout<<"\n";
    }
    cout<<c[0];

}
