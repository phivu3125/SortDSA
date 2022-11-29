#include "checkNumber.h"

bool checkNumber(char s[])
{
	int len = strlen(s);
	bool isNumber = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] - '0' > 9 || s[i] - '0' < 0)
		{
			return 0;
		}
	}
	return 1;
}

int stringToNumber(char s[])
{
	int len = strlen(s);
	bool isNumber = 0;
	int n = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		n += (int)(s[i] - '0') * pow(10, len - 1 - i);
	}
	return n;
}