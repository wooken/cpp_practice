#ifndef GRADE_H
#define GRADE_H

#include <vector>

#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const Student_info &);
double grade_aux(const Student_info &);

#endif
