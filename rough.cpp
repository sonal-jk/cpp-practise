#include <iostream>
#include <ctime>
int main(){
    time_t t=time(0);
    std::cout<<t<<"\n";
    tm *t1=localtime(&t);
        std::cout<<1900+t1->tm_year<<"\n";
        std::cout<<1+t1->tm_mon<<"\n";
        std::cout<<t1->tm_mday<<"\n";

}