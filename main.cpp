#include <iostream>
#include <iomanip>
#include <string>
using std::cout;

int main()
{
	int step = 0;
	int raw_data[5][4][12] = {
		{
			{ 2,  5, 10,  7, 16,  8,  7,  8,  8,  3,  4, 12},
			{ 3,  3, 14, 14, 21, 21,  9,  9,  4,  4,  6,  6},  
			{ 8,  9, 10, 11, 12, 13, 14, 15,  4,  5,  6,  7},
			{14, 11, 14, 14, 11, 14, 11, 14, 11, 11, 14, 11}
		},
		{
			{ 1,  0,  9,  0, 12,  0,  6,  0, 10,  0, 10,  0},
			{ 3, 26,  6,  0,  2, 13,  9,  0, 17, 19,  3, 12},
			{ 9, 20, 12,  3,  6,  0, 14, 12,  3,  8,  9,  0},
			{ 7,  0,  9,  0,  7, 14, 11,  0,  8,  0, 16,  2}
		},
		{
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 5,  0, 10,  0,  8,  0, 22,  0, 16,  0,  9,  0},
			{21,  6, 15,  4,  9, 18, 11, 26, 14,  1, 12,  0},
			{ 9, 13,  9,  7, 13, 21, 17,  4,  5,  0,  7,  8}
		},
		{
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 4,  0,  7, 15,  0,  0, 14,  0,  9,  0, 12,  0},
			{ 7,  3,  0,  6,  0, 11, 11,  6, 11,  0,  6, 17}
		},
		{
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
			{ 3,  0,  6,  0, 10,  0,  7,  0, 15,  0,  8,  0}
		}
	};

	int greek_computer[5][4][12] = { { {} } };
	int sums[12] = {};
	int rotation[5] = {};
	int solutions = 0;

	while (true)
	{
		rotation[1] = step % 12;
		rotation[2] = (step / 12) % 12;
		rotation[3] = (step / 144) % 12;
		rotation[4] = (step / 1728) % 12;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 12; k++)
				{
					greek_computer[i][j][k] = raw_data[i][j][(k + rotation[i]) % 12];
				}
			}
		}

		int nums[4] = {};
		for (int k = 0; k < 12; k++)
		{
			for (int j = 0; j < 4; j++)
			{
				int i = 4;
				while (true)
				{
					if (greek_computer[i][j][k] == 0)
					{
						i--;
						continue;
					}
					break;
				}
				nums[j] = greek_computer[i][j][k];
			}
			sums[k] = 0;
			for (int i = 0; i < 4; i++)
			{
				sums[k] += nums[i];
			}
		}

		bool isSolution = true;
		for (int i = 0; i < 12; i++)
		{
			if (sums[i] != 42)
			{
				isSolution = false;
				break;
			}
		}

		if (isSolution)
		{
			solutions++;
			break;
		}

		if (step == 248831)
		{
			break;
		}

		if (step % 10 == 0)
		{
			cout.width(25);
			cout.setf(std::ios::left);
			cout << "Progress: % " + std::to_string(step * 100 / 248832.0);
			cout << "Solutions Found: " + std::to_string(solutions);
			cout << "\n";
		}
		
		step++;
	}

	cout << "\n\n -------- Solution Found! -------- (" << step << ") \n\n\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 12; k++)
			{
				int num = greek_computer[i][j][k];
				if (num <= 9) { cout << " "; } cout << num << ", ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < 12; i++)
	{
		if (sums[i] <= 9) { cout << " "; } cout << sums[i] << ", ";
	}
	cout << "\n\n";

	return 0;
}