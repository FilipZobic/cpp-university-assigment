# Zavrsni projekat za predmet OOP II

**Smer:** Softversko Informaciono Inzinjerstvo

**Godina Studija:** II

**Semestar:** III

**Predmetni Profesor:** Djordje Obradović

**Asistent:** Ivan Radosavljević

**Student:** Zobić Filip — *2019270036*

## Pokretanje
...

## Opis
Projektni zadatak
Napraviti grafički program za upravljanjem zaposlenima u preduzeću. Preduzeće je opisano nazivom,
matičnim brojem i poreskim identifikacionim brojem - pib. Svako preduzeće se sastoji iz proizvoljnog broja
odeljenja. Odeljenje je opisano nazivom i u sebi sadrži podatke o šefu odeljenja i trenutno zaposlenim
radnicima. U odeljenju obezbediti metode za zapošljavanje novih radnika i za davanje otkaza već zaposlenim
radnicima.

U sistemu definisati apstraktnu klasu osoba koja sadrži atribute ime, prezime i datum rođenja. Ovu klasu
potom nasleđuje apstraktna klasa radnik koja sadrži dodatni atribut koji predstavlja visinu plate.
Konkretni tipovi radnika mogu biti prodavac, vozač i magacioner. Prodavac sadrži podatak o kasi na kojoj je
zadužen. Vozač sadrži spisak kategorija vozila kojima može da upravlja i broj prekršaja načinjenih tokom
vožnje. Magacioner nema dodatne atribute.

U aplikaciju dodati mogućnost dodeljivanja godišnjih odmora radnicima. Svaki godišnji odmor je opisan
početkom i krajem. Godišnji odmor ne može trajati više od 24 dana u godini. Onemogućiti da se radniku
dodaju termini godišnjeg odmora koji bi narušili ovo ograničenje.
U prikazu podataka o zaposlenom napraviti komponentu za crtanje vizit karte zaposlenog. Vizit karata se crta
kao pravougaonik dimenzija 200x100 piksela u kojem su ispisani podaci o nazivu preduzeća, imenu i
prezimenu radnika, poziciji radnika i broju poslovnog telefona radnika kao i adresi i broj telefona preduzeća.
U slučaju da navedeni podaci nisu dostupni u programu, program proširiti tako da ih sadrži.
Za sve prethodno navedene tipove objekata obezbediti mogućnost zapisivanja i čitanja iz datoteka. Različite
tipove objekata zapisati u odvojene datoteke.

Uklanjanje objekata realizovati kao fizičko uklanjanje, odnosno obezbediti da uklonjeni objekat bude zaista
uklonjen iz memorije i iz datoteka u kojima je uskladišten. Pri uklanjanju povezanih objekata ispoštovati
ograničenja kompozicije i agregacije.
Za svaki od tipova objekata navedenih u specifikaciji programa obezbediti tabelarni prikaz i upravljanje u
vidu prikaza, dodavaja, izmene i uklanjanja objekata. Za povezane objekte obezbediti popunjavanje podataka
tako da se onemogući uvezivanje sa nepostojećim objektima.

