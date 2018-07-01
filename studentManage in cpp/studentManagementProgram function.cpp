#include "studentManagementProgram header.h"

void printMenu(void)
{
	cout << "\n�Ѥ� �л� ���� ���α׷� �Ѥ�\n" << endl;

	cout << " 1. �л� �߰�" << endl;
	cout << " 2. �л� ����" << endl;
	cout << " 3. �л� �˻�" << endl;
	cout << " 4. ��� ���" << endl;
	cout << " 5. ����\n" << endl;
	cout << " ���� >> ";
}

bool selectMenu(int *select)
{
	cin >> *select;
	cout << "\n" << endl;

	if (cin.fail())
	{
		cin.clear(); // �������۸� ����
		cin.ignore(1024, '\n'); // �˻��ϰ����ϴ� ����Ʈũ�� , ã���� �ϴ� ����
								// ã���� �ϴ� ���ڰ� �ִ°����� ������ �ٽ� �Է¹ް� ���ش�
		return false;
	}
	return true;
}

void studentInsert(student *student, int *studentIndex)
{
	system("cls");
	cout << "\n�Ѥ� �л� �߰� �Ѥ�\n" << endl;

	cout << "\n �̸� >> ";
	cin >> student[*studentIndex].name;

	cout << "\n ��ȣ [-���� �Է�] >> ";
	cin.ignore(1024, '\n'); // ���ۿ� '\n'�� ���������� ����ֱ����� ���
	cin.getline(student[*studentIndex].phone, PHONE_NUM); // ���ͱ��� ���Խ�Ű�� ���� getline ���

	cout << "\n �ּ� >> ";
	cin.getline(student[*studentIndex].address, ADDRESS); // ���ͱ��� ���Խ�Ű�� ���� getline ���

	cout << "\n ���� >> ";
	cin >> student[*studentIndex].korean;

	cout << "\n ���� >> ";
	cin >> student[*studentIndex].english;

	cout << "\n ���� >> ";
	cin >> student[*studentIndex].math;

	cout << "\n" << endl;
	// ��� �Է��� ���� �� total�� average�� ������!!!

	student[*studentIndex].total = student[*studentIndex].korean + student[*studentIndex].english + student[*studentIndex].math;
	student[*studentIndex].average = student[*studentIndex].total / 3;

 	(*studentIndex)++;
}

void studentDelete(student *student, int *studentIndex)
{
	char deleteName[MAX_NAME];

	system("cls");
	cout << "\n�Ѥ� �л� ���� �Ѥ�\n" << endl;

	cout << "\n �̸� �Է� >> ";

	cin.ignore(1024, '\n');
	cin.getline(deleteName, MAX_NAME);

	for (int i = 0; i < *studentIndex; i++)
	{
		if (strcmp(deleteName, student[i].name) == 0)
		{
			for (int j = (i + 1); j <= *studentIndex; i++, j++)
			{
				student[i] = student[j];
			}
			(*studentIndex)--;

			cout << "\n \"" << deleteName << "\" ���� �Ϸ�!!\n" << endl;
			return;
		}
	}

	cout << "\n ������ �̸��� �����ϴ�!!\n" << endl;

}

void studentSearch(student *student, int *studentIndex)
{
	char searchName[MAX_NAME];

	system("cls");
	cout << "\n�Ѥ� �л� �˻� �Ѥ�\n" << endl;

	cout << "\n �̸� �Է� >> ";

	cin.ignore(1024, '\n');
	cin.getline(searchName, MAX_NAME);

	for (int i = 0; i < *studentIndex; i++)
	{
		if (strcmp(searchName, student[i].name) == 0)
		{
			system("cls");
			cout << "\n�Ѥ� �˻� ���� �Ѥ�\n" << endl;
			cout << " �̸� >> " << student[i].name << endl << endl;
			cout << " ��ȣ >> " << student[i].phone << endl << endl;
			cout << " �ּ� >> " << student[i].address << endl << endl;
			cout << " ���� >> " << student[i].korean << endl << endl;
			cout << " ���� >> " << student[i].english << endl << endl;
			cout << " ���� >> " << student[i].math << endl << endl;
			cout << " ���� >> " << student[i].total << endl << endl;
			cout << " ��� >> " << student[i].average << endl << endl;

			return;
		}
	}

	cout << "\n �˻� ����\n" << endl;
}

void studentOutput(student *student, int *studentIndex)
{
	system("cls");
	cout << "\n�Ѥ� �л� ��� �Ѥ�\n" << endl;

	for (int i = 0; i < *studentIndex; i++)
	{
		cout << " " << (i + 1) << ". " << student[i].name << endl << endl;
	}
}