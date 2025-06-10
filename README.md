# Dokumentacja - Prosty kalkulator z obsługą błędów w C++

## 1. Opis projektu

Projekt przedstawia prosty kalkulator w języku C++ z implementacją mechanizmu **try-catch** do obsługi błędów. Program demonstruje jak prawidłowo obsługiwać różne typy wyjątków w aplikacji konsolowej.

## 2. Funkcjonalności

Program oferuje dwie podstawowe operacje matematyczne:
- **Dzielenie dwóch liczb** z kontrolą dzielenia przez zero
- **Pierwiastek kwadratowy** z kontrolą liczb ujemnych

## 3. Struktura kodu

### 3.1 Funkcje główne

#### `double dziel(double a, double b)`
- **Cel**: Wykonuje dzielenie dwóch liczb
- **Parametry**: 
  - `a` - dzielna (liczba rzeczywista)
  - `b` - dzielnik (liczba rzeczywista)
- **Zwraca**: Wynik dzielenia (double)
- **Wyjątek**: `runtime_error` gdy `b = 0`

#### `double pierwiastek(double x)`
- **Cel**: Oblicza pierwiastek kwadratowy
- **Parametry**: 
  - `x` - liczba z której obliczamy pierwiastek
- **Zwraca**: Pierwiastek kwadratowy (double)
- **Wyjątek**: `invalid_argument` gdy `x < 0`

### 3.2 Mechanizm obsługi błędów

Program wykorzystuje blok **try-catch** z trzema poziomami obsługi:

```cpp
try {
    // Kod który może generować wyjątki
}
catch (runtime_error& e) {
    // Obsługa błędów wykonania (np. dzielenie przez zero)
}
catch (invalid_argument& e) {
    // Obsługa błędów argumentów (np. nieprawidłowe dane)
}
catch (...) {
    // Obsługa wszystkich innych nieoczekiwanych błędów
}
```

## 4. Przypadki testowe - Gdzie występują błędy

### 4.1 Błąd: Dzielenie przez zero

**Kiedy występuje:**
- Użytkownik wybiera opcję 1 (dzielenie)
- Podaje jako dzielnik wartość 0

**Przykład testu:**
```
Wybierz opcję: 1
Podaj pierwszą liczbę: 15
Podaj drugą liczbę: 0
```

**Oczekiwany wynik:**
```
BŁĄD: Nie można dzielić przez zero!
```

**Dlaczego to błąd:**
W matematyce dzielenie przez zero jest operacją nieokreśloną. W programowaniu może prowadzić do:
- Nieskończoności (infinity)
- Crashu programu
- Nieprzewidywalnych wyników

### 4.2 Błąd: Pierwiastek z liczby ujemnej

**Kiedy występuje:**
- Użytkownik wybiera opcję 2 (pierwiastek)
- Podaje liczbę ujemną

**Przykład testu:**
```
Wybierz opcję: 2
Podaj liczbę: -25
```

**Oczekiwany wynik:**
```
BŁĄD: Nie można obliczyć pierwiastka z liczby ujemnej!
```

**Dlaczego to błąd:**
- W liczbach rzeczywistych pierwiastek z liczby ujemnej nie istnieje
- Funkcja `sqrt()` dla liczb ujemnych zwraca NaN (Not a Number)
- W niektórych systemach może powodować błąd wykonania

### 4.3 Błąd: Nieprawidłowy wybór opcji

**Kiedy występuje:**
- Użytkownik podaje opcję inną niż 1 lub 2

**Przykład testu:**
```
Wybierz opcję: 5
```

**Oczekiwany wynik:**
```
BŁĄD: Nieprawidłowy wybór!
```

**Dlaczego to błąd:**
- Program obsługuje tylko opcje 1 i 2
- Inne wartości prowadzą do nieprzewidywalnego zachowania
- Dobra praktyka to walidacja danych wejściowych

## 5. Typy wyjątków używane w projekcie

### 5.1 `std::runtime_error`
- **Zastosowanie**: Błędy które występują podczas wykonania programu
- **W projekcie**: Dzielenie przez zero
- **Charakterystyka**: Błędy logiczne w działaniu programu

### 5.2 `std::invalid_argument`
- **Zastosowanie**: Nieprawidłowe argumenty przekazane do funkcji
- **W projekcie**: Pierwiastek z liczby ujemnej, nieprawidłowy wybór opcji
- **Charakterystyka**: Błędy związane z danymi wejściowymi

### 5.3 `...` (catch-all)
- **Zastosowanie**: Wszystkie inne, nieoczekiwane wyjątki
- **W projekcie**: Zabezpieczenie przed nieznanymi błędami
- **Charakterystyka**: Ostatnia linia obrony programu

## 6. Instrukcja kompilacji i uruchomienia

### Kompilacja:
```bash
g++ -o kalkulator main.cpp -std=c++11
```

### Uruchomienie:
```bash
./kalkulator
```

## 7. Scenariusze testowania

### Test 1: Poprawne dzielenie
```
Opcja: 1
Liczba 1: 20
Liczba 2: 4
Oczekiwany wynik: 20 / 4 = 5
```

### Test 2: Dzielenie przez zero
```
Opcja: 1
Liczba 1: 10
Liczba 2: 0
Oczekiwany wynik: BŁĄD: Nie można dzielić przez zero!
```

### Test 3: Poprawny pierwiastek
```
Opcja: 2
Liczba: 16
Oczekiwany wynik: √16 = 4
```

### Test 4: Pierwiastek z liczby ujemnej
```
Opcja: 2
Liczba: -9
Oczekiwany wynik: BŁĄD: Nie można obliczyć pierwiastka z liczby ujemnej!
```

### Test 5: Nieprawidłowa opcja
```
Opcja: 3
Oczekiwany wynik: BŁĄD: Nieprawidłowy wybór!
```

## 8. Korzyści z obsługi błędów

1. **Stabilność**: Program nie crashuje przy błędnych danych
2. **Użyteczność**: Użytkownik otrzymuje czytelne komunikaty błędów
3. **Debugowanie**: Łatwiejsze znajdowanie i naprawianie problemów
4. **Profesjonalizm**: Aplikacja zachowuje się przewidywalnie

## 9. Możliwe rozszerzenia

- Dodanie pętli głównej dla wielokrotnego użycia
- Walidacja danych wejściowych (sprawdzanie czy użytkownik podał liczbę)
- Dodanie większej liczby operacji matematycznych
- Implementacja własnych klas wyjątków
- Logowanie błędów do pliku
