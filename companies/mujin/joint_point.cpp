#include <iostream>
#include <string>

using namespace std;


int digitSum(int n) {
    /*Compute the sum of digits in the number.*/
    string num = to_string(n);
    int sum = 0;
    for (auto& d : num) {
        sum += d - '0';
    }
    return sum;
}


int nextNum(int n) {
    /*Find the next number in the sequence.*/
    return n + digitSum(n);
}


int findJointPoint(int s1, int s2) {
    /*Find the joint point of two sequences starting from s1 and s2.*/
    while (s1 != s2) {
        if (s1 < s2) {
            s1 = nextNum(s1);
        } else {
            s2 = nextNum(s2);
        }
    }
    return s1;
}

int main(int argc, char **argv) {
    int s1 = 34;
    int s2 = 40;
    cout << "Joint point of " << s1 << " and " << s2 << ": " << findJointPoint(s1, s2) << endl;
}