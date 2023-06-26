/*---BOOKSTORE MANAGEMENT SYSTEM---*/


#include <iostream>
#include "windows.h"
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>
#include "classes.h"
#include <conio.h>
#include <string.h>
#include <sstream>
using namespace std;

MYSQL* conn=NULL;
string query;
stringstream stat;
const char* a;
MYSQL_RES* result;
MYSQL_ROW row;

/*CLASS FUNCTIONS*/

void Book::add(){

        std::cout<<"Enter book id :";
        std::cin>>id;
        std::cout<<"Enter book's name :";
        std::cin>>name;
        std::cout<<"Enter author's name :";
        std::cin>>author;
        std::cout<<"Enter book's price :";
        std::cin>>price;
        std::cout<<"Enter quantity of books :";
        std::cin>>qty;
        

        stat.str("");
        stat<<"Insert into books values("<<id<<",'"<<name<<"','"<<author<<"',"<<price<<","<<qty<<");";
        query=stat.str();
        a=query.c_str();
        int res=mysql_query(conn,a);

        if (res!=0){
            std::cout<<"error";
        }
        else{
            std::cout<<"success";
        }
        std::cout<<"\n";
        
    }

void Book:: up_price(){
        
        std::cout<<"Enter book id :";
        std::cin>>id;
        
        stat.str("");
        stat<<"select b_id,b_name,b_price from books where b_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        while ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"Book's id :"<<row[0]<<"\n";
            std::cout<<"Book's name :"<<row[1]<<"\n";
            std::cout<<"Book's price :"<<row[2]<<"\n";
        }
        
        char c;
        std::cout<<"do you want to change the price? type y/n :";
        std::cin>>c;
        if (c=='y'){
            std::cout<<"Enter book's new price :";
            std::cin>>price;
            stat.str("");
            stat<<"Update books set b_price="<<price<<" where b_id="<<id<<";";
            query=stat.str();
            a=query.c_str();
            int res=mysql_query(conn,a);

            if (res!=0){
               std::cout<<"error";
            }
            else{
               std::cout<<"success";
            }
            std::cout<<"\n";
            }
        else{
            return;
        }
        
    }

void Book::search(){
    std::cout<<"Enter book id to search :";
    std::cin>>id;
    stat.str("");
    stat<<"select * from books where b_id="<<id<<";";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    std::cout<<"\n";
    if ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"Book's id :"<<row[0]<<"\n";
    std::cout<<"Book's name :"<<row[1]<<"\n";
    std::cout<<"Book's author :"<<row[2]<<"\n";
    std::cout<<"Book's price :"<<row[3]<<"\n";
    std::cout<<"Book's quantity :"<<row[4]<<"\n";
    }
    else{
        std::cout<<"No record found";
    }
}

void Book::dis_all(){
    int count=1;
    stat.str("");
    stat<<"select * from books;";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"Book :"<<count<<"\n \n";
    std::cout<<"Book's id :"<<row[0]<<"\n";
    std::cout<<"Book's name :"<<row[1]<<"\n";
    std::cout<<"Book's author :"<<row[2]<<"\n";
    std::cout<<"Book's price :"<<row[3]<<"\n";
    std::cout<<"Book's quantity :"<<row[4]<<"\n \n";
    count++;
    }

}

void Suppliers::add(){

        std::cout<<"Enter supplier id :";
        std::cin>>id;
        std::cout<<"Enter supplier's name :";
        std::cin>>name;
        std::cout<<"Enter supplier's phone number :";
        std::cin>>phone;
        std::cout<<"Enter supplier's address :";
        std::cin>>addr;
        std::cout<<"Enter supplier's city :";
        std::cin>>city;
        std::cout<<"Enter supplier's state :";
        std::cin>>state;
        

        stat.str("");
        stat<<"Insert into suppliers values("<<id<<",'"<<name<<"',"<<phone<<",'"<<addr<<"','"<<city<<"','"<<state<<"');";
        query=stat.str();
        a=query.c_str();
        int res=mysql_query(conn,a);

        if (res!=0){
            std::cout<<"error";
        }
        else{
            std::cout<<"success";
        }
        std::cout<<"\n";
        
    }

void Suppliers::remove(){
        std::cout<<"Enter supplier id to remove :";
        std::cin>>id;

        stat.str("");
        stat<<"select * from suppliers where s_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        while ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Supplier's id :"<<row[0]<<"\n";
            std::cout<<"Supplier's name :"<<row[1]<<"\n";
            std::cout<<"Supplier's phone :"<<row[2]<<"\n";
            std::cout<<"Supplier's address :"<<row[3]<<"\n";
            std::cout<<"Supplier's city :"<<row[4]<<"\n";
            std::cout<<"Supplier's state :"<<row[5]<<"\n";
        }
        
        char c;
        std::cout<<"do you want to remove this supplier? type y/n :";
        std::cin>>c;
        if (c=='y'){
            stat.str("");
            stat<<"Delete from suppliers where s_id="<<id<<";";
            query=stat.str();
            a=query.c_str();
            int res=mysql_query(conn,a);

            if (res!=0){
               std::cout<<"error";
            }
            else{
               std::cout<<"success";
            }
            std::cout<<"\n";
            }
        else{
            return;
        }
    }

