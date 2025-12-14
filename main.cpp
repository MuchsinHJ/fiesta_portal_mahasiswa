#include "mahasiswa.cpp"
using namespace std;

// class history nav
class NavigationStack {
private:
    string history[20];
    int top;

public:
    NavigationStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 19; }

    void push(string page) {
        if (isFull()) return;
        history[++top] = page;
    }

    void pop() {
        if (!isEmpty()) top--;
    }

    string current() {
        if (isEmpty()) return "None";
        return history[top];
    }
};




// === Class untuk menu utama admin ===
class AdminDashboard {
private:
    NavigationStack nav;
    ManajemenMahasiswa mnjMhs;
    ManajemenDosen mnjDosen;
    ManajemenMatakuliah mnjMatkul;
    ManajemenDosenMataKuliah mnjdsmatkul;
    ManajemenKelas mnjKelas;
    ManajemenKelasMahasiswa mnjKelasMahasiswa;
    ManajemenKrs mnjKrs;
public:

    void tarikData(){
        mnjMhs.tarikMahasiswadarifile();
        mnjDosen.tarikDosenFile();
        mnjMatkul.tarikDataDariFileMataKuliah();
        mnjdsmatkul.tarikDataDariFileDosenMataKuliah();
        mnjKelas.tarikDataDariFileKelas();
        mnjKelasMahasiswa.tarikDataDariFileKelasMahasiswa();
        mnjKrs.tarikDataDariFileKrs();
    }

    void tampilMenuDashAdmin() {
        nav.push("Dashboard Admin");
        tarikData();
        
        int pilih;
        do {
            cout << "\n=== DASHBOARD ADMIN ===" << endl;
            cout << "1. Manajemen Mahasiswa" << endl;
            cout << "2. Manajemen Dosen" << endl;
            cout << "3. Manajemen Mata Kuliah" << endl;
            cout << "4. Manajemen Dosen Mata Kuliah" << endl;
            cout << "5. Manajemen Kelas" << endl;
            cout << "6. Manajemen Kelas Mahasiswa" << endl;
            cout << "7. Validasi KRS" << endl;
            cout << "8. Input dan Koreksi Nilai" << endl;
            cout << "9. Verifikasi Pembayaran" << endl;
            cout << "10. Layanan Akademik" << endl;
            cout << "11. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;
            switch (pilih) {
                case 1: 
                    tampilMenuMhs(); 
                    break;

                case 2: 
                    tampilMenuDosen();
                    break;

                case 3:
                    tampilMenuMatakuliah();
                    break; 
                case 4:
                    tampilMenuDosenMataKuliah();
                    break;
                case 5:
                    tampilMenuKelas();
                    break;
                case 6:
                    tampilMenuKelasMahasiswa();
                    break;
                case 7:
                    tampilMenuKrs();
                    break;
                case 10: 
                    nav.pop();
                    cout << "Keluar dari dashboard admin...\n";
                    break;
                default: cout << "Pilihan tidak valid!\n";
                    break;
            }
        } while (pilih != 10);
    }

