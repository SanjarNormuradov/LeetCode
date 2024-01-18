#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <list>
#include <algorithm>

using namespace std;


class Node {
public:
    string name_;
    list<Node> children_;

    Node(const string& name, const list<Node>& children = {}) {
        name_ = name;
        children_ = children;
        }

    int countSameNodes(const string& search_name) const {
        // Convert both strings to lower case for case-insensitive comparison
        string lc_name = name_;
        string lc_search_name = search_name;
        transform(lc_name.begin(), lc_name.end(), lc_name.begin(), [](unsigned char ch) {
            return static_cast<char>(cToLower(ch));
        });
        transform(lc_search_name.begin(), lc_search_name.end(), lc_search_name.begin(), [](unsigned char ch) {
            return static_cast<char>(cToLower(ch));
        });

        int cnt = 0;
        // Check if this node's name matches
        if (lc_name == lc_search_name) {
            cnt++;
        }
        // Check all children recursively
        for (const auto& child : children_) {
            cnt += child.countSameNodes(search_name);
        }
        return cnt;
    }
private:
    static int cToLower(int c) {
        return tolower(c);
    }
};

int main(int argc, char **argv) {
    locale::global(locale("")); // Set global locale to user's environment
    Node n = Node("root", {
        Node("Coding", {Node("I"), Node("Love"), Node("coDing")}),
        Node("hello", {Node("Hello", {Node("World")})})
    });
    cout << n.countSameNodes("CODING") << endl;
    cout << n.countSameNodes("helLo") << endl;
    cout << n.countSameNodes("likE") << endl;
}