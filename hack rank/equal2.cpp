#include<iostream>
using namespace std;
int max_ind(int *a,int k){
    int i,t=0,m=0;
    for(i=0;i<k;i++){
        if(a[i]>m){
            m=a[i];
            t=i;
        }
    }
    return t;
}
int diff(int* a,int k){
    int i,t=1000,m=0;
    for(i=0;i<k;i++){
        if(a[i]>m){
            m=a[i];
        }
    }
    for(i=0;i<k;i++){
        if(a[i]<t){
            t=a[i];
        }
    }
    cout<<m<<" "<<t<<endl;
    return m-t;
}
void print(int *a,int k){
    int i;
    for(i=0;i<k;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
void solve(int k){
    int j,t,i,m,d=0,cunt=0,jj;
    int *a=new int[k];
    for(j=0;j<k;j++){
        cin>>a[j];
    }
    while(d!=1){
        i=max_ind(a,k);
        m=diff(a,k);
        if(m==0){
            cout<<cunt<<endl;
            d=1;
        }
        for(j=0;j<k;j++){
            if(j!=i){
                if(m>=5){
                    jj=m/5;
                    a[j]=a[j]+5*jj;
                }
                if((m<5)&&(m>=2)){
                    jj=m/2;
                    a[j]=a[j]+2*jj;
                }
                if((m<2)&&(m>=1)){
                    a[j]=a[j]+1;
                }
            }
        }
        cunt=cunt+jj;
        print(a,k);
    }
}
int main(){
    int notest,i,k;
    cin>>notest;
    for(i=0;i<notest;i++){
        cin>>k;
        solve(k);
    }
    return 0;
}



