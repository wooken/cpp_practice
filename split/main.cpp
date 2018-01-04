#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
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

void main1() {
    string s;
    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split(s);
        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }
}

void main2() {
    string s;
    while (cin >> s) {
        cout << s << endl;
    }
}

int main() {
    main1();
    //main2();
    return 0;
}
