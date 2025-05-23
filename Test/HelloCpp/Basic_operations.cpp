//
// Created by Naiweilanlan on 25-2-16.
//

#include<iostream>
#include<string>
#include <algorithm>  // transform 需要包含
#include <cctype>  // isupper, islower, toupper, tolower 需要包含
using namespace std;

int main() {

  // 输入cin输出cout
  cout<<"please input your name:"<<endl;
  string name;
  cin>>name;
  cout<<"your name:"<<name<<endl;
  int a = 10;
  cout<< a << "数字" <<endl;


  // 字符串String操作
  string s1 = "Hello";
  string s2 = "World";
  // 1. 拼接字符串
  string s3 = s1 + " " + s2;
  cout << "拼接: " << s3 << endl;  // Hello World
  // 2. 获取长度
  cout << "长度: " << s3.length() << endl;  // 11
  // 3. 访问字符（索引）
  cout << "第一个字符: " << s3[0] << endl;  // H
  // 4. 查找子串
  size_t pos = s3.find("World");
  if (pos != string::npos) {  // string::npos 表示未找到
    cout << "World 在索引: " << pos << endl;
  }
  // 5. 取子串
  string sub = s3.substr(0, 5);
  cout << "子串: " << sub << endl;  // Hello
  // 6. 替换子串
  //s3.replace(6, 5, "C++");
  //cout << "替换后: " << s3 << endl;  // Hello C++

  //遍历字符串
  for (int i = 0; i < s3.length(); i++) {
    cout<< s3.at(i) << " " << s3[i] << " "; //.at() 和 [] 有一样的效果
  }
  cout << endl;
  for (char c :s3) {
    cout << c << " ";
  }
  cout << endl;
  // 转换为大写
  transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
  cout << "大写: " << s3 << endl;
  // 转换为小写
  transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
  cout << "小写: " << s3 << endl;
  // 大小写互转
  /*
    transform(s3.begin(), s3.end(), s3.begin(), [](char c) {
    return isupper(c) ? tolower(c) : toupper(c);
  });
  */
  // 反转字符串
  reverse(s3.begin(), s3.end());
  cout << "反转：: " << s3 << endl;
  // 去除空格
  //s3.erase(remove(s3.begin(), s3.end(), " "), s3.end());
  /*
  1.	remove(s3.begin(), s3.end(), ' ') 让 所有非空格字符向前挪，并返回新 “逻辑结尾”。
  2.	erase(start, end) 从 start 位置一直删除到 end。
  3.	s3.end() 指向原本的字符串结尾，而 remove(...) 返回新的逻辑结尾（即没有空格的部分）。
  4.	erase() 删除 逻辑结尾之后的所有内容，真正缩短字符串。
   */


  return 0;
}