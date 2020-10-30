#include <string>
#include <iostream>
using namespace std;

void allLexicographicRecur(string alph, char* perm, int last, int index)
{
	int len = alph.length();

	for (int i = 0; i < len; ++i)
	{
		perm[index] = alph[i];

		if (index == last)
		{
			int count = 0;

			for (int n = 0; n < len; n++)
			{
				for (int j = 0; j <= last; ++j)
				{
					if (alph[n] == perm[j])
					{
						++count;
						break;	
					}
				}
			}

			if (count == len)
			{
				cout << perm << " ";
			}
		}
		else
		{
			allLexicographicRecur(alph, perm, last, index + 1);
		}
	}
}

int main()
{
	int n; string alph;
	cin >> n >> alph;
	char* perm = new char[n + 1];
	perm[n] = '\0';
	allLexicographicRecur(alph, perm, n - 1, 0);
	return 0;
}