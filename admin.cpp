#include <iostream>
#include <string>
#include <fstream>

#include <iomanip>
#include "dataStruct.h"
#include "doubleLinkedList.h"
using namespace std;

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

        username="";
        password="";
        return statusLogin;
    }

    bool isLogin() const {
        return statusLogin;
    }

    void logoutnih() {
        username.clear();
        password.clear();
        cout << "Logout berhasil." << endl;
        system("pause");
        
    }
};

//CLASS UNTUK MENU UTAMA MAHASISWA
class ManajemenMahasiswa {
private:
public:
DoubleLinkedList<Mahasiswa> listMahasiswa;
Mahasiswa mhsBaru;

ManajemenMahasiswa() {
    tarikMahasiswadarifile();
    // 300 data mahasiswa baru dengan NIM 2400018001 - 2400018300
    bool fileKosong = (listMahasiswa.head == nullptr);
    if (fileKosong){
        
        tambahMahasiswaLangsung({"Adi Pratama", "2400018001", 3, 2024, "Informatika", "FTI", "Jakarta", "10-03-2002", "Jl. Mangga No. 5", "adi@example.com", "081200000001", JenisKelamin::LakiLaki, true, "10032002001"});
        tambahMahasiswaLangsung({"Bunga Sari", "2400018002", 3, 2024, "Informatika", "FTI", "Bandung", "15-04-2002", "Jl. Anggrek No. 12", "bunga@example.com", "081200000002", JenisKelamin::Perempuan, true, "15042002002"});
        tambahMahasiswaLangsung({"Cahyo Nugroho", "2400018003", 3, 2024, "Informatika", "FTI", "Surabaya", "20-05-2002", "Jl. Melati No. 8", "cahyo@example.com", "081200000003", JenisKelamin::LakiLaki, true, "20052002003"});
        tambahMahasiswaLangsung({"Dewi Lestari", "2400018004", 3, 2024, "Informatika", "FTI", "Semarang", "25-06-2002", "Jl. Kenanga No. 15", "dewi@example.com", "081200000004", JenisKelamin::Perempuan, true, "25062002004"});
        tambahMahasiswaLangsung({"Eko Prasetyo", "2400018005", 3, 2024, "Informatika", "FTI", "Yogyakarta", "30-07-2002", "Jl. Mawar No. 20", "eko@example.com", "081200000005", JenisKelamin::LakiLaki, true, "30072002005"});
        tambahMahasiswaLangsung({"Fitri Handayani", "2400018006", 3, 2024,"Informatika", "FTI", "Malang", "05-08-2002", "Jl. Flamboyan No. 25", "fitri@example.com", "081200000006", JenisKelamin::Perempuan, true, "05082002006"});
        tambahMahasiswaLangsung({"Gilang Ramadhan", "2400018007", 3, 2024, "Informatika", "FTI", "Medan", "10-09-2002", "Jl. Cempaka No. 30", "gilang@example.com", "081200000007", JenisKelamin::LakiLaki, true, "10092002007"});
        tambahMahasiswaLangsung({"Hana Wijaya", "2400018008", 3, 2024, "Informatika", "FTI", "Palembang", "15-10-2002", "Jl. Teratai No. 35", "hana@example.com", "081200000008", JenisKelamin::Perempuan, true, "15102002008"});
        tambahMahasiswaLangsung({"Irfan Setiawan", "2400018009", 3, 2024,"Informatika", "FTI", "Makassar", "20-11-2002", "Jl. Kamboja No. 40", "irfan@example.com", "081200000009", JenisKelamin::LakiLaki, true, "20112002009"});
        tambahMahasiswaLangsung({"Jihan Amelia", "2400018010", 3, 2024, "Informatika", "FTI", "Denpasar", "25-12-2002", "Jl. Sakura No. 45", "jihan@example.com", "081200000010", JenisKelamin::Perempuan, true, "25122002010"});
        
        tambahMahasiswaLangsung({"Kurniawan", "2400018011", 3, 2024, "Informatika", "FTI", "Bandung", "03-01-2002", "Jl. Dahlia No. 50", "kurnia@example.com", "081200000011", JenisKelamin::LakiLaki, true, "03012002011"});
        tambahMahasiswaLangsung({"Lestari", "2400018012", 3, 2024, "Informatika", "FTI", "Jakarta", "08-02-2002", "Jl. Tulip No. 55", "lestari@example.com", "081200000012", JenisKelamin::Perempuan, true, "08022002012"});
        tambahMahasiswaLangsung({"Mulyadi", "2400018013", 3, 2024, "Informatika", "FTI", "Surabaya", "13-03-2002", "Jl. Lavender No. 60", "mulyadi@example.com", "081200000013", JenisKelamin::LakiLaki, true, "13032002013"});
        tambahMahasiswaLangsung({"Nadia Putri", "2400018014", 3, 2024, "Informatika", "FTI", "Semarang", "18-04-2002", "Jl. Aster No. 65", "nadia@example.com", "081200000014", JenisKelamin::Perempuan, true, "18042002014"});
        tambahMahasiswaLangsung({"Oki Pratama", "2400018015", 3, 2024,"Informatika", "FTI", "Yogyakarta", "23-05-2002", "Jl. Lily No. 70", "oki@example.com", "081200000015", JenisKelamin::LakiLaki, true, "23052002015"});
        tambahMahasiswaLangsung({"Putri Ayu", "2400018016", 3, 2024, "Informatika", "FTI", "Malang", "28-06-2002", "Jl. Orchid No. 75", "putri@example.com", "081200000016", JenisKelamin::Perempuan, true, "28062002016"});
        tambahMahasiswaLangsung({"Rizki Maulana", "2400018017", 3, 2024,"Informatika", "FTI", "Medan", "03-07-2002", "Jl. Jasmine No. 80", "rizki@example.com", "081200000017", JenisKelamin::LakiLaki, true, "03072002017"});
        tambahMahasiswaLangsung({"Sari Dewi", "2400018018", 3, 2024, "Informatika", "FTI", "Palembang", "08-08-2002", "Jl. Sunflower No. 85", "sari@example.com", "081200000018", JenisKelamin::Perempuan, true, "08082002018"});
        tambahMahasiswaLangsung({"Teguh Santoso", "2400018019", 3, 2024, "Informatika", "FTI", "Makassar", "13-09-2002", "Jl. Rose No. 90", "teguh@example.com", "081200000019", JenisKelamin::LakiLaki, true, "13092002019"});
        tambahMahasiswaLangsung({"Umi Kulsum", "2400018020", 3, 2024, "Informatika", "FTI", "Denpasar", "18-10-2002", "Jl. Daisy No. 95", "umi@example.com", "081200000020", JenisKelamin::Perempuan, true, "18102002020"});
       
        tambahMahasiswaLangsung({"Vino Gustomo", "2400018021", 3, 2024, "Informatika", "FTI", "Bandung", "23-11-2002", "Jl. Magnolia No. 100", "vino@example.com", "081200000021", JenisKelamin::LakiLaki, true, "23112002021"});
        tambahMahasiswaLangsung({"Wulan Sari", "2400018022", 3, 2024, "Informatika", "FTI", "Jakarta", "28-12-2002", "Jl. Peony No. 105", "wulan@example.com", "081200000022", JenisKelamin::Perempuan, true, "28122002022"});
        tambahMahasiswaLangsung({"Yoga Perdana", "2400018023", 3, 2024, "Informatika", "FTI", "Surabaya", "02-01-2002", "Jl. Hibiscus No. 110", "yoga@example.com", "081200000023", JenisKelamin::LakiLaki, true, "02012002023"});
        tambahMahasiswaLangsung({"Zahra Amanda", "2400018024", 3, 2024, "Informatika", "FTI", "Semarang", "07-02-2002", "Jl. Camellia No. 115", "zahra@example.com", "081200000024", JenisKelamin::Perempuan, true, "07022002024"});
        tambahMahasiswaLangsung({"Agus Salim", "2400018025", 3, 2024, "Informatika", "FTI", "Yogyakarta", "12-03-2002", "Jl. Azalea No. 120", "agus@example.com", "081200000025", JenisKelamin::LakiLaki, true, "12032002025"});
        tambahMahasiswaLangsung({"Bella Nurul", "2400018026", 3, 2024, "Informatika", "FTI", "Malang", "17-04-2002", "Jl. Bougainvillea No. 125", "bella@example.com", "081200000026", JenisKelamin::Perempuan, true, "17042002026"});
        tambahMahasiswaLangsung({"Candra Wijaya", "2400018027", 3, 2024, "Informatika", "FTI", "Medan", "22-05-2002", "Jl. Carnation No. 130", "candra@example.com", "081200000027", JenisKelamin::LakiLaki, true, "22052002027"});
        tambahMahasiswaLangsung({"Dina Marlina", "2400018028", 3, 2024, "Informatika", "FTI", "Palembang", "27-06-2002", "Jl. Chrysanthemum No. 135", "dina@example.com", "081200000028", JenisKelamin::Perempuan, true, "27062002028"});
        tambahMahasiswaLangsung({"Eri Gunawan", "2400018029", 3, 2024, "Informatika", "FTI", "Makassar", "02-07-2002", "Jl. Daffodil No. 140", "eri@example.com", "081200000029", JenisKelamin::LakiLaki, true, "02072002029"});
        tambahMahasiswaLangsung({"Fajar Nugraha", "2400018030", 3, 2024, "Informatika", "FTI", "Denpasar", "07-08-2002", "Jl. Edelweiss No. 145", "fajar@example.com", "081200000030", JenisKelamin::LakiLaki, true, "07082002030"});
       
        tambahMahasiswaLangsung({"Gita Purnama", "2400018031", 3, 2024, "Informatika", "FTI", "Bandung", "12-09-2002", "Jl. Forsythia No. 150", "gita@example.com", "081200000031", JenisKelamin::Perempuan, true, "12092002031"});
        tambahMahasiswaLangsung({"Hendra Saputra", "2400018032", 3, 2024, "Informatika", "FTI", "Jakarta", "17-10-2002", "Jl. Gardenia No. 155", "hendra@example.com", "081200000032", JenisKelamin::LakiLaki, true, "17102002032"});
        tambahMahasiswaLangsung({"Indah Permata", "2400018033", 3, 2024, "Informatika", "FTI", "Surabaya", "22-11-2002", "Jl. Heather No. 160", "indah@example.com", "081200000033", JenisKelamin::Perempuan, true, "22112002033"});
        tambahMahasiswaLangsung({"Joko Susilo", "2400018034", 3, 2024, "Informatika", "FTI", "Semarang", "27-12-2002", "Jl. Iris No. 165", "joko@example.com", "081200000034", JenisKelamin::LakiLaki, true, "27122002034"});
        tambahMahasiswaLangsung({"Kartika Sari", "2400018035", 3, 2024, "Informatika", "FTI", "Yogyakarta", "01-01-2002", "Jl. Jonquil No. 170", "kartika@example.com", "081200000035", JenisKelamin::Perempuan, true, "01012002035"});
        tambahMahasiswaLangsung({"Lukman Hakim", "2400018036", 3, 2024, "Informatika", "FTI", "Malang", "06-02-2002", "Jl. Kangaroo Paw No. 175", "lukman@example.com", "081200000036", JenisKelamin::LakiLaki, true, "06022002036"});
        tambahMahasiswaLangsung({"Mira Utami", "2400018037", 3, 2024, "Informatika", "FTI", "Medan", "11-03-2002", "Jl. Lantana No. 180", "mira@example.com", "081200000037", JenisKelamin::Perempuan, true, "11032002037"});
        tambahMahasiswaLangsung({"Nugroho", "2400018038", 3, 2024, "Informatika", "FTI", "Palembang", "16-04-2002", "Jl. Marigold No. 185", "nugroho@example.com", "081200000038", JenisKelamin::LakiLaki, true, "16042002038"});
        tambahMahasiswaLangsung({"Olivia Tan", "2400018039", 3, 2024, "Informatika", "FTI", "Makassar", "21-05-2002", "Jl. Nasturtium No. 190", "olivia@example.com", "081200000039", JenisKelamin::Perempuan, true, "21052002039"});
        tambahMahasiswaLangsung({"Pandu Winata", "2400018040", 3, 2024, "Informatika", "FTI", "Denpasar", "26-06-2002", "Jl. Oleander No. 195", "pandu@example.com", "081200000040", JenisKelamin::LakiLaki, true, "26062002040"});
       
        tambahMahasiswaLangsung({"Qory Sandioriva", "2400018041", 3, 2024, "Informatika", "FTI", "Bandung", "01-07-2002", "Jl. Pansy No. 200", "qory@example.com", "081200000041", JenisKelamin::Perempuan, true, "01072002041"});
        tambahMahasiswaLangsung({"Rendra Mahesa", "2400018042", 3, 2024, "Informatika", "FTI", "Jakarta", "06-08-2002", "Jl. Queen Anne's Lace No. 205", "rendra@example.com", "081200000042", JenisKelamin::LakiLaki, true, "06082002042"});
        tambahMahasiswaLangsung({"Siska Wulandari", "2400018043", 3, 2024, "Informatika", "FTI", "Surabaya", "11-09-2002", "Jl. Ranunculus No. 210", "siska@example.com", "081200000043", JenisKelamin::Perempuan, true, "11092002043"});
        tambahMahasiswaLangsung({"Taufik Hidayat", "2400018044", 3, 2024, "Informatika", "FTI", "Semarang", "16-10-2002", "Jl. Snapdragon No. 215", "taufik@example.com", "081200000044", JenisKelamin::LakiLaki, true, "16102002044"});
        tambahMahasiswaLangsung({"Uci Sanjaya", "2400018045", 3, 2024, "Informatika", "FTI", "Yogyakarta", "21-11-2002", "Jl. Tulip No. 220", "uci@example.com", "081200000045", JenisKelamin::Perempuan, true, "21112002045"});
        tambahMahasiswaLangsung({"Viktor Siregar", "2400018046", 3, 2024, "Informatika", "FTI", "Malang", "26-12-2002", "Jl. Ulex No. 225", "viktor@example.com", "081200000046", JenisKelamin::LakiLaki, true, "26122002046"});
        tambahMahasiswaLangsung({"Winda Puspita", "2400018047", 3, 2024, "Informatika", "FTI", "Medan", "31-01-2002", "Jl. Verbena No. 230", "winda@example.com", "081200000047", JenisKelamin::Perempuan, true, "31012002047"});
        tambahMahasiswaLangsung({"Xavier Tanoto", "2400018048", 3, 2024, "Informatika", "FTI", "Palembang", "05-02-2002", "Jl. Wisteria No. 235", "xavier@example.com", "081200000048", JenisKelamin::LakiLaki, true, "05022002048"});
        tambahMahasiswaLangsung({"Yuni Astuti", "2400018049", 3, 2024, "Informatika", "FTI", "Makassar", "10-03-2002", "Jl. Xeranthemum No. 240", "yuni@example.com", "081200000049", JenisKelamin::Perempuan, true, "10032002049"});
        tambahMahasiswaLangsung({"Zulkifli", "2400018050", 3, 2024,"Informatika", "FTI", "Denpasar", "15-04-2002", "Jl. Yarrow No. 245", "zulkifli@example.com", "081200000050", JenisKelamin::LakiLaki, true, "15042002050"});
    
    
        // Data 51-60
        tambahMahasiswaLangsung({"Arya Dharma", "2400018051", 3, 2024, "Informatika", "FTI", "Bandung", "20-05-2002", "Jl. Zinnia No. 250", "arya@example.com", "081200000051", JenisKelamin::LakiLaki, true, "20052002051"});
        tambahMahasiswaLangsung({"Bimo Satrio", "2400018052", 3, 2024, "Informatika", "FTI", "Jakarta", "25-06-2002", "Jl. Acacia No. 255", "bimo@example.com", "081200000052", JenisKelamin::LakiLaki, true, "25062002052"});
        tambahMahasiswaLangsung({"Cindy Laura", "2400018053", 3, 2024, "Informatika", "FTI", "Surabaya", "30-07-2002", "Jl. Bamboo No. 260", "cindy@example.com", "081200000053", JenisKelamin::Perempuan, true, "30072002053"});
        tambahMahasiswaLangsung({"Dodi Pranata", "2400018054", 3, 2024, "Informatika", "FTI", "Semarang", "04-08-2002", "Jl. Cedar No. 265", "dodi@example.com", "081200000054", JenisKelamin::LakiLaki, true, "04082002054"});
        tambahMahasiswaLangsung({"Eva Yuliana", "2400018055", 3, 2024, "Informatika", "FTI", "Yogyakarta", "09-09-2002", "Jl. Dogwood No. 270", "eva@example.com", "081200000055", JenisKelamin::Perempuan, true, "09092002055"});
        tambahMahasiswaLangsung({"Fadli Zon", "2400018056", 3, 2024,"Informatika", "FTI", "Malang", "14-10-2002", "Jl. Elm No. 275", "fadli@example.com", "081200000056", JenisKelamin::LakiLaki, true, "14102002056"});
        tambahMahasiswaLangsung({"Gina Melati", "2400018057", 3, 2024, "Informatika", "FTI", "Medan", "19-11-2002", "Jl. Fir No. 280", "gina@example.com", "081200000057", JenisKelamin::Perempuan, true, "19112002057"});
        tambahMahasiswaLangsung({"Haryanto", "2400018058", 3, 2024, "Informatika", "FTI", "Palembang", "24-12-2002", "Jl. Ginkgo No. 285", "haryanto@example.com", "081200000058", JenisKelamin::LakiLaki, true, "24122002058"});
        tambahMahasiswaLangsung({"Ira Wahyuni", "2400018059", 3, 2024,"Informatika", "FTI", "Makassar", "29-01-2002", "Jl. Hazel No. 290", "ira@example.com", "081200000059", JenisKelamin::Perempuan, true, "29012002059"});
        tambahMahasiswaLangsung({"Jefri Nicholas", "2400018060", 3, 2024, "Informatika", "FTI", "Denpasar", "03-02-2002", "Jl. Ironwood No. 295", "jefri@example.com", "081200000060", JenisKelamin::LakiLaki, true, "03022002060"});
        
        tambahMahasiswaLangsung({"Kurniawan", "2400018061", 3, 2024, "Informatika", "FTI", "Bandung", "03-01-2002", "Jl. Dahlia No. 50", "kurnia@example.com", "081200000011", JenisKelamin::LakiLaki, true, "03012002061"});
        tambahMahasiswaLangsung({"Lestari", "2400018062", 3, 2024, "Informatika", "FTI", "Jakarta", "08-02-2002", "Jl. Tulip No. 55", "lestari@example.com", "081200000012", JenisKelamin::Perempuan, true, "08022002062"});
        tambahMahasiswaLangsung({"Mulyadi", "2400018063", 3, 2024, "Informatika", "FTI", "Surabaya", "13-03-2002", "Jl. Lavender No. 60", "mulyadi@example.com", "081200000013", JenisKelamin::LakiLaki, true, "13032002063"});
        tambahMahasiswaLangsung({"Nadia Putri", "2400018064", 3, 2024, "Informatika", "FTI", "Semarang", "18-04-2002", "Jl. Aster No. 65", "nadia@example.com", "081200000014", JenisKelamin::Perempuan, true, "18042002064"});
        tambahMahasiswaLangsung({"Oki Pratama", "2400018065", 3, 2024,"Informatika", "FTI", "Yogyakarta", "23-05-2002", "Jl. Lily No. 70", "oki@example.com", "081200000015", JenisKelamin::LakiLaki, true, "23052002065"});
        tambahMahasiswaLangsung({"Putri Ayu", "2400018066", 3, 2024, "Informatika", "FTI", "Malang", "28-06-2002", "Jl. Orchid No. 75", "putri@example.com", "081200000016", JenisKelamin::Perempuan, true, "28062002066"});
        tambahMahasiswaLangsung({"Rizki Maulana", "2400018067", 3, 2024, "Informatika", "FTI", "Medan", "03-07-2002", "Jl. Jasmine No. 80", "rizki@example.com", "081200000017", JenisKelamin::LakiLaki, true, "03072002067"});
        tambahMahasiswaLangsung({"Sari Dewi", "2400018068", 3, 2024, "Informatika", "FTI", "Palembang", "08-08-2002", "Jl. Sunflower No. 85", "sari@example.com", "081200000018", JenisKelamin::Perempuan, true, "08082002068"});
        tambahMahasiswaLangsung({"Teguh Santoso", "2400018069", 3, 2024, "Informatika", "FTI", "Makassar", "13-09-2002", "Jl. Rose No. 90", "teguh@example.com", "081200000019", JenisKelamin::LakiLaki, true, "13092002069"});
        tambahMahasiswaLangsung({"Umi Kulsum", "2400018070", 3, 2024, "Informatika", "FTI", "Denpasar", "18-10-2002", "Jl. Daisy No. 95", "umi@example.com", "081200000020", JenisKelamin::Perempuan, true, "18102002070"});
        
        tambahMahasiswaLangsung({"Vino Gustomo", "2400018071", 3, 2024, "Informatika", "FTI", "Bandung", "23-11-2002", "Jl. Magnolia No. 100", "vino@example.com", "081200000021", JenisKelamin::LakiLaki, true, "23112002071"});
        tambahMahasiswaLangsung({"Wulan Sari", "2400018072", 3, 2024, "Informatika", "FTI", "Jakarta", "28-12-2002", "Jl. Peony No. 105", "wulan@example.com", "081200000022", JenisKelamin::Perempuan, true, "28122002072"});
        tambahMahasiswaLangsung({"Yoga Perdana", "2400018073", 3, 2024,"Informatika", "FTI", "Surabaya", "02-01-2002", "Jl. Hibiscus No. 110", "yoga@example.com", "081200000023", JenisKelamin::LakiLaki, true, "02012002073"});
        tambahMahasiswaLangsung({"Zahra Amanda", "2400018074", 3, 2024, "Informatika", "FTI", "Semarang", "07-02-2002", "Jl. Camellia No. 115", "zahra@example.com", "081200000024", JenisKelamin::Perempuan, true, "07022002074"});
        tambahMahasiswaLangsung({"Agus Salim", "2400018075", 3, 2024, "Informatika", "FTI", "Yogyakarta", "12-03-2002", "Jl. Azalea No. 120", "agus@example.com", "081200000025", JenisKelamin::LakiLaki, true, "12032002075"});
        tambahMahasiswaLangsung({"Bella Nurul", "2400018076", 3, 2024, "Informatika", "FTI", "Malang", "17-04-2002", "Jl. Bougainvillea No. 125", "bella@example.com", "081200000026", JenisKelamin::Perempuan, true, "17042002076"});
        tambahMahasiswaLangsung({"Candra Wijaya", "2400018077", 3, 2024,"Informatika", "FTI", "Medan", "22-05-2002", "Jl. Carnation No. 130", "candra@example.com", "081200000027", JenisKelamin::LakiLaki, true, "22052002077"});
        tambahMahasiswaLangsung({"Dina Marlina", "2400018078", 3, 2024, "Informatika", "FTI", "Palembang", "27-06-2002", "Jl. Chrysanthemum No. 135", "dina@example.com", "081200000028", JenisKelamin::Perempuan, true, "27062002078"});
        tambahMahasiswaLangsung({"Eri Gunawan", "2400018079", 3, 2024, "Informatika", "FTI", "Makassar", "02-07-2002", "Jl. Daffodil No. 140", "eri@example.com", "081200000029", JenisKelamin::LakiLaki, true, "02072002079"});
        tambahMahasiswaLangsung({"Fajar Nugraha", "2400018080", 3, 2024, "Informatika", "FTI", "Denpasar", "07-08-2002", "Jl. Edelweiss No. 145", "fajar@example.com", "081200000030", JenisKelamin::LakiLaki, true, "07082002080"});
       
        tambahMahasiswaLangsung({"Gita Purnama", "2400018081", 3, 2024, "Informatika", "FTI", "Bandung", "12-09-2002", "Jl. Forsythia No. 150", "gita@example.com", "081200000031", JenisKelamin::Perempuan, true, "12092002081"});
        tambahMahasiswaLangsung({"Hendra Saputra", "2400018082", 3, 2024, "Informatika", "FTI", "Jakarta", "17-10-2002", "Jl. Gardenia No. 155", "hendra@example.com", "081200000032", JenisKelamin::LakiLaki, true, "17102002082"});
        tambahMahasiswaLangsung({"Indah Permata", "2400018083", 3, 2024, "Informatika", "FTI", "Surabaya", "22-11-2002", "Jl. Heather No. 160", "indah@example.com", "081200000033", JenisKelamin::Perempuan, true, "22112002083"});
        tambahMahasiswaLangsung({"Joko Susilo", "2400018084", 3, 2024, "Informatika", "FTI", "Semarang", "27-12-2002", "Jl. Iris No. 165", "joko@example.com", "081200000034", JenisKelamin::LakiLaki, true, "27122002084"});
        tambahMahasiswaLangsung({"Kartika Sari", "2400018085", 3, 2024, "Informatika", "FTI", "Yogyakarta", "01-01-2002", "Jl. Jonquil No. 170", "kartika@example.com", "081200000035", JenisKelamin::Perempuan, true, "01012002085"});
        tambahMahasiswaLangsung({"Lukman Hakim", "2400018086", 3, 2024, "Informatika", "FTI", "Malang", "06-02-2002", "Jl. Kangaroo Paw No. 175", "lukman@example.com", "081200000036", JenisKelamin::LakiLaki, true, "06022002086"});
        tambahMahasiswaLangsung({"Mira Utami", "2400018087", 3, 2024, "Informatika", "FTI", "Medan", "11-03-2002", "Jl. Lantana No. 180", "mira@example.com", "081200000037", JenisKelamin::Perempuan, true, "11032002087"});
        tambahMahasiswaLangsung({"Nugroho", "2400018088", 3, 2024, "Informatika", "FTI", "Palembang", "16-04-2002", "Jl. Marigold No. 185", "nugroho@example.com", "081200000038", JenisKelamin::LakiLaki, true, "16042002088"});
        tambahMahasiswaLangsung({"Olivia Tan", "2400018089", 3, 2024, "Informatika", "FTI", "Makassar", "21-05-2002", "Jl. Nasturtium No. 190", "olivia@example.com", "081200000039", JenisKelamin::Perempuan, true, "21052002089"});
        tambahMahasiswaLangsung({"Pandu Winata", "2400018090", 3, 2024, "Informatika", "FTI", "Denpasar", "26-06-2002", "Jl. Oleander No. 195", "pandu@example.com", "081200000040", JenisKelamin::LakiLaki, true, "26062002090"});
        
        tambahMahasiswaLangsung({"Qory Sandioriva", "2400018091", 3, 2024, "Informatika", "FTI", "Bandung", "01-07-2002", "Jl. Pansy No. 200", "qory@example.com", "081200000041", JenisKelamin::Perempuan, true, "01072002091"});
        tambahMahasiswaLangsung({"Rendra Mahesa", "2400018092", 3, 2024,"Informatika", "FTI", "Jakarta", "06-08-2002", "Jl. Queen Anne's Lace No. 205", "rendra@example.com", "081200000042", JenisKelamin::LakiLaki, true, "06082002092"});
        tambahMahasiswaLangsung({"Siska Wulandari", "2400018093", 3, 2024, "Informatika", "FTI", "Surabaya", "11-09-2002", "Jl. Ranunculus No. 210", "siska@example.com", "081200000043", JenisKelamin::Perempuan, true, "11092002093"});
        tambahMahasiswaLangsung({"Taufik Hidayat", "2400018094", 3, 2024,"Informatika", "FTI", "Semarang", "16-10-2002", "Jl. Snapdragon No. 215", "taufik@example.com", "081200000044", JenisKelamin::LakiLaki, true, "16102002094"});
        tambahMahasiswaLangsung({"Uci Sanjaya", "2400018095", 3, 2024, "Informatika", "FTI", "Yogyakarta", "21-11-2002", "Jl. Tulip No. 220", "uci@example.com", "081200000045", JenisKelamin::Perempuan, true, "21112002095"});
        tambahMahasiswaLangsung({"Viktor Siregar", "2400018096", 3, 2024, "Informatika", "FTI", "Malang", "26-12-2002", "Jl. Ulex No. 225", "viktor@example.com", "081200000046", JenisKelamin::LakiLaki, true, "26122002096"});
        tambahMahasiswaLangsung({"Winda Puspita", "2400018097", 3, 2024, "Informatika", "FTI", "Medan", "31-01-2002", "Jl. Verbena No. 230", "winda@example.com", "081200000047", JenisKelamin::Perempuan, true, "31012002097"});
        tambahMahasiswaLangsung({"Xavier Tanoto", "2400018098", 3, 2024, "Informatika", "FTI", "Palembang", "05-02-2002", "Jl. Wisteria No. 235", "xavier@example.com", "081200000048", JenisKelamin::LakiLaki, true, "05022002098"});
        tambahMahasiswaLangsung({"Yuni Astuti", "2400018099", 3, 2024, "Informatika", "FTI", "Makassar", "10-03-2002", "Jl. Xeranthemum No. 240", "yuni@example.com", "081200000049", JenisKelamin::Perempuan, true, "10032002099"});
        tambahMahasiswaLangsung({"Zulkifli", "2400018100", 3, 2024, "Informatika", "FTI", "Denpasar", "15-04-2002", "Jl. Yarrow No. 245", "zulkifli@example.com", "081200000050", JenisKelamin::LakiLaki, true, "15042002100"});
    
    
    
        tambahMahasiswaLangsung({"Rina Marlina", "2400018101", 3, 2024, "Informatika", "FTI", "Bogor", "12-03-2002", "Jl. Seroja No. 10", "rina@example.com", "081200010001", JenisKelamin::Perempuan, true, "12032002101"});
        tambahMahasiswaLangsung({"Surya Aditya", "2400018102", 3, 2024, "Informatika", "FTI", "Tangerang", "18-04-2002", "Jl. Teratai No. 15", "surya@example.com", "081200010002", JenisKelamin::LakiLaki, true, "18042002102"});
        tambahMahasiswaLangsung({"Maya Sari", "2400018103", 3, 2024, "Informatika", "FTI", "Bekasi", "22-05-2002", "Jl. Kamboja No. 20", "maya@example.com", "081200010003", JenisKelamin::Perempuan, true, "22052002103"});
        tambahMahasiswaLangsung({"Doni Pratama", "2400018104", 3, 2024, "Informatika", "FTI", "Depok", "28-06-2002", "Jl. Mawar No. 25", "doni@example.com", "081200010004", JenisKelamin::LakiLaki, true, "28062002104"});
        tambahMahasiswaLangsung({"Lia Anggraini", "2400018105", 3, 2024, "Informatika", "FTI", "Cirebon", "03-07-2002", "Jl. Melati No. 30", "lia@example.com", "081200010005", JenisKelamin::Perempuan, true, "03072002105"});
        tambahMahasiswaLangsung({"Rizky Fadilah", "2400018106", 3, 2024, "Informatika", "FTI", "Cimahi", "08-08-2002", "Jl. Anggrek No. 35", "rizky@example.com", "081200010006", JenisKelamin::LakiLaki, true, "08082002106"});
        tambahMahasiswaLangsung({"Diana Putri", "2400018107", 3, 2024, "Informatika", "FTI", "Tasikmalaya", "13-09-2002", "Jl. Flamboyan No. 40", "diana@example.com", "081200010007", JenisKelamin::Perempuan, true, "13092002107"});
        tambahMahasiswaLangsung({"Fajar Ramadan", "2400018108", 3, 2024, "Informatika", "FTI", "Banjar", "18-10-2002", "Jl. Cempaka No. 45", "fajar@example.com", "081200010008", JenisKelamin::LakiLaki, true, "18102002108"});
        tambahMahasiswaLangsung({"Nina Rosita", "2400018109", 3, 2024, "Informatika", "FTI", "Magelang", "23-11-2002", "Jl. Kenanga No. 50", "nina@example.com", "081200010009", JenisKelamin::Perempuan, true, "23112002109"});
        tambahMahasiswaLangsung({"Hadi Susanto", "2400018110", 3, 2024, "Informatika", "FTI", "Purwokerto", "28-12-2002", "Jl. Dahlia No. 55", "hadi@example.com", "081200010010", JenisKelamin::LakiLaki, true, "28122002110"});
        
        tambahMahasiswaLangsung({"Anisa Rahma", "2400018111", 3, 2024, "Informatika", "FTI", "Pekalongan", "02-01-2002", "Jl. Sakura No. 60", "anisa@example.com", "081200010011", JenisKelamin::Perempuan, true, "02012002111"});
        tambahMahasiswaLangsung({"Bayu Kurniawan", "2400018112", 3, 2024, "Informatika", "FTI", "Salatiga", "07-02-2002", "Jl. Lavender No. 65", "bayu@example.com", "081200010012", JenisKelamin::LakiLaki, true, "07022002112"});
        tambahMahasiswaLangsung({"Citra Dewi", "2400018113", 3, 2024, "Informatika", "FTI", "Semarang", "12-03-2002", "Jl. Aster No. 70", "citra@example.com", "081200010013", JenisKelamin::Perempuan, true, "12032002113"});
        tambahMahasiswaLangsung({"Dodi Hermawan", "2400018114", 3, 2024, "Informatika", "FTI", "Surakarta", "17-04-2002", "Jl. Lily No. 75", "dodi@example.com", "081200010014", JenisKelamin::LakiLaki, true, "17042002114"});
        tambahMahasiswaLangsung({"Elsa Fitriani", "2400018115", 3, 2024, "Informatika", "FTI", "Klaten", "22-05-2002", "Jl. Orchid No. 80", "elsa@example.com", "081200010015", JenisKelamin::Perempuan, true, "22052002115"});
        tambahMahasiswaLangsung({"Firman Syah", "2400018116", 3, 2024, "Informatika", "FTI", "Sragen", "27-06-2002", "Jl. Jasmine No. 85", "firman@example.com", "081200010016", JenisKelamin::LakiLaki, true, "27062002116"});
        tambahMahasiswaLangsung({"Gita Permatasari", "2400018117", 3, 2024, "Informatika", "FTI", "Wonogiri", "02-07-2002", "Jl. Sunflower No. 90", "gita@example.com", "081200010017", JenisKelamin::Perempuan, true, "02072002117"});
        tambahMahasiswaLangsung({"Hendra Wijaya", "2400018118", 3, 2024, "Informatika", "FTI", "Karanganyar", "07-08-2002", "Jl. Rose No. 95", "hendra@example.com", "081200010018", JenisKelamin::LakiLaki, true, "07082002118"});
        tambahMahasiswaLangsung({"Intan Permata", "2400018119", 3, 2024, "Informatika", "FTI", "Sukoharjo", "12-09-2002", "Jl. Daisy No. 100", "intan@example.com", "081200010019", JenisKelamin::Perempuan, true, "12092002119"});
        tambahMahasiswaLangsung({"Joni Saputra", "2400018120", 3, 2024, "Informatika", "FTI", "Boyolali", "17-10-2002", "Jl. Magnolia No. 105", "joni@example.com", "081200010020", JenisKelamin::LakiLaki, true, "17102002120"});
        
        tambahMahasiswaLangsung({"Kartika Sari", "2400018121", 3, 2024, "Informatika", "FTI", "Pati", "22-11-2002", "Jl. Peony No. 110", "kartika@example.com", "081200010021", JenisKelamin::Perempuan, true, "22112002121"});
        tambahMahasiswaLangsung({"Luthfi Rahman", "2400018122", 3, 2024, "Informatika", "FTI", "Rembang", "27-12-2002", "Jl. Hibiscus No. 115", "luthfi@example.com", "081200010022", JenisKelamin::LakiLaki, true, "27122002122"});
        tambahMahasiswaLangsung({"Melia Utami", "2400018123", 3, 2024, "Informatika", "FTI", "Blora", "01-01-2002", "Jl. Camellia No. 120", "melia@example.com", "081200010023", JenisKelamin::Perempuan, true, "01012002123"});
        tambahMahasiswaLangsung({"Nando Pratama", "2400018124", 3, 2024, "Informatika", "FTI", "Grobogan", "06-02-2002", "Jl. Azalea No. 125", "nando@example.com", "081200010024", JenisKelamin::LakiLaki, true, "06022002124"});
        tambahMahasiswaLangsung({"Oktavia Nur", "2400018125", 3, 2024, "Informatika", "FTI", "Demak", "11-03-2002", "Jl. Bougainvillea No. 130", "oktavia@example.com", "081200010025", JenisKelamin::Perempuan, true, "11032002125"});
        tambahMahasiswaLangsung({"Pandu Setiawan", "2400018126", 3, 2024, "Informatika", "FTI", "Kudus", "16-04-2002", "Jl. Carnation No. 135", "pandu@example.com", "081200010026", JenisKelamin::LakiLaki, true, "16042002126"});
        tambahMahasiswaLangsung({"Queen Amelia", "2400018127", 3, 2024, "Informatika", "FTI", "Jepara", "21-05-2002", "Jl. Chrysanthemum No. 140", "queen@example.com", "081200010027", JenisKelamin::Perempuan, true, "21052002127"});
        tambahMahasiswaLangsung({"Rafi Akbar", "2400018128", 3, 2024, "Informatika", "FTI", "Pemalang", "26-06-2002", "Jl. Daffodil No. 145", "rafi@example.com", "081200010028", JenisKelamin::LakiLaki, true, "26062002128"});
        tambahMahasiswaLangsung({"Salsa Bila", "2400018129", 3, 2024, "Informatika", "FTI", "Brebes", "01-07-2002", "Jl. Edelweiss No. 150", "salsa@example.com", "081200010029", JenisKelamin::Perempuan, true, "01072002129"});
        tambahMahasiswaLangsung({"Toni Gunawan", "2400018130", 3, 2024, "Informatika", "FTI", "Tegal", "06-08-2002", "Jl. Forsythia No. 155", "toni@example.com", "081200010030", JenisKelamin::LakiLaki, true, "06082002130"});
        
        tambahMahasiswaLangsung({"Umi Kalsum", "2400018131", 3, 2024, "Informatika", "FTI", "Slawi", "11-09-2002", "Jl. Gardenia No. 160", "umi@example.com", "081200010031", JenisKelamin::Perempuan, true, "11092002131"});
        tambahMahasiswaLangsung({"Viktor Surya", "2400018132", 3, 2024, "Informatika", "FTI", "Purwodadi", "16-10-2002", "Jl. Heather No. 165", "viktor@example.com", "081200010032", JenisKelamin::LakiLaki, true, "16102002132"});
        tambahMahasiswaLangsung({"Winda Puspita", "2400018133", 3, 2024, "Informatika", "FTI", "Ungaran", "21-11-2002", "Jl. Iris No. 170", "winda@example.com", "081200010033", JenisKelamin::Perempuan, true, "21112002133"});
        tambahMahasiswaLangsung({"Yoga Maulana", "2400018134", 3, 2024, "Informatika", "FTI", "Ambarawa", "26-12-2002", "Jl. Jonquil No. 175", "yoga@example.com", "081200010034", JenisKelamin::LakiLaki, true, "26122002134"});
        tambahMahasiswaLangsung({"Zahra Nabila", "2400018135", 3, 2024, "Informatika", "FTI", "Banyumanik", "31-01-2002", "Jl. Kangaroo Paw No. 180", "zahra@example.com", "081200010035", JenisKelamin::Perempuan, true, "31012002135"});
        tambahMahasiswaLangsung({"Aldi Firmansyah", "2400018136", 3, 2024, "Informatika", "FTI", "Gunungpati", "05-02-2002", "Jl. Lantana No. 185", "aldi@example.com", "081200010036", JenisKelamin::LakiLaki, true, "05022002136"});
        tambahMahasiswaLangsung({"Bella Anastasia", "2400018137", 3, 2024, "Informatika", "FTI", "Mijen", "10-03-2002", "Jl. Marigold No. 190", "bella@example.com", "081200010037", JenisKelamin::Perempuan, true, "10032002137"});
        tambahMahasiswaLangsung({"Cakra Bumi", "2400018138", 3, 2024, "Informatika", "FTI", "Ngaliyan", "15-04-2002", "Jl. Nasturtium No. 195", "cakra@example.com", "081200010038", JenisKelamin::LakiLaki, true, "15042002138"});
        tambahMahasiswaLangsung({"Dinda Maharani", "2400018139", 3, 2024, "Informatika", "FTI", "Tembalang", "20-05-2002", "Jl. Oleander No. 200", "dinda@example.com", "081200010039", JenisKelamin::Perempuan, true, "20052002139"});
        tambahMahasiswaLangsung({"Eko Purnomo", "2400018140", 3, 2024, "Informatika", "FTI", "Banyuwangi", "25-06-2002", "Jl. Pansy No. 205", "eko@example.com", "081200010040", JenisKelamin::LakiLaki, true, "25062002140"});
        
        tambahMahasiswaLangsung({"Fani Oktaviani", "2400018141", 3, 2024, "Informatika", "FTI", "Jember", "30-07-2002", "Jl. Queen Anne's Lace No. 210", "fani@example.com", "081200010041", JenisKelamin::Perempuan, true, "30072002141"});
        tambahMahasiswaLangsung({"Gilang Persada", "2400018142", 3, 2024, "Informatika", "FTI", "Lumajang", "04-08-2002", "Jl. Ranunculus No. 215", "gilang@example.com", "081200010042", JenisKelamin::LakiLaki, true, "04082002142"});
        tambahMahasiswaLangsung({"Hesti Wulandari", "2400018143", 3, 2024, "Informatika", "FTI", "Probolinggo", "09-09-2002", "Jl. Snapdragon No. 220", "hesti@example.com", "081200010043", JenisKelamin::Perempuan, true, "09092002143"});
        tambahMahasiswaLangsung({"Ivan Kurnia", "2400018144", 3, 2024, "Informatika", "FTI", "Pasuruan", "14-10-2002", "Jl. Tulip No. 225", "ivan@example.com", "081200010044", JenisKelamin::LakiLaki, true, "14102002144"});
        tambahMahasiswaLangsung({"Jeni Anggraeni", "2400018145", 3, 2024, "Informatika", "FTI", "Mojokerto", "19-11-2002", "Jl. Ulex No. 230", "jeni@example.com", "081200010045", JenisKelamin::Perempuan, true, "19112002145"});
        tambahMahasiswaLangsung({"Kevin Ardian", "2400018146", 3, 2024, "Informatika", "FTI", "Madiun", "24-12-2002", "Jl. Verbena No. 235", "kevin@example.com", "081200010046", JenisKelamin::LakiLaki, true, "24122002146"});
        tambahMahasiswaLangsung({"Lala Safitri", "2400018147", 3, 2024, "Informatika", "FTI", "Kediri", "29-01-2002", "Jl. Wisteria No. 240", "lala@example.com", "081200010047", JenisKelamin::Perempuan, true, "29012002147"});
        tambahMahasiswaLangsung({"Miko Andika", "2400018148", 3, 2024, "Informatika", "FTI", "Blitar", "03-02-2002", "Jl. Xeranthemum No. 245", "miko@example.com", "081200010048", JenisKelamin::LakiLaki, true, "03022002148"});
        tambahMahasiswaLangsung({"Nia Kurniasih", "2400018149", 3, 2024, "Informatika", "FTI", "Tulungagung", "08-03-2002", "Jl. Yarrow No. 250", "nia@example.com", "081200010049", JenisKelamin::Perempuan, true, "08032002149"});
        tambahMahasiswaLangsung({"Omar Syahputra", "2400018150", 3, 2024, "Informatika", "FTI", "Trenggalek", "13-04-2002", "Jl. Zinnia No. 255", "omar@example.com", "081200010050", JenisKelamin::LakiLaki, true, "13042002150"});
        
        // Hanya update file jika baru menambahkan data hardcode
        updateFileMhs();
    }
}

void tambahMahasiswaLangsung(const Mahasiswa& mhs) {
    listMahasiswa.tambahData(mhs);
}

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
        for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
            if (temp->data.nim == mhsBaru.nim) {
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
    mhsBaru.password = mhsBaru.tanggalLahir.substr(0,2) + mhsBaru.tanggalLahir.substr(3,2) + mhsBaru.tanggalLahir.substr(6,4) + mhsBaru.nim.substr(mhsBaru.nim.length() - 3);

    int pilihGender;
    cout << "Pilih jenis kelamin (1. Laki-laki, 2. Perempuan): ";
    cin >> pilihGender;
    mhsBaru.g = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;

    mhsBaru.aktif = true;
    listMahasiswa.tambahData(mhsBaru);
    updateFileMhs(); // simpan semua
}
        
