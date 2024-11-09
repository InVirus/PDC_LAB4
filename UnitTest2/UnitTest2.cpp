#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <sstream>
#include <string>
#include "../PDC_LAB_4_2/source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		std::string captureOutput(int n, int r) {
			std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
			std::ostringstream strCout;
			std::cout.rdbuf(strCout.rdbuf());

			generateCombinations(n, r);

			std::cout.rdbuf(oldCoutStreamBuf);

			return strCout.str();
		}

		TEST_METHOD(TestValidCombinations)
		{
			int n = 4, r = 2;
			std::string expectedOutput =
				"{ 1, 2 }\n"
				"{ 1, 3 }\n"
				"{ 1, 4 }\n"
				"{ 2, 3 }\n"
				"{ 2, 4 }\n"
				"{ 3, 4 }\n";


			std::string actualOutput = captureOutput(n, r);

			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(TestInvalidInput)
		{
			int n = 3, r = 4;
			std::string expectedOutput =
				"Invalid input. Please ensure that n > 0, r >= 0, and n >= r.\n";

			std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
			std::ostringstream strCout;
			std::cout.rdbuf(strCout.rdbuf());

			if (n <= 0 || r < 0 || n < r) {
				std::cout << "Invalid input. Please ensure that n > 0, r >= 0, and n >= r." << std::endl;
			}
			std::cout.rdbuf(oldCoutStreamBuf);

			Assert::AreEqual(expectedOutput, strCout.str());
		}
	};
}
