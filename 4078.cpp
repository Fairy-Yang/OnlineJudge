#include<iostream>
using namespace std;

int main()
{
    // �ɼ���������ͬѧ
/*��дһ�����򣬶��� N ��ͬѧ�����������������Ź���
�ĵ��Ƴɼ������䰴��һ����������������γ�һ�ųɼ���
���Ȱ��ִܷӸߵ��������ܷ���ͬ�����ĳɼ��ɸߵ���
������Ȼ��ͬ����ѧ�ɼ��ɸߵ����������ֺܷ͵���
�ɼ�����ͬ������������ֵ������򣩡�������һ����
�� K(K<=N) ������������ź���ĳɼ�����λ���ڵ� K λ
��ͬѧ���������ܷ֡�*/
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

    //����ѧ����Ϣ�ͳɼ�
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
