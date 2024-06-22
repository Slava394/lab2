#include <cassert>
#include <iostream>
#include "MutableListSequenceTest.h"
#include "../header/ListSequence.h"


void TestMutableListSequenceGetFirst()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 1);
    }
    {
        int values[] = {10};
        MutableListSequence<int> seq(values, 1);
        assert(seq.GetFirst() == 10);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        assert(seq.GetFirst() == 100);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 5);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 0);
    }
    std::cout << "[GetFirst test passed]" << std::endl;
}

void TestMutableListSequenceGetLast()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 5);
    }
    {
        int values[] = {10};
        MutableListSequence<int> seq(values, 1);
        assert(seq.GetLast() == 10);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        assert(seq.GetLast() == 300);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 1);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == -4);
    }
    std::cout << "[GetLast test passed]" << std::endl;
}

void TestMutableListSequenceGet()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 1);
        assert(seq.Get(2) == 3);
        assert(seq.Get(4) == 5);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        assert(seq.Get(1) == 20);
        assert(seq.Get(3) == 40);
    }
    {
        int values[] = {100, 200, 300, 400, 500};
        MutableListSequence<int> seq(values, 5);
        assert(seq.Get(1) == 200);
        assert(seq.Get(3) == 400);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 5);
        assert(seq.Get(4) == 25);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 0);
        assert(seq.Get(4) == -4);
    }
    std::cout << "[Get test passed]" << std::endl;
}

void TestMutableListSequenceGetLength()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {10};
        MutableListSequence<int> seq(values, 1);
        assert(seq.GetLength() == 1);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        assert(seq.GetLength() == 3);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    std::cout << "[GetLength test passed]" << std::endl;
}

void TestMutableListSequenceSet()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.Set(10, 2);
        assert(seq.Get(2) == 10);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        seq.Set(100, 0);
        assert(seq.Get(0) == 100);
    }
    {
        int values[] = {100, 200, 300, 400, 500};
        MutableListSequence<int> seq(values, 5);
        seq.Set(0, 4);
        assert(seq.Get(4) == 0);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        seq.Set(50, 1);
        assert(seq.Get(1) == 50);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.Set(-10, 3);
        assert(seq.Get(3) == -10);
    }
    std::cout << "[Set test passed]" << std::endl;
}

void TestMutableListSequencePrepend()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.Prepend(0);
        assert(seq.GetFirst() == 0);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {10};
        MutableListSequence<int> seq(values, 1);
        seq.Prepend(5);
        assert(seq.GetFirst() == 5);
        assert(seq.GetLength() == 2);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        seq.Prepend(50);
        assert(seq.GetFirst() == 50);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        seq.Prepend(6);
        assert(seq.GetFirst() == 6);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.Prepend(1);
        assert(seq.GetFirst() == 1);
        assert(seq.GetLength() == 6);
    }
    std::cout << "[Prepend test passed]" << std::endl;
}

void TestMutableListSequenceAppend()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.Append(6);
        assert(seq.GetLast() == 6);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {10};
        MutableListSequence<int> seq(values, 1);
        seq.Append(20);
        assert(seq.GetLast() == 20);
        assert(seq.GetLength() == 2);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        seq.Append(400);
        assert(seq.GetLast() == 400);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        seq.Append(0);
        assert(seq.GetLast() == 0);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.Append(-5);
        assert(seq.GetLast() == -5);
        assert(seq.GetLength() == 6);
    }
    std::cout << "[Append test passed]" << std::endl;
}

void TestMutableListSequenceInsertAt()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.InsertAt(10, 2);
        assert(seq.Get(2) == 10);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        seq.InsertAt(5, 0);
        assert(seq.Get(0) == 5);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {100, 200, 300, 400, 500};
        MutableListSequence<int> seq(values, 5);
        seq.InsertAt(0, 5);
        assert(seq.Get(5) == 0);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        seq.InsertAt(50, 1);
        assert(seq.Get(1) == 50);
        assert(seq.GetLength() == 6);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.InsertAt(-10, 3);
        assert(seq.Get(3) == -10);
        assert(seq.GetLength() == 6);
    }
    std::cout << "[InsertAt test passed]" << std::endl;
}

void TestMutableListSequenceRemoveFirst()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveFirst();
        assert(seq.GetFirst() == 2);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveFirst();
        assert(seq.GetFirst() == 20);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        seq.RemoveFirst();
        assert(seq.GetFirst() == 200);
        assert(seq.GetLength() == 2);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveFirst();
        assert(seq.GetFirst() == 4);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveFirst();
        assert(seq.GetFirst() == -1);
        assert(seq.GetLength() == 4);
    }
    std::cout << "[RemoveFirst test passed]" << std::endl;
}

