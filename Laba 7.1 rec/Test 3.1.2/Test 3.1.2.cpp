#include "pch.h"
#include "CppUnitTest.h"
#include "../Laba 7.1 rec/Laba 7.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test312
{
	TEST_CLASS(Test312)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** arr = new int* [3];
			for (int i = 0; i < 3; i++) {
				arr[i] = new int[3];
			}
			arr[0][0] = 1;
			arr[0][1] = 2;
			arr[0][2] = 3;

			arr[1][0] = 4;
			arr[1][1] = 5;
			arr[1][2] = 6;

			arr[2][0] = 7;
			arr[2][1] = 8;
			arr[2][2] = 9;

			Change(arr, 0, 1, 3);

			Assert::AreEqual(4, arr[0][0]);
			Assert::AreEqual(5, arr[0][1]);
			Assert::AreEqual(6, arr[0][2]);

			Assert::AreEqual(1, arr[1][0]);
			Assert::AreEqual(2, arr[1][1]);
			Assert::AreEqual(3, arr[1][2]);

			for (int i = 0; i < 3; i++) {
				delete[] arr[i];
			}

			delete[] arr;
		}
	};
}
