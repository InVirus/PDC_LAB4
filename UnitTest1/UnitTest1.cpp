#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../PDC_LAB_4/Source.cpp" // ����� �� ��� ���� �� �����

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int n = 3;
			vector<vector<int>> expectedPermutations = {
				{1, 2, 3},
				{1, 3, 2},
				{2, 1, 3},
				{2, 3, 1},
				{3, 1, 2},
				{3, 2, 1}
			};

			vector<vector<int>> actualPermutations = generatePermutations(n);

			// �������� ������ ����������
			Assert::AreEqual(expectedPermutations.size(), actualPermutations.size(), L"ʳ������ ������������ �� ��������");

			// �������� ��� ��������
			for (size_t i = 0; i < expectedPermutations.size(); ++i) {
				Assert::IsTrue(expectedPermutations[i] == actualPermutations[i], L"������������ �� ���������");
			}
		}
	};
}
