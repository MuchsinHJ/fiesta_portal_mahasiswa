#include "admin.cpp"
#include <iomanip>
using namespace std;

struct NodeMHS{
    NodeMHS* next;
    NodeMHS* prev;
    Mahasiswa mhs;
};

class DataMahasiswa {
    private :

    public :
    NodeMHS* head = NULL;
    NodeMHS* tail = NULL;

    DataMahasiswa (){

    }

    void TambahMhs(Mahasiswa mhsBaru){
        NodeMHS* newNode = new NodeMHS();
        newNode->mhs = mhsBaru;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void TarikMhsdariFile(){
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
            } else if (line.find("Password: ") != string::npos) {
                mhsSementara.password = line.substr(10);
            } else if (line.find("--------------------------") != string::npos) {
                // Tambahkan ke linked list setiap selesai 1 blok data mahasiswa
                TambahMhs(mhsSementara);
            }

        }
 
        in.close();
    }

    Mahasiswa* cariMahasiswaBynim(string nim) {
        NodeMHS* current = head;
        while (current != NULL) {
            if (current->mhs.nim == nim) {
                return &current->mhs;
            }
            current = current->next;
        }
        
        return NULL; 
    }
    
};






class MahasiswaPortal {
 private:
        DataMahasiswa * mhsDasboard;  
        string username;
        string password;
        Mahasiswa mhsLogin;  

    public:
       
        MahasiswaPortal(DataMahasiswa * mhsData) {
            if (mhsData != NULL) {
                this->mhsDasboard = mhsData;
                this->mhsDasboard->TarikMhsdariFile();
            } else {
                cout << "Error: DataMahasiswa NULL saat inisialisasi!\n";
                this->mhsDasboard = NULL;
            }
            username = "";
            password = "";
        }

       
        bool login(string nim, string password) {
            if (mhsDasboard == NULL) {
                cout << "Error: DataMahasiswa  tidak diinisialisasi\n";
                return false;
            }

          
            Mahasiswa* mhs = mhsDasboard->cariMahasiswaBynim(nim);
            
            if (mhs != NULL && password == mhs->password) {
                this->mhsLogin = *mhs;
                this->username = nim;
                this->password = password;
                cout << "Login berhasil! Selamat datang " << mhs->nama << "\n";
                return true;
            }
            
            cout << "Login gagal! NIM atau password salah\n";
            return false;
        }

        

        void logout() {
            username.clear();
            password.clear();
            cout << "Anda telah logout.\n";
        }

