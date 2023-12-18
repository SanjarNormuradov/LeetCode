#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if (!checkConstraints(s)) {
            throw std::runtime_error("Constraints violated");
        }
        if (s.size() % 2 != 0) return false;
        stack<char, vector<char>> stck;
        for (auto& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stck.push(ch);
            } else {
                if (stck.empty()) return false;
                if (ch == ')') {
                    if (stck.top() == '(') stck.pop();
                    else return false;
                } else if (ch == '}') {
                    if (stck.top() == '{') stck.pop();
                    else return false;                 
                } else {
                    if (stck.top() == '[') stck.pop();
                    else return false;  
                }
            }
        }
        return stck.empty() ? true : false;
    }

private:
    bool checkConstraints(const string& s) {
        if (s.size() < 1 || s.size() > pow(10, 4)) return false;
        for (const char& ch : s) {
            if (!(ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')) return false;
        }
        return true;
    }
};