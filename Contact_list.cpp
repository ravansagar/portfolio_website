#include<iostream>
#include<fstream>
#define SIZE 10
using namespace std;
//Created a file I/O
fstream out;
class contacts{
	private:
	int sn[SIZE],c;
	string name[SIZE],adress[SIZE],gmail[SIZE],number[SIZE];
	public:
        void add();
        void edit();
        void delet();
        void view();
}contact[SIZE];
void contacts::add(){
		int i = 0;
	char x,y, choice;
	do
	{
		fflush(stdin);
		sn[i] = i + 1;
		cout << "Enter Name: " << endl;
		getline(cin,name[i]);
		cout << "Enter Number: " << endl;
		cin >> number[i];
		cout << "Enter Gmail: " << endl;
		cin>>gmail[i];
		cout << "Enter Adress: " << endl;
		cin>>adress[i];
		i++;
		c++;
		cout << "Do you want to add more y/n: ";
		cin >> choice;
		system("clear");
	} while (choice == 'y' || choice == 'Y');
	view();
	cout<<"Do you want to delete contact y/n: ";
	cin>>x;
	if(x=='y'||x=='Y')delet();
	cout<<"Do you want to edit contact y/n: ";
	cin>>y;
	if(y=='y'||y=='Y')edit();
	system("clear");
	view();
}
void contacts::edit(){
	int choice,i;
	view();
	cout<<"Enter SN of your contact which you want to edit: ";
	cin>>i;
	cout << "\nEnter what you want to edit\n"
		 << "1. Name\n"
		 << "2. Number\n"
		 << "3. Gmail\n"
		 << "4. Adress\n"
		 << "Enter your choice: ";
	cin >> choice;
	cout <<endl;
	system("clear");
	switch (choice)
	{
		fflush(stdin);
	case 1:
		cout << "Enter Name: " << endl;
		getline(cin,name[i]);
		break;
	case 2:
		cout << "Enter number: " << endl;
		cin >> number[i];
		break;
	case 3:
		cout << "Enter Gmail: " << endl;
		cin >> gmail[i];
		break;
	case 4:
		cout << "Enter Adress: " << endl;
		cin >> adress[i];
		break;
	default:
		cout << "Wrong input!!!";
		break;
	}
	cout << "Editted Successfully\n";
	system("clear");
	view();
}
void contacts::delet()
{
	system("clear");
	int s;
	view();
	cout << "Enter sn of contact which you want to delet: ";
	cin >> s;
	--s;
   --c;
	for (int i = s; i <SIZE; i++)
	{
		name[i] = name[i+1];
		adress[i] = adress[i+1];
		number[i] = number[i+1];
		gmail[i]=gmail[i+1];
	}
	system("clear");
	view();
}
void contacts::view(){
	string x;
	out.open("contacts.txt",ios::out|ios::trunc);
  out<< "Sn. "
		<< "Name"<<"\t"
		<< "Number"<<"\t\t"
		<< "Gmail"<<"\t\t\t"
		<< "Adress\n";
	for (int i = 0; i < c; i++)
	{
	 	out<<sn[i]<< ". "
			<< name[i]<<"\t"
			<<number[i]<<"\t\t"
			<< gmail[i] << "\t\t"
			<< adress[i]<< "\n"; 
			//Here i write comment for $ sign which terminate the reading
	}
	out.close();
	out.open("contacts.txt",ios::in);
      getline(out,x,'$');
      cout<<x;
	out.close();
}
int main(){
	contact[SIZE].add();
	return 0;
}ich terminate the reading
	}
	out.close();
	out.open("contacts.txt",ios::in);
      getline(out,x,'$');
      cout<<x;
	out.close();
}
int main(){
	contact[SIZE].add();
	return 0;
}
