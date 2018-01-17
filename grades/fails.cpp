#include "grade.h"

bool fgrade(const Student_info &s) {
    return grade(s) < 60;
}

bool pgrade(const Student_info &s) {
    return !fgrade(s);
}

vector<Student_info>
extract_fails_2_pass(vector<Student_info>& students) {
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(),
            back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(),
            fgrade), students.end());
    return fail;
}

vector<Student_info>
extract_fails(vector<Student_info> &students) {
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fail(iter, students.end());
    students.erase(iter, students.end());
    return fail;
}
