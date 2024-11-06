#include "pch.h"
#include "CppUnitTest.h"
#include "../lab.6.4.rec/lab.6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
	TEST_CLASS(UnitTest64rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr[] = { 0, 1, 0, 3, 4, 0, 6 };
			int n = sizeof(arr) / sizeof(arr[0]);
			int expectedCount = 3;
			Assert::AreEqual(expectedCount, CountZeros(arr, n));
		}
	};
}
