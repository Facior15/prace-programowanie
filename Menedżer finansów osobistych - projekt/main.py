class Transakcja:
    def __init__(self, kwota, kategoria, typ):
        self.kwota = kwota
        self.kategoria = kategoria
        self.typ = typ

    def pobierz_opis(self):
        return f"[{self.typ}] {self.kategoria}: {self.kwota} zł"


class Budzet:
    def __init__(self):
        self.lista_transakcji = []
        self.saldo = 0.0

    def dodaj_transakcje(self, transakcja):
        self.lista_transakcji.append(transakcja)
        if transakcja.typ == "Przychód":
            self.saldo += transakcja.kwota
        elif transakcja.typ == "Wydatek":
            self.saldo -= transakcja.kwota

    def wyswietl_historie(self):
        if len(self.lista_transakcji) == 0:
            print("Historia transakcji jest pusta.")
        else:
            print("\n--- HISTORIA TRANSAKCJI ---")
            for t in self.lista_transakcji:
                print(t.pobierz_opis())

    def filtruj_po_kategorii(self, szukana_kategoria):
        znaleziono = False
        print(f"\n--- TRANSAKCJE W KATEGORII: {szukana_kategoria} ---")

        for t in self.lista_transakcji:
            if t.kategoria.lower() == szukana_kategoria.lower():
                print(t.pobierz_opis())
                znaleziono = True

        if not znaleziono:
            print("Nie znaleziono żadnych transakcji w tej kategorii.")

    def pokaz_saldo(self):
        print(f"\nAktualny stan konta: {self.saldo} zł")
        if self.saldo < 0:
            print("UWAGA: Twój budżet jest na minusie!")


moj_budzet = Budzet()

while True:
    print("\n=== SYSTEM ZARZĄDZANIA BUDŻETEM ===")
    print("1. Dodaj przychód")
    print("2. Dodaj wydatek")
    print("3. Pokaż historię transakcji")
    print("4. Filtruj transakcje po kategorii")
    print("5. Sprawdź stan konta (saldo)")
    print("6. Zakończ program")

    wybor = input("Wybierz opcję (1-6): ")

    if wybor == "1":
        kwota = float(input("Podaj kwotę przychodu w zł: "))
        kategoria = input("Podaj źródło (np. Wypłata, Kieszonkowe): ")
        nowa_transakcja = Transakcja(kwota, kategoria, "Przychód")
        moj_budzet.dodaj_transakcje(nowa_transakcja)
        print("Pomyślnie dodano przychód!")

    elif wybor == "2":
        kwota = float(input("Podaj kwotę wydatku w zł: "))
        kategoria = input("Podaj kategorię (np. Jedzenie, Rozrywka): ")
        nowa_transakcja = Transakcja(kwota, kategoria, "Wydatek")
        moj_budzet.dodaj_transakcje(nowa_transakcja)
        print("Pomyślnie dodano wydatek!")

    elif wybor == "3":
        moj_budzet.wyswietl_historie()

    elif wybor == "4":
        szukana = input("Podaj nazwę kategorii do przefiltrowania: ")
        moj_budzet.filtruj_po_kategorii(szukana)

    elif wybor == "5":
        moj_budzet.pokaz_saldo()

    elif wybor == "6":
        print("Dziękuję za skorzystanie z programu.")
        break

    else:
        print("Niepoprawny wybór! Wybierz cyfrę od 1 do 6.")