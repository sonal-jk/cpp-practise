#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;

class Book{
    int id,price,qty;
    string name, author;
    public:
    void add();
    void up_price();
    void search();
    void dis_all();
};

class Suppliers{};
class Purchases{};
class Employees{};
class Members{};
class Sales{};

#endif