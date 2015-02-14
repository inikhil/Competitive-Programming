#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
# define m 100000001

struct index{
    char c;
    int in;
};

bool sortbyin(index a, index b){
    return a.in<b.in;
}

int main(){
    int nt,n,i,j,cnt;
    char prev;
    cin>>nt;
    while(nt--){
        cin>>n;
        index *a=new index[2*n];
        for(i=0;i<2*n;i=(i+2)){
            cin>>a[i].in;a[i].c='a';
            cin>>a[i+1].in;a[i+1].c='b';
        }
        int *b=new int[m];
        for(i=0;i<m;i++){b[i]=0;}
        sort(a,a+2*n,sortbyin);
        //for(i=0;i<2*n;i++){cout<<a[i].in<<" "<<a[i].c<<endl;}
        prev='a';cnt=0;
        for(j=1,i=0;j<m;j++){
            if(i<2*n && j==a[i].in){
                if(prev=='a'){
                    if(a[i].c=='a'){
                        cnt=cnt+1;
                        b[j]=cnt%2;
                        i++;
                    }
                    else if(a[i].c=='b'){
                        b[j]=cnt%2;
                        i++;
                        prev='b';
                        cnt=(cnt+1)%2;
                    }
                }
                else if(prev=='b'){
                    if(a[i].c=='a'){
                        b[j]=cnt%2;
                        i++;
                        prev='a';
                    }
                    else if(a[i].c=='b'){
                        cnt=cnt-1;
                        b[j]=cnt%2;
                        i++;
                    }
                }
            }
            else if(i==2*n){
                b[j]=0;
            }
            else{
                b[j]=b[j-1];
            }
        }
        for(j=1;j<20;j++){cout<<b[j];}
    }
}
