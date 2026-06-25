#include <iostream>
#include <iomanip>
#include "antrian.cpp"
using namespace std;

struct Slot{
    int nomorSlot;
    bool terisi;
    string namaSlot;
    string platNomor;
    string jenisKendaraan;
    string jamMasuk;
    int harga;
};

struct Riwayat{
    string namaSlot;
    string platNomor;
    string jenisKendaraan;
    string jamMasuk;
    string jamKeluar;
    int harga;
};

const int MAX_SLOT = 10;
const int MAX_RIWAYAT = 50;
string daftarNamaSlot[MAX_SLOT] = {"A1", "A2", "A3", "A4", "A5", "B1", "B2", "B3", "B4", "B5"};
Slot daftarSlot[MAX_SLOT];
Riwayat daftarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

void inisialisasiSlot(){
    for (int i = 0; i < MAX_SLOT; i++)
    {
        daftarSlot[i].nomorSlot = i + 1;
        daftarSlot[i].namaSlot = daftarNamaSlot[i];
        daftarSlot[i].terisi = false;
        daftarSlot[i].platNomor = "";
        daftarSlot[i].jenisKendaraan = "";
        daftarSlot[i].jamMasuk = "";
        daftarSlot[i].harga = 0;
    }
}

void tambahKendaraanMasuk(){
    if (a.empty()){
        cout << "Antrian kosong! Tidak ada kendaraan yang bisa masuk.\n";
        return;
    }

    int slotKosong = -1;
    for (int i = 0; i < MAX_SLOT; i++){
        if (!daftarSlot[i].terisi)
        {
            slotKosong = i;
            break;
        }
    }

    if (slotKosong == -1){
        cout << "Slot parkir penuh!\n";
        return;
    }

    Kendaraan k = a.front();
    a.pop();

    cout << "\n+----------------------------------+\n";
    cout << "| Data Kendaraan yang Masuk        |\n";
    cout << "+----------------------------------+\n";
    cout << "| Plat Nomor : " << left << setw(20) << k.platNomor << "|\n";
    cout << "| Jenis      : " << left << setw(20) << k.jenis << "|\n";
    cout << "| Slot       : " << left << setw(20) << daftarNamaSlot[slotKosong] << "|\n";
    cout << "+----------------------------------+\n";

    string jam;
    cout << "Jam Masuk (contoh 08:30) : ";
    cin >> jam;

    daftarSlot[slotKosong].terisi = true;
    daftarSlot[slotKosong].nomorSlot = slotKosong + 1;
    daftarSlot[slotKosong].platNomor = k.platNomor;
    daftarSlot[slotKosong].jenisKendaraan = k.jenis;
    daftarSlot[slotKosong].jamMasuk = jam;
    daftarSlot[slotKosong].harga = 0;

    cout << "Kendaraan " << k.platNomor << " berhasil masuk ke Slot " << daftarNamaSlot[slotKosong] << "\n";
}

void tampilSlot(){
    cout << "\n+-------+----------------+-----------------+----------+\n";
    cout << "| Slot  | Plat Nomor     | Jenis           | Jam      |\n";
    cout << "+-------+----------------+-----------------+----------+\n";
    for (int i = 0; i < MAX_SLOT; i++)
    {
        if (daftarSlot[i].terisi)
        {
            cout << "| " << left << setw(6) << daftarSlot[i].namaSlot
                 << "| " << setw(15) << daftarSlot[i].platNomor
                 << "| " << setw(16) << daftarSlot[i].jenisKendaraan
                 << "| " << setw(9) << daftarSlot[i].jamMasuk << "|\n";
        }
        else
        {
            cout << "| " << left << setw(6) << daftarSlot[i].namaSlot
                 << "| " << setw(15) << "[ KOSONG ]"
                 << "| " << setw(16) << "-"
                 << "| " << setw(9) << "-" << "|\n";
        }
    }
    cout << "+-------+----------------+-----------------+----------+\n";
}

void tambahKendaraanKeluar(){
    tampilSlot();

    string platCari;
    cout << "Masukkan Plat Nomor yang keluar : ";
    cin.ignore();
    getline(cin, platCari);

    int ketemu = -1;
    for (int i = 0; i < MAX_SLOT; i++)
    {
        if (daftarSlot[i].terisi && daftarSlot[i].platNomor == platCari)
        {
            ketemu = i;
            break;
        }
    }

    if (ketemu == -1)
    {
        cout << "Plat nomor tidak ditemukan!\n";
        return;
    }

    string jamKeluar;
    int harga;
    cout << "Jam Keluar (contoh 10:30) : ";
    cin >> jamKeluar;
    cout << "Harga Parkir              : ";
    cin >> harga;

    // Simpan ke riwayat sebelum slot dikosongkan
    daftarRiwayat[jumlahRiwayat].namaSlot = daftarSlot[ketemu].namaSlot;
    daftarRiwayat[jumlahRiwayat].platNomor = daftarSlot[ketemu].platNomor;
    daftarRiwayat[jumlahRiwayat].jenisKendaraan = daftarSlot[ketemu].jenisKendaraan;
    daftarRiwayat[jumlahRiwayat].jamMasuk = daftarSlot[ketemu].jamMasuk;
    daftarRiwayat[jumlahRiwayat].jamKeluar = jamKeluar;
    daftarRiwayat[jumlahRiwayat].harga = harga;
    jumlahRiwayat++;

    cout << "Kendaraan " << daftarSlot[ketemu].platNomor << " keluar dari Slot " << daftarSlot[ketemu].namaSlot << "\n";

    // Kosongkan slot
    daftarSlot[ketemu].terisi = false;
    daftarSlot[ketemu].platNomor = "";
    daftarSlot[ketemu].jenisKendaraan = "";
    daftarSlot[ketemu].jamMasuk = "";
    daftarSlot[ketemu].harga = 0;
}

int pilihan;
void menuslot(){
    do
    {
        cout << endl;
        cout << "+================================================+\n";
        cout << "|              SISTEM SMART PARKING              |\n";
        cout << "+================================================+\n";
        cout << "| MENU SLOT PARKIR                               |\n";
        cout << "+================================================+\n";
        cout << "| 1. Tambah Kendaraan Masuk                      |\n";
        cout << "| 2. Tambah Kendaraan Keluar                     |\n";
        cout << "| 3. Tampilkan Slot Parkir                       |\n";
        cout << "| 0. Kembali                                     |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| Pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahKendaraanMasuk();
            break;
        case 2:
            tambahKendaraanKeluar();
            break;
        case 3:
            tampilSlot();
            break;
        case 0:
            cout << "Keluar..\n";
            break;
        default:
            cout << "Pilihan Anda Tidak Valid!\n";
        }
    } while (pilihan != 0);
}