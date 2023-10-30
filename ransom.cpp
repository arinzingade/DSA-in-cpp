#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dic;

        for (char c : magazine) {
            dic[c]++;
        }

        for (char c : ransomNote) {
            if (dic.find(c) != dic.end() && dic[c] > 0) {
                dic[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    
    bool res = sol.canConstruct(ransomNote, magazine);

    if (res) {
        cout << "You can construct the ransom note from the magazine." << endl;
    } else {
        cout << "You cannot construct the ransom note from the magazine." << endl;
    }

    return 0;
}