    void tampilMenuDosen() {
        nav.push("Dashboard Manajemen Dosen");
        int pilih;
        do {
            cout << "\n=== DASHBOARD MANAJEMEN DOSEN ===" << endl;
            cout << "1. Tambah Dosen" << endl;
            cout << "2. Lihat Dosen" << endl;
            cout << "3. Edit data Dosen" << endl;
            cout << "4. Hapus Dosen" << endl;
            cout << "5. Cek Keaktifan Dosen" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: mnjDosen.tambahDosen(); 
                break;
                case 2: mnjDosen.tampilDosen();
                break;
                case 3: mnjDosen.editDosen();
                break;
                case 4: mnjDosen.hapusDosen(); 
                break;
                case 5: mnjDosen.cekKeaktifanDosen();
                break;
                case 6:
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n";
                    return;  
                break;
                default: cout << "Pilihan tidak valid!\n";
                break;
            }
        } while (pilih != 6);
    }

    void tampilMenuMhs() {
        nav.push("Dashboard Manajemen Mahasiswa");
        int pilih;
        do {
            cout << "\n=== DASHBOARD MANAJEMEN MAHASISWA ===" << endl;
            cout << "1. Tambah Mahasiswa" << endl;
            cout << "2. Lihat Mahasiswa" << endl;
            cout << "3. Edit data Mahasiswa" << endl;
            cout << "4. Hapus Mahasiswa" << endl;
            cout << "5. Cek Keaktifan Mahasiswa" << endl;
            cout << "6. Keluar" << endl;
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
                case 5: mnjMhs.cekKeaktifanMahasiswa();
                break;
                case 6: 
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n"; 
                    return;
                default: cout << "Pilihan tidak valid!\n"; 
                break;
            }
        } while (pilih != 6);
    }

    void tampilMenuMatakuliah() {
        nav.push("Dashboard Manajemen Mata Kuliah");
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
                    nav.pop();
                    cout<<"Kembalikan ke dashboard admin...\n";
                    return;
                default:
                    cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
        }while(pilih!=6);
        
    }

    void tampilMenuDosenMataKuliah() {
        nav.push("Dashboard Manajemen Dosen Mata Kuliah");
        int pilih;
        do {
            cout << "\n==== MENU MANAJEMEN DOSEN MATA KULIAH ====" << endl;
            cout << "1. Tambah Dosen Mata Kuliah" << endl;
            cout << "2. Lihat Semua Dosen Mata Kuliah" << endl;
            cout << "3. Cari Dosen Mata Kuliah" << endl;
            cout << "4. Edit Dosen Mata Kuliah" << endl;
            cout << "5. Hapus Dosen Mata Kuliah" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;
            
            switch(pilih) {
                case 1:
                    mnjdsmatkul.tambahDosenMataKuliah();
                    break;
                case 2:
                    mnjdsmatkul.tampilSemuaDosenMataKuliah();
                    break;
                case 3:
                    mnjdsmatkul.cariDosenMataKuliah();
                    break;
                case 4:
                    mnjdsmatkul.editDosenMataKuliah();
                    break;
                case 5:
                    mnjdsmatkul.hapusDosenMataKuliah();
                    break;
                case 6:
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n";
                    return;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (pilih != 6);
    }

    void tampilMenuKelas() {
        nav.push("Dashboard Manajemen Kelas");
        int pilih;
        do {
            cout << "1. Tambah Kelas" << endl;
            cout << "2. Lihat Semua Kelas" << endl;
            cout << "3. Edit Kelas" << endl;
            cout << "4. Hapus Kelas" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    mnjKelas.tambahKelas();
                    break;
                case 2:
                    mnjKelas.tampilSemuaKelas();
                    break;
                case 3:
                    mnjKelas.editKelas();
                    break;
                case 4:
                    mnjKelas.hapusKelas();
                    break;
                case 5:
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n";
                    return;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
            }
        } while (pilih != 6);
    }

    void tampilMenuKelasMahasiswa() {
        nav.push("Dashboard Manajemen Kelas Mahasiswa");
        int pilih;
        do {
            cout << "1. Tambah Kelas Mahasiswa" << endl;
            cout << "2. Lihat Semua Kelas Mahasiswa" << endl;
            cout << "3. Edit Kelas Mahasiswa" << endl;
            cout << "4. Hapus Kelas Mahasiswa" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                    //  mnjKrs.tambahKrsMahasiswa();
                    break;
                case 2:
                    //  mnjKrs.tampilSemuaKKrs();
                    break;
                case 3:
                    // mnjKelasMahasiswa.editKelasMahasiswa();
                    break;
                case 4:
                    // mnjKelasMahasiswa.hapusKelasMahasiswa();
                    break;
                case 5:
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n";
                    return;
                    default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
                }
            } while (pilih != 5);
        }

        void tampilMenuKrs(){
            nav.push("Dashboard Manajemen KRS");
            int pilih;
            do {
                cout << "1. Tambah krs mahasiswa" << endl;
                cout << "2. Lihat Semua krs berdasarkan kelas dan semester" << endl;
                cout << "3. Edit krs mahasiswa" << endl;
                cout << "4. Hapus krs mahasiswa" << endl;
                cout << "5. Keluar" << endl;
                cout << "Pilih: ";
                cin >> pilih;

                switch(pilih) {
                    case 1:
                        // mnjKrs.tambahKrs();
                        break;
                    case 2:
                        mnjKrs.tampilKrsByKelas();
                        break;
                    case 3:
                        // mnjKrs.editKrsMahasiswa();
                        break;
                    case 4:
                        // mnjKrs.hapusKrsMahasiswa();
                        break;
                    case 5:
                        nav.pop();
                        cout << "Kembalikan ke dashboard admin...\n";
                        return;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                }
            } while (pilih != 5);
        }
    };
    
    
