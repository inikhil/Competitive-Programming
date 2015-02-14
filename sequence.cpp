#include<iostream>
#include<cstdio>
using namespace std;

long long**** func(int p,int q,int r,int s){
    int i,j,k,l;
    long long ****a=new long long***[p];
    for(i=0;i<p;i++){
        a[i]=new long long **[q];
        for(j=0;j<q;j++){
            a[i][j]=new long long*[r];
            for(k=0;k<r;k++){
                a[i][j][k]=new long long[s];
                for(l=0;l<s;l++){
                    a[i][j][k][l]=0;
                }
            }
        }
    }
    return a;
}

int main(){
    int p,q,r,s;
    int i,j,k,l;
    cin>>i>>j>>k>>l;
    int m=1000000007;
    long long ****a,****b,****c,****d;
    a=func(i+1,j+1,k+1,l+1);b=func(i+1,j+1,k+1,l+1);c=func(i+1,j+1,k+1,l+1);d=func(i+1,j+1,k+1,l+1);
    a[1][0][0][0]=1;
    b[0][1][0][0]=1;
    c[0][0][1][0]=1;
    d[0][0][0][1]=1;
    for(p=0;p<=i;p++){
        for(q=0;q<=j;q++){
            for(r=0;r<=k;r++){
                for(s=0;s<=l;s++){
                    if(p+q+r+s>1){
                        if(p>0){a[p][q][r][s]=(((a[p][q][r][s] + b[p-1][q][r][s])%m + c[p-1][q][r][s])%m + d[p-1][q][r][s])%m;}
                        if(q>0){b[p][q][r][s]=(((b[p][q][r][s] + a[p][q-1][r][s])%m + c[p][q-1][r][s])%m + d[p][q-1][r][s])%m;}
                        if(r>0){c[p][q][r][s]=(((c[p][q][r][s] + a[p][q][r-1][s])%m + b[p][q][r-1][s])%m + d[p][q][r-1][s])%m;}
                        if(s>0){d[p][q][r][s]=(((d[p][q][r][s] + a[p][q][r][s-1])%m + b[p][q][r][s-1])%m + c[p][q][r][s-1])%m;}
                    }
                }
            }
        }
    }
    p=i;q=j;r=k;s=l;
    cout<<a[p][q][r][s]<<" "<<b[p][q][r][s]<<" "<<c[p][q][r][s]<<" "<<d[p][q][r][s];
    delete []a;
}
