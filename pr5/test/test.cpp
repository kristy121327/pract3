#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Owner.h"
#include "../ConsoleApplication1/Owner.cpp"
#include "../ConsoleApplication1/Data.h"
#include "../ConsoleApplication1/Data.cpp"
#include "../ConsoleApplication1/Price.h"
#include "../ConsoleApplication1/Price.cpp"
#include "../ConsoleApplication1/Nedv.h"
#include "../ConsoleApplication1/Nedv.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
    TEST_CLASS(test)
    {
    public:

        TEST_METHOD(TestReadDate1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "25.13.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate2)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "35.07.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate3)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "13.11.2025" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate4)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "13.07" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate5)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "11,11,2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate6)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "31.11.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate7)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "32.07.2006" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadDate8)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "29.02.2001" };
                Data data;
                sin >> data;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }


        TEST_METHOD(TestReadName1)
        {
            const auto func = [] {
                auto owner_text = "mixit[\n11.02.2001 55566\n]";
                auto sin = std::istringstream{ owner_text };
                Owner owner;
                sin >> owner;
            };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadName2)
        {
            const auto func = [] {
                auto owner_text = "MIkhailova[\n11.02.2001 55566\n]";
                auto sin = std::istringstream{ owner_text };
                Owner owner;
                sin >> owner;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadName3)
        {
            const auto func = [] {
                auto owner_text = "MIKHAILOVA[\n11.02.2001 55566\n]";
                auto sin = std::istringstream{ owner_text };
                Owner owner;
                sin >> owner;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }

        TEST_METHOD(TestReadSum1)
        {
            const auto func = [] {
                auto sin = std::istringstream{ "-432432432" };
                Price price;
                sin >> price;
                };
            Assert::ExpectException<std::runtime_error>(func);
        }
    };
}
