#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout<<"Error! "<<word1<<" "<<word2<<" "<<msg<<endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {

}

bool is_adjacent(const string& word1, const string& word2) {
    int l1 = word1.length(), l2 = word2.length();
    if (abs(l1 - l2) > 1) return false;
    int count = 0;

    if (l1 == l2) {
        for (int i = 0; i < l1; ++i) {
            if (word1[i] != word2[i]) {
                ++count;
                if (count >= 2)return false;
            }
        }
        return true;
    }

    if (l1 < l2) return is_adjacent(word2, word1);


    int i = 0, j = 0;
    bool flag = false;
    while (i < l1 && j < l2) {
        if (word1[i] == word2[j]) {
            ++i;
            ++j;
        }else {
            if (flag) return false;
            flag = true;
            i++;
        }
    }
    return true;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder;
    ladder.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder.empty()) {
        vector<string> temp = ladder.front();
        ladder.pop();
        string last = temp[temp.size() - 1];
        for (auto w : word_list) {
            if (is_adjacent(w, last)) {
                if (!visited.contains(w)) {
                    visited.insert(w);
                    vector<string >new_temp = temp;
                    new_temp.push_back(w);
                    if (w == end_word)return new_temp;
                    ladder.push(new_temp);
                }
            }
        }
    }
    vector<string> r = {};
    return r;
}

void load_words(set<string> & word_list, const string& file_name) {
    fstream in(file_name);
    string temp;
    while (in>>temp)
        word_list.insert(temp);
}

void print_word_ladder(const vector<string>& ladder) {
    for (auto e : ladder)
        cout<<e<<" ";
}

void verify_word_ladder() {

}
