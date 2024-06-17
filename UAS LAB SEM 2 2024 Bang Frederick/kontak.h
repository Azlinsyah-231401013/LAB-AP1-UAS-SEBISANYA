#ifndef KONTAK_H
#define KONTAK_H

#include <iostream>
#include <string>

class Kontak {
private:
    std::string nama;
    std::string nomorTelepon;
    std::string email;

public:
    Kontak(const std::string& n, const std::string& t, const std::string& e);

    std::string getNama() const;
    std::string getNomorTelepon() const;
    std::string getEmail() const;

    void tampilkan() const;
};

#endif // KONTAK_H
