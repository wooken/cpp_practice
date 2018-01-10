#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::find; // algorithm
using std::find_if; // algorithm
using std::isalnum; // cctype
using std::isalpha; // cctype
using std::search; // algorithm
using std::string;
using std::vector;

bool not_url_char(char c) {
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator
url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        // make sure the separator isn't at the beginning or end of the line
        if (i != b && i + sep.size() != e) {
            // beg marks the beginning of the protocol-name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                beg--;
        // is there at least one appropriate character before and after the separator?
        if (beg != i && !not_url_char(i[sep.size()]))
            return beg;
        }
        // the separator we found wasn't part of a URL, advance i past this separator
        i += sep.size();
    }
    return e;
}

vector<string> find_urls(const string &s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while (b != e) {
        // look for one or more letters followed by ://
        b = url_beg(b, e);

        if (b != e) {
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> urls = find_urls(s);
    for (vector<string>::size_type i = 0; i != urls.size(); i++) {
        cout << urls[i] << endl;
    }
    return 0;
}
