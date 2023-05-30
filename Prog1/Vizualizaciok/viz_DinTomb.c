// Ebben a példában egy (a példában inteket tároló) dinamikus tömb vizualizációja látható.
// A cél az, hogy a memóriaképet bemutató vizualizáció mindenkinek segítsen könnyebben megérteni az anyagot.
// A teljes vizualizációhoz futtatsd a programot (pl. az alábbi webhelyen: https://godbolt.org/z/abrboGE6n).

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// DinTomb dinamikus tömb struktúra, melyben egyszerre tárolhatjuk...
typedef struct DinTomb {
    size_t meret;  // a méretet,
    int *tomb_ptr; // és egy int tömbre mutató pointert.
} DinTomb;

void DinTomb_kirajzol(const char*, DinTomb *); // ez nem fontos

void DinTomb_felvesz(DinTomb *dintomb_ptr, int ertek); // ezzel érdemes azért szemezni

int main() {
    // Üres tömböt hozunk létre
    DinTomb din_tomb = {0, NULL};
    DinTomb_kirajzol("Uresen", &din_tomb);

    // Felveszünk egy elemet
    DinTomb_felvesz(&din_tomb, 10);
    DinTomb_kirajzol("10 felveve", &din_tomb);

    // Felveszünk még egy elemet
    DinTomb_felvesz(&din_tomb, 9);
    DinTomb_kirajzol("10 es 9 felveve", &din_tomb);

    // Felveszünk sok elemet
    DinTomb_felvesz(&din_tomb, 8);
    DinTomb_felvesz(&din_tomb, 7);
    DinTomb_felvesz(&din_tomb, 6);
    DinTomb_felvesz(&din_tomb, 5);
    DinTomb_felvesz(&din_tomb, 4);
    DinTomb_felvesz(&din_tomb, 3);
    DinTomb_felvesz(&din_tomb, 2);
    DinTomb_felvesz(&din_tomb, 1);
    DinTomb_kirajzol("8...1 felveve", &din_tomb);

    return 0;
}

// Így működik a felvevő függvény:
void DinTomb_felvesz(DinTomb *dintomb_ptr, int ertek) {
    // Ha még nincs benne elem
    if (dintomb_ptr->tomb_ptr == NULL) {
        dintomb_ptr->tomb_ptr = (int *) malloc(sizeof(int)); // egynek elég hely foglalása
        *dintomb_ptr->tomb_ptr = ertek; // új érték felvétele
        dintomb_ptr->meret = 1; // méret növelése
        return;
    }
    // Ha már van benne
    int *temp = (int *) malloc(sizeof(int) * (dintomb_ptr->meret + 1)); // újrafoglalás
    for (size_t idx = 0; idx != dintomb_ptr->meret; ++idx) {
        temp[idx] = dintomb_ptr->tomb_ptr[idx]; // korábbiak átmásolása
    }
    temp[dintomb_ptr->meret++] = ertek; // új érték felvétele és méret növelése
    free(dintomb_ptr->tomb_ptr); // régi foglalás felszabadítása
    dintomb_ptr->tomb_ptr = temp;
}


// ^^^ Nektek a fenti rész a fontos! ^^^
// vvv Lefelé csak a bátrak nézzenek vvv


void DinTomb_kirajzol(const char* cim, DinTomb *dintomb_ptr) {
// Kirajzoló függvény teljesértékű megjelenítésért, kicsit csúnyácska helyenként, de ide elég jó lesz.
//         +----------------------+
// @0xNNN: |size_t meret = NNN;   |
//         +----------------------+
// @0xNNN: |int *tomb_ptr = 0xNNN;|
//         +-----+----------------+
//               |
//               v
//         +----------------------+
// @0xNNN: |tomb_ptr[0] = NNN     |
//         +----------------------+
// @0xNNN: |tomb_ptr[1] = NNN     |
//         +----------------------+
// @0xNNN: |tomb_ptr[2] = NNN     |
//         +----------------------+
    void keresztelem() {
        printf("                +------------------------------+\n");
    }
    void valtozo(void* ptr, const char* text, int val) {
        printf("%14p: |%13s = %14d|\n", ptr, text, val);
    }
    void pointer(void* ptr, const char* text, void* val) {
        printf("%14p: |%s = %14p|\n", ptr, text, val);
    }
    void nyil() {
        printf("                +-----+------------------------+\n");
        printf("                      |\n");
        printf("                      v\n");
    }

    printf("\t\t%s:\n", cim);
// struktúra kirajzolása
    keresztelem();
  // meret kirajzolása
    valtozo(&dintomb_ptr->meret, "size_t meret", dintomb_ptr->meret);
  // ptr kirajzolása
    keresztelem();
    pointer(&dintomb_ptr->tomb_ptr, "int *tomb_ptr", dintomb_ptr->tomb_ptr);

// van mutatott érték?
    if (dintomb_ptr->tomb_ptr == NULL) {
        keresztelem();
        printf("\n\n\n\n");
        return;
    } else {
        nyil();
    }

// tárolt adatok kirajzolása
    for (size_t i = 0; i != dintomb_ptr->meret; ++i) {
        keresztelem();
        char str[14];
        sprintf(str, "tomb_ptr[%d]", i);
        valtozo(&dintomb_ptr->tomb_ptr[i], str, dintomb_ptr->tomb_ptr[i]);
    }
    keresztelem();
    printf("\n\n\n\n");
}