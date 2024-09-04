#include <iostream>
#include <vector>
using namespace std;
class BankAccount
{
private:
	string name;
	int accountnum;
	double balance;
public:
	BankAccount(string n, int acn, double bal) {
		name = n;
		accountnum = acn;
		balance = bal;
	}
	void set_name(string n)
	{
		name = n;
	}
	string get_name()
	{
		return name;
	}
	void set_accountNum(int acn)
	{
		accountnum = acn;
	}
	int get_accountNum()
	{
		return accountnum;
	}
	void set_balance(double bal)
	{
		balance = bal;
	}
	double get_balance()
	{
		return balance;
	}
	void display() 
	{
		cout << " Name: " << name << "\nAccount Number: " << accountnum << "\nBalance: " << balance << endl;
	}
	void Depoist(double amount)
	{
		balance += amount;
	}
	void Withdraw(double amount)
	{
		if (balance >= amount)
		{
			balance -=amount;
			cout << "withdraw oky\n";
		}
		else
		{
			cout << "withdraw not ok\n";
		}
	}
};
class BankManagement
{
private:
	vector<BankAccount> accounts;
public:
	void Add_accout(string name, int accountnum, double balamce)
	{
		accounts.push_back(BankAccount(name , accountnum ,balamce));
	}
	void Show_All_Account()
	{
		cout << "\t\tAccount\n";
		for (int i = 0; i < accounts.size(); i++)
		{
			cout << "\nName: " << accounts[i].get_name() << "\nAccount Number: " << accounts[i].get_accountNum()
				<< "\nBalance: " << accounts[i].get_balance()<<endl;
		}
	}
	void Search_Account(int account)
	{
		for (int i = 0; i < accounts.size(); i++) {
			if (account == accounts[i].get_accountNum())
			{
				cout << "\nName: " << accounts[i].get_name() << "\nAccount Number: " << accounts[i].get_accountNum()
					<< "\nBalance: " << accounts[i].get_balance() << endl;

			}
				cout << "account not found\n";
		}
		
	}
	BankAccount* findaccount(int accountnum)
	{
		for (int i = 0; i < accounts.size(); i++)
		{
			if (accounts[i].get_accountNum() == accountnum)
			{
				return &accounts[i];
			}
		}
	}

};
int main() {
	BankManagement Bank;
	int choice;
	char op;
	do
	{
		system("cls");
	cout << "\t\t:::Bank Management System\n";
	cout << "\t\t----Main Meun----\n";
	cout << "\t\t1-Creat New Account\n";
	cout << "\t\t2-Show All Account\n";
	cout << "\t\t3-Search Account\n";
	cout << "\t\t4-Depoist Money\n";
	cout << "\t\t5-Withdraw Money\n";
	cout << "\t\t6-Exit\n";
	cout << "\t\t------------------\n";
	cout << "\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice) {
		{
	case 1:
		string name;
		int accountnum;
		double balance;
		cout << " enter your name: ";
		cin >> name;
		cout << " enter your account number: ";
		cin >> accountnum;
		cout << " enter balance: ";
		cin >> balance;
		Bank.Add_accout(name, accountnum, balance);
		cout << "\t\tAcvount created Successfully....\n";
		break;
		}
		{
	case 2:
		Bank.Show_All_Account();
		break;
		}
		{
		case 3:
			int accountnum;
			cout << " enetr your account number: ";
			cin >> accountnum;
			Bank.Search_Account(accountnum);
			break;
		}
		{
		case 4:
			int accountnum;
			double amount;
			cout << " Account Number Depoist Money: ";
			cin >> accountnum;
			BankAccount* account = Bank.findaccount(accountnum);
			if (account != NULL)
			{
				cout << " enter amount: ";
				cin >> amount;
				account->Depoist(amount);
				cout << amount << "  depoist ok\n";
			}
			else
			{
				cout << " account not found\n";
			}
			break;
		}
		{
		case 5:
			int accountnum;
			double amount;
			cout << " Account Number Withdraw Money: ";
			cin >> accountnum;
			BankAccount* account = Bank.findaccount(accountnum);
			if (account != NULL)
			{
				cout << " enter amount Withdraw: ";
				cin >> amount;
				account->Withdraw(amount);
				
			}
			else
			{
				cout << " account not found\n";
			}
			break;
		}
		{
		case 6:
			exit(1);
			break;
		}
	default:
		cout << "choice invalid\n";
		
	}
	cout << "Do You Want continue? [YES / NO]:";
	cin >> op;
	} while (op=='y' ||op=='Y');

	return 0;
}