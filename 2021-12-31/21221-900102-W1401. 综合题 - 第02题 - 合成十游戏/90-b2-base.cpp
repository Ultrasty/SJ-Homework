/* 1851521 �� ������ */
//���ڲ����鷽ʽʵ�ֵĸ�����

#include "90-b2.h"


void console_fall_step(int data[10][10], int i, int j)
{
	swap(data[i][j], data[i][j - 1]);

	for (int k = 1; k <= 4; k++) {
		Sleep(1);
		if (((j - 1) * 4 + k) % 4 != 0) {
			cct_showch(i * 8 + 4, (j - 1) * 4 + k + 2 - 1, ' ', COLOR_HWHITE, COLOR_BLACK, 6);
		}
		else {
			cct_gotoxy(i * 8 + 4, (j - 1) * 4 + k + 2 - 1);
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "������";
			cct_setcolor();
		}
		print_one_block(data[i][j], i * 8 + 4, (j - 1) * 4 + k + 2);
	}
}

void console_fall(int data[10][10], int max_x, int max_y)
{
	while (1) {
		int anything_changed = 0;
		for (int j = max_y - 1; j >= 0; j--) {
			for (int i = max_x - 1; i >= 0; i--) {
				if (data[i][j] == 0 && j - 1 >= 0 && data[i][j - 1] != 0) {
					console_fall_step(data, i, j);
					anything_changed = 1;
				}
			}
		}
		if (!anything_changed) {
			break;
		}
	}
}

void highlight_findresult(int data[10][10], int max_x, int max_y, int find_result[10][10])
{
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (find_result[i][j] == 1) {
				print_one_block(data[i][j], i * 8 + 4, j * 4 + 2, COLOR_HWHITE);
			}
		}
	}
}

int sum_of_findresult(int find_result[10][10],int max_x,int max_y)
{
	int sum = 0;
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			sum += find_result[i][j];
		}
	}
	return sum;
}

void key_move(int &current_x,int &current_y,int data[10][10],int max_x,int max_y, int vertical_direction, int horizontal_direction)
{
	print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
	current_x = (current_x + max_x + horizontal_direction) % max_x;
	current_y = (current_y + max_y + vertical_direction) % max_y;
	print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);

	cct_gotoxy(0, 4 * max_y + 3);
	cout << "[��ǰ����] : ";
	if (vertical_direction == 1) {
		cout << "��";
	}
	if (vertical_direction == -1) {
		cout << "��";
	}
	if (horizontal_direction == 1) {
		cout << "��";
	}
	if (horizontal_direction == -1) {
		cout << "��";
	}
	cout << "��ͷ [��ǰѡ��]:" << char(current_y + 'A') << "��" << setw(2) << current_x + 1 << "��";
}

void change_find_result_to_zero(int data[10][10], int max_x, int max_y, int find_result[10][10])
{
	for (int i = 0; i < max_x; i++) {
		for (int j = 0; j < max_y; j++) {
			if (data[i][j] == 0) {
				find_result[i][j] = 1;
			}
			else {
				find_result[i][j] = 0;
			}
		}
	}
}

void input_select(char select[100], int max_x, int max_y)
{
	while (1) {
		cout << "\n������ĸ+������ʽ[����c2]����������꣺" << endl;
		cin >> select;

		if (select[0] >= 'A' && select[0] <= 'Z') {
			select[0] += 0x20;
		}

		char c;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (select[0] < 'a' || select[0] > 'a' + max_y - 1 || select[1] < '1' || select[1] > '1' + max_x - 1) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}
}


