#include "pratice.h"
#include <iostream>
#include <bitset>
#include <vector>
#include <set>
#include <array>

void pratic1()
{
	int32_t N{ 0b100'0000'0000 }, M{ 0b1'0011 };
	int i{ 2 }, j{ 6 };

	cout << "counter : N = 0b10000000000, M = 0b10011, i = 2, j = 6" << endl;

	int32_t left{-1}, right{-1};

	left <<= j;
	left = ~left;
	right <<= i;
	N = N & ~(left & right);
	N |= (M << i);
	cout << "output : N = 0b" << bitset<32>(N) << endl;
}
void pratic2()
{
	double input{0.0};
	std::vector<bool> output;
	cout << "counter [0 ~ 1] : ";
	cin >> input;
	if (0.0 <= input && input <= 1.0)
	{
		while (output.size() <= 32 && input != 0)
		{
			input *= 2;
			if (input / 1 >= 1.0)
			{
				output.push_back(true);
			}
			else
			{
				output.push_back(false);
			}
			input = std::fmod(input, 1);
		}
		if (output.size() <= 32)
		{
			cout << "output : 0b";
			for (bool inner : output)
			{
				cout << inner;
			}
			cout << endl;
		}
		else
		{
			cout << "output : ERROR" << endl;
		}
	}
	else
	{
		cout << "plz counter a range of 0 to 1." << endl;
	}
}
// 0이 연속으로 나올것을 예상 하지 않음 110011100111001
void pratic3()
{
	int32_t input{0};
	cout << "counter : ";
	cin >> input;

	std::set<int32_t> sumSet = {0};
	std::vector<int32_t> vecCounter;
	int32_t counter = 0;
	while (input != 0)
	{
		if (input & 0b1)
		{
			counter++;
		}
		else
		{
			vecCounter.emplace_back(counter);
			counter = 0;
		}
		input = input >> 1;
	}
	int32_t before = counter;

	for (int32_t value : vecCounter)
	{
		sumSet.insert(before + value + 1);
		before = value;
	}

	cout << "output : " << *sumSet.rbegin() << endl;
}
void pratic4()
{
}
void pratic5()
{
	int32_t input{0};
	cout << "counter : ";
	cin >> input;

	cout << input << " is ";

	if ( false == ((input & (input - 1)) == 0))
	{
		cout << " not ";
	}
	
	cout << " 0 or powers of two " << endl;

}
void pratic6()
{// you can think better then this logic
	uint32_t inputA{ 0 }, inputB{ 0 };

	cout << "input A value : ";
	cin >> inputA;
	cout << "input B value : ";
	cin >> inputB;

	uint32_t temp = inputA ^ inputB;

	uint32_t count{ 0 };
	while (temp > 0)
	{
		count += temp & 1;
		temp >>= 1;
	}

	cout << "value : " << count << endl;
}
void pratic7()
{// you can think better then this logic
	uint32_t input{ 0 }, output{0};

	cout << "input : ";
	cin >> input;
	uint32_t counter{ 0 };
	do 
	{
		if ((input & 1) == 1)
		{
			output |= (2 << counter);
		}
		if ((input & 2) == 2)
		{
			output |= (1 << counter);
		}
		input >>= 2;
		counter += 2;
	} while (input > 0);

	cout << "output : " << output << endl;
}
void pratic8()
{ // more read question
	const uint32_t width{ 8 }, x1{ 1 }, x2{ 1 }, y{ 1 };
	array<byte, width> screen = {byte(0), };
	screen[y] = byte(255 >> (x1 -1)) & byte(byte(255) << width - x2);
	for (uint32_t count = screen.size(); count > 0; count--)
	{
		cout << count << " " << bitset<8>(to_integer<int>(screen[count - 1])) << endl;
	}
}