#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // find_if

using std::cin;
using std::cout;
using std::endl;
using std::find_if;
using std::string;
using std::vector;

// split_func1() code ---------------------------------------------------------
vector<string> split_func1_helper(const string &s) {
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

void split_func1() {
    string s;
    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split_func1_helper(s);
        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
}

// end split_func1() code -----------------------------------------------------

// split_func3() code ---------------------------------------------------------
bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}

// uses iterators and find_if() from <algorithm>
vector<string> split_func3_helper(const string &str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy the characters in [i, j)
        if (i != str.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}

void split_func3() {
    string s;
    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split_func3_helper(s);
        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
}
// end split_func3() code -----------------------------------------------------

void split_func2() {
    string s;
    while (cin >> s) {
        cout << s << endl;
    }
}

int main() {
    //split_func1();
    //split_func2();
    split_func3();
    return 0;
}
