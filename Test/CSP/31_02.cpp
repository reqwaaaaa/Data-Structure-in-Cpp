//
// Created by Naiweilanlan on 25-5-31.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = acos(-1.0);

// 定义仿射变换矩阵
struct Matrix {
    double a, b, c, d; // 对应 2x2 矩阵的四个元素
    Matrix(double a_ = 1, double b_ = 0, double c_ = 0, double d_ = 1) : a(a_), b(b_), c(c_), d(d_) {}

    // 矩阵乘法
    Matrix operator*(const Matrix& other) const {
        return Matrix(
            a * other.a + b * other.c,
            a * other.b + b * other.d,
            c * other.a + d * other.c,
            c * other.b + d * other.d
        );
    }

    // 计算逆矩阵
    Matrix inverse() const {
        double det = a * d - b * c;
        return Matrix(d / det, -b / det, -c / det, a / det);
    }

    // 应用变换到点 (x, y)
    pair<double, double> apply(double x, double y) const {
        return {a * x + b * y, c * x + d * y};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Matrix> prefix(n + 1); // prefix[0] = 单位矩阵
    for (int i = 1; i <= n; ++i) {
        int type;
        double val;
        cin >> type >> val;
        if (type == 1) {
            // 拉伸：k 倍放大，相当于乘以 k
            Matrix scale(val, 0, 0, val);
            prefix[i] = scale * prefix[i - 1];
        } else {
            // 旋转 θ 弧度
            Matrix rotate(cos(val), -sin(val), sin(val), cos(val));
            prefix[i] = rotate * prefix[i - 1];
        }
    }

    // 读取所有查询，统一处理
    vector<tuple<int, int, int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        queries[i] = {l, r, x, y};
    }

    vector<pair<double, double>> result;
    for (auto [l, r, x, y] : queries) {
        Matrix trans = prefix[r] * prefix[l - 1].inverse();
        result.push_back(trans.apply(x, y));
    }

    cout << fixed << setprecision(10); // 设置精度
    for (auto [x, y] : result) {
        cout << x << " " << y << "\n";
    }

    return 0;
}