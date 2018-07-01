#include "studentManagementProgram header.h"

int main(void)
{
	struct student student[MAX_STUDENT] = {};

	int studentIndex = 0; // �л� �ε���
	int select;
	bool conti = true; // ������� ������ �ľ��ϴ� ����

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

		if (select == Exit) // ����
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
			cout << " �߸� �Է��ϼ̽��ϴ�\n" << endl;
		}


		system("pause");
	}

	cout << "\n���α׷��� ����\n" << endl;

	return 0;
}