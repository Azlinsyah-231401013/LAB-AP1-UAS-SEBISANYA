#include <iostream>
#include <string>
#include "Kontak.h"
#include "BukuAlamat.h"

void tampilkanMenu() {
    std::cout << "1. Tambah Kontak\n2. Daftar Kontak\n3. Keluar\nPilih opsi: ";
}

int main() {
    BukuAlamat bukuAlamat(5);
    int pilihan;

    do {
        tampilkanMenu();
        std::cin >> pilihan;
        std::cin.ignore();

        if (pilihan == 1) {
            std::string nama, nomorTelepon, email;

            std::cout << "Masukkan nama: ";
            std::getline(std::cin, nama);
            std::cout << "Masukkan nomor telepon: ";
            std::getline(std::cin, nomorTelepon);
            std::cout << "Masukkan email: ";
            std::getline(std::cin, email);

            Kontak newKontak(nama, nomorTelepon, email);
            bukuAlamat.tambahKontak(newKontak);
        } else if (pilihan == 2) {
            bukuAlamat.daftarKontak();
        }

    } while (pilihan != 3);

    return 0;
}
