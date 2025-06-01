//
// Created by Naiweilanlan on 25-5-31.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    // 输入 Q、K、V
    vector<vector<int>> Q(n, vector<int>(d));
    vector<vector<int>> K(n, vector<int>(d));
    vector<vector<int>> V(n, vector<int>(d));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> Q[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> K[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> V[i][j];

    // 输入权重向量 W
    vector<int> W(n);
    for (int i = 0; i < n; ++i)
        cin >> W[i];

    // Step 1: 计算 QK^T
    vector<vector<int>> qkt(n, vector<int>(n, 0));  // QK^T 是 n x n
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < d; ++k) {
                qkt[i][j] += Q[i][k] * K[j][k];  // 注意是 K 的转置
            }
        }
    }

    // Step 2: 每行乘以 W[i]
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            qkt[i][j] *= W[i];

    // Step 3: qkt × V → 结果是 n x d
    vector<vector<int>> result(n, vector<int>(d, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += qkt[i][k] * V[k][j];
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cout << result[i][j];
            if (j < d - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
