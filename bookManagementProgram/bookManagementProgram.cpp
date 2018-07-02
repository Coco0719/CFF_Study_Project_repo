#include "bookManagementProgram header.h"

int main(void)
{
	struct book books[MAX_BOOK] = {};
	struct book initBook = {};

	int select;
	int bookIndex = -1;
	bool errorVar = true;
	
	while (true)
	{
		system("cls");
		
		printMenu();
		errorVar = selectMenu(&select);
		if (errorVar == false)
		{
			errorVar = true;
			continue;
		}

		if (select == Exit)
		{
			break;
		}

		switch (select)
		{
		case Register: 
			errorVar = registerBook(books, &bookIndex);
			if (errorVar == false)
			{
				cout << "\n 등록을 실패했습니다." << endl << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				books[bookIndex] = initBook; // 책 초기화
				bookIndex--;

				errorVar = true;
			}
			break;
		
		case Rent:
			errorVar = rentBook(books, &bookIndex);
			if (errorVar == true)
			{
				cout << endl << " 대여 완료" << endl << endl;
			}
			else
			{
				cout << endl << " 대여 실패" << endl << endl;
				errorVar = true;
			}
			break;

		case Return:
			errorVar = returnBook(books, &bookIndex);
			if (errorVar == true)
			{
				cout << endl << " 반납 완료" << endl << endl;
			}
			else
			{
				cout << endl << " 다시 확인해 주세요" << endl << endl;
				errorVar = true;
			}
			break;

		case Search:
			errorVar = searchBook(books, &bookIndex);
			if (errorVar == false)
			{
				cout << endl << " 책이 존재하지 않습니다." << endl << endl;
				errorVar = true;
			}
			break;

		case ListOutput:
			errorVar = outputList(books, &bookIndex);
			if (errorVar == false)
			{
				cout << endl << " 도서 수 >> 0" << endl << endl;
				errorVar = true;
			}
			break;

		default:
			cout << "\n 잘못 입력하셨습니다." << endl << endl;
		}

		system("pause");
	}

	cout << "\n 프로그램 종료" << endl << endl;

	return 0;
}