class MahasiswaDashboard {
private:
    NavigationStack nav;
    KRSKHS* krs;
    MahasiswaPortal* mhsPortal;
    ManajemenMatakuliah* mk;
    ManajemenDosenMataKuliah* dmk;
    ManajemenKelas* kls;
public:
    MahasiswaDashboard(MahasiswaPortal* portal) : mhsPortal(portal) {
        // Inisialisasi KRS dengan objek manajemen yang diperlukan
        mk = new ManajemenMatakuliah();
        mk->tarikDataDariFileMataKuliah();
        
        dmk = new ManajemenDosenMataKuliah();
        dmk->tarikDataDariFileDosenMataKuliah();
        
        kls = new ManajemenKelas();
        // ManajemenKelas sudah load data di constructor
        
        krs = new KRSKHS(mk, dmk, kls);
        krs->bacaKRSdariFile();
    }

    void tampilMenuDashMahasiswa() {
        nav.push("Dashboard Mahasiswa");
        int pilih;
        do {
            cout << "\n=== DASHBOARD MAHASISWA ===" << endl;
            cout << "1. Profile" << endl;
            cout << "2. Perkuliahan" << endl;
            cout << "3. KRS dan KHS" << endl;
            cout << "4. Mata Kuliah" << endl;
            cout << "5. Logout" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1:
                 tampilProfil();
                    break;
                case 2:
                tampilPerkuliahan();
                    break;
                case 3:
                tampilKRSKHS();
                    break;
                case 4: 
                tampilMataKuliah();
                    break;
                case 5:
                mhsPortal->logout();
                nav.pop(); 
                cout << "Keluar dari dashboard mahasiswa...\n";
                return;
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
                    break;
            }
        } while (pilih != 5);
    }

    


    void tampilProfil(){
        nav.push("Tampil Menu Profil Mahasiswa");
        int pilih;
        do{
            cout<<"====MENU MANAJEMEN PROFIL MAHASISWA===="<<endl;
            cout<<"1. Biodata"<<endl;
            cout<<"2. Tagihan"<<endl;
            cout<<"3. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                    mhsPortal->tampilProfil();
                    break;
                case 2:
                    mhsPortal->Tagihanmhs();
                    break;
                case 3:
                    nav.pop();
                    cout<<"Kembalikan ke dashboard mahasiswa...\n";
                    return;
                default:
                    cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
        }while(pilih!=3);
    }


    void tampilPerkuliahan(){
        nav.push("Tampil Menu Perkuliahan Mahasiswa");
        int pilih;
        do{
            cout<<"====MENU MANAJEMEN PERKULIAHAN MAHASISWA===="<<endl;
            cout<<"1. Mata Kuliah Aktif"<<endl;
            cout<<"2. Sertifikat Seminar"<<endl;
            cout<<"3. Sertifikat Prestasi"<<endl;
            cout<<"4. Presensi Kuliah"<<endl;
            cout<<"5. Informasi"<<endl;
            cout<<"6. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                    cout << "Menampilkan biodata..." << endl;
                    break;
                case 2:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 3:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 4:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 5:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 6:
                    nav.pop();
                    cout<<"Kembalikan ke dashboard mahasiswa...\n";
                    return;
                default:
                    cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
        }while(pilih!=6);
    }

    void tampilKRSKHS(){
        nav.push("Tampil Menu KRS dan KHS Mahasiswa");
        int pilih;
        do{
            cout<<"====MENU MANAJEMEN PERKULIAHAN MAHASISWA===="<<endl;
            cout<<"1. KRS Reguler"<<endl;
            cout<<"2. KRS Aktivitas Mahasiswa"<<endl;
            cout<<"3. Cetak KRS"<<endl;
            cout<<"4. Cek Nilai"<<endl;
            cout<<"5. Pendaftaran Seminar"<<endl;
            cout<<"6. Pendaftaran Ujian"<<endl;
            cout<<"7. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                    krs->menuKRS(mhsPortal->getNIMMahasiswa(), mhsPortal->getSemesterMahasiswa());
                    system("pause");
                    break;
                case 2:
                    cout << "Menampilkan KRS Aktivitas Mahasiswa..." << endl;
                    system("pause");
                    break;
                case 3:
                    krs->cetakKRS(mhsPortal->getNIMMahasiswa());
                    system("pause");
                    break;
                case 4:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 5:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 6:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 7:
                    nav.pop();
                    cout<<"Kembalikan ke dashboard mahasiswa...\n";
                    return;
                default:
                    cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
        }while(pilih!=7);
    }

    void tampilMataKuliah(){
        nav.push("Tampil Menu Perkuliahan Mahasiswa");
        int pilih;
        do{
            cout<<"====MENU MANAJEMEN PERKULIAHAN MAHASISWA===="<<endl;
            cout<<"1. Mata Kuliah Semester Gasal"<<endl;
            cout<<"2. Mata Kuliah Semester Genap"<<endl;
            cout<<"3. Seluruh Mahasiswa"<<endl;
            cout<<"4. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                    cout << "Menampilkan biodata..." << endl;
                    break;
                case 2:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 3:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 4:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 5:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 6:
                    cout << "Menampilkan tagihan..." << endl;
                    break;
                case 7:
                    nav.pop();
                    cout<<"Kembalikan ke dashboard mahasiswa...\n";
                    return;
                default:
                    cout<<"Pilihan tidak valid!"<<endl;
                break;
            }
        }while(pilih!=4);
    }

    
};





