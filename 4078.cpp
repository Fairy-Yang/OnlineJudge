#include<iostream>
using namespace std;

int main()
{
    // 成绩表排序找同学
/*编写一个程序，读入 N 个同学的姓名和语数外三门功课
的单科成绩，对其按照一定的排序规则排序形成一张成绩表
（先按总分从高到低排序，总分相同则按语文成绩由高到低
排序，仍然相同则按数学成绩由高到低排序，若总分和单科
成绩均相同则最后按姓名的字典序排序）。最后给定一个数
字 K(K<=N) ，输出在这张排好序的成绩表中位置在第 K 位
的同学的姓名和总分。*/
// test 01
struct studentT
{
    char name[20];
    int chinese;
    int math;
    int english;
    int sum;
};

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    studentT studentarray[1200], tempT;
    int i, n, j, k;
    bool flagSum;
    cin>>n;}

    //输入学生信息和成绩
    for(i = 0; i < n; ++i)
    {
        cin>> studentarray[i].name;
        cin>> studentarray[i].chinese;
        cin>> studentarray[i].math;
        cin>> studentarray[i].english;
        studentarray[i].sum = studentarray[i].chinese + studentarray[i].math + studentarray[i].english;
    }

    cin>>k;
    if(n==1)
        {cout<< studentarray[k-1].name << " ";
        cout<< studentarray[k-1].sum;
        return 0;}

    for (i = 1; i < n; ++i)
    {
        for(j = 0; j < n-i; ++j)
        {
            flagSum =( studentarray[j].sum < studentarray[j+1].sum );
            if(flagSum)
            {
                tempT = studentarray[j];
                studentarray[j] = studentarray[j+1];
                studentarray[j+1] = tempT;
            }

        }
    }

    for (i = 1; i < n; ++i)
    {
        for(j = 0; j < n-i; ++j)
        {
            if( studentarray[j].sum == studentarray[j+1].sum)
            {
                if( studentarray[j].chinese < studentarray[j+1].chinese )
                {
                    tempT = studentarray[j];
                    studentarray[j] = studentarray[j+1];
                    studentarray[j+1] = tempT;
                }
            }
        }
    }

    for (i = 1; i < n; ++i)
    {
       for(j = 0; j < n-i; ++j)
        {
            if( studentarray[j].chinese == studentarray[j+1].chinese)
            {
                if( studentarray[j].math < studentarray[j+1].math )
                {
                    tempT = studentarray[j];
                    studentarray[j] = studentarray[j+1];
                    studentarray[j+1] = tempT;
                }
            }
        }

    }

    for(i = 1; i < n; ++i)
    {
      for(j = 0; j < n-i; ++j)
        {
            if( studentarray[j].math == studentarray[j+1].math)
            {
                for(int m=0;; ++m)
                {
                    if(studentarray[j].name[m] == '\0') break;

                    else if(studentarray[j+1].name[m] =='\0')
                    {
                        tempT = studentarray[j];
                        studentarray[j] = studentarray[j+1];
                        studentarray[j+1] = tempT;
                        break;
                    }

                    else {
                        if(studentarray[j].name[m] > studentarray[j+1].name[m])

                        {tempT = studentarray[j];
                        studentarray[j] = studentarray[j+1];
                        studentarray[j+1] = tempT;
                        break;}
                    }

                }
            }
        }
    }

    cout<< studentarray[k-1].name << " ";
    cout<< studentarray[k-1].sum;
}

}
