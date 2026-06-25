#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;

struct Kendaraan{
    string platNomor, jenis; 
};

//tambah antrian
queue<Kendaraan>a;
void tambahAntrian(Kendaraan data){
    a.push(data);
    cout<<"Kendaraan "<<data.platNomor<<"( "<<data.jenis<<" ) berhasil ditambahkan!!\n";
}

//tampil antrian
void tampilAntrian(queue<Kendaraan>a){
    if(a.empty()){
        cout<<"Antrian kosong!\n";
        return;
    }
    cout<<endl;
    cout << "+----+----------------+-----------------+\n";
    cout << "| " << left << setw(3)  << "NO" 
         << "| " << setw(15) << "Plat Nomor" 
         << "| " << setw(15) << "Jenis Kendaraan" << " |\n";
    cout << "+----+----------------+-----------------+\n";
    
    int no = 1;
    while(!a.empty()){
        Kendaraan k = a.front();
        cout<<"| "<<left<<setw(3)<<no
            <<"| "<<setw(15)<<k.platNomor
            <<"| "<<setw(15)<<k.jenis<<" |\n";
        a.pop();
        no++;
    }
    cout << "+----+----------------+-----------------+\n";
}

void menuantrian(){
    int pilihan;

    do{
        cout << endl;
        cout << "+================================================+\n";
        cout << "|              SISTEM SMART PARKING              |\n";
        cout << "+================================================+\n";
        cout << "| MENU ANTRIAN                                   |\n";
        cout << "+================================================+\n";
        cout << "| 1. Tambah Antrian                              |\n";
        cout << "| 2. Tampil Antrian                              |\n";
        cout << "| 0. Kembali                                     |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| Pilihan : ";
        cin >> pilihan;

        switch (pilihan){
            case 1:{
                Kendaraan data;
                cout<<"Masukan Plat Nomor: ";
                cin.ignore();
                getline(cin, data.platNomor);

                int jenisPilihan;
                cout<<"Jenis kendaraan ( 1 = Mobil, 2  = Motor): ";
                cin>>jenisPilihan;

                if(jenisPilihan == 1)data.jenis = " Mobil ";
                else if(jenisPilihan == 2)data.jenis = " Motor ";
                else data.jenis = "Tidak diketahui!";

                tambahAntrian(data);
                break;
            }
            case 2:
                tampilAntrian(a);
                break;
            case 0:
                cout << "Keluar..\n";
                break;
            default:
                cout<<"Pilihan tidak valid!\n";
        }
    }
    while(pilihan != 0);
}