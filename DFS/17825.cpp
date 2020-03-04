#include <iostream>
#define END 32

using namespace std;

/*
               32
 0             31
 1                19
 2             30    18
 3             29       17
 4                         16
 5   20 21 22  23  24 25 26   15
    6                      14
       7       28       13
          8    27    12
             9    11
               10
*/

int score[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 13, 16, 19, 25, 26, 27, 28, 22, 24, 30, 35, 40, 0 };
int dice[11];
int player[5], cur_score, max_score;

// 주사위 값에 따라 말 이동
int move_player(int from, int value)
{
    int dest = 0;
    if (from == 5) {
        if (value == 5) dest = 29;
        else dest = 20 + value - 1;
    }
    else if (from == 10) {
        if (value == 1) dest = 27;
        else if (value == 2) dest = 28;
        else if (value == 3) dest = 23;
        else if (value == 4) dest = 29;
        else if (value == 5) dest = 30;
    }
    else if (from == 15) {
        if (value == 5) dest = 29;
        else dest = 26 - value + 1;
    }
    else if (from == 23) {
        dest = 29 + value - 1;
    }
    else if (from == 16 && value >= 4) {
        dest = 31 + value - 4;
    }
    else if (from == 17 && value >= 3) {
        dest = 31 + value - 3;
    }
    else if (from == 18 && value >= 2) {
        dest = 31 + value - 2;
    }
    else if (from == 19) {
        dest = 31 + value - 1;
    }
    else if (from == 20) {
        if (value <= 3) dest = from + value;
        else dest = 29 + value - 4;
    }
    else if (from == 21) {
        if (value <= 2) dest = from + value;
        else dest = 29 + value - 3;
    }
    else if (from == 22) {
        if (value <= 1) dest = from + value;
        else dest = 29 + value - 2;
    }
    else if (from == 24) {
        if (value <= 1) dest = from - value;
        else dest = 29 + value - 2;
    }
    else if (from == 25) {
        if (value <= 2) dest = from - value;
        else dest = 29 + value - 3;
    }
    else if (from == 26) {
        if (value <= 3) dest = from - value;
        else dest = 29 + value - 4;
    }
    else if (from == 25 || from == 26) {
        dest = from - value;
    }
    else if (from == 27) {
        if (value == 1) dest = 28;
        else if (value == 2) dest = 23;
        else if (value == 3) dest = 29;
        else if (value == 4) dest = 30;
        else if (value == 5) dest = 31;
    }
    else if (from == 28) {
        if (value == 1) dest = 23;
        else if (value == 2) dest = 29;
        else if (value == 3) dest = 30;
        else if (value == 4) dest = 31;
        else if (value == 5) dest = 32;
    }
    else {
        dest = from + value;
    }

    if (dest > END) {
        dest = END;
    }
    return dest;
}

// DFS
void dfs(int index)
{
    // 10번 이동 후 최대값 갱신
    if (index > 10) {
        if (max_score < cur_score) {
            max_score = cur_score;
            if (max_score == 224) {
                index = index;
            }
        }
        return;
    }

    // 1, 2, 3, 4번 말 중 하나를 선택해 이동
    for (int i = 1; i <= 4; i++) {
        // 도착한 말은 움직이지 않음
        if (player[i] == END) {
            continue;
        }

        int from = player[i];
        int dest = move_player(player[i], dice[index]);
        bool is_blank = true;

        // 이동할 곳에 이미 말이 있으면 이동하지 않음
        if (dest != END) {
            for (int j = 1; j <= 4; j++) {
                if (dest == player[j]) {
                    is_blank = false;
                    break;
                }
            }
        }
        if (!is_blank) {
            continue;
        }

        // i번 말을 이동한 뒤 계속 탐색
        player[i] = dest;
        cur_score += score[dest];
        dfs(index + 1);
        // 탐색을 마쳤으면 i번 말을 원래 자리로 되돌림
        cur_score -= score[dest];
        player[i] = from;
    }
}

int main()
{
	for (int i = 1; i <= 10; i++) {
		cin >> dice[i];
	}

    dfs(1);

    cout << max_score << endl;

	return 0;
}