//file:学生成绩管理系统.app
//1-添加学生信息
//2-显示全部学生信息
//3-按学号查询学生信息
//4-按姓名查询学生信息
//5-按学号升序排序
//6-按成绩降序排序
//7-退出

#include<iostream>
#include<cstring>
using namespace std;

struct studentT{
    char code[10];
    char name[20];
    int grade;
    int k;
} studentarray1[20000],studentarray2[20000];

//1-添加学生信息
void add_information(studentT studentarray[],char code[], char name[], int grade);
//2-显示全部学生信息
void pnt_all_information(studentT studentarray[]);
//3-按学号查询学生信息
void code_to_search(char code[]);
//4-按姓名查询学生信息
void name_to_search(char name[]);
//5-按学号升序排序
void code_increase_sort(studentT studentarray[]);
//6-按成绩降序排序
void grade_decrease_sort(studentT studentarray[]);
//判断数组studentarray中是否含有code
bool compare(char code[],studentT studentarray[]);

//k，记录添加学生顺序,同时记录学生人数（k+1）,同时作为存储的计数变量；
int k=0;
int main()
{
    //初始化数组：1用于记录，2用于排序；
    strcpy(studentarray1[0].code , "NULL");
    strcpy(studentarray2[0].code , "NULL");
    int n, grade;
    char code[100], name[200];

    while(true)
    {
        cin>>n;
        switch(n)
        {
            case 1:
                {
                    cin>>code;cin>>name;cin>>grade;
                    if(compare(code,studentarray1))
                    {
                        add_information(studentarray1, code, name, grade);
                        add_information(studentarray2, code, name, grade);
                        cout<<"SUCCESS"<<endl;
                        k++;
                    }
                    else
                    {cout<<"FAILED"<<endl;}
                    break;
                }
            case 2: pnt_all_information(studentarray1);break;
            case 3: cin>>code;code_to_search(code); break;
            case 4: cin>>name;name_to_search(name); break;
            case 5: code_increase_sort ( studentarray2 ); break;
            case 6: grade_decrease_sort ( studentarray2 ); break;
            case 7: cout<<"END";return 0;
        }
    }
}
//1-添加学生信息
void add_information(studentT studentarray[], char code[], char name[], int grade)
{
    strcpy(studentarray[k].code , code);
    strcpy(studentarray[k].name , name);
    studentarray[k].grade = grade;
    studentarray[k].k=k;
    strcpy(studentarray[k+1].code , "NULL");
}
//2-显示全部学生信息
void pnt_all_information( studentT studentarray[])
{
    for(int i = 0; strcmp(studentarray[i].code , "NULL") != 0;++i)
        cout<<studentarray[i].code<<" "<<studentarray[i].name<<" "<<studentarray[i].grade<<endl;
}
//3-按学号查询学生信息
void code_to_search(char code[])
{
    for(int i = 0; strcmp(studentarray1[i].code , "NULL") != 0;++i)
        if(strcmp(studentarray1[i].code , code) == 0)
        cout<<studentarray1[i].code<<" "<<studentarray1[i].name<<" "<<studentarray1[i].grade<<endl;
}
//4-按姓名查询学生信息
void name_to_search(char name[])
{
    for(int i = 0; strcmp(studentarray1[i].code , "NULL") != 0;++i)
        if(strcmp(studentarray1[i].name , name) == 0)
        cout<<studentarray1[i].code<<" "<<studentarray1[i].name<<" "<<studentarray1[i].grade<<endl;
}
//5-按学号升序排序
void code_increase_sort(studentT studentarray[])
{
    studentT tmp;
    if( k == 0) return;
    else if(k == 1)
    {cout<<studentarray[0].code<<" "<<studentarray[0].name<<" "<<studentarray[0].grade<<endl;return;}
    else
    {
        for(int i = 1; strcmp(studentarray1[i].code,"NULL") != 0; ++i)
            for(int j=0; j<k; ++j)
            {
                if(strcmp(studentarray[j].code, studentarray[i].code) > 0)
                {
                    tmp = studentarray[i];
                    studentarray[i] = studentarray[j];
                    studentarray[j] = tmp;
                }
            }
    }
    pnt_all_information(studentarray);
}
//6-按成绩降序排序
void grade_decrease_sort(studentT studentarray[])
{
    studentT tmp;
    if( k == 0) return;
    else if(k == 1)
    {cout<<studentarray[0].code<<" "<<studentarray[0].name<<" "<<studentarray[0].grade<<endl;return;}
    else
    {
        for(int i = 1; strcmp(studentarray1[i].code,"NULL") != 0; ++i)
            for(int j=0; j<k; ++j)
            {
                if(studentarray[j].grade < studentarray[i].grade)
                {
                    tmp = studentarray[i];
                    studentarray[i] = studentarray[j];
                    studentarray[j] = tmp;
                }
                if(studentarray[j].grade == studentarray[i].grade)
                {
                    if(studentarray[j].k > studentarray[i].k)
                    {
                        tmp = studentarray[i];
                    studentarray[i] = studentarray[j];
                    studentarray[j] = tmp;
                    }
                }
            }
    }
    pnt_all_information(studentarray);
}
//判断数组studentarray中是否含有code
bool compare(char code[],studentT studentarray[])
{
    if(k==0) return true;
    for(int i=0; strcmp(studentarray[i].code ,"NULL");++i)
        if(strcmp(studentarray[i].code , code) == 0)
            return false;
    return true;
}
