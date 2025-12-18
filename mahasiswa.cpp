#include "admin.cpp"
#include <iomanip>
#include <cctype>
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
            system("pause");


        }

        void tampilProfil() {
            if (username.empty()) {
                cout << "Error: Anda belum login! Silakan login terlebih dahulu.\n";
                return;
            }

            Mahasiswa* mhs = mhsDasboard->cariMahasiswaBynim(username);
      
            if (mhs == NULL) {
                cout << "Error: Data mahasiswa tidak ditemukan!\n";
                return;
            }

            if (mhs->nim != username) {
                cout << "Error: Data tidak sesuai dengan akun yang login!\n";
                cout << "Username login: " << username << " | NIM di data: " << mhs->nim << endl;
                return;
            }

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
    int jumlah=0;
    
    DoubleLinkedList<KRSData> listKRS;
    
    ManajemenMatakuliah* mataKuliah;
    ManajemenDosenMataKuliah* dosenMataKuliah;
    ManajemenKelas* kelas;
    ManajemenKelasMahasiswa* kelasMahasiswa;
    ManajemenKrs* manajemenKrs;
    MahasiswaPortal* mhsPortal;
    
public:

    KRSKHS(ManajemenMatakuliah* mk, ManajemenDosenMataKuliah* dmk, ManajemenKelas* k) {
        this->mataKuliah = mk;
        this->dosenMataKuliah = dmk;
        this->kelas = k;
        this->kelasMahasiswa = nullptr;
        this->manajemenKrs = nullptr;
        this->mhsPortal = nullptr;
    }

    // Set manager pointers setelah objek dibuat
    void setManagers(ManajemenKelasMahasiswa* km, ManajemenKrs* mkrs) {
        this->kelasMahasiswa = km;
        this->manajemenKrs = mkrs;
    }

    void setMahasiswaPortal(MahasiswaPortal* portal) {
        this->mhsPortal = portal;
    }

    string cariKelasMahasiswa(const string& nim) {
        ifstream in("dataKelasMahasiswa.txt");
        if (!in.is_open()) return "";
        string line;
        string currentKelas = "";
        while (getline(in, line)) {
            if (line.find("Kode Kelas: ") != string::npos) {
                currentKelas = line.substr(12);
                // trim both ends (space, CR, LF, tab)
                while (!currentKelas.empty() && (currentKelas.front() == ' ' || currentKelas.front() == '\r' || currentKelas.front() == '\n' || currentKelas.front() == '\t')) currentKelas.erase(0,1);
                while (!currentKelas.empty() && (currentKelas.back() == ' ' || currentKelas.back() == '\r' || currentKelas.back() == '\n' || currentKelas.back() == '\t')) currentKelas.pop_back();
            } else if (line.find("NIM Mahasiswa: ") != string::npos) {
                string nimLine = line.substr(15);
                if (nimLine == nim) {
                    in.close();
                    return currentKelas;
                }
            }
        }
        in.close();
        return "";
    }



    void TampilDosenMatakuliahKrs(const string& nim) {
        system("cls");
        cout<<string(82,'=')<<endl;
        cout << "                   ================ KRS MAHASISWA ================                      "<<endl;
        cout<<string(82,'=')<<endl;
        cout << "NIM: " << nim << "\n";

        string kdKelas = cariKelasMahasiswa(nim);
        if (kdKelas.empty()) {
            cout << "Mahasiswa belum terdaftar dalam kelas mana pun.\n\n";
            system("pause");
            return;
        }
        cout << "Kelas: " << kdKelas << "\n\n";

        cout << left << setw(6) << "No"
             << setw(12) << "Kode MK"
             << setw(34) << "Nama Mata Kuliah"
             << setw(24) << "Nama Dosen"
             << "SKS" << "\n";
        cout << string(82, '-') << "\n";

        ifstream inFile("dataKrs.txt");
        if (!inFile.is_open()) {
            cout << "Gagal membuka file dataKrs.txt\n\n";
            system("pause");
            return;
        }

        string line;
        string currentKelas;
        bool adaData = false;
        int no = 1;

        while (getline(inFile, line)) {
            if (line.find("Kode Kelas Mahasiswa:") != string::npos) {
                size_t pos = line.find(":");
                currentKelas = (pos != string::npos) ? line.substr(pos+1) : string();
                while (!currentKelas.empty() && isspace((unsigned char)currentKelas.front())) currentKelas.erase(0,1);
                while (!currentKelas.empty() && isspace((unsigned char)currentKelas.back())) currentKelas.pop_back();
            } else if (line.find("Kode Dosen Mata Kuliah:") != string::npos) {
                size_t pos = line.find(":");
                string kd = (pos != string::npos) ? line.substr(pos+1) : string();
                while (!kd.empty() && isspace((unsigned char)kd.front())) kd.erase(0,1);
                while (!kd.empty() && isspace((unsigned char)kd.back())) kd.pop_back();

                if (currentKelas == kdKelas) {
                    adaData = true;

                    string kodeMK;
                    string nidn;
                    {
                        ifstream fdmk("dataDosenMataKuliah.txt");
                        if (fdmk.is_open()) {
                            string dmkLine;
                            string curKodeMK;
                            string curNidn;
                            bool matchBlock = false;
                            while (getline(fdmk, dmkLine)) {
                                if (dmkLine.find("Kode MK") != string::npos && dmkLine.find(":") != string::npos) {
                                    size_t pos = dmkLine.find(":");
                                    curKodeMK = dmkLine.substr(pos+1);
                                    while (!curKodeMK.empty() && isspace((unsigned char)curKodeMK.front())) curKodeMK.erase(0,1);
                                    while (!curKodeMK.empty() && isspace((unsigned char)curKodeMK.back())) curKodeMK.pop_back();
                                } else if (dmkLine.find("NIDN Dosen") != string::npos && dmkLine.find(":") != string::npos) {
                                    size_t pos = dmkLine.find(":");
                                    curNidn = dmkLine.substr(pos+1);
                                    while (!curNidn.empty() && isspace((unsigned char)curNidn.front())) curNidn.erase(0,1);
                                    while (!curNidn.empty() && isspace((unsigned char)curNidn.back())) curNidn.pop_back();
                                } else if (dmkLine.find("Kode Dosen MK") != string::npos && dmkLine.find(":") != string::npos) {
                                    size_t pos = dmkLine.find(":");
                                    string curKd = dmkLine.substr(pos+1);
                                    while (!curKd.empty() && isspace((unsigned char)curKd.front())) curKd.erase(0,1);
                                    while (!curKd.empty() && isspace((unsigned char)curKd.back())) curKd.pop_back();
                                    // mark this block matched
                                    matchBlock = (curKd == kd);
                                } else if (dmkLine.find("----------------------------------------") != string::npos) {
                                    if (matchBlock) {
                                        kodeMK = curKodeMK;
                                        nidn = curNidn;
                                        break;
                                    }
                                    // reset for next block
                                    curKodeMK.clear();
                                    curNidn.clear();
                                    matchBlock = false;
                                }
                            }
                            fdmk.close();
                        }
                    }

                    string namaMK = "-";
                    string Sksmk = "-";
                    {
                        ifstream fm("dataMataKuliah.txt");
                        if (fm.is_open()) {
                            string mline;
                            string currentKode;
                            string currentNama;
                            string currentSks;
                            bool matchBlock = false;
                            
                            while (getline(fm, mline)) {
                                if (mline.find("Kode :") != string::npos) {
                                    currentKode = mline.substr(mline.find("Kode :") + 6);
                                    while (!currentKode.empty() && isspace((unsigned char)currentKode.front())) currentKode.erase(0,1);
                                    while (!currentKode.empty() && isspace((unsigned char)currentKode.back())) currentKode.pop_back();
                                    matchBlock = (!currentKode.empty() && currentKode == kodeMK);

                                } else if (mline.find("Nama :") != string::npos) {
                                    currentNama = mline.substr(mline.find("Nama :") + 6);
                                    while (!currentNama.empty() && isspace((unsigned char)currentNama.front())) currentNama.erase(0,1);
                                    while (!currentNama.empty() && isspace((unsigned char)currentNama.back())) currentNama.pop_back();
                                    if (matchBlock) namaMK = currentNama;

                                } else if (mline.find("SKS :") != string::npos) {
                                    currentSks = mline.substr(mline.find("SKS :") + 5);
                                    while (!currentSks.empty() && isspace((unsigned char)currentSks.front())) currentSks.erase(0,1);
                                    while (!currentSks.empty() && isspace((unsigned char)currentSks.back())) currentSks.pop_back();  
                                    if (matchBlock) Sksmk = currentSks;
                                    
                                } else if (mline.find("------------------------------------------------------") != string::npos) {
                                   
                                    if (matchBlock && !namaMK.empty() && Sksmk != "-") {
                                        break;
                                    }
                                   
                                    currentKode.clear();
                                    currentNama.clear();
                                    currentSks.clear();
                                    matchBlock = false;
                                }
                            }
                            fm.close();
                        }
                    }

                    string namaDosen = "-";
                    {
                        ifstream fd("dataDosen.txt");
                        if (fd.is_open()) {
                            string dline;
                            string currentNama;
                            string currentNidn;
                            
                            while (getline(fd, dline)) {
                                if (dline.find("Nama: ") != string::npos) {
                                    currentNama = dline.substr(6);
                                    while (!currentNama.empty() && isspace((unsigned char)currentNama.front())) currentNama.erase(0,1);
                                    while (!currentNama.empty() && isspace((unsigned char)currentNama.back())) currentNama.pop_back();
                                } else if (dline.find("NIDN: ") != string::npos) {
                                    currentNidn = dline.substr(6);
                                    while (!currentNidn.empty() && isspace((unsigned char)currentNidn.front())) currentNidn.erase(0,1);
                                    while (!currentNidn.empty() && isspace((unsigned char)currentNidn.back())) currentNidn.pop_back();
                                    if (!currentNidn.empty() && currentNidn == nidn) {
                                        namaDosen = currentNama;
                                        break;
                                    }
                                } else if (dline.find("-------------------------------------") != string::npos) {
                                    currentNama.clear();
                                    currentNidn.clear();
                                }
                            }
                            fd.close();
                        }
                    }

                    cout << left << setw(6) << no++
                         << setw(12) << (kodeMK.empty() ? "-" : kodeMK)
                         << setw(34) << (namaMK.empty() ? "-" : namaMK)
                         << setw(24) << (namaDosen.empty() ? "-" : namaDosen)
                         << (Sksmk.empty() ? "-":Sksmk) << "\n";
                }
            }
        }
        inFile.close();

        if (!adaData) {
            cout << "(Tidak ada data KRS untuk kelas ini)\n";
        }
           cout << "===================================================================================\n\n";
        
        ifstream dp("dataPengajuanKrs.txt");
        if( dp.is_open()) {
            string line;
            bool found = false;
            while (getline(dp, line)) {
                if (line.find("NIM: ") != string::npos) {
                    string nimLine = line.substr(5);
                    if (nimLine == nim) {
                        found = true;
                        break;
                    }
                }
            }
            dp.close();
            if (found) {
                cout << "\n";
                cout << " ______________________________________________________________________\n";
                cout << "|                                                                      |\n";
                cout << "|                   SISTEM KRS (Kartu Rencana Studi)                   |\n";
                cout << "|                     SUDAH AKTIF & SIAP DIGUNAKAN                     |\n";
                cout << "|                                                                      |\n";
                cout << " ======================================================================\n";
                cout << "\n";
            }else{
                if (adaData) {
                    cout << " ___________________________________________________________________\n";
                    cout << "|                                                                   |\n";
                    cout << "|    Silakan ajukan KRS Anda sekarang!                              |\n";
                    cout << "|    Pastikan mengajukan sebelum batas waktu yang ditentukan        |\n";
                    cout << "|    KRS yang sudah diajukan akan divalidasi oleh admin             |\n";
                    cout << "|                                                                   |\n";
                    cout << " ===================================================================\n";
                    char konfirmasi;
                    cout << "Apakah Anda ingin mengajukan KRS ini? (Y/N): ";
                    cin >> konfirmasi;
                    
                    if (konfirmasi == 'Y' || konfirmasi == 'y') {
                        if (!mhsPortal || !mhsPortal->isLogin()) {
                            cout << "Error: Tidak ada mahasiswa yang login.\n";
                            system("pause");
                            return;
                        }
                        
                        Mahasiswa mhs = mhsPortal->getMahasiswaLogin();

                        ofstream outFile("dataPengajuanKrs.txt", ios::app);
                        if (outFile.is_open()) {
                            outFile << "Nama: " << mhs.nama << "\n";
                            outFile << "NIM: " << mhs.nim << "\n";
                            outFile << "Mata Kuliah: ";

                            ifstream inFile2("dataKrs.txt");
                            if (inFile2.is_open()) {
                                string line2;
                                string currentKelas2;
                                bool pertama = true;
                                
                                while (getline(inFile2, line2)) {
                                    if (line2.find("Kode Kelas Mahasiswa:") != string::npos) {
                                        size_t pos = line2.find(":");
                                        currentKelas2 = (pos != string::npos) ? line2.substr(pos+1) : string();
                                        while (!currentKelas2.empty() && isspace((unsigned char)currentKelas2.front())) currentKelas2.erase(0,1);
                                        while (!currentKelas2.empty() && isspace((unsigned char)currentKelas2.back())) currentKelas2.pop_back();
                                    } else if (line2.find("Kode Dosen Mata Kuliah:") != string::npos && currentKelas2 == kdKelas) {
                                        size_t pos = line2.find(":");
                                        string kd = (pos != string::npos) ? line2.substr(pos+1) : string();
                                        while (!kd.empty() && isspace((unsigned char)kd.front())) kd.erase(0,1);
                                        while (!kd.empty() && isspace((unsigned char)kd.back())) kd.pop_back();
        
                                        string kodeMK2, namaMK2;
        
                                        ifstream fdmk2("dataDosenMataKuliah.txt");
                                        if (fdmk2.is_open()) {
                                            string dmkLine2;
                                            string curKodeMK2, curKd2;
                                            bool matchBlock2 = false;
                                            
                                            while (getline(fdmk2, dmkLine2)) {
                                                if (dmkLine2.find("Kode MK") != string::npos && dmkLine2.find(":") != string::npos) {
                                                    size_t pos2 = dmkLine2.find(":");
                                                    curKodeMK2 = dmkLine2.substr(pos2+1);
                                                    while (!curKodeMK2.empty() && isspace((unsigned char)curKodeMK2.front())) curKodeMK2.erase(0,1);
                                                    while (!curKodeMK2.empty() && isspace((unsigned char)curKodeMK2.back())) curKodeMK2.pop_back();
                                                } else if (dmkLine2.find("Kode Dosen MK") != string::npos && dmkLine2.find(":") != string::npos) {
                                                    size_t pos2 = dmkLine2.find(":");
                                                    string curKd2 = dmkLine2.substr(pos2+1);
                                                    while (!curKd2.empty() && isspace((unsigned char)curKd2.front())) curKd2.erase(0,1);
                                                    while (!curKd2.empty() && isspace((unsigned char)curKd2.back())) curKd2.pop_back();
                                                    matchBlock2 = (curKd2 == kd);
                                                } else if (dmkLine2.find("----------------------------------------") != string::npos) {
                                                    if (matchBlock2) {
                                                        kodeMK2 = curKodeMK2;
                                                        break;
                                                    }
                                                    curKodeMK2.clear();
                                                    matchBlock2 = false;
                                                }
                                            }
                                            fdmk2.close();
                                        }
                                        
                                        if (!kodeMK2.empty()) {
                                            ifstream fmk2("dataMataKuliah.txt");
                                            if (fmk2.is_open()) {
                                                string mkLine2;
                                                string curKode2, curNama2;
                                                bool matchBlock3 = false;
                                                
                                                while (getline(fmk2, mkLine2)) {
                                                    if (mkLine2.find("Kode :") != string::npos) {
                                                        curKode2 = mkLine2.substr(mkLine2.find("Kode :") + 6);
                                                        while (!curKode2.empty() && isspace((unsigned char)curKode2.front())) curKode2.erase(0,1);
                                                        while (!curKode2.empty() && isspace((unsigned char)curKode2.back())) curKode2.pop_back();
                                                        matchBlock3 = (!curKode2.empty() && curKode2 == kodeMK2);
                                                    } else if (mkLine2.find("Nama :") != string::npos) {
                                                        curNama2 = mkLine2.substr(mkLine2.find("Nama :") + 6);
                                                        while (!curNama2.empty() && isspace((unsigned char)curNama2.front())) curNama2.erase(0,1);
                                                        while (!curNama2.empty() && isspace((unsigned char)curNama2.back())) curNama2.pop_back();
                                                        if (matchBlock3) namaMK2 = curNama2;
                                                    } else if (mkLine2.find("------------------------------------------------------") != string::npos) {
                                                        if (matchBlock3 && !namaMK2.empty()) break;
                                                        curKode2.clear();
                                                        curNama2.clear();
                                                        matchBlock3 = false;
                                                    }
                                                }
                                                fmk2.close();
                                            }
                                        }
                                        

                                        if (!namaMK2.empty()) {
                                            if (!pertama) outFile << ", ";
                                            outFile << namaMK2;
                                            pertama = false;
                                        }
                                    }
                                }
                                inFile2.close();
                            }

                            bool status=false;
                            
                            outFile << "\n";
                            outFile << "Status Pengajuan: Diajukan\n";
                            outFile << "Status Validasi: \n"<<(status?"Disetujui":"Belum di setujui")<<"\n"; 
                            outFile << "==========================================\n";
                            outFile.close();
                            
                            cout << "\nPengajuan KRS berhasil disimpan!\n";
                        } else {
                            cout << "\nError: Gagal menyimpan pengajuan KRS.\n";
                        }
                    } else {
                        cout << "\nPengajuan KRS dibatalkan.\n";
                    }
                }
            }
        }
        
     

        
        
        cout << "\n";
        system("pause");
    }


    void TampilDosenMatakuliahKrs() {
        if (mhsPortal && mhsPortal->isLogin()) {
            TampilDosenMatakuliahKrs(mhsPortal->getNIMMahasiswa());
        } else {
            cout << "Tidak ada mahasiswa yang login.\n";
            system("pause");
        }
    }


    void tampilKrsAktivitas(){
        system("cls");
        cout << "\n============================================\n";
        cout << "        KRS AKTIVITAS MAHASISWA            \n";
        cout << "============================================\n\n";

        
        Mahasiswa m = mhsPortal->getMahasiswaLogin();

        
        if (m.nim.empty()) {
            cout << "Error: Tidak ada mahasiswa yang login.\n";
            cout << "Silakan login terlebih dahulu.\n";
            cout << "\n";
            system("pause");
            return;
        }

        cout << "Nama     : " << m.nama << "\n";
        cout << "NIM      : " << m.nim << "\n";
        cout << "Semester : " << m.semester << "\n\n";

        cout << "(Belum ada daftar aktivitas. Fitur input/list aktivitas dapat ditambahkan.)\n\n";
        system("pause");
    }


    void cekNilaiMhs(const string& nim) {
        system("cls");
        ifstream dp("dataPengajuanKrs.txt");
        if( dp.is_open()) {
            string line;
            bool found = false;
            while (getline(dp, line)) {
                if (line.find("NIM: ") != string::npos) {
                    string nimLine = line.substr(5);
                    if (nimLine == nim) {
                        found = true;
                        break;
                    }
                }
            }
            dp.close();

            if (found) {

                cout << "                ============================================================================\n";
                cout << "                |                                                                          |\n";
                cout << "                |                  KARTU HASIL STUDI (KHS) MAHASISWA                       |\n";
                cout << "                |                                                                          |\n";
                cout << "                ============================================================================\n\n";
                cout << "Nim: " << mhsPortal->getNIMMahasiswa() << "\n";
                string kdKelas = cariKelasMahasiswa(nim);
                if (kdKelas.empty()) {
                    cout << "Mahasiswa belum terdaftar dalam kelas mana pun.\n\n";
                    system("pause");
                    return;
                }
                cout << "Kelas: " << kdKelas << "\n\n";
                cout<<string(104,'-')<<"\n";
                cout<<left<<setw(6)<<"No"
                    <<setw(12)<<"Kode MK"
                    <<setw(34)<<"Nama Mata Kuliah"
                    <<setw(24)<<"Nama Dosen"
                    <<setw(6)<<"SKS"
                    <<setw(8)<<"Nilai"
                    <<setw(8)<<"Angka"
                    <<"Status"<<"\n";
                    cout<<string(104,'-')<<"\n";

                    ifstream inFile("dataKrs.txt");
                    if (!inFile.is_open()) {
                        cout << "Gagal membuka file dataKrs.txt\n\n";
                        system("pause");
                        return;
                    }
                    string line;
                    string currentKelas;
                    bool adaData = false;
                    int no = 1;

                    while(getline(inFile, line)) {
                        if (line.find("Kode Kelas Mahasiswa:") != string::npos) {
                            size_t pos = line.find(":");
                            currentKelas = (pos != string::npos) ? line.substr(pos+1) : string();
                            while (!currentKelas.empty() && isspace((unsigned char)currentKelas.front())) currentKelas.erase(0,1);
                            while (!currentKelas.empty() && isspace((unsigned char)currentKelas.back())) currentKelas.pop_back();
                        } else if (line.find("Kode Dosen Mata Kuliah:") != string::npos) {
                            size_t pos = line.find(":");
                            string kd = (pos != string::npos) ? line.substr(pos+1) : string();
                            while (!kd.empty() && isspace((unsigned char)kd.front())) kd.erase(0,1);
                            while (!kd.empty() && isspace((unsigned char)kd.back())) kd.pop_back();

                            if (currentKelas == kdKelas) {
                                adaData = true;

                                string kodeMK;
                                string nidn;
                                {
                                    ifstream fdmk("dataDosenMataKuliah.txt");
                                    if (fdmk.is_open()) {
                                        string dmkLine;
                                        string curKodeMK;
                                        string curNidn;
                                        bool matchBlock = false;
                                        while (getline(fdmk, dmkLine)) {
                                            if (dmkLine.find("Kode MK") != string::npos && dmkLine.find(":") != string::npos) {
                                                size_t pos = dmkLine.find(":");
                                                curKodeMK = dmkLine.substr(pos+1);
                                                while (!curKodeMK.empty() && isspace((unsigned char)curKodeMK.front())) curKodeMK.erase(0,1);
                                                while (!curKodeMK.empty() && isspace((unsigned char)curKodeMK.back())) curKodeMK.pop_back();
                                            } else if (dmkLine.find("NIDN Dosen") != string::npos && dmkLine.find(":") != string::npos) {
                                                size_t pos = dmkLine.find(":");
                                                curNidn = dmkLine.substr(pos+1);
                                                while (!curNidn.empty() && isspace((unsigned char)curNidn.front())) curNidn.erase(0,1);
                                                while (!curNidn.empty() && isspace((unsigned char)curNidn.back())) curNidn.pop_back();
                                            } else if (dmkLine.find("Kode Dosen MK") != string::npos && dmkLine.find(":") != string::npos) {
                                                size_t pos = dmkLine.find(":");
                                                string curKd = dmkLine.substr(pos+1);
                                                while (!curKd.empty() && isspace((unsigned char)curKd.front())) curKd.erase(0,1);
                                                while (!curKd.empty() && isspace((unsigned char)curKd.back())) curKd.pop_back();
                                                // mark this block matched
                                                matchBlock = (curKd == kd);
                                            } else if (dmkLine.find("----------------------------------------") != string::npos) {
                                                if (matchBlock) {
                                                    kodeMK = curKodeMK;
                                                    nidn = curNidn;
                                                    break;
                                                }
                                                // reset for next block
                                                curKodeMK.clear();
                                                curNidn.clear();
                                                matchBlock = false;
                                            }
                                        }
                                        fdmk.close();
                                    }
                                }

                                string namaMK = "-";
                                string Sksmk = "-";
                                {
                                    ifstream fm("dataMataKuliah.txt");
                                    if (fm.is_open()) {
                                        string mline;
                                        string currentKode;
                                        string currentNama;
                                        string currentSks;
                                        bool matchBlock = false;
                                        
                                        while (getline(fm, mline)) {
                                            if (mline.find("Kode :") != string::npos) {
                                                currentKode = mline.substr(mline.find("Kode :") + 6);
                                                while (!currentKode.empty() && isspace((unsigned char)currentKode.front())) currentKode.erase(0,1);
                                                while (!currentKode.empty() && isspace((unsigned char)currentKode.back())) currentKode.pop_back();
                                                matchBlock = (!currentKode.empty() && currentKode == kodeMK);

                                            } else if (mline.find("Nama :") != string::npos) {
                                                currentNama = mline.substr(mline.find("Nama :") + 6);
                                                while (!currentNama.empty() && isspace((unsigned char)currentNama.front())) currentNama.erase(0,1);
                                                while (!currentNama.empty() && isspace((unsigned char)currentNama.back())) currentNama.pop_back();
                                                if (matchBlock) namaMK = currentNama;

                                            } else if (mline.find("SKS :") != string::npos) {
                                                currentSks = mline.substr(mline.find("SKS :") + 5);
                                                while (!currentSks.empty() && isspace((unsigned char)currentSks.front())) currentSks.erase(0,1);
                                                while (!currentSks.empty() && isspace((unsigned char)currentSks.back())) currentSks.pop_back();  
                                                if (matchBlock) Sksmk = currentSks;
                                                
                                            } else if (mline.find("------------------------------------------------------") != string::npos) {
                                            
                                                if (matchBlock && !namaMK.empty() && Sksmk != "-") {
                                                    break;
                                                }
                                            
                                                currentKode.clear();
                                                currentNama.clear();
                                                currentSks.clear();
                                                matchBlock = false;
                                            }
                                        }
                                        fm.close();
                                    }
                                }

                                string namaDosen = "-";
                                {
                                    ifstream fd("dataDosen.txt");
                                    if (fd.is_open()) {
                                        string dline;
                                        string currentNama;
                                        string currentNidn;
                                        
                                        while (getline(fd, dline)) {
                                            if (dline.find("Nama: ") != string::npos) {
                                                currentNama = dline.substr(6);
                                                while (!currentNama.empty() && isspace((unsigned char)currentNama.front())) currentNama.erase(0,1);
                                                while (!currentNama.empty() && isspace((unsigned char)currentNama.back())) currentNama.pop_back();
                                            } else if (dline.find("NIDN: ") != string::npos) {
                                                currentNidn = dline.substr(6);
                                                while (!currentNidn.empty() && isspace((unsigned char)currentNidn.front())) currentNidn.erase(0,1);
                                                while (!currentNidn.empty() && isspace((unsigned char)currentNidn.back())) currentNidn.pop_back();
                                                if (!currentNidn.empty() && currentNidn == nidn) {
                                                    namaDosen = currentNama;
                                                    break;
                                                }
                                            } else if (dline.find("-------------------------------------") != string::npos) {
                                                currentNama.clear();
                                                currentNidn.clear();
                                            }
                                        }
                                        fd.close();
                                    }
                                }

                                string nilai = "-";
                                string angka = "-";
                                string status = "Aktif";
                                {
                                    ifstream fnilai("DataKHSMahasiswa.txt");
                                    if (fnilai.is_open()) {
                                        string nline;
                                        bool matchBlock = false;
                                        while (getline(fnilai, nline)) {
                                            if (nline.find("NIM: " + nim) != string::npos) {
                                                matchBlock = true;
                                            } else if (matchBlock && nline.find(kodeMK) != string::npos) {
                                                size_t posNilai = nline.find("Nilai:");
                                                size_t posAngka = nline.find("Angka:");
                                                size_t posStatus = nline.find("Status:");
                                                if (posNilai != string::npos) {
                                                    nilai = nline.substr(posNilai + 6, nline.find(" ", posNilai + 6) - (posNilai + 6));
                                                    while (!nilai.empty() && isspace((unsigned char)nilai.front())) nilai.erase(0,1);
                                                    while (!nilai.empty() && isspace((unsigned char)nilai.back())) nilai.pop_back();
                                                }
                                                if (posAngka != string::npos) {
                                                    angka = nline.substr(posAngka + 6, nline.find(" ", posAngka + 6) - (posAngka + 6));
                                                    while (!angka.empty() && isspace((unsigned char)angka.front())) angka.erase(0,1);
                                                    while (!angka.empty() && isspace((unsigned char)angka.back())) angka.pop_back();
                                                }
                                                if (posStatus != string::npos) {
                                                    status = nline.substr(posStatus + 7);
                                                    while (!status.empty() && isspace((unsigned char)status.front())) status.erase(0,1);
                                                    while (!status.empty() && isspace((unsigned char)status.back())) status.pop_back();
                                                }
                                                break;
                                            } else if (nline.find("==========================================") != string::npos) {
                                                matchBlock = false;
                                            }
                                        }
                                        fnilai.close();
                                    }
                                }
                                cout << left << setw(6) << no++
                                    << setw(12) << (kodeMK.empty() ? "-" : kodeMK)
                                    << setw(34) << (namaMK.empty() ? "-" : namaMK)
                                    << setw(24) << (namaDosen.empty() ? "-" : namaDosen)
                                    << setw(6) << (Sksmk.empty() ? "-" : Sksmk)
                                    << setw(8) << (nilai.empty() ? "-" : nilai)
                                    << setw(8) << (angka.empty() ? "-" : angka)
                                    << (status.empty() ? "-" : status) << "\n";
                            }
                        }
                    }
                inFile.close();
                if (!adaData) {
                    cout << "(Tidak ada data KRS untuk kelas ini)\n";
                }
                cout<<string(104,'=')<<"\n";
                cout << "\n";



            }else{
                cout << "\n";
                cout << " ___________________________________________________________________\n";
                cout << "|                                                                   |\n";
                cout << "|    KARTU HASIL STUDI BELUM TERSEDIA                               |\n";
                cout << "|    AKTIFKAN KRS DAHULU UNTUK MENGAKSES KHS                        |\n";
                cout << "|    TERIMA KASIH!!!!                                               |\n";
                cout << "|                                                                   |\n";
                cout << " ===================================================================\n";
                cout << "\n";
            }

        }
        


    }


    void PendaftaranUjianMhs(const string& nim) {
        system("cls");
        cout << "\n============================================\n";
        cout << "        PENDAFTARAN UJIAN MAHASISWA        \n";
        cout << "============================================\n\n";

        
        Mahasiswa m = mhsPortal->getMahasiswaLogin();

        
        if (m.nim.empty()) {
            cout << "Error: Tidak ada mahasiswa yang login.\n";
            cout << "Silakan login terlebih dahulu.\n";
            cout << "\n";
            system("pause");
            return;
        }

        cout << "Nama     : " << m.nama << "\n";
        cout << "NIM      : " << m.nim << "\n";
        cout << "Semester : " << m.semester << "\n\n";

        cout << "(Fitur pendaftaran ujian belum tersedia.)\n\n";
        system("pause");
    }
    

    void PendaftaranSeminarMhs(const string& nim) {
        system("cls");
        cout << "\n============================================\n";
        cout << "       PENDAFTARAN SEMINAR MAHASISWA       \n";
        cout << "============================================\n\n";

        
        Mahasiswa m = mhsPortal->getMahasiswaLogin();

        
        if (m.nim.empty()) {
            cout << "Error: Tidak ada mahasiswa yang login.\n";
            cout << "Silakan login terlebih dahulu.\n";
            cout << "\n";
            system("pause");
            return;
        }

        cout << "Nama     : " << m.nama << "\n";
        cout << "NIM      : " << m.nim << "\n";
        cout << "Semester : " << m.semester << "\n\n";

        cout << "(Fitur pendaftaran seminar belum tersedia.)\n\n";
        system("pause");

    }
};



