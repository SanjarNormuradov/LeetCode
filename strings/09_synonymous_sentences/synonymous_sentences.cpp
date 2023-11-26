#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> generateSentences(const vector<vector<string>>& synonyms, const string& text) {
        if (!checkConstraints(synonyms, text)) {
            throw std::runtime_error("Constraints violated");
        }
        // Initialize Union-Find structure for grouping synonyms
        UnionFind uf;
        for (auto& p : synonyms) {
            uf.unionSet(p[0], p[1]);
        }

        // Group words into root: (root, synonyms)
        unordered_map<string, set<string>> groupSynonyms;
        for (auto& p : synonyms) {
            string root = uf.find(p[0]);
            groupSynonyms[root].insert(p[0]);
            groupSynonyms[root].insert(p[1]);
        }

        // Split the input text into words
        vector<string> words;
        string word;
        istringstream iss(text);
        while (iss >> word) {
            words.push_back(word);
        }

        vector<string> sentences;
        generateSentence(0, words, groupSynonyms, uf, "", sentences);
        // sort(sentences.begin(), sentences.end());
        return sentences;
    return sentences;
    }

private:
    // Union-Find class for efficient grouping
    class UnionFind {
        unordered_map<string, string> parent;

    public:
        // Find the root of the set that element x belongs to
        string find(string x) {
            // Initialize x as independent element
            if (!parent.count(x)) parent[x] = x;
            // Find the parent of x, i.e. an independent element
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        }

        // Union two sets represented by elements x and y
        void unionSet(string x, string y) {
            // Initialize y as dependent on x
            parent[find(x)] = find(y);
        } 
    };

    void generateSentence(int index, vector<string>& words, unordered_map<string, set<string>>& groupSynonyms, UnionFind& uf, string current, vector<string>& sentences) {
        // Base case: if we've reached the end of the words list
        if (index == words.size()) {
            sentences.push_back(current);
            return;
        }

        // Add space between words, but not before the first word
        string separator = index == 0 ? "" : " ";
        // Find the root of the current word to identify its synonym group
        string root = uf.find(words[index]);
        // If the word has synonyms, recursively explore each possibility
        if (groupSynonyms.count(root)) {
            for (const auto& synonym : groupSynonyms[root]) {
                generateSentence(index + 1, words, groupSynonyms, uf, current + separator + synonym, sentences);
            }
        } else {
            // If no synonyms, continue with the original word
            generateSentence(index + 1, words, groupSynonyms, uf, current + separator + words[index], sentences);
        }
    }

    // Helper function to check the constraints
    bool checkConstraints(const vector<vector<string>>& syn, const string& text) {
        if (syn.size() < 0 || syn.size() > 10) return false;
        set<string> syns;
        for (int i = 0; i < syn.size(); i++) {
            if (syn[i].size() != 2) return false;
            if (syn[i][0].size() < 1 || syn[i][0].size() > 10 || syn[i][1].size() < 1 || syn[i][1].size() > 10) return false;
            if (syn[i][0] == syn[i][1]) return false;
            if (syns.find(syn[i][0]) != syns.end() && syns.find(syn[i][1]) != syns.end()) return false;
            syns.insert(syn[i][0]);
            syns.insert(syn[i][1]);
        }
        int cnt_words = 0;
        string word;
        istringstream iss(text);
        while (iss >> word) cnt_words++;
        if (cnt_words > 10) return false;

        return true;
    }
};
