#include "studentManagementProgram header.h"

int main(void)
{
	struct student student[MAX_STUDENT] = {};

	int studentIndex = 0; // 학생 인덱스
	int select;
	bool conti = true; // 계속할지 안할지 파악하는 변수

	while (true)
	{
		system("cls");

		printMenu();
		conti = selectMenu(&select);
		if (conti == false)
		{
			conti = true;
			continue;
		}

		if (select == Exit) // 종료
		{
			break;
		}

		switch (select)
		{
		case Insert:
			studentInsert(student, &studentIndex);
			break;

		case Delete:
			studentDelete(student, &studentIndex);
			break;

		case Search:
			studentSearch(student, &studentIndex);
			break;

		case Output:
			studentOutput(student, &studentIndex);
			break;

		default:
			cout << " 잘못 입력하셨습니다\n" << endl;
		}


		system("pause");
	}

	cout << "\n프로그램을 종료\n" << endl;

	return 0;
}