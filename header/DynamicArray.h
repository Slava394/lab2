#pragma once
#include <stdexcept>
#include "BaseCollection.h"


//class DynamicArray
template <class T>
class DynamicArray final : public BaseCollection<T>
{
private:
    T *data;
    int allocatedMemory;
    int size;
    //decomposition
    void CheckIndexRange(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
    }

    void Reserve(int newAllocatedMemory)
    {
        if (newAllocatedMemory < size)
        {
            throw std::invalid_argument("Can`t allocate memory less than the current value");
        }
        T *newData = nullptr;
        if (newAllocatedMemory > 0) {
            newData = new T[newAllocatedMemory];
            for (int index{0}; index < size; ++index)
            {
                newData[index] = std::move(data[index]);
            }
        }
        delete[] data;
        data = newData;
        allocatedMemory = newAllocatedMemory;
    }

    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            throw std::invalid_argument("Can`t recreate array with negative length");
        }
        T *newData;
        if (newSize > 0)
        {
            newData = new T[newSize];
            for (int index{0}; index < std::min(size, newSize); ++index)
            {
                newData[index] = std::move(data[index]);
            }
        }
        delete[] data;
        data = newData;
        allocatedMemory = newSize;
        size = newSize;
    }
public:
    //constructors
    DynamicArray() : DynamicArray(0) {}

    explicit DynamicArray(int length) : data{nullptr}, allocatedMemory{length}, size{length}
    {
        if (length < 0)
        {
            throw std::invalid_argument("Can`t create array with negative length");
        }
        else if (length > 0)
        {
            data = new T[length];
        }
    }

    DynamicArray(const T *items, int count) : data{nullptr}, allocatedMemory{count}, size{count}
    {
        if (count < 0)
        {
            throw std::invalid_argument("Can`t create array with negative amount of element");
        }
        else if (count > 0)
        {
            data = new T[count];
            for (int index{0}; index < count; ++index)
            {
                data[index] = items[index];
            }
        }
    }

    DynamicArray(const DynamicArray<T> &otherDynamicArray) : data{nullptr},
                                                             allocatedMemory{otherDynamicArray.allocatedMemory},
                                                             size{otherDynamicArray.size}

    {
        if (otherDynamicArray.allocatedMemory > 0)
        {
            data = new T[otherDynamicArray.allocatedMemory];
            for (int index{0}; index < otherDynamicArray.GetSize(); ++index)
            {
                data[index] = otherDynamicArray.Get(index);
            }
        }
    }

    explicit DynamicArray(const BaseCollection<T> &otherCollection) : data{nullptr},
                                                                      allocatedMemory{otherCollection.GetSize()},
                                                                      size{otherCollection.GetSize()}
    {
        if (otherCollection.GetSize() > 0)
        {
            data = new T[otherCollection.GetSize()];
            for (int index{0}; index < otherCollection.GetSize(); ++index)
            {
                data[index] = otherCollection.Get(index);
            }
        }
    }

    DynamicArray(DynamicArray<T> &&otherDynamicArray)  noexcept : data{otherDynamicArray.data},
                                                                  allocatedMemory{otherDynamicArray.allocatedMemory},
                                                                  size{otherDynamicArray.size}
    {
        otherDynamicArray.data = nullptr;
        otherDynamicArray.allocatedMemory = 0;
        otherDynamicArray.size = 0;
    }

    //operator overloading (=(copy, move), [], +=)
    DynamicArray<T> &operator=(const DynamicArray<T> &otherDynamicArray)
    {
        if (this != &otherDynamicArray)
        {
            T *newData = nullptr;
            if (otherDynamicArray.allocatedMemory > 0)
            {
                newData = new T[otherDynamicArray.allocatedMemory];
                for (int index{0}; index < otherDynamicArray.size; ++index)
                {
                    newData[index] = otherDynamicArray.data[index];
                }
            }
            delete[] data;
            data = newData;
            allocatedMemory = otherDynamicArray.allocatedMemory;
            size = otherDynamicArray.size;
        }
        return *this;
    }

    DynamicArray<T> &operator=(DynamicArray<T> &&otherDynamicArray) noexcept
    {
        if (this != &otherDynamicArray)
        {
            delete[] data;
            data = otherDynamicArray.data;
            allocatedMemory = otherDynamicArray.allocatedMemory;
            size = otherDynamicArray.size;
            otherDynamicArray.data = nullptr;
            otherDynamicArray.allocatedMemory = 0;
            otherDynamicArray.size = 0;
        }
        return *this;
    }

    const T &operator[](int index)
    {
        return Get(index);
    }

    DynamicArray<T> &operator+=(DynamicArray<T> &otherArray)
    {
        Concat(otherArray);
        return *this;
    }

    //destructor
    ~DynamicArray()
    {
        Clear();
    }

    //getters
    const T &GetFirst()
    {
        if (size == 0)
        {
            throw std::logic_error("Can`t get first element from an empty array");
        }
        return data[0];
    }

    const T &GetLast()
    {
        if (size == 0)
        {
            throw std::logic_error("Can`t get last element from an empty array");
        }
        return data[size - 1];
    }

    const T &Get(int index) const override
    {
        CheckIndexRange(index);
        return data[index];
    }

    [[nodiscard]] int GetSize() const override
    {
        return size;
    }

    //setters
    void Set(const T &value, int index)
    {
        CheckIndexRange(index);
        data[index] = value;
    }

    //other methods
    DynamicArray<T> &GetSubArray(int startIndex, int endIndex)
    {
        CheckIndexRange(startIndex);
        if (endIndex < 0 || endIndex > size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (startIndex >= endIndex)
        {
            throw std::logic_error("EndIndex can`t be less then startIndex");
        }
        auto *subsequence = new DynamicArray<T>();
        try
        {
            subsequence->Reserve(endIndex - startIndex);
        }
        catch (...)
        {
            delete subsequence;
            throw std::bad_alloc();
        }
        for (int index{startIndex}; index < endIndex; ++index)
        {
            subsequence->PushBack(Get(index));
        }
        return *subsequence;
    }

    void Concat(DynamicArray<T> &otherArray)
    {
        T *concatData = new T[size + otherArray.size];
        for (int index{0}; index < size; ++index)
        {
            concatData[index] = Get(index);
        }
        for (int index{0}; index < otherArray.size; ++index)
        {
            concatData[size + index] = otherArray.Get(index);
        }
        delete[] data;
        data = concatData;
        size += otherArray.size;
    }

    void InsertAt(const T &value, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        else if (size == allocatedMemory && size == 0)
        {
            Reserve(2);
        }
        else if (size == allocatedMemory)
        {
            Reserve(allocatedMemory * 2);
        }
        for (int backIndex{size}; index < backIndex; --backIndex)
        {
            data[backIndex] = data[backIndex - 1];
        }
        data[index] = value;
        size++;
    }

    void Erase(int index)
    {
        CheckIndexRange(index);
        for (int newIndex{index}; newIndex + 1 < size; ++newIndex)
        {
            data[newIndex] = data[newIndex + 1];
        }
        size--;
    }

    void PushBack(const T &value)
    {
        if (size == allocatedMemory && size == 0)
        {
            Reserve(2);
        }
        else if (size == allocatedMemory)
        {
            Reserve(allocatedMemory * 2);
        }
        data[size++] = value;
    }

    void PopBack()
    {
        if (size == 0)
        {
            throw std::logic_error("Can`t remove last element from an empty array");
        }
        else if (size > 0)
        {
            size--;
        }
    }

    void Clear()
    {
        delete[] data;
        data = nullptr;
        allocatedMemory = 0;
        size = 0;
    }
};
