#include "studentManagementProgram header.h"

void printMenu(void)
{
	cout << "\nㅡㅡ 학생 관리 프로그램 ㅡㅡ\n" << endl;

	cout << " 1. 학생 추가" << endl;
	cout << " 2. 학생 삭제" << endl;
	cout << " 3. 학생 검색" << endl;
	cout << " 4. 명단 출력" << endl;
	cout << " 5. 종료\n" << endl;
	cout << " 선택 >> ";
}

bool selectMenu(int *select)
{
	cin >> *select;
	cout << "\n" << endl;

	if (cin.fail())
	{
		cin.clear(); // 에러버퍼를 비운다
		cin.ignore(1024, '\n'); // 검색하고자하는 바이트크기 , 찾고자 하는 문자
								// 찾고자 하는 문자가 있는곳까지 지워서 다시 입력받게 해준다
		return false;
	}
	return true;
}

void studentInsert(student *student, int *studentIndex)
{
	system("cls");
	cout << "\nㅡㅡ 학생 추가 ㅡㅡ\n" << endl;

	cout << "\n 이름 >> ";
	cin >> student[*studentIndex].name;

	cout << "\n 번호 [-없이 입력] >> ";
	cin.ignore(1024, '\n'); // 버퍼에 '\n'가 남아있으니 비어주기위해 사용
	cin.getline(student[*studentIndex].phone, PHONE_NUM); // 엔터까지 포함시키기 위해 getline 사용

	cout << "\n 주소 >> ";
	cin.getline(student[*studentIndex].address, ADDRESS); // 엔터까지 포함시키기 위해 getline 사용

	cout << "\n 국어 >> ";
	cin >> student[*studentIndex].korean;

	cout << "\n 영어 >> ";
	cin >> student[*studentIndex].english;

	cout << "\n 수학 >> ";
	cin >> student[*studentIndex].math;

	cout << "\n" << endl;
	// 모두 입력을 받은 후 total과 average를 구하자!!!

	student[*studentIndex].total = student[*studentIndex].korean + student[*studentIndex].english + student[*studentIndex].math;
	student[*studentIndex].average = student[*studentIndex].total / 3;

 	(*studentIndex)++;
}

void studentDelete(student *student, int *studentIndex)
{
	char deleteName[MAX_NAME];

	system("cls");
	cout << "\nㅡㅡ 학생 삭제 ㅡㅡ\n" << endl;

	cout << "\n 이름 입력 >> ";

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

			cout << "\n \"" << deleteName << "\" 삭제 완료!!\n" << endl;
			return;
		}
	}

	cout << "\n 삭제할 이름이 없습니다!!\n" << endl;

}

void studentSearch(student *student, int *studentIndex)
{
	char searchName[MAX_NAME];

	system("cls");
	cout << "\nㅡㅡ 학생 검색 ㅡㅡ\n" << endl;

	cout << "\n 이름 입력 >> ";

	cin.ignore(1024, '\n');
	cin.getline(searchName, MAX_NAME);

	for (int i = 0; i < *studentIndex; i++)
	{
		if (strcmp(searchName, student[i].name) == 0)
		{
			system("cls");
			cout << "\nㅡㅡ 검색 성공 ㅡㅡ\n" << endl;
			cout << " 이름 >> " << student[i].name << endl << endl;
			cout << " 번호 >> " << student[i].phone << endl << endl;
			cout << " 주소 >> " << student[i].address << endl << endl;
			cout << " 국어 >> " << student[i].korean << endl << endl;
			cout << " 영어 >> " << student[i].english << endl << endl;
			cout << " 수학 >> " << student[i].math << endl << endl;
			cout << " 총점 >> " << student[i].total << endl << endl;
			cout << " 평균 >> " << student[i].average << endl << endl;

			return;
		}
	}

	cout << "\n 검색 실패\n" << endl;
}

void studentOutput(student *student, int *studentIndex)
{
	system("cls");
	cout << "\nㅡㅡ 학생 목록 ㅡㅡ\n" << endl;

	for (int i = 0; i < *studentIndex; i++)
	{
		cout << " " << (i + 1) << ". " << student[i].name << endl << endl;
	}
}