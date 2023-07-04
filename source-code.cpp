/*---BOOKSTORE MANAGEMENT SYSTEM---*/

//All the header files that need to be included...
#include <iostream>
#include "windows.h"
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>
//user defined header file
#include "classes.h"
#include <conio.h>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;


//Global variables
MYSQL* conn=NULL;
string query;
stringstream stat;
const char* a;
MYSQL_RES* result;
MYSQL_ROW row;

//Current date
time_t t= time(0);
tm *now= localtime(&t);
int y=1900+now->tm_year;
int m=1+now->tm_mon;
int d=now->tm_mday;


/*--CLASS FUNCTIONS--*/

void Book::add(){
        std::cout<<"\n";
        std::cout<<"Enter book id :";
        std::cin>>id;
        //If not added then >> operator only takes the input and leaves '\n' character which when read by getline() moves to next input
        //input buffer is cleared of any left over new line characters from the previous input
        cin.ignore(); 
        std::cout<<"Enter book's name :";
        //getlie fn is used to take a complete sentence or more as for cin, it only takes a single word or character
        getline(std::cin,name,'\n');
        std::cout<<"Enter author's name :";
        getline(std::cin,author,'\n');
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
            std::cout<<"Error!";
        }
        else{
            std::cout<<"Record added successfully!";
        }
        std::cout<<"\n";
        
    }

void Book:: up_price(){
        std::cout<<"\n";
        std::cout<<"Enter book id :";
        std::cin>>id;
        
        std::cout<<"\n";
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
        std::cout<<"\nDo you want to change the price? type y/n :";
        std::cin>>c;
        std::cout<<"\n";
        if (c=='y'){
            std::cout<<"Enter book's new price :";
            std::cin>>price;
            stat.str("");
            stat<<"Update books set b_price="<<price<<" where b_id="<<id<<";";
            query=stat.str();
            a=query.c_str();
            int res=mysql_query(conn,a);

            if (res!=0){
               std::cout<<"Error!";
            }
            else{
               std::cout<<"Price changed Successfully!";
            }
            std::cout<<"\n";
            }
        else{
            return;
        }
        
    }

void Book::search(){
    std::cout<<"\n";
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
        std::cout<<"No record found...";
    }
}

void Book::dis_all(){
    std::cout<<"\n";
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
        std::cout<<"\n";
        std::cout<<"Enter supplier id :";
        std::cin>>id;
        cin.ignore();
        std::cout<<"Enter supplier's name :";
        getline(std::cin,name);
        std::cout<<"Enter supplier's phone number :";
        std::cin>>phone;
        cin.ignore();
        std::cout<<"Enter supplier's address :";
        getline(std::cin,addr);
        std::cout<<"Enter supplier's city :";
        getline(std::cin,city);
        std::cout<<"Enter supplier's state :";
         getline(std::cin,state);
        

        stat.str("");
        stat<<"Insert into suppliers values("<<id<<",'"<<name<<"',"<<phone<<",'"<<addr<<"','"<<city<<"','"<<state<<"');";
        query=stat.str();
        a=query.c_str();
        int res=mysql_query(conn,a);

        if (res!=0){
            std::cout<<"Error!";
        }
        else{
            std::cout<<"Record added successfully!";
        }
        std::cout<<"\n";
        
    }

void Suppliers::remove(){
        std::cout<<"\n";
        std::cout<<"Enter supplier id to remove :";
        std::cin>>id;

        stat.str("");
        stat<<"select * from suppliers where s_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Supplier's id :"<<row[0]<<"\n";
            std::cout<<"Supplier's name :"<<row[1]<<"\n";
            std::cout<<"Supplier's phone :"<<row[2]<<"\n";
            std::cout<<"Supplier's address :"<<row[3]<<"\n";
            std::cout<<"Supplier's city :"<<row[4]<<"\n";
            std::cout<<"Supplier's state :"<<row[5]<<"\n";
        
        
        char c;
        std::cout<<"\nDo you want to remove this supplier? type y/n :";
        std::cin>>c;
        if (c=='y'){
            stat.str("");
            stat<<"Delete from suppliers where s_id="<<id<<";";
            query=stat.str();
            a=query.c_str();
            int res=mysql_query(conn,a);

            if (res!=0){
               std::cout<<"Error!";
            }
            else{
               std::cout<<"Record deleted successfully!";
            }
            } }
        else{
            std::cout<<"No record found...";
            return;
        }
        std::cout<<"\n";
    }

