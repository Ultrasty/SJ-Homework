/* 1851521 沈天宇 软工 */
/* 2151621 张威 2051943 张梓瀚 1853539 杨奇璇 1853022 巩欣怡 1854063 姜昱九 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{

    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.txt                    : 不带路径形式" << endl;
    cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
    
    char filename_in[50];
    char filename_out[50];
    
    cerr << "请输入要转换的hex格式文件名 : ";
    cin >> filename_in;
   
    cerr << "请输入转换后的文件名        : ";
    cin >> filename_out;

    ifstream in(filename_in, ios::in);
    ofstream out(filename_out, ios::out | ios::binary);

    int current;
    int count = 0;
    char buf[20] = { 0 };
    char cache[100];
    while (!in.eof()) {

        in.getline(cache,100);

        if (cache[0] == '\0') {
            in.close();
            out.close();
            return 0;
        }

        //错误处理（判断第一列有无错误）
        cache[8] = 0;
        sprintf(buf, "%8x", count);
        for (int i = 0; i < 7; i++) {
            if (buf[i] == ' ') {
                buf[i] = '0';
            }
        }
        if (strncmp(buf, cache, 8) != 0) {
            cerr << "最左侧的偏移量0x" << cache << "不是期望值0x" << buf << endl;
            in.close();
            out.close();
            return 0;
        }


        //大小写转换及将'a'-'f'偏移到'9'后面
        for (int i = 0; i < 100; i++) {
            if (cache[i] >= 'A' && cache[i] <= 'Z') {
                cache[i] += 0x20;
            }

            if (cache[i] >= 'a' && cache[i] <= 'f') {
                cache[i] = '9' + cache[i] - 'a' + 1;
            }
        }

        

        //十六进制字符串转十进制数字，转为char输出
        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 10] == ' ' && cache[i * 3 + 11] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << char((cache[i * 3 + 10] - '0') * 16 + cache[i * 3 + 11] - '0');
        }

        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 36] == ' ' && cache[i * 3 + 37] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << char((cache[i * 3 + 36] - '0') * 16 + cache[i * 3 + 37] - '0');
        }

        count += 16;
    }
    in.close();
    out.close();
    return 0;
}
