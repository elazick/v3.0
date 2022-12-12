# v1.0

#Naudojimo instrukcija
- Paledus programą vartotojas gaus sąrašą įmanomų funkcijų:
1. Duomenu vedimas ranka (v0.1)
2. Duomenu skaitymas is failo(v0.2)
3. Failu generavimas(v0.3)
4. Spartos testas(v0.4)
5. Spartos testas su skirtingais algoritmais(v0.5)
-Norima funkcija pasirenkama įvedant atitinkamą numerį
-Vartotojui pateikiami pasirinkimai: (V/M) - čia "V" arba "v" - vidurkis, "M" arba "m" - mediana; (P/A) - čia "P" arba "p" - patys, "A" arba "a" - atsitiktinai; (T/N) - čia "T" arba "t" - taip, "N" arba "n" - ne.
-Pasirinkus duomenis įvesti rankiniu būdu, galima rinktis, ar pažymius generuoti atsitiktinai, ar vesti ranka, bei ar galutinį balą išvesti pagal vidurkį, ar pagal medianą.
-Pasirinkus generuoti failus, reikia įvesti norimą duomenų skaičių.
-Kiekvienos funckijos pabaigoje galima rinktis, ar baigti darbą. Jei norite vykdyti dar vieną funkciją, rinkitės "N".

#v0.1
Šioje programoje vartotojas įrašo studentų duomenis: vardą, pavardę, pažymių skaičių, pačius pažymius ir egzamino rezultatą. Vartotojas taip pat gali pasirinkti pažymius generuoti atsitiktinai. Toliau vartotojui pateikiamas pasirinkimas, kaip skaičiuoti galutinį rezultatą - naudojant vidurkį ar medianą. Vartotojui pasirinkus, programa apskaičiuoja galutinį rezultatą ir išveda jį į ekraną su atitinkamų studentų vardais ir pavardėmis. Programa realizuota naudojant du skirtingus konteinerių tipus: vektorius ir dinaminius masyvus.

Pastaba: dinaminio masyvo kode yra klaida, jis iki galo neveikia.

#v0.2
Toliau programą kuriame naudojant tik vektoriaus tipo konteinerį. Šioje versijoje v0.1 papildome galimybe studentų duomenis nuskaityti iš failo. Toliau atliekami veiksmai - studentų galutinio rezultato suskaičiavimas naudojant vidurkį arba medianą (priklausomai nuo vartotojo pasirinkimo). Gauti rezultatai tuomet yra išrašomi į naują failą.

Atliktas programos refactoring'as - funkcijų ir main failai iškelti į atskirus .cpp failus, o struktūra - į .h failą.

#v0.3
Šioje versijoje papildome v0.2 versiją galimybe studentų duomenų failą generuoti atsitiktinai. Generuojami 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų failai, priklausomai nuo vartotojo pasirinkimo. Toliau sugeneruoti failai yra nuskaitomi, vartotojui leidžiama pasirinkti, kaip skaičiuoti galutinį rezultatą. Jį suskaičiavus, studentai yra išskirstomi į dvi grupes: moksliukai(galutinis yra >=5) ir vargšiukai (galutinis yra < 5). Galiausiai, šios dvi grupės yra įrašomos į du naujus failus.

Programa taip pat atlieka laiko matavimą failų generavimui, nuskaitymui, išskirstymui bei įrašymui į failus. Žemiau pateikti laiko matavimo rezultatai kiekvienam duomenų kiekiui.

1000 failų sugeneruoti užtruko 0.0273sek, nuskaityti - 0.0224sek, surūšiuoti - 0.005sek, įrašyti į du failus - 0.0182sek.

