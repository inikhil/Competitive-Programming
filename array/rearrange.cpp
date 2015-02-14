#include<iostream>
#include<cstdio>
using namespace std;

void print(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout<<"\n";
}

void rearrange(int *a,int n){
    int i,j,k,t;
    //print(a,n);
    for(i=0;i<n;i++){
        if(i%2==0 && a[i]>0){
           for(j=i+1;j<n;j++){
                if(a[j]<0){break;}
           }
           if(j!=n){
                t=a[j];
                for(k=j;k>i;k--){
                    a[k]=a[k-1];
                }
                a[i]=t;
           }
        }
       // print(a,n);
        if(i%2==1 && a[i]<0){
             for(j=i+1;j<n;j++){
                if(a[j]>0){break;}
           }
           if(j!=n){
                t=a[j];
                for(k=j;k>i;k--){
                    a[k]=a[k-1];
                }
                a[i]=t;
           }
        }
    }

}

int main(){
    int i,n;
    cin>>n;
    int *a=new int[n];
    for(i=0;i<n;i++){scanf("%d",&a[i]);}
   // print(a,n);
    rearrange(a,n);
    print(a,n);
}
