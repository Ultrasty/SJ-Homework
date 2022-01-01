/* 1851521 软工 沈天宇 */
//放内部数组方式实现的各函数

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
			cout << "━━━";
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
	cout << "[当前按键] : ";
	if (vertical_direction == 1) {
		cout << "下";
	}
	if (vertical_direction == -1) {
		cout << "上";
	}
	if (horizontal_direction == 1) {
		cout << "右";
	}
	if (horizontal_direction == -1) {
		cout << "左";
	}
	cout << "箭头 [当前选择]:" << char(current_y + 'A') << "行" << setw(2) << current_x + 1 << "列";
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
		cout << "\n请以字母+数字形式[例：c2]输入矩阵坐标：" << endl;
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


//通用输入输出错误处理
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

//被main调用，并传入choice
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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

		cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

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



		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		char select[100];

		input_select(select, max_x, max_y);

		cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);


			cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

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

			cout << "请确认是否把相邻的相同值合并到" << select[0] << select[1] << "中(【小写】：y/n/q)：";

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
				//处理逻辑

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n相同值归并后的数组(不同色标识)：" << endl;
				print_data_with_color(data, max_x, max_y, find_result);

				cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << endl;

				cout << "按任意键进行数组下落除0操作..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y, find_result);
				print_data_with_color(data, max_x, max_y, find_result);

				cout << "按任意键进行新值填充..." << endl;
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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

		generate_data(data, max_x, max_y);
		print_data(data, max_x, max_y);

		while (1) {

			char select[100];

			input_select(select, max_x, max_y);


			cout << "输入为" << select[0] << "行" << select[1] << "列" << endl;

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

			cout << "请确认是否把相邻的相同值合并到" << select[0] << select[1] << "中(【小写】：y/n/q)：";

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
				//处理逻辑

				int temp_score = merge(data, max_x, max_y, select_x, select_y, find_result);
				score += temp_score;

				cout << "\n相同值归并后的数组(不同色标识)：" << endl;
				print_data_with_color(data, max_x, max_y, find_result);

				cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << endl;
				if (get_max_num(data, max_x, max_y) >= target) {
					cout << "您已达到合成目标！您可以继续往更高的目标合成" << endl;
				}

				cout << "按任意键进行数组下落除0操作..." << endl;
				system("pause");

				fall(data, max_x, max_y);

				change_find_result_to_zero(data, max_x, max_y, find_result);
				print_data_with_color(data, max_x, max_y, find_result);

				cout << "按任意键进行新值填充..." << endl;
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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

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

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

		generate_data(data, max_x, max_y);

		cct_setconsoleborder(8 * max_x + 7, 4 * max_y + 8);
		cct_cls();

		print_background_with_border(max_x, max_y);
		print_data_block_with_border(data, max_x, max_y);

		//block的坐标
		int current_x = 0;
		int current_y = 0;

		//cmd窗口的坐标
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
		
		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {
				
				
				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[无效位置]                                       ";
				}
				else {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[当前选择]:" <<char(current_y + 'A') << "行" << setw(2) << current_x + 1 << "列";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
						cout << " 选择完毕！" << endl;
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
						cout << " 选择完毕！" << endl;
						loop = 0;
						break;
					default:
						break;
				}//end of swicth(keycode1)
			}//end of else if(ret == CCT_KEYBOARD_EVENT）
		} //end of while(1)

		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标

		system("pause");
	}


	if (choice == 8) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");

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

		//block的坐标
		int current_x = 0;
		int current_y = 0;

		//cmd窗口的坐标
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;
		int comfirm = 0;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//关闭光标

		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {

				if (comfirm == 1 && (current_x != (X - 4) / 8 || current_y != (Y - 2) / 4)) {
					comfirm = 0;
					print_data_block_with_border(data, max_x, max_y);
				}

				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[无效位置]                                       ";
				}
				else {
					
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[当前选择]:" << char(current_y + 'A') << "行" << setw(2) << current_x + 1 << "列";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK://按下左键

						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "目标区域没有可合成的方块！                         " << endl;
						}
						else {
							cout << " 选择完毕！                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								merge(data, max_x, max_y, current_x, current_y, find_result);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "按任意键【键盘】下落                       " << endl;
								system("pause");
								console_fall(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "按任意键【键盘】产生新值                           " << endl;
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
							cout << "目标区域没有可合成的方块！                         " << endl;
						}
						else {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << " 选择完毕！                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								merge(data, max_x, max_y, current_x, current_y, find_result);
								print_data_block_with_border(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "按任意键【键盘】下落                       " << endl;
								system("pause");
								console_fall(data, max_x, max_y);

								cct_gotoxy(0, 4 * max_y + 3);
								cout << "按任意键【键盘】产生新值                           " << endl;
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

		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标

		system("pause");
	}

	if (choice == 9) {

		cct_cls();

		int score = 0;

		input(max_y, 5, 8, "请输入行数(5-8)：\n");
		input(max_x, 5, 10, "请输入列数(5-10)：\n");
		input(target, 5, 20, "请输入合成目标(5-20)\n");

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

		//block的坐标
		int current_x = 0;
		int current_y = 0;

		//cmd窗口的坐标
		int X = 0, Y = 0;
		int ret, maction;
		int keycode1, keycode2;
		int loop = 1;
		int comfirm = 0;

		cct_enable_mouse();
		cct_setcursor(CURSOR_INVISIBLE);	//关闭光标

		print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
		while (loop) {
			/* 读鼠标/键盘，返回值为下述操作中的某一种, 当前鼠标位置在<X,Y>处 */
			ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

			if (ret == CCT_MOUSE_EVENT) {

				if (comfirm == 1 && (current_x != (X - 4) / 8 || current_y != (Y - 2) / 4)) {
					comfirm = 0;
					print_data_block_with_border(data, max_x, max_y);
				}

				if ((Y - 1) % 4 == 0 || (X - 2) % 8 == 0 || (X - 2) % 8 == 1 || Y < 1 || X < 2 || Y > 4 * max_y + 1 || X > 8 * max_x + 2) {
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[无效位置]                                       ";
				}
				else {

					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2);
					current_x = (X - 4) / 8;
					current_y = (Y - 2) / 4;
					print_one_block(data[current_x][current_y], current_x * 8 + 4, current_y * 4 + 2, COLOR_HWHITE);
					cct_gotoxy(0, 4 * max_y + 3);
					cout << "[当前选择]:" << char(current_y + 'A') << "行" << setw(2) << current_x + 1 << "列";
				}

				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK://按下左键

						find_congener(data, max_x, max_y, current_x, current_y, find_result);
						if (sum_of_findresult(find_result, max_x, max_y) == 1) {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << "目标区域没有可合成的方块！                         " << endl;
						}
						else {
							cout << " 选择完毕！                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								int temp_score = merge(data, max_x, max_y, current_x, current_y, find_result);
								score += temp_score;
								cct_gotoxy(0, 4 * max_y + 4);
								cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << "      " << endl;
								if (get_max_num(data, max_x, max_y) >= target) {
									cout << "您已达到合成目标！您可以继续往更高的目标合成" << endl;
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
							cout << "目标区域没有可合成的方块！                         " << endl;
						}
						else {
							cct_gotoxy(0, 4 * max_y + 3);
							cout << " 选择完毕！                         " << endl;
							highlight_findresult(data, max_x, max_y, find_result);
							comfirm += 1;
							if (comfirm == 2) {
								int temp_score = merge(data, max_x, max_y, current_x, current_y, find_result);
								score += temp_score;
								cct_gotoxy(0, 4 * max_y + 4);
								cout << " 本次得分：" << temp_score << " 总得分：" << score << " 合成目标：" << target << endl;
								if (get_max_num(data, max_x, max_y) >= target) {
									cout << "您已达到合成目标！您可以继续往更高的目标合成" << endl;
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

		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标

		system("pause");
	}
}