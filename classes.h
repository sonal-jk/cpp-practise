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

class Suppliers{
    int id,phone;
    string name,addr,city,state;
    public:
    void add();
    void remove();
    void search();
};

class Purchases{
    int sup_id, book_id,qty,price;
    string ord_date,rec_date;
    public:
    void add();
    void cancel();
    void view_all();
    void received();  
};

class Employees{
    int id,phone,salary;
    string name,mng,addr,city;
    public:
    void add();
    void search();
    void assign_mng();
    void view_all();
    void up_sal();
};

class Members{};
class Sales{};

#endif