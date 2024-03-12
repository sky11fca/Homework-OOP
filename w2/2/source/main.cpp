#include <iostream>
#include "../headers/header.h"
#include "../headers/header2.h"

int main() {
    // Creating students

    Student s1, s2;
    s1.setName("Marcel");
    s1.setGradeMath(3.5);
    s1.setGradeEnglish(4.0);
    s1.setGradeHistory(3.0);

    s2.setName("Jennifer");
    s2.setGradeMath(9.5);
    s2.setGradeEnglish(8.0);
    s2.setGradeHistory(9.7);

    // Demonstrating getters
    cout << "Student 1: " << s1.getName() << endl;
    cout << "Math Grade: " << s1.getGradeMath() << endl;
    cout << "English Grade: " << s1.getGradeEnglish() << endl;
    cout << "History Grade: " << s1.getGradeHistory() << endl;

    // Demonstrating setters
    s1.setName("John Doe");
    s1.setGradeMath(9.0);
    s1.setGradeEnglish(8.5);
    s1.setGradeHistory(7.8);

    cout << "Updated Student 1: " << s1.getName() << endl;
    cout << "Updated Math Grade: " << s1.getGradeMath() << endl;
    cout << "Updated English Grade: " << s1.getGradeEnglish() << endl;
    cout << "Updated History Grade: " << s1.getGradeHistory() << endl;

    // Demonstrating average grade
    cout << "Average Grade of Student 1: " << s1.averageGrade() << endl;

    // Comparing students
    cout << "Comparison by Name: " << compareByName(s1, s2) << endl;
    cout << "Comparison by Grades: " << compareByGrades(s1, s2) << endl;
    cout << "Comparison by Average: " << compareByAverage(s1, s2) << endl;

    return 0;
}