void displayAdmin(){
    AdminPortal portal("admin", "123");
    string u, p;
    int pilihan;
    bool kondisi = false;
    do{
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    if (portal.login(u, p)) {
        kondisi = true;
        AdminDashboard dashboard;
        dashboard.tampilMenuDashAdmin();
    }else{
        cout << "Login gagal! Silakan coba lagi.\n";
        cout << "1. Coba lagi\n2. Keluar\nPilih: ";
        cin >> pilihan;
        if(pilihan==2){
            kondisi = true;
            return;
        }
    }
    }while(!kondisi);
}

void displayMahasiswa(){
    MahasiswaPortal portal(new DataMahasiswa());
    string u, p;
    bool kondisi = false;
    int pilihan;
    do
    {
        cout << "NIM: "; cin >> u;
        cout << "Password: "; cin >> p;
        bool loggedIn = portal.login(u, p);
        if (loggedIn) {
            kondisi = true;
            MahasiswaDashboard dashboard(&portal);
            dashboard.tampilMenuDashMahasiswa();
        }else{
            cout << "Login gagal! Silakan coba lagi.\n";
            cout << "1. Coba lagi\n2. Keluar\nPilih: ";
            cin >> pilihan;
            if(pilihan==2){
                kondisi = true;
                return;
            }
        }
    } while (!kondisi);
}

void displayMainMenu(){
    int pilih;
    cout << "=== SISTEM INFORMASI AKADEMIK ===" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai Mahasiswa" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih: ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            displayAdmin();
            break;
        case 2:
            displayMahasiswa();
            break;
        case 3:
            cout << "Keluar dari sistem...\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            displayMainMenu();
            break;
    }
}

int main(){
    displayMainMenu();
    return 0;
}