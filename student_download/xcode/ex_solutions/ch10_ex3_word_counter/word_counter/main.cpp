#include <iostream>
#include <fstream>
#include <string>
#include <set>
//#include <vector>
//#include <map>

using namespace std;

//void display_text(string filename);
multiset<string> display_and_load_words(string filename);
set<string> get_unique_words(multiset<string>& words);
//map<string, int> get_word_count(const multiset<string>& words);

string get_fulll_path() {
    // set a full path to the correct directory
    const char* home = getenv("HOME");
    string user_home = "";
    if (home) {
        user_home = home;
    }
    else {
        // if home isn't found, edit 'username' so it's correct for your system
        user_home = "/Users/username";
    }
    string file_path = "/Documents/murach/cpp/files/";
    return user_home + file_path;
}

int main() {
    cout << "The Word Counter program\n\n";

    string filename = "dickens.txt";

	cout << "FILE TEXT: ";
	//display_text(filename);

    auto words = display_and_load_words(get_fulll_path() + filename);
	cout << "WORD COUNT: " << words.size() << endl << endl;

    //cout << words.size() << " WORDS: ";
    //for (string word : words) {
    //    cout << word << ' ';
    //}
    //cout << endl << endl;

    //auto word_count = get_word_count(words);
	auto unique_words = get_unique_words(words);

    cout << unique_words.size() << " UNIQUE WORDS: ";
	for (string word : unique_words) {
		cout << word << ' ';
	}
    //for (auto pair : word_count) {
    //    cout << pair.first << ' ';
    //}
    cout << endl << endl;

    cout << "COUNT PER WORD: ";
	for (string word : unique_words) {
		cout << word << '=' << words.count(word) << ' ';
	}
    //for (auto pair : word_count) {
    //    cout << pair.first << '=' << pair.second << ' ';
    //}
    cout << endl << endl;
}

//void display_text(string filename) {
//	ifstream infile(filename);
//
//	if (infile) {
//		string line;
//		while (getline(infile, line)) {
//			cout << line << endl;
//		}
//		infile.close();
//		cout << endl;
//	}
//}
multiset<string> display_and_load_words(string filename) {
    multiset<string> words;
    ifstream infile(filename);

    if (infile) {
        string word;
        while (infile >> word) {
			cout << word << ' ';

            string new_word = "";
            for (char c : word) {
                if (c == '.' || c == ',') {
                    continue;               // remove punctuation
                }
                else if (isupper(c)) {
                    new_word += tolower(c); // convert to lowercase
                }
                else {
                    new_word += c;
                }
            }
            words.insert(new_word);      // add word 
        }
		cout << endl << endl;
        infile.close();
    }
    return words;
}

//map<string, int> get_word_count(const vector<string>& words) {
//    map<string, int> word_count{};
//
//    for (string word : words) {
//        auto search = word_count.find(word);
//        if (search == word_count.end()) {
//            word_count[word] = 1;   // not found - add word with count of 1
//        }
//        else {
//            word_count[word] += 1;  // found - increment count for word
//        }
//    }
//    return word_count;
//}

set<string> get_unique_words(multiset<string>& words) {
	set<string> unique_words;

	for (string word : words) {
		auto search = unique_words.find(word);
		if (search == unique_words.end()) {
			unique_words.insert(word);
		}
	}
	return unique_words;
}
