#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>

#include "median.h"
#include "Student_info.h"
#include "grade.h"

using std::accumulate; // numeric
using std::domain_error; // stdexcept
using std::remove_copy; // algorithm
using std::sort; // algorithm
using std::vector;

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// median of the nonzero elements of s.homework, or 0, if no such elements exist
double optimistic_median(const Student_info &s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double average(const vector<double> &v) {
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info &s) {
    return grade(s.midterm, s.final, average(s.homework));
}
