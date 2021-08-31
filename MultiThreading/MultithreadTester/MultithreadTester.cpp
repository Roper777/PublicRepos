#include "pch.h"
#include "CppUnitTest.h"
#include "../MultiThreading/SodaLine.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MultithreadTester
{
	TEST_CLASS(MultithreadTester)
	{
	public:
		
		std::int32_t testBottle = 0;
		std::int32_t bottleNum = 0;
		std::int32_t *repBottle = &testBottle;
		
		
		
		TEST_METHOD(PointerandReference)
		{
			
			Assert::AreEqual(0, *repBottle);//comes out true
			
			
		}
		TEST_METHOD(ChangeValueinPointer)
		{
			testBottle += 100;
			Assert::AreEqual(100, *repBottle); // comes out true
			*repBottle += 100;// need to do a scope check
		}
	

		TEST_METHOD(DoNotKeepValueThruScope)
		{
			*repBottle += 100;
			Assert::AreEqual(200, *repBottle); // comes out FALSE
		}
	};
}
