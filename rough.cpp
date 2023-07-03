#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;
int main(){

    int id,phone;
    string name,addr,city,state;
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
}