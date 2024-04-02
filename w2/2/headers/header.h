#pragma once

#include <string>

using namespace std;

class Student
{

    string name;

    float gradeMath;
    float gradeHistory;
    float gradeEnglish;

    public:
    string getName() const;
    float getGradeMath() const;
    float getGradeHistory() const;
    float getGradeEnglish() const;

    void setName(string name1);
    void setGradeMath(float grade1);
    void setGradeHistory(float grade2);
    void setGradeEnglish(float grade3);

    float averageGrade() const;
};