        void tampilProfil() {
            // Validasi: Pengecekan apakah user sudah login
            if (username.empty()) {
                cout << "Error: Anda belum login! Silakan login terlebih dahulu.\n";
                return;
            }

            // Validasi: Ambil data mahasiswa berdasarkan username (NIM) yang login
            Mahasiswa* mhs = mhsDasboard->cariMahasiswaBynim(username);
            
            // Validasi: Pengecekan apakah data ditemukan
            if (mhs == NULL) {
                cout << "Error: Data mahasiswa tidak ditemukan!\n";
                return;
            }

            // Validasi: Pengecekan kecocokan NIM dengan username login
            if (mhs->nim != username) {
                cout << "Error: Data tidak sesuai dengan akun yang login!\n";
                cout << "Username login: " << username << " | NIM di data: " << mhs->nim << endl;
                return;
            }

            // Tampilkan profil jika semua validasi berhasil
            system("cls");
            cout << "\n========================================\n";
            cout << "           PROFIL MAHASISWA            \n";
            cout << "========================================\n\n";
            
            cout << "----------------------------------------\n";
            cout << " Nama              : " << mhs->nama << endl;
            cout << " NIM               : " << mhs->nim << endl;
            cout << " Tempat Lahir      : " << mhs->tempatLahir << endl;
            cout << " Tanggal Lahir     : " << mhs->tanggalLahir << endl;
            cout << " Jenis Kelamin     : " << (mhs->g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << endl;
            cout << " Alamat            : " << mhs->alamat << endl;
            cout << " Email             : " << mhs->email << endl;
            cout << " No HP             : " << mhs->noHp << endl;
            cout << "----------------------------------------\n";
            
            cout << "\nData Akademik:\n";
            cout << "----------------------------------------\n";
            cout << " Fakultas          : " << mhs->fakultas << endl;
            cout << " Jurusan           : " << mhs->jurusan << endl;
            cout << " Semester          : " << mhs->semester << endl;
            cout << " Tahun Masuk       : " << mhs->tahunMasuk << endl;
            cout << " Status            : " << (mhs->aktif ? "Aktif" : "Tidak Aktif") << endl;
            cout << "\n========================================\n";
            
            cout << "\n✓ Data terverifikasi untuk username: " << username << endl;
        }
        void Tagihanmhs(){
            cout << "================================\n";
            cout << "        DATA TAGIHAN MHS        \n";
            cout << "================================\n";
            cout << "Nama: " << mhsLogin.nama << endl;
            cout << "NIM: " << mhsLogin.nim << endl;
            cout << "Tagihan Semester " << mhsLogin.semester << ": Belum ada tagihan\n";
            cout << "================================\n";

        }

        // Getter methods untuk mengakses data mahasiswa yang login
        string getNIMMahasiswa() {
            return username;
        }

        int getSemesterMahasiswa() {
            return mhsLogin.semester;
        }

        Mahasiswa getMahasiswaLogin() {
            return mhsLogin;
        }

        // Cek apakah sudah login
        bool isLogin() {
            return !username.empty();
        }
};

class Perkuliahan {
    public:
        void mataKuliahAktif(Mahasiswa mhsLogin) {
            cout << "================================\n";
            cout << "      MATA KULIAH AKTIF        \n";
            cout << "================================\n";
            cout << "Nama: " << mhsLogin.nama << endl;
            cout << "NIM: " << mhsLogin.nim << endl;
            cout << "Semester: " << mhsLogin.semester << endl;
            cout << "Mata Kuliah Aktif: \n";
            
            cout << "================================\n";
        }
};


class KRSKHS{
private:
    struct KRSData {
        string nimMahasiswa;
        string kdDosenMk;
        string semesterDiambil;
        char nilaiHuruf;
        float nilaiAngka;
    };
    
    DoubleLinkedList<KRSData> listKRS;
    
    ManajemenMatakuliah* mataKuliah;
    ManajemenDosenMataKuliah* dosenMataKuliah;
    ManajemenKelas* kelas;
    
public:
    KRSKHS(ManajemenMatakuliah* mk, ManajemenDosenMataKuliah* dmk, ManajemenKelas* k) {
        this->mataKuliah = mk;
        this->dosenMataKuliah = dmk;
        this->kelas = k;
        bacaKRSdariFile();
    }

    // Baca data KRS dari file
    void bacaKRSdariFile() {
        ifstream file("dataKRS.txt");
        if (!file.is_open()) {
            return;
        }
        
        string line;
        KRSData krsTemp;
        
        while (getline(file, line)) {
            if (line.find("NIM: ") != string::npos) {
                krsTemp.nimMahasiswa = line.substr(5);
            } else if (line.find("Kode Dosen MK: ") != string::npos) {
                krsTemp.kdDosenMk = line.substr(15);
            } else if (line.find("Semester: ") != string::npos) {
                krsTemp.semesterDiambil = line.substr(10);
            } else if (line.find("Nilai Huruf: ") != string::npos) {
                string nilai = line.substr(13);
                krsTemp.nilaiHuruf = nilai.empty() ? '-' : nilai[0];
            } else if (line.find("Nilai Angka: ") != string::npos) {
                string nilaiStr = line.substr(13);
                // Trim whitespace
                nilaiStr.erase(0, nilaiStr.find_first_not_of(" \t\r\n"));
                nilaiStr.erase(nilaiStr.find_last_not_of(" \t\r\n") + 1);
                try {
                    krsTemp.nilaiAngka = nilaiStr.empty() ? 0.0f : stof(nilaiStr);
                } catch (...) {
                    krsTemp.nilaiAngka = 0.0f;
                }
            } else if (line.find("---") != string::npos) {
                tambahKRS(krsTemp);
            }
        }
        file.close();
    }

