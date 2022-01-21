#include "pch.h"
#include "CppUnitTest.h"
#include "../Account/Account.h"
#include "../Account/CheckingAccount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AccountUnitTest
{
	TEST_CLASS(AccountUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Account aObj1(120.5);
			Assert::IsTrue(aObj1.debit(25.25));
		}

		TEST_METHOD(TestMethod2)
		{
			Account aObj2(120.5);
			Assert::IsFalse(aObj2.debit(275.5));
		}

		TEST_METHOD(TestMethod3)
		{
			Account aObj3(-11.55);
			Assert::AreEqual(0.0, aObj3.getBalance());
		}

		TEST_METHOD(TestMethod4)
		{
			Account aObj4(100.2);
			Assert::AreEqual(100.2, aObj4.getBalance());
		}

		TEST_METHOD(TestMethod5)
		{
			CheckingAccount chObj(2000.0, 15.25);
			Assert::AreEqual(2000.0, chObj.getBalance());
		}
	};
}
