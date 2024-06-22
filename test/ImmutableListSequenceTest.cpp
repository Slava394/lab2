#include <cassert>
#include <iostream>
#include "ImmutableListSequenceTest.h"
#include "../header/ListSequence.h"


void TestImmutableListSequenceGetFirst()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 1);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 10);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 0);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 2);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetFirst() == 5);
    }
    std::cout << "[GetFirst test passed]" << std::endl;
}

void TestImmutableListSequenceGetLast()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 5);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 50);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == -4);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 10);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLast() == 25);
    }
    std::cout << "[GetLast test passed]" << std::endl;
}

void TestImmutableListSequenceGet()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 1);
        assert(seq.Get(1) == 2);
        assert(seq.Get(2) == 3);
        assert(seq.Get(3) == 4);
        assert(seq.Get(4) == 5);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 10);
        assert(seq.Get(1) == 20);
        assert(seq.Get(2) == 30);
        assert(seq.Get(3) == 40);
        assert(seq.Get(4) == 50);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 0);
        assert(seq.Get(1) == -1);
        assert(seq.Get(2) == -2);
        assert(seq.Get(3) == -3);
        assert(seq.Get(4) == -4);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 2);
        assert(seq.Get(1) == 4);
        assert(seq.Get(2) == 6);
        assert(seq.Get(3) == 8);
        assert(seq.Get(4) == 10);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.Get(0) == 5);
        assert(seq.Get(1) == 10);
        assert(seq.Get(2) == 15);
        assert(seq.Get(3) == 20);
        assert(seq.Get(4) == 25);
    }
    std::cout << "[Get test passed]" << std::endl;
}

void TestImmutableListSequenceGetLength()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        assert(seq.GetLength() == 5);
    }
    std::cout << "[GetLength test passed]" << std::endl;
}

void TestImmutableListSequenceSet()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Set(10, 0);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 2);
        assert(result.Get(2) == 3);
        assert(result.Get(3) == 4);
        assert(result.Get(4) == 5);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Set(100, 4);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 20);
        assert(result.Get(2) == 30);
        assert(result.Get(3) == 40);
        assert(result.Get(4) == 100);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Set(1, 2);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == -1);
        assert(result.Get(2) == 1);
        assert(result.Get(3) == -3);
        assert(result.Get(4) == -4);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Set(20, 1);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 20);
        assert(result.Get(2) == 6);
        assert(result.Get(3) == 8);
        assert(result.Get(4) == 10);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Set(50, 3);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 15);
        assert(result.Get(3) == 50);
        assert(result.Get(4) == 25);
        delete &result;
    }
    std::cout << "[Set test passed]" << std::endl;
}

void TestImmutableListSequencePrepend()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Prepend(0);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == 1);
        assert(result.Get(2) == 2);
        assert(result.Get(3) == 3);
        assert(result.Get(4) == 4);
        assert(result.Get(5) == 5);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Prepend(5);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 20);
        assert(result.Get(3) == 30);
        assert(result.Get(4) == 40);
        assert(result.Get(5) == 50);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Prepend(-5);
        assert(result.Get(0) == -5);
        assert(result.Get(1) == 0);
        assert(result.Get(2) == -1);
        assert(result.Get(3) == -2);
        assert(result.Get(4) == -3);
        assert(result.Get(5) == -4);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Prepend(1);
        assert(result.Get(0) == 1);
        assert(result.Get(1) == 2);
        assert(result.Get(2) == 4);
        assert(result.Get(3) == 6);
        assert(result.Get(4) == 8);
        assert(result.Get(5) == 10);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Prepend(0);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == 5);
        assert(result.Get(2) == 10);
        assert(result.Get(3) == 15);
        assert(result.Get(4) == 20);
        assert(result.Get(5) == 25);
        delete &result;
    }
    std::cout << "[Prepend test passed]" << std::endl;
}

