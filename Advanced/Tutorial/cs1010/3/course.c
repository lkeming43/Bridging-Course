#include<stdio.h>
#define MAX_STUDENTS 30

int secondMostNumOfCourse(int enrol[][MAX_STUDENTS], int numStudents, int numClasses)
{
    int courses[numStudents], i, j, temp; 
    for (i = 0; i < numStudents; i++) courses[i] = 0;        

    for(j=0;j<numStudents;j++)
    {
        for(i=0;i<numClasses;i++)
        {
            courses[j] += enrol[i][j];
        }
    }

    for(i=0;i<numStudents-1;i++)
    {
        for(j=0;j<numStudents-i-1;j++)
        {
            if(courses[j] > courses[j+1])
            {
                temp = courses[j];
                courses[j] = courses[j+1];
                courses[j+1] = courses[j];
            }
        }
    }

    return courses[numStudents - 2];
}

int *mostPopularNumOfCourses(int enrol[][MAX_STUDENTS], int numStudents, int numClasses)
{
    int courses[numStudents], i, j, temp; 
    for (i = 0; i < numStudents; i++) courses[i] = 0;        

    for(j=0;j<numStudents;j++)
    {
        for(i=0;i<numClasses;i++)
        {
            courses[j] += enrol[i][j];
        }
    }

    for(i=0;i<numStudents-1;i++)
    {
        for(j=0;j<numStudents-i-1;j++)
        {
            if(courses[j] > courses[j+1])
            {
                temp = courses[j];
                courses[j] = courses[j+1];
                courses[j+1] = temp;
            }
        }
    }

    int occ[numStudents][2], flag = 1, temp, max[numStudents];
    for(j=0;j<numStudents;j++)
    {
        for(i=0;i<2;i++)
        {
            occ[j][i] = 0;
        }
    }

    occ[0][0] = courses[0];
    j = 0;

    for(i=0;i<numStudents;i++)
    {
        if(courses[i] != occ[j][0])
        {
            j++;
            occ[j][0] = courses[i];
            occ[j][1]++;
        }

        else occ[j][0]++;
    }

    while(flag)
    {
        flag = 0;
        for(i=0;i<j;i++)
        {
            if(occ[i][1] > occ[i+1][1])
            {
                temp = occ[i][1];
                occ[i][1] = occ[i+1][1];
                occ[i+1][1] = temp;
                flag = 1;
            }
        }
    }

    max[0] = occ[j][0];
    int p = 0;
    for(i = j - 2;i >= 0;i++)
    {
        if(occ[i][1] == occ[i+1][1])
        {
            max[++p] = occ[i][1];
        }

        else break;
    }

    return max;
}

//更好的方法
int* mostPopularNumOfCourses(int enrol[][MAX_STUDENTS], int numStudents, int numClasses, int *returnSize) 
{
    int courseCounts[MAX_STUDENTS] = {0};
    int freq[101] = {0}; // 课程数最多不会超过100（每个学生最多选100门）
    int maxFreq = 0;

    // 统计每个学生选了多少门课
    for (int j = 0; j < numStudents; j++) 
    {
        for (int i = 0; i < numClasses; i++) 
        {
            courseCounts[j] += enrol[i][j];
        }
        freq[courseCounts[j]]++;//这个课程数量出现的频率
        if (freq[courseCounts[j]] > maxFreq)
            maxFreq = freq[courseCounts[j]];
    }

    // 统计有多少种课程数是最热门的
    int* result = malloc(sizeof(int) * numStudents); // 最多不会超过 numStudents 个
    int count = 0;
    for (int i = 0; i <= 100; i++) 
    {
        if (freq[i] == maxFreq) //i是选课的数量，freq[i]是这个选课数量的出现次数
        {
            result[count++] = i;
        }
    }

    *returnSize = count;
    return result;
}