    // Simpan KRS ke file
    void simpanKRSkeFile() {
        ofstream file("dataKRS.txt");
        if (!file.is_open()) {
            cout << "Error: Tidak dapat membuka file dataKRS.txt\n";
            return;
        }
        
        DoubleLinkedList<KRSData>::Node* current = listKRS.head;
        while (current != nullptr) {
            file << "NIM: " << current->data.nimMahasiswa << endl;
            file << "Kode Dosen MK: " << current->data.kdDosenMk << endl;
            file << "Semester: " << current->data.semesterDiambil << endl;
            file << "Nilai Huruf: " << current->data.nilaiHuruf << endl;
            file << "Nilai Angka: " << current->data.nilaiAngka << endl;
            file << "----------------------------" << endl;
            current = current->next;
        }
        file.close();
    }

    // Tambah KRS ke linked list
    void tambahKRS(KRSData krsData) {
        listKRS.tambahData(krsData);
    }

    // Tampilkan mata kuliah yang tersedia dengan dosen dan kelas
    void tampilMataKuliahTersedia(int semesterMhs) {
        cout << "\n==========================================================\n";
        cout << "     DAFTAR MATA KULIAH TERSEDIA SEMESTER " << semesterMhs << "            ║\n";
        cout << "==========================================================\n\n";
        
        // Tampilkan mata kuliah dari ManajemenMatakuliah
        cout << "Daftar mata kuliah semester " << semesterMhs << ":\n";
        cout << "Silakan gunakan menu admin untuk melihat detail mata kuliah.\n";
    }