    void hapusMahasiswa() {
        cout << "=====MENU HAPUS MAHASISWA=====" << endl;
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
        cin >> nimCari;
        bool ditemukan = false;
        DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head;
        size_t index=0;
        while(temp!=nullptr){
            if (temp->data.nim == nimCari) {
                ditemukan = true;
                
                cout << "Data Mahasiswa yang ditemukan:\n";
                cout << "Nama: " << temp->data.nama << "\n";
                cout << "NIM: " << temp->data.nim << "\n";
                cout << "Semester: " << temp->data.semester << "\n";
                cout << "Tahun Masuk: " << temp->data.tahunMasuk << "\n";
                cout << "Jurusan: " << temp->data.jurusan << "\n";

                //konfirmasi penghapusan
                char konfirmasi;
                cout << "Apakah Anda yakin ingin menghapus mahasiswa dengan NIM " << nimCari << "? (y/n): ";
                cin >> konfirmasi;
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    listMahasiswa.hapusData(index);
                    cout << "Mahasiswa dengan NIM " << nimCari << " telah dihapus.\n";
                    updateFileMhs();
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
                break;
            }
            temp=temp->next;
            ++index;
        }
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }

    void tarikMahasiswadarifile(){
        listMahasiswa.clear();
        ifstream in("dataMahasiswa.txt");
        
        if (!in.is_open()) {
            cout << "Gagal membuka file dataMahasiswa.txt\n";
            return;
        }

        auto trim = [](string &s){
            while (!s.empty() && isspace((unsigned char)s.front())) s.erase(0,1);
            while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
        };

        string line;
        Mahasiswa mhsSementara;

        while (getline(in, line)) {
            size_t pos = line.find(":");
            if (pos == string::npos) continue;

            string value = line.substr(pos + 1);
            trim(value);

            if (line.find("Nama: ") == 0) {
                mhsSementara.nama = value;
            } else if (line.find("NIM: ") == 0) {
                mhsSementara.nim = value;
            } else if (line.find("Semester: ") == 0) {
                try {
                    mhsSementara.semester = stoi(value);
                } catch (...) {
                    mhsSementara.semester = 0;
                }
            } else if (line.find("Tahun Masuk: ") == 0) {
                try {
                    mhsSementara.tahunMasuk = stoi(value);
                } catch (...) {
                    mhsSementara.tahunMasuk = 0;
                }
            } else if (line.find("Jurusan: ") == 0) {
                mhsSementara.jurusan = value;
            } else if (line.find("Fakultas: ") == 0) {
                mhsSementara.fakultas = value;
            } else if (line.find("Tempat Lahir: ") == 0) {
                mhsSementara.tempatLahir = value;
            } else if (line.find("Tanggal Lahir: ") == 0) {
                mhsSementara.tanggalLahir = value;
            } else if (line.find("Alamat: ") == 0) {
                mhsSementara.alamat = value;
            } else if (line.find("Email: ") == 0) {
                mhsSementara.email = value;
            } else if (line.find("No HP: ") == 0) {
                mhsSementara.noHp = value;
            } else if (line.find("Jenis Kelamin: ") == 0) {
                mhsSementara.g = (value == "Laki-laki") ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;
            } else if (line.find("Status: ") == 0) {
                mhsSementara.aktif = (value == "Aktif");
            } else if (line.find("Password: ") == 0) {
                mhsSementara.password = value;
            } else if (line.find("--------------------------") != string::npos) {
                
                if (!mhsSementara.nim.empty()) {
                    tambahMahasiswaLangsung(mhsSementara);
                    mhsSementara = Mahasiswa(); 
                }
            }
        }

        in.close();
    }

