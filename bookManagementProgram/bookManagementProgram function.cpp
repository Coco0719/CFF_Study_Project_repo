#include "bookManagementProgram header.h"

void printMenu(void)
{
	cout << "\n �ѤѤ� ���� �޴� ���� �ѤѤ�\n" << endl;
	cout << " 1. ���� ���" << endl; 
	cout << " 2. ���� �뿩" << endl; 
	cout << " 3. ���� �ݳ�" << endl;	
	cout << " 4. ���� �˻�" << endl;	
	cout << " 5. ���� ���" << endl; 
	cout << " 6. ����" << endl << endl; 

	cout << " �޴� ���� >> ";
}

bool selectMenu(int *select)
{
	cin >> *select;

	if (cin.fail())
	{	
		cin.clear();
		cin.ignore(1024, '\n');

		return false;
	}
	return true;
}

bool registerBook(book books[], int *bookIndex) 
{
	system("cls");

	struct book initBook = {};
	int confirm;
	
	(*bookIndex)++;

	cout << "\n �ѤѤ� ���� ��� �ڳ� �ѤѤ�\n" << endl;

	if (*bookIndex == (MAX_BOOK + 1))
	{
		cout << "\n �� �̻� å�� ����� �� �����ϴ�." << endl << endl;
		(*bookIndex)--;
		return true;
	}

	cout << " ���� �̸� >> ";
	cin.ignore(1024, '\n');
	cin.getline(books[*bookIndex].name, MAX_NAME);

	cout << " �뿩 �ݾ� >> ";
	cin >> books[*bookIndex].fee;
	if (cin.fail())
	{
		return false;
	}

	cout << " ���� ��ȣ >> ";
	cin >> books[*bookIndex].number;
	if (cin.fail())
	{
		return false;
	}

	system("cls");

	cout << "\n\n ���� �̸� >> " << books[*bookIndex].name << endl;
	cout << " �뿩 �ݾ� >> " << books[*bookIndex].fee << endl;
	cout << " ���� ��ȣ >> " << books[*bookIndex].number << endl;
	cout << "\n (1) ���� ��� (Any) ��� ���� >> ";
	cin >> confirm;
	if (confirm == 1)
	{
		cout << "\n ���� ��ϿϷ�" << endl << endl;
		books[*bookIndex].rented = true; // �뿩����
		return true;
	}
	else
	{
		return false;
	}
}

bool rentBook(book books[], int *bookIndex)
{
	system("cls");

	char bookName[MAX_NAME];

	cout << "\n �ѤѤ� ���� �뿩 �ڳ� �ѤѤ�\n" << endl;

	cout << " �뿩 ���� >> ";
	cin.ignore(1024, '\n');
	cin.getline(bookName, MAX_NAME);
	
	for (int i = 0; i <= *bookIndex; i++)
	{
		if (strcmp(bookName, books[i].name) == 0)
		{
			if (books[i].rented == false)
			{
				return false;
			}
			books[i].rented = false;
			return true;
		}
	}

	return false;
}

bool returnBook(book books[], int *bookIndex)
{
	system("cls");

	char bookName[MAX_NAME] = {};

	cout << "\n �ѤѤ� ���� �ݳ� �ڳ� �ѤѤ�\n" << endl;

	cout << " �ݳ� ���� >> ";
	cin.ignore(1024, '\n');
	cin.getline(bookName, MAX_NAME);

	for (int i = 0; i < *bookIndex + 1; i++)
	{
		if (strcmp(bookName, books[i].name) == 0)
		{
			if (books[i].rented == true)
			{
				return false;
			}
			books[i].rented = true;
			return true;
		}
	}
	return false;
}

bool searchBook(book books[], int *bookIndex)
{
	system("cls");
	
	char bookName[MAX_NAME] = {};
	
	cout << "\n �ѤѤ� ���� �˻� �ڳ� �ѤѤ�\n" << endl;
	
	cout << " ���� �˻� >> ";
	cin.ignore(1024, '\n');
	cin.getline(bookName, MAX_NAME);

	for (int i = 0; i < *bookIndex + 1; i++)
	{
		if (strcmp(books[i].name, bookName) == 0)
		{
			cout << endl << " \"" << bookName << "\" �˻� �Ϸ�";
			if (books[i].rented == true)
			{
				cout << "(�뿩 ����)" << endl << endl;
			}
			else
			{
				cout << "(�뿩 �Ұ���)" << endl << endl;
			}
			return true;
		}
	}
	return false;
}

bool outputList(book books[], int *bookIndex)
{
	system("cls");

	cout << "\n �ѤѤ� ���� ����Ʈ �ѤѤ�\n" << endl;

	if (*bookIndex == -1)
	{
		return false;
	}


	for (int i = 0; i < *bookIndex + 1; i++)
	{
		cout << " " << (i + 1) << ". " << books[i].name;
		if (books[i].rented == true)
		{
			cout << "(T)" << endl;
		}
		else
		{
			cout << "(F)" << endl;
		}
	}
	
	cout << endl << " ���� �� >> " << (*bookIndex) + 1 << endl << endl;
	return true;
}