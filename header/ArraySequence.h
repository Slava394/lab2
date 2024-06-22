#pragma once
#include "Sequence.h"
#include "DynamicArray.h"


//sequence based on linked list
template <class T>
class ArraySequence : public Sequence<T>
{
protected:
    DynamicArray<T> *dataHolder;
    virtual ArraySequence<T> *Clone() = 0;
    virtual ArraySequence<T> *Instance() = 0;
public:
    //constructors
    ArraySequence()
    {
        dataHolder = new DynamicArray<T>();
    }
    ArraySequence(const T *items, int count)
    {
        dataHolder = new DynamicArray<T>(items, count);
    }
    ArraySequence(const ArraySequence<T> &otherArraySequence)
    {
        dataHolder = new DynamicArray<T>(otherArraySequence.GetDataHolder());
    }
    explicit ArraySequence(const Sequence<T> &otherSequence)
    {
        dataHolder = new DynamicArray<T>(otherSequence.GetDataHolder());
    }
    //operator overloading ([], +=)
    const T &operator[](int index) const
    {
        const T element = dataHolder->Get(index);
        return element;
    }
    ArraySequence<T> &operator+=(ArraySequence<T> &otherArraySequence) const
    {
        return Concat(otherArraySequence);
    }
    //destructor
    virtual ~ArraySequence()
    {
        delete dataHolder;
    }
    //other methods
    const T &GetFirst() const override
    {
        return dataHolder->GetFirst();
    }
    const T &GetLast() const override
    {
        return dataHolder->GetLast();
    }
    const T &Get(int index) const override
    {
        return dataHolder->Get(index);
    }
    [[nodiscard]] int GetLength() const override
    {
        return dataHolder->GetSize();
    }
    const BaseCollection<T> &GetDataHolder() const override
    {
        return *dataHolder;
    }
    ArraySequence<T> &Set(const T &value, int index) override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->Set(value, index);
        return *result;
    }
    ArraySequence<T> &Prepend(const T &item) override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->InsertAt(item, 0);
        return *result;
    }
    ArraySequence<T> &Append(const T &item) override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->PushBack(item);
        return *result;
    }
    ArraySequence<T> &InsertAt(const T &item, int index) override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->InsertAt(item, index);
        return *result;
    }
    ArraySequence<T> &RemoveFirst() override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->Erase(0);
        return *result;
    }
    ArraySequence<T> &RemoveLast() override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->PopBack();
        return *result;
    }
    ArraySequence<T> &Erase(int index) override
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->Erase(index);
        return *result;
    }
    ArraySequence<T> &Concat(ArraySequence<T> &otherArraySequence)
    {
        ArraySequence<T> *result = Instance();
        result->dataHolder->Concat(*(otherArraySequence.dataHolder));
        return *result;
    }
    ArraySequence<T> &GetSubSequence(int startIndex, int endIndex) override
    {
        ArraySequence<T> *result = Clone();
        delete result->dataHolder;
        try
        {
            result->dataHolder = &(dataHolder->GetSubArray(startIndex, endIndex));
        }
        catch (...)
        {
            delete result;
            throw std::bad_alloc();
        }
        return *result;
    }
    //map-reduce
    ArraySequence<T> &Map(T (*function)(const T &argument)) override
    {
        ArraySequence<T> *result = Instance();
        for (int index{0}; index < GetLength(); ++index)
        {
            T element = dataHolder->Get(index);
            T newElement = function(element);
            result->dataHolder->Set(newElement, index);
        }
        return *result;
    }
    ArraySequence<T> &Where(bool (*condition)(const T &argument)) override
    {
        ArraySequence<T> *result = Instance();
        int newIndex = 0;
        for (int index{0}; index < GetLength(); ++index)
        {
            T element = dataHolder->Get(index);
            if (condition(element))
            {
                result->dataHolder->Set(element, newIndex);
                newIndex++;
            }
        }
        for (int backIndex{GetLength()}; backIndex > newIndex; --backIndex)
        {
            result->dataHolder->PopBack();
        }
        return *result;
    }
    T Reduce(T (*function)(const T &leftArgument, const T &rightArgument), const T &initialValue) override
    {
        T result = initialValue;
        for (int index{0}; index < GetLength(); ++index)
        {
            result = function(dataHolder->Get(index), result);
        }
        return result;
    }
};

//mutable version
template <class T>
class MutableArraySequence final : public ArraySequence<T>
{
protected:
    MutableArraySequence<T> *Clone() override
    {
        auto *result = new MutableArraySequence<T>(*this);
        return result;
    }
    MutableArraySequence<T> *Instance() override
    {
        return this;
    }
public:
    //constructors
    MutableArraySequence() : ArraySequence<T>() {}
    MutableArraySequence(const T *items, int count) : ArraySequence<T>(items, count) {}
    MutableArraySequence(const MutableArraySequence<T> &otherArraySequence) : ArraySequence<T>(otherArraySequence) {}
    explicit MutableArraySequence(const Sequence<T> &otherSequence) : ArraySequence<T>(otherSequence) {}
    MutableArraySequence<T> &operator=(const Sequence<T> &otherSequence)
    {
        if (this != &otherSequence)
        {
            *(this->dataHolder) = otherSequence.GetDataHolder();
        }
        return *this;
    }
};

//immutable version
template <class T>
class ImmutableArraySequence final : public ArraySequence<T>
{
protected:
    ImmutableArraySequence<T> *Clone() override
    {
        auto *result = new ImmutableArraySequence<T>(*this);
        return result;
    }
    ImmutableArraySequence<T> *Instance() override
    {
        return Clone();
    }
public:
    //constructors
    ImmutableArraySequence() : ArraySequence<T>() {}
    ImmutableArraySequence(const T *items, int count) : ArraySequence<T>(items, count) {}
    ImmutableArraySequence(const ImmutableArraySequence<T> &otherArraySequence) : ArraySequence<T>(otherArraySequence) {}
    explicit ImmutableArraySequence(const Sequence<T> &otherSequence) : ArraySequence<T>(otherSequence) {}
};