void TestImmutableListSequenceAppend()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Append(6);
        assert(result.Get(0) == 1);
        assert(result.Get(1) == 2);
        assert(result.Get(2) == 3);
        assert(result.Get(3) == 4);
        assert(result.Get(4) == 5);
        assert(result.Get(5) == 6);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Append(60);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 20);
        assert(result.Get(2) == 30);
        assert(result.Get(3) == 40);
        assert(result.Get(4) == 50);
        assert(result.Get(5) == 60);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Append(-5);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == -1);
        assert(result.Get(2) == -2);
        assert(result.Get(3) == -3);
        assert(result.Get(4) == -4);
        assert(result.Get(5) == -5);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Append(12);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
        assert(result.Get(2) == 6);
        assert(result.Get(3) == 8);
        assert(result.Get(4) == 10);
        assert(result.Get(5) == 12);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.Append(30);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 15);
        assert(result.Get(3) == 20);
        assert(result.Get(4) == 25);
        assert(result.Get(5) == 30);
        delete &result;
    }
    std::cout << "[Append test passed]" << std::endl;
}

void TestImmutableListSequenceInsertAt()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.InsertAt(0, 0);
        assert(result.GetLength() == 6);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == 1);
        assert(result.Get(2) == 2);
        assert(result.Get(3) == 3);
        assert(result.Get(4) == 4);
        assert(result.Get(5) == 5);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.InsertAt(15, 1);
        assert(result.GetLength() == 6);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 15);
        assert(result.Get(2) == 20);
        assert(result.Get(3) == 30);
        assert(result.Get(4) == 40);
        assert(result.Get(5) == 50);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.InsertAt(-5, 5);
        assert(result.GetLength() == 6);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == -1);
        assert(result.Get(2) == -2);
        assert(result.Get(3) == -3);
        assert(result.Get(4) == -4);
        assert(result.Get(5) == -5);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.InsertAt(5, 2);
        assert(result.GetLength() == 6);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
        assert(result.Get(2) == 5);
        assert(result.Get(3) == 6);
        assert(result.Get(4) == 8);
        assert(result.Get(5) == 10);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.InsertAt(18, 3);
        assert(result.GetLength() == 6);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 15);
        assert(result.Get(3) == 18);
        assert(result.Get(4) == 20);
        assert(result.Get(5) == 25);
        delete &result;
    }
    std::cout << "[InsertAt test passed]" << std::endl;
}

void TestImmutableListSequenceRemoveFirst()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveFirst();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 3);
        assert(result.Get(2) == 4);
        assert(result.Get(3) == 5);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveFirst();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 20);
        assert(result.Get(1) == 30);
        assert(result.Get(2) == 40);
        assert(result.Get(3) == 50);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveFirst();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == -1);
        assert(result.Get(1) == -2);
        assert(result.Get(2) == -3);
        assert(result.Get(3) == -4);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveFirst();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 4);
        assert(result.Get(1) == 6);
        assert(result.Get(2) == 8);
        assert(result.Get(3) == 10);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveFirst();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 15);
        assert(result.Get(2) == 20);
        assert(result.Get(3) == 25);
        delete &result;
    }
    std::cout << "[RemoveFirst test passed]" << std::endl;
}

void TestImmutableListSequenceRemoveLast()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveLast();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 1);
        assert(result.Get(1) == 2);
        assert(result.Get(2) == 3);
        assert(result.Get(3) == 4);
        delete &result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveLast();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 10);
        assert(result.Get(1) == 20);
        assert(result.Get(2) == 30);
        assert(result.Get(3) == 40);
        delete &result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveLast();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 0);
        assert(result.Get(1) == -1);
        assert(result.Get(2) == -2);
        assert(result.Get(3) == -3);
        delete &result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveLast();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 2);
        assert(result.Get(1) == 4);
        assert(result.Get(2) == 6);
        assert(result.Get(3) == 8);
        delete &result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> &result = seq.RemoveLast();
        assert(result.GetLength() == 4);
        assert(result.Get(0) == 5);
        assert(result.Get(1) == 10);
        assert(result.Get(2) == 15);
        assert(result.Get(3) == 20);
        delete &result;
    }
    std::cout << "[RemoveLast test passed]" << std::endl;
}

