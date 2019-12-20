#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main () {
    setlocale (LC_ALL, "");
    wchar_t *charset_1 = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wchar_t *charset_2 = L"abcdefghijklmnopqrstuvwxyz";
    wchar_t *charset_3 = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    wchar_t *charset_4 = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    void table (wchar_t* charset) {
        for (int i = 0; charset[i]; i++)
            if (i && (i % 8 == 0))
                wprintf (L"\n[%4d %2lc]\t", (int) charset[i], charset[i]);
            else
                wprintf (L"[%4d %2lc]\t", (int) charset[i], charset[i]);
        wprintf (L"\n|||%ls|||\n", charset);
    }
    table (charset_1);
    table (charset_2);
    table (charset_3);
    table (charset_4);
    return 0;
}
