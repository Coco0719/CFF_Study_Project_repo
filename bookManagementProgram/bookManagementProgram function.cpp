#include "bookManagementProgram header.h"

void printMenu(void)
{
	cout << "\n ㅡㅡㅡ 도서 메뉴 선택 ㅡㅡㅡ\n" << endl;
	cout << " 1. 도서 등록" << endl; 
	cout << " 2. 도서 대여" << endl; 
	cout << " 3. 도서 반납" << endl;	
	cout << " 4. 도서 검색" << endl;	
	cout << " 5. 도서 목록" << endl; 
	cout << " 6. 종료" << endl << endl; 

	cout << " 메뉴 선택 >> ";
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

	cout << "\n ㅡㅡㅡ 도서 등록 코너 ㅡㅡㅡ\n" << endl;

	if (*bookIndex == (MAX_BOOK + 1))
	{
		cout << "\n 더 이상 책을 등록할 수 없습니다." << endl << endl;
		(*bookIndex)--;
		return true;
	}

	cout << " 도서 이름 >> ";
	cin.ignore(1024, '\n');
	cin.getline(books[*bookIndex].name, MAX_NAME);

	cout << " 대여 금액 >> ";
	cin >> books[*bookIndex].fee;
	if (cin.fail())
	{
		return false;
	}

	cout << " 도서 번호 >> ";
	cin >> books[*bookIndex].number;
	if (cin.fail())
	{
		return false;
	}

	system("cls");

	cout << "\n\n 도서 이름 >> " << books[*bookIndex].name << endl;
	cout << " 대여 금액 >> " << books[*bookIndex].fee << endl;
	cout << " 도서 번호 >> " << books[*bookIndex].number << endl;
	cout << "\n (1) 최종 등록 (Any) 등록 실패 >> ";
	cin >> confirm;
	if (confirm == 1)
	{
		cout << "\n 최종 등록완료" << endl << endl;
		books[*bookIndex].rented = true; // 대여여부
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

	cout << "\n ㅡㅡㅡ 도서 대여 코너 ㅡㅡㅡ\n" << endl;

	cout << " 대여 도서 >> ";
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

	cout << "\n ㅡㅡㅡ 도서 반납 코너 ㅡㅡㅡ\n" << endl;

	cout << " 반납 도서 >> ";
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
	
	cout << "\n ㅡㅡㅡ 도서 검색 코너 ㅡㅡㅡ\n" << endl;
	
	cout << " 도서 검색 >> ";
	cin.ignore(1024, '\n');
	cin.getline(bookName, MAX_NAME);

	for (int i = 0; i < *bookIndex + 1; i++)
	{
		if (strcmp(books[i].name, bookName) == 0)
		{
			cout << endl << " \"" << bookName << "\" 검색 완료";
			if (books[i].rented == true)
			{
				cout << "(대여 가능)" << endl << endl;
			}
			else
			{
				cout << "(대여 불가능)" << endl << endl;
			}
			return true;
		}
	}
	return false;
}

bool outputList(book books[], int *bookIndex)
{
	system("cls");

	cout << "\n ㅡㅡㅡ 도서 리스트 ㅡㅡㅡ\n" << endl;

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
	
	cout << endl << " 도서 수 >> " << (*bookIndex) + 1 << endl << endl;
	return true;
}