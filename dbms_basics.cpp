#include<iostream>
#include<vector>
using namespace std;
int myfunc(int i){
    return i;
}
double myfunc(double i){
    return i;
}
string myfunc(string i){
    return i;
}
char myfunc(char i){
    return i;
}
template <class Type> void type_return(Type a)
{
    return a;
}

class Tuple{
    public:
        int tuple_no;

};

class Row{
    public:
        int num;
        vector <Tuple> tuples;
};

class Table{
    public:
        string name;
        vector <Row> rows;
};


class Database{
    public:
        string name;
        vector <Table> tables;
};

int main(){
    Database nik;
    nik.name ="xyz";
    Table abc;
    abc.name="ady";
    nik.tables.push_back(abc);
    Row r0;
    r0.num=34;
    //r0.num_tup[0]=23;r0.num_tup[1]=14;
    //r0.str_tup[0]="abc";r0.str_tup[1]="xyz";r0.str_tup[2]="uvw";
    //abc.rows.push_back(r0);
    //cout<<abc.rows[0].num;
    //cout<<nik.tables[0].rows[0].num;
    //cout<<r0.str_tup[0];
    //cout<<abc.name;
    cout<<myfunc(34)<<endl;
    cout<<myfunc(34.778)<<endl;
    cout<<myfunc("dgshfvdufv")<<endl;
}
