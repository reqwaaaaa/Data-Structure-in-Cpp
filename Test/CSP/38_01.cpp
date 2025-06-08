//
// Created by Naiweilanlan on 25-6-8.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>

using namespace std;

int main() {
    // IO优化
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin>>a>>b>>c;

    float ans = (float)(c - a) / b;
    int first_digit = ((int)(ans * 10)) % 10;
    int second_digit = ((int)(ans * 100)) % 10;
    int code = ((int)ans) * 10 + first_digit;

    cout << code+1 << " " << second_digit+1 << endl;

    int n = 12345;
    // 个位：5
    int ones = n % 10;
    // 十位：4
    int tens = (n / 10) % 10;
    // 百位：3
    int hundreds = (n / 100) % 10;
    // 千位：2
    int thousands = (n / 1000) % 10;
    cout << ones+tens+hundreds+thousands << endl;

    float x = 4.5678;
    // 第一位：5
    int first = ((int)(x * 10)) % 10;
    // 第二位：6
    int second = ((int)(x * 100)) % 10;
    // 第三位：7
    int third = ((int)(x * 1000)) % 10;
    cout << first+second+third << endl;

    return 0;
}