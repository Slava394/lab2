#pragma once


//for copy constructor DynamicArray <-> LinkedList
template <class T>
class BaseCollection
{
public:
    virtual const T &Get(int index) const = 0;
    [[nodiscard]] virtual int GetSize() const = 0;
};
