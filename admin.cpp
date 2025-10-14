#include <iostream>
#include <string>
using namespace std;

struct AdminData {
    string username;
    string password;
};

class AdminPortal {
private:
    AdminData admin;
    bool statusLogin;

public:
    AdminPortal(string user, string pass) {
        admin.username = user;
        admin.password = pass;
        statusLogin = false;
    }

    // Fungsi login
    bool login(string inputUser, string inputPass) {
        if (inputUser == admin.username && inputPass == admin.password) {
            statusLogin = true;
            cout << "Login berhasil! Selamat datang, " << admin.username << endl;
        } else {
            cout << "Username atau password salah!" << endl;
            statusLogin = false;
        }
        return statusLogin;
    }

    void showAdminMenu() {
        if (!statusLogin) {
            cout << "Silakan login terlebih dahulu.\n";
            return;
        }

        int pilihan;
        do {
            cout << "\n=== MENU ADMIN ===" << endl;
            cout << "1. Tambah Data Mahasiswa" << endl;
            cout << "2. Lihat Data Mahasiswa" << endl;
            cout << "3. Logout" << endl;
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    cout << "Fitur tambah data mahasiswa (belum diimplementasikan)\n";
                    break;
                case 2:
                    cout << "Fitur lihat data mahasiswa (belum diimplementasikan)\n";
                    break;
                case 3:
                    cout << "Logout berhasil.\n";
                    statusLogin = false;
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        } while (statusLogin);
    }
};