void Suppliers::search(){
    std::cout<<"Enter supplier id to search :";
    std::cin>>id;
    stat.str("");
    stat<<"select * from suppliers where s_id="<<id<<";";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    std::cout<<"\n";
    if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Supplier's id :"<<row[0]<<"\n";
            std::cout<<"Supplier's name :"<<row[1]<<"\n";
            std::cout<<"Supplier's phone :"<<row[2]<<"\n";
            std::cout<<"Supplier's address :"<<row[3]<<"\n";
            std::cout<<"Supplier's city :"<<row[4]<<"\n";
            std::cout<<"Supplier's state :"<<row[5]<<"\n";
    }
    else{
        std::cout<<"No record found";
    }
    }


void Employees::add(){
    
    std::cout<<"Enter employees id :";
    std::cin>>id;
    std::cout<<"Enter employees name :";
    std::cin>>name;
    std::cout<<"Enter employees phone number :";
    std::cin>>phone;
    std::cout<<"Enter employees salary :";
    std::cin>>salary;
    std::cout<<"Enter employees manager status in yes or no :";
    std::cin>>mng;
    std::cout<<"Enter employees address :";
    std::cin>>addr;
    std::cout<<"Enter employees city :";
    std::cin>>city;

    stat.str("");
    stat<<"Insert into employee values("<<id<<",'"<<name<<"',"<<phone<<","<<salary<<",'"<<mng<<"','"<<addr<<"','"<<city<<"';";
    query=stat.str();
    a=query.c_str();
    int res=mysql_query(conn,a);
    if (res!=0){
            std::cout<<"error";
        }
    else{
            std::cout<<"success";
        }
    std::cout<<"\n";
}

void Employees::search(){
    std::cout<<"Enter employee id to search :";
    std::cin>>id;
    stat.str("");
    stat<<"select * from employee where e_id="<<id<<";";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    std::cout<<"\n";
    if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Employee's id :"<<row[0]<<"\n";
            std::cout<<"Employee's name :"<<row[1]<<"\n";
            std::cout<<"Employee's phone :"<<row[2]<<"\n";
            std::cout<<"Employee's salary :"<<row[3]<<"\n";
            std::cout<<"Employee's mangerial status :"<<row[4]<<"\n";
            std::cout<<"Employee's address :"<<row[5]<<"\n";
            std::cout<<"Employee's city :"<<row[6]<<"\n";

    }
    else{
        std::cout<<"No record found";
    }

}

void Employees::assign_mng(){
    std::cout<<"Enter employee id to check managerial status:";
        std::cin>>id;
        
        stat.str("");
        stat<<"select e_id,e_name,manager from employee where e_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);

        while ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"Employee's id :"<<row[0]<<"\n";
            std::cout<<"Employee's name :"<<row[1]<<"\n";
            std::cout<<"Employee's status :"<<row[2]<<"\n";
            if (row[2]!="yes"){

                char c;
                std::cout<<"The employee isn't a manager. Do you want to change the status? type y/n :";
                std::cin>>c;
                if (c=='y'){
                   stat.str("");
                   stat<<"Update employees set manager='yes' where e_id="<<id<<";";
                   query=stat.str();
                   a=query.c_str();
                   int res=mysql_query(conn,a);

                   if (res!=0){
                     std::cout<<"error";
                    }
                   else{
                     std::cout<<"success";
                    }
                   std::cout<<"\n";
                }
            else{
               return;
            }
            }
        }
                
}

void Employees::view_all(){
    int count=1;
    stat.str("");
    stat<<"select * from employee;";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"\n";
    std::cout<<"Employee's id :"<<row[0]<<"\n";
    std::cout<<"Employee's name :"<<row[1]<<"\n";
    std::cout<<"Employee's phone :"<<row[2]<<"\n";
    std::cout<<"Employee's salary :"<<row[3]<<"\n";
    std::cout<<"Employee's mangerial status :"<<row[4]<<"\n";
    std::cout<<"Employee's address :"<<row[5]<<"\n";
    std::cout<<"Employee's city :"<<row[6]<<"\n";
    count++;
    }
}

