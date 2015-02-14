#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;
char * itoa1(int i) {
        char * res = (char *)malloc(8*sizeof(int));
        sprintf(res, "%d", i);
        return res;
    }


void func(vector <string> &tokens){
    int i,a,b,c;
    //for(i=0;i<tokens.size();i++){cout<<tokens[i]<<" ";}
    stack<string> s1;
    string x,y;
    const char *p,*q;
    char r[10];
    for(i=0;i<tokens.size();i++){
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
            s1.push(tokens[i]);
        }
        else{
            x=s1.top();p=x.c_str();s1.pop();a=atoi(p);
            y=s1.top();q=y.c_str();s1.pop();b=atoi(q);
            if(tokens[i]=="+"){c=a+b;}
            else if(tokens[i]=="*"){c=a*b;}
            else if(tokens[i]=="-"){c=a-b;}
            else if(tokens[i]=="/"){c=b/a;}
            //itoa(c,r,10);
            p=itoa1(c);
            //cout<<r;
            s1.push(p);
        }
    }
    x=s1.top();p=x.c_str();s1.pop();a=atoi(p);
    cout<<a;
}
int evalRPN(vector<string> &tokens) {
        int i,a,b,c;
        stack<const char*> s1;
        const char *p,*q;
        char r[10];
        for(i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                s1.push(tokens[i].c_str());
            }
            else{
                p=s1.top();s1.pop();a=atoi(p);
                q=s1.top();s1.pop();b=atoi(q);
                if(tokens[i]=="+"){c=a+b;}
                else if(tokens[i]=="*"){c=a*b;}
                else if(tokens[i]=="-"){c=a-b;}
                else if(tokens[i]=="/"){c=b/a;}
                //cout<<c;
                p=itoa1(c);
                s1.push(p);
            }
        }
        p=s1.top();s1.pop();a=atoi(p);
        cout<<a;
        //return a;
    }



int main(){
    int i;
    vector <string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    //for(i=0;i<tokens.size();i++){cout<<tokens[i]<<" ";}
    //func(tokens);
    evalRPN(tokens);
    //for(i=0;i<tokens.size();i++){cout<<tokens[i]<<" ";}
}
