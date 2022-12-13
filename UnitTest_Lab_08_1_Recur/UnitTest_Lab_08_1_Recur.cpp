#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1_Recur/Lab_08_1_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

char* TestChange(char* dest, const char* str, char* t, int i)
{
	if (str[i + 2] != 0)
	{
		if (((str[i] == 'O' && str[i + 2] == 'O') || (str[i] == 'A' && str[i + 2] == 'A')) && str[i + 1] == 'G')
		{
			strcat_s(t, strlen(str), "**");
			return Change(dest, str, t + 2, i + 3);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}

namespace UnitTestLab081Recur
{
	TEST_CLASS(UnitTestLab081Recur)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[101] = "TESTOGOTESTAGA";
			char teststr[101] = "TESTOGOTESTAGA";
			char* dest1 = new char[151];
			dest1[0] = '\0';
			char* dest = Change(dest1, str, dest1, 0, 0);
			char* testdest = TestChange(dest1, teststr, dest1, 0);
			Assert::AreEqual(strcmp(dest, testdest), 0);
		}
	};
}
