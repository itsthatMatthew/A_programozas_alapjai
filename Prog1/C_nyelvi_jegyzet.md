# C nyelvi jegyzet

*Rövid összefoglaló jegyzet a szükséges nyelvi ismeretekhez*

---

## Bevezetés

Mély, részletes anyag és az aktualitások a tárgyholnapon: <https://infoc.eet.bme.hu/> (kötelezően ezzel kell kezdeni!)

Ennek a jegyzetnek a célja röviden és lényegretörően, de érthetően átadni alapkoncepciókat és az elméletet. Ezt teszi sokkal inkább a C programozási nyelvvel kapcsolatban, nem célja hatékony algoritmusokat és feladatmegoldásokat bemutatni.

A [függellék](#függellék) tartalmaz linkeket olyan további olvasmányokra, amiket itt kifejteni feleslegesen sok lenne.

## Tartalomjegyzék

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
Ez a gondolkodásmód nekünk egy tökéletes absztrakciós réteg, sokkal könnyebb így róluk beszélni, névvel illetni őket.

### Típusok

A doboz gondolkodásmód csavarja, hogy C-ben mindig meg kell mondanunk, hogy milyen adatot is tárolunk bennük. Ezt jellemezzük a változó típusával. A nyelv által támogatott alapvető ("beépített") típusok a következőek [[1]](#1-httpsenwikipediaorgwikic_data_types):

- `char` (betűket tud tárolni, pl.: `'a'` vagy `'Z'`, de csak 8 biten)
- `int` (egész számokat tud tárolni, pl.: `-123` vagy `10198`)
- `float` (lebegőpontos számokat tud tárolni, pl.: `-1.41` vagy `3.1415`)
- `double` (hasonló a `float`-hoz, csak nagyobb pontosságot biztosít)

Ez egészen kevésnek tűnik, de bizonyos módosítószavakkal, valamint egyszerűen ezekre az alaptípusokra építve nagyon sok mindent el tudunk érni.

### Deklaráció

Egy változó *deklaráció*jának hívjuk azt a kódsort, amikor őt létrehozzuk, például:

```c
    int a; // Az "a" nevű változó deklarációja egész számként.
```

Ezt követően az "a" nevű változónkban már képesek vagyunk valami konkrét értéket eltárolni.
Ezt az egyenlőségjellel tehetjük meg, értékadásnak hívjuk:

```c
    int a; // Az "a" nevű változó deklarációja.
    a = 1; // Az 1 érték eltárolása "a"-ban.
```

Ha egy változót csak deklarálunk, akkor a felvett értékében nem lehetünk biztosak.
Ezt azért baj, mert ha így használnánk fel, akkor valami határozatlan értéket olvasnánk ki belőle.
Egy változót ha csak lehet *inicializáljunk*, azaz létrehozáskor adjunk is neki értéket:

```c
    int a = 0; // Az "a" nevű változó inicializációja 0-ra.
```

Létrehozás után is felül tudunk írni egy változót más értékkel:

```c
    int a = 0; // Az "a" nevű változó inicializációja 0-ra.
    a = 1;     // Az "a" nevű változó értékének megváltoztatása 1-re.
    a = 2;     // Az "a" nevű változó értékének megváltoztatása 2-re.
```

Valamint egy változóba egy másik értékét is eltárolhatjuk:

```c
    int a = 1; // Az "a" nevű változó inicializációja 1-re.
    int b = 2; // A "b" nevű változó inicializációja 2-re.

    b = a; // "a" értékének eltárolása "b"-ben, így "a" és "b" is 1 értékű lesz.
```

Több változót is létrehozhatunk egyszerre, ekkor vesszővel kell a neveket elválasztani:

```c
    int x = 1, y = 2; // Egy "x" és egy "y" nevű változót hozunk létre 1 és 2 értékekkel.
```

### Konverziók

Amennyiben egy változóban olyan értéket szeretnék tárolni, ami nem a típusának megfelelő, valamilyen *típuskonverzió* fog végrehajtódni. Ez azért veszélyes, mert ha nem vigyázunk, könnyen információt vesztetünk! Példák:

```c
    char c = 300; // A "c" változóban 44 lesz letárolva, ezt hívják túlcsordulásnak.

    int i = 3.14; // Az "i" változóban 3 lesz letárolva, ezt hívják levágásnak.
```

Ezekre az esetekre a fordító is igyekszik felhívni a figyelmünket, de mi is legyünk körültekintőek.
A fenti példákat kifejezetten "implicit" típuskonverziónak hívjuk, hiszen szintaktikailag semmi nem jelzi, hogy nekik meg kéne történniük.
Ilyen típuskonverzió elvégezhető "explicit" módon is a következő szintaktikával: `(int) 13.7`

### Műveletek

Persze mindez a sok inicializálás és értékadás mind értelmetlen lenne anélkül, ha a változóinkkal műveleteket lehetne végezni. Ilyen műveletek alapcsoportja például az aritmetikai műveletek (összeadás, kivonás, szorzás), melyek mind jelen vannak a C nyelvben.

Ilyen műveleteket egyszerűen tudunk végezni, akár konrét értékekkel, akár változókkal. A műveletek kiértékelése szabályosan fog megtörténni, akár zárójeleket is felhasználhatunk:

```c
    int a = 2, b = 3; // "a" és "b" változók 2 és 3 értékekkel.

    int c = 5 * a + 6 / (b - 2); // Helyesen "c"-be 11 fog eltárolódni.
```

Az osztás kicsit problémás művelet, mert míg lebegőpontos számokra úgy fut, ahogyan várnánk, egész számok osztásánál egy érdekes jelenség merül fel:

```c
    22 / 7; // A kifejezés "3" értéket fog adni.
```

Ennek a jelenségnek fontos következményei vannak:

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
    22 % 7; // "1" értéket fog adni, ami az osztási maradék.
```

Negatív számoknál óvatosan kell eljárni, mert az eredmény meghatározása nem is definiált.

Hasznos ismeret még, hogy aritmetikai műveletek elvégzése és önértékadása rövidíthető:

```c
    a = a + 2; // "a" változóhoz kettőt adunk, majd eltároljuk saját magában.
    a += 2;    // A felső sor rövidítése, ugyan azt a hatást érjük el.
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
                 // Tehát "a" és "b" is 2 lesz.
    int c = a++; // Először "a" értékét írjuk "c"-be, majd "a" értékét megváltoztatjuk.
                 // Tehát "c" még 2 lesz, de "a" már 3 a végére.
```

Ez hasznos eszköz lehet sok `a += 1;` kifejezések lerövidítésére, de a sorrendiségre mindig nagyon oda kell figyelni!

### Változónevek

> There are only two hard things in Computer Science: cache invalidation and naming things.

Minket igazán csak a második érdekel most, az biztos, hogy nehéz jó változóneveket kitalálni. Pár szabály írja le, hogy milyennek választhatjuk meg őket:

- Betűket, számokat és aláhúzást tartalmazhatnak
- Számmal nem kezdődhetnek
- Minden változónévnek egyedinek kell lenni, de a kis- és nagybetűk külön vannak kezelve
- Kulcsszavak nem lehetnek változónevek

Valamint bár sokan szeretik, érdemes az alulhúzással kezdődő neveket kerülni [[2]](#2-on-leading-underscores-and-names-reserved-by-the-c-and-c-languages).

Mindenkinek érdeke, hogy a változónevek rövidek, de lényegre törőek, mégis beszédesek legyenek. Ez egy kellően nehéz feladat, de a rövidítéseket, random egybetűs változóneveket érdemes kerülni, írjunk kódot mindig úgy, mintha azt utána valaki másnak kellene átolvasnia (gyakran saját magunk is így fogjuk érezni).

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

---

## Függellék

*Minden olyan link vagy további olvasmány, aminek a kifejtése túl sok lenne ide.*

#### [[1]: https://en.wikipedia.org/wiki/C_data_types](https://en.wikipedia.org/wiki/C_data_types)

#### [[2]: On leading underscores and names reserved by the C and C++ languages](https://devblogs.microsoft.com/oldnewthing/20230109-00/?p=107685)
