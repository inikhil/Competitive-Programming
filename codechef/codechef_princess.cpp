#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
    int nt,n,i,j,t=0,k,j1,k1;
    double prob;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>n;
        t=0;
        prob=0;
        int *a=new int[n];
        int *p=new int[n];
        for(j=0;j<n;j++){
            cin>>a[j];
            t=t+a[j];
        }
        for(j=0;j<n;j++){
            cin>>p[j];
        }
        k=pow(2.0,n+1)-2;
       // cout<<k<<endl;
        double *b=new double[k];
        double *c=new double[k];
        b[0]=(double)p[0]/100;
        //cout<<b[0]<<" ";
        b[1]=1-b[0];
        //cout<<b[1]<<" ";
        c[0]=a[0];
        //cout<<c[0]<<" ";
        c[1]=0;
        //cout<<c[1]<<endl;
        for(j=1;j<n;j++){
            //cout<<"sdf"<<endl;
            k=pow(2.0,j+1)-2;
            //cout<<k<<" ";
            k1=pow(2.0,j+2)-2;
            //cout<<k1<<" "<<endl;
            for(j1=k;j1<k1;j1=(j1+2)){
                b[j1]=b[j1/2-1]*(double)p[j]/100;
               // cout<<b[j1]<<" ";
                b[j1+1]=b[(j1+1)/2-1]*(1-(double)p[j]/100);
                //cout<<b[j1+1]<<" ";
                c[j1]=c[j1/2-1]+a[j];
                //cout<<c[j1]<<" ";
                c[j1+1]=c[j1/2-1];
                //cout<<c[j1+1]<<endl;
            }
           // cout<<"\n";
        }
       // cout<<"xzcds"<<endl;
        k=pow(2.0,n)-2;
        k1=pow(2.0,n+1)-2;
        //cout<<k<<endl;
        for(j=k;j<k1;j++){
            if(((double)c[j]/t)>=0.5){
                prob+=b[j];
            }
        }
        printf("%0.7f",prob);
        delete[] a;
        delete[] b;
        delete[] c;
        delete[] p;
    }
}
