#include <iostream>
#include <iomanip>
#include "slot.cpp"
using namespace std;

void tampilRiwayat(){
    if (jumlahRiwayat == 0)
    {
        cout << "Belum ada riwayat keluar.\n";
        return;
    }
    cout << "\n+-------+----------------+-----------------+----------+----------+----------+\n";
    cout << "| Slot  | Plat Nomor     | Jenis           | Jam Msk  | Jam Klr  | Harga    |\n";
    cout << "+-------+----------------+-----------------+----------+----------+----------+\n";
    for (int i = 0; i < jumlahRiwayat; i++)
    {
        cout << "| " << left << setw(6) << daftarRiwayat[i].namaSlot
             << "| " << setw(15) << daftarRiwayat[i].platNomor
             << "| " << setw(16) << daftarRiwayat[i].jenisKendaraan
             << "| " << setw(9) << daftarRiwayat[i].jamMasuk
             << "| " << setw(9) << daftarRiwayat[i].jamKeluar
             << "| " << setw(9) << daftarRiwayat[i].harga << "|\n";
    }
    cout << "+-------+----------------+-----------------+----------+----------+----------+\n";
}

void menuriwayat(){
    int pilihan;
    do
    {
        cout << endl;
        cout << "+================================================+\n";
        cout << "|              SISTEM SMART PARKING              |\n";
        cout << "+================================================+\n";
        cout << "| MENU RIWAYAT                                   |\n";
        cout << "+================================================+\n";
        cout << "| 1. Tampil Riwayat Keluar                       |\n";
        cout << "| 0. Kembali                                     |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| Pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tampilRiwayat();
            break;
        case 0:
            cout << "Keluar..\n";
            break;
        default:
            cout << "Pilihan Tidak Valid!\n";
        }
    } while (pilihan != 0);
}