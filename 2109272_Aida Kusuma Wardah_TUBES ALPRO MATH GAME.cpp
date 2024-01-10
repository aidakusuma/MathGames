#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <sstream>
#include <windows.h>
#include <iomanip>
using namespace std;
void setcolor (unsigned short color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

int main()
{
    //DEKLARASI
    int i, benar, totalNo, timeNeeded, totaltime, randomoperator;
    float q1, q2, j;
    double JawabanBenar;
    char yt;
    time_t start, finish;
    string flag, opsi, level, jawab;

    //Total Soal
    totalNo = 10;

    //ALGORITMA
    setcolor(9);
    cout<<"-----------------------------------"<<endl;
    cout<<"           Math Game 			  "<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"Welcome to math game"<<endl;
    cout<<"Program by Aida Kusuma Wardah (2109272)"<<endl;
    cout<<"Sebelum bermain, silakan lihat Aturan Bermain terlebih dulu"<<endl;
    cout<<"Tekan enter untuk masuk ke Menu"<<endl;
    cin.get();

    menu:
    setcolor (10);
    cout<<"-----------------------------------"<<endl;
    cout<<"           Menu     			      "<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"1. Aturan Bermain"<<endl;
    cout<<"2. Mainkan"<<endl;
    cout<<"3. Keluar"<<endl<<endl;
    cout<<"pilih opsi (1-3):";
    cin>>opsi;
    cout<<endl;
    while(flag!="stop")
        if(opsi=="stop")
            flag="stop";
        else
        if(opsi=="1" or opsi=="1."){
            setcolor(12);
            cout<<"-----------------------------------"<<endl;
            cout<<"          Aturan Bermain			  "<<endl;
            cout<<"-----------------------------------"<<endl<<endl;
            cout<<"1. Game ini tentang aritmatika               "<<endl;
            cout<<"2. Game ini berisi 10 soal pada setiap levelnya"<<endl;
            cout<<"3. Jika benar akan mendapat 1 point          "<<endl;
            cout<<"4. Untuk memenangkan game ini butuh 10 point "<<endl;
            cout<<"5. Setiap level tingkat kesulitannya berbeda "<<endl;
            cout<<"6. Untuk soal pembagian, jawabannya tulis semua angka di belakang koma dan koma ditulis dengan titik (.) "<<endl;
            cout<<"7. Jika kamu beruntung pada level hard - very hard kamu akan mendapatkan soal yang mudah"<<endl;
            cout<<"   Selamat bermain!! enjoyyy!!               "<<endl;
            cout<<endl;
            cout<<"ingin bermain? (y/t): "; cin>>yt;
            cout<<endl;
            while(flag!="stop")
            if(yt=='stop')
                    flag="stop";
                    else
                    if(yt == 'Y' or yt == 'y'){
                        goto game;
                    }
                    else
                    if(yt == 'T' or yt == 't'){
                        goto selesai;
                    }
                    else{
                    cout<<"opsi salah, masukkan opsi yang benar.\nOpsi: ";
                            cin>>yt;}
        }
        else
            if(opsi=="2" or opsi=="2."){
                game:
                setcolor(11);
                cout<<"-----------------------------------"<<endl;
                cout<<"              Level        		  "<<endl;
                cout<<"-----------------------------------"<<endl<<endl;
                cout<<"1. Level Easy        "<<endl;
                cout<<"2. Level Medium      "<<endl;
                cout<<"3. Level Hard        "<<endl;
                cout<<"4. Level Very Hard   "<<endl;
                cout<<"5. Kembali ke menu   "<<endl<<endl;
                cout<<"pilih level: ";cin>>level;
                cin.get();
                benar=0;
                while(flag!="stop")
                if(level=="stop")
                    flag="stop";
                    else{
                     while(level == "1" or level == "1."){
                         setcolor(14);
                        for(int i = 0; i <totalNo; i++ ){
                            srand(time(0));
                            q1 = rand()%10;
                            q2 = rand()%10+1;
                            cout<<"("<<(i+1)<<"). ";
                            randomoperator = rand()%4;
                            if(randomoperator == 0){
                                time(&start);
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                                JawabanBenar= q1 + q2;
                            }
                            if(randomoperator == 1){
                                time(&start);
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                                JawabanBenar= q1 - q2;
                            }
                            if(randomoperator == 2){
                                time(&start);
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                                JawabanBenar= q1 * q2;
                            }
                            if(randomoperator == 3){
                                time(&start);
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                                JawabanBenar= q1 / q2;
                            }
                            cin>>jawab;
                            time(&finish);
                            istringstream(jawab)>>j;
                        if( JawabanBenar == j ){
                        benar++;
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yeay kamu benar, waktu menjawab "<<timeNeeded<<" detik"<<endl<<endl;
                            }
                        else{
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yah kamu salah, waktu menjawab "<<timeNeeded<<" detik"<<endl;
                            if(randomoperator == 0)
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                            if(randomoperator == 1)
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                            if(randomoperator == 2)
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                            if(randomoperator == 3)
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                            cout<<JawabanBenar<<endl<<endl;
                            }
                        }
                        cout<<"Total Soal: "<<totalNo<<endl;
                        cout<<"Benar: "<<benar<<endl<<endl;

                        if(benar == 10){
                            cout<<"yeay kamu menang"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        else{
                            cout<<"yah kamu kalah silakan coba lagi"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        cout<<"Apakah ingin bermain lagi? (y/t): "; cin>>yt;
                        cout<<endl;
                        if(yt=='Y' or yt=='y'){
                            goto game;
                            }
                        if(yt=='T' or yt=='t'){
                            goto akhir;
                            }
                        break;
                        }
                     while(level == "2" or level == "2."){
                            setcolor(2);
                        for(int i = 0; i <totalNo; i++ ){
                            srand(time(0));
                            q1 = rand()%30;
                            q2 = rand()%30+1;

                            cout<<"("<<(i+1)<<"). ";
                            randomoperator = rand()%4;
                            if(randomoperator == 0){
                                time(&start);
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                                JawabanBenar= q1 + q2;
                                }
                            if(randomoperator == 1){
                                time(&start);
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                                JawabanBenar= q1 - q2;
                                }
                            if(randomoperator == 2){
                                time(&start);
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                                JawabanBenar= q1 * q2;
                                }
                            if(randomoperator == 3){
                                time(&start);
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                                JawabanBenar= q1 / q2;
                                }
                            cin>>jawab;
                            time(&finish);
                             istringstream(jawab)>>j;
                        if( JawabanBenar == j){
                        benar++;
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yeay kamu benar, waktu menjawab "<<timeNeeded<<" detik"<<endl<<endl;
                            }
                        else{
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yah kamu salah, waktu menjawab "<<timeNeeded<<" detik"<<endl;
                            if(randomoperator == 0)
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                            if(randomoperator == 1)
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                            if(randomoperator == 2)
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                            if(randomoperator == 3)
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                            cout<<JawabanBenar<<endl<<endl;
                                }
                            }
                        cout<<"Total Soal: "<<totalNo<<endl;
                        cout<<"Benar: "<<benar<<endl<<endl;

                        if(benar == 10){
                            cout<<"yeay kamu menang"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        else{
                            cout<<"yah kamu kalah silakan coba lagi"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        cout<<"Apakah ingin bermain lagi? (y/t): ";
                        cin>>yt;
                        cout<<endl;
                        if(yt=='Y' or yt=='y'){
                            goto game;
                            }
                        if(yt=='T' or yt== 't'){
                            goto akhir;
                            }
                        break;
                        }
                     while(level == "3" or level == "3."){
                            setcolor(13);
                        for(int i = 0; i <totalNo; i++ ){
                            srand(time(0));
                            q1 = rand()%50;
                            q2 = rand()%50+1;

                            cout<<"("<<(i+1)<<"). ";
                            randomoperator = rand()%4;
                            if(randomoperator == 0){
                                time(&start);
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                                JawabanBenar= q1 + q2;
                                }
                            if(randomoperator == 1){
                                time(&start);
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                                JawabanBenar= q1 - q2;
                                }
                            if(randomoperator == 2){
                                time(&start);
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                                JawabanBenar= q1 * q2;
                                }
                            if(randomoperator == 3){
                                time(&start);
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                                JawabanBenar= q1 / q2;
                                }
                            cin>>jawab;
                            time(&finish);
                            istringstream(jawab)>>j;
                        if( JawabanBenar == j ){
                        benar++;
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yeay kamu benar, waktu menjawab "<<timeNeeded<<" detik"<<endl<<endl;
                            }
                        else{
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yah kamu salah, waktu menjawab "<<timeNeeded<<" detik"<<endl;
                            if(randomoperator == 0)
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                            if(randomoperator == 1)
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                            if(randomoperator == 2)
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                            if(randomoperator == 3)
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                            cout<<JawabanBenar<<endl<<endl;
                            }
                        }
                        cout<<"Total Soal: "<<totalNo<<endl;
                        cout<<"Benar: "<<benar<<endl<<endl;

                        if(benar == 10){
                            cout<<"yeay kamu menang"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        else{
                            cout<<"yah kamu kalah silakan coba lagi"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }

                        cout<<"Apakah ingin bermain lagi? (y/t): "; cin>>yt;
                        cout<<endl;
                        if(yt=='Y' or yt=='y'){
                            goto game;
                            }
                        if(yt=='T' or yt=='t'){
                            goto akhir;
                            }
                        break;
                        }
                     while(level == "4" or level == "4."){
                            setcolor(8);
                        for(int i = 0; i <totalNo; i++ ){
                            srand(time(0));
                            q1 = rand()%100;
                            q2 = rand()%100+1;

                            cout<<"("<<(i+1)<<"). ";
                            randomoperator = rand()%4;
                            if(randomoperator == 0){
                                time(&start);
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                                JawabanBenar= q1 + q2;
                                }
                            if(randomoperator == 1){
                                time(&start);
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                                JawabanBenar= q1 - q2;
                                }
                            if(randomoperator == 2){
                                time(&start);
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                                JawabanBenar= q1 * q2;
                                }
                            if(randomoperator == 3){
                                time(&start);
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                                JawabanBenar= q1 / q2;
                                }
                            cin>>jawab;
                            time(&finish);
                            istringstream(jawab)>>j;
                        if( JawabanBenar == j ){
                        benar++;
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yeay kamu benar, waktu menjawab "<<timeNeeded<<" detik"<<endl<<endl;
                            }
                        else{
                            timeNeeded=difftime(finish,start);
                            totaltime=totaltime+timeNeeded;
                            cout<<"Yah kamu salah, waktu menjawab "<<timeNeeded<<" detik"<<endl;
                            if(randomoperator == 0)
                                cout<<q1<<" "<<"+"<<" "<<q2<<" = ";
                            if(randomoperator == 1)
                                cout<<q1<<" "<<"-"<<" "<<q2<<" = ";
                            if(randomoperator == 2)
                                cout<<q1<<" "<<"*"<<" "<<q2<<" = ";
                            if(randomoperator == 3)
                                cout<<q1<<" "<<"/"<<" "<<q2<<" = ";
                            cout<<JawabanBenar<<endl<<endl;
                            }
                        }
                        cout<<"Total Soal: "<<totalNo<<endl;
                        cout<<"Benar: "<<benar<<endl<<endl;

                        if(benar == 10){
                            cout<<"yeay kamu menang"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }
                        else{
                            cout<<"yah kamu kalah silakan coba lagi"<<endl;
                            cout<<"total waktu menjawab "<<totaltime<<" detik"<<endl;
                            }

                        cout<<"Apakah ingin bermain lagi? (y/t): "; cin>>yt;
                        cout<<endl;
                        if(yt=='Y' or yt=='y'){
                            goto game;
                            }
                        if(yt=='T' or yt=='t'){
                            goto akhir;
                            }
                        break;
                        }
                     while(level == "5" or level == "5."){
                        goto menu;
                        }
                    cout<<"opsi salah, masukkan opsi yang benar.\nOpsi: ";
                    cin>>level;}
                }
            else
                if(opsi == "3" or opsi == "3."){
                    selesai:
                    setcolor(6);
                    cout<<"yah kamu belum sempat bermain dan "<<endl;
                    flag="stop";
                    }
                else{
                    cout<<"opsi salah, masukkan opsi yang benar.\nOpsi: ";
                    cin>>opsi;
                }
      akhir:
        setcolor(6);
        cout<<"terima kasih sudah mencoba program ini!!"<<endl;

    cout<<"layar ini akan dihapus dalam 5 detik";
    for(i=4;i>=0;i--){
        Sleep(1000);
        cout<<"\b\b\b\b\b\b\b"; cout<<i<<" detik";

    }
    system ("cls");

}