void Suppliers::search(){
    std::cout<<"\n";
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

void Purchases::add(){
        std::cout<<"\n";
        std::cout<<"Enter purchase id :";
        std::cin>>o_id;
        std::cout<<"Enter supplier's id :";
        std::cin>>sup_id;
        std::cout<<"Enter book's id :";
        std::cin>>book_id;
        std::cout<<"Enter purchase quantity :";
        std::cin>>qty;
        std::cout<<"Enter purchase recieving date in format 'YYYY-MM-DD' :";
        std::cin>>rec_date;
        std::cout<<"Enter purchase price :";
        std::cin>>price;

        stat.str("");
        stat<<"Insert into purchases values("<<o_id<<","<<sup_id<<","<<book_id<<","<<qty<<",'"<<y<<"-"<<m<<"-"<<d<<"','"<<rec_date<<"',"<<price<<",'N');";
        query=stat.str();
        a=query.c_str();
        int res=mysql_query(conn,a);

        if (res!=0){
            std::cout<<"Error!";
        }
        else{
            std::cout<<"Record added successfully!";
            }
        std::cout<<"\n";
}

void Purchases::mark_R(){
        std::cout<<"\n";
        std::cout<<"Enter order id that is received :";
        std::cin>>o_id;

        stat.str("");
        stat<<"select o_id,receive_date,mark from purchases where o_id="<<o_id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Purchase id :"<<row[0]<<"\n";
            std::cout<<"Receiving Date :"<<row[1]<<"\n";
            std::cout<<"Received or Not :"<<row[2]<<"\n";
        }
        else{
            std::cout<<"No record found...";
            std::cout<<"\n";
            return;
        }

        std::cout<<"Changing Receive Status...";
        stat.str("");
        stat<<"Update purchases set mark='R' where o_id="<<o_id<<";";
        query=stat.str();
        a=query.c_str();
        if(mysql_query(conn,a)){
            std::cout<<"Error!";
        }
        else{
            std::cout<<"Status changed successfully!";
        }
        std::cout<<"\n";
}

void Purchases::cancel(){
        std::cout<<"\n";
        std::cout<<"Enter order id that needs to be cancelled:";
        std::cin>>o_id;

        stat.str("");
        stat<<"select o_id,receive_date,mark from purchases where o_id="<<o_id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Purchase id :"<<row[0]<<"\n";
            std::cout<<"Receiving Date :"<<row[1]<<"\n";
            std::cout<<"Received or Not :"<<row[2]<<"\n";
        }
        else{
            std::cout<<"No record found...";
            std::cout<<"\n";
            return;
        }

        std::cout<<"Cancelling the purchase...";
        stat.str("");
        stat<<"Update purchases set mark='C' where o_id="<<o_id<<";";
        query=stat.str();
        a=query.c_str();
        if(mysql_query(conn,a)){
            std::cout<<"Error!";
        }
        else{
            std::cout<<"Purchase cancelled successfully!";
        }
        std::cout<<"\n";

}

void Purchases::view_all(){
    std::cout<<"\n";
    int count=1;
    stat.str("");
    stat<<"select * from purchases;";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);

    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"\n"<<"Purchase :"<<count<<"\n \n";
    std::cout<<"Purchase id :"<<row[0]<<"\n";
    std::cout<<"Supplier's id :"<<row[1]<<"\n";
    std::cout<<"Book's id :"<<row[2]<<"\n";
    std::cout<<"Purchase quantity :"<<row[3]<<"\n";
    std::cout<<"Order date :"<<row[4]<<"\n";
    std::cout<<"Receiving date :"<<row[5]<<"\n";
    std::cout<<"Purchase price :"<<row[6]<<"\n";
    std::cout<<"Purchase status :"<<row[7]<<"\n";
    count++;
    }
}

