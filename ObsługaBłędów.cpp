#include <iostream>
#include <stdexcept>

using namespace std;

double dziel(double a, double b) {
    if (b == 0) {
        throw runtime_error("Nie można dzielić przez zero!");
    }
    return a / b;
}

double pierwiastek(double x) {
    if (x < 0) {
        throw invalid_argument("Nie można obliczyć pierwiastka z liczby ujemnej!");
    }
    return sqrt(x);
}

int main() {
    int wybor;
    double a, b, wynik;

    cout << "=== PROSTY KALKULATOR ===" << endl;
    cout << "1. Dzielenie" << endl;
    cout << "2. Pierwiastek kwadratowy" << endl;
    cout << "Wybierz opcję (1 lub 2): ";
    cin >> wybor;

    try {
        switch (wybor) {
        case 1:
            cout << "Podaj pierwszą liczbę: ";
            cin >> a;
            cout << "Podaj drugą liczbę: ";
            cin >> b;

            wynik = dziel(a, b);
            cout << "Wynik: " << a << " / " << b << " = " << wynik << endl;
            break;

        case 2:
            cout << "Podaj liczbę: ";
            cin >> a;

            wynik = pierwiastek(a);
            cout << "Wynik: " << a << " = " << wynik << endl;
            break;

        default:
            throw invalid_argument("Nieprawidłowy wybór!");
        }
    }
    catch (runtime_error& e) {
        cout << "BŁĄD: " << e.what() << endl;
    }
    catch (invalid_argument& e) {
        cout << "BŁĄD: " << e.what() << endl;
    }
    catch (...) {
        cout << "BŁĄD: Wystąpił nieoczekiwany problem!" << endl;
    }

    return 0;
}