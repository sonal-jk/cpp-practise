//SELF-MADE HEADER FILE 

#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
using namespace std;

//--CLASS DECLARATIONS--

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
    int o_id,sup_id, book_id,qty,price;
    string rec_date;
    public:
    void add();
    void mark_R();
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

class Members{
    int id,phone;
    string name,expiry;
    public:
    void add();
    void search();
    void refresh();
};
class Sales{
    int id,mem_id,book_id,qty,price;
    string sale_date;
    public:
    void add();
    void total();
    void search();
};

#endif