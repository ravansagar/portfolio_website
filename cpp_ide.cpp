#include<iostream>
#include<fstream>
using namespace std;
fstream out;
int main(){
    string x;
    cout<<"Write Your C code here"<<endl<<"[+]When your program is finished click \'\\\$=\' and press enter to save it<<endl;
    getline(cin,x,'=');
    out.open("file.c++",ios::out|ios::trunc);
    out<<x;
    out.close();
    out.open("file.cpp", ios::in);
    getline(out,x,'$');
    system("G++ file.pp -o file.exe");
    system("./file.exe");
    out.close();
    return 0;
}
