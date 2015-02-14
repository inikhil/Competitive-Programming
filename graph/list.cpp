#include<iostream>
#include<list>

using namespace std;

int main(){
    int n;cin>>n;
    int i,p,q,k;
    list<int> *a=new list<int>[n];
    for(i=0;i<10;i++){
        cin>>p>>q;
        a[p].push_back(q);
    }
    list<int>::iterator j;
    for(i=0;i<n;i++){
        cout<<i<<":: ";
        for(j=a[i].begin();j != a[i].end();j++){
            cout<<*j<<"->";
        }
        cout<<"\n";
    }
}
