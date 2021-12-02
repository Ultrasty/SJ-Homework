/* 1851521 ������ �� */

#define STU_COUNT 10
#define CODE_LEN 8
#define NAME_LEN 9
#include <iostream>
#include <cstring>
using namespace std;

void read_data(string studentID[STU_COUNT], string name[STU_COUNT], int grade[STU_COUNT])
{
    for (int i = 0; i < STU_COUNT; i++) {
        cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�\n";
        cin >> studentID[i];
        cin >> name[i];
        cin >> grade[i];
    }
}

void bubble_sort(string studentID[STU_COUNT], string name[STU_COUNT], int grade[STU_COUNT])
{
    for (int i = STU_COUNT - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            string temp;
            int tempgrade;
            int comp;
            if (grade[j] > grade[j + 1]) {
                comp = -1;
            }
            else if (grade[j] < grade[j + 1]) {
                comp = 1;
            }
            else
                comp = 0;
            
            if (comp < 0) {
                temp = studentID[j];
                studentID[j] = studentID[j + 1];
                studentID[j + 1] = temp;

                temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;

                tempgrade = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = tempgrade;
            }
        }
    }
}

void print_data(string studentID[STU_COUNT], string name[STU_COUNT], int grade[STU_COUNT])
{
    cout << "\n����������(�ɼ�����):\n";
    for (int i = 0; i < STU_COUNT; i++) {
        if (grade[i] < 60) {
            cout << name[i] << " " << studentID[i] << " " << grade[i] << endl;
        }
    }
}

int main()
{
    string studentID[STU_COUNT];
    string name[STU_COUNT];
    int grade[STU_COUNT];

    read_data(studentID, name, grade);
    bubble_sort(studentID, name, grade);
    print_data(studentID, name, grade);

    return 0;
}