void TestImmutableListSequenceErase()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.Erase(2);
        assert(result->GetLength() == 4);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        assert(result->Get(2) == 4);
        assert(result->Get(3) == 5);
        delete result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.Erase(0);
        assert(result->GetLength() == 4);
        assert(result->Get(0) == 20);
        assert(result->Get(1) == 30);
        assert(result->Get(2) == 40);
        assert(result->Get(3) == 50);
        delete result;
    }
    {
        int values[] = {100, 200, 300};
        ImmutableListSequence<int> seq(values, 3);
        ListSequence<int> *result = &seq.Erase(2);
        assert(result->GetLength() == 2);
        assert(result->Get(0) == 100);
        assert(result->Get(1) == 200);
        delete result;
    }
    {
        int values[] = {5, 15, 25, 35, 45, 55};
        ImmutableListSequence<int> seq(values, 6);
        ListSequence<int> *result = &seq.Erase(3);
        assert(result->GetLength() == 5);
        assert(result->Get(0) == 5);
        assert(result->Get(1) == 15);
        assert(result->Get(2) == 25);
        assert(result->Get(3) == 45);
        assert(result->Get(4) == 55);
        delete result;
    }
    {
        int values[] = {-1, -2, -3, -4, -5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.Erase(1);
        assert(result->GetLength() == 4);
        assert(result->Get(0) == -1);
        assert(result->Get(1) == -3);
        assert(result->Get(2) == -4);
        assert(result->Get(3) == -5);
        delete result;
    }
    std::cout << "[Erase test passed]" << std::endl;
}

void TestImmutableListSequenceConcat()
{
    {
        int values1[] = {1, 2, 3};
        int values2[] = {4, 5, 6};
        ImmutableListSequence<int> seq1(values1, 3);
        ImmutableListSequence<int> seq2(values2, 3);
        ListSequence<int> *result = &seq1.Concat(seq2);
        assert(result->GetLength() == 6);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        assert(result->Get(2) == 3);
        assert(result->Get(3) == 4);
        assert(result->Get(4) == 5);
        assert(result->Get(5) == 6);
        delete result;
    }
    {
        int values1[] = {10, 20};
        int values2[] = {30, 40, 50};
        ImmutableListSequence<int> seq1(values1, 2);
        ImmutableListSequence<int> seq2(values2, 3);
        ListSequence<int> *result = &seq1.Concat(seq2);
        assert(result->GetLength() == 5);
        assert(result->Get(0) == 10);
        assert(result->Get(1) == 20);
        assert(result->Get(2) == 30);
        assert(result->Get(3) == 40);
        assert(result->Get(4) == 50);
        delete result;
    }
    {
        int values1[] = {};
        int values2[] = {1, 2, 3};
        ImmutableListSequence<int> seq1(values1, 0);
        ImmutableListSequence<int> seq2(values2, 3);
        ListSequence<int> *result = &seq1.Concat(seq2);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        assert(result->Get(2) == 3);
        delete result;
    }
    {
        int values1[] = {1, 2, 3};
        int values2[] = {};
        ImmutableListSequence<int> seq1(values1, 3);
        ImmutableListSequence<int> seq2(values2, 0);
        ListSequence<int> *result = &seq1.Concat(seq2);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        assert(result->Get(2) == 3);
        delete result;
    }
    {
        int values1[] = {-1, -2, -3};
        int values2[] = {4, 5, 6};
        ImmutableListSequence<int> seq1(values1, 3);
        ImmutableListSequence<int> seq2(values2, 3);
        ListSequence<int> *result = &seq1.Concat(seq2);
        assert(result->GetLength() == 6);
        assert(result->Get(0) == -1);
        assert(result->Get(1) == -2);
        assert(result->Get(2) == -3);
        assert(result->Get(3) == 4);
        assert(result->Get(4) == 5);
        assert(result->Get(5) == 6);
        delete result;
    }
    std::cout << "[Concat test passed]" << std::endl;
}