    void updateFileMhs() {
    ofstream in("dataMahasiswa.txt", ios::trunc); // hapus isi lama
    if (!in.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data.\n";
        return;
    }

    int idx=1;
    for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next, ++idx) {
        in << "Data Mahasiswa ke-" << idx << ":\n";
        in << "Nama: " << temp->data.nama << "\n";
        in << "NIM: " << temp->data.nim << "\n";
        in << "Semester: " << temp->data.semester << "\n";
        in << "Tahun Masuk: " << temp->data.tahunMasuk << "\n";
        in << "Jurusan: " << temp->data.jurusan << "\n";
        in << "Fakultas: " << temp->data.fakultas << "\n";
        in << "Tempat Lahir: " << temp->data.tempatLahir << "\n";
        in << "Tanggal Lahir: " << temp->data.tanggalLahir << "\n";
        in << "Alamat: " << temp->data.alamat << "\n";
        in << "Email: " << temp->data.email << "\n";
        in << "No HP: " << temp->data.noHp << "\n";
        in << "Jenis Kelamin: " << (temp->data.g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
        in << "Status: " << (temp->data.aktif ? "Aktif" : "Tidak Aktif") << "\n";
        in << "Password: " << temp->data.password << "\n";
        in << "--------------------------\n";
    }

        in.close();
    }

    void tampilMahasiswa() {
        if (listMahasiswa.head == nullptr) {
            cout << "Tidak ada data mahasiswa.\n";
            return;
        }

        auto clip = [](const string& s, size_t w){
            if (s.size() <= w) return s;
            if (w <= 3) return s.substr(0, w);
            return s.substr(0, w-3) + "...";
        };

        cout << string(180,'=') << "\n";
        cout << "                                          DATA MAHASISWA\n";
        cout << string(180,'=') << "\n";
        cout << left
             << setw(4)  << "No"
             << setw(25) << "Nama"
             << setw(13) << "NIM"
             << setw(5)  << "Sem"
             << setw(7)  << "Tahun"
             << setw(15) << "Jurusan"
             << setw(10) << "Fakultas"
             << setw(18) << "Tempat Lahir"
             << setw(13) << "Tgl Lahir"
             << setw(25) << "Alamat"
             << setw(20) << "Email"
             << setw(14) << "No HP"
             << setw(10) << "Gender"
             << setw(8)  << "Status"
             << "\n";
        cout << string(180,'-') << "\n";

        int idx = 1;
        for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
            cout << left
                 << setw(4)  << idx++
                 << setw(25) << clip(temp->data.nama, 25)
                 << setw(13) << clip(temp->data.nim, 13)
                 << setw(5)  << temp->data.semester
                 << setw(7)  << temp->data.tahunMasuk
                 << setw(15) << clip(temp->data.jurusan, 15)
                 << setw(10) << clip(temp->data.fakultas, 10)
                 << setw(18) << clip(temp->data.tempatLahir, 18)
                 << setw(13) << clip(temp->data.tanggalLahir, 13)
                 << setw(25) << clip(temp->data.alamat, 25)
                 << setw(20) << clip(temp->data.email, 20)
                 << setw(14) << clip(temp->data.noHp, 14)
                 << setw(10) << (temp->data.g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")
                 << setw(8)  << (temp->data.aktif ? "Aktif" : "Non-Aktif")
                 << "\n";
        }
        cout << string(180,'=') << "\n";
    }

    void editMahasiswa() {
        updateFileMhs();
        cout << "=====MENU EDIT MAHASISWA=====" << endl;
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang akan diedit: ";
        cin >> nimCari;
        bool ditemukan = false;
        for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
            if (temp->data.nim == nimCari) {
                ditemukan = true;
                cout << "Data ditemukan:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                cout << "Nama: " << temp->data.nama << "\n";
                cout << "NIM: " << temp->data.nim << "\n";
                cout << "Semester: " << temp->data.semester << "\n";
                cout << "Tahun Masuk: " << temp->data.tahunMasuk << "\n";
                cout << "Jurusan: " << temp->data.jurusan << "\n";
                cout << "Fakultas: " << temp->data.fakultas << "\n";
                cout << "Tempat Lahir: " << temp->data.tempatLahir << "\n";
                cout << "Tanggal Lahir: " << temp->data.tanggalLahir << "\n";
                cout << "Alamat: " << temp->data.alamat << "\n";
                cout << "Email: " << temp->data.email << "\n";
                cout << "No HP: " << temp->data.noHp << "\n";
                cout << "Jenis Kelamin: " << (temp->data.g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
                cout << "Status: " << (temp->data.aktif ? "Aktif" : "Tidak Aktif") << "\n";
                cout << "==============================\n";
                cout << " Masukkan Data Baru: \n";
                cout << "==============================\n";
                cout << "\nMasukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, temp->data.nama);
                cout << "Masukkan semester: ";
                cin >> temp->data.semester;
                cout << "Masukkan tahun masuk: ";
                cin >> temp->data.tahunMasuk;
                cout << "Masukkan jurusan: ";
                getline(cin, temp->data.jurusan);
                cout << "Masukkan fakultas: ";
                getline(cin, temp->data.fakultas);
                cout << "Masukkan tempat lahir: ";
                getline(cin, temp->data.tempatLahir);
                cout << "Masukkan tanggal lahir (DD-MM-YYYY): ";
                getline(cin, temp->data.tanggalLahir);
                cout << "Masukkan alamat: ";
                getline(cin, temp->data.alamat);
                cout << "Masukkan email: ";
                getline(cin, temp->data.email);
                cout << "Masukkan nomor HP: ";
                getline(cin, temp->data.noHp);

                // Input jenis kelamin (enum)
                int pilihGender;
                cout << "Pilih jenis kelamin (1. Laki-laki, 2. Perempuan): ";
                cin >> pilihGender;
                temp->data.g = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;

                cout << "Data mahasiswa berhasil diperbarui!\n";
                updateFileMhs();
                break;
            }
        }
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }

    void cekKeaktifanMahasiswa() {
        cout << "=====MENU CEK KEAKTIFAN MAHASISWA=====" << endl;
        string nimCari;
        cout << "Masukkan NIM mahasiswa yang akan dicek: ";
        cin >> nimCari;
        bool ditemukan = false;
        for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
            if (temp->data.nim == nimCari) {
                ditemukan = true;
                cout << "Status keaktifan mahasiswa dengan NIM " << nimCari << ": "
                     << (temp->data.aktif ? "Aktif" : "Tidak Aktif") << "\n";
                break;
            }
        }
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }

    void TampilSemuaMahasiswa() {
        tarikMahasiswadarifile();
        tampilMahasiswa();
    }

    void tampilMahasiswaPerSemester() {
        tarikMahasiswadarifile();

        auto clip = [](const string& s, size_t w){
            if (s.size() <= w) return s;
            if (w <= 3) return s.substr(0, w);
            return s.substr(0, w-3) + "...";
        };

        cout << "\n" << string(180,'=') << "\n";
        cout << "                              DAFTAR MAHASISWA PER SEMESTER\n";
        cout << string(180,'=') << "\n\n";

        
        for (int semester = 1; semester <= 8; semester++) {
            bool ditemukan = false;
            int jumlah = 0;

            
            for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
                if (temp->data.semester == semester) {
                    jumlah++;
                    ditemukan = true;
                }
            }

            if (!ditemukan) {
                continue; // Skip semester yang tidak ada mahasiswanya
            }

            // Header per semester
            cout << string(180,'-') << "\n";
            cout << "SEMESTER " << semester << " (Total: " << jumlah << " mahasiswa)\n";
            cout << string(180,'-') << "\n";
            cout << left
                 << setw(4)  << "No"
                 << setw(25) << "Nama"
                 << setw(13) << "NIM"
                 << setw(5)  << "Sem"
                 << setw(7)  << "Tahun"
                 << setw(15) << "Jurusan"
                 << setw(10) << "Fakultas"
                 << setw(18) << "Tempat Lahir"
                 << setw(13) << "Tgl Lahir"
                 << setw(25) << "Alamat"
                 << setw(20) << "Email"
                 << setw(14) << "No HP"
                 << setw(10) << "Gender"
                 << setw(8)  << "Status"
                 << "\n";
            cout << string(180,'-') << "\n";

            int idx = 1;
            for (DoubleLinkedList<Mahasiswa>::Node* temp=listMahasiswa.head; temp!=nullptr; temp=temp->next) {
                if (temp->data.semester == semester) {
                    cout << left
                         << setw(4)  << idx++
                         << setw(25) << clip(temp->data.nama, 25)
                         << setw(13) << clip(temp->data.nim, 13)
                         << setw(5)  << temp->data.semester
                         << setw(7)  << temp->data.tahunMasuk
                         << setw(15) << clip(temp->data.jurusan, 15)
                         << setw(10) << clip(temp->data.fakultas, 10)
                         << setw(18) << clip(temp->data.tempatLahir, 18)
                         << setw(13) << clip(temp->data.tanggalLahir, 13)
                         << setw(25) << clip(temp->data.alamat, 25)
                         << setw(20) << clip(temp->data.email, 20)
                         << setw(14) << clip(temp->data.noHp, 14)
                         << setw(10) << (temp->data.g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")
                         << setw(8)  << (temp->data.aktif ? "Aktif" : "Non-Aktif")
                         << "\n";
                }
            }
            cout << "\n";
        }
        
        cout << string(180,'=') << "\n";
    }
};

//CLASS UNTUK MENU UTAMA DOSEN
class ManajemenDosen{
    private:
    DoubleLinkedList<Dosen> listDosen;
    Dosen dosenBaru;
    
    public:
    ManajemenDosen(){
    
        tarikDosenFile();
        // Data dosen Informatika FTI
        if (listDosen.head == nullptr)
        {

            TambahDosenLangsung({"Dr. Ahmad Santoso","1234567801", "196501011234", "Dr.", "M.Kom", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::LakiLaki, "ahmad.santoso@univ.ac.id", "081200000001", "Jl. Pendidikan No. 123", StatusDosen::Aktif, 2005});
            TambahDosenLangsung({"Prof. Siti Rahayu", "1234567802", "196602021235", "Prof.", "Ph.D", "FTI", "Informatika", "Guru Besar", "S3", JenisKelamin::Perempuan, "siti.rahayu@univ.ac.id", "081200000002", "Jl. Akademik No. 45", StatusDosen::Aktif, 2000});
            TambahDosenLangsung({"Drs. Bambang Wijaya", "1234567803", "197003031236", "Drs.", "M.T", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::LakiLaki, "bambang.wijaya@univ.ac.id", "081200000003", "Jl. Teknologi No. 67", StatusDosen::Aktif, 2008});
            TambahDosenLangsung({"Ir. Maria Dewi", "1234567804", "197104041237", "Ir.", "M.Kom", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::Perempuan, "maria.dewi@univ.ac.id", "081200000004", "Jl. Komputer No. 89", StatusDosen::Aktif, 2010});
            TambahDosenLangsung({"Dr. Rudi Hermawan", "1234567805", "197205051238", "Dr.", "M.Sc", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::LakiLaki, "rudi.hermawan@univ.ac.id", "081200000005", "Jl. Programmer No. 12", StatusDosen::Aktif, 2007});
            TambahDosenLangsung({"Diana Puspita, M.Kom", "1234567806", "198306061239", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "diana.puspita@univ.ac.id", "081200000006", "Jl. Algorithm No. 34", StatusDosen::Aktif, 2015});
            TambahDosenLangsung({"Fajar Nugroho, M.T", "1234567807", "198407071240", "", "M.T", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::LakiLaki, "fajar.nugroho@univ.ac.id", "081200000007", "Jl. Database No. 56", StatusDosen::Aktif, 2016});
            TambahDosenLangsung({"Prof. Dr. Hendra Gunawan", "1234567808", "196508081241", "Prof. Dr.", "M.Eng", "FTI", "Informatika", "Guru Besar", "S3", JenisKelamin::LakiLaki, "hendra.gunawan@univ.ac.id", "081200000008", "Jl. Network No. 78", StatusDosen::Aktif, 1998});
            TambahDosenLangsung({"Lina Marlina, M.Kom", "1234567809", "198609091242", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "lina.marlina@univ.ac.id", "081200000009", "Jl. Software No. 90", StatusDosen::Aktif, 2017});
            TambahDosenLangsung({"Eko Prasetyo, M.Sc", "1234567810", "197710101243", "", "M.Sc", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::LakiLaki, "eko.prasetyo@univ.ac.id", "081200000010", "Jl. Hardware No. 11", StatusDosen::Aktif, 2012});
        
            TambahDosenLangsung({"Dr. Ir. Anita Sari", "1234567811", "197811111244", "Dr. Ir.", "M.T", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::Perempuan, "anita.sari@univ.ac.id", "081200000011", "Jl. Artificial No. 22", StatusDosen::Aktif, 2009});
            TambahDosenLangsung({"Rizki Maulana, M.Kom", "1234567812", "198912121245", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::LakiLaki, "rizki.maulana@univ.ac.id", "081200000012", "Jl. Intelligence No. 33", StatusDosen::Aktif, 2018});
            TambahDosenLangsung({"Dewi Anggraeni, M.T", "1234567813", "199013131246", "", "M.T", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "dewi.anggraeni@univ.ac.id", "081200000013", "Jl. Machine No. 44", StatusDosen::Aktif, 2019});
            TambahDosenLangsung({"Prof. Dr. Ir. Joko Susilo", "1234567814", "196114141247", "Prof. Dr. Ir.", "Ph.D", "FTI", "Informatika", "Guru Besar", "S3", JenisKelamin::LakiLaki, "joko.susilo@univ.ac.id", "081200000014", "Jl. Learning No. 55", StatusDosen::Aktif, 1995});
            TambahDosenLangsung({"Maya Sari, M.Kom", "1234567815", "199215151248", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "maya.sari@univ.ac.id", "081200000015", "Jl. Data No. 66", StatusDosen::Aktif, 2020});
            TambahDosenLangsung({"Dr. Adi Saputra", "1234567816", "197316161249", "Dr.", "M.Eng", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::LakiLaki, "adi.saputra@univ.ac.id", "081200000016", "Jl. Science No. 77", StatusDosen::Aktif, 2011});
            TambahDosenLangsung({"Nina Permata, M.T", "1234567817", "199417171250", "", "M.T", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "nina.permata@univ.ac.id", "081200000017", "Jl. Computing No. 88", StatusDosen::Aktif, 2021});
            TambahDosenLangsung({"Drs. Toni Gunawan", "1234567818", "197518181251", "Drs.", "M.Kom", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::LakiLaki, "toni.gunawan@univ.ac.id", "081200000018", "Jl. Information No. 99", StatusDosen::Aktif, 2006});
            TambahDosenLangsung({"Fitri Handayani, M.Sc", "1234567819", "199619191252", "", "M.Sc", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "fitri.handayani@univ.ac.id", "081200000019", "Jl. Technology No. 100", StatusDosen::Aktif, 2022});
            TambahDosenLangsung({"Prof. Dr. Rendra Mahesa", "1234567820", "196720201253", "Prof. Dr.", "Ph.D", "FTI", "Informatika", "Guru Besar", "S3", JenisKelamin::LakiLaki, "rendra.mahesa@univ.ac.id", "081200000020", "Jl. Innovation No. 111", StatusDosen::Aktif, 1999});
        
            TambahDosenLangsung({"Ir. Sari Indah, M.T", "1234567821", "197821211254", "Ir.", "M.T", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::Perempuan, "sari.indah@univ.ac.id", "081200000021", "Jl. Digital No. 122", StatusDosen::Aktif, 2013});
            TambahDosenLangsung({"Budi Santoso, M.Kom", "1234567822", "198922221255", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::LakiLaki, "budi.santoso@univ.ac.id", "081200000022", "Jl. Programming No. 133", StatusDosen::Aktif, 2023});
            TambahDosenLangsung({"Dr. Citra Dewi", "1234567823", "197023231256", "Dr.", "M.Sc", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::Perempuan, "citra.dewi@univ.ac.id", "081200000023", "Jl. Development No. 144", StatusDosen::Aktif, 2014});
            TambahDosenLangsung({"Agus Setiawan, M.T", "1234567824", "199124241257", "", "M.T", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::LakiLaki, "agus.setiawan@univ.ac.id", "081200000024", "Jl. Engineering No. 155", StatusDosen::Aktif, 2024});
            TambahDosenLangsung({"Prof. Dr. Wulan Sari", "1234567825", "196225251258", "Prof. Dr.", "Ph.D", "FTI", "Informatika", "Guru Besar", "S3", JenisKelamin::Perempuan, "wulan.sari@univ.ac.id", "081200000025", "Jl. Research No. 166", StatusDosen::Aktif, 1997});
            TambahDosenLangsung({"Drs. Heri Prabowo", "1234567826", "197326261259", "Drs.", "M.Kom", "FTI", "Informatika", "Lektor", "S2", JenisKelamin::LakiLaki, "heri.prabowo@univ.ac.id", "081200000026", "Jl. Analysis No. 177", StatusDosen::Cuti, 2004});
            TambahDosenLangsung({"Yuni Astuti, M.Sc", "1234567827", "199427271260", "", "M.Sc", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "yuni.astuti@univ.ac.id", "081200000027", "Jl. Design No. 188", StatusDosen::Aktif, 2023});
            TambahDosenLangsung({"Dr. Ir. Farid Rahman", "1234567828", "196528281261", "Dr. Ir.", "M.Eng", "FTI", "Informatika", "Lektor Kepala", "S3", JenisKelamin::LakiLaki, "farid.rahman@univ.ac.id", "081200000028", "Jl. System No. 199", StatusDosen::Pensiun, 1990});
            TambahDosenLangsung({"Gita Permatasari, M.Kom", "1234567829", "199629291262", "", "M.Kom", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::Perempuan, "gita.permatasari@univ.ac.id", "081200000029", "Jl. Architecture No. 200", StatusDosen::Aktif, 2022});
            TambahDosenLangsung({"Hadi Nugroho, M.T", "1234567830", "198730301263", "", "M.T", "FTI", "Informatika", "Asisten Ahli", "S2", JenisKelamin::LakiLaki, "hadi.nugroho@univ.ac.id", "081200000030", "Jl. Security No. 211", StatusDosen::Aktif, 2021});
        }
    
        updateFileDosen();

    }


