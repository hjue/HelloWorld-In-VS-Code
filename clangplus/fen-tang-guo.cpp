// parse input to function parameters
// 输入 [1,1,2,2,3,3]
// 一行表示一个参数 ，输入 [1,1,2,2,3,3] 解析为函数参数 candyType = [1,1,2,2,3,3]
// 输入 [1,4]\n2 ，表示两个参数
// 关于类型，有数字、字符串、布尔
// 输出 3
// clang++ -std=c++11  fen-tang-guo.cpp -o fen-tang-guo
// echo "[1,1,2,2,3,3]" | ./fen-tang-guo

#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
  int distributeCandies(vector<int> &candyType)
  {
    return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
  }
};

void trimLeftTrailingSpaces(string &input)
{
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                     { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                      { return !isspace(ch); })
                  .base(),
              input.end());
}

vector<int> stringToIntegerVector(string input)
{
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim))
  {
    output.push_back(stoi(item));
  }
  return output;
}

int main()
{
  Solution s;

  vector<int> candyType = {1, 1, 2, 2, 3, 3};
  cout << s.distributeCandies(candyType) << endl;

  // string line;
  // while (getline(cin, line))
  // {
  //   // vector<int> candyType = stringToIntegerVector(line);
  //   cout << s.distributeCandies(candyType) << endl;
  // }
  return 0;
}