void TestMutableListSequenceRemoveLast()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveLast();
        assert(seq.GetLast() == 4);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveLast();
        assert(seq.GetLast() == 40);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        seq.RemoveLast();
        assert(seq.GetLast() == 200);
        assert(seq.GetLength() == 2);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveLast();
        assert(seq.GetLast() == 2);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.RemoveLast();
        assert(seq.GetLast() == -3);
        assert(seq.GetLength() == 4);
    }
    std::cout << "[RemoveLast test passed]" << std::endl;
}

void TestMutableListSequenceErase()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        seq.Erase(2);
        assert(seq.Get(2) == 4);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        seq.Erase(0);
        assert(seq.Get(0) == 20);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        seq.Erase(2);
        assert(seq.Get(1) == 200);
        assert(seq.GetLength() == 2);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        MutableListSequence<int> seq(values, 5);
        seq.Erase(4);
        assert(seq.Get(3) == 2);
        assert(seq.GetLength() == 4);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        seq.Erase(1);
        assert(seq.Get(1) == -2);
        assert(seq.GetLength() == 4);
    }
    std::cout << "[Erase test passed]" << std::endl;
}

void TestMutableListSequenceConcat()
{
    {
        int values1[] = {1, 2, 3};
        int values2[] = {4, 5};
        MutableListSequence<int> seq1(values1, 3);
        MutableListSequence<int> seq2(values2, 2);
        seq1.Concat(seq2);
        assert(seq1.GetLength() == 5);
        assert(seq1.Get(3) == 4);
    }
    {
        int values1[] = {10};
        int values2[] = {20, 30, 40};
        MutableListSequence<int> seq1(values1, 1);
        MutableListSequence<int> seq2(values2, 3);
        seq1.Concat(seq2);
        assert(seq1.GetLength() == 4);
        assert(seq1.Get(1) == 20);
    }
    {
        int values1[] = {100, 200};
        int values2[] = {300};
        MutableListSequence<int> seq1(values1, 2);
        MutableListSequence<int> seq2(values2, 1);
        seq1.Concat(seq2);
        assert(seq1.GetLength() == 3);
        assert(seq1.Get(2) == 300);
    }
    {
        int values1[] = {5, 10};
        int values2[] = {15, 20, 25};
        MutableListSequence<int> seq1(values1, 2);
        MutableListSequence<int> seq2(values2, 3);
        seq1.Concat(seq2);
        assert(seq1.GetLength() == 5);
        assert(seq1.Get(4) == 25);
    }
    {
        int values1[] = {0};
        int values2[] = {-1, -2, -3};
        MutableListSequence<int> seq1(values1, 1);
        MutableListSequence<int> seq2(values2, 3);
        seq1.Concat(seq2);
        assert(seq1.GetLength() == 4);
        assert(seq1.Get(3) == -3);
    }
    std::cout << "[Concat test passed]" << std::endl;
}

void TestMutableListSequenceGetSubSequence()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        ListSequence<int> &subSeq = seq.GetSubSequence(1, 4);
        assert(subSeq.GetLength() == 3);
        assert(subSeq.Get(0) == 2);
        assert(subSeq.Get(2) == 4);
        delete &subSeq;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        ListSequence<int> &subSeq = seq.GetSubSequence(0, 2);
        assert(subSeq.GetLength() == 2);
        assert(subSeq.Get(0) == 10);
        assert(subSeq.Get(1) == 20);
        delete &subSeq;
    }
    {
        int values[] = {100, 200, 300};
        MutableListSequence<int> seq(values, 3);
        ListSequence<int> &subSeq = seq.GetSubSequence(1, 2);
        assert(subSeq.GetLength() == 1);
        assert(subSeq.Get(0) == 200);
        delete &subSeq;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        ListSequence<int> &subSeq = seq.GetSubSequence(0, 5);
        assert(subSeq.GetLength() == 5);
        assert(subSeq.Get(4) == 25);
        delete &subSeq;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        ListSequence<int> &subSeq = seq.GetSubSequence(1, 4);
        assert(subSeq.GetLength() == 3);
        assert(subSeq.Get(0) == -1);
        assert(subSeq.Get(2) == -3);
        delete &subSeq;
    }
    std::cout << "[GetSubSequence test passed]" << std::endl;
}

