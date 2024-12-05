#include <iostream>

#include <string>

using namespace std;
std::string solution(const std::string &s) {
  // write code here
  int i = 0;
  while (s[i] == '0' && i < s.size())
    i++;
  string before, after;
  auto pos = s.find('.');
  if (pos != string::npos) {
    before = s.substr(i, pos-i);
    after = s.substr(pos);
  } else {
    before = s.substr(i);
  }

  string rel;
  int count = 0;
  for (int j = before.size() - 1; j >= 0; j--) {
    rel = before[j] + rel;
    count++;
    if (count % 3 == 0 && j != 0) {
      rel = ',' + rel;
    }
  }
  if (after.empty()) {
    return rel;
  }
  return rel + after;
}

int main() {

  std::cout << (solution("0000123456789.99")) << std::endl;

}