#include <iostream>
#include <fstream>
using namespace std;
//Created A class
class contact
{
  public:
	string name, addrs, gmail, nmbr;
	int sn;
} c1[10];
//Created File I/O variable
fstream out;
void add();
void edit(int);
void view(int);
void delet(int);
int main()
{
	add();
	return 0;
}
//Function for add contacts
void add()
{
	int i = 0, c = 0;
	char x, y, choice;
	do
	{
		fflush(stdin);
		c1[i].sn = i + 1;
		cout << "Enter Name: " << endl;
		getline(cin, c1[i].name);
		cout << "Enter Number: " << endl;
		cin >> c1[i].nmbr;
		cout << "Enter Gmail: " << endl;
		cin >> c1[i].gmail;
		cout << "Enter Adress: " << endl;
		cin >> c1[i].addrs;
		i++;
		c++;
		cout << "Do you want to add more y/n: ";
		cin >> choice;
		if (i == 9)
			break;
	} while (choice == 'y' || choice == 'Y');
	view(c);
	cout << "\nDo you want to edit y/n: ";
	cin >> x;
	if (x == 'Y' || x == 'y')
		edit(c);
	cout << "\nDo you want to delet contact y/n: ";
	cin >> y;
	if (y == 'Y' || y == 'y')
		delet(c);
}
//function for edit contact information
void edit(int c)
{
	int choice;
	cout << "\nEnter what you want to edit\n"
		 << "1. Name\n"
		 << "2. Number\n"
		 << "3. Gmail\n"
		 << "4. Adress\n"
		 << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
		fflush(stdin);
	case 1:
		cout << "Enter Name: " << endl;
		cin >> c1[0].name;
		break;
	case 2:
		cout << "Enter number: " << endl;
		cin >> c1[0].nmbr;
		break;
	case 3:
		cout << "Enter Gmail: " << endl;
		cin >> c1[0].gmail;
		break;
	case 4:
		cout << "Enter Adress: " << endl;
		cin >> c1[0].addrs;
		break;
	default:
		cout << "Wrong input!!!";
		break;
	}
	cout << "Editted Successfully\n";
	view(c);
}
//function for delet contact from contact list
void delet(int c)
{
	int sn;
	view(c);
	cout << "Enter sn of contact which you want to delet: ";
	cin >> sn;
	--sn;
	--c;
	for (int i = sn; i < 10; i++)
	{
		c1[i] = c1[i + 1];
		c1[i].sn = --c1[i].sn;
	}
	view(c);
}
//function for view contact info. and write it on file
void view(int c)
{
	string get_from_file;
	out.open("My_contacts.txt", ios::out | ios::trunc);
	out << "Sn. "
		<< "Name \t"
		<< "Number\t\t"
		<< "Gmail\t\t\t"
		<< "Adress\n";
	for (int i = 0; i < c; i++){
		out << c1[i].sn << ". "
			<< c1[i].name << "\t"
			<< c1[i].nmbr << "\t"
			<< c1[i].gmail << "\t"
			<< c1[i].addrs << "\n";
	}
//Here i write comment for $ sign which terminate the reading
	out.close();
    out.open("My_contacts.txt", ios::in);
     getline(out,get_from_file,'$' );
     cout<<get_from_file;
     out.close();
}