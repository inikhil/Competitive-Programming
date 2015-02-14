#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void generate1(int numrows) {
        vector<vector <int> > vec;
        int i,j;
        for(i=0;i<numrows;i++){
            vector<int> row;
            vec.push_back(row);
            for(j=0;j<=i;j++){
                if(j==0||j==i){
                    vec[i].push_back(1);
                }
                else{
                    vec[i].push_back(vec[i-1][j]+vec[i-1][j-1]);
                }
            }
        }
        for(i=0;i<numrows;i++){
            for(j=0;j<vec[i].size();j++){
                cout<<vec[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
int main(){
    int n;cin>>n;
    generate1(n);
}
