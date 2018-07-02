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
				cout << "\n ����� �����߽��ϴ�." << endl << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				books[bookIndex] = initBook; // å �ʱ�ȭ
				bookIndex--;

				errorVar = true;
			}
			break;
		
		case Rent:
			errorVar = rentBook(books, &bookIndex);
			if (errorVar == true)
			{
				cout << endl << " �뿩 �Ϸ�" << endl << endl;
			}
			else
			{
				cout << endl << " �뿩 ����" << endl << endl;
				errorVar = true;
			}
			break;

		case Return:
			errorVar = returnBook(books, &bookIndex);
			if (errorVar == true)
			{
				cout << endl << " �ݳ� �Ϸ�" << endl << endl;
			}
			else
			{
				cout << endl << " �ٽ� Ȯ���� �ּ���" << endl << endl;
				errorVar = true;
			}
			break;

		case Search:
			errorVar = searchBook(books, &bookIndex);
			if (errorVar == false)
			{
				cout << endl << " å�� �������� �ʽ��ϴ�." << endl << endl;
				errorVar = true;
			}
			break;

		case ListOutput:
			errorVar = outputList(books, &bookIndex);
			if (errorVar == false)
			{
				cout << endl << " ���� �� >> 0" << endl << endl;
				errorVar = true;
			}
			break;

		default:
			cout << "\n �߸� �Է��ϼ̽��ϴ�." << endl << endl;
		}

		system("pause");
	}

	cout << "\n ���α׷� ����" << endl << endl;

	return 0;
}