    // Cek apakah mahasiswa sudah mengambil mata kuliah
    bool sudahAmbilMK(string nim, string kdDosenMk) {
        DoubleLinkedList<KRSData>::Node* current = listKRS.head;
        while (current != nullptr) {
            if (current->data.nimMahasiswa == nim && 
                current->data.kdDosenMk == kdDosenMk) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Hitung total SKS yang sudah diambil mahasiswa
    int hitungTotalSKS(string nim, string semester) {
        int totalSKS = 0;
        DoubleLinkedList<KRSData>::Node* current = listKRS.head;
        
        while (current != nullptr) {
            if (current->data.nimMahasiswa == nim && 
                current->data.semesterDiambil == semester) {
                // Ambil SKS dari mata kuliah
                // Ini memerlukan method tambahan di ManajemenMatakuliah
                totalSKS += 3; // Sementara default 3 SKS
            }
            current = current->next;
        }
        return totalSKS;
    }

    // Menu KRS Mahasiswa
    void menuKRS(string nim, int semesterMhs) {
        system("cls");
        cout << "\n==========================================================\n";
        cout << "           KARTU RENCANA STUDI (KRS)                  \n";
        cout << "==========================================================\n\n";
        
        cout << "NIM: " << nim << " | Semester: " << semesterMhs << endl;
        cout << "\n1. Lihat Mata Kuliah Tersedia\n";
        cout << "2. Ambil Mata Kuliah (Isi KRS)\n";
        cout << "3. Lihat KRS Saya\n";
        cout << "4. Hapus Mata Kuliah dari KRS\n";
        cout << "5. Kembali\n";
        cout << "\nPilih: ";
        
        int pilihan;
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1:
                tampilMataKuliahTersedia(semesterMhs);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                menuKRS(nim, semesterMhs);
                break;
            case 2:
                isiKRS(nim, semesterMhs);
                menuKRS(nim, semesterMhs);
                break;
            case 3:
                tampilKRSMahasiswa(nim);
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.get();
                menuKRS(nim, semesterMhs);
                break;
            case 4:
                hapusKRS(nim);
                menuKRS(nim, semesterMhs);
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid!\n";
                menuKRS(nim, semesterMhs);
                break;
        }
    }

    // Isi KRS
    void isiKRS(string nim, int semesterMhs) {
        system("cls");
        cout << "\n==========================================================\n";
        cout << "              PENGISIAN KRS                            \n";
        cout << "==========================================================\n\n";
        
        // Cek total SKS yang sudah diambil
        string semesterStr = "Ganjil 2024/2025";
        int totalSKS = hitungTotalSKS(nim, semesterStr);
        int maxSKS = 24; // Batas maksimal SKS
        
        cout << "Total SKS saat ini: " << totalSKS << "/" << maxSKS << endl;
        
        if (totalSKS >= maxSKS) {
            cout << "\nAnda sudah mencapai batas maksimal SKS!\n";
            cout << "Tekan Enter untuk kembali...";
            cin.get();
            return;
        }
        
        // Tampilkan mata kuliah dengan dosen
        cout << "\n--- Pilih Mata Kuliah ---\n";
        dosenMataKuliah->tampilSemuaDosenMataKuliah();
        
        cout << "\nMasukkan Kode Dosen-Mata Kuliah (misal: DMK001): ";
        string kdDosenMk;
        cin >> kdDosenMk;
        cin.ignore();
        
        // Validasi apakah sudah diambil
        if (sudahAmbilMK(nim, kdDosenMk)) {
            cout << "\nAnda sudah mengambil mata kuliah ini!\n";
            cout << "Tekan Enter untuk melanjutkan...";
            cin.get();
            return;
        }
        
        // Konfirmasi
        cout << "\nApakah Anda yakin ingin mengambil mata kuliah ini? (y/n): ";
        char konfirmasi;
        cin >> konfirmasi;
        cin.ignore();
        
        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            KRSData krsData;
            krsData.nimMahasiswa = nim;
            krsData.kdDosenMk = kdDosenMk;
            krsData.semesterDiambil = semesterStr;
            krsData.nilaiHuruf = '-';
            krsData.nilaiAngka = 0.0f;
            
            tambahKRS(krsData);
            simpanKRSkeFile();
            
            cout << "\n✓ Berhasil menambahkan mata kuliah ke KRS!\n";
        } else {
            cout << "\nPengisian KRS dibatalkan.\n";
        }
        
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }

