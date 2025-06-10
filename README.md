# Dokumentacja - Prosty kalkulator z obsługą błędów w C++

## 1. Opis projektu

Projekt przedstawia prosty kalkulator w języku C++ z implementacją mechanizmu **try-catch** do obsługi błędów. Program demonstruje jak prawidłowo obsługiwać różne typy wyjątków w aplikacji konsolowej.

## 2. Funkcjonalności

Program oferuje dwie podstawowe operacje matematyczne:
- **Dzielenie dwóch liczb** z kontrolą dzielenia przez zero
- **Pierwiastek kwadratowy** z kontrolą liczb ujemnych

### 3 Funkcje główne

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

### 4 Mechanizm obsługi błędów

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

## 5. Przypadki testowe - Gdzie występują błędy

### 5.1 Błąd: Dzielenie przez zero

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

### 5.2 Błąd: Pierwiastek z liczby ujemnej

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

### 5.3 Błąd: Nieprawidłowy wybór opcji

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

## 6. Typy wyjątków używane w projekcie

### 6.1 `std::runtime_error`
- **Zastosowanie**: Błędy które występują podczas wykonania programu
- **W projekcie**: Dzielenie przez zero
- **Charakterystyka**: Błędy logiczne w działaniu programu

### 6.2 `std::invalid_argument`
- **Zastosowanie**: Nieprawidłowe argumenty przekazane do funkcji
- **W projekcie**: Pierwiastek z liczby ujemnej, nieprawidłowy wybór opcji
- **Charakterystyka**: Błędy związane z danymi wejściowymi

### 6.3 `...` (catch-all)
- **Zastosowanie**: Wszystkie inne, nieoczekiwane wyjątki
- **W projekcie**: Zabezpieczenie przed nieznanymi błędami
- **Charakterystyka**: Ostatnia linia obrony programu
