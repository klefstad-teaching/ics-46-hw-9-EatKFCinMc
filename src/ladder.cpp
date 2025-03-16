#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout<<"Error! "<<word1<<" "<<word2<<" "<<msg<<endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {

}

bool is_adjacent(const string& word1, const string& word2) {
    int l1 = word1.length(), l2 = word2.length();
    if (abs(l1 - l2) > 1) return false;
    int l = l1 ? l2 : l1 < l2, count = 0;
    for (int i = 0; i < l; ++i) {
        if (word1[i] != word2[i]) {
            ++count;
            if (count >= 2)return false;
        }
    }
    return true;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder;
    ladder.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    int i = 1;
    while (!ladder.empty()) {
        vector<string> temp = ladder.front();
        ladder.pop();
        string last = temp[temp.size() - 1];
        for (auto w : word_list) {
            if (is_adjacent(w, last)) {
                visited.insert(w);
                vector<string >new_temp = temp;
                new_temp.push_back(w);
                if (w == end_word)return new_temp;
                ladder.push(new_temp);
            }
            ++i;
            cout<<i<<endl;
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
