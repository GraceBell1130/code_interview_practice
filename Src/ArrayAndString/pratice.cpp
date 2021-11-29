#include "pratice.h"
#include <string>
#include <cstdio>
#include <map>
void pratic1()
{ //done
	int arr[255] = {0, };
	std::string str = "aaaaaaabbddccdfda";

	for (char c: str)
	{
		arr[c]++;
	}

	for (int a : arr)
	{
		if (a > 2)
		{
			printf("I find duplicate char in %s", str.c_str()); 
			break;
		}
	}
}

void pratic2()
{ // done
	int arr[255] = { 0, };
	std::string str = "aaaaaaabbddccdfda";
	std::string compare = "abc";
	bool checker = true;
	for (char c : str)
	{
		arr[c]++;
	}

	for (int a : compare)
	{
		arr[a] -= 1;
		if (arr[a] < 0)
		{
			checker = false;
			printf("%s is not %s of permutation", compare.c_str() , str.c_str());
			break;
		}
	}
	
	if (checker)
	{
		printf("%s is %s of permutation", compare.c_str(), str.c_str());
	}
}

void pratic3()
{ // done
	std::string input = "Mr John Smith";
	size_t inputSize = 13;

	std::string output(inputSize * 3, 0);
	size_t pos = 0;
	for (char c : input)
	{
		if (c == 0x20)
		{
			output[pos] = '%';
			output[pos + 1] = '2';
			output[pos + 2] = '0';
			pos+=3;
			continue;
		}
		output[pos] = c;
		pos++;
	}
	printf("%s", output.c_str());
}

void make_permutation_string_pratic4(std::string input, std::string& makeString,std::map<std::string, bool>& dict)
{
	if (input.size() == 0)
	{
		auto ret = dict.insert(std::pair<std::string, bool>(makeString, false));
		if (!ret.second)
		{
			std::string makeStringReverse = makeString;
			for (int i = 0; i < makeStringReverse.size() / 2; i++)
			{
				std::swap(makeStringReverse[i], makeStringReverse[makeStringReverse.size() - 1 - i]);
			}
			if (makeString == makeStringReverse)
			{
				ret.first->second = true;
			}
		}
		return;
	}
	for (int i = 0; i < input.size(); i++)
	{
		makeString.push_back(input[i]);
		std::string backup = input;
		backup.erase(i, 1);
		make_permutation_string_pratic4(backup, makeString, dict);
		makeString.erase(makeString.size() - 1, 1);
	}
}
void pratic4()
{ // done
	std::string input = "Tact Coa";
	int count  = 0;
	bool bReuslt = false;
	std::map<std::string, bool> dict;
	std::string erasedEmptyInput;
	std::string::size_type prePosition = 0;
	std::string::size_type findPosition = input.find(" ", prePosition);
	while (findPosition != std::string::npos)
	{
		erasedEmptyInput.append(input.substr(prePosition, findPosition));
		prePosition = findPosition + 1;
		findPosition = input.find(" ", prePosition);
	}
	erasedEmptyInput.append(input.substr(prePosition));
	for (std::string::iterator i = erasedEmptyInput.begin(); i != erasedEmptyInput.end(); i++)
	{
		*i = tolower(*i);
	}
	std::string test;
	make_permutation_string_pratic4(erasedEmptyInput, test, dict);
	for (std::map<std::string, bool>::iterator i = dict.begin(); i != dict.end() ;i++)
	{
		if (i->second)
		{
			printf("%s\n", i->first.c_str());
		}
	}
}

void pratic5()
{ //done
	int arr[255] = { 0, };
	std::string input = "pale";
	std::string compare = "bake";

	for (char c : input)
	{
		arr[c]++;
	}
	for (char c : compare)
	{
		arr[c]--;
	}
	int result = 0;
	for (int i = 0; i < 255; i++)
	{
		if (arr[i] < 0)
		{
			result = result + (arr[i] * -1);
		}
		result += arr[i];
	}
	if (result < 2)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
}

void pratic6()
{ //done
	std::string input = "aabbccccaaa";
	
	int zipCount[122 - 97] = {0, };

	for (char c : input)
	{
		zipCount[c - 97]++;
	}
	
	std::string output;
	for (int pos = 0; pos < sizeof(zipCount) / sizeof(int); pos++)
	{
		if (zipCount[pos] > 0)
		{
			output.append(1, 'a' + pos);
			output.append(std::to_string(zipCount[pos]));
		}
	}
	if (output.length() < input.length())
	{
		printf("%s", output.c_str());
	}
	else
	{
		printf("%s", input.c_str());
	}
}

void printArr(int* input, int total_size, int row_size)
{
	for (int i = 0; i < total_size; i++)
	{
		int test = ((i / row_size) * row_size) + (i % row_size);

		printf("%3d", *(input + test));
		if ((i + 1) % row_size == 0)
		{
			printf("\n");
		}
	}
}

void pratic7()
{ // not solved
	int input[][3] =
	{ 
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	
	int total_size = sizeof(input) / sizeof(int);
	int row_size = (sizeof(input[0]) / sizeof(int));
	
	printArr((int*)input, total_size, row_size);

	printf("\n");

	for (int i = 0; i < row_size / 2; i++)
	{
		for (int j = i; j < row_size - i - 1; j++)
		{
			int temp								  = input[i][j];
			input[i][j]								  = input[j][row_size - i - 1];
			input[j][row_size - i - 1]				  = input[row_size - i - 1][row_size - j - 1];
			input[row_size - i - 1][row_size - j - 1] = input[row_size - j - 1][i];
			input[row_size - j - 1][i]				  = temp;

		}
	}

	printArr((int*)input, total_size, row_size);

}

void pratic8()
{ //done
	int input[][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int total_size = sizeof(input) / sizeof(int);
	int row_size = (sizeof(input[0]) / sizeof(int));
	int column_size = (total_size / row_size);

	int x = 0 , y = 0;
	printf("intput x : ");
	scanf_s("%d", &x);
	printf("intput y : ");
	scanf_s("%d", &y);

	for (int i = 0; i < column_size; i++)
	{
		input[i][x] = 0;
	}
	
	memset(&input[y][0], 0 , row_size * sizeof(int));

	for (int i = 0; i < total_size; i++)
	{
		printf("%3d", input[i / row_size][i % row_size]);
		if ((i + 1) % row_size == 0)
		{
			printf("\n");
		}
	}

}

bool isSubstring(std::string s1, std::string s2)
{
	return s1.find(s2) != std::string::npos? true: false;
}

void pratic9()
{ //done
	std::string s1 = "waterbottle";
	std::string s2 = "erbottlewat";

	if (isSubstring(s2 + s2, s1))
	{
		printf("ok");
	}
}