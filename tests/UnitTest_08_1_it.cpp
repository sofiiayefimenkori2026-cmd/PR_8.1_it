#if defined(_MSC_VER)
#include "pch.h"
#include "CppUnitTest.h"
#define main prog_main
#include "../PR_8.1.it.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest081it
{
    TEST_CLASS(UnitTest081it)
    {
    public:
        TEST_METHOD(TestInclude)
        {
            Assert::IsTrue(Include("who is living here", "while"));
            Assert::IsFalse(Include("hello world", "while"));
        }

        TEST_METHOD(TestChange)
        {
            char str[100] = "do while loop";
            Change(str);
            Assert::AreEqual(std::string("do ** loop"), std::string(str));
        }
    };
}
#else
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#define main prog_main
#include "../PR_8.1.it.cpp"
#undef main

TEST_CASE("Include")
{
    CHECK(Include("who is living here", "while") == true);
    CHECK(Include("hello world", "while") == false);
}

TEST_CASE("Change")
{
    char str[100] = "do while loop";
    Change(str);
    CHECK(std::string(str) == "do ** loop");
}
#endif
