#include<iostream>
using namespace std;

int part(int *a,int p,int r){
    int x=a[r];
    int i=p-1,j;
    for(j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;

}

void quicksort(int *a, int p,int r){
    if(p<r){
        int q=part(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}

void printlist(int *a,int n){
    int i;
    for(i=0;i<n;i++){cout<<a[i]<<" ";}
}

int main(){
    int n,i;
    cin>>n;
    int *a=new int[n];
    for(i=0;i<n;i++){cin>>a[i];}
    quicksort(a,0,n-1);
    printlist(a,n);
}
