#include<iostream>
using namespace std;

void func(int *y){
    if(*y<0){return;}
    cout<<*y<<" ";
    //cout<<y<<" ";
    *y = (*y)-1;
    //cout<<*y<<" ";
    func(y);
}

void func1(int **y){
    //cout<<**y;
    if((**y) < -10){return;}
    cout<<**y<<" ";
    **y = (**y) -1;
    func1(y);
}

int main(){
    int x=10;
    //cout<<&x<<" ";
    int *z = &x;
    int **k=&z;
    func(z);cout<<"\n";
    func1(k);
}
