#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <string>
#include <vector>

#include "Student_info.h"

using std::string;
using std::vector;
using std::ostream;

double median_analysis(const vector<Student_info> &students);
double average_analysis(const vector<Student_info> &students);
double optimistic_median_analysis(const vector<Student_info> &students);
void write_analysis(ostream &out, const string &name,
        double analysis(const vector<Student_info> &),
        const vector<Student_info> &did,
        const vector<Student_info> &didnt);

#endif
