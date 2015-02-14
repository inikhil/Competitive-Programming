#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct xy{
    int x;
    int y;
};

bool byval(xy c,xy d){
    return (c.x<d.x);
}

int main(){
    int i,t;
    vector<xy> a;
    for(i=10;i>=0;i--){
        t=rand()%10;
        a.push_back({i,t});
    }
    for(i=0;i<11;i++){
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
    sort(a.begin(),a.end(),byval);
    cout<<"\n";
    for(i=0;i<11;i++){
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
    a.erase(a.begin()+5);
    cout<<"\n";
    for(i=0;i<11;i++){
        cout<<a[i].x<<" "<<a[i].y<<endl;
    }
}
