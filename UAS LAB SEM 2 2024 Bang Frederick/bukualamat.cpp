#include "BukuAlamat.h"
#include <iostream>
#include <iomanip>

BukuAlamat::BukuAlamat(int kap) : kapasitas(kap) {}

BukuAlamat::~BukuAlamat() {
    for (Kontak* k : kontak) {
        delete k;
    }
}

void BukuAlamat::tambahKontak(const Kontak& k) {
    if (kontak.size() < kapasitas) {
        kontak.push_back(new Kontak(k));
    } else {
        std::cout << "Buku alamat penuh. Tidak dapat menambah kontak lagi." << std::endl;
    }
}

void BukuAlamat::daftarKontak() const {
    std::cout << std::left << std::setw(20) << "Nama"
              << std::left << std::setw(15) << "Nomor Telepon"
              << std::left << "Email" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (const Kontak* k : kontak) {
        k->tampilkan();
    }
}