    // Tampilkan KRS Mahasiswa
    void tampilKRSMahasiswa(string nim) {
        system("cls");
        cout << "\n============================================================================\n";
        cout << "|                KARTU RENCANA STUDI (KRS) MAHASISWA                        |  \n";
        cout << " ===========================================================================\n\n";
        
        cout << "NIM      : " << nim << endl;
        cout << "Semester : Ganjil 2024/2025\n\n";
        
        DoubleLinkedList<KRSData>::Node* current = listKRS.head;
        int no = 1;
        int totalSKS = 0;
        bool adaData = false;
        
        cout << " ===================================================================================\n";
        cout << "| No |   Kode MK   |      Nama Mata Kuliah      |     Nama Dosen     |SKS| Status   |\n";
        cout << " ===================================================================================\n";
        
        while (current != nullptr) {
            if (current->data.nimMahasiswa == nim) {
                // Cari informasi dosen dan mata kuliah dari kdDosenMk
                string kodeMK = "";
                string nidnDosen = "";
                string namaMK = "Mata Kuliah";
                string namaDosen = "Dosen";
                int sks = 3;
                
                // Baca file DosenMataKuliah untuk mendapatkan kodeMK dan nidn
                ifstream fileDMK("dataDosenMataKuliah.txt");
                if (fileDMK.is_open()) {
                    string lineDMK;
                    string kdDosenMkTemp = "";
                    while (getline(fileDMK, lineDMK)) {
                        if (lineDMK.find("Kode Dosen-MK: ") != string::npos) {
                            kdDosenMkTemp = lineDMK.substr(15);
                        } else if (lineDMK.find("NIDN Dosen: ") != string::npos && kdDosenMkTemp == current->data.kdDosenMk) {
                            nidnDosen = lineDMK.substr(12);
                        } else if (lineDMK.find("Kode Mata Kuliah: ") != string::npos && kdDosenMkTemp == current->data.kdDosenMk) {
                            kodeMK = lineDMK.substr(18);
                            break;
                        }
                    }
                    fileDMK.close();
                }
                
                // Baca file MataKuliah untuk mendapatkan nama dan SKS
                if (!kodeMK.empty()) {
                    ifstream fileMK("dataMataKuliah.txt");
                    if (fileMK.is_open()) {
                        string lineMK;
                        string kodeTemp = "";
                        while (getline(fileMK, lineMK)) {
                            if (lineMK.find("Kode MK: ") != string::npos) {
                                kodeTemp = lineMK.substr(9);
                            } else if (lineMK.find("Nama MK: ") != string::npos && kodeTemp == kodeMK) {
                                namaMK = lineMK.substr(9);
                                if (namaMK.length() > 25) namaMK = namaMK.substr(0, 22) + "...";
                            } else if (lineMK.find("SKS: ") != string::npos && kodeTemp == kodeMK) {
                                sks = stoi(lineMK.substr(5));
                                break;
                            }
                        }
                        fileMK.close();
                    }
                }
                
                // Baca file Dosen untuk mendapatkan nama dosen
                if (!nidnDosen.empty()) {
                    ifstream fileDosen("dataDosen.txt");
                    if (fileDosen.is_open()) {
                        string lineDosen;
                        string nidnTemp = "";
                        while (getline(fileDosen, lineDosen)) {
                            if (lineDosen.find("NIDN: ") != string::npos) {
                                nidnTemp = lineDosen.substr(6);
                            } else if (lineDosen.find("Nama: ") != string::npos && nidnTemp == nidnDosen) {
                                namaDosen = lineDosen.substr(6);
                                if (namaDosen.length() > 18) namaDosen = namaDosen.substr(0, 15) + "...";
                                break;
                            }
                        }
                        fileDosen.close();
                    }
                }
                
                cout << "║ " << setw(2) << no << " ║ " 
                     << setw(11) << kodeMK << " ║ "
                     << setw(26) << namaMK << " ║ "
                     << setw(18) << namaDosen << " ║" 
                     << setw(3) << sks << "║ Aktif    ║\n";
                totalSKS += sks;
                no++;
                adaData = true;
            }
            current = current->next;
        }
        
        cout << " ===================================================================================\n";
        
        if (!adaData) {
            cout << "\nBelum ada mata kuliah yang diambil.\n";
        } else {
            cout << "\nTotal Mata Kuliah : " << (no - 1) << endl;
            cout << "Total SKS        : " << totalSKS << " SKS\n\n";
            
            cout << "Status: AKTIF\n";
        }
    }

