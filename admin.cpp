#include <iostream>
#include <string>
#include <fstream>
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
        return statusLogin;
    }

    bool isLogin() const {
        return statusLogin;
    }
};

//CLASS UNTUK MENU UTAMA MAHASISWA
class ManajemenMahasiswa {
private:
public:
Mahasiswa data[1000];
Mahasiswa mhsBaru;
int jumlah = 0;

ManajemenMahasiswa() {
    tarikMahasiswadarifile();
    // 300 data mahasiswa baru dengan NIM 2400018001 - 2400018300
    if (jumlah == 0){
        
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
    }

    updateFileMhs();
}

void tambahMahasiswaLangsung(const Mahasiswa& mhs) {
    if (jumlah < 200) { // Pastikan array tidak penuh
        data[jumlah++] = mhs;
    } else {
        cout << "Kapasitas data mahasiswa penuh!" << endl;
    }
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
                
                cout << "Data Mahasiswa yang ditemukan:\n";
                cout << "Nama: " << data[i].nama << "\n";
                cout << "NIM: " << data[i].nim << "\n";
                cout << "Semester: " << data[i].semester << "\n";
                cout << "Tahun Masuk: " << data[i].tahunMasuk << "\n";
                cout << "Jurusan: " << data[i].jurusan << "\n";

                //konfirmasi penghapusan
                char konfirmasi;
                cout << "Apakah Anda yakin ingin menghapus mahasiswa dengan NIM " << nimCari << "? (y/n): ";
                cin >> konfirmasi;
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    // Geser elemen setelahnya ke kiri
                    for (int j = i; j < jumlah - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    jumlah--;
                    cout << "Mahasiswa dengan NIM " << nimCari << " telah dihapus.\n";
                    updateFileMhs();
                } else {
                    cout << "Penghapusan dibatalkan.\n";
                }
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
                // Tambahkan ke array setiap selesai 1 blok data mahasiswa
                data[jumlah] = mhsSementara;
                jumlah++;
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

    for (int i = 0; i < jumlah; i++) {
        in << "Data Mahasiswa ke-" << i + 1 << ":\n";
        in << "Nama: " << data[i].nama << "\n";
        in << "NIM: " << data[i].nim << "\n";
        in << "Semester: " << data[i].semester << "\n";
        in << "Tahun Masuk: " << data[i].tahunMasuk << "\n";
        in << "Jurusan: " << data[i].jurusan << "\n";
        in << "Fakultas: " << data[i].fakultas << "\n";
        in << "Tempat Lahir: " << data[i].tempatLahir << "\n";
        in << "Tanggal Lahir: " << data[i].tanggalLahir << "\n";
        in << "Alamat: " << data[i].alamat << "\n";
        in << "Email: " << data[i].email << "\n";
        in << "No HP: " << data[i].noHp << "\n";
        in << "Jenis Kelamin: " << (data[i].g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
        in << "Status: " << (data[i].aktif ? "Aktif" : "Tidak Aktif") << "\n";
        in << "Password: " << data[i].password << "\n";
        in << "--------------------------\n";
    }

        in.close();
    }

    void tampilMahasiswa() {
        cout << "\n=== Data Mahasiswa ===\n";
        ifstream out;
        out.open("dataMahasiswa.txt");
        string cetak;
        while (getline(out, cetak)) {
            cout << cetak << endl;
        }
        out.close();
        if (jumlah == 0) {
            cout << "Tidak ada data mahasiswa.\n";
            return;
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
                cout << "Data ditemukan:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                cout << "Nama: " << data[i].nama << "\n";
                cout << "NIM: " << data[i].nim << "\n";
                cout << "Semester: " << data[i].semester << "\n";
                cout << "Tahun Masuk: " << data[i].tahunMasuk << "\n";
                cout << "Jurusan: " << data[i].jurusan << "\n";
                cout << "Fakultas: " << data[i].fakultas << "\n";
                cout << "Tempat Lahir: " << data[i].tempatLahir << "\n";
                cout << "Tanggal Lahir: " << data[i].tanggalLahir << "\n";
                cout << "Alamat: " << data[i].alamat << "\n";
                cout << "Email: " << data[i].email << "\n";
                cout << "No HP: " << data[i].noHp << "\n";
                cout << "Jenis Kelamin: " << (data[i].g == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
                cout << "Status: " << (data[i].aktif ? "Aktif" : "Tidak Aktif") << "\n";
                cout << "==============================\n";
                cout << " Masukkan Data Baru: \n";
                cout << "==============================\n";
                cout << "\nMasukkan nama mahasiswa: ";
                cin.ignore();
                getline(cin, data[i].nama);
                cout << "Masukkan semester: ";
                cin >> data[i].semester;
                cout << "Masukkan tahun masuk: ";
                cin >> data[i].tahunMasuk;
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
        for (int i = 0; i < jumlah; i++) {
            if (data[i].nim == nimCari) {
                ditemukan = true;
                cout << "Status keaktifan mahasiswa dengan NIM " << nimCari << ": "
                     << (data[i].aktif ? "Aktif" : "Tidak Aktif") << "\n";
                break;
            }
        }
        if (!ditemukan) {
            cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
        }
    }
};

//CLASS UNTUK MENU UTAMA DOSEN
class ManajemenDosen{
    private:
    Dosen data[1000];
    Dosen dosenBaru;
    int jumlahDosen = 0;
    
    public:
    ManajemenDosen(){
    
        tarikDosenFile();
        // Data dosen Informatika FTI
        if (jumlahDosen == 0)
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
        if (jumlahDosen < 200) { // Pastikan array tidak penuh
            data[jumlahDosen++] = dosen;
        } else {
            cout << "Kapasitas data Dosen penuh!" << endl;
        }
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
        data[jumlahDosen] = dosenBaru;
        jumlahDosen++;
        cout<<"Dosen berhasil ditambahkan!"<<endl;

        updateFileDosen();
    }

    void tarikDosenFile(){
        jumlahDosen=0;
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
                }else if(statusstr=="TidakAktif"){
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
                data[jumlahDosen]=DsSementara;
                jumlahDosen++;
            }
           
        }
         in.close();

        
    }

    //update Dosen ke file txt
    void updateFileDosen(){
        //clear isi file
        // clearFileDosen();

        ofstream in("dataDosen.txt", ios::trunc);
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
        ifstream out;
        out.open("dataDosen.txt");
        string cetak;
        while(getline(out,cetak)){
            cout<<cetak<<endl;
        }
        out.close();

    }

    void hapusDosen() {
    cout << "=====MENU HAPUS DOSEN====" << endl;
    string nidnCari;
    cout << "Masukkan NIDN Dosen Yang Akan di Hapus: ";
    cin >> nidnCari;
    
    bool ditemukan = false;
    for (int i = 0; i < jumlahDosen; i++) {
        if (data[i].nidn == nidnCari) {
            ditemukan = true;
            // Tampilkan data yang akan dihapus
            cout << "\nData Dosen yang akan dihapus:" << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "NIDN: " << data[i].nidn << endl;
            cout << "Fakultas: " << data[i].fakultas << endl;
            cout << "Jurusan: " << data[i].jurusan << endl;
            
            // Konfirmasi penghapusan
            char konfirmasi;
            cout << "\nApakah Anda yakin ingin menghapus data dosen ini? (y/n): ";
            cin >> konfirmasi;
            
            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                // Geser elemen setelahnya ke kiri
                for (int j = i; j < jumlahDosen - 1; j++) {
                    data[j] = data[j + 1];
                }
                jumlahDosen--;
                cout << "Dosen dengan NIDN " << nidnCari << " telah dihapus.\n";
                updateFileDosen();
            } else {
                cout << "Penghapusan dibatalkan.\n";
            }
            break;
        }
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
        for (int i = 0; i < jumlahDosen; i++) {
            if (data[i].nidn == nidnCari) {
                ditemukan = true;
                cout << "Data ditemukan. Masukkan data baru:\n";
                cout << "==============================\n";
                cout << " Data Sebelumnya \n";
                cout << "==============================\n";
                cout << "Nama: " << data[i].nama << "\n";
                cout << "NIP: " << data[i].nip << "\n";
                cout << "Fakultas: " << data[i].fakultas << "\n";
                cout << "Jurusan: " << data[i].jurusan << "\n";
                cout << "Gelar Depan: " << data[i].gelarDepan << "\n";
                cout << "Gelar Belakang: " << data[i].gelarBelakang << "\n";
                cout << "Jabatan Akademik: " << data[i].jabatanAkademik << "\n";
                cout << "Pendidikan Terakhir: " << data[i].pendidikanTerakhir << "\n";
                cout << "Email: " << data[i].email << "\n";
                cout << "No HP: " << data[i].noHp << "\n";
                cout << "Alamat: " << data[i].alamat << "\n";
                cout << "Jenis Kelamin: " << (data[i].gender == JenisKelamin::LakiLaki ? "Laki-laki" : "Perempuan") << "\n";
                cout << "Tahun Masuk: " << data[i].tahunMasuk << "\n";
                cout << "Status: " << (data[i].status == StatusDosen::Aktif ? "Aktif" :
                                    data[i].status == StatusDosen::Cuti ? "Cuti" :
                                    data[i].status == StatusDosen::Pensiun ? "Pensiun" : "Tidak Aktif") << "\n";
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
        for (int i = 0; i < jumlahDosen; i++) {
            if (data[i].nidn == nidnCari) {
                ditemukan = true;
                cout << "Data ditemukan:\n";
                cout << "Nama: " << data[i].nama << "\n";
                cout << "Status: " << (data[i].status == StatusDosen::Aktif ? "Aktif" :
                                    data[i].status == StatusDosen::Cuti ? "Cuti" :
                                    data[i].status == StatusDosen::Pensiun ? "Pensiun" : "Tidak Aktif") << "\n";
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
    struct NodeMataKuliah {
        MataKuliah data;          // Data mata kuliah
        NodeMataKuliah* next;     // Pointer ke node berikutnya
    };

    NodeMataKuliah* head = nullptr;         // Pointer ke head linked list

public:
    
    ManajemenMatakuliah() {
        if (head == nullptr) {
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
        UpdateFileMataKuliah();
        cout<<"=====MENU EDIT MATA KULIAH====="<<endl;
        string kodeCari;
        cout<<"Masukkan Kode Matakuliah yang akan di edit :";
        cin>>kodeCari;
        bool ditemukan = false;
        for(NodeMataKuliah* temp=head;temp!=nullptr;temp=temp->next){
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
            
            if (!ditemukan){
                cout<<"Mata kuliah dengan kode "<<kodeCari<<" tidak ditemukan."<<endl;
            }
        }
    }

    void hapusMataKuliah(){
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

                //konfirmasi penghapusan
                char konfirmasi;
                cout<<"Apakah anda yakin ingin menghapus mata kuliah ini? (y/n): ";
                cin>>konfirmasi;
                if(konfirmasi!='y' && konfirmasi!='Y'){
                    cout<<"Penghapusan dibatalkan."<<endl;
                    return;
                }

                if(prev==nullptr){
                    head=temp->next;
                }else{
                    prev->next=temp->next;
                }
                delete temp;
                cout<<"Mata kuliah dengan kode "<<kodeCari<<" berhasil dihapus."<<endl;
                UpdateFileMataKuliah();
                break;
            }
            prev=temp;
            temp=temp->next;
        }

        if(!ditemukan){
            cout<<"Mata kuliah dengan kode "<<kodeCari<<" tidak ditemukan."<<endl;
        }
    }

    void tarikDataDariFileMataKuliah() {
    head = nullptr;
    ifstream inFile("dataMataKuliah.txt");

    if (!inFile.is_open()) {
        cout << "File dataMataKuliah.txt tidak ditemukan atau gagal dibuka." << endl;
        return;
    }

    string line;
    MataKuliah mk;

    while (getline(inFile, line)) {

        // Hapus spasi depan & belakang
        while (!line.empty() && (line[0] == ' ' || line[0] == '\t'))
            line.erase(0, 1);

        if (line.find("Kode :") == 0) {
            mk = MataKuliah(); // reset data MK baru
            mk.kodeMK = line.substr(7);
        } else if (line.find("Nama :") == 0) {
            mk.namaMK = line.substr(7);
        } else if (line.find("SKS :") == 0) {
            try {
                mk.sks = stoi(line.substr(line.find(":") + 1));
            } catch (...) {
                mk.sks = 0;
            }
        } else if (line.find("Deskripsi :") == 0) {
            mk.deskripsi = line.substr(12);
        } else if (line.find("Semester :") == 0) {
            try {
                mk.semester = stoi(line.substr(10));
            } catch (...) {
                mk.semester = 0;
            }
        }
        else if (line.find("Jurusan :") == 0) {
            mk.jurusan = line.substr(10);
        }
        else if (line.find("Fakultas :") == 0) {
            mk.fakultas = line.substr(11);
        }
        else if (line.find("Wajib :") == 0) {
            string wajibStr = line.substr(8);
            mk.wajib = (wajibStr == "Ya");
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
            NodeMataKuliah* temp = head;
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
    struct NodeDosenMataKuliah {
        DosenMataKuliah data;
        NodeDosenMataKuliah* next;
        NodeDosenMataKuliah* prev;

        NodeDosenMataKuliah(const DosenMataKuliah& dmk) : data(dmk), next(nullptr), prev(nullptr) {}
    };
    
    NodeDosenMataKuliah* head = nullptr;
    NodeDosenMataKuliah* tail = nullptr;
    int jumlah = 0;

public:
    ManajemenDosenMataKuliah() {

    if (head == nullptr) {
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
        if (head == nullptr) return;
        
        NodeDosenMataKuliah* current = head;
        NodeDosenMataKuliah* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        
        head = nullptr;
        tail = nullptr;
        jumlah = 0;
        cout << "Semua data dosen mata kuliah telah dihapus dari memory." << endl;
    }

    // Tambah data dosen mata kuliah ke circular linked list
    void tambahDosenMataKuliahLangsung(const DosenMataKuliah& dmk) {
        NodeDosenMataKuliah* newNode = new NodeDosenMataKuliah(dmk);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;

            tail->next = head;
            head->prev = tail;
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
        if (head == nullptr) return false;
        
        NodeDosenMataKuliah* current = head;
        do {
            if (current->data.kdDosenMk == kdDosenMk) {
                return true;
            }
            current = current->next;
        } while (current != head);
        
        return false;
    }

    // Hapus data dosen mata kuliah berdasarkan kdDosenMk
    void hapusDosenMataKuliah() {
        updateFileDosenMataKuliah();
        cout << "===== MENU HAPUS DOSEN MATA KULIAH =====" << endl;
        if (head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah yang akan dihapus: ";
        cin >> kdCari;

        NodeDosenMataKuliah* current = head;
        
        bool ditemukan = false;

        do {
            if (current->data.kdDosenMk == kdCari) {
                ditemukan = true;
                
                if (current == head && current == tail) {
                    head = nullptr;
                    tail = nullptr;
                } else if (current == head) {
                    // Kasus 2: Hapus head
                    head = head->next;
                    head->prev = NULL;
                    tail->next = NULL;
                } else if (current == tail) {
                    // Kasus 3: Hapus tail
                    tail = tail->prev;
                    tail->next = NULL;
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
        } while (current != head);

        if (!ditemukan) {
            cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' tidak ditemukan!" << endl;
        }
    }

    // Edit data dosen mata kuliah
    void editDosenMataKuliah() {
        cout << "===== MENU EDIT DOSEN MATA KULIAH =====" << endl;
        if (head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah yang akan diedit: ";
        cin >> kdCari;

        NodeDosenMataKuliah* current = head;
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
        } while (current != head);

        if (!ditemukan) {
            cout << "Data dosen mata kuliah dengan kode '" << kdCari << "' tidak ditemukan!" << endl;
        }
    }

    // Tampilkan semua data dosen mata kuliah
    void tampilSemuaDosenMataKuliah() {
        cout << "\n=== DAFTAR SEMUA DOSEN MATA KULIAH ===" << endl;
        
        if (head == nullptr) {
            cout << "Tidak ada data dosen mata kuliah." << endl;
            return;
        }

        NodeDosenMataKuliah* current = head;
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
        } while (current != head);
    }

    // Cari data dosen mata kuliah berdasarkan kdDosenMk
    void cariDosenMataKuliah() {
        cout << "===== MENU CARI DOSEN MATA KULIAH =====" << endl;
        if (head == nullptr) {
            cout << "Data dosen mata kuliah kosong!" << endl;
            return;
        }

        string kdCari;
        cout << "Masukkan Kode Dosen Mata Kuliah: ";
        cin >> kdCari;

        NodeDosenMataKuliah* current = head;
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
        } while (current != head);

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

        if (head == nullptr) {
            outFile << "Tidak ada data dosen mata kuliah." << endl;
            outFile.close();
            return;
        }

        NodeDosenMataKuliah* current = head;
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
        } while (current != head);

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

    void tampilKelasByKode(const string& kodeKelas) {
        DoubleLinkedList<Kelas>::Node* temp = daftarKelas.head;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->data.kdKelas == kodeKelas) {
                ditemukan = true;
                cout << "Kode Kelas: " << temp->data.kdKelas
                     << ", Nama Kelas: " << temp->data.namaKelas
                     << ", Kapasitas: " << temp->data.batasKelas << endl;
                // tidak perlu update file di sini; tetap sesuai konsep aslinya
                break;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Kelas dengan kode " << kodeKelas << " tidak ditemukan." << endl;
        }
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
    struct NodeKelasMahasiswa {
        KelasMahasiswa data;
        NodeKelasMahasiswa* next;
        NodeKelasMahasiswa* prev;
        NodeKelasMahasiswa(const KelasMahasiswa& km) : data(km), next(nullptr), prev(nullptr) {}
    };

    
    ManajemenMahasiswa* mhsMgr = nullptr;
    ManajemenKelas* kelasMgr = nullptr;

    
    Mahasiswa dataMhs[1000];
    Kelas dataKelas[100];
    int jumlahMhs = 0;
    int jumlahKelas = 0;

public:
    NodeKelasMahasiswa* head = nullptr;
    NodeKelasMahasiswa* tail = nullptr;

    
    ManajemenKelasMahasiswa() {
        if (head == nullptr) {
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018008"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018002"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018005"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018001"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018006"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018003"});
        tambahKelasMahasiswaLangsung({"IF103-A", "2400018007"});

        tambahKelasMahasiswaLangsung({"IF103-B", "2400018011"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018012"});
        tambahKelasMahasiswaLangsung({"IF103-B", "2400018013"});
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
        NodeKelasMahasiswa* newNode = new NodeKelasMahasiswa(km);

       if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = nullptr;
        }
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

    void editKelasMaasiswa(){
        cout << "\n=== Edit Kelas Mahasiswa ===" << endl;
        string kodeCari, nimCari;
        cout << "Masukkan Kode Kelas yang akan diedit: ";
        cin >> kodeCari;
        cout << "Masukkan NIM Mahasiswa yang akan diedit: ";
        cin >> nimCari;

        NodeKelasMahasiswa* temp = head;
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
       
        NodeKelasMahasiswa* cur = head;
        while (cur) { NodeKelasMahasiswa* nx = cur->next; delete cur; cur = nx; }
        head = tail = nullptr;

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

   
    string findNamaMahasiswaByNIM(const string& nim) {
        if (mhsMgr) {
            for (int i = 0; i < mhsMgr->jumlah; ++i) {
                if (mhsMgr->data[i].nim == nim) return mhsMgr->data[i].nama;
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
        if (head == nullptr) {
            cout << "Belum ada relasi kelas-mahasiswa." << endl;
            return;
        }

        cout << "\n=== Daftar Kelas Mahasiswa ===" << endl;
        NodeKelasMahasiswa* temp = head;
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

        NodeKelasMahasiswa* temp = head;
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
        NodeKelasMahasiswa* temp = head;
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
            tambahKrsLangsung({"IF103-A", "DMK054"});
            tambahKrsLangsung({"IF103-A", "DMK055"});
            tambahKrsLangsung({"IF103-A", "DMK056"});
            tambahKrsLangsung({"IF103-A", "DMK057"});
            tambahKrsLangsung({"IF103-A", "DMK058"});
            tambahKrsLangsung({"IF103-A", "DMK059"});
            tambahKrsLangsung({"IF103-A", "DMK060"});
            tambahKrsLangsung({"IF103-A", "DMK061"});

            // # KELAS B
            tambahKrsLangsung({"IF103-B", "DMK062"});
            tambahKrsLangsung({"IF103-B", "DMK063"});
            tambahKrsLangsung({"IF103-B", "DMK064"});
            tambahKrsLangsung({"IF103-B", "DMK065"});
            tambahKrsLangsung({"IF103-B", "DMK066"});
            tambahKrsLangsung({"IF103-B", "DMK067"});
            tambahKrsLangsung({"IF103-B", "DMK068"});
            tambahKrsLangsung({"IF103-B", "DMK069"});

            // # KELAS C
            tambahKrsLangsung({"IF103-C", "DMK070"});
            tambahKrsLangsung({"IF103-C", "DMK071"});
            tambahKrsLangsung({"IF103-C", "DMK072"});
            tambahKrsLangsung({"IF103-C", "DMK073"});
            tambahKrsLangsung({"IF103-C", "DMK074"});
            tambahKrsLangsung({"IF103-C", "DMK075"});
            tambahKrsLangsung({"IF103-C", "DMK076"});
            tambahKrsLangsung({"IF103-C", "DMK077"});

            // # KELAS D
            tambahKrsLangsung({"IF103-D", "DMK078"});
            tambahKrsLangsung({"IF103-D", "DMK079"});
            tambahKrsLangsung({"IF103-D", "DMK080"});
            tambahKrsLangsung({"IF103-D", "DMK081"});
            tambahKrsLangsung({"IF103-D", "DMK082"});
            tambahKrsLangsung({"IF103-D", "DMK083"});
            tambahKrsLangsung({"IF103-D", "DMK084"});
            tambahKrsLangsung({"IF103-D", "DMK085"});
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
};