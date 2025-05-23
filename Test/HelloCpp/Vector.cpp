//
// Created by Naiweilanlan on 25-2-18.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 10;
    // 数组大小为 10，元素值都为 0
    vector<int> nums(n); vector<int> num(n,2);
    // 输出 0 (false)
    cout << nums.empty() << endl; cout<< num[1] << endl;
    // 输出：10
    cout << nums.size() << endl;

    // 在数组尾部插入一个元素 9 ,尾部就是索引为0
    nums.push_back(9);
    // 输出：11
    cout << nums.size() << endl; cout<< num[1] << endl;

    // 得到数组最后一个元素
    // 输出：9
    cout << nums.back() << endl;

    // 删除数组的最后一个元素（无返回值）
    nums.pop_back();
    // 输出：10
    cout << nums.size() << endl;

    // 可以通过方括号直接取值或修改
    nums[0] = 11;
    // 输出：11
    cout << nums[0] << endl;

    // 在索引 3 处插入一个元素 99 ,第四个元素
    nums.insert(nums.begin() + 3, 99);

    // 删除索引 2 处的元素
    nums.erase(nums.begin() + 2);

    // 交换 nums[0] 和 nums[1]
    swap(nums[0], nums[1]);

    // 遍历数组
    // 0 11 99 0 0 0 0 0 0 0
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // 二维向量
    int x = 3, y = 4;
    vector<vector<int>> matrix(x, vector<int>(y, 0));
    /*
    x = 3, y = 4：创建 3 行 4 列 的二维 vector。
    vector<int>(y, 0)：表示 每一行有 y 个 0。
    matrix(x, ...)：表示 总共有 y 行。
    */
    /*
    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    */

    // 修改元素
    matrix[1][2] = 99;

    // 遍历矩阵（索引方式）
    cout << "矩阵内容:" << endl;
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // 添加新的一行
    matrix.push_back({10, 20, 30, 40});

    // 遍历矩阵（`range-based for` 方式）
    cout << "添加新行后:" << endl;
    for (const auto &row : matrix) { // auto 自动推导类型
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    /*
    int x = 10;
    const int* p = &x;  // ✅ p 指向的值不能修改，但 p 本身可以改指向
    p = &y;  // ✅ 合法
    *p = 20;  // ❌ 错误

    int* const p2 = &x;  // ✅ p2 不能修改指向的地址，但值可以改
    p2 = &y;  // ❌ 错误
    *p2 = 20;  // ✅ 合法
     */
    return 0;
}