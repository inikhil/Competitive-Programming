#include<iostream>
using namespace std;
int main(){
    int nt,i,j,k,t,l,ans=0,d,n,m,e,j1;
    cin>>nt;
    for(i=0;i<nt;i++){
        cin>>n>>m;
        ans=0;
        int *c=new int[m];
        for(j=0;j<m;j++){
            cin>>c[j];
        }
        int **v= new int*[n];
        for(k=0;k<n;k++){
            cin>>t;
            v[k]=new int[t+1];
            v[k][0]=t;
            for(l=1;l<=t;l++){
                cin>>v[k][l];
            }
        }
        /*for(k=0;k<n;k++){
            for(j=0;j<=v[k][0];j++){
                cout<<v[k][j]<<" ";
            }
            cout<<"\n";
        }*/
        for(k=0;k<m;k++){
            d=c[k];
            e=v[d][0];
            t=0;
            j1=1;
            for(j=1;j<=e;j++){
                if(v[d][j]>t){
                    t=v[d][j];
                    j1=j;
                }
            }
            ans=ans+t;
            v[d][j1]=0;
        }
        cout<<ans<<endl;
        delete[] c;
        delete[] v;
    }
}
