#include <iostream>
using namespace std;

char* Change(char* dest, const char* str, char* t, int i, int k)
{
	if (i < strlen(str) && str[i + 2] != 0)
	{
		if (((str[i] == 'O' && str[i + 2] == 'O') || (str[i] == 'A' && str[i + 2] == 'A')) && str[i + 1] == 'G')
		{
			strcat_s(t, strlen(str), "**");
			k++;
			return Change(dest, str, t + 2, i + 3, k);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i, k);
		}
	}
	else
	{
		if (k > 0)
			cout << "Yes, Count : " << k << endl;
		else
			cout << "No" << endl;
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}