/* 1851521 沈天宇 软工 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void print_cache(int c,int cache[],int limit) 
{
    cout << setw(8) << hex << c << "  ";
    for (int i = 0; i < limit; i++) {
        if (i == 8) {
            cout << "- ";
        }
        cout << setw(2) << hex << cache[i] << " ";
    }

    for (int i = limit; i < 16; i++) {
        if (i == 8) {
            cout << "  ";
        }
        cout << "   ";
    }

    cout << "    ";

    for (int i = 0; i < limit; i++) {
        if (cache[i] >= 33 && cache[i] <= 126) {
            cout << char(cache[i]);
        }
        else
            cout << ".";
    }

    cout << endl;
}

int main(int argc, char* argv[])
{

    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.txt                    : 不带路径形式" << endl;
    cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
    cerr << "请输入文件名 : ";

    char filename[50];
    cin >> filename;

    ifstream in(filename, ios::in | ios::binary);//可加ios::binary
    int c = 0;
    int current;
    int cache[16];

    cout << setfill('0');

    while ((current = in.get()) != EOF) {

        cache[c % 16] = current;
        c++;   

        if (c % 16 == 0) {
            print_cache(c, cache ,16);
            for (int i = 0; i < 16; i++) {
                cache[i] = 0;
            }
        }       
    }

    print_cache(c, cache ,c % 16);

    in.close();

    return 0;
}
