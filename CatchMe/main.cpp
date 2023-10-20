/*
* Catch Me If You Can
* Game kejar-kejaran antara 'hero' dan 'enemy'
* hero harus mengejar enemy yang bergerak secara acak
* bila hero berhasil menangkap enemy, skor akan bertambah
* 
* Kontrol
* - ESC			keluar
* - Panah		pergerakan
* 
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#include "cursor.h"

using namespace std;
using namespace cur;

int main()
{
	system("title Catch Me If You Can");
	
	// koordinat hero
	short heroX = 30;
	short heroY = 12;

	// koordinat enemy
	short enemX = 30;
	short enemY = 5;

	// arah pergerakan disimbolkan dengan 4 karakter:
	// U	atas
	// D	bawah
	// L	kiri
	// R	kanan
	char heroDir = ' ';		// hero
	char enemDir = 'U';		// enemy

	short tick = 0;			// counter perulangan
	int score = 0;			// skor

	srand((unsigned int)time(NULL));

	while (true)
	{
		system("cls");

		// menggambar garis bawah
		setcolor(3, 0);
		gotoxy(1, 29);
		for(int i = 0; i < 60; ++i)
			cout << char(196);

		// menggambar enemy
		if (enemDir == 'U' && enemY > 2) enemY--;
		if (enemDir == 'L' && enemX > 2) enemX--;
		if (enemDir == 'D' && enemY < 28) enemY++;
		if (enemDir == 'R' && enemX < 59) enemX++;

		gotoxy(enemX, enemY);
		setcolor(12, 0);
		cout << char(219);

		// menggambar hero
		if (heroDir == 'U' && heroY > 1) heroY--;
		if (heroDir == 'L' && heroX > 1) heroX--;
		if (heroDir == 'D' && heroY < 28) heroY++;
		if (heroDir == 'R' && heroX < 59) heroX++;

		gotoxy(heroX, heroY);
		setcolor(11, 0);
		cout << char(219);

		// menampilkan 'press ESC to exit
		gotoxy(1, 30);
		setcolor(7, 0);
		cout << "press ";
		setcolor(0, 7);
		cout << " ESC ";
		setcolor(7, 0);
		cout << " to exit";

		// menampilkan score
		gotoxy(50, 30);
		setcolor(3, 0);
		cout << "score: ";
		setcolor(10, 0);
		cout << score << ' ';

		// mendeteksi apakah posisi hero dan enemy sama
		if (heroX == enemX && heroY == enemY)
		{
			// tambahkan score
			score++;
			Beep(440, 100);

			// reset posisi hero dan enemy
			heroX = 30;
			heroY = 12;
			enemX = 30;
			enemY = 5;

			// reset arah hero dan enemy
			heroDir = ' ';
			enemDir = ' ';
		}

		// mendeteksi input dari keyboard
		// fungsi _kbhit() memungkinkan agar perulangan
		// tetap berjalan tanpa tertahan oleh penekanan tombol
		if (_kbhit())
		{
			char key = _getch();
			if (key == 27) break;
			if (key == 72) heroDir = 'U';
			if (key == 75) heroDir = 'L';
			if (key == 80) heroDir = 'D';
			if (key == 77) heroDir = 'R';
		}

		// tiap 5x tick
		// acak arah pergerakan enemy
		tick++;
		if (tick >= 5)
		{
			int rnd = rand() % 12 + 1;
			if (rnd < 4) enemDir = 'U';
			else if (rnd < 7) enemDir = 'D';
			else if (rnd < 10) enemDir = 'L';
			else enemDir = 'R';

			tick = 0;
		}

		Sleep(200);
	}
	
	return 0;
}