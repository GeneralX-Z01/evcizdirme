/****************************************************************************
**					        SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				        ÖDEV NUMARASI.............: Odev 2
**				        ÖĞRENCİ ADI...............: Fuad Garibli
**				        ÖĞRENCİ NUMARASI..........: G201210558
**				        DERS GRUBU................: 2.Öğretim A grubu
****************************************************************************/

#include <windows.h>
#include <iostream>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati
{
public:
    char catiChar = '*';
    int catiboy;
    void olustur(int x, int y, int evEn, int catiBoy, char catiChar)     //gerekli parametreler alinir
    {
        //cati yazdıirma
        for (int i = 0; i < catiBoy; i++)
        {
            gotoxy(x, y);
            for (int j = catiBoy - 1 - i; j > 0; j--)
            {
                cout << " ";
            }

            for (int k = 0; k < (evEn - (catiBoy - 1 - i) * 2); k++)
            {
                cout << catiChar;
            }
            cout << endl;
            y++;
        }
    }
};

//kat sinifi kat kismini yazdirir
class Kat
{
public:
    int en;
    char katChar = (char)219;
    int boy;
    void olustur(int x, int y, int evEn, int evBoy, int catiBoy, char katChar)
    {
        gotoxy(x, y + catiBoy);
        //govdenin ust kisminin yazdirilmasi
        int i = 0;
        while (i < evEn)
        {
            cout << katChar;
            i++;
        }
        //govdenin orta kismi
        int j = 0;
        while (j < evBoy)
        {
            gotoxy(x + evEn - 1, (y + catiBoy));
            cout << katChar;
            gotoxy(x, (y + catiBoy));
            cout << katChar;
            y++;
            j++;
        }
        //govdenin alt kisminin yazdirilmasi      
        for (int k = 0; k < evEn; k++)
        {
            gotoxy(x + k, y + catiBoy);
            if (k < evEn / 2 || k >= (evEn * 3 / 4))
            {
                cout << katChar;
            }
        }
    }
};

//kapi kisminin yazilmasi
class Kapi
{
public:
    char kapiChar = '#';
    void olustur(int x, int y, int evEn, int evBoy, int catiBoy, char kapiChar)
    {
        //yukseklik degerlerinin tek olmasi durumunda kapinin disarida kalmamasi icin if else kontrolu
        if (evBoy % 2 == 1 || catiBoy % 2 == 1) {
            int sayac = 0;
            while (sayac < evBoy / 2) {
                gotoxy((x + evEn / 2), (y + 2 + catiBoy + (evBoy / 2)));
                for (int i = 0; i < evEn / 4; i++)
                {
                    cout << kapiChar;
                }
                cout << endl;
                y++;
                sayac++;
            }
        }
        else {
            int count = 0;
            while (count < evBoy / 2) {
                gotoxy((x + evEn / 2), (y + 1 + catiBoy + (evBoy / 2)));

                for (int i = 0; i < evEn / 4; i++) {
                    cout << kapiChar;
                }
                cout << endl;
                count++;
                y++;
            }
        }
    }
};

// ev classinda kullanicidan girdiler alinir ve diger siniflarin fonksiyonlarina parametreler yollanir
class Ev
{
public:
    void evOlustur()
    {
        Kapi kapi;
        Kat kat;
        Cati cati;

        char tercih = ' ';
        int  x, y;

        cout << "genislik : ";
        cin >> kat.en;

        cout << "yukseklik : ";
        cin >> kat.boy;

        cout << "cati yuksekligi: ";
        cin >> cati.catiboy;

        cout << "x koordinati: ";
        cin >> x;

        cout << "y koordinati: ";
        cin >> y;

        cout << " sembolu degistirmek icin 'e' basiniz: ";
        cin >> tercih;

        switch (tercih)
        {
        case 'e' || 'E':
            cout << "kat karakteri igirin: ";
            cin >> kat.katChar;

            cout << "cati sembolu: ";
            cin >> cati.catiChar;

            cout << "kapi sembolu: ";
            cin >> kapi.kapiChar;
            break;
        }

        system("cls");

        cati.olustur(x, y, kat.en, cati.catiboy, cati.catiChar);

        kat.olustur(x, y, kat.en, kat.boy, cati.catiboy, kat.katChar);

        kapi.olustur(x, y, kat.en, kat.boy, cati.catiboy, kapi.kapiChar);
    }
};

//main de ev sınıfı nesnesi olusturulur ve fonksiyonu cagirilir
int main()
{
    Ev ev;
    ev.evOlustur();
    cin.get();
}

