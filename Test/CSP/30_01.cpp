//
// Created by Naiweilanlan on 25-5-31.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 清除换行

    unordered_map<string, int> board_count;
    vector<int> result;

    for (int step = 0; step < n; ++step) {
        string board_flat;
        for (int i = 0; i < 8; ++i) {
            string row;
            getline(cin, row);
            board_flat += row;
        }

        board_count[board_flat]++;
        result.push_back(board_count[board_flat]);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}