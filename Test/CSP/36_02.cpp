#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> sum(n + 1);
    vector<int> pre_max(n + 1);//前缀和的最大值
    sum[0] = a[0];
    pre_max[0] = sum[0];
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i] - b[i];
        pre_max[i] = max(sum[i], pre_max[i - 1]);
    }
    vector<int> suf_max(n + 1);//逆序对前缀和处理后的最大值
    suf_max[n] = sum[n];
    for(int i = n - 1; i >= 1; i--) {
        suf_max[i] = max(sum[i], suf_max[i + 1]);
    }
    //输出结果
    for(int i = 1; i <= n; i++) {
        int ans = max(pre_max[i - 1], suf_max[i] + b[i]);
        cout << ans << " ";
    }
    return 0;
}