void TestImmutableListSequenceGetSubSequence()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.GetSubSequence(1, 4);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == 2);
        assert(result->Get(1) == 3);
        assert(result->Get(2) == 4);
        delete result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.GetSubSequence(0, 3);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == 10);
        assert(result->Get(1) == 20);
        assert(result->Get(2) == 30);
        delete result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.GetSubSequence(2, 5);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == -2);
        assert(result->Get(1) == -3);
        assert(result->Get(2) == -4);
        delete result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.GetSubSequence(1, 5);
        assert(result->GetLength() == 4);
        assert(result->Get(0) == 10);
        assert(result->Get(1) == 15);
        assert(result->Get(2) == 20);
        assert(result->Get(3) == 25);
        delete result;
    }
    {
        int values[] = {100, 200, 300, 400, 500};
        ImmutableListSequence<int> seq(values, 5);
        ListSequence<int> *result = &seq.GetSubSequence(0, 2);
        assert(result->GetLength() == 2);
        assert(result->Get(0) == 100);
        assert(result->Get(1) == 200);
        delete result;
    }
    std::cout << "[GetSubSequence test passed]" << std::endl;
}

void TestImmutableListSequenceMap()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        auto square = [](const int &x) { return x * x; };
        ListSequence<int> *result = &seq.Map(square);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 4);
        assert(result->Get(2) == 9);
        assert(result->Get(3) == 16);
        assert(result->Get(4) == 25);
        delete result;
    }
    {
        int values[] = {2, 4, 6, 8, 10};
        ImmutableListSequence<int> seq(values, 5);
        auto half = [](const int &x) { return x / 2; };
        ListSequence<int> *result = &seq.Map(half);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        assert(result->Get(2) == 3);
        assert(result->Get(3) == 4);
        assert(result->Get(4) == 5);
        delete result;
    }
    {
        int values[] = {0, -1, -2, -3, -4};
        ImmutableListSequence<int> seq(values, 5);
        auto absValue = [](const int &x) { return std::abs(x); };
        ListSequence<int> *result = &seq.Map(absValue);
        assert(result->Get(0) == 0);
        assert(result->Get(1) == 1);
        assert(result->Get(2) == 2);
        assert(result->Get(3) == 3);
        assert(result->Get(4) == 4);
        delete result;
    }
    {
        int values[] = {5, 10, 15, 20, 25};
        ImmutableListSequence<int> seq(values, 5);
        auto increment = [](const int &x) { return x + 1; };
        ListSequence<int> *result = &seq.Map(increment);
        assert(result->Get(0) == 6);
        assert(result->Get(1) == 11);
        assert(result->Get(2) == 16);
        assert(result->Get(3) == 21);
        assert(result->Get(4) == 26);
        delete result;
    }
    {
        int values[] = {100, 200, 300, 400, 500};
        ImmutableListSequence<int> seq(values, 5);
        auto subtract = [](const int &x) { return x - 50; };
        ListSequence<int> *result = &seq.Map(subtract);
        assert(result->Get(0) == 50);
        assert(result->Get(1) == 150);
        assert(result->Get(2) == 250);
        assert(result->Get(3) == 350);
        assert(result->Get(4) == 450);
        delete result;
    }
    std::cout << "[Map test passed]" << std::endl;
}