    void TambahDosenLangsung(const Dosen& dosen){
        listDosen.tambahData(dosen);
    }


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
        listDosen.tambahData(dosenBaru);
        cout<<"Dosen berhasil ditambahkan!"<<endl;

        updateFileDosen();
    }

    void tarikDosenFile(){
        listDosen.clear();
        ifstream in("dataDosen.txt");

        if(!in.is_open()){
            cout<<"gagal membuka filee dataDosen.txt"<<endl;
            return;
        }

        string line;
        Dosen DsSementara;

        while(getline(in,line)){
            if(line.find("Nama: ") !=string::npos){
                DsSementara.nama=line.substr(6);
            }else if(line.find("NIDN: ") !=string::npos){
                DsSementara.nidn=line.substr(6);
            }else if(line.find("NIP: ") !=string::npos){
                DsSementara.nip=line.substr(5);
            }else if(line.find("Gelar Depan: ") !=string::npos){
                DsSementara.gelarDepan=line.substr(13);
            }else if(line.find("Gelar Belakang: ") !=string::npos){
                DsSementara.gelarBelakang=line.substr(16);
            }else if(line.find("Fakultas: ") !=string::npos){
                DsSementara.fakultas=line.substr(10);
            }else if(line.find("Jurusan: ") !=string::npos){
                DsSementara.jurusan=line.substr(9);
            }else if(line.find("Jabatan Akademik: ") !=string::npos){
                DsSementara.jabatanAkademik=line.substr(18);
            }else if(line.find("Pendidikan Terakhir: ") !=string::npos){
                DsSementara.pendidikanTerakhir=line.substr(21);
            }else if(line.find("Jenis Kelamin: ") !=string::npos){
                string genderstr=line.substr(15);
                if(genderstr=="Laki-laki"){
                    DsSementara.gender=JenisKelamin::LakiLaki;
                }else{
                    DsSementara.gender=JenisKelamin::Perempuan;
                }
            }else if(line.find("Email: ") !=string::npos){
                DsSementara.email=line.substr(7);
            }else if(line.find("No HP: ") !=string::npos){
                DsSementara.noHp=line.substr(7);
            }else if(line.find("Alamat: ") !=string::npos){
                DsSementara.alamat=line.substr(8);
            }else if(line.find("Status: ") !=string::npos){
                string statusstr=line.substr(8);
                if(statusstr=="Aktif"){
                    DsSementara.status=StatusDosen::Aktif;
                }else if(statusstr=="Cuti"){
                    DsSementara.status=StatusDosen::Cuti;
                }else if(statusstr=="Pensiun"){
                    DsSementara.status=StatusDosen::Pensiun;
                }else if(statusstr=="Tidak Aktif" || statusstr=="TidakAktif"){
                    DsSementara.status=StatusDosen::TidakAktif;
                }
            }else if(line.find("Tahun Masuk: ") !=string::npos){
                string tahunstr=line.substr(13);
                try{
                    DsSementara.tahunMasuk=stoi(tahunstr);
                }catch(...){
                    DsSementara.tahunMasuk=0;
                }
            }else if(line.find("-------------------------------------")!=string::npos){
                TambahDosenLangsung(DsSementara);
            }
           
        }
         in.close();

        
    }

    //update Dosen ke file txt
    void updateFileDosen(){
        ofstream in("dataDosen.txt", ios::trunc);
        if(in.is_open()){
            int idx = 1;
            for(DoubleLinkedList<Dosen>::Node* cur=listDosen.head;cur!=nullptr;cur=cur->next,++idx){
                const Dosen& d = cur->data;
                in<<"Dosen ke-"<<idx<<":"<<"\n";
                in<<"Nama: "<<d.nama<<"\n";
                in<<"NIDN: "<<d.nidn<<"\n";
                in<<"NIP: "<<d.nip<<"\n";
                in<<"Fakultas: "<<d.fakultas<<"\n";
                in<<"Jurusan: "<<d.jurusan<<"\n";
                in<<"Gelar Depan: "<<d.gelarDepan<<"\n";
                in<<"Gelar Belakang: "<<d.gelarBelakang<<"\n";
                in<<"Jabatan Akademik: "<<d.jabatanAkademik<<"\n";
                in<<"Pendidikan Terakhir: "<<d.pendidikanTerakhir<<"\n";
                in<<"Email: "<<d.email<<"\n";
                in<<"No HP: "<<d.noHp<<"\n";
                in<<"Alamat: "<<d.alamat<<"\n";
                in<<"Jenis Kelamin: "<<(d.gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")<<"\n";
                in<<"Tahun Masuk: "<<d.tahunMasuk<<"\n";
                in<<"Status: ";
                switch(d.status){
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
                in<<"-------------------------------------"<<"\n";
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
        if(listDosen.head==nullptr){
            cout<<"Belum ada data dosen."<<endl;
            return;
        }

        int idx=1;
        for(DoubleLinkedList<Dosen>::Node* cur=listDosen.head;cur!=nullptr;cur=cur->next,++idx){
            cout<<"Dosen ke-"<<idx<<":"<<endl;
            cout<<"Nama: "<<cur->data.nama<<endl;
            cout<<"NIDN: "<<cur->data.nidn<<endl;
            cout<<"NIP: "<<cur->data.nip<<endl;
            cout<<"Fakultas: "<<cur->data.fakultas<<endl;
            cout<<"Jurusan: "<<cur->data.jurusan<<endl;
            cout<<"Gelar Depan: "<<cur->data.gelarDepan<<endl;
            cout<<"Gelar Belakang: "<<cur->data.gelarBelakang<<endl;
            cout<<"Jabatan Akademik: "<<cur->data.jabatanAkademik<<endl;
            cout<<"Pendidikan Terakhir: "<<cur->data.pendidikanTerakhir<<endl;
            cout<<"Email: "<<cur->data.email<<endl;
            cout<<"No HP: "<<cur->data.noHp<<endl;
            cout<<"Alamat: "<<cur->data.alamat<<endl;
            cout<<"Jenis Kelamin: "<<(cur->data.gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan")<<endl;
            cout<<"Tahun Masuk: "<<cur->data.tahunMasuk<<endl;
            cout<<"Status: "<<(cur->data.status == StatusDosen::Aktif ? "Aktif" :
                                    cur->data.status == StatusDosen::Cuti ? "Cuti" :
                                    cur->data.status == StatusDosen::Pensiun ? "Pensiun" : "Tidak Aktif")<<endl;
            cout<<"-------------------------------------"<<endl;
        }

    }

    void hapusDosen() {
    cout << "=====MENU HAPUS DOSEN====" << endl;
    string nidnCari;
    cout << "Masukkan NIDN Dosen Yang Akan di Hapus: ";
    cin >> nidnCari;
    
    bool ditemukan = false;
    DoubleLinkedList<Dosen>::Node* temp = listDosen.head;
    size_t index = 0;
    while (temp != nullptr) {
        if (temp->data.nidn == nidnCari) {
            ditemukan = true;
            // Tampilkan data yang akan dihapus
            cout << "\nData Dosen yang akan dihapus:" << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "NIDN: " << temp->data.nidn << endl;
            cout << "Fakultas: " << temp->data.fakultas << endl;
            cout << "Jurusan: " << temp->data.jurusan << endl;
            
            // Konfirmasi penghapusan
            char konfirmasi;
            cout << "\nApakah Anda yakin ingin menghapus data dosen ini? (y/n): ";
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                listDosen.hapusData(index);
                cout << "Dosen dengan NIDN " << nidnCari << " telah dihapus.\n";
                updateFileDosen();
            } else {
                cout << "Penghapusan dibatalkan.\n";
            }
            break;
        }
        temp = temp->next;
        ++index;
    }
    
    if (!ditemukan) {
        cout << "Dosen dengan NIDN " << nidnCari << " tidak ditemukan.\n";
    }
}

    void editDosen(){
        updateFileDosen();
        cout << "=====MENU EDIT DOSEN=====" << endl;
        string nidnCari;
        cout << "Masukkan NIDN dosen yang akan diedit: ";
        cin >> nidnCari;
        bool ditemukan = false;
        for (DoubleLinkedList<Dosen>::Node* temp=listDosen.head; temp!=nullptr; temp=temp->next) {
            if (temp->data.nidn == nidnCari) {
                ditemukan = true;
                cout << "Data ditemukan. Masukkan data baru:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                cout << "Nama: " << temp->data.nama << "\n";
                cout << "NIP: " << temp->data.nip << "\n";
                cout << "Fakultas: " << temp->data.fakultas << "\n";
                cout << "Jurusan: " << temp->data.jurusan << "\n";
                cout << "Gelar Depan: " << temp->data.gelarDepan << "\n";
                cout << "Gelar Belakang: " << temp->data.gelarBelakang << "\n";
                cout << "Jabatan Akademik: " << temp->data.jabatanAkademik << "\n";
                cout << "Pendidikan Terakhir: " << temp->data.pendidikanTerakhir << "\n";
                cout << "Email: " << temp->data.email << "\n";
                cout << "No HP: " << temp->data.noHp << "\n";
                cout << "Alamat: " << temp->data.alamat << "\n";
                cout << "Jenis Kelamin: " << (temp->data.gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
                cout << "Tahun Masuk: " << temp->data.tahunMasuk << "\n";
                cout << "Status: " << (temp->data.status == StatusDosen::Aktif ? "Aktif" :
                                    temp->data.status == StatusDosen::Cuti ? "Cuti" :
                                    temp->data.status == StatusDosen::Pensiun ? "Pensiun" : "Tidak Aktif") << "\n";
                cout << "==============================\n";
                cout << " Masukkan Data Baru: \n";
                cout << "\nMasukkan nama dosen: ";
                cin.ignore();
                getline(cin, temp->data.nama);
                cout << "Masukkan NIP:";
                cin >> temp->data.nip;
                cout << "Masukkan fakultas:";
                cin >> temp->data.fakultas;
                cout << "Masukkan jurusan:";
                cin >> temp->data.jurusan;
                cout << "Gelar Depan:";
                cin >> temp->data.gelarDepan;
                cout << "Gelar Belakang:";
                cin >> temp->data.gelarBelakang;
                cout << "Jabatan Akademik:";
                cin >> temp->data.jabatanAkademik;
                cout << "Pendidikan Terakhir:";
                cin >> temp->data.pendidikanTerakhir;
                cout << "Email:";
                cin >> temp->data.email;
                cout << "No HP:";
                cin >> temp->data.noHp;
                cout << "Alamat:";
                cin >> temp->data.alamat;
                cout << "Jenis Kelamin (1. Laki-laki, 2. Perempuan):";
                int pilihGender;
                cin >> pilihGender;
                temp->data.gender = (pilihGender == 1) ? JenisKelamin::LakiLaki : JenisKelamin::Perempuan;
                cout << "Tahun Masuk:";
                cin >> temp->data.tahunMasuk;
                cout << "Status (1. Aktif, 2. Cuti, 3. Pensiun, 4. Tidak Aktif):";
                int pilihStatus;
                cin >> pilihStatus;
                switch(pilihStatus){
                    case 1:
                        temp->data.status = StatusDosen::Aktif;
                        break;
                    case 2:
                        temp->data.status = StatusDosen::Cuti;
                        break;
                    case 3:
                        temp->data.status = StatusDosen::Pensiun;
                        break;
                    case 4:
                        temp->data.status = StatusDosen::TidakAktif;
                        break;
                    default:
                        cout<<"Pilihan tidak valid! Mengatur status ke Aktif secara default."<<endl;
                        temp->data.status = StatusDosen::Aktif;
                        break;
                }
                cout << "Data dosen berhasil diperbarui!\n";
                updateFileDosen();
                break;
            }

        }
        if (!ditemukan) {
            cout << "Dosen dengan NIDN " << nidnCari << " tidak ditemukan.\n";
        }
    }

    void cekKeaktifanDosen() {
        cout << "=====MENU CEK KEAKTIFAN DOSEN=====" << endl;
        string nidnCari;
        cout << "Masukkan NIDN dosen yang akan dicek: ";
        cin >> nidnCari;
        bool ditemukan = false;
        for (DoubleLinkedList<Dosen>::Node* temp=listDosen.head; temp!=nullptr; temp=temp->next) {
            if (temp->data.nidn == nidnCari) {
                ditemukan = true;
                cout << "Data ditemukan:\n";
                cout << "Nama: " << temp->data.nama << "\n";
                cout << "Status: " << (temp->data.status == StatusDosen::Aktif ? "Aktif" :
                                    temp->data.status == StatusDosen::Cuti ? "Cuti" :
                                    temp->data.status == StatusDosen::Pensiun ? "Pensiun" : "Tidak Aktif") << "\n";
                break;
            }
        }
        if (!ditemukan) {
            cout << "Dosen dengan NIDN " << nidnCari << " tidak ditemukan.\n";
        }
    }
};

//CLASS UNTUK MENU UTAMA MATAKULIAH
class ManajemenMatakuliah {
private:
    
public:
    DoubleLinkedList<MataKuliah> listMatakuliah;
    ManajemenMatakuliah() {
        if (listMatakuliah.head == nullptr) {
        // Jika file kosong, tambahkan data mata kuliah awal
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

        UpdateFileMataKuliah();
    }

    
    void tambahMataKuliahLangsung(const MataKuliah& mk) {
        // gunakan helper pada DoubleLinkedList
        listMatakuliah.tambahData(mk);
    }

   
    void tampilSemuaMataKuliah() {
        if (listMatakuliah.head == nullptr) {
            cout << "Belum ada mata kuliah yang terdaftar." << endl;
            return;
        }

        cout << "\n=== Daftar Semua Mata Kuliah Berdasarkan Semester ===" << endl;
        for (int semester = 1; semester <= 8; semester++) {
            cout << "\n--- Semester " << semester << " ---" << endl;
            DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
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

    void tampilkanMatakuliahGanjil() {
       
        DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
        bool ditemukan = false;
        int no = 1;

        auto clip = [](const string& s, size_t w){
            if (s.size() <= w) return s;
            if (w <= 3) return s.substr(0, w);
            return s.substr(0, w-3) + "...";
        };

        cout << string(105,'=') << "\n";
        cout << "                                            DAFTAR MATA KULIAH SEMESTER GANJIL\n";
        cout << string(105,'=') << "\n";
        cout << left
             << setw(4)  << "No"
             << setw(10) << "Kode"
             << setw(35) << "Nama"
             << setw(6)  << "SKS"
             << setw(10) << "Semester"
             << setw(18) << "Jurusan"
             << setw(16) << "Fakultas"
             << setw(8)  << "Wajib"
             
             << "\n";
        cout << string(105,'-') << "\n";

        while (temp != nullptr) {
            if (temp->data.semester % 2 != 0) {
                cout << left
                     << setw(4)  << no++
                     << setw(10) << clip(temp->data.kodeMK, 10)
                     << setw(35) << clip(temp->data.namaMK, 35 )
                     << setw(6)  << temp->data.sks
                     << setw(10) << temp->data.semester
                     << setw(18) << clip(temp->data.jurusan, 18)
                     << setw(16) << clip(temp->data.fakultas, 16)
                     << setw(8)  << (temp->data.wajib ? "Ya" : "Tidak")
                     
                     << "\n";
                ditemukan = true;
            }
            temp = temp->next;
        }
        if (!ditemukan) {
            cout << "Tidak ada mata kuliah untuk semester ganjil." << endl;
        } else {
            cout << string(105,'=') << "\n";
        }
    }

    void tampilkanMatakuliahGenap() {
        
        DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
        bool ditemukan = false;
        int no = 1;

        auto clip = [](const string& s, size_t w){
            if (s.size() <= w) return s;
            if (w <= 3) return s.substr(0, w);
            return s.substr(0, w-3) + "...";
        };

        cout << string(105,'=') << "\n";
        cout << "                                            DAFTAR MATA KULIAH SEMESTER GENAP\n";
        cout << string(105,'=') << "\n";
        cout << left
             << setw(4)  << "No"
             << setw(10) << "Kode"
             << setw(35) << "Nama"
             << setw(6)  << "SKS"
             << setw(10) << "Semester"
             << setw(18) << "Jurusan"
             << setw(16) << "Fakultas"
             << setw(8)  << "Wajib"
            
             << "\n";
        cout << string(105,'-') << "\n";

        while (temp != nullptr) {
            if (temp->data.semester % 2 == 0) {
                cout << left
                     << setw(4)  << no++
                     << setw(10) << clip(temp->data.kodeMK, 10)
                     << setw(35) << clip(temp->data.namaMK, 35)
                     << setw(6)  << temp->data.sks
                     << setw(10) << temp->data.semester
                     << setw(18) << clip(temp->data.jurusan, 18)
                     << setw(16) << clip(temp->data.fakultas, 16)
                     << setw(8)  << (temp->data.wajib ? "Ya" : "Tidak")
                     << "\n";
                ditemukan = true;
            }
            temp = temp->next;
        }
        if (!ditemukan) {
            cout << "Tidak ada mata kuliah untuk semester genap." << endl;
        } else {
            cout << string(105,'=') << "\n";
        }
    }

    
    void tampilMataKuliahPerSemester() {
        int semester;
        cout << "Masukkan semester yang ingin ditampilkan: ";
        cin >> semester;

        cout << "\n=== Mata Kuliah Semester " << semester << " ===" << endl;
        DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
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

    void tampilMataKuliahPerSem(int semester) {
        

        cout << "\n=== Mata Kuliah Semester " << semester << " ===" << endl;
       DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
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
        cout << "\n=== Tambah Mata Kuliah Baru ===" << endl;
        MataKuliah mk;
        cout << "Masukkan kode mata kuliah: ";
        cin >> mk.kodeMK;
        cin.ignore();
        cout << "Masukkan nama mata kuliah: ";
        getline(cin, mk.namaMK);
        cout << "Masukkan jumlah SKS: ";
        cin >> mk.sks;
        cin.ignore();
        cout << "Masukkan deskripsi mata kuliah: ";
        getline(cin, mk.deskripsi);
        cout << "Masukkan semester: ";
        cin >> mk.semester;
        cin.ignore();
        cout << "Masukkan jurusan: ";
        getline(cin, mk.jurusan);
        cout << "Masukkan fakultas: ";
        getline(cin, mk.fakultas);
        cout << "Apakah mata kuliah ini wajib? (1. Ya, 2. Tidak): ";
        int pilihWajib;
        cin >> pilihWajib;
        mk.wajib = (pilihWajib == 1);

        listMatakuliah.tambahData(mk);

        cout << "Mata kuliah berhasil ditambahkan!" << endl;
        UpdateFileMataKuliah();
    }

    void editMataKuliah(){
        UpdateFileMataKuliah();
        cout<<"=====MENU EDIT MATA KULIAH====="<<endl;
        string kodeCari;
        cout<<"Masukkan Kode Matakuliah yang akan di edit :";
        cin>>kodeCari;
        bool ditemukan = false;
        for(DoubleLinkedList<MataKuliah>::Node* temp=listMatakuliah.head;temp!=nullptr;temp=temp->next){
            if(temp->data.kodeMK==kodeCari){
                ditemukan=true;
                cout<<"Data di temukan\n";
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
                UpdateFileMataKuliah();
                break;

            }
        }

        if (!ditemukan){
            cout<<"Mata kuliah dengan kode "<<kodeCari<<" tidak ditemukan."<<endl;
        }
    }

    void hapusMataKuliah(){
        cout<<"=====MENU HAPUS MATA KULIAH====="<<endl;
        string kodeCari;
        cout<<"Masukkan Kode Matakuliah yang akan di hapus :";
        cin>>kodeCari;
        DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
        size_t index = 0;
        bool ditemukan=false;

        while(temp!=nullptr){
            if(temp->data.kodeMK==kodeCari){
                ditemukan=true;

                //konfirmasi penghapusan
                char konfirmasi;
                cout<<"Apakah anda yakin ingin menghapus mata kuliah ini? (y/n): ";
                cin>>konfirmasi;
                if(konfirmasi!='y' && konfirmasi!='Y'){
                    cout<<"Penghapusan dibatalkan."<<endl;
                    return;
                }

                // gunakan helper hapusData berdasarkan indeks
                listMatakuliah.hapusData(index);
                cout<<"Mata kuliah dengan kode "<<kodeCari<<" berhasil dihapus."<<endl;
                UpdateFileMataKuliah();
                break;
            }
            temp=temp->next;
            ++index;
        }

        if(!ditemukan){
            cout<<"Mata kuliah dengan kode "<<kodeCari<<" tidak ditemukan."<<endl;
        }
    }

    void tarikDataDariFileMataKuliah() {
        listMatakuliah.clear();
        ifstream inFile("dataMataKuliah.txt");

        if (!inFile.is_open()) {
            cout << "File dataMataKuliah.txt tidak ditemukan atau gagal dibuka." << endl;
            return;
        }

        string line;
        MataKuliah mk;

        while (getline(inFile, line)) {

            // Trim kiri spasi/tabs
            while (!line.empty() && (line[0] == ' ' || line[0] == '\t'))
                line.erase(0, 1);

            auto trim = [](string &s){
                while (!s.empty() && isspace((unsigned char)s.front())) s.erase(0,1);
                while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
            };

            size_t pos = line.find(":");
            string value = (pos != string::npos) ? line.substr(pos+1) : string();
            trim(value);

            if (line.find("Kode ") == 0) {
                mk = MataKuliah(); // reset data MK baru
                mk.kodeMK = value;
            } else if (line.find("Nama ") == 0) {
                mk.namaMK = value;
            } else if (line.find("SKS ") == 0) {
                try {
                    mk.sks = stoi(value);
                } catch (...) {
                    mk.sks = 0;
                }
            } else if (line.find("Deskripsi ") == 0) {
                mk.deskripsi = value;
            } else if (line.find("Semester ") == 0) {
                try {
                    mk.semester = stoi(value);
                } catch (...) {
                    mk.semester = 0;
                }
            }
            else if (line.find("Jurusan ") == 0) {
                mk.jurusan = value;
            }
            else if (line.find("Fakultas ") == 0) {
                mk.fakultas = value;
            }
            else if (line.find("Wajib ") == 0) {
                mk.wajib = (value == "Ya");
            }
            else if (line.find("-----") != string::npos) {
                // Akhir data 1 mata kuliah → masukkan ke linked list
                tambahMataKuliahLangsung(mk);
            }
        }

        inFile.close();
    }

   



    //update mata kuliah ke file per semester
    void UpdateFileMataKuliah() {
    // Tarik data dari file ke linked list
    // tarikDataDariFileMataKuliah();

    // Clear isi file
    // clearFileMataKuliah();

    // Tulis ulang data dari linked list ke file
    ofstream outFile("dataMataKuliah.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data mata kuliah." << endl;
            return;
        }

        for (int semester = 1; semester <= 8; semester++) {
            outFile << "====MATA KULIAH SEMESTER " << semester << "====" << endl;
            DoubleLinkedList<MataKuliah>::Node* temp = listMatakuliah.head;
            bool ditemukan = false;

            while (temp != nullptr) {
                if (temp->data.semester == semester) {
                    outFile << "Kode :" << temp->data.kodeMK << endl;
                    outFile << "   Nama :" << temp->data.namaMK << endl;
                    outFile << "   SKS :" << temp->data.sks << endl;
                    outFile << "   Deskripsi :" << temp->data.deskripsi << endl;
                    outFile << "   Semester :" << temp->data.semester << endl;
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
    }

    void clearFileMataKuliah(){
        ofstream in("dataMataKuliah.txt", ios::trunc);
        in.close();
    }

    
    
};

//CLASS UNTUK MENU UTAMA DOSEN MATA KULIAH (CIRCULAR LINKED LIST)
class ManajemenDosenMataKuliah {
private:
    
    int jumlah = 0;

public:
    DoubleLinkedList<DosenMataKuliah> dmkList;
    ManajemenDosenMataKuliah() {

    if (dmkList.head == nullptr) {
    // Dosen pertama
    tambahDosenMataKuliahLangsung({"1234567801", "IF101", "DMK001"});
    tambahDosenMataKuliahLangsung({"1234567801", "IF102", "DMK002"});
    tambahDosenMataKuliahLangsung({"1234567801", "IF103", "DMK003"});
    // Dosen ke 2
    tambahDosenMataKuliahLangsung({"1234567802", "IF104", "DMK004"});
    tambahDosenMataKuliahLangsung({"1234567802", "IF105", "DMK005"});
    // Dosen ke 3
    tambahDosenMataKuliahLangsung({"1234567803", "IF106", "DMK006"});
    tambahDosenMataKuliahLangsung({"1234567803", "IF107", "DMK007"});
    tambahDosenMataKuliahLangsung({"1234567803", "IF108", "DMK008"}); 
    // Dosen ke 4
    tambahDosenMataKuliahLangsung({"1234567804", "IF111", "DMK009"});
    tambahDosenMataKuliahLangsung({"1234567804", "IF112", "DMK010"}); 
    // Dosen ke 5
    tambahDosenMataKuliahLangsung({"1234567805", "IF113", "DMK011"});
    tambahDosenMataKuliahLangsung({"1234567805", "IF114", "DMK012"});
    tambahDosenMataKuliahLangsung({"1234567805", "IF115", "DMK013"});  
    // Dosen ke 6
    tambahDosenMataKuliahLangsung({"1234567806", "IF116", "DMK014"});
    tambahDosenMataKuliahLangsung({"1234567806", "IF117", "DMK015"}); 
    // Dosen ke 7
    tambahDosenMataKuliahLangsung({"1234567807", "IF121", "DMK016"});
    tambahDosenMataKuliahLangsung({"1234567807", "IF122", "DMK017"});
    tambahDosenMataKuliahLangsung({"1234567807", "IF123", "DMK018"}); 
    // Dosen ke 8
    tambahDosenMataKuliahLangsung({"1234567808", "IF124", "DMK019"});
    tambahDosenMataKuliahLangsung({"1234567808", "IF125", "DMK020"});  
    // Dosen ke 9
    tambahDosenMataKuliahLangsung({"1234567809", "IF126", "DMK021"});
    tambahDosenMataKuliahLangsung({"1234567809", "IF127", "DMK022"});
    tambahDosenMataKuliahLangsung({"1234567809", "IF128", "DMK023"}); 
    // Dosen ke 10
    tambahDosenMataKuliahLangsung({"1234567810", "IF131", "DMK024"});
    tambahDosenMataKuliahLangsung({"1234567810", "IF132", "DMK025"}); 
    // Dosen ke 11
    tambahDosenMataKuliahLangsung({"1234567811", "IF133", "DMK026"});
    tambahDosenMataKuliahLangsung({"1234567811", "IF134", "DMK027"});
    tambahDosenMataKuliahLangsung({"1234567811", "IF135", "DMK028"});  
    // Dosen ke 12
    tambahDosenMataKuliahLangsung({"1234567812", "IF136", "DMK029"});
    tambahDosenMataKuliahLangsung({"1234567812", "IF137", "DMK030"});  
    // Dosen ke 13
    tambahDosenMataKuliahLangsung({"1234567813", "IF141", "DMK031"});
    tambahDosenMataKuliahLangsung({"1234567813", "IF142", "DMK032"});
    tambahDosenMataKuliahLangsung({"1234567813", "IF143", "DMK033"});  
    // Dosen ke 14
    tambahDosenMataKuliahLangsung({"1234567814", "IF144", "DMK034"});
    tambahDosenMataKuliahLangsung({"1234567814", "IF145", "DMK035"}); 
    // Dosen ke 15
    tambahDosenMataKuliahLangsung({"1234567815", "IF146", "DMK036"});
    tambahDosenMataKuliahLangsung({"1234567815", "IF147", "DMK037"});
    tambahDosenMataKuliahLangsung({"1234567815", "IF148", "DMK038"});

    tambahDosenMataKuliahLangsung({"1234567819", "IF121", "DMK038"});
    tambahDosenMataKuliahLangsung({"1234567827", "IF121", "DMK039"});

    tambahDosenMataKuliahLangsung({"1234567803", "IF122", "DMK040"});
    tambahDosenMataKuliahLangsung({"1234567829", "IF122", "DMK041"});

    tambahDosenMataKuliahLangsung({"1234567811", "IF123", "DMK042"});
    tambahDosenMataKuliahLangsung({"1234567808", "IF123", "DMK043"});

    tambahDosenMataKuliahLangsung({"1234567824", "IF124", "DMK044"});
    tambahDosenMataKuliahLangsung({"1234567801", "IF124", "DMK045"});

    tambahDosenMataKuliahLangsung({"1234567814", "IF125", "DMK046"});
    tambahDosenMataKuliahLangsung({"1234567830", "IF125", "DMK047"});

    tambahDosenMataKuliahLangsung({"1234567806", "IF126", "DMK048"});
    tambahDosenMataKuliahLangsung({"1234567821", "IF126", "DMK049"});

    tambahDosenMataKuliahLangsung({"1234567817", "IF127", "DMK050"});
    tambahDosenMataKuliahLangsung({"1234567809", "IF127", "DMK051"});

    tambahDosenMataKuliahLangsung({"1234567826", "IF128", "DMK052"});
    tambahDosenMataKuliahLangsung({"1234567804", "IF128", "DMK053"});

    }
    updateFileDosenMataKuliah();
    }

    // Menghapus semua node (digantikan destructor)
    void clear() {
        if (dmkList.head == nullptr) return;
        
        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        DoubleLinkedList<DosenMataKuliah>::Node* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != dmkList.head);
        
        dmkList.head = nullptr;
        dmkList.tail = nullptr;
        jumlah = 0;
    }

    // Tambah data dosen mata kuliah ke circular linked list
    void tambahDosenMataKuliahLangsung(const DosenMataKuliah& dmk) {
        DoubleLinkedList<DosenMataKuliah>::Node* newNode = new DoubleLinkedList<DosenMataKuliah>::Node(dmk);

        if (dmkList.head == nullptr) {
            dmkList.head = newNode;
            dmkList.tail = newNode;
            newNode->next = dmkList.head;
            newNode->prev = dmkList.tail;
        } else {
            dmkList.tail->next = newNode;
            newNode->prev = dmkList.tail;
            dmkList.tail = newNode;
            dmkList.tail->next = dmkList.head;
            dmkList.head->prev = dmkList.tail;
        }
        jumlah++;
    }


    // Tambah data dosen mata kuliah melalui input
    void tambahDosenMataKuliah() {
        cout << "===== MENU TAMBAH DOSEN MATA KULIAH =====" << endl;
        DosenMataKuliah dmkBaru;
        
        cout << "Masukkan NIDN Dosen: ";
        cin >> dmkBaru.nidnDosen;
        
        cout << "Masukkan Kode Mata Kuliah: ";
        cin >> dmkBaru.kodeMK;
        
        cout << "Masukkan Kode Dosen Mata Kuliah: ";
        cin >> dmkBaru.kdDosenMk;

        if (isKdDosenMkExist(dmkBaru.kdDosenMk)) {
            cout << "Error: Kode Dosen Mata Kuliah '" << dmkBaru.kdDosenMk << "' sudah ada!" << endl;
            return;
        }

        tambahDosenMataKuliahLangsung(dmkBaru);
        cout << "Data dosen mata kuliah berhasil ditambahkan!" << endl;
        updateFileDosenMataKuliah();
    }

    // Cek apakah kdDosenMk sudah ada
    bool isKdDosenMkExist(const string& kdDosenMk) {
        if (dmkList.head == nullptr) return false;
        
        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        do {
            if (current->data.kdDosenMk == kdDosenMk) {
                return true;
            }
            current = current->next;
        } while (current != dmkList.head);
        
        return false;
    }


    // Hapus data dosen mata kuliah berdasarkan kdDosenMk
    void hapusDosenMataKuliah() {
        updateFileDosenMataKuliah();
        cout << "===== MENU HAPUS DOSEN MATA KULIAH =====" << endl;
        if (dmkList.head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah yang akan dihapus: ";
        cin >> kdCari;

        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        
        bool ditemukan = false;

        do {
            if (current->data.kdDosenMk == kdCari) {
                ditemukan = true;
                
                if (current == dmkList.head && current == dmkList.tail) {
                    dmkList.head = nullptr;
                    dmkList.tail = nullptr;
                } else if (current == dmkList.head) {
                    // Kasus 2: Hapus head
                    dmkList.head = dmkList.head->next;
                    dmkList.head->prev = NULL;
                    dmkList.tail->next = NULL;
                } else if (current == dmkList.tail) {
                    // Kasus 3: Hapus tail
                    dmkList.tail = dmkList.tail->prev;
                    dmkList.tail->next = NULL;
                } else {
                    // Kasus 4: Hapus node di tengah
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                
                delete current;
                jumlah--;
                cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' berhasil dihapus!" << endl;
                updateFileDosenMataKuliah();
                break;
            }
            current = current->next;
        } while (current != dmkList.head);

        if (!ditemukan) {
            cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' tidak ditemukan!" << endl;
        }
    }

    // Edit data dosen mata kuliah
    void editDosenMataKuliah() {
        cout << "===== MENU EDIT DOSEN MATA KULIAH =====" << endl;
        if (dmkList.head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah yang akan diedit: ";
        cin >> kdCari;

        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        bool ditemukan = false;

        do {
            if (current->data.kdDosenMk == kdCari) {
                ditemukan = true;
                cout << "\nData ditemukan:" << endl;
                cout << "NIDN Dosen saat ini: " << current->data.nidnDosen << endl;
                cout << "Kode MK saat ini: " << current->data.kodeMK << endl;
                cout << "Kode Dosen MK saat ini: " << current->data.kdDosenMk << endl;
                
                cout << "\nMasukkan data baru:" << endl;
                cout << "Masukkan NIDN Dosen baru: ";
                cin >> current->data.nidnDosen;
                
                cout << "Masukkan Kode MK baru: ";
                cin >> current->data.kodeMK;
                
                cout << "Masukkan Kode Dosen MK baru: ";
                string kdBaru;
                cin >> kdBaru;
                
                if (kdBaru != current->data.kdDosenMk && isKdDosenMkExist(kdBaru)) {
                    cout << "Error: Kode Dosen Mata Kuliah '" << kdBaru << "' sudah ada!" << endl;
                    return;
                }
                current->data.kdDosenMk = kdBaru;
                
                cout << "Data dosen mata kuliah berhasil diperbarui!" << endl;
                updateFileDosenMataKuliah();
                break;
            }
            current = current->next;
        } while (current != dmkList.head);

        if (!ditemukan) {
            cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' tidak ditemukan!" << endl;
        }
    }

    // Tampilkan semua data dosen mata kuliah
    void tampilSemuaDosenMataKuliah() {
        cout << "\n=== DAFTAR SEMUA DOSEN MATA KULIAH ===" << endl;
        
        if (dmkList.head == nullptr) {
            cout << "Tidak ada data dosen mata kuliah." << endl;
            return;
        }

        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        int counter = 1;      
        
        cout << "Jumlah data: " << jumlah << endl;
        cout << "========================================" << endl;
        
        do {
            cout << "Data ke-" << counter << ":" << endl;
            cout << "  NIDN Dosen    : " << current->data.nidnDosen << endl;
            cout << "  Kode MK       : " << current->data.kodeMK << endl;
            cout << "  Kode Dosen MK : " << current->data.kdDosenMk << endl;
            cout << "----------------------------------------" << endl;
            
            current = current->next;
            counter++;
        } while (current != dmkList.head);
    }

    // Cari data dosen mata kuliah berdasarkan kdDosenMk
    void cariDosenMataKuliah() {
        cout << "===== MENU CARI DOSEN MATA KULIAH =====" << endl;
        if (dmkList.head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah: ";
        cin >> kdCari;

        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        bool ditemukan = false;
        int posisi = 1;

        do {
            if (current->data.kdDosenMk == kdCari) {
                ditemukan = true;
                cout << "\nData ditemukan (Posisi: " << posisi << "):" << endl;
                cout << "  NIDN Dosen    : " << current->data.nidnDosen << endl;
                cout << "  Kode MK       : " << current->data.kodeMK << endl;
                cout << "  Kode Dosen MK : " << current->data.kdDosenMk << endl;
                break;
            }
            current = current->next;
            posisi++;
        } while (current != dmkList.head);

        if (!ditemukan) {
            cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' tidak ditemukan!" << endl;
        }
    }


    // Update data ke file
    void updateFileDosenMataKuliah() {

        // clearFileDosenMataKuliah();

        ofstream outFile("dataDosenMataKuliah.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data dosen mata kuliah." << endl;
            return;
        }

        if (dmkList.head == nullptr) {
            outFile << "Tidak ada data dosen mata kuliah." << endl;
            outFile.close();
            return;
        }

        DoubleLinkedList<DosenMataKuliah>::Node* current = dmkList.head;
        int counter = 1;
        
        outFile << "=== DATA DOSEN MATA KULIAH ===" << endl;
        outFile << "Jumlah data: " << jumlah << endl;
        outFile << "========================================" << endl;
        
        do {
            outFile << "Data ke-" << counter << ":" << endl;
            outFile << "  NIDN Dosen    : " << current->data.nidnDosen << endl;
            outFile << "  Kode MK       : " << current->data.kodeMK << endl;
            outFile << "  Kode Dosen MK : " << current->data.kdDosenMk << endl;
            outFile << "----------------------------------------" << endl;
            
            current = current->next;
            counter++;
        } while (current != dmkList.head);

        outFile.close();
        // cout << "Data dosen mata kuliah berhasil disimpan ke file." << endl;
    }

    // Tarik data dari file
    void tarikDataDariFileDosenMataKuliah() {
        ifstream inFile("dataDosenMataKuliah.txt");
        if (!inFile.is_open()) {
            // cout << "File dataDosenMataKuliah.txt tidak ditemukan. Akan dibuat file baru." << endl;
            return;
        }

        clear(); // Hapus data existing sebelum memuat dari file

        string line;
        DosenMataKuliah dmk;
        bool readingData = false;

        while (getline(inFile, line)) {
            if (line.find("NIDN Dosen    : ") != string::npos) {
                dmk.nidnDosen = line.substr(16);
            } else if (line.find("Kode MK       : ") != string::npos) {
                dmk.kodeMK = line.substr(16);
            } else if (line.find("Kode Dosen MK : ") != string::npos) {
                dmk.kdDosenMk = line.substr(16);
            } else if (line.find("----------------------------------------") != string::npos) {
                // Akhir dari satu data, tambahkan ke linked list
                if (!dmk.nidnDosen.empty() && !dmk.kodeMK.empty() && !dmk.kdDosenMk.empty()) {
                    tambahDosenMataKuliahLangsung(dmk);
                    dmk = DosenMataKuliah(); // Reset untuk data berikutnya
                }
            }
        }

        inFile.close();
    }

    // Clear file
    void clearFileDosenMataKuliah() {
        ofstream in("dataDosenMataKuliah.txt", ios::trunc);
        in.close();
        cout << "File dataDosenMataKuliah.txt telah dikosongkan." << endl;
    }


};


class ManajemenKelas {
private:
    DoubleLinkedList<Kelas> daftarKelas;

public:
    ManajemenKelas() {
        // Inisialisasi dengan beberapa data kelas jika list masih kosong
        if (daftarKelas.size() == 0) {
            tambahKelasLangsung({"IF101-A", "A", 30});
            tambahKelasLangsung({"IF101-B", "B", 30});
            tambahKelasLangsung({"IF101-C", "C", 30});

            tambahKelasLangsung({"IF102-A", "A", 25});
            tambahKelasLangsung({"IF102-B", "B", 25});
            tambahKelasLangsung({"IF102-C", "C", 25});

            tambahKelasLangsung({"IF103-A", "A", 20});
            tambahKelasLangsung({"IF103-B", "B", 20});
            tambahKelasLangsung({"IF103-C", "C", 20});
            
            tambahKelasLangsung({"IF104-A", "A", 20});
            tambahKelasLangsung({"IF104-B", "B", 20});
            tambahKelasLangsung({"IF104-C", "C", 20});

            tambahKelasLangsung({"IF105-A", "A", 20});
            tambahKelasLangsung({"IF105-B", "B", 20});
            tambahKelasLangsung({"IF105-C", "C", 20});

            tambahKelasLangsung({"IF106-A", "A", 20});
            tambahKelasLangsung({"IF106-B", "B", 20});
            tambahKelasLangsung({"IF106-C", "C", 20});

            tambahKelasLangsung({"IF107-A", "A", 20});
            tambahKelasLangsung({"IF107-B", "B", 20});
            tambahKelasLangsung({"IF107-C", "C", 20});

            tambahKelasLangsung({"IF108-A", "A", 20});
            tambahKelasLangsung({"IF108-B", "B", 20});
            tambahKelasLangsung({"IF108-C", "C", 20});
        }
        updateFileKelas();
    }

    void tambahKelasLangsung(const Kelas& kelasBaru) {
        daftarKelas.tambahData(kelasBaru);
    }

    void tambahKelas() {    
        Kelas kelasBaru;
        cout << "\n=== Tambah Kelas Baru ===" << endl;
        cout << "Masukkan kode kelas: ";
        cin >> kelasBaru.kdKelas;
        cin.ignore();
        cout << "Masukkan nama kelas: ";
        getline(cin, kelasBaru.namaKelas);
        cout << "Masukkan batas kapasitas kelas: ";
        cin >> kelasBaru.batasKelas;
        cin.ignore();

        tambahKelasLangsung(kelasBaru);
        cout << "Kelas berhasil ditambahkan!" << endl;
        updateFileKelas();
    }

    void editKelas() {
        string kodeCari;
        cout << "\n=== Edit Kelas ===" << endl;
        cout << "Masukkan kode kelas yang akan diedit: ";
        cin >> kodeCari;

        // akses Node internal (Node dan head publik di implementasimu)
        DoubleLinkedList<Kelas>::Node* temp = daftarKelas.head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->data.kdKelas == kodeCari) {
                ditemukan = true;
                cout << "Masukkan nama kelas baru: ";
                cin.ignore();
                getline(cin, temp->data.namaKelas);
                cout << "Masukkan batas kapasitas kelas baru: ";
                cin >> temp->data.batasKelas;
                cin.ignore();
                cout << "Kelas berhasil diperbarui!" << endl;
                updateFileKelas();
                break;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Kelas dengan kode " << kodeCari << " tidak ditemukan." << endl;
        }
    }

    void hapusKelas() {
        string kodeCari;
        cout << "\n=== Hapus Kelas ===" << endl;
        cout << "Masukkan kode kelas yang akan dihapus: ";
        cin >> kodeCari;

        DoubleLinkedList<Kelas>::Node* temp = daftarKelas.head;
        DoubleLinkedList<Kelas>::Node* prev = nullptr;
        bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->data.kdKelas == kodeCari) {
                ditemukan = true;
                if (prev == nullptr) {
                    // hapus head
                    daftarKelas.head = temp->next;
                    if (daftarKelas.head != nullptr) {
                        daftarKelas.head->prev = nullptr;
                    } else {
                        daftarKelas.tail = nullptr; // list jadi kosong
                    }
                } else {
                    // hapus di tengah atau tail
                    prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = prev;
                    } else {
                        daftarKelas.tail = prev; // dihapus tail
                    }
                }

                delete temp;
                // update ukuran karena kita manipulasi langsung struktur internal
                if (daftarKelas.sz > 0) daftarKelas.sz--;

                updateFileKelas();
                cout << "Kelas dengan kode " << kodeCari << " berhasil dihapus." << endl;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Kelas dengan kode " << kodeCari << " tidak ditemukan." << endl;
        }
    }

    void tampilSemuaKelas() {
        if (daftarKelas.size() == 0) {
            cout << "Belum ada kelas yang terdaftar." << endl;
            return;
        }

        cout << "\n=== Daftar Semua Kelas ===" << endl;
        DoubleLinkedList<Kelas>::Node* temp = daftarKelas.head;
        while (temp != nullptr) {
            cout << "Kode Kelas: " << temp->data.kdKelas
                 << ", Nama Kelas: " << temp->data.namaKelas
                 << ", Kapasitas: " << temp->data.batasKelas << endl;
            temp = temp->next;
        }
    }
    
    void clearKelas() {
        // gunakan clear() dari DoubleLinkedList agar konsisten (menghapus node + set ukuran)
        daftarKelas.clear();
        cout << "Semua data kelas telah dihapus dari memory." << endl;
    }

    

    void tarikDataDariFileKelas() {
    ifstream inFile("dataKelas.txt");
    if (!inFile.is_open()) {
        cout << "File dataKelas.txt tidak ditemukan. Akan dibuat file baru." << endl;
        return;
    }

    // Hapus data existing sebelum memuat dari file
    daftarKelas.clear();

    auto trim = [](string &s) {
        // trim leading
        size_t start = 0;
        while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) ++start;
        // trim trailing
        size_t end = s.size();
        while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) --end;
        if (start == 0 && end == s.size()) return; // tidak perlu ubah
        s = s.substr(start, end - start);
    };

    string line;
    Kelas kelasSementara;
    bool adaDataSementara = false;

    while (getline(inFile, line)) {
        // cari delimiter ": "
        size_t pos = line.find(": ");
        string value;
        if (pos != string::npos) {
            value = line.substr(pos + 2);
            trim(value);
        } else {
            value = "";
        }

        if (line.find("Kode Kelas") != string::npos) {
            kelasSementara.kdKelas = value;
            adaDataSementara = true;
        } else if (line.find("Nama Kelas") != string::npos) {
            kelasSementara.namaKelas = value;
        } else if (line.find("Kapasitas") != string::npos) {
            try {
                kelasSementara.batasKelas = stoi(value);
            } catch (...) {
                kelasSementara.batasKelas = 0;
            }
        } else if (line.find("--------------------------") != string::npos) {
            // akhir dari satu data kelas -> tambahkan bila ada data
            if (adaDataSementara) {
                tambahKelasLangsung(kelasSementara);
                kelasSementara = Kelas();
                adaDataSementara = false;
            }
        }
    }

    // jika file tidak diakhiri separator, tambahkan data terakhir
    if (adaDataSementara) {
        tambahKelasLangsung(kelasSementara);
    }

    inFile.close();
}

    void updateFileKelas() {
        ofstream outFile("dataKelas.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data kelas." << endl;
            return;
        }

        DoubleLinkedList<Kelas>::Node* temp = daftarKelas.head;
        while (temp != nullptr) {
            outFile << "Kode Kelas: " << temp->data.kdKelas << endl;
            outFile << "Nama Kelas: " << temp->data.namaKelas << endl;
            outFile << "Kapasitas: " << temp->data.batasKelas << endl;
            outFile << "--------------------------" << endl;
            temp = temp->next;
        }

        outFile.close();
    }
};

class ManajemenKelasMahasiswa{
private:
    ManajemenMahasiswa* mhsMgr = nullptr;
    ManajemenKelas* kelasMgr = nullptr;

    
    Mahasiswa dataMhs[1000];
    Kelas dataKelas[100];
    int jumlahMhs = 0;
    int jumlahKelas = 0;

public:
    DoubleLinkedList<KelasMahasiswa> daftarKelasMahasiswa;

    
    ManajemenKelasMahasiswa() {
        if (daftarKelasMahasiswa.size() == 0) {
        // IF101-A: NIM 2400018001-2400018020
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018001"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018002"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018003"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018004"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018005"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018006"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018007"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018008"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018009"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018010"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018011"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018012"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018013"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018014"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018015"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018016"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018017"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018018"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018019"});
        tambahKelasMahasiswaLangsung({"IF101-A", "2400018020"});

        // IF101-B: NIM 2400018021-2400018040
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018021"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018022"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018023"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018024"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018025"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018026"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018027"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018028"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018029"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018030"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018031"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018032"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018033"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018034"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018035"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018036"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018037"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018038"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018039"});
        tambahKelasMahasiswaLangsung({"IF101-B", "2400018040"});

        // IF101-C: NIM 2400018041-2400018060
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018041"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018042"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018043"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018044"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018045"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018046"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018047"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018048"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018049"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018050"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018051"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018052"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018053"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018054"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018055"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018056"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018057"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018058"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018059"});
        tambahKelasMahasiswaLangsung({"IF101-C", "2400018060"});

        // IF102-A: NIM 2400018061-2400018080
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018061"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018062"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018063"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018064"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018065"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018066"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018067"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018068"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018069"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018070"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018071"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018072"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018073"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018074"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018075"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018076"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018077"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018078"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018079"});
        tambahKelasMahasiswaLangsung({"IF102-A", "2400018080"});

        // IF102-B: NIM 2400018081-2400018100
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018081"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018082"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018083"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018084"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018085"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018086"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018087"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018088"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018089"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018090"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018091"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018092"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018093"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018094"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018095"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018096"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018097"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018098"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018099"});
        tambahKelasMahasiswaLangsung({"IF102-B", "2400018100"});

        // IF102-C: NIM 2400018101-2400018120
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018101"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018102"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018103"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018104"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018105"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018106"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018107"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018108"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018109"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018110"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018111"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018112"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018113"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018114"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018115"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018116"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018117"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018118"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018119"});
        tambahKelasMahasiswaLangsung({"IF102-C", "2400018120"});

        // IF103-A: NIM 2400018121-2400018140
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018121"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018122"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018123"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018124"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018125"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018126"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018127"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018128"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018129"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018130"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018131"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018132"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018133"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018134"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018135"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018136"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018137"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018138"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018139"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018140"});

        // IF103-B: NIM 2400018141-2400018160
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018141"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018142"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018143"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018144"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018145"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018146"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018147"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018148"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018149"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018150"});
        }
        updateFileKelasMahasiswa();
    }

   
    ManajemenKelasMahasiswa(ManajemenMahasiswa* mhsManager, ManajemenKelas* kelasManager)
        : mhsMgr(mhsManager), kelasMgr(kelasManager)
    {
        
        if (mhsMgr) mhsMgr->tarikMahasiswadarifile();
        if (kelasMgr) kelasMgr->tarikDataDariFileKelas();
        
        tarikDataDariFileKelasMahasiswa();
    }

   
    void setManagers(ManajemenMahasiswa* m, ManajemenKelas* k) {
        mhsMgr = m;
        kelasMgr = k;
        if (mhsMgr) mhsMgr->tarikMahasiswadarifile();
        if (kelasMgr) kelasMgr->tarikDataDariFileKelas();
    }

    void tambahKelasMahasiswaLangsung(const KelasMahasiswa& km) {
        daftarKelasMahasiswa.tambahData(km);
    }

    void tambahKelasMahasiswa() {
        KelasMahasiswa km;
        cout << "\n=== Tambah Kelas Mahasiswa Baru ===" << endl;
        cout << "Masukkan Kode Kelas: ";
        cin >> km.kdKelas;
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> km.nim;
        tambahKelasMahasiswaLangsung(km);
        cout << "Kelas Mahasiswa berhasil ditambahkan!" << endl;
        updateFileKelasMahasiswa();
    }

    void editKelasMahasiswa(){
        cout << "\n=== Edit Kelas Mahasiswa ===" << endl;
        string kodeCari, nimCari;
        cout << "Masukkan Kode Kelas yang akan diedit: ";
        cin >> kodeCari;
        cout << "Masukkan NIM Mahasiswa yang akan diedit: ";
        cin >> nimCari;

        DoubleLinkedList<KelasMahasiswa>::Node* temp = daftarKelasMahasiswa.head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->data.kdKelas == kodeCari && temp->data.nim == nimCari) {
                ditemukan = true;
                cout << "Masukkan Kode Kelas baru: ";
                cin >> temp->data.kdKelas;
                cout << "Masukkan NIM Mahasiswa baru: ";
                cin >> temp->data.nim;
                cout << "Kelas Mahasiswa berhasil diperbarui!" << endl;
                updateFileKelasMahasiswa();
                break;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Kelas Mahasiswa dengan Kode Kelas " << kodeCari << " dan NIM " << nimCari << " tidak ditemukan." << endl;
        }
    }

    
    void tarikDataDariFileMahasiswa() {
        jumlahMhs = 0;
        ifstream in("dataMahasiswa.txt");
        if (!in.is_open()) return;
        string line;
        Mahasiswa mhsSementara;
        while (getline(in, line)) {
            if (line.find("NIM: ") != string::npos) mhsSementara.nim = line.substr(5);
            else if (line.find("Nama: ") != string::npos) mhsSementara.nama = line.substr(6);
            else if (line.find("Jurusan: ") != string::npos) mhsSementara.jurusan = line.substr(9);
            else if (line.find("--------------------------") != string::npos) {
                dataMhs[jumlahMhs++] = mhsSementara;
                mhsSementara = Mahasiswa();
            }
        }
        in.close();
    }

    void tarikDataDariFileKelas() {
        jumlahKelas = 0;
        ifstream in("dataKelas.txt");
        if (!in.is_open()) return;
        string line;
        Kelas kelasSementara;
        while (getline(in, line)) {
            if (line.find("Kode Kelas: ") != string::npos) kelasSementara.kdKelas = line.substr(13);
            else if (line.find("Nama Kelas: ") != string::npos) kelasSementara.namaKelas = line.substr(13);
            else if (line.find("Kapasitas: ") != string::npos) {
                try { kelasSementara.batasKelas = stoi(line.substr(12)); } catch(...) { kelasSementara.batasKelas = 0; }
            } else if (line.find("--------------------------") != string::npos) {
                dataKelas[jumlahKelas++] = kelasSementara;
                kelasSementara = Kelas();
            }
        }
        in.close();
    }

    
    void tarikDataDariFileKelasMahasiswa() {
        daftarKelasMahasiswa.clear();

        ifstream in("dataKelasMahasiswa.txt");
        if (!in.is_open()) return;
        string line;
        KelasMahasiswa km;
        while (getline(in, line)) {
            if (line.find("Kode Kelas: ") != string::npos) km.kdKelas = line.substr(13);
            else if (line.find("NIM Mahasiswa: ") != string::npos) km.nim = line.substr(15);
            else if (line.find("--------------------------") != string::npos) {
                tambahKelasMahasiswaLangsung(km);
                km = KelasMahasiswa();
            }
        }
        in.close();
    }

    void hapusKelasMahasiswa() {
        string  nimCari;
        cout << "\n=== Hapus Kelas Mahasiswa ===" << endl;
        cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
        cin >> nimCari;

        DoubleLinkedList<KelasMahasiswa>::Node* temp = daftarKelasMahasiswa.head;
        DoubleLinkedList<KelasMahasiswa>::Node* prev = nullptr;
        bool ditemukan = false;

        while (temp != nullptr) {
            if ( temp->data.nim == nimCari) {
                ditemukan = true;
                if (prev == nullptr) {
                    daftarKelasMahasiswa.head = temp->next;
                    if (daftarKelasMahasiswa.head != nullptr) {
                        daftarKelasMahasiswa.head->prev = nullptr;
                    } else {
                        daftarKelasMahasiswa.tail = nullptr;
                    }
                } else {
                    prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = prev;
                    } else {
                        daftarKelasMahasiswa.tail = prev;
                    }
                }

                delete temp;
                if (daftarKelasMahasiswa.sz > 0) daftarKelasMahasiswa.sz--;

                updateFileKelasMahasiswa();
                cout << "Mahasiswa dengan Nim " << nimCari << " berhasil dihapus dari kelas." << endl;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Mahasiswa dengan Nim" << nimCari << " tidak ditemukan di kelas Manapin." << endl;
        }
    }

   
    string findNamaMahasiswaByNIM(const string& nim) {
        if (mhsMgr) {
            for (DoubleLinkedList<Mahasiswa>::Node* t=mhsMgr->listMahasiswa.head; t!=nullptr; t=t->next) {
                if (t->data.nim == nim) return t->data.nama;
            }
        } else {
           
            if (jumlahMhs == 0) tarikDataDariFileMahasiswa();
            for (int i = 0; i < jumlahMhs; ++i) {
                if (dataMhs[i].nim == nim) return dataMhs[i].nama;
            }
        }
        return string("[Nama tidak ditemukan]");
    }

    
    void tampilSemuaKelasMahasiswa() {
        if (daftarKelasMahasiswa.size() == 0) {
            cout << "Belum ada relasi kelas-mahasiswa." << endl;
            return;
        }

        cout << "\n=== Daftar Kelas Mahasiswa ===" << endl;
        DoubleLinkedList<KelasMahasiswa>::Node* temp = daftarKelasMahasiswa.head;
        int idx = 1;
        while (temp != nullptr) {
            string nim = temp->data.nim;
            string kdKelas = temp->data.kdKelas;
            string nama = findNamaMahasiswaByNIM(nim);
            // Kelas* k = findKelasByKode(kdKelas);

            // cout << "Relasi ke-" << idx++ << ":\n";
            cout<<"---------------------------------"<<endl;
            cout << "  Kode Kelas : " << kdKelas;
            cout << "\n  NIM        : " << nim << "\n";
            cout << "  Nama       : " << nama << "\n";
            cout << "---------------------------------" << endl;

            temp = temp->next;
        }
    }

    void detailMahasiswa() {
        cout << "\n=== Detail Mahasiswa dalam Kelas ===" << endl;
        string kodeCari;
        cout << "Masukkan Kode Kelas: ";
        cin >> kodeCari;

        DoubleLinkedList<KelasMahasiswa>::Node* temp = daftarKelasMahasiswa.head;
        bool ditemukan = false;
        int idx = 1;
        while (temp != nullptr) {
            if (temp->data.kdKelas == kodeCari) {
                ditemukan = true;
                string nim = temp->data.nim;
                string nama = findNamaMahasiswaByNIM(nim);

                cout << "Mahasiswa ke-" << idx++ << ":\n";
                cout << "  NIM  : " << nim << "\n";
                cout << "  Nama : " << nama << "\n";
                cout << "---------------------------------" << endl;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Tidak ada mahasiswa yang terdaftar dalam kelas dengan kode " << kodeCari << "." << endl;
        }
    }
    
    void updateFileKelasMahasiswa() {
        ofstream outFile("dataKelasMahasiswa.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data kelas mahasiswa." << endl;
            return;
        }
        DoubleLinkedList<KelasMahasiswa>::Node* temp = daftarKelasMahasiswa.head;
        while (temp != nullptr) {
            
            outFile << "Kode Kelas: " << temp->data.kdKelas << endl;
            outFile << "NIM Mahasiswa: " << temp->data.nim << endl;
            outFile << "Nama Mahasiswa: " << findNamaMahasiswaByNIM(temp->data.nim) << endl;
            outFile << "--------------------------" << endl;
            temp = temp->next;
        }
        outFile.close();
    }
};

class ManajemenKrs {
private:
    DoubleLinkedList<Krs> daftarKrs;
    DoubleLinkedList<KelasMahasiswa> daftarKelasMahasiswa;
public:
    ManajemenKrs() {
        // Inisialisasi dengan beberapa data KRS jika list masih kosong
        if (daftarKrs.size() == 0) {
            // # KELAS A
            tambahKrsLangsung({"IF101-A", "DMK001"});
            tambahKrsLangsung({"IF101-A", "DMK002"});
            tambahKrsLangsung({"IF101-A", "DMK003"});
            tambahKrsLangsung({"IF101-A", "DMK004"});
            tambahKrsLangsung({"IF101-A", "DMK005"});
            tambahKrsLangsung({"IF101-A", "DMK006"});
            tambahKrsLangsung({"IF101-A", "DMK007"});
            tambahKrsLangsung({"IF101-A", "DMK008"});

            // # KELAS B
            tambahKrsLangsung({"IF101-B", "DMK009"});
            tambahKrsLangsung({"IF101-B", "DMK010"});
            tambahKrsLangsung({"IF101-B", "DMK011"});
            tambahKrsLangsung({"IF101-B", "DMK012"});
            tambahKrsLangsung({"IF101-B", "DMK013"});
            tambahKrsLangsung({"IF101-B", "DMK014"});
            tambahKrsLangsung({"IF101-B", "DMK015"});
            tambahKrsLangsung({"IF101-B", "DMK016"});

            // # KELAS C
            tambahKrsLangsung({"IF101-C", "DMK017"});
            tambahKrsLangsung({"IF101-C", "DMK018"});
            tambahKrsLangsung({"IF101-C", "DMK019"});
            tambahKrsLangsung({"IF101-C", "DMK020"});
            tambahKrsLangsung({"IF101-C", "DMK021"});
            tambahKrsLangsung({"IF101-C", "DMK022"});
            tambahKrsLangsung({"IF101-C", "DMK023"});
            tambahKrsLangsung({"IF101-C", "DMK024"});

            // # KELAS D
            tambahKrsLangsung({"IF101-D", "DMK025"});
            tambahKrsLangsung({"IF101-D", "DMK026"});
            tambahKrsLangsung({"IF101-D", "DMK027"});
            tambahKrsLangsung({"IF101-D", "DMK028"});
            tambahKrsLangsung({"IF101-D", "DMK029"});
            tambahKrsLangsung({"IF101-D", "DMK030"});
            tambahKrsLangsung({"IF101-D", "DMK031"});
            tambahKrsLangsung({"IF101-D", "DMK032"});
            updateFileKrs();
        }
    }
    void tambahKrsLangsung(const Krs& krsBaru) {
        daftarKrs.tambahData(krsBaru);
    }
    void tarikDataKelasMahasiswa(const DoubleLinkedList<KelasMahasiswa>& kelasMhs) {
        DoubleLinkedList<KelasMahasiswa>::Node* cur = kelasMhs.head;
        while (cur) {
            daftarKelasMahasiswa.tambahData(cur->data);
            cur = cur->next;
        }

        ifstream in("dataKelasMahasiswa.txt");
        if (!in.is_open()) return;
        string line;
        KelasMahasiswa km;
        while (getline(in, line)) {
            if (line.find("Kode Kelas: ") != string::npos) km.kdKelas = line.substr(13);
            else if (line.find("NIM Mahasiswa: ") != string::npos) km.nim = line.substr(15);
            else if (line.find("--------------------------") != string::npos) {
                daftarKelasMahasiswa.tambahData(km);
                km = KelasMahasiswa();
            }
        }
        in.close();
    }

    void tampilKrsByKelasMahasiswa(const string& kdKelas, const string& nim) {
        DoubleLinkedList<Krs>::Node* temp = daftarKrs.head;
        bool ditemukan = false;
        cout << "\n=== Daftar KRS untuk Kelas " << kdKelas << " dan NIM " << nim << " ===" << endl;
        while (temp != nullptr) {
            if (temp->data.kdKelasMahasiswa == kdKelas && daftarKelasMahasiswa.head->data.nim == nim) {
                ditemukan = true;
                cout << "  Kode Dosen Mata Kuliah: " << temp->data.kdDosenMk << endl;
            }
            temp = temp->next;
            daftarKelasMahasiswa.head = daftarKelasMahasiswa.head->next;
        }
        if (!ditemukan) {
            cout << "Tidak ada KRS yang ditemukan untuk Kelas " << kdKelas << " dan NIM " << nim << "." << endl;
        }
    }


  
    void tambahKrs() {
        Krs krsBaru;
        cout << "\n=== Tambah KRS Baru ===" << endl;
        cout << "Masukkan Kode Kelas Mahasiswa: ";
        cin >> krsBaru.kdKelasMahasiswa;
        cout << "Masukkan Kode Dosen Mata Kuliah: ";
        cin >> krsBaru.kdDosenMk;

        tambahKrsLangsung(krsBaru);
        cout << "KRS berhasil ditambahkan!" << endl;
    }


    void tampilKrsByKelas() {
        string kdKelasCari;
        cout << "\n=== Tampil KRS berdasarkan Kelas ===" << endl;
        cout << "Masukkan Kode Kelas Mahasiswa: ";
        cin >> kdKelasCari;

        DoubleLinkedList<Krs>::Node* temp = daftarKrs.head;
        bool ditemukan = false;
        cout << "\n=== Daftar KRS untuk Kelas " << kdKelasCari << " ===" << endl;
        while (temp != nullptr) {
            if (temp->data.kdKelasMahasiswa == kdKelasCari) {
                ditemukan = true;
                cout << "  Kode Kelas Mahasiswa: " << temp->data.kdKelasMahasiswa << endl;
                cout << "  Kode Dosen Mata Kuliah: " << temp->data.kdDosenMk << endl;
                cout << "---------------------------------" << endl;
            }
            temp = temp->next;
        }
        if (!ditemukan) {
            cout << "Tidak ada KRS yang ditemukan untuk Kelas " << kdKelasCari << "." << endl;
        }
    }


    void editKrs() {
        string kdKelasCari;
        cout << "\n=== Edit KRS ===" << endl;
        cout << "Masukkan Kode Kelas Mahasiswa yang akan diedit: ";
        cin >> kdKelasCari;

        DoubleLinkedList<Krs>::Node* temp = daftarKrs.head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->data.kdKelasMahasiswa == kdKelasCari) {
                ditemukan = true;
                cout << "Masukkan Kode Dosen Mata Kuliah baru: ";
                cin >> temp->data.kdDosenMk;
                cout << "KRS berhasil diperbarui!" << endl;
                break;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "KRS dengan Kode Kelas Mahasiswa " << kdKelasCari << " tidak ditemukan." << endl;
        }
    }


    void hapusKrs() {
        string kdKelasCari;
        cout << "\n=== Hapus KRS ===" << endl;
        cout << "Masukkan Kode Kelas Mahasiswa yang akan dihapus: ";
        cin >> kdKelasCari;

        DoubleLinkedList<Krs>::Node* temp = daftarKrs.head;
        DoubleLinkedList<Krs>::Node* prev = nullptr;
        bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->data.kdKelasMahasiswa == kdKelasCari) {
                ditemukan = true;
                if (prev == nullptr) {
                    // hapus head
                    daftarKrs.head = temp->next;
                    if (daftarKrs.head != nullptr) {
                        daftarKrs.head->prev = nullptr;
                    } else {
                        daftarKrs.tail = nullptr; // list jadi kosong
                    }
                } else {
                    // hapus di tengah atau tail
                    prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = prev;
                    } else {
                        daftarKrs.tail = prev; // dihapus tail
                    }
                }

                delete temp;
                // update ukuran karena kita manipulasi langsung struktur internal
                if (daftarKrs.sz > 0) daftarKrs.sz--;

                cout << "KRS dengan Kode Kelas Mahasiswa " << kdKelasCari << " berhasil dihapus." << endl;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "KRS dengan Kode Kelas Mahasiswa " << kdKelasCari << " tidak ditemukan." << endl;
        }
    }

    void tarikDataDariFileKrs() {
        ifstream inFile("dataKrs.txt");
        if (!inFile.is_open()) {
            cout << "File dataKrs.txt tidak ditemukan. Akan dibuat file baru." << endl;
            return;
        }

        // Hapus data existing sebelum memuat dari file
        daftarKrs.clear();

        string line;
        Krs krs;
        while (getline(inFile, line)) {
            if (line.find("Kode Kelas Mahasiswa: ") != string::npos) {
                krs.kdKelasMahasiswa = line.substr(22);
            } else if (line.find("Kode Dosen Mata Kuliah: ") != string::npos) {
                krs.kdDosenMk = line.substr(24);
            } else if (line.find("--------------------------") != string::npos) {
                // Akhir dari satu data, tambahkan ke linked list
                if (!krs.kdKelasMahasiswa.empty() && !krs.kdDosenMk.empty()) {
                    tambahKrsLangsung(krs);
                    krs = Krs(); // Reset untuk data berikutnya
                }
            }
        }

        inFile.close();
    }

    void updateFileKrs() {
        ofstream outFile("dataKrs.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Gagal membuka file untuk menyimpan data KRS." << endl;
            return;
        }

        DoubleLinkedList<Krs>::Node* temp = daftarKrs.head;
        while (temp != nullptr) {
            outFile << "Kode Kelas Mahasiswa: " << temp->data.kdKelasMahasiswa << endl;
            outFile << "Kode Dosen Mata Kuliah: " << temp->data.kdDosenMk << endl;
            outFile << "--------------------------" << endl;
            temp = temp->next;
        }

        outFile.close();
    }
    
    
    // Fungsi untuk validasi pengajuan KRS (tanpa vector)
    void validasiPengajuanKrs() {
        system("cls");
        cout << "\n========================================================================\n";
        cout << "                      VALIDASI PENGAJUAN KRS                            \n";
        cout << "========================================================================\n\n";
        
        ifstream inFile("dataPengajuanKrs.txt");
        if (!inFile.is_open()) {
            cout << "Belum ada pengajuan KRS.\n\n";
            system("pause");
            return;
        }
        
        // Hitung jumlah pengajuan belum divalidasi dan tampilkan
        cout << "Daftar Pengajuan KRS Belum Divalidasi:\n\n";
        string line;
        int nomorTampil = 1;
        int totalBelumValidasi = 0;
        
        string nama, nim, mataKuliah, statusPengajuan, statusValidasi;
        bool sedangBacaBlok = false;
        
        while (getline(inFile, line)) {
            if (line.find("Nama: ") != string::npos) {
                nama = line.substr(6);
                sedangBacaBlok = true;
            } else if (line.find("NIM: ") != string::npos) {
                nim = line.substr(5);
            } else if (line.find("Mata Kuliah: ") != string::npos) {
                mataKuliah = line.substr(13);
            } else if (line.find("Status Pengajuan: ") != string::npos) {
                statusPengajuan = line.substr(18);
            } else if (line.find("Status Validasi: ") != string::npos) {
                statusValidasi = line.substr(17);
            } else if (line.find("==========================================") != string::npos) {
                if (sedangBacaBlok && statusValidasi == "Belum Divalidasi") {
                    totalBelumValidasi++;
                    cout << nomorTampil++ << ". " << nama << " (" << nim << ")\n";
                }
                nama.clear();
                nim.clear();
                mataKuliah.clear();
                statusPengajuan.clear();
                statusValidasi.clear();
                sedangBacaBlok = false;
            }
        }
        inFile.close();
        
        if (totalBelumValidasi == 0) {
            cout << "Semua pengajuan sudah divalidasi.\n\n";
            system("pause");
            return;
        }
        
        cout << "\nPilih nomor pengajuan yang akan divalidasi (0 untuk batal): ";
        int pilihan;
        cin >> pilihan;
        
        if (pilihan < 1 || pilihan > totalBelumValidasi) {
            cout << "Batal validasi.\n";
            system("pause");
            return;
        }
        
        // Baca lagi untuk mendapatkan detail pengajuan yang dipilih
        ifstream inFile2("dataPengajuanKrs.txt");
        int nomorBaca = 0;
        string targetNim;
        
        while (getline(inFile2, line)) {
            if (line.find("Nama: ") != string::npos) {
                nama = line.substr(6);
                sedangBacaBlok = true;
            } else if (line.find("NIM: ") != string::npos) {
                nim = line.substr(5);
            } else if (line.find("Mata Kuliah: ") != string::npos) {
                mataKuliah = line.substr(13);
            } else if (line.find("Status Pengajuan: ") != string::npos) {
                statusPengajuan = line.substr(18);
            } else if (line.find("Status Validasi: ") != string::npos) {
                statusValidasi = line.substr(17);
            } else if (line.find("==========================================") != string::npos) {
                if (sedangBacaBlok && statusValidasi == "Belum Divalidasi") {
                    nomorBaca++;
                    if (nomorBaca == pilihan) {
                        targetNim = nim;
                        break;
                    }
                }
                nama.clear();
                nim.clear();
                mataKuliah.clear();
                statusPengajuan.clear();
                statusValidasi.clear();
                sedangBacaBlok = false;
            }
        }
        inFile2.close();
        
        cout << "\n=== Detail Pengajuan ===" << endl;
        cout << "Nama           : " << nama << "\n";
        cout << "NIM            : " << nim << "\n";
        cout << "Mata Kuliah    : " << mataKuliah << "\n";
        cout << "Status Pengajuan : " << statusPengajuan << "\n\n";
        
        cout << "Validasi pengajuan ini? (Y/N): ";
        char konfirmasi;
        cin >> konfirmasi;
        
        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            // Baca file asli dan tulis ke file temp dengan perubahan
            ifstream inFile3("dataPengajuanKrs.txt");
            ofstream tempFile("dataPengajuanKrs_temp.txt");
            
            if (inFile3.is_open() && tempFile.is_open()) {
                string currentNim;
                bool isTargetBlock = false;
                
                while (getline(inFile3, line)) {
                    if (line.find("NIM: ") != string::npos) {
                        currentNim = line.substr(5);
                        isTargetBlock = (currentNim == targetNim);
                        tempFile << line << "\n";
                    } else if (line.find("Status Validasi: ") != string::npos && isTargetBlock) {
                        tempFile << "Status Validasi: Sudah Divalidasi\n";
                    } else {
                        tempFile << line << "\n";
                    }
                }
                
                inFile3.close();
                tempFile.close();
                
                // Hapus file asli dan rename file temp
                remove("dataPengajuanKrs.txt");
                rename("dataPengajuanKrs_temp.txt", "dataPengajuanKrs.txt");
                
                cout << "\nPengajuan KRS berhasil divalidasi!\n";
            } else {
                cout << "\nError: Gagal menyimpan perubahan.\n";
            }
        } else {
            cout << "\nValidasi dibatalkan.\n";
        }
        
        system("pause");
    }

    
};


class ManajemenInputDanKoreksiNilai{
private:
    DoubleLinkedList<InputDanKoreksiNilai> InputNilai;
    
    // Helper untuk konversi nilai angka ke huruf
    string konversiNilaiAngkaKeHuruf(float nilai) {
        if (nilai >= 80) return "A";
        else if (nilai >= 70) return "B";
        else if (nilai >= 60) return "C";
        else if (nilai >= 50) return "D";
        else return "E";
    }
    
    // Helper untuk konversi nilai huruf ke angka
    float konversiNilaiHurufKeAngka(const string& huruf) {
        if (huruf == "A") return 85.0f;
        else if (huruf == "B") return 75.0f;
        else if (huruf == "C") return 65.0f;
        else if (huruf == "D") return 55.0f;
        else if (huruf == "E") return 40.0f;
        else return 0.0f;
    }

public:
    ManajemenInputDanKoreksiNilai() {
        muatDataNilai();
    }

    void muatDataNilai() {
        ifstream file("dataInputDanKoreksiNilai.txt");
        if (!file.is_open()) return;

        string line;
        InputDanKoreksiNilai nilai;
        nilai.statusValidasi = false;
        
        while (getline(file, line)) {
            if (line.find("Kode Dosen Mata Kuliah: ") != string::npos) {
                nilai.kdDosenMk = line.substr(24);
            } else if (line.find("NIM Mahasiswa: ") != string::npos) {
                nilai.nim = line.substr(15);
            } else if (line.find("Nilai: ") != string::npos) {
                nilai.nilaiAkhir = stof(line.substr(7));
            } else if (line.find("Kode Kelas: ") != string::npos) {
                nilai.kdKelas = line.substr(12);
            } else if (line.find("Status Validasi: ") != string::npos) {
                string status = line.substr(17);
                nilai.statusValidasi = (status == "Sudah Divalidasi");
            } else if (line.find("--------------------------") != string::npos) {
                InputNilai.tambahData(nilai);
                nilai = InputDanKoreksiNilai();
                nilai.statusValidasi = false;
            }
        }
        file.close();
    }

    void simpanDataNilai() {
        ofstream file("dataInputDanKoreksiNilai.txt", ios::trunc);
        if (!file.is_open()) {
            cout << "Gagal menyimpan data nilai." << endl;
            return;
        }

        DoubleLinkedList<InputDanKoreksiNilai>::Node* temp = InputNilai.head;
        while (temp != nullptr) {
            file << "Kode Dosen Mata Kuliah: " << temp->data.kdDosenMk << endl;
            file << "NIM Mahasiswa: " << temp->data.nim << endl;
            file << "Nilai: " << temp->data.nilaiAkhir << endl;
            file << "Kode Kelas: " << temp->data.kdKelas << endl;
            file << "Status Validasi: " << (temp->data.statusValidasi ? "Sudah Divalidasi" : "Belum Divalidasi") << endl;
            file << "--------------------------" << endl;
            temp = temp->next;
        }
        file.close();
    }

    void inputNilaiOlehDosen() {
        system("cls");
        cout << "\n========================================\n";
        cout << "       INPUT NILAI OLEH DOSEN\n";
        cout << "========================================\n";

        cout << "\nDaftar NIM Mahasiswa:\n";
        cout << string(40, '-') << "\n";
        
        ifstream fileList("dataKHS.txt");
        if (!fileList.is_open()) {
            cout << "File dataKHS.txt tidak ditemukan.\n";
            system("pause");
            return;
        }

        DoubleLinkedList<string> daftarNIM;
        string line;
        int no = 1;
        
        while (getline(fileList, line)) {
            if (line.find("NIM :") != string::npos) {
                size_t pos = line.find(":");
                string nim = line.substr(pos + 1);
                while (!nim.empty() && isspace((unsigned char)nim.front())) nim.erase(0, 1);
                while (!nim.empty() && isspace((unsigned char)nim.back())) nim.pop_back();
                
                if (!nim.empty()) {
                    daftarNIM.tambahData(nim);
                    cout << no++ << ". " << nim << "\n";
                }
            }
        }
        fileList.close();

        if (daftarNIM.size() == 0) {
            cout << "Tidak ada mahasiswa yang terdaftar.\n";
            system("pause");
            return;
        }

        cout << "\nMasukkan NIM mahasiswa: ";
        string nimPilihan;
        cin >> nimPilihan;

        ifstream fileKHS("dataKHS.txt");
        if (!fileKHS.is_open()) {
            cout << "Gagal membuka file dataKHS.txt\n";
            system("pause");
            return;
        }

        DoubleLinkedList<string> daftarMataKuliah;
        string currentNIM = "";
        bool nimDitemukan = false;

        while (getline(fileKHS, line)) {
            if (line.find("NIM :") != string::npos) {
                size_t pos = line.find(":");
                string nim = line.substr(pos + 1);
                while (!nim.empty() && isspace((unsigned char)nim.front())) nim.erase(0, 1);
                while (!nim.empty() && isspace((unsigned char)nim.back())) nim.pop_back();
                currentNIM = nim;

                if (nim == nimPilihan) {
                    nimDitemukan = true;
                }
            } else if (nimDitemukan && line.find("nama MK :") != string::npos) {
                size_t pos = line.find(":");
                string namaMK = line.substr(pos + 1);
                while (!namaMK.empty() && isspace((unsigned char)namaMK.front())) namaMK.erase(0, 1);
                while (!namaMK.empty() && isspace((unsigned char)namaMK.back())) namaMK.pop_back();
                daftarMataKuliah.tambahData(namaMK);
            } else if (nimDitemukan && line.find("NIM :") != string::npos && currentNIM != nimPilihan) {
                break;
            }
        }
        fileKHS.close();

        if (!nimDitemukan) {
            cout << "NIM tidak ditemukan di dataKHS.txt\n";
            system("pause");
            return;
        }

        if (daftarMataKuliah.size() == 0) {
            cout << "NIM ditemukan namun tidak ada mata kuliah terdaftar.\n";
            system("pause");
            return;
        }

        system("cls");
        cout << string(70, '=') << "\n";
        cout << "              INPUT NILAI UNTUK NIM: " << nimPilihan << "\n";
        cout << string(70, '=') << "\n";

        cout << left << setw(5) << "No" 
             << setw(35) << "Nama MK"
             << "Nilai Angka (0-100)\n";
        cout << string(70, '-') << "\n";

        DoubleLinkedList<float> nilaiList;
        
        int noMK = 1;
        DoubleLinkedList<string>::Node* tempMK = daftarMataKuliah.head;
        while (tempMK != nullptr) {
            float nilaiAngka;
            cout << left << setw(5) << noMK
                 << setw(35) << tempMK->data
                 << "Nilai: ";
            cin >> nilaiAngka;

            if (nilaiAngka < 0 || nilaiAngka > 100) {
                cout << "Nilai harus antara 0-100. Silakan input ulang.\n";
                cout << "Nilai: ";
                cin >> nilaiAngka;
            }

            nilaiList.tambahData(nilaiAngka);
            noMK++;
            tempMK = tempMK->next;
        }

        ifstream fileRead("dataKHS.txt");
        ofstream fileWrite("dataKHS_temp.txt");

        if (!fileRead.is_open() || !fileWrite.is_open()) {
            cout << "Gagal membuka file untuk update.\n";
            system("pause");
            return;
        }

        bool inSection = false;
        bool cekvalidasi = false;
        cout << " \n\n Apakah Anda ingin mem Validasi nilai ini sekarang? (Y/N): ";
        {
            char validasi;
            cin >> validasi;
            cekvalidasi = (validasi == 'Y' || validasi == 'y');
        }

        DoubleLinkedList<float>::Node* tempNilai = nilaiList.head;
        bool pendingAngka = false;
        float nilaiAngkaPending = 0.0f;

        auto konversiHuruf = [](float n) -> string {
            if (n >= 90) return "A";
            if (n >= 80) return "B";
            if (n >= 73) return "C";
            if (n >= 50) return "D";
            return "E";
        };

        while (getline(fileRead, line)) {
            if (line.find("NIM :") != string::npos) {
                string nimLine = line.substr(line.find(":") + 1);
                while (!nimLine.empty() && isspace((unsigned char)nimLine.front())) nimLine.erase(0,1);
                while (!nimLine.empty() && isspace((unsigned char)nimLine.back())) nimLine.pop_back();
                inSection = (nimLine == nimPilihan);
                fileWrite << line << "\n";
                continue;
            }

            if (inSection) {
                if (line.find("nilai :") != string::npos && tempNilai != nullptr) {
                    string huruf = konversiHuruf(tempNilai->data);
                    fileWrite << "nilai : " << huruf << "\n";
                    nilaiAngkaPending = tempNilai->data;
                    pendingAngka = true;
                    continue;
                }
                if (line.find("angka :") != string::npos && pendingAngka) {
                    fileWrite << "angka : " << nilaiAngkaPending << "\n";
                    pendingAngka = false;
                    tempNilai = tempNilai->next;
                    continue;
                }
                if (cekvalidasi && line.find("Status Validasi:") != string::npos) {
                    fileWrite << "Status Validasi: Sudah Divalidasi\n";
                    continue;
                }
            }
            fileWrite << line << "\n";
        }

        
    

        fileRead.close();
        fileWrite.close();

        remove("dataKHS.txt");
        rename("dataKHS_temp.txt", "dataKHS.txt");

        system("cls");
        cout << "\n========================================\n";
        cout << "        NILAI BERHASIL DIINPUT\n";
        cout << "========================================\n";
        cout << "NIM: " << nimPilihan << "\n";
        cout << "Total Mata Kuliah: " << daftarMataKuliah.size() << "\n";
        cout << "Semua nilai telah disimpan ke file dataKHS.txt\n";
        cout << "\n\n";

        system("pause");
    }

    void tampilStatusValidasi() {
        system("cls");
        cout << "\n========================================\n";
        cout << "       STATUS VALIDASI NILAI\n";
        cout << "========================================\n";

        ifstream f("dataKHS.txt");
        if (!f.is_open()) {
            cout << "File dataKHS.txt tidak ditemukan.\n";
            system("pause");
            return;
        }

        cout << left << setw(5) << "No" 
             << setw(15) << "NIM"
             << setw(12) << "Kelas"
             << setw(12) << "Kode MK"
             << setw(10) << "Angka"
             << setw(8)  << "Huruf"
             << setw(18) << "Status" << endl;
        cout << string(80, '-') << endl;

        string line, nim, kelas, kodeMK, angka, huruf, status;
        int no = 1;

        auto flushRow = [&]() {
            if (nim.empty() || kodeMK.empty()) return;
            cout << left << setw(5) << no++
                 << setw(15) << nim
                 << setw(12) << kelas
                 << setw(12) << kodeMK
                 << setw(10) << (angka.empty() ? "-" : angka)
                 << setw(8)  << (huruf.empty() ? "-" : huruf)
                 << setw(18) << (status.empty() ? "-" : status) << endl;
            kodeMK.clear(); angka.clear(); huruf.clear(); status.clear();
        };

        while (getline(f, line)) {
            if (line.find("NIM :") != string::npos) {
                flushRow();
                nim = line.substr(line.find(":") + 1);
                while (!nim.empty() && isspace((unsigned char)nim.front())) nim.erase(0,1);
                while (!nim.empty() && isspace((unsigned char)nim.back())) nim.pop_back();
            } else if (line.find("Kelas") != string::npos) {
                kelas = line.substr(line.find(":") + 1);
                while (!kelas.empty() && isspace((unsigned char)kelas.front())) kelas.erase(0,1);
                while (!kelas.empty() && isspace((unsigned char)kelas.back())) kelas.pop_back();
            } else if (line.find("kode MK :") != string::npos) {
                flushRow();
                kodeMK = line.substr(line.find(":") + 1);
                while (!kodeMK.empty() && isspace((unsigned char)kodeMK.front())) kodeMK.erase(0,1);
                while (!kodeMK.empty() && isspace((unsigned char)kodeMK.back())) kodeMK.pop_back();
            } else if (line.find("nilai :") != string::npos) {
                huruf = line.substr(line.find(":") + 1);
                while (!huruf.empty() && isspace((unsigned char)huruf.front())) huruf.erase(0,1);
                while (!huruf.empty() && isspace((unsigned char)huruf.back())) huruf.pop_back();
            } else if (line.find("angka :") != string::npos) {
                angka = line.substr(line.find(":") + 1);
                while (!angka.empty() && isspace((unsigned char)angka.front())) angka.erase(0,1);
                while (!angka.empty() && isspace((unsigned char)angka.back())) angka.pop_back();
            } else if (line.find("status :") != string::npos) {
                status = line.substr(line.find(":") + 1);
                while (!status.empty() && isspace((unsigned char)status.front())) status.erase(0,1);
                while (!status.empty() && isspace((unsigned char)status.back())) status.pop_back();
            } else if (line.find("--------------------------------") != string::npos) {
                flushRow();
            }
        }
        flushRow();
        f.close();

        system("pause");
    }

    void editDanKoreksiNilai() {
        system("cls");
        cout << "\n========================================\n";
        cout << "       EDIT DAN KOREKSI NILAI\n";
        cout << "========================================\n";

        // List NIM dari KHS
        ifstream f("dataKHS.txt");
        if (!f.is_open()) {
            cout << "File dataKHS.txt tidak ditemukan.\n";
            system("pause");
            return;
        }
        DoubleLinkedList<string> nims;
        string line;
        while (getline(f, line)) {
            if (line.find("NIM :") != string::npos) {
                string nim = line.substr(line.find(":") + 1);
                while (!nim.empty() && isspace((unsigned char)nim.front())) nim.erase(0,1);
                while (!nim.empty() && isspace((unsigned char)nim.back())) nim.pop_back();
                if (!nim.empty()) nims.tambahData(nim);
            }
        }
        f.close();

        if (nims.size() == 0) {
            cout << "Tidak ada NIM dalam KHS.\n";
            system("pause");
            return;
        }

        cout << left << setw(5) << "No" << setw(15) << "NIM" << endl;
        cout << string(22, '-') << endl;
        int no = 1;
        for (auto p = nims.head; p; p = p->next) cout << left << setw(5) << no++ << setw(15) << p->data << endl;

        cout << "\nPilih NIM (nomor): ";
        int pilihNim; cin >> pilihNim;
        if (pilihNim < 1 || pilihNim > nims.size()) {
            cout << "Pilihan NIM tidak valid.\n";
            system("pause");
            return;
        }
        auto nimNode = nims.head; for (int i=1;i<pilihNim;i++) nimNode = nimNode->next;
        string targetNim = nimNode->data;

        // List MK untuk NIM
        ifstream f2("dataKHS.txt");
        DoubleLinkedList<string> mkList;
        string currentNim;
        while (getline(f2, line)) {
            if (line.find("NIM :") != string::npos) {
                currentNim = line.substr(line.find(":") + 1);
                while (!currentNim.empty() && isspace((unsigned char)currentNim.front())) currentNim.erase(0,1);
                while (!currentNim.empty() && isspace((unsigned char)currentNim.back())) currentNim.pop_back();
            } else if (currentNim == targetNim && line.find("kode MK :") != string::npos) {
                string mk = line.substr(line.find(":") + 1);
                while (!mk.empty() && isspace((unsigned char)mk.front())) mk.erase(0,1);
                while (!mk.empty() && isspace((unsigned char)mk.back())) mk.pop_back();
                mkList.tambahData(mk);
            } else if (line.find("--------------------------------") != string::npos && !currentNim.empty()) {
                // continue
            }
        }
        f2.close();

        if (mkList.size() == 0) {
            cout << "Tidak menemukan mata kuliah untuk NIM tersebut.\n";
            system("pause");
            return;
        }

        cout << left << setw(5) << "No" << setw(15) << "Kode MK" << endl;
        cout << string(22, '-') << endl;
        no = 1; for (auto p = mkList.head; p; p = p->next) cout << left << setw(5) << no++ << setw(15) << p->data << endl;
        cout << "\nPilih Mata Kuliah (nomor): "; int pilihMk; cin >> pilihMk;
        if (pilihMk < 1 || pilihMk > mkList.size()) {
            cout << "Pilihan MK tidak valid.\n"; system("pause"); return;
        }
        auto mkNode = mkList.head; for (int i=1;i<pilihMk;i++) mkNode = mkNode->next;
        string targetMK = mkNode->data;

        cout << "Masukkan nilai baru (0-100): "; float nilaiBaru; cin >> nilaiBaru;
        if (nilaiBaru < 0 || nilaiBaru > 100) { cout << "Nilai harus 0-100.\n"; system("pause"); return; }

        auto hurufDariAngka = [](float a){ if(a>=90)return string("A"); if(a>=80)return string("B"); if(a>=73)return string("C"); if(a>=50)return string("D"); return string("E"); };
        string hurufBaru = hurufDariAngka(nilaiBaru);

        ifstream rin("dataKHS.txt"); ofstream wout("dataKHS_temp.txt");
        if (!rin.is_open() || !wout.is_open()) { cout << "Gagal membuka file.\n"; system("pause"); return; }
        bool inNIM = false; bool inMK = false;
        while (getline(rin, line)) {
            if (line.find("NIM :") != string::npos) {
                string nim = line.substr(line.find(":") + 1);
                while (!nim.empty() && isspace((unsigned char)nim.front())) nim.erase(0,1);
                while (!nim.empty() && isspace((unsigned char)nim.back())) nim.pop_back();
                inNIM = (nim == targetNim);
                inMK = false;
                wout << line << "\n";
            } else if (inNIM && line.find("kode MK :") != string::npos) {
                string mk = line.substr(line.find(":") + 1);
                while (!mk.empty() && isspace((unsigned char)mk.front())) mk.erase(0,1);
                while (!mk.empty() && isspace((unsigned char)mk.back())) mk.pop_back();
                inMK = (mk == targetMK);
                wout << line << "\n";
            } else if (inNIM && inMK && line.find("nilai :") != string::npos) {
                wout << "nilai : " << hurufBaru << "\n";
            } else if (inNIM && inMK && line.find("angka :") != string::npos) {
                wout << "angka : " << nilaiBaru << "\n";
            } else if (inNIM && inMK && line.find("status :") != string::npos) {
                wout << "status : Belum Divalidasi\n";
            } else {
                wout << line << "\n";
            }
        }
        rin.close(); wout.close();
        remove("dataKHS.txt"); rename("dataKHS_temp.txt","dataKHS.txt");

        cout << "\n[✓] Nilai berhasil dikoreksi untuk NIM " << targetNim << ", MK " << targetMK << ".\n";
        system("pause");
    }

  

    // 6. Rekap Nilai per Kelas/Mata Kuliah
    void rekapNilaiPerKelas() {
        system("cls");
        cout << "\n========================================\n";
        cout << "   REKAP NILAI PER KELAS/MATA KULIAH\n";
        cout << "========================================\n";

        cout << "1. Rekap per Kelas\n";
        cout << "2. Rekap per Kode Dosen Mata Kuliah\n";
        cout << "Pilihan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nMasukkan Kode Kelas: ";
            string kdKelas;
            cin >> kdKelas;

            system("cls");
            cout << "\n========================================\n";
            cout << "   REKAP NILAI KELAS: " << kdKelas << "\n";
            cout << "========================================\n";

            cout << left << setw(5) << "No" 
                 << setw(15) << "NIM"
                 << setw(15) << "Kode MK"
                 << setw(10) << "Nilai"
                 << setw(8) << "Huruf" << endl;
            cout << string(53, '-') << endl;

            ifstream f("dataKHS.txt");
            if (!f.is_open()) {
                cout << "File dataKHS.txt tidak ditemukan.\n";
                system("pause");
                return;
            }

            string line;
            string currentNim;
            string currentKelas;
            string currentKodeMK;
            string nilaiHuruf;
            string nilaiAngkaStr;
            int no = 1;
            float totalNilai = 0;
            int jumlah = 0;
            bool inTarget = false;

            auto flushRow = [&](bool hasNilai){
                if (!inTarget || currentKodeMK.empty()) return;
                cout << left << setw(5) << no++
                     << setw(15) << currentNim
                     << setw(15) << currentKodeMK
                     << setw(10) << (nilaiAngkaStr.empty() ? "-" : nilaiAngkaStr)
                     << setw(8)  << (nilaiHuruf.empty() ? "-" : nilaiHuruf) << endl;

                // Hitung rata-rata hanya jika nilai angka valid
                try {
                    float n = stof(nilaiAngkaStr);
                    totalNilai += n;
                    jumlah++;
                } catch (...) {
                    // skip non-numeric
                }

                currentKodeMK.clear();
                nilaiHuruf.clear();
                nilaiAngkaStr.clear();
            };

            while (getline(f, line)) {
                if (line.find("NIM :") != string::npos) {
                    flushRow(false);
                    currentKodeMK.clear();
                    nilaiHuruf.clear();
                    nilaiAngkaStr.clear();
                    size_t pos = line.find(":");
                    currentNim = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentNim.empty() && isspace((unsigned char)currentNim.front())) currentNim.erase(0,1);
                    while (!currentNim.empty() && isspace((unsigned char)currentNim.back())) currentNim.pop_back();
                } else if (line.find("Kelas:") != string::npos || line.find("Kelas :") != string::npos) {
                    size_t pos = line.find(":");
                    currentKelas = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentKelas.empty() && isspace((unsigned char)currentKelas.front())) currentKelas.erase(0,1);
                    while (!currentKelas.empty() && isspace((unsigned char)currentKelas.back())) currentKelas.pop_back();
                    inTarget = (currentKelas == kdKelas);
                } else if (inTarget && line.find("kode MK :") != string::npos) {
                    flushRow(false);
                    size_t pos = line.find(":");
                    currentKodeMK = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentKodeMK.empty() && isspace((unsigned char)currentKodeMK.front())) currentKodeMK.erase(0,1);
                    while (!currentKodeMK.empty() && isspace((unsigned char)currentKodeMK.back())) currentKodeMK.pop_back();
                } else if (inTarget && line.find("nilai :") != string::npos) {
                    size_t pos = line.find(":");
                    nilaiHuruf = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!nilaiHuruf.empty() && isspace((unsigned char)nilaiHuruf.front())) nilaiHuruf.erase(0,1);
                    while (!nilaiHuruf.empty() && isspace((unsigned char)nilaiHuruf.back())) nilaiHuruf.pop_back();
                } else if (inTarget && line.find("angka :") != string::npos) {
                    size_t pos = line.find(":");
                    nilaiAngkaStr = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!nilaiAngkaStr.empty() && isspace((unsigned char)nilaiAngkaStr.front())) nilaiAngkaStr.erase(0,1);
                    while (!nilaiAngkaStr.empty() && isspace((unsigned char)nilaiAngkaStr.back())) nilaiAngkaStr.pop_back();
                } else if (line.find("--------------------------------") != string::npos) {
                    flushRow(true);
                }
            }
            flushRow(true);

            if (jumlah > 0) {
                cout << string(53, '-') << endl;
                cout << "Rata-rata: " << (totalNilai / jumlah) << endl;
            } else {
                cout << "Tidak ada data untuk kelas ini.\n";
            }

        } else if (pilihan == 2) {
            cout << "\nMasukkan Kode Dosen Mata Kuliah: ";
            string kdDosenMk;
            cin >> kdDosenMk;

            auto trimStr = [](string &s) {
                while (!s.empty() && isspace((unsigned char)s.front())) s.erase(0, 1);
                while (!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
            };

            // Map KD Dosen MK -> Kode MK
            string targetKodeMK = kdDosenMk;
            ifstream mapFile("dataDosenMataKuliah.txt");
            if (mapFile.is_open()) {
                string l; string mk; string dmk;
                while (getline(mapFile, l)) {
                    if (l.find("Kode MK") != string::npos && l.find(":") != string::npos) {
                        mk = l.substr(l.find(":") + 1); trimStr(mk);
                    } else if (l.find("Kode Dosen MK") != string::npos && l.find(":") != string::npos) {
                        dmk = l.substr(l.find(":") + 1); trimStr(dmk);
                        if (!dmk.empty() && dmk == kdDosenMk && !mk.empty()) targetKodeMK = mk;
                    }
                }
                mapFile.close();
            }

            system("cls");
            cout << "\n========================================\n";
            cout << "   REKAP NILAI KODE DMK: " << kdDosenMk << "\n";
            cout << "========================================\n";

            cout << left << setw(5) << "No" 
                 << setw(15) << "NIM"
                 << setw(12) << "Kelas"
                 << setw(10) << "Nilai"
                 << setw(8) << "Huruf" << endl;
            cout << string(50, '-') << endl;

            int no = 1;
            float totalNilai = 0;
            int jumlah = 0;

            ifstream f("dataKHS.txt");
            if (!f.is_open()) {
                cout << "File dataKHS.txt tidak ditemukan.\n";
                system("pause");
                return;
            }

            string line;
            string currentNim;
            string currentKelas;
            string currentKodeMK;
            string nilaiHuruf;
            string nilaiAngkaStr;
            bool matchMK = false;

            auto flushRow = [&](){
                if (!matchMK || currentKodeMK.empty()) return;
                cout << left << setw(5) << no++
                     << setw(15) << currentNim
                     << setw(12) << currentKelas
                     << setw(10) << (nilaiAngkaStr.empty() ? "-" : nilaiAngkaStr)
                     << setw(8)  << (nilaiHuruf.empty() ? "-" : nilaiHuruf) << endl;

                try {
                    float n = stof(nilaiAngkaStr);
                    totalNilai += n;
                    jumlah++;
                } catch (...) {
                    // skip non numeric
                }

                currentKodeMK.clear();
                nilaiHuruf.clear();
                nilaiAngkaStr.clear();
                matchMK = false;
            };

            while (getline(f, line)) {
                if (line.find("NIM :") != string::npos) {
                    flushRow();
                    size_t pos = line.find(":");
                    currentNim = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentNim.empty() && isspace((unsigned char)currentNim.front())) currentNim.erase(0,1);
                    while (!currentNim.empty() && isspace((unsigned char)currentNim.back())) currentNim.pop_back();
                } else if (line.find("Kelas") != string::npos) {
                    size_t pos = line.find(":");
                    currentKelas = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentKelas.empty() && isspace((unsigned char)currentKelas.front())) currentKelas.erase(0,1);
                    while (!currentKelas.empty() && isspace((unsigned char)currentKelas.back())) currentKelas.pop_back();
                } else if (line.find("kode MK :") != string::npos) {
                    flushRow();
                    size_t pos = line.find(":");
                    currentKodeMK = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!currentKodeMK.empty() && isspace((unsigned char)currentKodeMK.front())) currentKodeMK.erase(0,1);
                    while (!currentKodeMK.empty() && isspace((unsigned char)currentKodeMK.back())) currentKodeMK.pop_back();
                    matchMK = (currentKodeMK == targetKodeMK) || (currentKodeMK == kdDosenMk);
                } else if (matchMK && line.find("nilai :") != string::npos) {
                    size_t pos = line.find(":");
                    nilaiHuruf = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!nilaiHuruf.empty() && isspace((unsigned char)nilaiHuruf.front())) nilaiHuruf.erase(0,1);
                    while (!nilaiHuruf.empty() && isspace((unsigned char)nilaiHuruf.back())) nilaiHuruf.pop_back();
                } else if (matchMK && line.find("angka :") != string::npos) {
                    size_t pos = line.find(":");
                    nilaiAngkaStr = (pos != string::npos) ? line.substr(pos + 1) : "";
                    while (!nilaiAngkaStr.empty() && isspace((unsigned char)nilaiAngkaStr.front())) nilaiAngkaStr.erase(0,1);
                    while (!nilaiAngkaStr.empty() && isspace((unsigned char)nilaiAngkaStr.back())) nilaiAngkaStr.pop_back();
                } else if (line.find("--------------------------------") != string::npos) {
                    flushRow();
                }
            }
            flushRow();
            f.close();

            if (jumlah > 0) {
                cout << string(50, '-') << endl;
                cout << "Rata-rata: " << (totalNilai / jumlah) << endl;
            } else {
                cout << "Tidak ada data untuk kode MK ini.\n";
            }
        }

        system("pause");
    }

    
};