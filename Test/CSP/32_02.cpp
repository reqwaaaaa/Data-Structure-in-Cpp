//
// Created by Naiweilanlan on 25-5-28.
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

typedef long long ll;

class Solution {
public:
    // 快速幂：计算 base^exp
    ll powInt(ll base, int exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res *= base;
            base *= base;
            exp /= 2;
        }
        return res;
    }

    ll simplify(ll n, int k) {
        ll result = 1;

        for (ll i = 2; i * i <= n; ++i) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            if (count >= k) {
                result *= powInt(i, count);
            }
        }

        // n 最后剩下一个大素数
        if (n > 1) {
            if (k <= 1) result *= n;
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    Solution sol;

    for (int i = 0; i < q; ++i) {
        ll n;
        int k;
        cin >> n >> k;
        cout << sol.simplify(n, k) << "\n";
    }

    return 0;
}
