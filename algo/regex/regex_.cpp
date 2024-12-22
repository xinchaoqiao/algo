#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;
string return_rex(string template_) {
    string res;
    for (int i = 0;i < template_.size();i++) {
        char ch = template_[i];
        if (ch == '{' ) {
            res += ".*";
            while(template_[i]!='}')i++; 
        }
        else {
            res+=ch;
        }
    }
        
    return res;
}
std::string solution(int n, std::string template_,
                     std::vector<std::string> titles) {
    // Please write your code here
    string r = return_rex(template_);
    regex reg(r);
    string res;
    for (int i = 0;i < n;i++) {
        bool ret = regex_match(titles[i], reg);
        if(i != n-1) {
          res+= ret ? "True,":"False,";
        }else{
          res += ret ? "True":"False";
        }
    }
    return res;
}

int main() {
  //  You can add more test cases here
  std::vector<std::string> testTitles1 = {"adcdcefdfeffe", "adcdcefdfeff",
                                          "dcdcefdfeffe", "adcdcfe"};
  std::vector<std::string> testTitles2 = {
      "CLSomGhcQNvFuzENTAMLCqxBdj", "CLSomNvFuXTASzENTAMLCqxBdj",
      "CLSomFuXTASzExBdj",          "CLSoQNvFuMLCqxBdj",
      "SovFuXTASzENTAMLCq",         "mGhcQNvFuXTASzENTAMLCqx"};
  std::vector<std::string> testTitles3 = {"abcdefg", "abefg", "efg"};

  std::cout << (solution(4, "ad{xyz}cdc{y}f{x}e", testTitles1) ==
                "True,False,False,True")
            << std::endl;
  std::cout << (solution(6, "{xxx}h{cQ}N{vF}u{XTA}S{NTA}MLCq{yyy}",
                         testTitles2) == "False,False,False,False,False,True")
            << std::endl;
  std::cout << (solution(3, "a{bdc}efg", testTitles3) == "True,True,False")
            << std::endl;

  return 0;
}