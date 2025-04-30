#include <iostream>
using namespace std;

class MyClass
{
    // Атрибути
    int id;
    int age;
    double weight;
    string surname_name_patronymic;

    // Прапорці атрибутів
    bool fId, fAge, fWeight, fSNP;

    // Прапорці сетерів
    bool fSetId, fSetAge, fSetWeight, fSetSNP;

    // Прапорці методів
    bool fm1, fm2, fm3;

    // Метод контролю доступу
    void accessControl()
    {
        // Метод M1 доступний, якщо задано всі атрибути
        if (fId && fAge && fWeight && fSNP) fm1 = true;

        // Метод M2 доступний, якщо задано ID, вагу і ПІБ
        if (fId && fWeight && fSNP) fm2 = true;

        // Метод M3 доступний, якщо задано ID і вік
        if (fId && fAge) fm3 = true;
    }

public:
    // Конструктор за замовчуванням
    MyClass()
    {
        // Прапорці атрибутів
        fId = fAge = fWeight = fSNP = false;

        // Прапорці сетерів (true — доступні)
        fSetId = fSetAge = fSetWeight = fSetSNP = true;

        // Прапорці методів
        fm1 = fm2 = fm3 = false;
    }

    // Одноразовий сеттер ID
    void setId(int value)
    {
        if (fSetId)
        {
            id = value;
            fId = true;
            fSetId = false;
            accessControl();
        }
        else
        {
            cout << "Сеттер ID вже використано.\n";
        }
    }

    // Багаторазові сеттери
    void setAge(int value)
    {
        age = value;
        if (fSetAge)
        {
            fAge = true;
            fSetAge = false;
            accessControl();
        }
    }

    void setWeight(double value)
    {
        weight = value;
        if (fSetWeight)
        {
            fWeight = true;
            fSetWeight = false;
            accessControl();
        }
    }

    void setSNP(string value)
    {
        surname_name_patronymic = value;
        if (fSetSNP)
        {
            fSNP = true;
            fSetSNP = false;
            accessControl();
        }
    }

    // Методи
    void m1()
    {
        if (fm1)
        {
            cout << "Метод M1 викликано. ID = " << id
                 << ", Вік = " << age
                 << ", Вага = " << weight
                 << ", ПІБ = " << surname_name_patronymic << endl;
        }
        else
        {
            cout << "Метод M1 недоступний.\n";
        }
    }

    void m2()
    {
        if (fm2)
        {
            cout << "Метод M2 викликано. ID = " << id
                 << ", Вага = " << weight
                 << ", ПІБ = " << surname_name_patronymic << endl;
        }
        else
        {
            cout << "Метод M2 недоступний.\n";
        }
    }

    void m3()
    {
        if (fm3)
        {
            cout << "Метод M3 викликано. ID = " << id
                 << ", Вік = " << age
                 << ", ПІБ = " << surname_name_patronymic << endl;
        }
        else
        {
            cout << "Метод M3 недоступний.\n";
        }
    }

    // Показати доступні методи
    void showAvailableMethods()
    {
        cout << "\nДоступні методи:\n";
        if (fm1) cout << "1. M1\n";
        if (fm2) cout << "2. M2\n";
        if (fm3) cout << "3. M3\n";
        if (!fm1 && !fm2 && !fm3) cout << "Жодного методу не доступно.\n";
    }

    // Показати стан усіх прапорців
    void showFlags()
    {
        cout << "\n--- Стан прапорців ---\n";

        // Прапорці атрибутів
        cout << "Атрибути:\n";
        cout << "fId: " << fId << ", fAge: " << fAge
             << ", fWeight: " << fWeight << ", fSNP: " << fSNP << endl;

        // Прапорці сетерів
        cout << "Сеттери:\n";
        cout << "fSetId: " << fSetId << ", fSetAge: " << fSetAge
             << ", fSetWeight: " << fSetWeight << ", fSetSNP: " << fSetSNP << endl;

        // Прапорці методів
        cout << "Методи:\n";
        cout << "fm1: " << fm1 << ", fm2: " << fm2 << ", fm3: " << fm3 << endl;
    }
};

// ------------------- main -------------------
int main()
{
    MyClass obj;
    int choice;

    while (true)
    {
        cout << "\nМеню:\n";
        cout << "1. Встановити ID\n";
        cout << "2. Встановити вік\n";
        cout << "3. Встановити вагу\n";
        cout << "4. Встановити ПІБ (Прізвище Ім'я По Батькові)\n";
        cout << "5. Показати доступні методи\n";
        cout << "6. Викликати M1\n";
        cout << "7. Викликати M2\n";
        cout << "8. Викликати M3\n";
        cout << "9. Показати стан прапорців\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                int val;
                cout << "Введіть значення для ID: ";
                cin >> val;
                obj.setId(val);
                break;
            }
        case 2:
            {
                int val;
                cout << "Введіть значення для Віку: ";
                cin >> val;
                obj.setAge(val);
                break;
            }
        case 3:
            {
                double val;
                cout << "Введіть значення для Ваги: ";
                cin >> val;
                obj.setWeight(val);
                break;
            }
        case 4:
            {
                string val;
                cout << "Введіть ПІБ: ";
                cin.ignore();
                getline(cin, val);
                obj.setSNP(val);
                break;
            }
        case 5:
            obj.showAvailableMethods();
            break;
        case 6:
            obj.m1();
            break;
        case 7:
            obj.m2();
            break;
        case 8:
            obj.m3();
            break;
        case 9:
            obj.showFlags();
            break;
        case 0:
            cout << "Завершення програми.\n";
            return 0;
        default:
            cout << "Невірний вибір.\n";
        }
    }
}
