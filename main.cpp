#include "mahasiswa.cpp"
using namespace std;

// class history nav
class NavigationStack {
private:
    string history[20];
    int top;

public:
    NavigationStack() { top = -1; }
    bool logoutRequested = false; // flag untuk meminta logout ke menu login

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
    AdminPortal* admin;
    ManajemenMahasiswa mnjMhs;
    ManajemenDosen mnjDosen;
    ManajemenMatakuliah mnjMatkul;
    ManajemenDosenMataKuliah mnjdsmatkul;
    ManajemenKelas mnjKelas;
    ManajemenKelasMahasiswa mnjKelasMahasiswa;
    ManajemenKrs mnjKrs;
    ManajemenInputDanKoreksiNilai mnjik;
public:
    
    void setAdminPortal(AdminPortal* adminPortal) {
        admin = adminPortal;
    }

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
            cout<<endl;
            cout<<"==============================================" << endl;
            cout<<"           ==== DASHBOARD ADMIN ====          " << endl;
            cout<<"==============================================" << endl;
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
            cout << "0. Logout" << endl;
            cout << "Pilih: ";
            cin >> pilih;
            switch (pilih) {
                case 1:
                    system("cls"); 
                    tampilMenuMhs(); 
                    break;

                case 2:
                    system("cls"); 
                    tampilMenuDosen();
                    break;

                case 3:
                    system("cls");
                    tampilMenuMatakuliah();
                    break; 
                case 4:
                    system("cls");
                    tampilMenuDosenMataKuliah();
                    break;
                case 5:
                    system("cls");
                    tampilMenuKelas();
                    break;
                case 6:
                    system("cls");
                    tampilMenuKelasMahasiswa();
                    break;
                case 7:
                    system("cls");
                    tampilMenuKrs();
                    break;
                case 8:
                    system("cls");
                    menuInputDanKoreksiNilai();
                    break;
                case 10:
                    
                    cout << "(Fitur Layanan Akademik belum tersedia)\n";
                    break;
                case 0: 
                    system("cls");
                        admin->logoutnih();
                    
                    system("cls");
                    nav.pop();
                    cout << "Logout admin...\n";
                    return;
                default: cout << "Pilihan tidak valid!\n";
                    break;
            }
        } while (true);
    }

    void tampilMenuDosen() {
        nav.push("Dashboard Manajemen Dosen");
        int pilih;
        do {
            cout<<endl;
            cout<<"==============================================" << endl;
            cout<<"      ==== DASHBOARD MANAJEMEN DOSEN ====  " << endl;
            cout<<"==============================================" << endl;
            cout << "\n=== DASHBOARD MANAJEMEN DOSEN ===" << endl;
            cout << "1. Tambah Dosen" << endl;
            cout << "2. Lihat Dosen" << endl;
            cout << "3. Edit data Dosen" << endl;
            cout << "4. Hapus Dosen" << endl;
            cout << "0. Logout" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: 
                system("cls");
                    mnjDosen.tambahDosen();
                break;
                case 2: 
                    system("cls");
                    mnjDosen.tampilDosen();
                break;
                case 3: 
                    system("cls");
                    mnjDosen.editDosen();
                break;
                case 4: 
                    system("cls");
                    mnjDosen.hapusDosen(); 
                break;
                case 5: 
                    system("cls");
                    mnjDosen.cekKeaktifanDosen();
                break;
                case 6:
                    nav.pop();
                    cout << "Kembalikan ke dashboard admin...\n";
                    return;
                case 0:
                system("cls");
                    nav.pop();
                    cout << "Logout admin...\n";
                    return; 
                default: cout << "Pilihan tidak valid!\n";
                break;
            }
        } while (true);
    }

    void tampilMenuMhs() {
        nav.push("Dashboard Manajemen Mahasiswa");
        int pilih;
        do {
            cout<< "==============================================" << endl;
            cout<< "  ==== DASHBOARD MANAJEMEN MAHASISWA ====  " << endl;
            cout<< "==============================================" << endl;
            cout << "1. Tambah Mahasiswa" << endl;
            cout << "2. Lihat Mahasiswa" << endl;
            cout << "3. Edit data Mahasiswa" << endl;
            cout << "4. Hapus Mahasiswa" << endl;
            cout << "5. Cek Keaktifan Mahasiswa" << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: 
                system("cls");
                mnjMhs.tambahMahasiswa(); 
                break;
                case 2: 
                system("cls");
                mnjMhs.tampilMahasiswa(); 
                break;
                case 3:
                system("cls");
                 mnjMhs.editMahasiswa(); 
                break;
                case 4: 
                system("cls");
                    mnjMhs.hapusMahasiswa();
                break;
                
                case 5:
                 system("cls");
                    mnjMhs.cekKeaktifanMahasiswa();
                break;
                case 6: 
                system("cls");
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
            cout<<endl;
             cout<<"==============================================" << endl;
             cout<<"  ==== DASHBOARD MANAJEMEN MATA KULIAH ====  " << endl;
             cout<<"==============================================" << endl;
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
                system("cls");
                    mnjMatkul.tambahMataKuliah();
                    break;
                case 2:
                system("cls");
                    mnjMatkul.tampilMataKuliahPerSemester();
                    break;
                case 3:
                system("cls");
                    mnjMatkul.tampilSemuaMataKuliah();
                    break;
                case 4:
                system("cls");
                    mnjMatkul.editMataKuliah();
                    break;
                case 5:
                system("cls");
                    mnjMatkul.hapusMataKuliah();
                    break;
                case 6:
                system("cls");
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

            cout << "===================================================" << endl;
            cout << "  ==== DASHBOARD MANAJEMEN DOSEN MATA KULIAH ====  " << endl;
            cout << "===================================================" << endl;
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
                system("cls");
                    mnjdsmatkul.tambahDosenMataKuliah();
                    break;
                case 2:
                system("cls");
                    mnjdsmatkul.tampilSemuaDosenMataKuliah();
                    break;
                case 3:
                system("cls");
                    mnjdsmatkul.cariDosenMataKuliah();
                    break;
                case 4:
                system("cls");
                    mnjdsmatkul.editDosenMataKuliah();
                    break;
                case 5:
                system("cls");
                    mnjdsmatkul.hapusDosenMataKuliah();
                    break;
                case 6:
                system("cls");
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
            cout << "===============================================" << endl;
            cout << "      ==== DASHBOARD MANAJEMEN KELAS ====     " << endl;
            cout << "===============================================" << endl;
            cout << "1. Tambah Kelas" << endl;
            cout << "2. Lihat Semua Kelas" << endl;
            cout << "3. Edit Kelas" << endl;
            cout << "4. Hapus Kelas" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                system("cls");
                    mnjKelas.tambahKelas();
                    break;
                case 2:
                system("cls");
                    mnjKelas.tampilSemuaKelas();
                    break;
                case 3:
                system("cls");
                    mnjKelas.editKelas();
                    break;
                case 4:
                system("cls");
                    mnjKelas.hapusKelas();
                    break;
                case 5:
                system("cls");
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
            cout<<"===============================================" << endl;
            cout<<"  === DASHBOARD MANAJEMEN KELAS MAHASISWA ===" << endl;
            cout<<"===============================================" << endl;
            cout << "1. Tambah Kelas Mahasiswa" << endl;
            cout << "2. Lihat Semua Kelas Mahasiswa" << endl;
            cout << "3. Edit Kelas Mahasiswa" << endl;
            cout << "4. Hapus Mahasiswa dari Kelas" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch(pilih) {
                case 1:
                system("cls");
                    mnjKelasMahasiswa.tambahKelasMahasiswa();
                    break;
                case 2:
                system("cls");
                    mnjKelasMahasiswa.tampilSemuaKelasMahasiswa();
                    break;
                case 3:
                system("cls");
                    mnjKelasMahasiswa.editKelasMahasiswa();
                    break;
                case 4:
                system("cls");
                    mnjKelasMahasiswa.hapusKelasMahasiswa();
                    break;
                case 5:
                system("cls");
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
                cout<<"===============================================" << endl;
                cout<<"        ==== DASHBOARD MANAJEMEN KRS ====      " << endl;
                cout<<"===============================================" << endl;
                cout << "1. Tambah krs mahasiswa" << endl;
                cout << "2. Lihat Semua krs berdasarkan kelas dan semester" << endl;
                cout << "3. Edit krs mahasiswa" << endl;
                cout << "4. Hapus krs mahasiswa" << endl;
                cout << "5. Validasi Permintaan KRS (Pending)" << endl;
                cout << "6. Keluar" << endl;
                cout << "Pilih: ";
                cin >> pilih;

                switch(pilih) {
                    case 1:
                    system("cls");
                         mnjKrs.tambahKrs();
                        break;
                    case 2:
                    system("cls");
                        mnjKrs.tampilKrsByKelas();
                        break;
                    case 3:
                    system("cls");
                         mnjKrs.editKrs();
                        break;
                    case 4:
                    system("cls");
                         mnjKrs.hapusKrs();
                        break;
                    case 5:
                    system("cls");
                        mnjKrs.validasiPengajuanKrs();
                        
                        break;
                    case 6:
                    system("cls");
                        nav.pop();
                        cout << "Kembalikan ke dashboard admin...\n";
                        return;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                }
            } while (pilih != 5);
        }

        void menuInputDanKoreksiNilai() {
        int pilihan;
        do {
            system("cls");
            cout << "\n========================================\n";
            cout << "      MENU INPUT DAN KOREKSI NILAI\n";
            cout << "========================================\n";
            cout << "1. Input Nilai oleh Dosen\n";
            cout << "2. Status Validasi (Belum/Divalidasi/Revisi)\n";
            cout << "3. Edit dan Koreksi Nilai\n";
            cout << "4. Rekap Nilai per Kelas/Mata Kuliah\n";
            cout << "0. Kembali\n";
            cout << "========================================\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    system("cls");
                    mnjik.inputNilaiOlehDosen();
                    break;
                case 2:
                    system("cls");
                    mnjik.tampilStatusValidasi();
                    break;
                case 3:
                    system("cls");
                    mnjik.editDanKoreksiNilai();
                    break;
                case 4:
                    system("cls");
                    mnjik.rekapNilaiPerKelas();
                    break;
                case 0:
                system("cls");
                    nav.pop();
                    cout << "Kembali ke menu utama admin...\n";
                    return;
                default:
                    cout << "Pilihan tidak valid!\n";
                    system("pause");
            }
        } while (pilihan != 0);
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
    ManajemenKelasMahasiswa* klsMhs;
    ManajemenKrs* mnjKrs;
    ManajemenMahasiswa* mhs;
    Perkuliahan* per;
    

public:
    MahasiswaDashboard(MahasiswaPortal* portal) : mhsPortal(portal) {
        mk = new ManajemenMatakuliah();
        mk->tarikDataDariFileMataKuliah();
        
        dmk = new ManajemenDosenMataKuliah();
        dmk->tarikDataDariFileDosenMataKuliah();
        
        kls = new ManajemenKelas();
        
        klsMhs = new ManajemenKelasMahasiswa();
        mnjKrs = new ManajemenKrs();
        
        krs = new KRSKHS(mk, dmk, kls);
        krs->setManagers(klsMhs, mnjKrs);
        krs->setMahasiswaPortal(mhsPortal);
    }

    void tampilMenuDashMahasiswa() {
        nav.push("Dashboard Mahasiswa");
        int pilih;
        do {
            cout<<"===============================================" << endl;
            cout<<"        ==== DASHBOARD MAHASISWA ====          " << endl;
            cout<<"===============================================" << endl;
            cout << "1. Profile" << endl;
            cout << "2. Perkuliahan" << endl;
            cout << "3. KRS dan KHS" << endl;
            cout << "4. Mata Kuliah" << endl;
            cout << "5. Logout" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1:
                system("cls");
                 tampilProfil();
                 system("cls");
                    break;
                case 2:
                system("cls");
                tampilPerkuliahan();
                system("cls");
                    break;
                case 3:
                system("cls");
                tampilKRSKHS();
                system("cls");
                    break;
                case 4: 
                system("cls");
                tampilMataKuliah();
                    break;
                case 5:
                    system("cls");
                    mhsPortal->logout();
                    system("cls");
                    nav.pop();
                    return;
                default:
                    cout << "Pilihan tidak valid!\n";
                    break;
            }
        } while (true);
    }

    


    void tampilProfil(){
        nav.push("Tampil Menu Profil Mahasiswa");
        int pilih;
        do{
            cout<<"===============================================" << endl;
            cout<<"   ==== MENU MANAJEMEN PROFIL MAHASISWA ====          " << endl;
            cout<<"===============================================" << endl;
            cout<<"1. Biodata"<<endl;
            cout<<"2. Tagihan"<<endl;
            cout<<"3. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                system("cls");
                    mhsPortal->tampilProfil();
                    system("cls");
                    break;
                case 2:
                system("cls");
                    mhsPortal->Tagihanmhs();
                    system("cls");
                    break;
                case 3:
                system("cls");
                    nav.pop();
                    cout<<"Kembalikan ke dashboard mahasiswa...\n";
                    system("cls");
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
            cout<<"================================================" << endl;
            cout<<" ==== MENU MANAJEMEN PERKULIAHAN MAHASISWA ====          " << endl;
            cout<<"================================================" << endl;
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
                system("cls");
                per->tampilMataKuliahAktif(mhsPortal->getNIMMahasiswa());
                system("cls");
                    break;
                    
                case 2:
                    system("cls");
                    per->tampilSertifikatSeminar(mhsPortal->getNIMMahasiswa());
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    per->tampilSertifikatPrestasi(mhsPortal->getNIMMahasiswa());
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    per->tampilPresensiKuliah(mhsPortal->getNIMMahasiswa());
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    per->tampilInformasi();
                    system("cls");
                    break;
                case 6:
                system("cls");
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
            cout<<"================================================" << endl;
            cout<<" ==== MENU MANAJEMEN PERKULIAHAN MAHASISWA ====          " << endl;
            cout<<"================================================" << endl;
            cout<<"1. KRS Reguler"<<endl;
            cout<<"2. KRS Aktivitas Mahasiswa"<<endl;
            cout<<"3. Cetak KRS"<<endl;
            cout<<"4. Cek Nilai(KHS)"<<endl;
            cout<<"5. Pendaftaran Seminar"<<endl;
            cout<<"6. Pendaftaran Ujian"<<endl;
            cout<<"7. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                system("cls");
                    krs->TampilDosenMatakuliahKrs();
                    system("cls");
                    break;
                case 2:
                system("cls");
                    krs->tampilKrsAktivitas();
                    system("cls");
                    break;
                case 3:
                system("cls");
                    krs->cetakKrsMahasiswa(mhsPortal->getNIMMahasiswa());
                  system("cls");
                    
                    break;
                case 4:
                system("cls");
                    krs->cekNilaiMhs(mhsPortal->getNIMMahasiswa());
                    break;
                case 5:
                    krs->PendaftaranSeminarMhs(mhsPortal->getNIMMahasiswa());
                    break;
                case 6:
                    krs->PendaftaranUjianMhs(mhsPortal->getNIMMahasiswa());
                    break;
                case 7:
                system("cls");
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
            cout<<"==============================================" << endl;
            cout<<"==== MENU MANAJEMEN PERKULIAHAN MAHASISWA===="<<endl;
            cout<<"==============================================" << endl;
            cout<<"1. Mata Kuliah Semester Gasal"<<endl;
            cout<<"2. Mata Kuliah Semester Genap"<<endl;
            cout<<"3. Seluruh Mahasiswa"<<endl;
            cout<<"4. Keluar"<<endl;
            cout<<"Masukkan Pilihan:";
            cin>>pilih;

            switch(pilih){
                case 1:
                system("cls");
                    mk->tampilkanMatakuliahGanjil();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                system("cls");
                    mk->tampilkanMatakuliahGenap();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                system("cls");
                    mhs->tampilMahasiswa();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                system("cls");
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
    
    while(true){
        cout<<"==============================================" << endl;
        cout<<"             ==== LOGIN ADMIN ====            " << endl;
        cout<<"==============================================" << endl;
        cout << "Username: "; cin >> u;
        cout << "Password: "; cin >> p;
        
        if (portal.login(u, p)) {
            system("cls");
            AdminDashboard dashboard;
            dashboard.setAdminPortal(&portal);  // Pass AdminPortal pointer ke dashboard
            dashboard.tampilMenuDashAdmin();
            
            // Setelah logout, loop kembali ke login form
        }else{
            cout << "\nLogin gagal! Silakan coba lagi.\n";
            cout << "1. Coba lagi\n2. Kembali ke Menu Utama\nPilih: ";
            cin >> pilihan;
            if(pilihan==2){
                return; // keluar ke main menu
            }
        }
    }
}

void displayMahasiswa(){
    MahasiswaPortal portal(new DataMahasiswa());
    string u, p;
    bool kondisi = false;
    int pilihan;
    do
    {
        cout<<"===============================================" << endl;
        cout<<"           ==== LOGIN MAHASISWA ====           " << endl;
        cout<<"===============================================" << endl;
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
    while (true) {
        int pilih;
        
        cout<<"==============================================" << endl;
        cout<<"      ==== SISTEM INFORMASI AKADEMIK ====         " << endl;
        cout<<"==============================================" << endl;
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
                return;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    }
}

int main(){
    displayMainMenu();
    return 0;
}