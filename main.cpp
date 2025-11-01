#include "admin.cpp"
using namespace std;

// === Class untuk menu utama admin ===
class AdminDashboard {
private:
    ManajemenMahasiswa mnjMhs;
    ManajemenDosen mnjDosen;
    ManajemenMatakuliah mnjMatkul;
public:
    void tampilMenuDash() {
        mnjMhs.tarikMahasiswadarifile();
        int pilih;
        do {
            cout << "\n=== DASHBOARD ADMIN ===" << endl;
            cout << "1. Manajemen Mahasiswa" << endl;
            cout << "2. Manajemen Dosen" << endl;
            cout << "3. Manajemen Mata Kuliah" << endl;
            cout << "4. Manajemen Kelas" << endl;
            cout << "5. Validasi KRS" << endl;
            cout << "6. Input dan Koreksi Nilai" << endl;
            cout << "7. Verifikasi Pembayaran" << endl;
            cout << "8. Layanan Akademik" << endl;
            cout << "9. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;
            switch (pilih) {
                case 1: 
                    tampilMenuMnj(); 
                    break;

                case 2: 
                    tampilMenuDosen();
                    break;

                case 3:
                    tampilMenuMatakuliah();
                    break; 
                case 9: 
                    cout << "Keluar dari dashboard admin...\n";
                    break;
                default: cout << "Pilihan tidak valid!\n";
                    break;
            }
        } while (pilih != 9);
    }

    void tampilMenuDosen() {
        int pilih;
        do {
            cout << "\n=== DASHBOARD MANAJEMEN DOSEN ===" << endl;
            cout << "1. Tambah Dosen" << endl;
            cout << "2. Lihat Dosen" << endl;
            cout << "3. Edit data Dosen" << endl;
            cout << "4. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: mnjDosen.tambahDosen(); 
                break;
                case 2: mnjDosen.tampilDosen();
                break;
                case 3: mnjDosen.editDosen();
                break;
                case 4: cout << "Keluar dari dashboard manajemen dosen...\n"; 
                break;
                default: cout << "Pilihan tidak valid!\n";
                break;
            }
        } while (pilih != 4);
    }

    void tampilMenuMnj() {
        int pilih;
        do {
            cout << "\n=== DASHBOARD MANAJEMEN MAHASISWA ===" << endl;
            cout << "1. Tambah Mahasiswa" << endl;
            cout << "2. Lihat Mahasiswa" << endl;
            cout << "3. Edit data Mahasiswa" << endl;
            cout << "4. Hapus Mahasiswa" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: mnjMhs.tambahMahasiswa(); 
                break;
                case 2: mnjMhs.tampilMahasiswa(); 
                break;
                case 3: mnjMhs.editMahasiswa(); 
                break;
                case 4: mnjMhs.hapusMahasiswa();
                break;
                case 5: cout << "Keluar dari dashboard manajemen mahasiswa...\n"; 
                break;
                default: cout << "Pilihan tidak valid!\n"; 
                break;
            }
        } while (pilih != 5);
    }

    void tampilMenuMatakuliah() {


        int pilih;

        do{
            cout<<"====MENU MANAJEMEN MATAKULIAH===="<<endl;
            cout<<"1. Tambah Mata Kuliah"<<endl;
            cout<<"2. Lihat Mata Kuliah per Semester"<<endl;
            cout<<"3. Lihat Semua Mata Kuliah"<<endl;
            cout<<"4. Edit Mata Kuliah"<<endl;
            cout<<"5. Hapus Mata Kuliah"<<endl;
            cout<<"6. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                    mnjMatkul.tambahMataKuliah();
                    break;
                case 2:
                    mnjMatkul.tampilMataKuliahPerSemester();
                    break;
                case 3:
                    mnjMatkul.tampilSemuaMataKuliah();
                    break;
                case 4:
                    mnjMatkul.editMataKuliah();
                    break;
                case 5:
                    mnjMatkul.hapusMataKuliah();
                    break;
                case 6:
                    cout<<"Keluar dari menu manajemen mata kuliah..."<<endl;
                    break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
                break;
         }
        }while(pilih!=6);
        
}
};

void displayAdmin(){
  AdminPortal portal("admin", "123");
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;

    if (portal.login(u, p)) {
        AdminDashboard dashboard;
        dashboard.tampilMenuDash();
    }
}

int main(){
  displayAdmin();
  return 0;
}