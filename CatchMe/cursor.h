#pragma once

#include <Windows.h>

namespace cur
{
	const HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);

	// fungsi gotxy()
	// meletakkan kursor pada posisi _x dan _y
	void gotoxy(short _x, short _y)
	{
		SetConsoleCursorPosition(oh, { _x, _y });
	}

	// fungsi setcolor()
	// set warna teks dan warna latar teks
	// _fc: warna teks			(nilai: 0 - 15)
	// _bc: warna latar teks	(nilai: 0 - 15)
	void setcolor(short _fc, short _bc)
	{
		short fc = _fc < 0 ? 0 : _fc > 15 ? 15 : _fc;
		short bc = _bc < 0 ? 0 : _bc > 15 ? 15 : _bc;

		SetConsoleTextAttribute(oh, bc * 16 + fc);
	}
}