//
// Created by Naiweilanlan on 25-6-17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <chrono>

using namespace std;
using namespace chrono;

// ---------- 插入排序 ----------
// 稳定，时间 O(n^2)，空间 O(1)，适合小规模或基本有序数据
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) a[j + 1] = a[j--];
        a[j + 1] = key;
    }
}

// ---------- 折半插入排序 ----------
// 稳定，时间 O(n^2)，空间 O(1)，使用二分查找减少比较次数
void binaryInsertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int key = a[i], left = 0, right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] > key) right = mid - 1;
            else left = mid + 1;
        }
        for (int j = i - 1; j >= left; --j) a[j + 1] = a[j];
        a[left] = key;
    }
}

// ---------- 希尔排序 ----------
// 不稳定，时间最坏 O(n^2)，平均 O(n^1.3)，空间 O(1)，适合中等规模
void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

// ---------- 快速排序 ----------
// 不稳定，时间 O(n log n)，最坏 O(n^2)，空间 O(log n)，适合大数据
int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    while (low < high) {
        while (low < high && a[high] >= pivot) --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot) ++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quickSort(a, low, mid - 1);
        quickSort(a, mid + 1, high);
    }
}

// ---------- 快排优化：三数取中 + 插入排序 ----------
int median3(vector<int>& a, int l, int r) {
    int m = (l + r) / 2;
    if (a[l] > a[m]) swap(a[l], a[m]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[m] > a[r]) swap(a[m], a[r]);
    swap(a[m], a[r - 1]);
    return a[r - 1];
}

void quickSortOptimized(vector<int>& a, int l, int r) {
    if (r - l <= 10) {
        for (int i = l + 1; i <= r; ++i) {
            int key = a[i], j = i - 1;
            while (j >= l && a[j] > key) a[j + 1] = a[j--];
            a[j + 1] = key;
        }
        return;
    }
    int pivot = median3(a, l, r);
    int i = l, j = r - 1;
    while (true) {
        while (a[++i] < pivot);
        while (a[--j] > pivot);
        if (i < j) swap(a[i], a[j]);
        else break;
    }
    swap(a[i], a[r - 1]);
    quickSortOptimized(a, l, i - 1);
    quickSortOptimized(a, i + 1, r);
}

// ---------- 选择排序 ----------
// 不稳定，时间 O(n^2)，空间 O(1)，适合小规模
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

// ---------- 堆排序 ----------
// 不稳定，时间 O(n log n)，空间 O(1)，适合大规模
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) heapify(a, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// ---------- 计数排序 ----------
// 稳定，时间 O(n + k)，空间 O(k)，仅适用于整数且范围小
void countingSort(vector<int>& a) {
    int maxVal = *max_element(a.begin(), a.end());
    int minVal = *min_element(a.begin(), a.end());
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    for (int num : a) count[num - minVal]++;
    int idx = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i]--) a[idx++] = i + minVal;
    }
}

// ---------- 基数排序（LSD） ----------
// 稳定，时间 O(d * (n + k))，空间 O(n + k)，适用于大数据整数
void radixSort(vector<int>& a) {
    int maxVal = *max_element(a.begin(), a.end());
    int exp = 1;
    vector<int> tmp(a.size());
    while (maxVal / exp > 0) {
        vector<int> count(10, 0);
        for (int num : a) count[(num / exp) % 10]++;
        for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
        for (int i = a.size() - 1; i >= 0; --i)
            tmp[--count[(a[i] / exp) % 10]] = a[i];
        a = tmp;
        exp *= 10;
    }
}

// ---------- 主函数测试 ----------
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> copy;

    auto testSort = [&](string name, void(*sortFunc)(vector<int>&)) {
        copy = arr;
        auto start = high_resolution_clock::now();
        sortFunc(copy);
        auto end = high_resolution_clock::now();
        cout << name << ": ";
        for (int x : copy) cout << x << " ";
        cout << " | Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
    };

    testSort("Insertion", insertionSort);
    testSort("BinaryInsert", binaryInsertionSort);
    testSort("Shell", shellSort);
    testSort("Quick", [](vector<int>& a){ quickSort(a, 0, a.size() - 1); });
    testSort("QuickOptimized", [](vector<int>& a){ quickSortOptimized(a, 0, a.size() - 1); });
    testSort("Selection", selectionSort);
    testSort("Heap", heapSort);
    testSort("Counting", countingSort);
    testSort("Radix", radixSort);

    return 0;
}
