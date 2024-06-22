#pragma once
#include "Sequence.h"
#include "LinkedList.h"


//sequence based on linked list
template <class T>
class ListSequence : public Sequence<T>
{
protected:
    LinkedList<T> *dataHolder;
    virtual ListSequence<T> *Clone() = 0;
    virtual ListSequence<T> *Instance() = 0;
public:
    //constructors
    ListSequence()
    {
        dataHolder = new LinkedList<T>();
    }
    ListSequence(const T *items, int count)
    {
        dataHolder = new LinkedList<T>(items, count);
    }
    ListSequence(const ListSequence<T> &otherListSequence)
    {
        dataHolder = new LinkedList<T>(otherListSequence.GetDataHolder());
    }
    explicit ListSequence(const Sequence<T> &otherSequence)
    {
        dataHolder = new LinkedList<T>(otherSequence.GetDataHolder());
    }
    //operator overloading ([], +=)
    const T &operator[](int index) const
    {
        const T element = dataHolder->Get(index);
        return element;
    }
    ListSequence<T> &operator+=(ListSequence<T> &otherListSequence) const
    {
        return Concat(otherListSequence);
    }
    //destructor
    virtual ~ListSequence()
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
    ListSequence<T> &Set(const T &value, int index) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->Set(value, index);
        return *result;
    }
    ListSequence<T> &Prepend(const T &item) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->Prepend(item);
        return *result;
    }
    ListSequence<T> &Append(const T &item) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->Append(item);
        return *result;
    }
    ListSequence<T> &InsertAt(const T &item, int index) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->InsertAt(item, index);
        return *result;
    }
    ListSequence<T> &RemoveFirst() override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->RemoveFirst();
        return *result;
    }
    ListSequence<T> &RemoveLast() override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->RemoveLast();
        return *result;
    }
    ListSequence<T> &Erase(int index) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->Erase(index);
        return *result;
    }
    ListSequence<T> &Concat(ListSequence<T> &otherListSequence)
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->Concat(*(otherListSequence.dataHolder));
        return *result;
    }
    ListSequence<T> &GetSubSequence(int startIndex, int endIndex) override
    {
        ListSequence<T> *result = Clone();
        delete result->dataHolder;
        try
        {
            result->dataHolder = &(dataHolder->GetSubList(startIndex, endIndex));
        }
        catch (...)
        {
            delete result;
            throw std::bad_alloc();
        }
        return *result;
    }
    //map-reduce
    ListSequence<T> &Map(T (*function)(const T &argument)) override
    {
        ListSequence<T> *result = Instance();
        result->dataHolder->ResetTargetNode();
        for (int index{0}; index < GetLength(); ++index)
        {
            T element = result->dataHolder->GetTargetNodeValue();
            T updatedElement = function(element);
            result->dataHolder->Set(updatedElement, index);
        }
        result->dataHolder->ResetTargetNode();
        return *result;
    }
    ListSequence<T> &Where(bool (*condition)(const T &argument)) override
    {
        ListSequence<T> *result = Instance();
        int prevLength = GetLength();
        int shift = 0;
        for (int index{0}; index < prevLength; ++index)
        {
            T element = result->dataHolder->Get(index - shift);
            if (!condition(element))
            {
                result->dataHolder->Erase(index - shift);
                shift++;
            }
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
class MutableListSequence final : public ListSequence<T>
{
protected:
    MutableListSequence<T> *Clone() override
    {
        auto *result = new MutableListSequence<T>(*this);
        return result;
    }
    MutableListSequence<T> *Instance() override
    {
        return this;
    }
public:
    //constructors
    MutableListSequence() : ListSequence<T>() {}
    MutableListSequence(const T *items, int count) : ListSequence<T>(items, count) {}
    MutableListSequence(const MutableListSequence<T> &otherListSequence) : ListSequence<T>(otherListSequence) {}
    explicit MutableListSequence(const Sequence<T> &otherSequence) : ListSequence<T>(otherSequence) {}
    MutableListSequence<T> &operator=(const Sequence<T> &otherSequence)
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
class ImmutableListSequence final : public ListSequence<T>
{
protected:
    ImmutableListSequence<T> *Clone() override
    {
        auto *result = new ImmutableListSequence<T>(*this);
        return result;
    }
    ImmutableListSequence<T> *Instance() override
    {
        return Clone();
    }
public:
    //constructors
    ImmutableListSequence() : ListSequence<T>() {}
    ImmutableListSequence(const T *items, int count) : ListSequence<T>(items, count) {}
    ImmutableListSequence(const ImmutableListSequence<T> &otherListSequence) : ListSequence<T>(otherListSequence) {}
    explicit ImmutableListSequence(const Sequence<T> &otherSequence) : ListSequence<T>(otherSequence) {}
};
