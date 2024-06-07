#include <iostream> // bagian azlin
#include <vector>
#include <string>
using namespace std;
#include <iomanip> 

class Kontak {
private:
    string nama;
    string nomorTelepon;
    string email;

public:
    Kontak(string n, string t, string e) : nama(n), nomorTelepon(t), email(e) {}
    
    string getNama() const { return nama; }
    string getNomorTelepon() const { return nomorTelepon; }
    string getEmail() const { return email; }
    
    void tampilkan() const {
        cout << left << setw(20) << nama 
                  << left << setw(15) << nomorTelepon 
                  << left << email << endl; // sampai sini azlin 
    }
};

class BukuAlamat { // bagian zustine
private:
    vector<Kontak*> kontak;
    int kapasitas;

public:
    BukuAlamat(int kap) : kapasitas(kap) {}
    
    ~BukuAlamat() {
        for (Kontak* k : kontak) {
            delete k;
        }
    }
    
    void tambahKontak(const Kontak& k) {
        if (kontak.size() < kapasitas) {
            kontak.push_back(new Kontak(k));
        } else {
            cout << "Buku alamat penuh. Tidak dapat menambah kontak lagi." << endl;
        }
    }
    
    void daftarKontak() const {  
        cout << left << setw(20) << "Nama" 
                  << left << setw(15) << "Nomor Telepon" 
                  << left << "Email" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (const Kontak* k : kontak) {
            k->tampilkan(); // sampai sini zustine
        }
    }
};

void tampilkanMenu() { // bagian shafda
    cout << "1. Tambah Kontak\n2. Daftar Kontak\n3. Keluar\nPilih opsi: ";
}

int main() { 
    BukuAlamat bukuAlamat(5); 
    int pilihan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();  

        if (pilihan == 1) {
            string nama, nomorTelepon, email;

            cout << "Masukkan nama: ";
            getline(std::cin, nama);
            cout << "Masukkan nomor telepon: ";
            getline(std::cin, nomorTelepon);
            cout << "Masukkan email: ";
            getline(std::cin, email);

            Kontak newKontak(nama, nomorTelepon, email);
            bukuAlamat.tambahKontak(newKontak);
        } else if (pilihan == 2) {
            bukuAlamat.daftarKontak();
        }

    } while (pilihan != 3);

    return 0; // sampai sini shafda

}
  