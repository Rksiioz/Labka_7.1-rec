#include <iostream>
#include <iomanip>
#include <time.h>


void Create(int** t, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** t, const  int rowCount, const int colCount, int i, int j);
void Sort(int** t, const int rowCount, const int colCount, int i, int j);
void Change(int** t, const int row1, const int row2, const int colCount, int currentCol = 0);
void Calc(int** t, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main() {

	srand((unsigned)time(NULL));

	int Low = -17;
	int Hight = 14;
	int rowCount = 8;
	int colCount = 5;
	int currentCol = 0;

	int** t = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		t[i] = new int[colCount];

	Create(t, rowCount, colCount, Low, Hight, 0, 0);
	Print(t, rowCount, colCount, 0, 0);
	Sort(t, rowCount, colCount, 0, 0);
	std::cout << std::endl;
	Print(t, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;
	Calc(t, rowCount, colCount, S, k, 0, 0);

	std::cout << "Sum: " << S << std::endl;
	std::cout << "Count: " << k << std::endl;
	Print(t, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] t[i];

	delete[] t;
	return 0;
}


void Create(int** t, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
	if (i >= rowCount) {
		return;
	}

	t[i][j] = Low + rand() % (High - Low + 1);

	if (j + 1 < colCount) {
		Create(t, rowCount, colCount, Low, High, i, j + 1);
	}
	else {
		Create(t, rowCount, colCount, Low, High, i + 1, 0);
	}
}


void Print(int** t, const int rowCount, const int colCount, int i, int j) {
	if (i >= rowCount) {
		return;
	}

	std::cout << " " << std::setw(4) << t[i][j];

	if (j + 1 < colCount) {
		Print(t, rowCount, colCount, i, j + 1);
	}
	else {
		std::cout << std::endl;
		Print(t, rowCount, colCount, i + 1, 0);
	}
}


void Sort(int** t, const int rowCount, const int colCount, int i, int j) {
	if (i >= rowCount - 1) {
		return;
	}

	if (j < rowCount - i - 1) {
		if (
			(t[j][0] > t[j + 1][0]) ||
			(t[j][0] == t[j + 1][0]) && (t[j][1] > t[j + 1][1]) ||
			t[j][0] == t[j + 1][0] &&
			t[j][1] == t[j + 1][1] &&
			t[j][2] > t[j + 1][2]
			) {
			Change(t, j, j + 1, colCount);
		}
		Sort(t, rowCount, colCount, i, j + 1);
	}
	else {
		Sort(t, rowCount, colCount, i + 1, 0);
	}
}

void Change(int** t, const int row1, const int row2, const int colCount, int currentCol)
{
	if (currentCol < colCount)
	{
		int tmp = t[row1][currentCol];
		t[row1][currentCol] = t[row2][currentCol];
		t[row2][currentCol] = tmp;

		Change(t, row1, row2, colCount, currentCol + 1);
	}
}


void Calc(int** t, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
	if (i >= rowCount) {
		return;
	}

	if (j < colCount) {
		if (t[i][j] < 0 && !(t[i][j] % 4 == 0)) {
			S += t[i][j];
			k++;
			t[i][j] = 0;
		}
		Calc(t, rowCount, colCount, S, k, i, j + 1);
	}
	else {
		Calc(t, rowCount, colCount, S, k, i + 1, 0);
	}
}
