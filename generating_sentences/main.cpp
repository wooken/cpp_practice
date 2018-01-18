#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::find; // algorithm
using std::istream;
using std::length_error;
using std::logic_error;
using std::map;
using std::rand; // cstdlib
using std::string;
using std::vector;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

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

Grammar read_grammar(istream &in) {
    Grammar ret;
    string line;
    while (getline(in, line)) {
        vector<string> entry = split(line);
        if(!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}

bool bracketed(const string &s) {
    return s.size() > 1 && s[0] == '<' && s[s.size()-1] == '>';
}

// Return a random integer in the range [0, n)
//
// Divide RAND_MAX into buckets and return when rand() returns a number that
// fits into a bucket.
//
// e.g. [0, bucket_size) goes into bucket 1
//      [bucket_size, bucket_size * 2) goes into bucket 2
//      and so on...
//
// This imitates a more uniform distribution.
int nrand(int n) {
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX / n;
    int r;
    do {
        r = rand() / bucket_size;
    } while (r >= n);
    return r;
}

void gen_aux(const Grammar &g, const string &word, vector<string> &ret) {
    if (!bracketed(word)) {
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection &c = it->second;

        // from which we select one at random
        const Rule &r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator jt = r.begin(); jt != r.end(); jt++) {
            gen_aux(g, *jt, ret);
        }
    }
}

vector<string> gen_sentence(const Grammar &g) {
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

void rand_sentence(const Grammar &g) {
    vector<string> sen = gen_sentence(g);
    if (sen.empty()) {
        cout << "Error: empty vector" << endl;
        throw length_error("Empty sentence generated.");
    }
    vector<string>::const_iterator it = sen.begin();
    cout << *it;
    it++;
    while (it != sen.end()) {
        cout << " " << *it;
        it++;
    }
    cout << endl;
}

int main() {
    Grammar g = read_grammar(cin);
    int num = 10;
    for (int i = 0; i != num; i++) {
        rand_sentence(g);
    }
    return 0;
}
