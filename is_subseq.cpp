
#include <iostream>
using namespace std;

class Solution {

    public:
        bool isSubseq(string s, string t) {
            
            int i = 0;
            int j = 0;
            int count = 0;

            while (s[i] != '\0' && t[j] != '\0') {
                
                if (s[i] == t[j]) {
                    i++;
                    j++;
                    count++;
                }

                else {
                    j++;
                }

            }

            return (count == s.size());

        }
};

int main () {

    string s = "abc";
    string t = "ahbgdc";

    Solution sol;

    bool res = sol.isSubseq(s,t);

    if (res) {
        cout << "Yes it is a substring.";
    }

    else {
        cout << "It is not a substring";
    }
}