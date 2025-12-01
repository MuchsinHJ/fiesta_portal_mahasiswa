#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// enum class StatusAkademik { Aktif, Cuti, Lulus, DropOut };
// enum class StatusDosen { Aktif, Cuti, Pensiun, TidakAktif };
enum class JenisKelamina { LakiLaki, Perempuan };

struct Mahasiswaa {
    string nama;
    string nim;
    int semester;
    int tahunMasuk;
    string jurusan;
    string fakultas;

    // Informasi pribadi
    string tempatLahir;
    string tanggalLahir;
    string alamat;
    string email;
    string noHp;
    JenisKelamina g;
    bool aktif = true;

    // password
    string password;

};

// struct Dosen {
//     // Identitas dasar
//     string nama;
//     string nidn;        // Nomor Induk Dosen Nasional
//     string nip;         // Nomor Induk Pegawai (jika PNS)
//     string gelarDepan;  // misal: "Dr.", "Prof."
//     string gelarBelakang; // misal: "M.Kom", "Ph.D"

//     // Informasi akademik
//     string fakultas;
//     string jurusan;
//     string jabatanAkademik; // misal: "Lektor", "Guru Besar", "Asisten Ahli"
//     string pendidikanTerakhir; // misal: "S2", "S3"

//     // Data pribadi
//     JenisKelamina gender;
//     string email;
//     string noHp;
//     string alamat;

//     // Status kepegawaian
//     StatusDosen status = StatusDosen::Aktif;
//     int tahunMasuk;
//     bool aktif = true;

// };

// struct MataKuliah {
//     string kodeMK;         // Kode unik, contoh: "IF1234"
//     string namaMK;         // Nama mata kuliah, contoh: "Algoritma & Struktur Data"
//     int sks;               // Jumlah SKS
//     string deskripsi;      // Keterangan singkat mata kuliah
//     int semester;          // Semester disarankan, contoh: 2
//     string jurusan;       // Jurusan pemilik mata kuliah
//     string fakultas;       // Fakultas terkait

//     // Akademik
//     bool wajib;            // true = wajib, false = pilihan

//     // Status
//     bool aktif = true;     // apakah MK masih dibuka semester ini
// };

// // Relasi dosen dengan mata kuliah
// struct DosenMataKuliah {
//     string nidnDosen;
//     string kodeMK;
//     string kdDosenMk;
// };

// // Relasi mahasiswa dengan mata kuliah (KRS)
// struct Krs {
//     string nimMahasiswa;
//     string kdDosenMk;
//     string semesterDiambil; // contoh: "Ganjil 2023/2024"
//     char nilaiHuruf;        // contoh: 'A', 'B', 'C', 'D', 'E', 'F'
//     float nilaiAngka;      // contoh: 4.0, 3.5, dst.
// };

// struct Kelas {
//     string kdKelas;
//     string namaKelas;      // 
//     int batasKelas = 40;        // jumlah maksimum mahasiswa
// };

// struct KelasMahasiswa{
//     string kdKelas;
//     string nim;
// };

// struct Usernamepw{
//     string Username;
//     string Password;
// };

Mahasiswaa mhs;
Mahasiswaa data[1000]; // Assuming a maximum of 1000 students
int jumlah = 0;

void tarikDataMahasiswa(){
    // Implementasi untuk menarik data mahasiswa dari file
        ifstream in("dataMahasiswa.txt");
        
        if (!in.is_open()) {
            cout << "Gagal membuka file dataMahasiswa.txt\n";
            return;
        }

        string line;
        Mahasiswaa mhsSementara;

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
                    mhsSementara.g = JenisKelamina::LakiLaki;
                else
                    mhsSementara.g = JenisKelamina::Perempuan;
            } else if (line.find("Status: ") != string::npos) {
                string statusStr = line.substr(8);
                mhsSementara.aktif = (statusStr == "Aktif");
            } else if (line.find("Password: ") != string::npos) {
                mhsSementara.password = line.substr(10);
            } else if (line.find("--------------------------") != string::npos) {
                // Tambahkan ke array setiap selesai 1 blok data mahasiswa
                data[jumlah] = mhsSementara;
                jumlah++;
            }
        }

        in.close();
}

class MahasiswaPortal {
  private:
    string username;
    string password;
  public:
    MahasiswaPortal(){
        tarikDataMahasiswa();
    }
    bool login(string u, string p) {
      for (int i = 0; i < jumlah; i++) {
        if (u == data[i].nim && p == data[i].password) {
          mhs = data[i];
          return true;
        }
      }
      return false;
    }
};



