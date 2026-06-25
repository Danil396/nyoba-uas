#include<iostream>
using namespace std;
#include "riwayat.cpp"

int main(){
    inisialisasiSlot();
    int pilihan;
    do{
        cout<<endl;
        cout << "+================================================+\n";
        cout << "|              SISTEM SMART PARKING              |\n";
        cout << "+================================================+\n";
        cout << "| 1. Menu Antrian                                |\n";
        cout << "| 2. Menu Slot                                   |\n";
        cout << "| 3. Menu Riwayat Parkir                         |\n";
        cout << "| 0. Keluar....                                  |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            menuantrian();
            break;
        case 2:
            menuslot();
            break;
        case 3:
            menuriwayat();
            break;
        case 0:
            cout << "Keluar ..\n";
            break;
        default:
            cout << "Pilihan Tidak Valid\n";
        }
    } while (pilihan != 0);
}