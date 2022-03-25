#include<iostream>
#include<fstream>
using namespace std;
fstream out;
int main(){
	string x;
	cout<<"Write Your C code here"<<endl<<"[+]When your program is finished click \'=\' and press enter to save it<<endl;
	getline(cin,x,'=');
    out.open("file.c",ios::in|ios::out|ios::trunc);
    out<<x;
    system("gcc file.c -o file.exe");
    system("./file.exe");
    return 0;
}