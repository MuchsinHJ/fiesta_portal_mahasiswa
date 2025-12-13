#include "admin.cpp"
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
       
        MahasiswaPortal(DataMahasiswa * mhsDasboard) {
            this->mhsDasboard = mhsDasboard;
            mhsDasboard->TarikMhsdariFile();
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



