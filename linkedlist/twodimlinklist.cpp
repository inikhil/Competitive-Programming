#include<iostream>
#include<cstdlib>
using namespace std;

class link{
public:
    int val;
    link *right;
    link *down;
    link(int d,link *p,link *q){val=d;right=p;down=q;}
};

int main(){
    int n,d,m,i,j;
    cout<<"Print the length of the main link list: \n";
    cin>>n;
    link *a,*b,*c, *e;
    cout<<"Print the numbers you want to insert: \n";
    cin>>d;
    a=new link(d,0,0);
    b=a;e=a;
    for(i=0;i<n-1;i++){
        cin>>d;
        c=new link(d,0,0);
        a->right=c;
        a=a->right;
    }
    a=b;
    for(i=0;i<n;i++){
        cout<<"How many numbers you want to insert in "<<i<<" place list\n";
        cin>>m;
        cout<<"Print the numbers: \n";
        cin>>d;
        c=new link(d,0,0);
        e->down=c;
        a=e->down;
        for(j=0;j<m-1;j++){
            cin>>d;
            c=new link(d,0,0);
            a->down=c;
            a=a->down;
        }
        e=e->right;
    }
    for(i=0;i<n;i++){
        e=b;
        while(e!= NULL){
            cout<<e->val<<"->";
            e=e->down;
        }
        cout<<"\n|\n";
        b=b->right;
    }

}
