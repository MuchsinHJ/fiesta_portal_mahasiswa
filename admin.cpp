#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

enum class StatusAkademik { Aktif, Cuti, Lulus, DropOut };
enum class StatusDosen { Aktif, Cuti, Pensiun, TidakAktif };
enum class JenisKelamin { LakiLaki, Perempuan };

struct Mahasiswa {
    string nama;
    string nim;
    int semester;
    int tahunMasuk;
    int angkatan;
    string jurusan;
    string fakultas;

    // Informasi pribadi
    string tempatLahir;
    string tanggalLahir;
    string alamat;
    string email;
    string noHp;
    JenisKelamin g;

    // Akun portal
    string username;
    string password;

    // Akademik
    float ipk = 0.0;
    int sksDitempuh = 0;
    StatusAkademik statusAkademik = StatusAkademik::Aktif;
    string dosenWali;

    bool aktif = true;
};

struct Dosen {
    // Identitas dasar
    string nama;
    string nidn;        // Nomor Induk Dosen Nasional
    string nip;         // Nomor Induk Pegawai (jika PNS)
    string gelarDepan;  // misal: "Dr.", "Prof."
    string gelarBelakang; // misal: "M.Kom", "Ph.D"

    // Informasi akademik
    string fakultas;
    string jurusan;
    string jabatanAkademik; // misal: "Lektor", "Guru Besar", "Asisten Ahli"
    string pendidikanTerakhir; // misal: "S2", "S3"

    // Data pribadi
    JenisKelamin gender;
    string email;
    string noHp;
    string alamat;

    // Status kepegawaian
    StatusDosen status = StatusDosen::Aktif;
    int tahunMasuk;
    bool aktif = true;

    // Relasi / data tambahan
    // vector<string> mataKuliahDibina; // daftar mata kuliah yang diajar
};

struct MataKuliah {
    string kodeMK;         // Kode unik, contoh: "IF1234"
    string namaMK;         // Nama mata kuliah, contoh: "Algoritma & Struktur Data"
    int sks;               // Jumlah SKS
    string deskripsi;      // Keterangan singkat mata kuliah
    int semester;          // Semester disarankan, contoh: 2
    string jurusan;        // Jurusan pemilik mata kuliah
    string fakultas;       // Fakultas terkait

    // Dosen pengampu
    string nidnDosen;      // relasi ke struct Dosen (bisa juga pointer ke objek Dosen)
    vector<string> asistenDosen; // jika ada asisten

    // Akademik
    bool wajib;            // true = wajib, false = pilihan
    int kapasitas;         // jumlah maksimum mahasiswa
    vector<string> daftarNIM; // daftar mahasiswa yang mengambil MK ini

    // Jadwal dan lokasi
    string hari;           // contoh: "Senin"
    string jam;            // contoh: "08:00 - 09:40"
    string ruang;          // contoh: "Lab 3A"

    // Status
    bool aktif = true;     // apakah MK masih dibuka semester ini
};

// === Class untuk login dan autentikasi ===
class AdminPortal {
private:
    string username;
    string password;
    bool statusLogin = false;
public:
    AdminPortal(string user, string pass) : username(user), password(pass) {}

    bool login(string user, string pass) {
        if (user == username && pass == password) {
            statusLogin = true;
            cout << "Login berhasil, selamat datang " << username << endl;
        } else {
            cout << "Login gagal!" << endl;
        }
        return statusLogin;
    }

    bool isLogin() const {
        return statusLogin;
    }
};

// === Class untuk manajemen data mahasiswa ===
class ManajemenMahasiswa {
private:
    Mahasiswa mhsBaru;
    Mahasiswa data[100];
    int jumlah = 0;
public:

    void tambahMahasiswa() {
        cout << "=====MENU TAMBAH MAHASISWA=====" << endl;
        cout << "Masukkan nama mahasiswa: ";
        cin.ignore();
        getline(cin, mhsBaru.nama);

        // Validasi NIM duplikat
        bool nimDuplikat;
        do {
            nimDuplikat = false;
            cout << "Masukkan NIM: ";
            cin >> mhsBaru.nim;

            for (int i = 0; i < jumlah; i++) {
                if (mhsBaru.nim == data[i].nim) {
                    cout << "NIM sudah terdaftar! Silakan masukkan NIM lain.\n";
                    nimDuplikat = true;
                    break;
                }
            }
        } while (nimDuplikat);

        cout << "Masukkan semester: ";
        cin >> mhsBaru.semester;
        cout << "Masukkan tahun masuk: ";
        cin >> mhsBaru.tahunMasuk;
        cout << "Masukkan angkatan: ";
        cin >> mhsBaru.angkatan;
        cin.ignore();
        cout << "Masukkan jurusan: ";
        getline(cin, mhsBaru.jurusan);
        cout << "Masukkan fakultas: ";
        getline(cin, mhsBaru.fakultas);
        cout << "Masukkan tempat lahir: ";
        getline(cin, mhsBaru.tempatLahir);
        cout << "Masukkan tanggal lahir (DD-MM-YYYY): ";
        getline(cin, mhsBaru.tanggalLahir);
        cout << "Masukkan alamat: ";
        getline(cin, mhsBaru.alamat);
        cout << "Masukkan email: ";
        getline(cin, mhsBaru.email);
        cout << "Masukkan nomor HP: ";
        getline(cin, mhsBaru.noHp);

        // Input jenis kelamin (enum)
        int pilihGender;
        cout << "Pilih jenis kelamin (1. Laki-laki, 2. Perempuan): ";
        cin >> pilihGender;
        mhsBaru.g = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;

        mhsBaru.aktif = true;

        // Simpan ke array
        data[jumlah] = mhsBaru;
        jumlah++;

        // Simpan ke file
        ofstream in("dataMahasiswa.txt", ios::app);
        if (in.is_open()) {
            in << "Data Mahasiswa ke-" << jumlah << ":\n";
            in << "Nama: " << mhsBaru.nama << "\n";
            in << "NIM: " << mhsBaru.nim << "\n";
            in << "Semester: " << mhsBaru.semester << "\n";
            in << "Tahun Masuk: " << mhsBaru.tahunMasuk << "\n";
            in << "Angkatan: " << mhsBaru.angkatan << "\n";
            in << "Jurusan: " << mhsBaru.jurusan << "\n";
            in << "Fakultas: " << mhsBaru.fakultas << "\n";
            in << "Tempat Lahir: " << mhsBaru.tempatLahir << "\n";
            in << "Tanggal Lahir: " << mhsBaru.tanggalLahir << "\n";
            in << "Alamat: " << mhsBaru.alamat << "\n";
            in << "Email: " << mhsBaru.email << "\n";
            in << "No HP: " << mhsBaru.noHp << "\n";
            in << "Jenis Kelamin: " << (mhsBaru.g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
            in << "Status: " << (mhsBaru.aktif ? "Aktif" : "Tidak Aktif") << "\n";
            in << "--------------------------\n";
            in.close();
        } else {
            cout << "Gagal membuka file untuk menyimpan data.\n";
        }

        cout << "Mahasiswa berhasil ditambahkan!\n";
    }

    void tampilMahasiswa() {
        cout << "\n=== Data Mahasiswa ===\n";
        ifstream out;
        out.open("dataMahasiswa.txt");
        string cetak;
        while (getline(out, cetak)) {
            cout << cetak << endl;
        }
    }
};

class ManajemenDosen{
    public:
    Dosen data[1000];
    int jumlah = 0;
        
        void tambahDosen(){
            cout<<"=====MENU TAMBAH DOSEN====="<<endl;
            cout<<"Masukkan nama dosen: ";
            cin.ignore();
            getline(cin, data[jumlah].nama);
            cout<<"Masukkan NIDN:";
            cin>>data[jumlah].nidn;
            cout<<"Masukkan NIP:";
            cin>>data[jumlah].nip;
            cout<<"Masukkan fakultas:";
            cin>>data[jumlah].fakultas;
            cout<<"Masukkan jurusan:";
            cin>>data[jumlah].jurusan;
            cout<<"Gelar Depan:";
            cin>>data[jumlah].gelarDepan;
            cout<<"Gelar Belakang:";
            cin>>data[jumlah].gelarBelakang;
            cout<<"Jabatan Akademik:";
            cin>>data[jumlah].jabatanAkademik;
            cout<<"Pendidikan Terakhir:";
            cin>>data[jumlah].pendidikanTerakhir;
            cout<<"Email:";
            cin>>data[jumlah].email;
            cout<<"No HP:";
            cin>>data[jumlah].noHp;
            cout<<"Alamat:";
            cin>>data[jumlah].alamat;
            cout<<"Jenis Kelamin (1. Laki-laki, 2. Perempuan):";
            int pilihGender;
            cin>>pilihGender;
            data[jumlah].gender = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;
            cout<<"Tahun Masuk:";
            cin>>data[jumlah].tahunMasuk;
            cout<<"Status (1. Aktif, 2. Cuti, 3. Pensiun, 4. Tidak Aktif):";
            int pilihStatus;
            cin>>pilihStatus;
            switch(pilihStatus){
                case 1:
                    data[jumlah].status = StatusDosen::Aktif;
                    break;
                case 2:
                    data[jumlah].status = StatusDosen::Cuti;
                    break;
                case 3:
                    data[jumlah].status = StatusDosen::Pensiun;
                    break;
                case 4:
                    data[jumlah].status = StatusDosen::TidakAktif;
                    break;
                default:
                    cout<<"Pilihan tidak valid! Mengatur status ke Aktif secara default."<<endl;
                    data[jumlah].status = StatusDosen::Aktif;
                    break;
            }
            jumlah++;
            cout<<"Dosen berhasil ditambahkan!"<<endl;  
        }

        
        
