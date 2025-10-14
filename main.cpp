#include <iostream>
#include "admin.cpp"
using namespace std;

int main(){
  AdminPortal admin("admin", "12345");

    string userInput, passInput;
    cout << "=== PORTAL MAHASISWA ===" << endl;
    cout << "Masukkan username: ";
    cin >> userInput;
    cout << "Masukkan password: ";
    cin >> passInput;

    if (admin.login(userInput, passInput)) {
        admin.showAdminMenu();
    }
  return 0;
}