    // Cetak KRS - Membaca dari file tanpa vector
    void cetakKRS(string nim) {
        system("cls");
        cout << " __________________________________________________________\n";
        cout << "|             CETAK KARTU RENCANA STUDI (KRS)              |\n";
        cout << "|__________________________________________________________|\n\n";
        
        // Baca data dari file menggunakan array
        ifstream file("dataKRS.txt");
        if (!file.is_open()) {
            cout << "Error: Tidak dapat membuka file dataKRS.txt\n";
            cout << "Pastikan Anda sudah mengisi KRS terlebih dahulu.\n";
            return;
        }
        
        // Array untuk menyimpan data sementara (maksimal 50 mata kuliah)
        KRSData daftarKRS[50];
        int jumlahData = 0;
        
        string line;
        KRSData krsTemp;
        bool sedangBacaNIM = false;
        
        // Baca file dan filter berdasarkan NIM
        while (getline(file, line) && jumlahData < 50) {
            if (line.find("NIM: ") != string::npos) {
                krsTemp.nimMahasiswa = line.substr(5);
                sedangBacaNIM = true;
            } else if (line.find("Kode Dosen MK: ") != string::npos && sedangBacaNIM) {
                krsTemp.kdDosenMk = line.substr(15);
            } else if (line.find("Semester: ") != string::npos && sedangBacaNIM) {
                krsTemp.semesterDiambil = line.substr(10);
            } else if (line.find("Nilai Huruf: ") != string::npos && sedangBacaNIM) {
                string nilai = line.substr(13);
                krsTemp.nilaiHuruf = nilai.empty() ? '-' : nilai[0];
            } else if (line.find("Nilai Angka: ") != string::npos && sedangBacaNIM) {
                string nilaiStr = line.substr(13);
                krsTemp.nilaiAngka = nilaiStr.empty() ? 0.0f : stof(nilaiStr);
            } else if (line.find("---") != string::npos && sedangBacaNIM) {
                // Simpan data jika NIM sesuai
                if (krsTemp.nimMahasiswa == nim) {
                    daftarKRS[jumlahData] = krsTemp;
                    jumlahData++;
                }
                sedangBacaNIM = false;
            }
        }
        file.close();
        
        // Cek apakah ada data
        if (jumlahData == 0) {
            cout << "Tidak ada data KRS untuk NIM: " << nim << endl;
            cout << "Silakan isi KRS terlebih dahulu.\n";
            return;
        }
        
        // Tampilkan header cetak KRS
        cout << " __________________________________________________________\n";
        cout << "│                   UNIVERSITAS AHMAD DAHLAN               |\n";
        cout << "│                 FAKULTAS TEKNOLOGI INDUSTRI              |\n";
        cout << "│                  KARTU RENCANA STUDI (KRS)               |\n";
        cout << "│                  Semester Ganjil 2024/2025               |\n";
        cout << "|__________________________________________________________|\n\n";
        
        cout << "NIM           : " << nim << endl;
        cout << "Tanggal Cetak : 14 Desember 2025" << endl;
        cout << "\n";
        
        // Tampilkan daftar mata kuliah dengan informasi lengkap
        cout << " =============================================================================\n";
        cout << "| No | Kode MK    | Nama Mata Kuliah          | Nama Dosen              | SKS |\n";
        cout << " =============================================================================\n";
        
        int totalSKS = 0;
        for (int i = 0; i < jumlahData; i++) {
            // Cari informasi dosen dan mata kuliah dari kdDosenMk
            string kodeMK = "";
            string nidnDosen = "";
            string namaMK = "Mata Kuliah";
            string namaDosen = "Dosen";
            int sks = 3;
            
            // Baca file DosenMataKuliah untuk mendapatkan kodeMK dan nidn
            ifstream fileDMK("dataDosenMataKuliah.txt");
            if (fileDMK.is_open()) {
                string lineDMK;
                string kdDosenMkTemp = "";
                while (getline(fileDMK, lineDMK)) {
                    if (lineDMK.find("Kode Dosen-MK: ") != string::npos) {
                        kdDosenMkTemp = lineDMK.substr(15);
                    } else if (lineDMK.find("NIDN Dosen: ") != string::npos && kdDosenMkTemp == daftarKRS[i].kdDosenMk) {
                        nidnDosen = lineDMK.substr(12);
                    } else if (lineDMK.find("Kode Mata Kuliah: ") != string::npos && kdDosenMkTemp == daftarKRS[i].kdDosenMk) {
                        kodeMK = lineDMK.substr(18);
                        break;
                    }
                }
                fileDMK.close();
            }
            
            // Baca file MataKuliah untuk mendapatkan nama dan SKS
            if (!kodeMK.empty()) {
                ifstream fileMK("dataMataKuliah.txt");
                if (fileMK.is_open()) {
                    string lineMK;
                    string kodeTemp = "";
                    while (getline(fileMK, lineMK)) {
                        if (lineMK.find("Kode MK: ") != string::npos) {
                            kodeTemp = lineMK.substr(9);
                        } else if (lineMK.find("Nama MK: ") != string::npos && kodeTemp == kodeMK) {
                            namaMK = lineMK.substr(9);
                            if (namaMK.length() > 25) namaMK = namaMK.substr(0, 22) + "...";
                        } else if (lineMK.find("SKS: ") != string::npos && kodeTemp == kodeMK) {
                            sks = stoi(lineMK.substr(5));
                            break;
                        }
                    }
                    fileMK.close();
                }
            }
            
            // Baca file Dosen untuk mendapatkan nama dosen
            if (!nidnDosen.empty()) {
                ifstream fileDosen("dataDosen.txt");
                if (fileDosen.is_open()) {
                    string lineDosen;
                    string nidnTemp = "";
                    while (getline(fileDosen, lineDosen)) {
                        if (lineDosen.find("NIDN: ") != string::npos) {
                            nidnTemp = lineDosen.substr(6);
                        } else if (lineDosen.find("Nama: ") != string::npos && nidnTemp == nidnDosen) {
                            namaDosen = lineDosen.substr(6);
                            if (namaDosen.length() > 23) namaDosen = namaDosen.substr(0, 20) + "...";
                            break;
                        }
                    }
                    fileDosen.close();
                }
            }
            
            cout << "║ " << setw(2) << (i+1) << " ║ " 
                 << setw(10) << kodeMK << " ║ "
                 << setw(25) << namaMK << " ║ "
                 << setw(23) << namaDosen << " ║ "
                 << setw(3) << sks << " ║\n";
            totalSKS += sks;
        }
        
        cout << " =============================================================================\n";
        cout << "\nTotal Mata Kuliah: " << jumlahData << endl;
        cout << "Total SKS        : " << totalSKS << " SKS" << endl;
        cout << "\n";
        
        // Footer
        cout << " __________________________________________________________\n";
        cout << "| Catatan:                                                 |\n";
        cout << "| - KRS ini sah apabila sudah mendapat persetujuan dosen   |\n";
        cout << "| - Batas pengisian/perubahan KRS sesuai kalender akademik |\n";
        cout << "| - Simpan KRS ini sebagai bukti pengisian                 |\n";
        cout << "|__________________________________________________________|\n";
        
        cout << "\n✓ KRS berhasil dicetak dari file dataKRS.txt\n";
    }

