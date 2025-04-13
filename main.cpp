#include <iostream>
using namespace std;

class MyClass {
private:
    // Атрибути
    int a1;
    double a2;
    string a3;

    // Прапорці атрибутів
    bool fa1, fa2, fa3;

    // Прапорці сетерів
    bool fSetA1, fSetA2, fSetA3;

    // Прапорці методів
    bool fm1, fm2, fm3;

    // Метод контролю доступу
    void accessControl() {
        // Метод M1 доступний, якщо задано a2 і a3
        if (fa2 && fa3) fm1 = true;

        // Метод M2 доступний, якщо задано a1 і a3
        if (fa1 && fa3) fm2 = true;

        // Метод M3 доступний, якщо задано a1 і a2
        if (fa1 && fa2) fm3 = true;
    }

public:
    // Конструктор за замовчуванням
    MyClass() {
        // Ініціалізація прапорців
        fa1 = fa2 = fa3 = false;
        fSetA1 = fSetA2 = fSetA3 = true;
        fm1 = fm2 = fm3 = false;
    }

    // Одноразові сеттери
    void setA1(int value) {
        if (fSetA1) {
            a1 = value;
            fa1 = true;
            fSetA1 = false;
            accessControl();
        } else {
            cout << "Сеттер A1 вже використано.\n";
        }
    }

    void setA2(double value) {
        if (fSetA2) {
            a2 = value;
            fa2 = true;
            fSetA2 = false;
            accessControl();
        } else {
            cout << "Сеттер A2 вже використано.\n";
        }
    }

    void setA3(string value) {
        if (fSetA3) {
            a3 = value;
            fa3 = true;
            fSetA3 = false;
            accessControl();
        } else {
            cout << "Сеттер A3 вже використано.\n";
        }
    }

    // Методи
    void m1() {
        if (fm1) {
            cout << "Метод M1 викликано. Значення a2 = " << a2 << ", a3 = " << a3 << endl;
        } else {
            cout << "Метод M1 недоступний.\n";
        }
    }

    void m2() {
        if (fm2) {
            cout << "Метод M2 викликано. Значення a1 = " << a1 << ", a3 = " << a3 << endl;
        } else {
            cout << "Метод M2 недоступний.\n";
        }
    }

    void m3() {
        if (fm3) {
            cout << "Метод M3 викликано. Значення a1 = " << a1 << ", a2 = " << a2 << endl;
        } else {
            cout << "Метод M3 недоступний.\n";
        }
    }

    // Меню доступних методів
    void showAvailableMethods() {
        cout << "\nДоступні методи:\n";
        if (fm1) cout << "1. M1\n";
        if (fm2) cout << "2. M2\n";
        if (fm3) cout << "3. M3\n";
        if (!fm1 && !fm2 && !fm3) cout << "Жодного методу не доступно.\n";
    }
};

// ------------------- main -------------------
int main() {
    MyClass obj;
    int choice;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Встановити A1\n";
        cout << "2. Встановити A2\n";
        cout << "3. Встановити A3\n";
        cout << "4. Показати доступні методи\n";
        cout << "5. Викликати M1\n";
        cout << "6. Викликати M2\n";
        cout << "7. Викликати M3\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Введіть значення для A1 (int): ";
                cin >> val;
                obj.setA1(val);
                break;
            }
            case 2: {
                double val;
                cout << "Введіть значення для A2 (double): ";
                cin >> val;
                obj.setA2(val);
                break;
            }
            case 3: {
                string val;
                cout << "Введіть значення для A3 (string): ";
                cin >> val;
                obj.setA3(val);
                break;
            }
            case 4:
                obj.showAvailableMethods();
                break;
            case 5:
                obj.m1();
                break;
            case 6:
                obj.m2();
                break;
            case 7:
                obj.m3();
                break;
            case 0:
                cout << "Завершення програми.\n";
                return 0;
            default:
                cout << "Невірний вибір.\n";
        }
    }

    return 0;
}
