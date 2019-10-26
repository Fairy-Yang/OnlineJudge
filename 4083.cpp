//file:ѧ���ɼ�����ϵͳ.app
//1-���ѧ����Ϣ
//2-��ʾȫ��ѧ����Ϣ
//3-��ѧ�Ų�ѯѧ����Ϣ
//4-��������ѯѧ����Ϣ
//5-��ѧ����������
//6-���ɼ���������
//7-�˳�

#include<iostream>
#include<cstring>
using namespace std;

struct studentT{
    char code[10];
    char name[20];
    int grade;
    int k;
} studentarray1[20000],studentarray2[20000];

//1-���ѧ����Ϣ
void add_information(studentT studentarray[],char code[], char name[], int grade);
//2-��ʾȫ��ѧ����Ϣ
void pnt_all_information(studentT studentarray[]);
//3-��ѧ�Ų�ѯѧ����Ϣ
void code_to_search(char code[]);
//4-��������ѯѧ����Ϣ
void name_to_search(char name[]);
//5-��ѧ����������
void code_increase_sort(studentT studentarray[]);
//6-���ɼ���������
void grade_decrease_sort(studentT studentarray[]);
//�ж�����studentarray���Ƿ���code
bool compare(char code[],studentT studentarray[]);

//k����¼���ѧ��˳��,ͬʱ��¼ѧ��������k+1��,ͬʱ��Ϊ�洢�ļ���������
int k=0;
int main()
{
    //��ʼ�����飺1���ڼ�¼��2��������
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
//1-���ѧ����Ϣ
void add_information(studentT studentarray[], char code[], char name[], int grade)
{
    strcpy(studentarray[k].code , code);
    strcpy(studentarray[k].name , name);
    studentarray[k].grade = grade;
    studentarray[k].k=k;
    strcpy(studentarray[k+1].code , "NULL");
}
//2-��ʾȫ��ѧ����Ϣ
void pnt_all_information( studentT studentarray[])
{
    for(int i = 0; strcmp(studentarray[i].code , "NULL") != 0;++i)
        cout<<studentarray[i].code<<" "<<studentarray[i].name<<" "<<studentarray[i].grade<<endl;
}
//3-��ѧ�Ų�ѯѧ����Ϣ
void code_to_search(char code[])
{
    for(int i = 0; strcmp(studentarray1[i].code , "NULL") != 0;++i)
        if(strcmp(studentarray1[i].code , code) == 0)
        cout<<studentarray1[i].code<<" "<<studentarray1[i].name<<" "<<studentarray1[i].grade<<endl;
}
//4-��������ѯѧ����Ϣ
void name_to_search(char name[])
{
    for(int i = 0; strcmp(studentarray1[i].code , "NULL") != 0;++i)
        if(strcmp(studentarray1[i].name , name) == 0)
        cout<<studentarray1[i].code<<" "<<studentarray1[i].name<<" "<<studentarray1[i].grade<<endl;
}
//5-��ѧ����������
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
//6-���ɼ���������
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
//�ж�����studentarray���Ƿ���code
bool compare(char code[],studentT studentarray[])
{
    if(k==0) return true;
    for(int i=0; strcmp(studentarray[i].code ,"NULL");++i)
        if(strcmp(studentarray[i].code , code) == 0)
            return false;
    return true;
}
