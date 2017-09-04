#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

/* 记录已放置皇后位置 */
int pos[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/* 储存当前一种结果 */
vector<int> curResult;
/* 最终的结果 */
vector<vector<int> > result;

void searchQueen(int ithQueen)
{
	if (ithQueen == 8)
	{
		result.push_back(curResult);
		return;
	}

	for (int i = 0; i < 8; ++i)
	{
		bool bPut = true;
		if (pos[i] != 1)
		{
			curResult[ithQueen] = i + 1;
		}
		else
		{
			continue;
		}

		for (int j = 0; j < ithQueen; ++j)
		{
			if (curResult[j] == (i + 1) || abs((i + 1) - curResult[j]) == abs(ithQueen - j))
			{
				/* 可以被其他皇后吃掉 */
				bPut = false;
				break;
			}
		}

		if (bPut)
		{
			pos[i] = 1;
			searchQueen(ithQueen + 1);
			pos[i] = 0;
		}
		curResult[ithQueen] = -1;
	}
}

int main()
{
	curResult.assign(8, -1);
	searchQueen(0);

	for (int i = 1; i <= result.size(); ++i)
	{
		cout << i << ":";
		for (int j = 0; j < result[i - 1].size(); ++j)
			cout << result[i - 1][j] << ",";
		cout << endl;
	}

	cout << "八皇后最后共有" << result.size() << "种解法" << endl;
}
