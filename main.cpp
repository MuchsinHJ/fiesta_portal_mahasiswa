#include "admin.cpp"
using namespace std;

void displayAdmin(){
  AdminPortal portal("admin", "123");
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;

    if (portal.login(u, p)) {
        AdminDashboard dashboard;
        dashboard.tampilMenuMnj();
    }
}

int main(){
  displayAdmin();
  return 0;
}