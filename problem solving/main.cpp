#include <iostream>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;


class LCS {
public:
	int LongestCommonSubsequence(string text1, string text2) {
		int n = text1.length(), m = text2.length();
		if(n==0 || m==0)
			return 0;

		int **c;
		c = new int *[n + 1];
		for (int i = 0; i < n + 1; ++i)
			c[i] = new int[m + 1];

		for (int i = 0; i < n + 1; i++)
			c[i][0] = 0;
		for (int i = 0; i < m + 1; i++)
			c[0][i] = 0;

		for (int i = 1; i < n + 1; ++i)
			for(int j = 1; j < m + 1; ++j)
			{
				if(text1[i] == text2[j])
					c[i][j] = c[i - 1][j - 1] + 1;
				else
				{
					int tmp = max(c[i - 1][j], c[i][j - 1]);
					c[i][j] = tmp;
				}
			}
		return c[n][m];
	}
};


class WIS {
public:
	int WeightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
		int n = startTime.size();
		int m[n + 1];
		for (int i = 0; i < n + 1; ++i)
			m[i] = 0;

		for (int j = 0; j < n; ++j)
			m[j+1] = max(profit[j] + m[p(startTime, endTime, j)], m[j - 1]);
		return m[n];
	}

	int p(vector<int> &s, vector<int> &f, int i)
	{
		int j = i-1;
		while (j >= 0 && f[j] > s[i])
			--j;

		return j+1;
	}
};


class KP {
public:
	int KnapsackProblem(vector<int> &weight, vector<int> &value, int W) {
		int **m;
		int n = value.size();
		m = new int *[n + 1];
		for (int i = 0; i < n + 1; ++i)
			m[i] = new int[W + 1];

		for (int i = 0; i < W+1; ++i)
			m[0][i] = 0;
		for (int i = 0; i < n + 1; ++i)
			m[i][0] = 0;

		int Wet_tmp[n];
		Wet_tmp[0] = weight[0];
		for (int i = 1; i < n; ++i)
			Wet_tmp[i] = Wet_tmp[i - 1] + weight[i];

		for (int i = 1; i <= n; ++i)
		{
			for (int w = 1; w <= W; ++w)
				if (weight[i-1] > w)
					m[i][w] = m[i - 1][w];
				else
				{
					int tmp = max(value[i - 1] + m[i - 1][w - weight[i - 1]], m[i - 1][w]);
					m[i][w] = tmp;
				}
		}

		return m[n][W];
	}
};


// For testing
int main(int argc, const char * argv[]) {
	
	//*********** Test Longest Common Subsequence ***********//
	string text1 = "springtime";
	string text2 = "printing";
	LCS lcs = LCS();
	cout << "Test Longest Common Subsequence..." << endl;
	cout << lcs.LongestCommonSubsequence(text1, text2) << endl;
	cout << "The expected output: 6" << endl;
	cout << endl;
	
	//********** Test Weighted Interval Scheduling **********//
	vector<int> startTime = {1,2,3,4,6};
	vector<int> endTime = {3,5,9,6,9};
	vector<int> profit = {20,20,100,70,60};
	WIS wis = WIS();
	cout << "Test Weighted Interval Scheduling..." << endl;
	cout << wis.WeightedIntervalScheduling(startTime, endTime, profit) << endl;
	cout << "The expected output: 150" << endl;
	cout << endl;
	
	//*************** Test Knapsack Problem ****************//
	vector<int> weight = {1, 2, 5, 6, 7};
	vector<int> value = {1, 6, 18, 22, 28};
	int W = 11;
	KP kp = KP();
	cout << "Test Knapsack Problem..." << endl;
	cout << kp.KnapsackProblem(weight, value, W) << endl;
	cout << "The expected output: 40" << endl;
	cout << endl;
	system("pause");

	return 0;
}
