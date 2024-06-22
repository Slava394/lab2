#pragma once
#include <iostream>
#include <sstream>
#include "../header/Sequence.h"


void getFirst(Sequence<int> &sequence);

void getLast(Sequence<int> &sequence);

void get(Sequence<int> &sequence, const std::string &args);

void getLength(Sequence<int> &sequence);

void prepend(Sequence<int> &sequence, const std::string &args);

void append(Sequence<int> &sequence, const std::string &args);

void insertAt(Sequence<int> &sequence, const std::string &args);

void removeFirst(Sequence<int> &sequence);

void removeLast(Sequence<int> &sequence);

void erase(Sequence<int> &sequence, const std::string &args);

void print(const Sequence<int> &sequence);

void help();

void interface();
