#include <iostream>
#include <sstream>
#include <readline/readline.h>
#include <readline/history.h>
#include <functional>
#include "../header/ArraySequence.h"
#include "../header/ListSequence.h"
#include "CLI.h"


struct SequenceWithName
{
    std::string name;
    std::string sequenceType;
    Sequence<int> *sequence;
    SequenceWithName(std::string name,
                     std::string sequenceType,
                     Sequence<int> *sequence) : name{std::move(name)},
                                                sequenceType{std::move(sequenceType)},
                                                sequence{sequence} {}
};

template <typename functionType, typename ...argumentType>
void handleExceptions(functionType function, argumentType &&...args)
{
    try
    {
        function(std::forward<argumentType>(args)...);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void getFirst(Sequence<int> &sequence)
{
    std::cout << "First element: " << sequence.GetFirst() << std::endl;
}

void getLast(Sequence<int> &sequence)
{
    std::cout << "Last element: " << sequence.GetLast() << std::endl;
}

void get(Sequence<int> &sequence, std::istringstream &args)
{
    int index;
    if (args >> index)
    {
        std::cout << "Element at " << index << ": " << sequence.Get(index) << std::endl;
    }
    else
    {
        std::cerr << "Error: Invalid index" << std::endl;
    }
}

void getLength(Sequence<int> &sequence)
{
    std::cout << "Length: " << sequence.GetLength() << std::endl;
}

void prepend(Sequence<int> &sequence, std::istringstream &args)
{
    int value;
    while (args >> value)
    {
        sequence.Prepend(value);
    }
    print(sequence);
}

void append(Sequence<int> &sequence, std::istringstream &args)
{
    int value;
    while (args >> value)
    {
        sequence.Append(value);
    }
    print(sequence);
}

void insertAt(Sequence<int> &sequence, std::istringstream &args)
{
    int value, index;
    if (args >> value >> index)
    {
        sequence.InsertAt(value, index);
    }
    else
    {
        std::cerr << "Error: Invalid value or index" << std::endl;
    }
    print(sequence);
}

void removeFirst(Sequence<int> &sequence)
{
    sequence.RemoveFirst();
    print(sequence);
}

void removeLast(Sequence<int> &sequence)
{
    sequence.RemoveLast();
    print(sequence);
}

void erase(Sequence<int> &sequence, std::istringstream &args)
{
    int index;
    if (args >> index)
    {
        sequence.Erase(index);
    }
    else
    {
        std::cerr << "Error: Invalid index" << std::endl;
    }
    print(sequence);
}

void map(Sequence<int> &sequence, std::istringstream &args)
{
    std::string functionName;
    args >> functionName;
    if (functionName == "*3")
    {
        sequence.Map([](const int &x) { return x * 3; });
    }
    else if (functionName == "/2")
    {
        sequence.Map([](const int &x) { return x / 2; });
    }
    else
    {
        std::cerr << "Error: Invalid function name " << functionName << ". Use '*3' или '/2'." << std::endl;
        return;
    }
    print(sequence);
}

void reduce(Sequence<int> &sequence, std::istringstream &args, int initialValue)
{
    std::string functionName;
    args >> functionName;
    int result;
    if (functionName == "+")
    {
        result = sequence.Reduce([](const int &a, const int &b) { return a + b; }, initialValue);
    }
    else if (functionName == "*")
    {
        result = sequence.Reduce([](const int &a, const int &b) { return a * b; }, initialValue);
    }
    else
    {
        std::cerr << "Error: Invalid binary operation name " << functionName << ". Use '+' or '*'." << std::endl;
        return;
    }
    std::cout << "Reduce with " << functionName << ": " << result << std::endl;
}

void print(const Sequence<int> &sequence)
{
    for (int index{0}; index < sequence.GetLength(); ++index)
    {
        std::cout << sequence.Get(index) << " ";
    }
    std::cout << std::endl;
}

void help()
{
    std::cout << "Available commands:\n"
              << "printAll - Print the sequences\n"
              << "create <name> <array|list> <args (optional)> - Create a new sequence based on array/list\n"
              << "getFirst <name> - Get the first element\n"
              << "getLast <name> - Get the last element\n"
              << "get <name> <index> - Get the element at the specified index\n"
              << "getLength <name> - Get the length of the sequence\n"
              << "prepend <name> <values> - Prepend a value to the sequence\n"
              << "append <name> <values> - Append a value to the sequence\n"
              << "insert <name> <value> <index> - Insert a value at the specified index\n"
              << "removeFirst <name> - Remove the first element\n"
              << "removeLast <name> - Remove the last element\n"
              << "erase <name> <index> - Erase the element at the specified index\n"
              << "print <name> - Print the sequence\n"
              << "map <name> <*3|/2> - Apply the chosen function to all elements in the sequence\n"
              << "reduce <name> <initial> <*|+> - Reduce the sequence using the chosen operation\n"
              << "help - Show this help message\n"
              << "exit - Exit the program\n";
}

SequenceWithName *findSequenceByName(const MutableArraySequence<SequenceWithName *> &sequences,
                                     std::string &name,
                                     int isValueNeeded)
{
    SequenceWithName *sequenceWithName = nullptr;
    for (int index{0}; index < sequences.GetLength(); ++index)
    {
        if (sequences.Get(index)->name == name)
        {
            sequenceWithName = sequences.Get(index);
        }
    }
    if (sequenceWithName == nullptr && isValueNeeded == 1)
    {
        std::cerr << "Error: Sequence " << name << " not found." << std::endl;
    }
    if (sequenceWithName != nullptr && isValueNeeded == 0)
    {
        std::cerr << "Error: Sequence " << sequenceWithName->name << " already exists." << std::endl;
    }
    return sequenceWithName;
}

void printSequences(const MutableArraySequence<SequenceWithName *> &sequences)
{
    for (int index{0}; index < sequences.GetLength(); ++index)
    {
        std::cout << sequences.Get(index)->name << " ";
    }
    std::cout << std::endl;
}

void createSequence(MutableArraySequence<SequenceWithName *> &sequences, std::istringstream &stringStream)
{
    std::string name, sequenceType;
    stringStream >> name;
    if (name.empty())
    {
        std::cerr << "Error: Missing name for sequence creation" << std::endl;
        return;
    }
    SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 0);
    if (sequenceWithName == nullptr)
    {
        stringStream >> sequenceType;
        if (sequenceType == "array" || sequenceType == "list")
        {
            int argument;
            Sequence<int> *sequence;
            if (sequenceType == "array")
            {
                sequence = new MutableArraySequence<int>();
            }
            else
            {
                sequence = new MutableListSequence<int>();
            }
            while (stringStream >> argument)
            {
                sequence->Append(argument);
            }
            try
            {
                sequenceWithName = new SequenceWithName(name, sequenceType, sequence);
            }
            catch (...)
            {
                delete sequence;
                std::cerr << "Error: Failed to create sequence " << name << std::endl;
                return;
            }
            sequences.Append(sequenceWithName);
        }
        else if (sequenceType.empty())
        {
            std::cerr << "Error: Missing type for sequence creation" << std::endl;
        }
        else
        {
            std::cerr << "Error: Invalid type " << sequenceType << ". Use 'array' or 'list'." << std::endl;
        }
    }
}

void interface()
{
    MutableArraySequence<SequenceWithName *> sequences;
    std::string line, command, name, sequenceType;
    std::cout << "Sequence CLI\nType \"help\" for more information.\n";
    while (true)
    {
        char *input = readline(">>> ");
        if (input == nullptr)
        {
            break;
        }
        line = std::string(input);
        if (line.empty())
        {
            continue;
        }
        add_history(line.c_str());
        free(input);
        std::istringstream stringStream{line};
        stringStream >> command;
        if (command == "create")
        {
            handleExceptions<void (*)(MutableArraySequence<SequenceWithName *> &,
                             std::istringstream &)>(createSequence, sequences, stringStream);
        }
        else if (command == "printAll")
        {
            handleExceptions<void (*)(const MutableArraySequence<SequenceWithName *> &)>(printSequences,
                                                                                              sequences);
        }
        else if (command == "getFirst")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &)>(getFirst, *(sequenceWithName->sequence));
            }
        }
        else if (command == "getLast")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &)>(getLast, *(sequenceWithName->sequence));
            }
        }
        else if (command == "get")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &)>(get,
                                                                                  *(sequenceWithName->sequence),
                                                                                  stringStream);
            }
        }
        else if (command == "getLength")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &)>(getLength, *(sequenceWithName->sequence));
            }
        }
        else if (command == "prepend")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &)>(prepend,
                                                                                  *(sequenceWithName->sequence),
                                                                                  stringStream);
            }
        }
        else if (command == "append")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &)>(append,
                                                                                  *(sequenceWithName->sequence),
                                                                                  stringStream);
            }
        }
        else if (command == "insert")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &)>(insertAt,
                                                                                  *(sequenceWithName->sequence),
                                                                                  stringStream);
            }
        }
        else if (command == "removeFirst")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &)>(removeFirst, *(sequenceWithName->sequence));
            }
        }
        else if (command == "removeLast")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &)>(removeLast, *(sequenceWithName->sequence));
            }
        }
        else if (command == "erase")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &)>(erase,
                                                                                  *(sequenceWithName->sequence),
                                                                                  stringStream);
            }
        }
        else if (command == "print")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }
            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(const Sequence<int> &)>(print, *(sequenceWithName->sequence));
            }
        }
        else if (command == "map")
        {
            stringStream >> name;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }

            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                    handleExceptions<void (*)(Sequence<int> &, std::istringstream &)> (map,
                                                                                       *(sequenceWithName->sequence),
                                                                                       stringStream);
            }
        }
        else if (command == "reduce")
        {
            int initValue;
            stringStream >> name >> initValue;
            if (name.empty())
            {
                std::cerr << "Error: Missing name for sequence" << std::endl;
                continue;
            }

            SequenceWithName *sequenceWithName = findSequenceByName(sequences, name, 1);
            if (sequenceWithName != nullptr)
            {
                handleExceptions<void (*)(Sequence<int> &, std::istringstream &, int)> (reduce,
                                                                                   *(sequenceWithName->sequence),
                                                                                   stringStream,
                                                                                   initValue);
            }
        }
        else if (command == "help")
        {
            handleExceptions<void (*)()>(help);
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            std::cerr << "Error: Unknown command: " << command << std::endl;
        }
    }
    for (int index{0}; index < sequences.GetLength(); ++index)
    {
        delete sequences.Get(index)->sequence;
        delete sequences.Get(index);
    }
}