        void tampilDosen(){
            cout<<"\n=== Data Dosen ===\n";
            for(int i=0;i<jumlah;i++){
                cout<<"Dosen ke-"<<i+1<<":"<<endl;
                cout<<"Nama: "<<data[i].nama<<endl;
                cout<<"NIDN: "<<data[i].nidn<<endl;
                cout<<"NIP: "<<data[i].nip<<endl;
                cout<<"Fakultas: "<<data[i].fakultas<<endl;
                cout<<"Jurusan: "<<data[i].jurusan<<endl;
                cout<<"Gelar Depan: "<<data[i].gelarDepan<<endl;
                cout<<"Gelar Belakang: "<<data[i].gelarBelakang<<endl;
                cout<<"Jabatan Akademik: "<<data[i].jabatanAkademik<<endl;
                cout<<"Pendidikan Terakhir: "<<data[i].pendidikanTerakhir<<endl;
                cout<<"Email: "<<data[i].email<<endl;
                cout<<"No HP: "<<data[i].noHp<<endl;
                cout<<"Alamat: "<<data[i].alamat<<endl;
                cout<<"Jenis Kelamin: "<<(data[i].gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")<<endl;
                cout<<"Tahun Masuk: "<<data[i].tahunMasuk<<endl;
                cout<<"Status: ";
                switch(data[i].status){
                    case StatusDosen::Aktif:
                        cout<<"Aktif"<<endl;
                        break;
                    case StatusDosen::Cuti:
                        cout<<"Cuti"<<endl;
                        break;
                    case StatusDosen::Pensiun:
                        cout<<"Pensiun"<<endl;
                        break;
                    case StatusDosen::TidakAktif:
                        cout<<"Tidak Aktif"<<endl;
                        break;
                }
                cout<<"--------------------------"<<endl;
            }

            ofstream in("dataDosen.txt");
            if(in.is_open()){
                for(int i=0;i<jumlah;i++){
                    in<<"Dosen ke-"<<i+1<<":"<<"\n";
                    in<<"Nama: "<<data[i].nama<<"\n";
                    in<<"NIDN: "<<data[i].nidn<<"\n";
                    in<<"NIP: "<<data[i].nip<<"\n";
                    in<<"Fakultas: "<<data[i].fakultas<<"\n";
                    in<<"Jurusan: "<<data[i].jurusan<<"\n";
                    in<<"Gelar Depan: "<<data[i].gelarDepan<<"\n";
                    in<<"Gelar Belakang: "<<data[i].gelarBelakang<<"\n";
                    in<<"Jabatan Akademik: "<<data[i].jabatanAkademik<<"\n";
                    in<<"Pendidikan Terakhir: "<<data[i].pendidikanTerakhir<<"\n";
                    in<<"Email: "<<data[i].email<<"\n";
                    in<<"No HP: "<<data[i].noHp<<"\n";
                    in<<"Alamat: "<<data[i].alamat<<"\n";
                    in<<"Jenis Kelamin: "<<(data[i].gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")<<"\n";
                    in<<"Tahun Masuk: "<<data[i].tahunMasuk<<"\n";
                    in<<"Status: ";
                    switch(data[i].status){
                        case StatusDosen::Aktif:
                            in<<"Aktif"<<"\n";
                            break;
                        case StatusDosen::Cuti:
                            in<<"Cuti"<<"\n";
                            break;
                        case StatusDosen::Pensiun:
                            in<<"Pensiun"<<"\n";
                            break;
                        case StatusDosen::TidakAktif:
                            in<<"Tidak Aktif"<<"\n";
                            break;
                    }
                }
                in.close();
            }else{
                cout<<"Gagal membuka file untuk menyimpan data dosen."<<endl;
            }
        }
};

// === Class untuk menu utama admin ===
class AdminDashboard {
private:
    ManajemenMahasiswa mnjMhs;
    ManajemenDosen mnjDosen;
public:
    void tampilMenuDash() {
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
                case 1: tampilMenuMnj(); 
                break;
                case 2: tampilMenuDosen();
                break;
                case 3: cout << "Keluar dari dashboard admin...\n"; 
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
            cout << "3. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: mnjDosen.tambahDosen(); 
                break;
                case 2: mnjDosen.tampilDosen();
                break;
                case 3: cout << "Keluar dari dashboard manajemen dosen...\n"; 
                break;
                default: cout << "Pilihan tidak valid!\n";
                break;
            }
        } while (pilih != 3);
    }

    void tampilMenuMnj() {
        int pilih;
        do {
            cout << "\n=== DASHBOARD MANAJEMEN MAHASISWA ===" << endl;
            cout << "1. Tambah Mahasiswa" << endl;
            cout << "2. Lihat Mahasiswa" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1: mnjMhs.tambahMahasiswa(); 
                break;
                case 2: mnjMhs.tampilMahasiswa(); 
                break;
                case 3: cout << "Keluar dari dashboard manajemen mahasiswa...\n"; 
                break;
                default: cout << "Pilihan tidak valid!\n"; 
                break;
            }
        } while (pilih != 3);
    }
};


