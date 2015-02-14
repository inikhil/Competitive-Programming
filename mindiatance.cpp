#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

struct points{
    double x;
    double y;
};

bool byvalue(points p,points q){
    return p.y<q.y;
}

void findintmin(points *p,int i,int j,double &t){
    int m=(j-i)/2;
    if(j<=i){return;}
    if(m==i||m==j){return;}
    double x1,x2,x3,y1,y2,y3,v;
    x1=p[m-1].x;x2=p[m].x;x3=p[m+1].x;
    y1=p[m-1].y;y2=p[m].y;y3=p[m+1].y;
    v=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))+sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))+sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    t=min(t,v);
    findintmin(p,i,m,t);
    findintmin(p,m,j,t);
}


int main(){
    int nt,n,i,j;
    scanf("%d",&nt);
    for(i=1;i<=nt;i++){
        scanf("%d",&n);
        points *p=new points[n];
        for(j=0;j<n;j++){
            scanf("%lf",&p[j].x);
            scanf("%lf",&p[j].y);
        }
        sort(p,p+n,byvalue);
        double t=(double)INT_MAX;
        findintmin(p,0,n-1,t);
        printf("Case %d: %.6lf",i,t);
    }

}