void TestMutableListSequenceMap()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        auto doubleValue = [](const int &value) { return value * 2; };
        ListSequence<int> &result = seq.Map(doubleValue);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
        assert(result.Get(2) == 6);
        assert(result.Get(3) == 8);
        assert(result.Get(4) == 10);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        auto increment = [](const int &value) { return value + 1; };
        ListSequence<int> &result = seq.Map(increment);
        assert(result.Get(0) == 11);
        assert(result.Get(1) == 21);
        assert(result.Get(2) == 31);
        assert(result.Get(3) == 41);
        assert(result.Get(4) == 51);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        auto inverse = [](const int &value) { return -value; };
        ListSequence<int> &result = seq.Map(inverse);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == 1);
        assert(result.Get(2) == 2);
        assert(result.Get(3) == 3);
        assert(result.Get(4) == 4);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        MutableListSequence<int> seq(values, 5);
        auto square = [](const int &value) { return value * value; };
        ListSequence<int> &result = seq.Map(square);
        assert(result.Get(0) == 4);
        assert(result.Get(1) == 16);
        assert(result.Get(2) == 36);
        assert(result.Get(3) == 64);
        assert(result.Get(4) == 100);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        auto half = [](const int &value) { return value / 2; };
        ListSequence<int> &result = seq.Map(half);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 5);
        assert(result.Get(2) == 7);
        assert(result.Get(3) == 10);
        assert(result.Get(4) == 12);
    }
    std::cout << "[Map test passed]" << std::endl;
}

void TestMutableListSequenceWhere()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        auto isEven = [](const int &value) { return value % 2 == 0; };
        ListSequence<int> &result = seq.Where(isEven);
        assert(result.GetLength() == 2);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        auto greaterThan20 = [](const int &value) { return value > 20; };
        ListSequence<int> &result = seq.Where(greaterThan20);
        assert(result.GetLength() == 3);
        assert(result.Get(0) == 30);
        assert(result.Get(1) == 40);
        assert(result.Get(2) == 50);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        auto isNegative = [](const int &value) { return value < 0; };
        ListSequence<int> &result = seq.Where(isNegative);
        assert(result.GetLength() == 4);
        assert(result.Get(0) == -1);
        assert(result.Get(1) == -2);
        assert(result.Get(2) == -3);
        assert(result.Get(3) == -4);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        MutableListSequence<int> seq(values, 5);
        auto lessThan5 = [](const int &value) { return value < 5; };
        ListSequence<int> &result = seq.Where(lessThan5);
        assert(result.GetLength() == 2);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        auto divisibleBy5 = [](const int &value) { return value % 5 == 0; };
        ListSequence<int> &result = seq.Where(divisibleBy5);
        assert(result.GetLength() == 5);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 15);
        assert(result.Get(3) == 20);
        assert(result.Get(4) == 25);
    }
    std::cout << "[Where test passed]" << std::endl;
}

void TestMutableListSequenceReduce()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        MutableListSequence<int> seq(values, 5);
        auto sum = [](const int &left, const int &right) { return left + right; };
        int result = seq.Reduce(sum, 0);
        assert(result == 15);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        MutableListSequence<int> seq(values, 5);
        auto product = [](const int &left, const int &right) { return left * right; };
        int result = seq.Reduce(product, 1);
        assert(result == 12000000);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        MutableListSequence<int> seq(values, 5);
        auto min = [](const int &left, const int &right) { return left < right ? left : right; };
        int result = seq.Reduce(min, 0);
        assert(result == -4);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        MutableListSequence<int> seq(values, 5);
        auto max = [](const int &left, const int &right) { return left > right ? left : right; };
        int result = seq.Reduce(max, 0);
        assert(result == 10);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        MutableListSequence<int> seq(values, 5);
        auto sum = [](const int &left, const int &right) { return left + right; };
        int result = seq.Reduce(sum, 5);
        assert(result == 80);
    }
    std::cout << "[Reduce test passed]" << std::endl;
}

void MutableListSequenceTest()
{
    std::cout << "<Mutable list sequence tests>" << std::endl;
    TestMutableListSequenceGetFirst();
    TestMutableListSequenceGetLast();
    TestMutableListSequenceGet();
    TestMutableListSequenceGetLength();
    TestMutableListSequenceSet();
    TestMutableListSequencePrepend();
    TestMutableListSequenceAppend();
    TestMutableListSequenceInsertAt();
    TestMutableListSequenceRemoveFirst();
    TestMutableListSequenceRemoveLast();
    TestMutableListSequenceErase();
    TestMutableListSequenceConcat();
    TestMutableListSequenceGetSubSequence();
    TestMutableListSequenceMap();
    TestMutableListSequenceWhere();
    TestMutableListSequenceReduce();
}
