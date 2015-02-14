#include<iostream>
#include<fstream>
using namespace std;
ifstream myfile;
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
    int i,t=10000000,m=0;
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
    //cout<<m<<" "<<t<<endl;
    return m-t;
}
void print(int *a,int k){
    int i;
    for(i=0;i<k;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
int solve(int k){
    int j,t,i,m,d=0,cunt=0,jj;
    int *a=new int[k];
    for(j=0;j<k;j++){
        myfile>>a[j];
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
                    //jj=m/5;
                    a[j]=a[j]+5;
                }
                if((m<5)&&(m>=2)){
                    //jj=m/2;
                    a[j]=a[j]+2;
                }
                if((m<2)&&(m>=1)){
                    //jj=1;
                    a[j]=a[j]+1;
                }
            }
        }
        cunt=cunt++;
    }
}
int main(){
    int notest,i,k;
    myfile.open("equal1.txt");
    myfile>>notest;
    for(i=0;i<notest;i++){
        myfile>>k;
        solve(k);
    }
    return 0;
}


