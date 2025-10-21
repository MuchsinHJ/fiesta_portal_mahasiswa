#include <iostream>
#include <string>
#define MAX_MHS 1000
using namespace std;

struct AdminData {
    string username;
    string password;
    
};

struct Mahasiswa {
    string nama;
    string nim;
};

class AdminPortal {
private:
    AdminData admin;
    bool statusLogin;
    Mahasiswa* mhs = new Mahasiswa[MAX_MHS];
    int jumlahMhs = 0;
public:
    AdminPortal(string user, string pass) {
        admin.username = user;
        admin.password = pass;
        statusLogin = false;
    }

    void inputdataMahasiswa(){
        cout<<"===INPUT DATA MAHASISWA==="<<endl;
        cout << "Masukkan jumlah mahasiswa yang akan ditambahkan: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout<<"Data Mahasiswa ke-"<<(jumlahMhs+1)<<":"<<endl;
            cout<<"Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, mhs[jumlahMhs].nama);
            cout<<"Masukkan NIM Mahasiswa: ";
            cin>>mhs[jumlahMhs].nim;
            jumlahMhs++;
        }
        
    }

    void dataMahasiswa(){
        cout<<"===DATA MAHASISWA==="<<endl;
        for (int i = 0; i < jumlahMhs; i++) {
            cout << "Mahasiswa ke-" << (i + 1) << ":" << endl;
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "NIM: " << mhs[i].nim << endl;
        }
    }

    // void tahunMahasiswa(){
    //     cout<<"===PILIH TAHUN ANGKATAN=== "<<endl;
    //     cout<<"1. 2020"<<endl;
    //     cout<<"2. 2021"<<endl;
    //     cout<<"3. 2022"<<endl;
    //     cout<<"4. 2023"<<endl;
    //     cout<<"5. 2024"<<endl;
    //     cout<<"6. 2025"<<endl;

    //     int pilihan;
    //     cout<<"Masukkan Pilihan Tahun Angkatan: ";
    //     cin>>pilihan;
    // }

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
                    inputdataMahasiswa();
                    break;
                case 2:
                    dataMahasiswa();
                    break;
                case 3:
                    cout << "Logout berhasil.\n";
                    statusLogin = false;
                    delete[] mhs;
                    break;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        } while (statusLogin);
    }
};

