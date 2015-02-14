#include<iostream>
#include<cstdio>
using namespace std;

int heapsize=0;
int length=0;

void print(int *a){
    int i;
    for(i=0;i<=length;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void maxheapify(int *a,int i){
    int largest;
    int l=2*i+1;
    int r=2*i+2;
    if(l <= heapsize && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r <= heapsize && a[largest]<a[r])
        largest=r;
    if(largest!=i){
        swap(a[i],a[largest]);
        maxheapify(a,largest);
    }
}

void buildmaxheap(int *a){
    int i;
    heapsize=length;
    for(i=length/2;i>=0;i--)
        maxheapify(a,i);
}

void heapsort(int *a){
    int i;
    buildmaxheap(a);
    for(i=length;i>0;i--){
        //print(a);
        swap(a[i],a[0]);
        heapsize=heapsize-1;
        maxheapify(a,0);
    }
}

int main(){
    int n,i;
    cin>>n;
    length=n-1;
    int *a=new int[n];
    for(i=0;i<=length;i++){
        cin>>a[i];
    }
    heapsort(a);
    print(a);
}
