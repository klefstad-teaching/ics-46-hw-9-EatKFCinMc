#include "ladder.h"

#include <sstream>

void error(string word1, string word2, string msg) {
    cout<<"Error! "<<word1<<" "<<word2<<" "<<msg<<endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int n = str1.size(), m = str2.size();
    if (abs(n - m) > d) return false;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]);
        }
    }
    return dp[n][m] <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    // int l1 = word1.length(), l2 = word2.length();
    // if (abs(l1 - l2) > 1) return false;
    // int count = 0;
    //
    // if (l1 == l2) {
    //     for (int i = 0; i < l1; ++i) {
    //         if (word1[i] != word2[i]) {
    //             ++count;
    //             if (count >= 2)return false;
    //         }
    //     }
    //     return true;
    // }
    //
    // if (l1 < l2) return is_adjacent(word2, word1);
    //
    // int i = 0, j = 0;
    // bool flag = false;
    // while (i < l1 && j < l2) {
    //     if (word1[i] == word2[j]) {
    //         ++i;
    //         ++j;
    //     }else {
    //         if (flag) return false;
    //         flag = true;
    //         i++;
    //     }
    // }
    // return true;
    return edit_distance_within(word1, word2, 1);
}

map<string, vector<string>> generate_adjacency_list(set<string> word_list) {
    // map<string, vector<string>> map;
    // int count = 1;
    // for (auto e : word_list)
    //     for (auto w : word_list)
    //         if (is_adjacent(e, w) && e != w)
    //             map[e].push_back(w);
    //
    // return map;

    map<string, vector<string>> m;
    for (const auto &word : word_list) {
        for (size_t i = 0; i < word.size(); ++i) {
            string pattern = word;
            pattern[i] = '*';
            m[pattern].push_back(word);
        }
    }
    // int count = 1;
    map<string, vector<string>> adjacency;
    for (const auto &word : word_list) {
        set<string> neighbors;
        for (size_t i = 0; i < word.size(); ++i) {
            string pattern = word;
            pattern[i] = '*';
            if (m.count(pattern)) {
                for (const string &candidate : m[pattern]) {
                    if (candidate != word && is_adjacent(word, candidate)) {
                        neighbors.insert(candidate);
                    }
                }
            }
        }
        vector<string> neighbor_list(neighbors.begin(), neighbors.end());
        adjacency[word] = neighbor_list;
        // cout<<count++<<endl;
    }
    return adjacency;
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (!word_list.count(end_word))
        return {};

    queue<vector<string>> ladder;
    ladder.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    map<string, vector<string>> map = generate_adjacency_list(word_list);

    // int count = 1;
    while (!ladder.empty()) {
        vector<string> temp = ladder.front();
        ladder.pop();
        string last = temp[temp.size() - 1];
        if (last == end_word) return temp;

        for (auto w : map[last]) {
            if (!visited.count(w)) {
                visited.insert(w);
                vector<string> new_path = temp;
                new_path.push_back(w);
                ladder.push(new_path);
            }
            // if (is_adjacent(w, last)) {
            //     if (!visited.contains(w)) {
            //         visited.insert(w);
            //         vector<string >new_temp = temp;
            //         new_temp.push_back(w);
            //         if (w == end_word)return new_temp;
            //         ladder.push(new_temp);
            //     }
            // }
        }
        // cout<<count++<<endl;
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    fstream in(file_name);
    string temp;
    while (in>>temp)
        word_list.insert(temp);
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout<<"No word ladder found.";
        return;
    }
    cout<<"Word ladder found: ";
    for (auto e : ladder)
        cout<<e<<" ";
    cout<<endl;
}

void verify_word_ladder() {
    cout << "Enter a word ladder sequence separated by spaces:" << endl;
    string line;

    getline(cin, line);
    if (line.empty()) {
        getline(cin, line);
    }
    istringstream iss(line);
    vector<string> ladder;
    string word;
    while (iss >> word) {
        ladder.push_back(word);
    }

    bool valid = true;
    for (size_t i = 1; i < ladder.size(); i++) {
        if (!is_adjacent(ladder[i - 1], ladder[i])) {
            valid = false;
            break;
        }
    }
    if (valid)
        cout << "The word ladder is valid!" << endl;
    else
        cout << "The word ladder is not valid." << endl;
}
