#include <iostream>
#include "admin.cpp"
using namespace std;

int main(){
  Admin adm("admin", "12345");
    string userInput, passInput;
    cout << "=== PORTAL MAHASISWA ===" << endl;
    cout << "Masukkan username: ";
    cin >> userInput;
    cout << "Masukkan password: ";
    cin >> passInput;

    if (adm.login(userInput, passInput)) {
        adm.showAdminMenu();
    }
  return 0;
}