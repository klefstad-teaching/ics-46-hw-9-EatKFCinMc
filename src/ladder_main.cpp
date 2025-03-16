#include "ladder.h"

int main() {
    string file_name = "../src/words.txt";
    set<string> word_list;
    load_words(word_list, file_name);

    vector<string> ladder = generate_word_ladder("abase", "abated", word_list);

    print_word_ladder(ladder);
}