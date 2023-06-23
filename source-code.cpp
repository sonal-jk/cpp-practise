/*---BOOKSTORE MANAGEMENT SYSTEM---*/


#include <iostream>
#include "windows.h"
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>
#include "classes.h"
#include <conio.h>

using namespace std;
MYSQL* conn=NULL;


/*CLASSES*/
    void Book::add(){
        std::cout<<"Enter book id :";
        std::cin>>id;
        std::cout<<"/n";
        std::cout<<"Enter book's name :";
        std::cin>>name;
        std::cout<<"/n";
        std::cout<<"Enter author's name :";
        std::cin>>author;
        std::cout<<"/n";
        std::cout<<"Enter quantity of books :";
        std::cin>>qty;
        std::cout<<"/n";
        std::cout<<"Enter book's price :";
        std::cin>>price;
        std::cout<<"/n";
        /*string stat="Insert into books values" + "(" + ")";
        int res=mysql_query(conn,stat);
*/
    }


/*FUNCTION DECLARATION*/

void book_menu();
void sup_menu();
void pur_menu();
void emp_menu();
void mem_menu();
void sales_menu();



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
  
    int c;
    std::cout<<"--BOOKS MENU--\
    \n 1. Add\n 2. Update Price\n 3. Search\n 4. Display All\n 5. Return to Main Menu\n";
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

void sup_menu(){
  
    int c;
    std::cout<<"--SUPPLIERS MENU--\
    \n 1. Add\n 2. Remove\n 3. Search\n 4. Return to Main Menu\n";
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
            std::cout<<"D";
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
