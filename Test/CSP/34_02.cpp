//
// Created by Naiweilanlan on 25-5-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> mat;
    int rows, cols;

public:
    // 初始化矩阵
    Matrix(int r, int c, const vector<vector<int>>& data) : rows(r), cols(c), mat(data) {}

    // reshape 操作
    void reshape(int new_r, int new_c) {
        if (rows * cols != new_r * new_c) return; // 维度不匹配无法 reshape
        vector<int> flat;
        for (const auto& row : mat)
            for (int val : row)
                flat.push_back(val);

        mat.assign(new_r, vector<int>(new_c));
        for (int i = 0; i < new_r * new_c; ++i)
            mat[i / new_c][i % new_c] = flat[i];

        rows = new_r;
        cols = new_c;
    }

    // transpose 操作
    void transpose() {
        vector<vector<int>> trans(cols, vector<int>(rows));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                trans[j][i] = mat[i][j];
        mat = trans;
        swap(rows, cols);
    }

    // query 操作
    int query(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return -1; // 越界处理
        return mat[r][c];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    // 读入初始矩阵
    vector<vector<int>> data(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> data[i][j];

    Matrix matrix(n, m, data);

    vector<int> results; // 存储所有 query 的结果

    for (int i = 0; i < t; ++i) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            matrix.reshape(a, b);
        } else if (op == 2) {
            matrix.transpose();
        } else if (op == 3) {
            results.push_back(matrix.query(a, b));
        }
    }

    // 最后一次性输出所有查询结果
    for (int val : results)
        cout << val << '\n';

    return 0;
}