void Purchases::received(){
    std::cout<<"\n";
    int count=1;
    std::cout<<"All the received purchases :"<<"\n";
    stat.str("");
    stat<<"select * from purchases where mark='R';";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);

    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"\n"<<"Purchase :"<<count<<"\n \n";
    std::cout<<"Purchase id :"<<row[0]<<"\n";
    std::cout<<"Supplier's id :"<<row[1]<<"\n";
    std::cout<<"Book's id :"<<row[2]<<"\n";
    std::cout<<"Purchase quantity :"<<row[3]<<"\n";
    std::cout<<"Order date :"<<row[4]<<"\n";
    std::cout<<"Receiving date :"<<row[5]<<"\n";
    std::cout<<"Purchase price :"<<row[6]<<"\n";
    std::cout<<"Purchase status :"<<row[7]<<"\n";
    count++;
    }
}

void Employees::add(){
    std::cout<<"\n";
    std::cout<<"Enter employees id :";
    std::cin>>id;
    cin.ignore();
    std::cout<<"Enter employees name :";
    getline(std::cin,name);
    std::cout<<"Enter employees phone number :";
    std::cin>>phone;
    std::cout<<"Enter employees salary :";
    std::cin>>salary;
    std::cout<<"Enter employees manager status in yes or no :";
    std::cin>>mng;
    cin.ignore();
    std::cout<<"Enter employees address :";
    getline(std::cin,addr);
    std::cout<<"Enter employees city :";
    getline(std::cin,city);

    stat.str("");
    stat<<"Insert into employee values("<<id<<",'"<<name<<"',"<<phone<<","<<salary<<",'"<<mng<<"','"<<addr<<"','"<<city<<"');";
    query=stat.str();
    a=query.c_str();
    int res=mysql_query(conn,a);
    if (res!=0){
            std::cout<<"Error!";
        }
    else{
            std::cout<<"Record added successfully!";
        }
    std::cout<<"\n";
}

void Employees::search(){
    std::cout<<"\n";
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
        std::cout<<"No record found...";
    }

}

void Employees::assign_mng(){
        std::cout<<"\n";
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
            string o=row[2];
            if (o!="yes"){

                char c;
                std::cout<<"The employee isn't a manager. Do you want to change the status? type y/n :";
                std::cin>>c;
                if (c=='y'){
                   stat.str("");
                   stat<<"Update employee set manager='yes' where e_id="<<id<<";";
                   query=stat.str();
                   a=query.c_str();
                   int res=mysql_query(conn,a);

                   if (res!=0){
                     std::cout<<"Error!";
                    }
                   else{
                     std::cout<<"Status changed successfully!";
                    }
                   std::cout<<"\n";
                }
            else{
               std::cout<<"Already a manager..\n";
               return;
            }
            }
        }
                
}

void Employees::view_all(){
    std::cout<<"\n";
    int count=1;
    stat.str("");
    stat<<"select * from employee;";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);

    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"Employee :"<<count<<"\n \n";
    std::cout<<"Employee's id :"<<row[0]<<"\n";
    std::cout<<"Employee's name :"<<row[1]<<"\n";
    std::cout<<"Employee's phone :"<<row[2]<<"\n";
    std::cout<<"Employee's salary :"<<row[3]<<"\n";
    std::cout<<"Employee's mangerial status :"<<row[4]<<"\n";
    std::cout<<"Employee's address :"<<row[5]<<"\n";
    std::cout<<"Employee's city :"<<row[6]<<"\n";
    count++;
    }
    std::cout<<"\n";
}

