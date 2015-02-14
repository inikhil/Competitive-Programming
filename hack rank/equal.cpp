#include<iostream>
using namespace std;
int ii=0;
int diff(int* a,int k){
    int i,m=0;
    double t;
    t=a[0];
    for(i=0;i<k;i++){
        if(a[i]>m){
            m=a[i];
            ii=i;
        }
        if(a[i]<t){
            t=a[i];
        }
    }
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
    int j,t,i,m,d=0,cunt=0,jj=0;
    int *a=new int[k];
    for(j=0;j<k;j++){
        cin>>a[j];
    }
    while(d!=1){
        m=diff(a,k);
        if(m==0){
            cout<<cunt<<endl;
            d=1;
        }
        for(j=0;j<k;j++){
            if(j!=ii){
                if(m>=5){
                   // jj=m/5;
                    a[j]=a[j]+5;
                }
                if((m<5)&&(m>=2)){
                    //jj=m/2;
                    a[j]=a[j]+2;
                }
                if((m<2)&&(m==1)){
                    //jj=1;
                    a[j]=a[j]+1;
                }
            }
        }
        cunt=cunt+1;
        //print(a,k);
    }
    delete a;
}
int main(){
    int notest,i,k;
    cin>>notest;
    for(i=0;i<notest;i++){
        cin>>k;
        if(k==0){
            cout<<0;
        }
        else{
            solve(k);
        }
    }
    return 0;
}

