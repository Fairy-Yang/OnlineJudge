#include<iostream>
using namespace std;

bool judge(int **s)
{
  //line judge
  for (int i = 0; i < 9;++i)
  { 
    int line_num[10]{0};
    for (int j = 0; j < 9; ++j)
    {
      if(++line_num[s[i][j]] > 1)
        return false;
    }
  }

  //row judge
  for (int i = 0; i < 9;++i)
  { 
    int row_num[10]{0};
    for (int j = 0; j < 9;++j)
    {
      if(++row_num[s[j][i]]>1)
        return false;
    }
  }

  //block judge
  
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9;j+=3)
    {
      int block_num[10]{0};
      for (int k = 0; k < 3;k++)
      {
        for (int m = 0; m < 3;m++)
          if(++ block_num[s[i+k][j+m]] > 1)
            return false;
      }
    }
  }
  return true;
}

int main()
{
  int **sudoku, n;
  int i, j;
  sudoku = new int *[9];
  for (int i = 0; i < 9;++i)
    sudoku[i] = new int[9];
  cin >> n;
  while(n-->0)
  {
    for (i = 0; i < 9;++i)
      for (j = 0; j < 9; ++j)
        cin >> sudoku[i][j];
    if(judge(sudoku))
      cout << "Right\n";
    else
      cout << "Wrong\n";
  }
  return 0;
}