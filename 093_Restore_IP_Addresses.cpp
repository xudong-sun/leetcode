/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "essentials.h"

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        result.clear();
        restoreIpAddresses("", s, 0, 4);
        return result;
    }
private:
    void restoreIpAddresses(std::string ans, const std::string& s, int ptr, int remain) {
        int ls = s.size();
        if (remain == 0) {
            if (ptr == ls) result.push_back(ans);
            return;
        }
        if (ls - ptr < remain || ls - ptr > 3 * remain) return;
        if (s[ptr] == '0') {
            restoreIpAddresses(appendIp(ans, "0", remain), s, ptr + 1, remain - 1);
        }
        else {
            int z = ls - ptr >= 3 ? 3 : ls - ptr;
            for (int i = 1; i <= z; i++) {
                std::string str = s.substr(ptr, i);
                int num = stoi(str);
                if (num >= 0 && num <= 255) restoreIpAddresses(appendIp(ans, str, remain), s, ptr + i, remain - 1);
            }
        }
    }
    std::string appendIp(const std::string& s1, const std::string& s2, int remain) {
        return remain == 4 ? s2 : s1 + '.' + s2;
    }
    std::vector<std::string> result;
};

int main(int argc, char *argv[]) {
    auto sol = std::make_unique<Solution>();
    commons::print(sol->restoreIpAddresses("25525511135")); // 255.255.11.135, 255.255.111.35
    commons::print(sol->restoreIpAddresses("11111")); // 1.1.1.11, 1.1.11.1, 1.11.1.1, 11.1.1.1
    commons::print(sol->restoreIpAddresses("1110111")); // 11 results
    commons::print(sol->restoreIpAddresses("122")); // []
    commons::print(sol->restoreIpAddresses("1231231231231")); // []
    commons::print(sol->restoreIpAddresses("0000")); // 0.0.0.0
    return 0;
}

