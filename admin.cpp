#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
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
    string jurusan;       // Jurusan pemilik mata kuliah
    string fakultas;       // Fakultas terkait

    // Akademik
    bool wajib;            // true = wajib, false = pilihan

    // Status
    bool aktif = true;     // apakah MK masih dibuka semester ini
};

// Relasi dosen dengan mata kuliah
struct DosenMataKuliah {
    string nidnDosen;
    string kodeMK;
    string kdDosenMk;
};

// Relasi mahasiswa dengan mata kuliah (KRS)
struct Krs {
    string nimMahasiswa;
    string kdDosenMk;
    string semesterDiambil; // contoh: "Ganjil 2023/2024"
    char nilaiHuruf;        // contoh: 'A', 'B', 'C', 'D', 'E', 'F'
    float nilaiAngka;      // contoh: 4.0, 3.5, dst.
};



// CLASS UNTUK LOGIN PORTAL ADMIN DAN AUTENTIKASI
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

//CLASS UNTUK MENU UTAMA MAHASISWA
class ManajemenMahasiswa {
private:
    Mahasiswa mhsBaru;
    Mahasiswa data[100];
    int jumlah = 0;
public:

void tambahMahasiswa() {
    cout << "=====MENU TAMBAH MAHASISWA=====\n";
    Mahasiswa mhsBaru;
    cout << "Masukkan nama mahasiswa: ";
    cin.ignore();
    getline(cin, mhsBaru.nama);

    bool nimDuplikat;
    do {
        nimDuplikat = false;
        cout << "Masukkan NIM: ";
        cin >> mhsBaru.nim;
        for (int i = 0; i < jumlah; i++) {
            if (data[i].nim == mhsBaru.nim) {
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
    cout << "Masukkan tanggal lahir: "; 
    getline(cin, mhsBaru.tanggalLahir);
    cout << "Masukkan alamat: "; 
    getline(cin, mhsBaru.alamat);
    cout << "Masukkan email: "; 
    getline(cin, mhsBaru.email);
    cout << "Masukkan nomor HP: "; 
    getline(cin, mhsBaru.noHp);

    int pilihGender;
    cout << "Pilih jenis kelamin (1. Laki-laki, 2. Perempuan): ";
    cin >> pilihGender;
    mhsBaru.g = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;

    mhsBaru.aktif = true;
    data[jumlah++] = mhsBaru;
    updateFileMhs(); // simpan semua
}
        
    void hapusMahasiswa() {
        cout << "=====MENU HAPUS MAHASISWA=====" << endl;
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
        cin >> nimCari;
        bool ditemukan = false;
        for (int i = 0; i < jumlah; i++) {
            if (data[i].nim == nimCari) {
                ditemukan = true;
                // Geser elemen setelahnya ke kiri
                for (int j = i; j < jumlah - 1; j++) {
                    data[j] = data[j + 1];
                }
                jumlah--;
                cout << "Mahasiswa dengan NIM " << nimCari << " telah dihapus.\n";
                updateFileMhs();
                break;
            }
        }
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }

    void tarikMahasiswadarifile(){
        jumlah = 0; // Reset jumlah sebelum membaca ulang
        ifstream in("dataMahasiswa.txt");
        
        if (!in.is_open()) {
            cout << "Gagal membuka file dataMahasiswa.txt\n";
            return;
        }

        string line;
        Mahasiswa mhsSementara;

        while (getline(in, line)) {
            if (line.find("Nama: ") != string::npos) {
                mhsSementara.nama = line.substr(6);
            } else if (line.find("NIM: ") != string::npos) {
                mhsSementara.nim = line.substr(5);
            } else if (line.find("Semester: ") != string::npos) {
                mhsSementara.semester = stoi(line.substr(10));
            } else if (line.find("Tahun Masuk: ") != string::npos) {
                mhsSementara.tahunMasuk = stoi(line.substr(13));
            } else if (line.find("Angkatan: ") != string::npos) {
                mhsSementara.angkatan = stoi(line.substr(10));
            } else if (line.find("Jurusan: ") != string::npos) {
                mhsSementara.jurusan = line.substr(9);
            } else if (line.find("Fakultas: ") != string::npos) {
                mhsSementara.fakultas = line.substr(10);
            } else if (line.find("Tempat Lahir: ") != string::npos) {
                mhsSementara.tempatLahir = line.substr(14);
            } else if (line.find("Tanggal Lahir: ") != string::npos) {
                mhsSementara.tanggalLahir = line.substr(15);
            } else if (line.find("Alamat: ") != string::npos) {
                mhsSementara.alamat = line.substr(8);
            } else if (line.find("Email: ") != string::npos) {
                mhsSementara.email = line.substr(7);
            } else if (line.find("No HP: ") != string::npos) {
                mhsSementara.noHp = line.substr(6);
            } else if (line.find("Jenis Kelamin: ") != string::npos) {
                string genderStr = line.substr(14);
                if (genderStr == "Laki-laki")
                    mhsSementara.g = JenisKelamin::LakiLaki;
                else
                    mhsSementara.g = JenisKelamin::Perempuan;
            } else if (line.find("Status: ") != string::npos) {
                string statusStr = line.substr(8);
                mhsSementara.aktif = (statusStr == "Aktif");
            } else if (line.find("--------------------------") != string::npos) {
                // Tambahkan ke array setiap selesai 1 blok data mahasiswa
                data[jumlah] = mhsSementara;
                jumlah++;
            }
        }

        in.close();

    }

    void updateFileMhs() {
    ofstream out("dataMahasiswa.txt", ios::trunc); // hapus isi lama
    if (!out.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        out << "Data Mahasiswa ke-" << i + 1 << ":\n";
        out << "Nama: " << data[i].nama << "\n";
        out << "NIM: " << data[i].nim << "\n";
        out << "Semester: " << data[i].semester << "\n";
        out << "Tahun Masuk: " << data[i].tahunMasuk << "\n";
        out << "Angkatan: " << data[i].angkatan << "\n";
        out << "Jurusan: " << data[i].jurusan << "\n";
        out << "Fakultas: " << data[i].fakultas << "\n";
        out << "Tempat Lahir: " << data[i].tempatLahir << "\n";
        out << "Tanggal Lahir: " << data[i].tanggalLahir << "\n";
        out << "Alamat: " << data[i].alamat << "\n";
        out << "Email: " << data[i].email << "\n";
        out << "No HP: " << data[i].noHp << "\n";
        out << "Jenis Kelamin: " << (data[i].g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
        out << "Status: " << (data[i].aktif ? "Aktif" : "Tidak Aktif") << "\n";
        out << "--------------------------\n";
    }

    out.close();
    cout << "File dataMahasiswa.txt berhasil diperbarui!\n";
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

    void editMahasiswa() {
        updateFileMhs();
        cout << "=====MENU EDIT MAHASISWA=====" << endl;
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang akan diedit: ";
        cin >> nimCari;
        bool ditemukan = false;
        for (int i = 0; i < jumlah; i++) {
            if (data[i].nim == nimCari) {
                ditemukan = true;
                cout << "Data ditemukan. Masukkan data baru:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                tampilMahasiswa();
                cout << "==============================\n";
                cout << " Masukkan Data Baru: \n";
                cout << "\nMasukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, data[i].nama);
                cout << "Masukkan semester: ";
                cin >> data[i].semester;
                cout << "Masukkan tahun masuk: ";
                cin >> data[i].tahunMasuk;
                cout << "Masukkan angkatan: ";
                cin >> data[i].angkatan;
                cin.ignore();
                cout << "Masukkan jurusan: ";
                getline(cin, data[i].jurusan);
                cout << "Masukkan fakultas: ";
                getline(cin, data[i].fakultas);
                cout << "Masukkan tempat lahir: ";
                getline(cin, data[i].tempatLahir);
                cout << "Masukkan tanggal lahir (DD-MM-YYYY): ";
                getline(cin, data[i].tanggalLahir);
                cout << "Masukkan alamat: ";
                getline(cin, data[i].alamat);
                cout << "Masukkan email: ";
                getline(cin, data[i].email);
                cout << "Masukkan nomor HP: ";
                getline(cin, data[i].noHp);

                // Input jenis kelamin (enum)
                int pilihGender;
                cout << "Pilih jenis kelamin (1. Laki-laki, 2. Perempuan): ";
                cin >> pilihGender;
                data[i].g = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;

                cout << "Data mahasiswa berhasil diperbarui!\n";
                updateFileMhs();
                break;
            }
            if (!ditemukan) {
                cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
            }
        }
    }
};

//CLASS UNTUK MENU UTAMA DOSEN
class ManajemenDosen{
public:
Dosen data[1000];
Dosen dosenBaru;
int jumlahDosen = 0;
    
    void tambahDosen(){
        cout<<"=====MENU TAMBAH DOSEN====="<<endl;
        cout<<"Masukkan nama dosen: ";
        cin.ignore();
        getline(cin, dosenBaru.nama);
        cout<<"Masukkan NIDN:";
        cin>>dosenBaru.nidn;
        cout<<"Masukkan NIP:";
        cin>>dosenBaru.nip;
        cout<<"Masukkan fakultas:";
        cin>>dosenBaru.fakultas;
        cout<<"Masukkan jurusan:";
        cin>>dosenBaru.jurusan;
        cout<<"Gelar Depan:";
        cin>>dosenBaru.gelarDepan;
        cout<<"Gelar Belakang:";
        cin>>dosenBaru.gelarBelakang;
        cout<<"Jabatan Akademik:";
        cin>>dosenBaru.jabatanAkademik;
        cout<<"Pendidikan Terakhir:";
        cin>>dosenBaru.pendidikanTerakhir;
        cout<<"Email:";
        cin>>dosenBaru.email;
        cout<<"No HP:";
        cin>>dosenBaru.noHp;
        cout<<"Alamat:";
        cin>>dosenBaru.alamat;
        cout<<"Jenis Kelamin (1. Laki-laki, 2. Perempuan):";
        int pilihGender;
        cin>>pilihGender;
        dosenBaru.gender = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;
        cout<<"Tahun Masuk:";
        cin>>dosenBaru.tahunMasuk;
        cout<<"Status (1. Aktif, 2. Cuti, 3. Pensiun, 4. Tidak Aktif):";
        int pilihStatus;
        cin>>pilihStatus;
        switch(pilihStatus){
            case 1:
                dosenBaru.status = StatusDosen::Aktif;
                break;
            case 2:
                dosenBaru.status = StatusDosen::Cuti;
                break;
            case 3:
                dosenBaru.status = StatusDosen::Pensiun;
                break;
            case 4:
                dosenBaru.status = StatusDosen::TidakAktif;
                break;
            default:
                cout<<"Pilihan tidak valid! Mengatur status ke Aktif secara default."<<endl;
                dosenBaru.status = StatusDosen::Aktif;
                break;
        }
        data[jumlahDosen] = dosenBaru;
        jumlahDosen++;
        cout<<"Dosen berhasil ditambahkan!"<<endl;

        updateFileDosen();
    }

    void updateFileDosen(){
        ofstream in("dataDosen.txt");
        if(in.is_open()){
            for(int i=0;i<jumlahDosen;i++){
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

    void clearFileDosen(){
        ofstream in("dataDosen.txt", ios::trunc);
        in.close();
    }
    
    void tampilDosen(){
        cout<<"\n=== Data Dosen ===\n";
        ifstream out;
        out.open("dataDosen.txt");
        string cetak;
        int i=1;
        while(getline(out,cetak)){
            cout << "Dosen ke-" << i << ":" << endl;
            cout<<cetak<<endl;
            i++;
        }
        out.close();

    }

    void editDosen(){
        cout << "=====MENU EDIT DOSEN=====" << endl;
        string nidnCari;
        cout << "Masukkan NIDN dosen yang akan diedit: ";
        cin >> nidnCari;
        bool ditemukan = false;
        for (int i = 0; i < jumlahDosen; i++) {
            if (data[i].nidn == nidnCari) {
                ditemukan = true;
                cout << "Data ditemukan. Masukkan data baru:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                tampilDosen();
                cout << "==============================\n";
                cout << " Masukkan Data Baru: \n";
                cout << "\nMasukkan nama dosen: ";
                cin.ignore();
                getline(cin, data[i].nama);
                cout << "Masukkan NIP:";
                cin >> data[i].nip;
                cout << "Masukkan fakultas:";
                cin >> data[i].fakultas;
                cout << "Masukkan jurusan:";
                cin >> data[i].jurusan;
                cout << "Gelar Depan:";
                cin >> data[i].gelarDepan;
                cout << "Gelar Belakang:";
                cin >> data[i].gelarBelakang;
                cout << "Jabatan Akademik:";
                cin >> data[i].jabatanAkademik;
                cout << "Pendidikan Terakhir:";
                cin >> data[i].pendidikanTerakhir;
                cout << "Email:";
                cin >> data[i].email;
                cout << "No HP:";
                cin >> data[i].noHp;
                cout << "Alamat:";
                cin >> data[i].alamat;
                cout << "Jenis Kelamin (1. Laki-laki, 2. Perempuan):";
                int pilihGender;
                cin >> pilihGender;
                data[i].gender = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;
                cout << "Tahun Masuk:";
                cin >> data[i].tahunMasuk;
                cout << "Status (1. Aktif, 2. Cuti, 3. Pensiun, 4. Tidak Aktif):";
                int pilihStatus;
                cin >> pilihStatus;
                switch(pilihStatus){
                    case 1:
                        data[i].status = StatusDosen::Aktif;
                        break;
                    case 2:
                        data[i].status = StatusDosen::Cuti;
                        break;
                    case 3:
                        data[i].status = StatusDosen::Pensiun;
                        break;
                    case 4:
                        data[i].status = StatusDosen::TidakAktif;
                        break;
                    default:
                        cout<<"Pilihan tidak valid! Mengatur status ke Aktif secara default."<<endl;
                        data[i].status = StatusDosen::Aktif;
                        break;
                }
                cout << "Data dosen berhasil diperbarui!\n";
                break;
            }
        clearFileDosen();
        updateFileDosen();
        }
    }
};

//CLASS UNTUK MENU UTAMA MATAKULIAH
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

        tambahMataKuliahLangsung({"IF101", "Dasar Pemrograman", 3, "Dasar-dasar pemrograman", 1, "Informatika", "FTI",true});
        tambahMataKuliahLangsung({"IF102", "Dasar Sistem Komputer", 3, "Dasar Dasar Komputer", 1, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF103", "Kalkulus Informatika", 3, "Dasar-dasar Perhitungan ", 1, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF104", "Logika Informatika ", 3, "Dasar Logika Pemprograman", 1, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF105", "Manajemen Data dan Informasi", 3, "Dasar Manajemen data", 1, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF106", "Pancasila", 2, "Pemahaman Tata Negara", 1, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF107", "Praktikum Dasar Pempograman", 1, "Praktikum ", 1, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF108", "AL-Qur'an dan Hadits", 2, "Pengertian Al-Qur'an ", 1, "Informatika", "FTI", true});
    
        tambahMataKuliahLangsung({"IF111", "Pemrograman Web", 3, " Dasar Pemprograman Web ", 2, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF112", "Matematika Diskrit", 3, "Perhitungan Berbasis program", 2, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF113", "Bahasa Indonesia", 3, "Penerapan Dasar Bahasa Indonesia", 2, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF114", "Aljabar Linear Matrik", 2, "Perhitungan aljabar", 2, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF115", "Algoritma Pemprograman", 3, "Dasar dasar Pemprograman", 2, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF116", "Aristektur Komputer", 3, "Dasar Susunan komputer", 2, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF117", "Kemuhammadiyahan", 2, "Pembelajaran Muhammadiyah", 2, "Informatika", "FTI",  true});

        tambahMataKuliahLangsung({"IF121", "Algoritma dan Pemrograman", 3, "Dasar-dasar pemrograman", 3, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF122", "Struktur Data", 3, "Pengelolaan data dalam memori", 3, "Informatika", "FTI",   true});
        tambahMataKuliahLangsung({"IF123", "Basis Data", 4, "Dasar-dasar basis data", 3, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF124", "Pemrograman Berorientasi Objek", 3, "Konsep OOP", 3, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF125", "Sistem Operasi", 3, "Operasi Sistem Komputer", 3, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF126", "Bahasa Inggris", 2, "Pembelajarann bahasa Inggris IT", 3, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF127", "Statistika Informatika", 4, "Konsep penerapan statistik ", 3, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF128", "Akidah Akhlak", 2, "Perbaikan Akhlak ", 3, "Informatika", "FTI", true});

        tambahMataKuliahLangsung({"IF131", "AnalisiS Dan Perancangan Perangkat Lunak", 3, "Konsep Perancangan Perangkat Lunak", 4, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF132", "Grafika Komputer", 3, "Penerapan Grafik Komputer", 4, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF133", "Interaksi Manusia dan Komputer", 3, "Interaksi Manusia dan Sistem Komputer", 4, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF134", "Islam Inerdisipliner", 3, "Pengajaran Islam ", 4, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF135", "Kecedarsan Buatan", 3, "Operasi sistem cerdas", 4, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF136", "Komunikasi Data dan Jaringan Komputer", 3, "Komunikasi data jaringan", 4, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF137", "Strategi Algoritma", 3, "Strategi Pemprograman ", 4, "Informatika", "FTI",  true});

        tambahMataKuliahLangsung({"IF141", "Forensik Digital", 3, "Pemeriksa Kasus Digital", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF142", "Keamanan Komputer", 3, "Computer Security", 5, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF143", "Pembelajar Mesin", 3, "Pembelajaran Konsep Mesin Learning", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF144", "Pemprograman Mobile", 3, "Pembuatan Aplikasi Mobile ", 5, "Informatika", "FTI",true});
        tambahMataKuliahLangsung({"IF145", "Pemprograman Web Dinamis", 3, "Pembuatan Web", 5, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF146", "Data Mining", 3, "Penambangan Data", 5, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF147", "Pengantar Manajemen dan Prinsip Proyek", 2, "Penerapan Managemen Konsep Dalam Proyek ", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF148", "Penjaminan Kualitas Perangkat Lunak", 3, "Penjamin Kualitas Perangkat Lunak ", 5, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF149", "Robotika Informatika", 3, "Perancangan Robot", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF150", "Sistem Pendukung Keputusan", 3, "Pendukung Keputusan", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF151", "Sistem Temu Balik Informasi", 3, "Temu Balik ", 5, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF152", "FTI Optimasi", 3, "Optimasi", 5, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF153", "Teori Bahasa Otomata", 2, "Bahasa Otomata ", 5, "Informatika", "FTI",  true});

        tambahMataKuliahLangsung({"IF156", "Manajemen Proyek Teknologi Informasi", 2, "Konsep Perancangan Perangkat Lunak", 6, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF157", "Pengajaran TPQ", 0, "NGaji", 6, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF158", "Tahsinul Quran", 0, "Perbaikan Cara baca AL-Qur'an", 6, "Informatika", "FTI",  true});

        tambahMataKuliahLangsung({"IF161", "Bahasa Inggris Profesional", 2, "Bahasa Internasional", 7, "Informatika", "FTI",true});
        tambahMataKuliahLangsung({"IF162", "Fiqih Ibadah", 0, "Fikih", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF163", "Kapita Selekta", 2, "Kapita Selekta", 7, "Informatika", "FTI",  true});
        tambahMataKuliahLangsung({"IF164", "Kewirausahaan", 2, "Pelatihan Ber wirausahaan ", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF165", "komunikasi Interpersonal", 2, "Komunikasi", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF166", "Pengukuran Arah Kiblat", 0, "Penentu Arah Kiblat", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF167", "Pra Nikah", 0, "Pra Nikah ", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF168", "Praktek Magang", 3, "Magang ", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF169", "Sosio Informatika", 2, "Sosio", 7, "Informatika", "FTI", true});
        tambahMataKuliahLangsung({"IF170", "Kuliah Kerja Nyata", 4, "KKN", 7, "Informatika", "FTI", true});

        tambahMataKuliahLangsung({"IF181", "Skripsi", 6, "Tugas Akhir", 8, "Informatika", "FTI", true});
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

    void hapusMataKuliah(){
        UpdateFileMataKuliah();
        cout<<"=====MENU HAPUS MATA KULIAH====="<<endl;
        string kodeCari;
        cout<<"Masukkan Kode Matakuliah yang akan di hapus :";
        cin>>kodeCari;
        NodeMataKuliah* temp=head;
        NodeMataKuliah* prev=nullptr;
        bool ditemukan=false;

        while(temp!=nullptr){
            if(temp->data.kodeMK==kodeCari){
                ditemukan=true;
                if(prev==nullptr){
                    head=temp->next;
                }else{
                    prev->next=temp->next;
                }
                delete temp;
                cout<<"Mata kuliah dengan kode "<<kodeCari<<" berhasil dihapus."<<endl;
                break;
            }
            prev=temp;
            temp=temp->next;
        }

        if(!ditemukan){
            cout<<"Mata kuliah dengan kode "<<kodeCari<<" tidak ditemukan."<<endl;
        }else{
            UpdateFileMataKuliah();
        }
    }

    void tarikDataDariFileMataKuliah() {
        ifstream inFile("dataMataKuliah.txt");
        if (inFile.is_open()) {
            string line;
            MataKuliah mk;
            while (getline(inFile, line)) {
                if (line.find("Kode :") != string::npos) {
                    mk.kodeMK = line.substr(7); // Ambil nilai setelah "Kode :"
                } else if (line.find("Nama :") != string::npos) {
                    mk.namaMK = line.substr(7);
                }else if (line.find("SKS :") != string::npos) {
                string sksStr = line.substr(5);
                try {
                    mk.sks = stoi(sksStr);
                } catch (...) {
                    mk.sks = 0; // jika error konversi
                }
                } else if (line.find("Deskripsi :") != string::npos) {
                    mk.deskripsi = line.substr(12);
                } else if (line.find("Jurusan :") != string::npos) {
                    mk.jurusan = line.substr(10);
                } else if (line.find("Fakultas :") != string::npos) {
                    mk.fakultas = line.substr(11);
                } else if (line.find("Wajib :") != string::npos) {
                    mk.wajib = (line.substr(8) == "Ya");
                } else if (line.find("------------------------------------------------------") != string::npos) {
                    // Tambahkan mata kuliah ke linked list
                    tambahMataKuliahLangsung(mk);
                }
            }
            inFile.close();
        } else {
            cout << "File dataMataKuliah.txt tidak ditemukan atau gagal dibuka." << endl;
        }
    }

    //update mata kuliah ke file per semester
    void UpdateFileMataKuliah() {
    // Tarik data dari file ke linked list
    tarikDataDariFileMataKuliah();

    // Clear isi file
    clearFileMataKuliah();

    // Tulis ulang data dari linked list ke file
    ofstream outFile("dataMataKuliah.txt");
    if (!outFile.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data mata kuliah." << endl;
        return;
    }

    for (int semester = 1; semester <= 8; semester++) {
        outFile << "====MATA KULIAH SEMESTER " << semester << "====" << endl;
        NodeMataKuliah* temp = head;
        bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->data.semester == semester) {
                outFile << "Kode :" << temp->data.kodeMK << endl;
                outFile << "   Nama :" << temp->data.namaMK << endl;
                outFile << "   SKS :" << temp->data.sks << endl;
                outFile << "   Deskripsi :" << temp->data.deskripsi << endl;
                outFile << "   Jurusan :" << temp->data.jurusan << endl;
                outFile << "   Fakultas :" << temp->data.fakultas << endl;
                outFile << "   Wajib :" << (temp->data.wajib ? "Ya" : "Tidak") << endl;
                outFile << "------------------------------------------------------" << endl;
                ditemukan = true;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            outFile << "Tidak ada mata kuliah untuk semester ini." << endl;
        }
        outFile << endl;
    }

    outFile.close();
    cout << "Data mata kuliah berhasil diperbarui ke file." << endl;
}


    void clearFileMataKuliah(){
        ofstream in("dataMataKuliah.txt", ios::trunc);
        in.close();
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
        cout << "Apakah mata kuliah ini wajib? (1. Ya, 2. Tidak): ";
        int pilihWajib;
        cin >> pilihWajib;
        newNode->data.wajib = (pilihWajib == 1);
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
        UpdateFileMataKuliah();
    }

    void editMataKuliah(){
        cout<<"=====MENU EDIT MATA KULIAH====="<<endl;
        string kodeCari;
        cout<<"Masukkan Kode Matakuliah yang akan di edit :";
        cin>>kodeCari;
        bool ditemukan = false;
        for(NodeMataKuliah* temp=head;temp!=nullptr;temp=temp->next){
            if(temp->data.kodeMK==kodeCari){
                ditemukan=true;
                cout<<"Data di temukan. Masukkan Data baru :\n";
                cout<<"=============================="<<endl;
                cout<<"       DATA SEBELUM NYA       "<<endl;
                cout<<"=============================="<<endl;
                cout<<"Kode :"<<temp->data.kodeMK<<endl;
                cout<<"Nama :"<<temp->data.namaMK<<endl;
                cout<<"SKS :"<<temp->data.sks<<endl;
                cout<<"Deskripsi :"<<temp->data.deskripsi<<endl;
                cout<<"Jurusan :"<<temp->data.jurusan<<endl;
                cout<<"Fakultas :"<<temp->data.fakultas<<endl;
                cout<<"Wajib :"<<(temp->data.wajib ? "Ya" : "Tidak")<<endl;
                cout<<"=============================="<<endl;
                cout<<"\n";
                cout<<"--------------------------------------"<<endl;
                cout<<"           MASUKKAN DATA BARU         "<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Masukkan kode mata kuliah: ";
                cin>>temp->data.kodeMK;
                cout<<"Masukkan nama mata kuliah: ";
                cin.ignore();
                getline(cin, temp->data.namaMK);
                cout<<"Masukkan jumlah SKS: ";
                cin>>temp->data.sks;
                cout<<"Masukkan deskripsi mata kuliah: ";
                cin.ignore();
                getline(cin, temp->data.deskripsi);
                cout<<"Masukkan semester: ";
                cin>>temp->data.semester;
                cout<<"Masukkan jurusan: ";
                cin.ignore();
                getline(cin, temp->data.jurusan);
                cout<<"Masukkan fakultas: ";
                getline(cin, temp->data.fakultas);
                cout<<"Apakah mata kuliah ini wajib? (1. Ya, 2. Tidak): ";
                int pilihWajib;
                cin>>pilihWajib;
                temp->data.wajib = (pilihWajib == 1);
                cout<<"Data mata kuliah berhasil diperbarui!\n";
                break;

            }
            
        }
        UpdateFileMataKuliah();

    }
};

