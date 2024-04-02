#include "../headers/header.h"

void Student::setName(string name1)
{
    this->name=name1;
}

string Student::getName() const
{
    return name;
}

float Student::getGradeMath() const
{
    return gradeMath;
}

float Student::getGradeHistory() const
{
    return gradeHistory;
}

float Student::getGradeEnglish() const
{
    return gradeEnglish;
}


void Student::setGradeMath(float grade1)
{
    this->gradeMath=grade1;
}

void Student::setGradeHistory(float grade2)
{
    this->gradeHistory=grade2;
}

void Student::setGradeEnglish(float grade3)
{
    this->gradeEnglish=grade3;
}

float Student::averageGrade() const
{
    return (gradeMath + gradeHistory + gradeEnglish) / 3.0f;
}