//ͨ���������������
template <class T>
void input(T& in, T lower_limits, T upper_limits, const char* prompt)
{
	char c;
	while (1) {
		cout << prompt;
		cin >> in;
		if (cin.fail()) {
			cin.clear();
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else if (in < lower_limits || in > upper_limits) {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			continue;
		}
		else {
			while ((c = getchar()) != '\n' && c != EOF)
				;
			break;
		}
	}
}

//��main���ã�������choice
void play(int choice)
{

	int max_x;
	int max_y;
	int target;
	int data[10][10];


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			data[i][j] = 0;
		}
	}

	if (choice == 1) {
		cct_cls();

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

		cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

		int select_x = select[1] - '1';
		int select_y = select[0] - 'a';

		int find_result[10][10];
		find_congener(data, max_x, max_y, select_x, select_y, find_result);
		print_find_result(find_result, max_x, max_y);
		print_data_with_color(data, max_x, max_y, find_result);

		system("pause");
	}

	if (choice == 2) {
		cct_cls();



		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

		cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

		int select_x = select[1] - '1';
		int select_y = select[0] - 'a';

		int find_result[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				find_result[i][j] = 0;
			}
		}
		find_result[select_x][select_y] = 1;
		find_congener_recursion(data, max_x, max_y, select_x, select_y, find_result);
		print_find_result(find_result, max_x, max_y);
		print_data_with_color(data, max_x, max_y, find_result);

		system("pause");
	}

	if (choice == 3) {
		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");
		input(target, 5, 20, "������ϳ�Ŀ��(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);


			cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

			int select_x = select[1] - '1';
			int select_y = select[0] - 'a';

			int find_result[10][10];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					find_result[i][j] = 0;
				}
			}
			find_result[select_x][select_y] = 1;
			find_congener_recursion(data, max_x, max_y, select_x, select_y, find_result);
			print_find_result(find_result, max_x, max_y);
			print_data_with_color(data, max_x, max_y, find_result);

			cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << select[0] << select[1] << "��(��Сд����y/n/q)��";

			char choice;
			while (1) {
				choice = _getche();
				if (choice != 'y' && choice != 'n' && choice != 'q') {
					continue;
				}
				else
					break;
			}

			if (choice == 'q') {
				break;
			}
			if (choice == 'n') {
				continue;
			}
			if (choice == 'y') {
				//�����߼�

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
				print_data_with_color(data, max_x, max_y, find_result);

				cout << " ���ε÷֣�" << temp_score << " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << target << endl;

				cout << "��������������������0����..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y, find_result);
				print_data_with_color(data, max_x, max_y, find_result);

				cout << "�������������ֵ���..." << endl;
				system("pause");

				generate_data(data, max_x, max_y);
				print_data_with_color(data, max_x, max_y, find_result);

				break;
			}

		}

		system("pause");
	}

	if (choice == 4) {
		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");
		input(target, 5, 20, "������ϳ�Ŀ��(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);


			cout << "����Ϊ" << select[0] << "��" << select[1] << "��" << endl;

			int select_x = select[1] - '1';
			int select_y = select[0] - 'a';

			int find_result[10][10];
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					find_result[i][j] = 0;
				}
			}
			find_result[select_x][select_y] = 1;
			find_congener_recursion(data, max_x, max_y, select_x, select_y, find_result);
			print_find_result(find_result, max_x, max_y);
			print_data_with_color(data, max_x, max_y, find_result);

			cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << select[0] << select[1] << "��(��Сд����y/n/q)��";

			char choice;
			while (1) {
				choice = _getche();
				if (choice != 'y' && choice != 'n' && choice != 'q') {
					continue;
				}
				else
					break;
			}

			if (choice == 'q') {
				break;
			}
			if (choice == 'n') {
				continue;
			}
			if (choice == 'y') {
				//�����߼�

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
				print_data_with_color(data, max_x, max_y, find_result);

				cout << " ���ε÷֣�" << temp_score << " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << target << endl;
				if (get_max_num(data, max_x, max_y) >= target) {
					cout << "���Ѵﵽ�ϳ�Ŀ�꣡�����Լ��������ߵ�Ŀ��ϳ�" << endl;
				}

				cout << "��������������������0����..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y, find_result);
				print_data_with_color(data, max_x, max_y, find_result);

				cout << "�������������ֵ���..." << endl;
				system("pause");

				generate_data(data, max_x, max_y);
				print_data_with_color(data, max_x, max_y, find_result);

			}

		}
		system("pause");
	}

	if (choice == 5) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(6 * max_x + 7, 3 * max_y + 8);
		cct_cls();

		print_background(max_x, max_y);
		print_data_block(data, max_x, max_y);

		cct_gotoxy(0, 3 * max_y + 3);

		system("pause");
	}

	if (choice == 6) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(8 * max_x + 7, 4 * max_y + 8);
		cct_cls();

		print_background_with_border(max_x, max_y);
		print_data_block_with_border(data, max_x, max_y);

		cct_gotoxy(0, 4 * max_y + 3);

		system("pause");
	}

	if (choice == 7) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(8 * max_x + 7, 4 * max_y + 8);
		cct_cls();

		print_background_with_border(max_x, max_y);
		print_data_block_with_border(data, max_x, max_y);

		//block������
		int current_x = 0;
		int current_y = 0;

		//cmd���ڵ�����
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//�رչ��
		
		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				
				
				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��Чλ��]                                       ";
				}
				else {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��ǰѡ��]:" <<char(current_y + 'A') << "��" << setw(2) << current_x + 1 << "��";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK:			//�������
						cout << " ѡ����ϣ�" << endl;
						loop = 0;
						break;
					default:
						break;
				} 
			} 
			else if (ret == CCT_KEYBOARD_EVENT) {
				

				switch (keycode1) {
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								key_move(current_x, current_y, data, max_x, max_y, -1, 0);
								break;
							case KB_ARROW_DOWN:
								key_move(current_x, current_y, data, max_x, max_y, 1, 0);
								break;
							case KB_ARROW_LEFT:
								key_move(current_x, current_y, data, max_x, max_y, 0, -1);
								break;
							case KB_ARROW_RIGHT:
								key_move(current_x, current_y, data, max_x, max_y, 0, 1);
								break;
						}
						break;
					case 13:
						cout << " ѡ����ϣ�" << endl;
						loop = 0;
						break;
					default:
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT��
		} //end of while(1)

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��

		system("pause");
	}


	if (choice == 8) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(8 * max_x + 7, 4 * max_y + 8);
		cct_cls();

		print_background_with_border(max_x, max_y);
		print_data_block_with_border(data, max_x, max_y);

		int find_result[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				find_result[i][j] = 0;
			}
		}

		//block������
		int current_x = 0;
		int current_y = 0;

		//cmd���ڵ�����
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;
		int comfirm = 0;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//�رչ��

		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {

				if (comfirm == 1 && (current_x != (X - 4) / 8 || current_y != (Y - 2) / 4)) {
					comfirm = 0;
					print_data_block_with_border(data, max_x, max_y);
				}

				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��Чλ��]                                       ";
				}
				else {
					
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��ǰѡ��]:" << char(current_y + 'A') << "��" << setw(2) << current_x + 1 << "��";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK://�������

						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "Ŀ������û�пɺϳɵķ��飡                         " << endl;
						}
						else {
							cout << " ѡ����ϣ�                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								merge(data, max_x, max_y, current_x, current_y, find_result);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "������������̡�����                       " << endl;
								system("pause");
								console_fall(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "������������̡�������ֵ                           " << endl;
								system("pause");

								generate_data(data, max_x, max_y);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								loop = 0;
							}
						}
						
						break;
					default:
						break;
				}
			}
			else if (ret == CCT_KEYBOARD_EVENT) {


				switch (keycode1) {
					case 224:
						if (comfirm == 1) {
							comfirm = 0;
							print_data_block_with_border(data, max_x, max_y);
						}
						switch (keycode2) {
							case KB_ARROW_UP:
								key_move(current_x, current_y, data, max_x, max_y, -1, 0);
								break;
							case KB_ARROW_DOWN:
								key_move(current_x, current_y, data, max_x, max_y, 1, 0);
								break;
							case KB_ARROW_LEFT:
								key_move(current_x, current_y, data, max_x, max_y, 0, -1);
								break;
							case KB_ARROW_RIGHT:
								key_move(current_x, current_y, data, max_x, max_y, 0, 1);
								break;
						}
						break;
					case 13:
						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "Ŀ������û�пɺϳɵķ��飡                         " << endl;
						}
						else {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << " ѡ����ϣ�                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								merge(data, max_x, max_y, current_x, current_y, find_result);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "������������̡�����                       " << endl;
								system("pause");
								console_fall(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "������������̡�������ֵ                           " << endl;
								system("pause");

								generate_data(data, max_x, max_y);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								loop = 0;
							}
						}
						break;
					default:
						break;
				}
			}
		}

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��

		system("pause");
	}

	if (choice == 9) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "����������(5-8)��\n");
		input(max_x, 5, 10, "����������(5-10)��\n");
		input(target, 5, 20, "������ϳ�Ŀ��(5-20)\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(8 * max_x + 7, 4 * max_y + 8);
		cct_cls();

		print_background_with_border(max_x, max_y);
		print_data_block_with_border(data, max_x, max_y);

		int find_result[10][10];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				find_result[i][j] = 0;
			}
		}

		//block������
		int current_x = 0;
		int current_y = 0;

		//cmd���ڵ�����
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;
		int comfirm = 0;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//�رչ��

		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {

				if (comfirm == 1 && (current_x != (X - 4) / 8 || current_y != (Y - 2) / 4)) {
					comfirm = 0;
					print_data_block_with_border(data, max_x, max_y);
				}

				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��Чλ��]                                       ";
				}
				else {

					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[��ǰѡ��]:" << char(current_y + 'A') << "��" << setw(2) << current_x + 1 << "��";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK://�������

						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "Ŀ������û�пɺϳɵķ��飡                         " << endl;
						}
						else {
							cout << " ѡ����ϣ�                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								int temp_score = merge(data, max_x, max_y, current_x, current_y, find_result);
								score += temp_score;
								cct_gotoxy(0, 4 * max_y + 4);
								cout << " ���ε÷֣�" << temp_score << " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << target << "      " << endl;
								if (get_max_num(data, max_x, max_y) >= target) {
									cout << "���Ѵﵽ�ϳ�Ŀ�꣡�����Լ��������ߵ�Ŀ��ϳ�" << endl;
								}
								print_data_block_with_border(data, max_x, max_y);
								console_fall(data, max_x, max_y);
								generate_data(data, max_x, max_y);
								print_data_block_with_border(data, max_x, max_y);
								cct_gotoxy(0, 4 * max_y + 3);
								comfirm = 0;
							}
						}

						break;
					default:
						break;
				}
			}
			else if (ret == CCT_KEYBOARD_EVENT) {


				switch (keycode1) {
					case 224:
						if (comfirm == 1) {
							comfirm = 0;
							print_data_block_with_border(data, max_x, max_y);
						}
						switch (keycode2) {
							case KB_ARROW_UP:
								key_move(current_x, current_y, data, max_x, max_y, -1, 0);
								break;
							case KB_ARROW_DOWN:
								key_move(current_x, current_y, data, max_x, max_y, 1, 0);
								break;
							case KB_ARROW_LEFT:
								key_move(current_x, current_y, data, max_x, max_y, 0, -1);
								break;
							case KB_ARROW_RIGHT:
								key_move(current_x, current_y, data, max_x, max_y, 0, 1);
								break;
						}
						break;
					case 13:
						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "Ŀ������û�пɺϳɵķ��飡                         " << endl;
						}
						else {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << " ѡ����ϣ�                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								int temp_score = merge(data, max_x, max_y, current_x, current_y, find_result);
								score += temp_score;
								cct_gotoxy(0, 4 * max_y + 4);
								cout << " ���ε÷֣�" << temp_score << " �ܵ÷֣�" << score << " �ϳ�Ŀ�꣺" << target << endl;
								if (get_max_num(data, max_x, max_y) >= target) {
									cout << "���Ѵﵽ�ϳ�Ŀ�꣡�����Լ��������ߵ�Ŀ��ϳ�" << endl;
								}
								print_data_block_with_border(data, max_x, max_y);
								console_fall(data, max_x, max_y);
								generate_data(data, max_x, max_y);
								print_data_block_with_border(data, max_x, max_y);
								cct_gotoxy(0, 4 * max_y + 3);
								comfirm = 0;
							}
						}
						break;
					default:
						break;
				}
			}
		}

		cct_disable_mouse();	//�������
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��

		system("pause");
	}
}