void TestImmutableListSequenceWhere()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        auto isEven = [](const int &x) { return x % 2 == 0; };
        ListSequence<int> *result = &seq.Where(isEven);
        assert(result->GetLength() == 2);
        assert(result->Get(0) == 2);
        assert(result->Get(1) == 4);
        delete result;
    }
    {
        int values[] = {1, 2, 3, 4, 5, 6};
        ImmutableListSequence<int> seq(values, 6);
        auto greaterThanThree = [](const int &x) { return x > 3; };
        ListSequence<int> *result = &seq.Where(greaterThanThree);
        assert(result->GetLength() == 3);
        assert(result->Get(0) == 4);
        assert(result->Get(1) == 5);
        assert(result->Get(2) == 6);
        delete result;
    }
    {
        int values[] = {-1, -2, 0, 1, 2};
        ImmutableListSequence<int> seq(values, 5);
        auto isPositive = [](const int &x) { return x > 0; };
        ListSequence<int> *result = &seq.Where(isPositive);
        assert(result->GetLength() == 2);
        assert(result->Get(0) == 1);
        assert(result->Get(1) == 2);
        delete result;
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        auto multipleOfTen = [](const int &x) { return x % 10 == 0; };
        ListSequence<int> *result = &seq.Where(multipleOfTen);
        assert(result->GetLength() == 5);
        assert(result->Get(0) == 10);
        assert(result->Get(1) == 20);
        assert(result->Get(2) == 30);
        assert(result->Get(3) == 40);
        assert(result->Get(4) == 50);
        delete result;
    }
    {
        int values[] = {3, 6, 9, 12, 15};
        ImmutableListSequence<int> seq(values, 5);
        auto divisibleByThree = [](const int &x) { return x % 3 == 0; };
        ListSequence<int> *result = &seq.Where(divisibleByThree);
        assert(result->GetLength() == 5);
        assert(result->Get(0) == 3);
        assert(result->Get(1) == 6);
        assert(result->Get(2) == 9);
        assert(result->Get(3) == 12);
        assert(result->Get(4) == 15);
        delete result;
    }
    std::cout << "[Where test passed]" << std::endl;
}

void TestImmutableListSequenceReduce()
{
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        auto sum = [](const int &a, const int &b) { return a + b; };
        int result = seq.Reduce(sum, 0);
        assert(result == 15);
    }
    {
        int values[] = {1, 2, 3, 4, 5};
        ImmutableListSequence<int> seq(values, 5);
        auto product = [](const int &a, const int &b) { return a * b; };
        int result = seq.Reduce(product, 1);
        assert(result == 120);
    }
    {
        int values[] = {10, 20, 30, 40, 50};
        ImmutableListSequence<int> seq(values, 5);
        auto max = [](const int &a, const int &b) { return a > b ? a : b; };
        int result = seq.Reduce(max, values[0]);
        assert(result == 50);
    }
    {
        int values[] = {5, 4, 3, 2, 1};
        ImmutableListSequence<int> seq(values, 5);
        auto min = [](const int &a, const int &b) { return a < b ? a : b; };
        int result = seq.Reduce(min, values[0]);
        assert(result == 1);
    }
    {
        int values[] = {1, 1, 1, 1, 1};
        ImmutableListSequence<int> seq(values, 5);
        auto sum = [](const int &a, const int &b) { return a + b; };
        int result = seq.Reduce(sum, 5);
        assert(result == 10);
    }
    std::cout << "[Reduce test passed]" << std::endl;
}

void ImmutableListSequenceTest()
{
    std::cout << "<Immutable list sequence tests>" << std::endl;
    TestImmutableListSequenceGetFirst();
    TestImmutableListSequenceGetLast();
    TestImmutableListSequenceGet();
    TestImmutableListSequenceGetLength();
    TestImmutableListSequenceSet();
    TestImmutableListSequencePrepend();
    TestImmutableListSequenceAppend();
    TestImmutableListSequenceInsertAt();
    TestImmutableListSequenceRemoveFirst();
    TestImmutableListSequenceRemoveLast();
    TestImmutableListSequenceErase();
    TestImmutableListSequenceConcat();
    TestImmutableListSequenceGetSubSequence();
    TestImmutableListSequenceMap();
    TestImmutableListSequenceWhere();
    TestImmutableListSequenceReduce();
}
