#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
int main(){

for (int i = 0; i < 5; i++){
    int asciiVal = rand()%26 + 97;
    char asciiChar = asciiVal;
    cout << asciiChar << " and ";
}
}