void Employees::up_sal(){
        std::cout<<"\n";
        std::cout<<"Enter employee id :";
        std::cin>>id;
        
        stat.str("");
        stat<<"select e_id,e_name,e_sal from employee where e_id="<<id<<";";
        query=stat.str();
        a=query.c_str();
        mysql_query(conn,a);
        result=mysql_store_result(conn);
        if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"Employee's id :"<<row[0]<<"\n";
            std::cout<<"Employee's name :"<<row[1]<<"\n";
            std::cout<<"Employee's salary :"<<row[2]<<"\n";
        }
        else{
            std::cout<<"No record found...";
            std::cout<<"\n";
            return;
        }
        
        char c;
        std::cout<<"Do you want to change the salary? type y/n :";
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
               std::cout<<"Error!";
            }
            else{
               std::cout<<"Salary updated successfully!";
            }
            std::cout<<"\n";
            }
        else{ 
            std::cout<<"\n";
            return;
        }
}

void Members::add(){
    std::cout<<"\n";
    std::cout<<"Enter Member id :";
    std::cin>>id;
    cin.ignore();
    std::cout<<"Enter Member name :";
    getline(std::cin,name);
    std::cout<<"Enter Member's phone number :";
    std::cin>>phone;
    std::cout<<"Enter Membership validity date in format 'YYYY-MM-DD' :";
    std::cin>>expiry;

    stat.str("");
    stat<<"Insert into members values("<<id<<",'"<<name<<"',"<<phone<<",'"<<expiry<<"','valid');";
    query=stat.str();
    a=query.c_str();
    int res=mysql_query(conn,a);
    if (res!=0){
            std::cout<<"Error!";
        }
    else{
            std::cout<<"Record added successfully!";
        }
    std::cout<<"\n";

}

void Members::search(){
    std::cout<<"\n";
    std::cout<<"Enter Member id to search :";
    std::cin>>id;

    stat.str("");
    stat<<"select * from members where m_id="<<id<<";";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    std::cout<<"\n";
    if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Member id :"<<row[0]<<"\n";
            std::cout<<"Member's name :"<<row[1]<<"\n";
            std::cout<<"Member's phone :"<<row[2]<<"\n";
            std::cout<<"Membership Expiry date :"<<row[3]<<"\n";
            std::cout<<"Membership validity :"<<row[4]<<"\n";

    }
    else{
        std::cout<<"No record found...";
    }
}

void Members::refresh(){

    stat.str("");
    stat<<"Update members set validity='invalid' where expiry_date<'"<<y<<"-"<<m<<"-"<<d<<"';";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
}


void Sales::add(){
    std::cout<<"\n";
    std::cout<<"Enter Sale id :";
    std::cin>>id;
    std::cout<<"Enter Member id :";
    std::cin>>mem_id;
    std::cout<<"Enter Book id :";
    std::cin>>book_id;
    std::cout<<"Enter Sale Quantity :";
    std::cin>>qty;
    std::cout<<"Enter Sale date in format 'YYYY-MM-DD' :";
    std::cin>>sale_date;
    std::cout<<"Enter Sale price :";
    std::cin>>price;

    stat.str("");
    stat<<"Insert into sales values("<<mem_id<<","<<book_id<<","<<qty<<",'"<<sale_date<<"',"<<id<<","<<price<<");";
    query=stat.str();
    a=query.c_str();
    int res=mysql_query(conn,a);
    if (res!=0){
            std::cout<<"Error!";
        }
    else{
            std::cout<<"Record added successfully!";
        }
    std::cout<<"\n";
}

void Sales::search(){
    std::cout<<"\n";
    std::cout<<"Enter Sale id to search :";
    std::cin>>id;

    stat.str("");
    stat<<"select * from sales where s_id="<<id<<";";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);
    std::cout<<"\n";
    if ((row=mysql_fetch_row(result)) !=NULL){
            std::cout<<"\n";
            std::cout<<"Sale id :"<<row[4]<<"\n";
            std::cout<<"Member id :"<<row[0]<<"\n";
            std::cout<<"Book id :"<<row[1]<<"\n";
            std::cout<<"Sale quantity :"<<row[2]<<"\n";
            std::cout<<"Sale date :"<<row[3]<<"\n";
            std::cout<<"Sale price :"<<row[5]<<"\n";

    }
    else{
        std::cout<<"No record found...";
        std::cout<<"\n";
    }
}

