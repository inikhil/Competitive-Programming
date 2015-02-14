#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //cout<<m<<n;
        int i,j,k;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][j]=INT_MIN;
                    for(k=0;k<m;k++){
                        if(matrix[k][j]==0||matrix[k][j]==INT_MIN){matrix[k][j]==INT_MIN;}
                        else{matrix[k][j]=INT_MAX;}
                    }
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==INT_MIN){
                    for(k=0;k<n;k++){matrix[i][k]=0;}
                    j=n;
                }
                else if(matrix[i][j]==INT_MAX){
                    matrix[i][j]=0;
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }


int main(){
    vector<vector <int> > v;
    int n,m,t;
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++){
        vector<int> row;
        v.push_back(row);
        for(j=0;j<m;j++){
            cin>>t;
            v[i].push_back(t);
        }
    }
    /*for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    setZeroes(v);
}
