/*BOOKSTORE MANAGEMENT SYSTEM*/


#include <iostream>
#include "windows.h"
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>
#include <conio.h>
#include "functions.cpp"
#include "classes.h"
using namespace std;

/*CLASSES*/


void menu(){
     std::cout<<"WELCOME TO THE BOOKSTORE!";

    string ans="yes";
    while (ans=="yes"){
        int c;
        std::cout<<" Please select an option from the given list by typing the number:\
           \n 1. Books\n 2. Suppliers\n 3. Purchases\n 4. Employees\n 5. Members\n 6. Sales\n 7. Exit"<<"\n";
        
        std::cout<<"Select one option :";
        std::cin>>c;
        switch(c){
            case 1:
            book_menu();
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
            std::cout<<"E";
            break;
                   
            case 6:
            std::cout<<"F";
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
}

int main(){
    /*
    MYSQL* conn=NULL;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "12345678", "rough", 0, NULL, 0);

    if(conn){
        std::cout << "Connected" << endl;
    } else {
        std::cout << "Not connected" << endl;
    }
    int res=mysql_query(conn,"Insert into stud values(3)");
    if (res!=0){
        std::cout<<"error";
    }
    else{
        std::cout<<"success";
    }
*/
    /*START*/

   menu();
    return 0;
}

/*FUNCTIONS FOR MENUS OF DIFFERENT CATEGORIES*/