    // Hapus mata kuliah dari KRS
    void hapusKRS(string nim) {
        system("cls");
        cout << "\n==========================================================\n";
        cout << "           HAPUS MATA KULIAH DARI KRS                    \n";
        cout << "==========================================================\n\n";
        
        tampilKRSMahasiswa(nim);
        
        cout << "\nMasukkan Kode Dosen-Mata Kuliah yang ingin dihapus: ";
        string kdDosenMk;
        cin >> kdDosenMk;
        cin.ignore();
        
        // Cari index data yang akan dihapus
        size_t index = 0;
        bool ditemukan = false;
        DoubleLinkedList<KRSData>::Node* current = listKRS.head;
        
        while (current != nullptr) {
            if (current->data.nimMahasiswa == nim && 
                current->data.kdDosenMk == kdDosenMk) {
                ditemukan = true;
                break;
            }
            current = current->next;
            index++;
        }
        
        if (ditemukan) {
            listKRS.hapusData(index);
            simpanKRSkeFile();
            cout << "\n✓ Mata kuliah berhasil dihapus dari KRS!\n";
        } else {
            cout << "\n✗ Mata kuliah tidak ditemukan dalam KRS Anda!\n";
        }
        
        cout << "Tekan Enter untuk melanjutkan...";
        cin.get();
    }
};



