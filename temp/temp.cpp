
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

std::string solution(const std::string& str1) {
    // Edit your code here
    unordered_map<char,int> hash;
    string rel = "";
    for(int i = 0;i < str1.length();i++){
        if(hash[str1[i]] == 0){
            rel = rel + str1[i];
            hash[str1[i]]++;
        }
        
    }
    cout << rel << endl;
    return rel;
}

int main() {
    // Add your test cases here
    
    std::cout << (solution("abbabbbabb") == "ab") << std::endl;
    std::cout << (solution("abbbabbbb") == "ab") << std::endl;
    std::cout << (solution("jiabanbananananiabanbananananbananananiabanbananananbananananbananananbanananan") == "jiaban") << std::endl;
    std::cout << (solution("selectecttectelectecttectcttectselectecttectelectecttectcttectectelectecttectcttectectcttectectcttectectcttect") == "select") << std::endl;
    std::cout << (solution("discussssscussssiscussssscussssdiscussssscussssiscussssscussssiscussssscussss") == "discus") << std::endl;
    cout << "hello " << endl;
    return 0;
}
