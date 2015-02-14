#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;



void getRow(int rowIndex) {
        int i,j,n,t;
        vector<int> m;
        for(i=0;i<=rowIndex;i++){
            if(i==0){m.push_back(1);}
            else{m.push_back(0);}
        }
        for(i=0;i<=rowIndex;i++){
            n=1;
            for(j=1;j<i;j++){
                t=m[j];
                m[j]=n+t;
                n=t;
            }
            m[j]=1;
        }
    for(i=0;i<=rowIndex;i++){cout<<m[i]<<" ";}
}

int main(){
    int n;
    cin>>n;
    getRow(n);
}
