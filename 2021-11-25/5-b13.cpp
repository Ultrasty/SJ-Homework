/* 1851521 Èí¹¤ ÉòÌìÓî */
#include <iostream>
#include <ctime> 
using namespace std;

int main()
{
    int bomb[10][26];
    int count = 0;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            bomb[i][j] = 0;
        }
    }

    srand(time(NULL));

    while (count < 50) {
        int i, j;
        i = rand() % 10;
        j = rand() % 26;
        if (bomb[i][j] != -1) {
            bomb[i][j] = -1;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < 10 && l >= 0 && l < 26 && bomb[k][l] != -1) {
                        bomb[k][l]++;
                    }
                }
            }
            count++;
        }
    }
            


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++) {
            if (bomb[i][j] == -1) {
                cout << "* ";
            }
            else {
                cout << bomb[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
