#include "../headers/header2.h"
#include <string.h>

int compareByName(const Student& s1, const Student& s2)
{
    return s1.getName().compare(s2.getName());
}

int compareByGrade(const Student& s1, const Student& s2)
{
    double Total1 = s1.getGradeEnglish()+s1.getGradeMath()+s1.getGradeHistory();
    double Total2 = s2.getGradeEnglish()+s2.getGradeMath()+s2.getGradeHistory();

    if(Total1==Total2) return 0;
    else if (Total1>Total2) return 1;
    else return -1;
}

int compareByAverage(const Student& s1, const Student& s2)
{
    if(s1.averageGrade()==s2.averageGrade()) return 0;
    else if(s1.averageGrade()>s2.averageGrade()) return 1;
    else return -1;
}