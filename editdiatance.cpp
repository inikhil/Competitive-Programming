#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int dist(string x,string y, int n,int m){
    if(n==0 && m==0){return 0;}
   // else if(n==0){return m;}
   // else if(m==0){return n;}
    int R=5,I=5,D=5;
    int i,j;
    int **a=new int*[n+1];
    for(i=0;i<=n;i++){a[i]=new int[m+1];}
    for(i=0;i<=n;i++){a[i][0]=i*R;}
    for(j=0;j<=m;j++){a[0][j]=j*R;}
    int ins,del,rep;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            del=a[i-1][j]+D;
            ins=a[i][j-1]+I;
            if(x[i-1]==y[j-1]){rep=a[i-1][j-1];}
            else{rep=a[i-1][j-1]+R;}
            a[i][j]=min(min(del,ins),rep);
            //cout<<a[i][j]<<" ";
        }
    }
    /*for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return a[n][m];
}

int main(){
    string x,y;
    //string x,y;
    int n,m;
    //scanf("%s %s",x,y);
    getline(cin, x);
    //getchar();
    //gets(x);
    //gets(y);
    if (x.find (' ') == string::npos)
        getline(cin, y);
   else{
        y = x.substr(x.find (' ')+1, string::npos);
        x = x.substr(0, x.find (' '));
   }
   cout<<y<<" "<<x<<endl;
    n=x.length();
    //cout<<n<<" ";
    //m=strlen(y);
    m=y.length();
    //cout<<m<<" ";
    cout<<dist(x,y,n,m);
}
