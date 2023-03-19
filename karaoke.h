#ifndef KARAOKE_H_INCLUDED
#define KARAOKE_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define pengunjung(P) P->pengunjung
#define lagu(P) P->lagu
#define nil NULL

struct Pengunjung{
    string nama;
    string umur;
};
struct Lagu{
    string judul;
    string genre;
};
typedef Pengunjung infotypePengunjung;
typedef Lagu infotypeLagu;

typedef struct elmPengunjung *adrPengunjung;
typedef struct elmLagu *adrLagu;
typedef struct elmRelasi *adrRelasi;

struct elmPengunjung{
    infotypePengunjung info;
    adrPengunjung next;
    adrPengunjung prev;
};
struct elmLagu{
    infotypeLagu info;
    adrLagu next;
};
struct elmRelasi{
    adrPengunjung pengunjung;
    adrLagu lagu;
    adrRelasi next;
};
struct ListPengunjung{
    adrPengunjung first;
    adrPengunjung last;
};
struct ListLagu{ //circular single linked list
    adrLagu first;
};
struct ListRelasi{ //circular single linked list
    adrRelasi first;
};

//Deklarasi Fungsi dan Prosedur/
void createListPengunjung(ListPengunjung &L);
void createListLagu(ListLagu &L);
void createListRelasi(ListRelasi &L);
//Fungsi untuk Alokasi/
adrPengunjung pengunjungBaru(infotypePengunjung x);
adrLagu laguBaru(infotypeLagu x);
adrRelasi relasiBaru(adrPengunjung P, adrLagu L);
//Tambah Data Pengunjung dan lagu/
void tambahPengunjung(ListPengunjung &L, adrPengunjung P); //insert First
void tambahLagu(ListLagu &L, adrLagu L1); //insert First
//Cari data pengunjung dan lagu//
adrPengunjung cariPengunjung(ListPengunjung L, string nama);
adrLagu cariLagu(ListLagu L, string judul);
// Menambahkan relasi antara pengunjung dan lagu
void Connect(ListRelasi &L, adrRelasi R);
// Mencari pengunjung yang menyanyikan lagu X
string menyanyikanLaguX(ListRelasi L, string judul);
// Menghapus pengunjung tertentu beserta relasinya
void hapusPengunjungdanRelasi(ListPengunjung &LP, ListRelasi &LR, string nama);
// Menghapus pengunjung yang menyanyikan lagu X
void hapusPengunjungmenyanyikanLaguX(ListRelasi &LR, string judul);
// Menampilkan semua pengunjung dan lagu yang pernah mereka nyanyikan
void ShowAllPengunjungdanLagu(ListPengunjung LP, ListRelasi LR);
// Menampilkan pengunjung yang menyanyikan lagu paling banyak
string SingerwithMostSong(ListRelasi LR, ListPengunjung LP);
// Menampilkan lagu yang paling banyak dinyanyikan
string SongwithMostSinger(ListRelasi LR, ListLagu LL);
// Menu
int Menu();

#endif // KARAOKE_H_INCLUDED
//Tugas WGTIK