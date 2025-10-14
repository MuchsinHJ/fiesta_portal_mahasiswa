#include <iostream>
#include <string>
using namespace std;

struct AdminData {
    string username;
    string password;
};

struct Penerbangan {
    string kode;
    string tujuan;
    string waktu;
};

class Admin {
private:
    AdminData admin;
    bool statusLogin;

    // Array statis untuk data penerbangan
    static const int MAX_PENERBANGAN = 10;
    Penerbangan daftarPenerbangan[MAX_PENERBANGAN];
    int jumlahPenerbangan;

public:
    Admin(string user, string pass) {
        admin.username = user;
        admin.password = pass;
        statusLogin = false;
        jumlahPenerbangan = 0;
    }

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

    void tambahPenerbangan() {
        if (jumlahPenerbangan >= MAX_PENERBANGAN) {
            cout << "Data penerbangan penuh!\n";
            return;
        }
        cout << "Masukkan kode penerbangan: ";
        cin >> daftarPenerbangan[jumlahPenerbangan].kode;
        cout << "Masukkan tujuan: ";
        cin >> daftarPenerbangan[jumlahPenerbangan].tujuan;
        cout << "Masukkan waktu: ";
        cin >> daftarPenerbangan[jumlahPenerbangan].waktu;
        jumlahPenerbangan++;
        cout << "Data penerbangan berhasil ditambahkan.\n";
    }

    void lihatJadwalPenerbangan() {
        if (jumlahPenerbangan == 0) {
            cout << "Belum ada data penerbangan.\n";
            return;
        }
        cout << "\nJadwal Penerbangan:\n";
        for (int i = 0; i < jumlahPenerbangan; ++i) {
            cout << i + 1 << ". Kode: " << daftarPenerbangan[i].kode
                 << ", Tujuan: " << daftarPenerbangan[i].tujuan
                 << ", Waktu: " << daftarPenerbangan[i].waktu << endl;
        }
    }

    void showAdminMenu() {
        if (!statusLogin) {
            cout << "Silakan login terlebih dahulu.\n";
            return;
        }

        int pilihan;
        do {
            cout << "\n=== MENU ADMIN BANDARA ===" << endl;
            cout << "1. Tambah Data Penerbangan" << endl;
            cout << "2. Lihat Jadwal Penerbangan" << endl;
            cout << "3. Logout" << endl;
            cout << "Pilih: ";
            cin >> pilihan;

            switch (pilihan) {
            case 1:
                tambahPenerbangan();
                break;
            case 2:
                lihatJadwalPenerbangan();
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
