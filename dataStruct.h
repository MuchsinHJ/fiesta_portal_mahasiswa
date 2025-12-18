#include <iostream>
using namespace std;

enum class StatusAkademik { Aktif, Cuti, Lulus, DropOut };
enum class StatusDosen { Aktif, Cuti, Pensiun, TidakAktif };
enum class JenisKelamin { LakiLaki, Perempuan };

struct Mahasiswa {
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
    JenisKelamin g;
    bool aktif = true;

    // password
    string password;

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
    string kdKelasMahasiswa;
    string kdDosenMk;
};

struct Kelas {
    string kdKelas;
    string namaKelas;      // 
    int batasKelas = 40;        // jumlah maksimum mahasiswa
};

struct KelasMahasiswa{
    string kdKelas;
    string nim;
};

struct InputDanKoreksiNilai{
    string kdDosenMk;
    string nim;
    int nilaiAkhir;
    string kdKelas;
};