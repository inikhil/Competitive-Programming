#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;

void solve(vector<int> a){

    char *single_digits[] = { "zero", "one", "two", "three", "four",
                              "five", "six", "seven", "eight", "nine"};

    char *two_digits[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

    char *tens_power[] = {"hundred", "thousand","lakhs","crore"};

    int i;
    int m=a.size()-1;
    int t;
    for(i=m;i>=0;i--){
        if(i%2!=0 && i>2){
            cout<<single_digits[a[i]]<<" ";
            cout<<tens_power[i/2]<<" ";
        }
        else if(i%2==0 && i>2){
            if(a[i]!=1 && a[i]!=0){
                cout<<tens_multiple[a[i]]<<" ";
                if(a[i-1]!=0){cout<<single_digits[a[i-1]]<<" ";}
                cout<<tens_power[i/2-1]<<" ";
                i--;
            }
            else if(a[i]==1){
                t=a[i]*10+a[i-1];
                cout<<two_digits[t-9]<<" ";
                cout<<tens_power[i/2-1]<<" ";
                i--;
            }
            else{
                if(a[i-1]!=0){
                   cout<<single_digits[a[i-1]]<<" ";
                   cout<<tens_power[i/2-1]<<" ";
                }
                i--;
            }
        }
        else if(i==2){
            if(a[i]!=0){
                cout<<single_digits[a[i]]<<" "<<tens_power[i/2-1];
            }
        }
        else{
            if(a[i]!=1 && a[i]!=0){
                cout<<" and "<<tens_multiple[a[i]]<<" ";
                if(a[i-1]!=0){cout<<single_digits[a[i-1]]<<" ";}
                i--;
            }
            else if(a[i]==1){
                t=a[i]*10+a[i-1];
                cout<<" and "<<two_digits[t-9]<<" ";
                i--;
            }
            else{
                if(a[i-1]!=0){
                   cout<<" and "<<single_digits[a[i-1]]<<" ";
                }
                i--;
            }
        }
    }
}

int main(){
    int n,i;
    cin>>n;
    vector<int> a;
    while(n!=0){
        a.push_back(n%10);
        n=n/10;
    }
    solve(a);
}
