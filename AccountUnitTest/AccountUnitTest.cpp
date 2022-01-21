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
			//test passed, because debit amount is less, than the balance
			Account aObj1(120.5);
			Assert::IsTrue(aObj1.debit(25.25));
		}

		TEST_METHOD(TestMethod2)
		{
			//test passed, because debit amount is bigger, than the balance
			Account aObj2(120.5);
			Assert::IsFalse(aObj2.debit(275.5));
		}

		TEST_METHOD(TestMethod3)
		{
			//test passed, because if we pass negative balance to the constructor, 0.0 is assigned to it
			Account aObj3(-11.55);
			Assert::AreEqual(0.0, aObj3.getBalance());
		}

		TEST_METHOD(TestMethod4)
		{
			//test passed, testing the constructor of Account class
			Account aObj4(100.2);
			Assert::AreEqual(100.2, aObj4.getBalance());
		}

		TEST_METHOD(TestMethod5)
		{
			//test passed  
			CheckingAccount chObj(2000.0, 15.25); //CheckingAccount constructor passes the balance to Account constructor 
			Assert::AreEqual(2000.0, chObj.getBalance()); //Account's getBalance function is called for CheckingAccount object
		}
	};
}
