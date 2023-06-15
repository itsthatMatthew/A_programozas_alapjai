# C nyelvi jegyzet

*Rövid összefoglaló jegyzet a szükséges nyelvi ismeretekhez*

---

## 0. Bevezetés

Mély, részletes anyag és az aktualitások a tárgyholnapon: <https://infoc.eet.bme.hu/> (kötelezően ezzel kell kezdeni!)

Ennek a jegyzetnek a célja röviden és lényegretörően, de érthetően átadni alapkoncepciókat és az elméletet. Ezt teszi sokkal inkább a C programozási nyelvvel kapcsolatban, nem célja hatékony algoritmusokat és feladatmegoldásokat bemutatni.

### Tartalomjegyzék

[1. Változók](#1-változók)

[2. Vezérlési szerkezetek](#2-vezérlési-szerkezetek)

[3. Tömbök](#3-tömbök)

---

## 1. Változók

Több egyszerű analógia is létezik változókra, gondolhatunk rájuk úgy, mint:

- házakra egy városban,
- dobozokra egy raktárban,
- vagy oldalakra egy könyben.

A közös mindháromban az, hogy "bennük" valamilyen tényleges adatot lehet tárolni.
Ez a gondolkodásmód egy absztrakciós réteget képez a számítógép memóriája és az emberi világ között, sokkal könnyebb róluk beszélni, névvel illetni őket, valamint hihetetlenül jól képesek leképezni a tényleges háttérbeli történéseket.

### Típusok

C-ben a változóink erősen típusosak, tehát mindig meg kell mondanunk, hogy milyen adatot is tárolunk bennük. A nyelv által támogatott alapvető típusok a következőek:

- `char`
- `int`
- `float`
- `double`

Ez egészen kevésnek tűnik, de bizonyos módosítószavakkal, valamint egyszerűen ezekre az alaptípusokra építve nagyon sok mindent el tudunk érni.

Egy változó *deklaráció*jának hívjuk azt a kódsort, amikor őt létrehozzuk, például:

```c
    int a; // az "a" nevű változó deklarációja egész számként
```

Ha egy változót csak deklarálunk, akkor a felvett értékében nem lehetünk biztosak.
Egy változót ha csak lehet *inicializáljunk*, azaz létrehozáskor adjunk is neki értéket:

```c
    int a = 0; // az "a" nevű változó inicializációja 0-ra
```

Egyébként a változónk bármilyen (határozatlan) értéket tárolhatna.

Nézzünk még pár példát a többi típusra is:

```c
    int i = 0; // A már korábban látott egész számot tárolni képes típus.

    unsigned u = 1; // Előjel nélküli számok tárolására alkalmas típus (így 2x annyi,
                    // de csak pozitív szám tárolható el benne).
                    // Az "unsigned" módosító valamennyi típus elé kihelyezhető.

    long long l = 10; // A legnagyobb méretű egész szám típus. Hasznos lehet, főleg
                      // ha az előjel nélküliséggel ötvözzük.

    char c = 'a'; // Karakterek tárolására alkalmas típus, 1 byte-nyi helyet foglal
                  // (egy karakternyi), a karaktereket számértékként tárolva,
                  // ezek az ASCII táblának megfelelően "lefordíthatóak".

    float f = 1.1f; // Lebegőpontos számokat tárolni képes típus.

    double d = 3.14159; // 2x nagyobb méretű lebegőpontos típus a nagyobb precizitásért.
```

Több változót is létrehozhatunk egyszerre, ekkor vesszővel kell a neveket elválasztani:

```c
    int x = 1, y = 2; // Egy "x" és egy "y" nevű változót hozunk létre 1 és 2 értékekkel.
```

Amennyiben egy változó értékének a megváltozását nem akarjuk megengedni, a változót konstansként deklarálhatjuk. Ekkor kötelező inicializálni, és a tárolt értéke a későbbiekben sem változtatható meg:

```c
    const int a = 3; // "a" a program teljes futása során a 3 értéket fogja felvenni.
```

### Konverziók

Amennyiben egy változóban olyan értéket szeretnék tárolni, ami nem a típusának megfelelő, valamilyen *típuskonverzió* fog végrehajtódni. Ez azért veszélyes, mert ha nem vigyázunk, könnyen információt vesztetünk! Példák:

```c
    char c = 300; // A "c" változóban 44 lesz letárolva, ezt hívják túlcsordulásnak.

    int i = 3.14; // Az "i" változóban 3 lesz letárolva, ezt hívják levágásnak.
```

Ezekre az esetekre a fordító is igyekszik felhívni a figyelmünket, de mi is legyünk körültekintőek.
A fenti példákat kifejezetten "implicit" típuskonverziónak hívjuk, hiszen szintaktikailag semmi nem jelzi, hogy nekik meg kéne történniük.
Ha valamiért (és később lesz rá okunk) biztosra szeretnénk menni, hogy egy ilyen típuskonverzió megtörténjen, ezt "explicit" módon is megtehetjük a következő képpen:

```c
    int i = (int) 13.7;
```

### Műveletek

Persze mindez a sok inicializálás mind értelmetlen lenne anélkül, ha a változóinkkal műveleteket lehetne végezni. Ilyen műveletek alapcsoportja például az aritmetikai műveletek (összeadás, kivonás, szorzás), melyek mind jelen vannak a C nyelvben.

A legegyértelműbb ilyen művelet az értékadás, mely az egyenlőségjellel tehető meg, akár változók között is:

```c
    int a = 0; // Az "a" változó 0-ra inicializálva.

    int b = a; // A "b" változó "a" értékével, azaz 0-val inicializálva.

    b = 3; // "b" változó értéke felülírva 3-mal

    a = b; // "a" változó értéke felülírva "b" értékével, azaz hárommal.
```

Természetesen nem csak egyedül értékadást tudunk változókkal végezni, de a már fent említett aritmetikai műveleteket is el tudjuk végezni, akár konkrét értékekkel (*literálokkal*), vagy más változókkal, sőt, ezt értékadáskor is megtehetjük:

```c
    int a = 2, b = 3; // "a" és "b" változók 2 és 3 értékekkel.

    int c = a + b; // "c" változó inicializálása "a" és "b" összegével, azaz 5-tel.

    b = a * c; // "b" értékét felülírjuk "a" és "c" szorzatával, azaz 10-zel.

    const int x = a - c; // "x" értéke "a" és "c" különbségére, azaz -3-ra inicializálva.

    const int y = -b; // "y" értéke "b" ellentetjére, azaz -10-re inicializálva.
```

Természetesen ezek a műveletek mind a 4 alaptípusra elvégezhetőek, de maradjunk egyelőre `int`-eknél. Az elefánt a szobában az osztás lesz, mely lebegőpontos számokra tökéletesen azt fogja csinálni, amit várnánk, egész számokra mégis egy érdekes jelenség fog előkerülni:

```c
    int a = 11 / 3; // "a" értéke 3-ra fog inicializálódni.
```

Ezt a jelenséget "integer osztásnak" hívják, és sokkal rosszab implikációi vannak, mint a fenti példa, mivel jelen esetben nem csak egyszerű levágásról van szó:

```c
    float pi = 22 / 7; // "pi" 3.0-ra fog inicializálódni.
```

Ez egy fájó rossz, amivel együtt kell élnünk, de a már korábban megismert explicit típuskoncerzióval például kezelhető:

```c
    float pi_1 = (float) 22 / 7; // A típuskonverzió előbb fog elvégződni, egy lebegőpontos
                                 // és egy egész szám osztása pedig megfelelő eredményt ad.

    float pi_2 = 22.f / 7; // Ezzel a jelöléssel is biztosra mehetünk, hogy lebegőpontos
                           // osztás fog történni.
```

Egész osztáshoz tartozó nagyon fontos aritmetikai művelet még a moduló számítás. Ha visszamegyünk a korábbi példára, jól látszik, hogy hogyan egészítik ki egymást:

```c
    int osztando = 11; // Az osztandót 11-re inicializáljuk.
    int oszto = 3; // Az osztót pedig 3-ra.

    int megvan = osztando / oszto; // Értéke 3, hiszen 11-ben a három 3-szor van meg.
    int maradek = osztando % oszto; // Értéke 2, hiszen 11 3-mal osztva 2 maradékot ad.

    int eredeti = megvan * oszto + maradek; // 3 * 3 + 2 = 11
```

Két egész szám osztási maradékát határozza meg, de negatív számoknál óvatosan kell eljárni, mert az eredmény meghatározása gyakran fordítónként és platformonként változik.

Hasznos ismeret még, hogy aritmetikai műveletek elvégzése és önértékadása rövidíthető:


```c
    int a = 0; // Inicializáció.

    a = a + 2; // "a" változóhoz kettőt adunk, majd eltároljuk saját magában.
    a += 2; // A felső sor rövidítése, ugyan azt a hatást érjük el.
```

Továbbá ha egy értéket eggyel szeretnénk csökkenteni avgy növelni, erre is létezik rövidítés, kettő kategóriában:

```c
    int a = 0; // Inicializáció.

    a++; // Poszt-inkrementálás, a példában "a" értéke 1-re változik.
    ++a; // Pre-inkrementálás, a példában "a" értéke 2-re változik.

    a--; // Poszt-dekrementálás, a példában "a" értéke 1-re változik.
    --a; // Pre-dekrementálás, a példában "a" értéke 0-ra változik.
```

Önmagukban a két művelet nagyon hasonlónak tűnik, a különbség abból fakad, hogy a változó értéke a kifejezés "előtt" vagy "után" változik meg. Példa:

```c
    int a = 1; // "a" értéke 1-re.

    int b = ++a; // Először "a" értékét változtatjuk meg, majd ez az érték íródik "b"-be.

    int c = a++; // Először "a" értékét írjuk "c"-be, majd "a" értékét megváltoztatjuk.
```

Ez hasznos eszköz lehet sok `a += 1;` kifejezések lerövidítésére, de a sorrendiségre mindig nagyon oda kell figyelni!

---

## 2. Vezérlési szerkezetek

### Szekvencia

### Elágazások

### Ciklusok

---

## 3. Tömbök

---

## 4. Függvények

---

## 6. Struktúrák

---

## 7. Pointerek

---

## 8. Sztringek

---

## 9. Fájlkezelés

---

## 10. Rekurzió

---

## 11. Operátorok

---

## 12. Bitmanipuláció

---

## 13. Dinamikus memóriakezelés

---

## 14. Modulokra bontás

---

## 15. Láncolt listák

---

## 16. Bináris fák

---

## 17.  Állapotgépek