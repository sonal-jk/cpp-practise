#pragma once
#include <iostream>
using namespace std;
void book_menu(){
  
    int c;
    std::cout<<"Select one option\
    \n 1. Add\n 2. Update Price\n 3.Search\n 4. Display All\n 5. Return to Main Menu\n";
    std::cout<<"Your answer :";
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