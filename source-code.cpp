#include <iostream>
#include <windows.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

#include <conio.h>
using namespace std;
int main(){
    MYSQL* conn=NULL;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "12345678", "rough", 0, NULL, 0);

    if(conn){
        cout << "Connected" << endl;
    } else {
        cout << "Not connected" << endl;
    }
}
