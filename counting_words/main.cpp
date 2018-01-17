#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::istream;
using std::vector;

vector<string> split(const string &s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            i++;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != s.size() && !isspace(s[j]))
            j++;
        // if we found some non-whitespace characters
        if (i != j){
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

map<string, vector<int>>
xref(istream &in, vector<string> find_words(const string &) = split) {
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    while (getline(in, line)) {
        line_number++;
        vector<string> words = find_words(line);
        for (vector<string>::const_iterator i = words.begin(); i != words.end(); i++) {
            ret[*i].push_back(line_number);
        }
    }
    return ret;
}

int main() {
    map<string, vector<int>> ret = xref(cin); // calls split by default
    for (map<string, vector<int>>::const_iterator i = ret.begin(); i != ret.end(); i++) {
        cout << i->first << " occurs on lines(s): ";
        vector<int>::const_iterator num_it = i->second.begin();
        cout << *num_it;
        num_it++;
        while (num_it != i->second.end()) {
            cout << ", " << *num_it;
            num_it++;
        }
        cout << endl;
    }
    return 0;
}