![image](https://user-images.githubusercontent.com/112683136/207101726-feeb1693-2af0-41e2-88fd-7d0c97b706f8.png)


10000 failų sugeneruoti užtruko 0.276sek, nuskaityti - 0.193sek, surūšiuoti - 0.0469sek, įrašyti į du failus - 0.08sek.

![image](https://user-images.githubusercontent.com/112683136/207101777-5781bf33-6de5-4149-a64a-223d6dbd80c8.png)


100000 failų sugeneruoti užtruko 2.716sek, nuskaityti - 2.061sek, surūšiuoti - 0.48sek, įrašyti į du failus - 0.723sek.

![image](https://user-images.githubusercontent.com/112683136/207101884-7775db2e-a491-4b0c-9d68-4106a9403f28.png)


1000000 failų sugeneruoti užtruko 27sek, nuskaityti - 23sek, surūšiuoti - 4.723sek, įrašyti į du failus - 7.304sek.

![image](https://user-images.githubusercontent.com/112683136/207101971-37866f5c-3542-4c88-a942-d9328eb2b467.png)

10000000 failų sugeneruoti užtruko apie 20min, nuskaityti - 6min, surūšiuoti - 1min19sek, įrašyti į du failus - 1min17sek.

![image](https://user-images.githubusercontent.com/112683136/207102078-feda91b9-9a34-464c-a4e6-9c7002cef8d5.png)

Įdomus pastebėjimas: programos veikimo laikas generuojant 10000000 failų buvo net keturis kartus mažensis, kai kompiuteris buvo prijungtas prie krovimo laido - tada programa užtruko vos 5min.

#v0.4

0.3 versiją papildome galimybe atlikti failų įrašymo spartos testą tarp skirtingų konteinerių tipų: std::list ir std::vector. Spartos testas matuoja failų nuskaitymo ir duomenų išskirstymo į dvi grupes pagal galutinį balą laiką.

Žemiau pateiktoje iškarpoje yra testavimo rezultatai. Juose matome, jog, nepriklausomai nuo duomenų kiekio, programa darbą atliko greičiau su std::list tipo struktūra.
![image](https://user-images.githubusercontent.com/112683136/207102862-7a929ce1-c764-4cca-bc73-28486569397d.png)

#v1.0
Visos aukščiau išvardintos funkcijos apjungiamos į vieną programą. Kad būtų paprasčiau skaityti kodą atliktas papildomas refactoring'as išskadant funkcijas pagal jų tipą. Taip pat vartotojo patogumo dėlei programa pakeista iš klausimų "Ar norite daryti ....", į meniu pasirinkimus. 

Atliekamas programos spartos testas naudojant skirtingas studentų dalijimo į dvi kategorijas strategijas - kuriant tik vieną naują konteinerį n ir į jį sukeliant duomenis studentų, kurių galutinis balas mažesnis už 5.0, o kitus paliekant konteineryje stud, arba kuriant du naujus konteinerius.

Abiejoms strategijoms naudoti algoritmai:
-std::sort - duomenys vektoriuje išdėstomi didėjimo tvarka pagal galutinį balą;
-std::find_if - randamas pirmas elementas vektoriuje, kurio galutinis balas lygus 5.0;
-std::move - į naują vektorių sukeliami elementai iki to, kurio galutinis balas lygus 5.0. Antroje strategijoje elementai, esantys po rasto elemento taip pat sukeliami į naują konteinerį;
-Pirmoje strategijoje naudotas std::erase - iš pirmojo konteinerio ištrinami elementai, perkelti į naują konteinerį.
![image](https://user-images.githubusercontent.com/112683136/207106011-a61e5be5-7675-40a9-9431-cf5953126e77.png)

Iš rezultatų matome, kad programa veikia greičiausiai su vienu list tipo konteineriu, ir apskritai list konteineriai yra spartens, nei vector, nepriklausomai nuo jų kiekio.

Taip pat vykdytas programos spartos testas naudojant tik std::vector konteinerio tipą, tačiau jam taikant skirtingus algoritmus:
-Toks pat algoritmas, kaip atliekant spartos testą sukuriant tik vieną naują konteinerį;
-Dalis duomenų sukeliami į naują konteinerį naudojant std::stable_partition ir std::copy algoritmus. Į naują vektorių sukelti duomenys iš senojo pašalinami naudojant std::erase algoritmą;
-Toks pat algoritmas, kaip atliekant spartos testą sukuriant du naujus konteinerius;
 -Duomenys išskirstomi į du naujus vektorius naudojant std::partition_copy algoritmą.
 
![image](https://user-images.githubusercontent.com/112683136/207106643-ba833a48-724f-427c-96eb-22a89aa55114.png)

Čia pastebime, jog tiek stable_partition ir copy, tiek partition_copy algoritmų pritaikymas yra efektyvesnis už algoritmus, naudotus pirmame spartos teste, kai duomenų kiekis yra 1000, 10000 arba 1000000. Kai turime 100000 arba 10000000 duomenų akivaizdžiai sparčiausias algoritmas yra partition_copy, o visi kiti algoritmai užtrunka maždaug tiek pat laiko. 

Testavimo sistemos parametrai: CPU 11th Gen Intel(R) Core(TM) i7-1165G7 @ 2.80GHz 2.80 GHz; RAM 16GB; SSD.
