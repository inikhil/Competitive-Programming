#include<iostream>
using namespace std;
int main(){
    int nt,i,u,n,j,k,jj;
    double d,t;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>d>>u>>n;
        double **a=new double*[n];
        double *b= new double[n+1];
        b[0]=d*u;
        for(j=0;j<n;j++){
            a[j]=new double[3];
        }
        for(k=0;k<n;k++){
            for(j=0;j<3;j++){
                cin>>a[k][j];
            }
        }
        for(j=1;j<=n;j++){
            t=a[j-1][0]*u*a[j-1][1]+a[j-1][2];
            b[j]=(double)t/a[j-1][0];
           //cout<<b[j]<<" ";
        }
        t=100010;
       // cout<<"\n";
        for(j=0;j<=n;j++){
            if(b[j]<t){
                t=b[j];
               // cout<<t<<" ";
                jj=j;
            }
        }
       // cout<<"\n";
        cout<<jj<<endl;
        delete[] a;
        delete[] b;
    }
}