void Employees::up_sal(){
    std::cout<<"Enter employee id :";
        std::cin>>id;
        
        stat.str("");
        stat<<"select e_id,e_name,e_sal from employee where e_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        while ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"Employee's id :"<<row[0]<<"\n";
            std::cout<<"Employee's name :"<<row[1]<<"\n";
            std::cout<<"Employee's salary :"<<row[2]<<"\n";
        }
        
        char c;
        std::cout<<"do you want to change the salary? type y/n :";
        std::cin>>c;
        if (c=='y'){
            std::cout<<"Enter Employee's new salary :";
            std::cin>>salary;
            stat.str("");
            stat<<"Update employee set e_sal="<<salary<<" where e_id="<<id<<";";
            query=stat.str();
            a=query.c_str();
            int res=mysql_query(conn,a);

            if (res!=0){
               std::cout<<"error";
            }
            else{
               std::cout<<"success";
            }
            std::cout<<"\n";
            }
        else{
            return;
        }
}

/*FUNCTION DECLARATION*/

void book_menu();
void sup_menu();
void pur_menu();
void emp_menu();
void mem_menu();
void sales_menu();

/*MAIN FUNCTION*/

int main(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "12345678", "rough", 0, NULL, 0);

    if(conn){
        std::cout << "Connected" << endl;
    } else {
        std::cout << "Not connected" << endl;
    }
    /*
    int res=mysql_query(conn,"Insert into stud values(3)");
    if (res!=0){
        std::cout<<"error";
    }
    else{
        std::cout<<"success";
    }
*/
    /*START*/

   std::cout<<"WELCOME TO THE BOOKSTORE!";

    string ans="yes";
    while (ans=="yes"){
        int c;
        std::cout<<" Please select an option from the given list by typing the number:\
           \n 1. Books\n 2. Suppliers\n 3. Purchases\n 4. Employees\n 5. Members\n 6. Sales\n 7. Exit"<<"\n";
        
        std::cout<<"Select one option :";
        std::cin>>c;
        std::cout<<"\n";
        switch(c){
            case 1:
            book_menu();
            break;
            
            case 2:
            sup_menu();
            break;
       
            case 3:
            pur_menu();
            break;

            case 4:
            emp_menu();
            break;
            
            case 5:
            mem_menu();
            break;
                   
            case 6:
            sales_menu();
            break;
            
            case 7:
            exit(1);
            break;
            
            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    std::cout<<"\n"<<"Do you want to continue? Type yes or no :";
    std::cin>>ans;

    }
   return 0;
}

/*FUNCTIONS FOR MENUS OF DIFFERENT CATEGORIES*/

void book_menu(){
    Book b;
    int c;
    std::cout<<"--BOOKS MENU--\
    \n 1. Add\n 2. Update Price\n 3. Search\n 4. Display All\n 5. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            b.add();
            break;
            
            case 2:
            b.up_price();
            break;
       
            case 3:
            b.search();
            break;

            case 4:
            b.dis_all();
            break;
            
            case 5:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;

}

void sup_menu(){
    Suppliers s;
    int c;
    std::cout<<"--SUPPLIERS MENU--\
    \n 1. Add\n 2. Remove\n 3. Search\n 4. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            s.add();
            break;
            
            case 2:
            s.remove();
            break;
       
            case 3:
            s.search();
            break;

            case 4:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;

}

void pur_menu(){
  
    int c;
    std::cout<<"--PURCHASES MENU--\
    \n 1. New Order\n 2. Cancel Order\n 3. View All\n 4. Received Order\n 5. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            std::cout<<"A";
            break;
            
            case 2:
            std::cout<<"B";
            break;
       
            case 3:
            std::cout<<"C";
            break;

            case 4:
            std::cout<<"D";
            break;
            
            case 5:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;
}

void emp_menu(){
  
    int c;
    std::cout<<"--EMPLOYEE MENU--\
    \n 1. New Employee\n 2. Search Employee\n 3. Assign Manager\n 4. View All\n 5. Update Salary\n 6. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;
    Employees e;
    switch(c){
            case 1:
            e.add();
            break;
            
            case 2:
            e.search();
            break;
       
            case 3:
            e.assign_mng();
            break;

            case 4:
            e.view_all();
            break;

            case 5:
            e.up_sal();
            break;
            
            case 6:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;

}

void mem_menu(){
  
    int c;
    std::cout<<"--MEMBERS MENU--\
    \n 1. New Member\n 2. Search Member\n 3. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            std::cout<<"A";
            break;
            
            case 2:
            std::cout<<"B";
            break;
            
            case 3:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;
}

void sales_menu(){
  
    int c;
    std::cout<<"--SALES MENU--\
    \n 1. New Receipt\n 2. Total Sales\n 3. Return to Main Menu\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            std::cout<<"A";
            break;
            
            case 2:
            std::cout<<"B";
            break;
       
            case 3:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;
}