void Sales::total(){
    std::cout<<"\n";
    int count=1;
    stat.str("");
    stat<<"select * from sales;";
    query=stat.str();
    a=query.c_str();
    mysql_query(conn,a);
    result=mysql_store_result(conn);

    while ((row=mysql_fetch_row(result)) !=NULL){
    std::cout<<"\n"<<"Sale :"<<count<<"\n \n";
    std::cout<<"Sale id :"<<row[4]<<"\n";
    std::cout<<"Member id :"<<row[0]<<"\n";
    std::cout<<"Book id :"<<row[1]<<"\n";
    std::cout<<"Sale quantity :"<<row[2]<<"\n";
    std::cout<<"Sale date :"<<row[3]<<"\n";
    std::cout<<"Sale price :"<<row[5]<<"\n";
    count++;
    }
    std::cout<<"\n";
}


/*--FUNCTION DECLARATION--*/

void book_menu();
void sup_menu();
void pur_menu();
void emp_menu();
void mem_menu();
void sales_menu();


/*--MAIN FUNCTION--*/

int main(){
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "12345678", "rough", 0, NULL, 0);
    
    if(conn){
        std::cout << "Connection Established...\n" << endl;
    } else {
        std::cout << "Not connected...\n" << endl;
    }

    /*--START--*/

   std::cout<<"\n\n--WELCOME TO THE LIBRARY!--\n\n";

    string ans="yes";
    while (ans=="yes"){
        int c;
        std::cout<<" Please select an option from the given list by typing the number:\
           \n\n 1. Books\n 2. Suppliers\n 3. Purchases\n 4. Employees\n 5. Members\n 6. Sales\n 7. Exit"<<"\n\n";
        
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
    std::cout<<"\n";
    }
   return 0;
}

/*--FUNCTIONS FOR MENUS OF DIFFERENT CATEGORIES--*/

void book_menu(){
    Book b;
    int c;
    std::cout<<"--BOOKS MENU--\
    \n\n 1. Add\n 2. Update Price\n 3. Search\n 4. Display All\n 5. Return to Main Menu\n\n";
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
    \n\n 1. Add\n 2. Remove\n 3. Search\n 4. Return to Main Menu\n\n";
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
    Purchases p;
    int c;
    std::cout<<"--PURCHASES MENU--\
    \n\n 1. New Order\n 2. Cancel Order\n 3. Mark Recieved\n 4. View All\n 5. Received Orders\n 6. Return to Main Menu\n\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            p.add();
            break;
            
            case 2:
            p.cancel();
            break;
       
            case 3:
            p.mark_R();
            break;
            
            case 4:
            p.view_all();
            break;

            case 5:
            p.received();
            break;
            
            case 6:
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
    \n\n 1. New Employee\n 2. Search Employee\n 3. Assign Manager\n 4. View All\n 5. Update Salary\n 6. Return to Main Menu\n\n";
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
    Members m;
    int c;
    m.refresh();
    std::cout<<"--MEMBERS MENU--\
    \n\n 1. New Member\n 2. Search Member\n 3. Return to Main Menu\n\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            m.add();
            break;
            
            case 2:
            m.search();
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
    Sales s;
    int c;
    std::cout<<"--SALES MENU--\
    \n\n 1. New Receipt\n 2. Search Sale\n 3. Total Sales\n 4. Return to Main Menu\n\n";
    std::cout<<"Select an option :";
    std::cin>>c;

    switch(c){
            case 1:
            s.add();
            break;
            
            case 2:
            s.search();
            break;
            
            case 3:
            s.total();
            break;
       
            case 4:
            return;

            default:
            std::cout<<"Invalid Input";
            break;
       
        }    
    return;
}
