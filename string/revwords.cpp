#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    char *s=new char[1000];
    int i,j=0;
    gets(s);
    char *p=new char[1000];
    char *q=new char[1000];
    string t;
    p[0]='\0';q[0]='\0';
    for(i=0;i<strlen(s);i++){
        if(s[i]==' '){
            //cout<<p<<endl;
            if(p!='\0' && q=='\0'){strcat(p,q);strcpy(q,p);}
            else if(p!='\0'){strcat(p," ");strcat(p,q);strcpy(q,p);}
            p[0]='\0';j=0;
        }
        else{
            *(p+j)=s[i];*(p+j+1)='\0';
            j++;
        }
    }
    if(p!='\0' && q=='\0'){strcat(p,q);strcpy(q,p);}
    else if(p!='\0'){strcat(p," ");strcat(p,q);strcpy(q,p);}
    //cout<<q<<endl;
    t=q;
    cout<<t<<endl;
}
