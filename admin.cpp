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

//class untuk menu utama matakuliah
class ManajemenMatakuliah {
private:
    struct NodeMataKuliah {
        MataKuliah data;          // Data mata kuliah
        NodeMataKuliah* next;     // Pointer ke node berikutnya
    };

    NodeMataKuliah* head;         // Pointer ke head linked list

public:
    
    ManajemenMatakuliah() {
        head = nullptr;

        tambahMataKuliahLangsung({"IF101", "Dasar Pemrograman", 3, "Dasar-dasar pemrograman", 1, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF102", "Dasar Sistem Komputer", 3, "Dasar Dasar Komputer", 1, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF103", "Kalkulus Informatika", 3, "Dasar-dasar Perhitungan ", 1, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF104", "Logika Informatika ", 3, "Dsar Logika Pemprograman", 1, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF105", "Manajemen Data dan Informasi", 3, "Dasar Manajemen data", 1, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF106", "Pancasila", 2, "Pemahaman Tata Negara", 1, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF107", "Praktikum Dasar Pempograman", 1, "Praktikum ", 1, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF108", "AL-Qur'an dan Hadits", 2, "Pengertian Al-Qur'an ", 1, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
    
        tambahMataKuliahLangsung({"IF111", "Pemrograman Web", 3, " Dasar Pemprograman Web ", 2, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF112", "Matematika Diskrit", 3, "Perhitungan Berbasis program", 2, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF113", "Bahasa Indonesia", 3, "Penerapan Dasar Bahasa Indonesia", 2, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF114", "Aljabar Linear Matrik", 2, "Perhitungan aljabar", 2, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF115", "Algoritma Pemprograman", 3, "Dasar dasar Pemprograman", 2, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF116", "Aristektur Komputer", 3, "Dasar Susunan komputer", 2, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF117", "Kemuhammadiyahan", 2, "Pembelajaran Muhammadiyah", 2, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});

        tambahMataKuliahLangsung({"IF121", "Algoritma dan Pemrograman", 3, "Dasar-dasar pemrograman", 3, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF122", "Struktur Data", 3, "Pengelolaan data dalam memori", 3, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF123", "Basis Data", 4, "Dasar-dasar basis data", 3, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF124", "Pemrograman Berorientasi Objek", 3, "Konsep OOP", 3, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF125", "Sistem Operasi", 3, "Operasi Sistem Komputer", 3, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF126", "Bahasa Inggris", 2, "Pembelajarann bahasa Inggris IT", 3, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF127", "Statistika Informatika", 4, "Konsep penerapan statistik ", 3, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF128", "Akidah Akhlak", 2, "Perbaikan Akhlak ", 3, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});

        tambahMataKuliahLangsung({"IF131", "AnalisiS Dan Perancangan Perangkat Lunak", 3, "Konsep Perancangan Perangkat Lunak", 4, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF132", "Grafika Komputer", 3, "Penerapan Grafik Komputer", 4, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF133", "Interaksi Manusia dan Komputer", 3, "Interaksi Manusia dan Sistem Komputer", 4, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF134", "Islam Inerdisipliner", 3, "Pengajaran Islam ", 4, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF135", "Kecedarsan Buatan", 3, "Operasi sistem cerdas", 4, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF136", "Komunikasi Data dan Jaringan Komputer", 3, "Komunikasi data jaringan", 4, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF137", "Strategi Algoritma", 3, "Strategi Pemprograman ", 4, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});

        tambahMataKuliahLangsung({"IF141", "Forensik Digital", 3, "Pemeriksa Kasus Digital", 5, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF142", "Keamanan Komputer", 3, "Computer Security", 5, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF143", "Pembelajar Mesin", 3, "Pembelajaran Konsep Mesin Learning", 5, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF144", "Pemprograman Mobile", 3, "Pembuatan Aplikasi Mobile ", 5, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF145", "Pemprograman Web Dinamis", 3, "Pembuatan Web", 5, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF146", "Data Mining", 3, "Penambangan Data", 5, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF147", "Pengantar Manajemen dan Prinsip Proyek", 2, "Penerapan Managemen Konsep Dalam Proyek ", 5, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF148", "Penjaminan Kualitas Perangkat Lunak", 3, "Penjamin Kualitas Perangkat Lunak ", 5, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF149", "Robotika Informatika", 3, "Perancangan Robot", 5, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF150", "Sistem Pendukung Keputusan", 3, "Pendukung Keputusan", 5, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF151", "Sistem Temu Balik Informasi", 3, "Temu Balik ", 5, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF152", "Teknik Optimasi", 3, "Optimasi", 5, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF153", "Teori Bahasa Otomata", 2, "Bahasa Otomata ", 5, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});

        tambahMataKuliahLangsung({"IF156", "Manajemen Proyek Teknologi Informasi", 2, "Konsep Perancangan Perangkat Lunak", 6, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF157", "Pengajaran TPQ", 0, "NGaji", 6, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF158", "Tahsinul Quran", 0, "Perbaikan Cara baca AL-Qur'an", 6, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});

        tambahMataKuliahLangsung({"IF161", "Bahasa Inggris Profesional", 2, "Bahasa Internasional", 7, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF162", "Fiqih Ibadah", 0, "Fikih", 7, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF163", "Kapita Selekta", 2, "Kapita Selekta", 7, "Informatika", "Teknik", "12347", {}, true, 40, {}, "Rabu", "08:00-10:00", "Lab 3", true});
        tambahMataKuliahLangsung({"IF164", "Kewirausahaan", 2, "Pelatihan Ber wirausahaan ", 7, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF165", "komunikasi Interpersonal", 2, "Komunikasi", 7, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF166", "Pengukuran Arah Kiblat", 0, "Penentu Arah Kiblat", 7, "Informatika", "Teknik", "12345", {}, true, 40, {}, "Senin", "08:00-10:00", "Lab 1", true});
        tambahMataKuliahLangsung({"IF167", "Pra Nikah", 0, "Pra Nikah ", 7, "Informatika", "Teknik", "12346", {}, true, 40, {}, "Selasa", "10:00-12:00", "Lab 2", true});
        tambahMataKuliahLangsung({"IF168", "Praktek Magang", 3, "Magang ", 7, "Informatika", "Teknik", "12348", {}, true, 40, {}, "Kamis", "10:00-12:00", "Lab 4", true});
        tambahMataKuliahLangsung({"IF1669", "Sosio Informatika", 2, "Sosio", 7, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        tambahMataKuliahLangsung({"IF1670", "Kuliah Kerja Nyata", 4, "KKN", 7, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});

        tambahMataKuliahLangsung({"IF1681", "Skripsi", 6, "Tugas Akhir", 8, "Informatika", "Teknik", "12349", {}, true, 40, {}, "Jumat", "08:00-10:00", "Lab 5", true});
        
        
        

        
    }

    
    void tambahMataKuliahLangsung(const MataKuliah& mk) {
        NodeMataKuliah* newNode = new NodeMataKuliah();
        newNode->data = mk;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            NodeMataKuliah* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

   
    void tampilSemuaMataKuliah() {
        if (head == nullptr) {
            cout << "Belum ada mata kuliah yang terdaftar." << endl;
            return;
        }

        cout << "\n=== Daftar Semua Mata Kuliah Berdasarkan Semester ===" << endl;
        for (int semester = 1; semester <= 8; semester++) {
            cout << "\n--- Semester " << semester << " ---" << endl;
            NodeMataKuliah* temp = head;
            bool ditemukan = false;
            while (temp != nullptr) {
                if (temp->data.semester == semester) {
                    cout << "Kode: " << temp->data.kodeMK << ", Nama: " << temp->data.namaMK
                         << ", SKS: " << temp->data.sks << ", Wajib: " << (temp->data.wajib ? "Ya" : "Tidak") << endl;
                    ditemukan = true;
                }
                temp = temp->next;
            }
            if (!ditemukan) {
                cout << "Tidak ada mata kuliah untuk semester ini." << endl;
            }
        }
    }

    
    void tampilMataKuliahPerSemester() {
        int semester;
        cout << "Masukkan semester yang ingin ditampilkan: ";
        cin >> semester;

        cout << "\n=== Mata Kuliah Semester " << semester << " ===" << endl;
        NodeMataKuliah* temp = head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->data.semester == semester) {
                cout << "Kode: " << temp->data.kodeMK << ", Nama: " << temp->data.namaMK
                     << ", SKS: " << temp->data.sks << ", Wajib: " << (temp->data.wajib ? "Ya" : "Tidak") << endl;
                ditemukan = true;
            }
            temp = temp->next;
        }
        if (!ditemukan) {
            cout << "Tidak ada mata kuliah untuk semester ini." << endl;
        }
    }

    
    void tambahMataKuliah() {
        NodeMataKuliah* newNode = new NodeMataKuliah();
        cout << "\n=== Tambah Mata Kuliah Baru ===" << endl;
        cout << "Masukkan kode mata kuliah: ";
        cin >> newNode->data.kodeMK;
        cin.ignore();
        cout << "Masukkan nama mata kuliah: ";
        getline(cin, newNode->data.namaMK);
        cout << "Masukkan jumlah SKS: ";
        cin >> newNode->data.sks;
        cin.ignore();
        cout << "Masukkan deskripsi mata kuliah: ";
        getline(cin, newNode->data.deskripsi);
        cout << "Masukkan semester: ";
        cin >> newNode->data.semester;
        cin.ignore();
        cout << "Masukkan jurusan: ";
        getline(cin, newNode->data.jurusan);
        cout << "Masukkan fakultas: ";
        getline(cin, newNode->data.fakultas);
        cout << "Masukkan NIDN dosen pengampu: ";
        cin >> newNode->data.nidnDosen;
        cout << "Apakah mata kuliah ini wajib? (1. Ya, 2. Tidak): ";
        int pilihWajib;
        cin >> pilihWajib;
        newNode->data.wajib = (pilihWajib == 1);
        cout << "Masukkan kapasitas mahasiswa: ";
        cin >> newNode->data.kapasitas;
        cin.ignore();
        cout << "Masukkan hari (misal: Senin): ";
        getline(cin, newNode->data.hari);
        cout << "Masukkan jam (misal: 08:00-10:00): ";
        getline(cin, newNode->data.jam);
        cout << "Masukkan ruang (misal: Lab 1): ";
        getline(cin, newNode->data.ruang);
        newNode->data.aktif = true;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            NodeMataKuliah* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Mata kuliah berhasil ditambahkan!" << endl;
    }
};

// === Class untuk menu utama admin ===
class AdminDashboard {
private:
    ManajemenMahasiswa mnjMhs;
    ManajemenDosen mnjDosen;
    ManajemenMatakuliah mnjMatkul;
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
                case 1: 
                    tampilMenuMnj(); 
                    break;

                case 2: 
                    tampilMenuDosen();
                    break;

                case 3:
                    tampilMenuMatakuliah();
                    break; 

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

    void tampilMenuMatakuliah() {
        int pilih;
        cout<<"====MENU MANAJEMEN MATAKULIAH===="<<endl;
        cout<<"1. Tambah Mata Kuliah"<<endl;
        cout<<"2. Lihat Mata Kuliah per Semester"<<endl;
        cout<<"3. Lihat Semua Mata Kuliah"<<endl;
        cout<<"4. Keluar"<<endl;
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
                cout<<"Keluar dari dashboard manajemen mata kuliah..."<<endl;
                break;
            default:
                cout<<"Pilihan tidak valid!"<<endl;
                break;
    }
}
};


