//
// Created by 86138 on 2025/1/5.
//

#include<iostream>
#include <limits>

using namespace std;

int main()
{
    // system("chcp 65001");
    cout << "type: \t\t" << "************size**************"<< endl;
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
    cout << "\t最大值：" << (numeric_limits<bool>::max)();
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);
    cout << "\t最大值：" << (numeric_limits<char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);
    cout << "\t最大值：" << (numeric_limits<short>::max)();
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);
    cout << "\t最大值：" << (numeric_limits<int>::max)();
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);
    cout << "\t最大值：" << (numeric_limits<long>::max)();
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "所占字节数：" << sizeof(double);
    cout << "\t最大值：" << (numeric_limits<double>::max)();
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);
    cout << "\t最大值：" << (numeric_limits<long double>::max)();
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);
    cout << "\t最大值：" << (numeric_limits<float>::max)();
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size**************"<< endl;
    return 0;
}

/* #include <limits>

 用法示例:
 1. 获取数据类型的最大值和最小值
    std::numeric_limits<int>::max();   // 返回 int 类型的最大值
    std::numeric_limits<float>::min(); // 返回 float 类型的最小正值

 2. 检查数据类型是否有符号
    std::numeric_limits<int>::is_signed;    // true (int 是有符号类型)
    std::numeric_limits<unsigned>::is_signed; // false (unsigned 是无符号类型)

 3. 检查浮点数特性
    std::numeric_limits<float>::epsilon();    // 浮点数的机器精度
    std::numeric_limits<double>::infinity(); // 浮点数正无穷大
    std::numeric_limits<double>::quiet_NaN(); // 浮点数非数字值 (NaN)

 4. 检查整数类型特性
    std::numeric_limits<int>::digits; // int 类型的二进制位数
    std::numeric_limits<unsigned char>::digits; // unsigned char 的二进制位数

 5. 检查类型是否支持无穷大或 NaN
    std::numeric_limits<float>::has_infinity;  // true (float 支持无穷大)
    std::numeric_limits<int>::has_infinity;    // false (int 不支持无穷大)

 6. 检查最小值和最大值是否包含负数
   std::numeric_limits<int>::min();   // 返回负值 (int 的最小值)
    std::numeric_limits<unsigned>::min(); // 返回 0 (unsigned 类型最小值
 7. 类型范围的动态检查 (可用于模板编程)
    使用 std::numeric_limits<T>::max() 和 std::numeric_limits<T>::min()
    可以动态检查模板中 T 类型的范围。

 8. 用于科学计算中避免硬编码
    使用 std::numeric_limits<double>::max() 替代硬编码的 DBL_MAX
*/