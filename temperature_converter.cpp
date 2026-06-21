/*
    Project       : Temperature Converter
    Language      : C++
    Author        : Avinash Kumar
    Description   : A console-based Temperature Converter that converts
                     between Celsius, Fahrenheit, and Kelvin using a
                     simple menu-driven interface.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class TemperatureConverter {
public:
    double celsiusToFahrenheit(double c) {
        return (c * 9.0 / 5.0) + 32;
    }

    double celsiusToKelvin(double c) {
        return c + 273.15;
    }

    double fahrenheitToCelsius(double f) {
        return (f - 32) * 5.0 / 9.0;
    }

    double fahrenheitToKelvin(double f) {
        return fahrenheitToCelsius(f) + 273.15;
    }

    double kelvinToCelsius(double k) {
        return k - 273.15;
    }

    double kelvinToFahrenheit(double k) {
        return celsiusToFahrenheit(kelvinToCelsius(k));
    }
};

void showMenu() {
    cout << "\n========= TEMPERATURE CONVERTER =========\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Celsius to Kelvin\n";
    cout << "3. Fahrenheit to Celsius\n";
    cout << "4. Fahrenheit to Kelvin\n";
    cout << "5. Kelvin to Celsius\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "7. Exit\n";
    cout << "===========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    TemperatureConverter converter;
    int choice;
    double value, result;

    cout << "Welcome to the Temperature Converter (CITS2826)\n";
    cout << fixed << setprecision(2);

    do {
        showMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter temperature value: ";
            cin >> value;
        }

        switch (choice) {
            case 1:
                result = converter.celsiusToFahrenheit(value);
                cout << value << " C = " << result << " F\n";
                break;
            case 2:
                result = converter.celsiusToKelvin(value);
                cout << value << " C = " << result << " K\n";
                break;
            case 3:
                result = converter.fahrenheitToCelsius(value);
                cout << value << " F = " << result << " C\n";
                break;
            case 4:
                result = converter.fahrenheitToKelvin(value);
                cout << value << " F = " << result << " K\n";
                break;
            case 5:
                result = converter.kelvinToCelsius(value);
                cout << value << " K = " << result << " C\n";
                break;
            case 6:
                result = converter.kelvinToFahrenheit(value);
                cout << value << " K = " << result << " F\n";
                break;
            case 7:
                cout << "\nExiting... Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
