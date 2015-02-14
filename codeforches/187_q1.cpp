#include<iostream>
using namespace std;
int* op1(int* a){
    int i,j;
    cin>>i;
    cin>>j;
    a[i-1]=j;
    return a;
}
int* op2(int* a,int n){
    int i,j;
    cin>>i;
    for(j=0;j<n;j++){
        a[j]=a[j]+i;
    }
    return a;
}
void op3(int *a){
    int i;
    cin>>i;
    cout<<a[i-1]<<endl;
}
int main(){
    int n,m,i,op;
    cin>>n;
    cin>>m;
    int *a= new int[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<m;i++){
        cin>>op;
        if(op==1){
            a=op1(a);
        }
        if(op==2){
            a=op2(a,n);
        }
        if(op==3){
            op3(a);
        }
    }
    return 0;
}
