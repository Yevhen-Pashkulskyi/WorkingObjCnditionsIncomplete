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
        // M1: weight && SNP
        fm1 = (fWeight && fSNP);

        // M2: id && SNP
        fm2 = (fId && fSNP);

        // M3: id && weight
        fm3 = (fId && fWeight);
    }

public:
    // Конструктор за замовчуванням
    MyClass()
    {
        // Ініціалізація прапорців атрибутів
        fId = fAge = fWeight = fSNP = false;

        // Сеттери: id – одноразовий, інші – багаторазові
        fSetId = true;
        fSetAge = fSetWeight = fSetSNP = true;

        // Методи
        fm1 = fm2 = fm3 = false;
    }

    // Одноразовий сеттер
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
        fAge = true;
        accessControl();
    }

    void setWeight(double value)
    {
        weight = value;
        fWeight = true;
        accessControl();
    }

    void setSNP(string value)
    {
        surname_name_patronymic = value;
        fSNP = true;
        accessControl();
    }

    // Методи
    void m1()
    {
        if (fm1)
            cout << "Метод M1 викликано. Вага = " << weight << ", ПІБ = " << surname_name_patronymic << endl;
        else
            cout << "Метод M1 недоступний.\n";
    }

    void m2()
    {
        if (fm2)
            cout << "Метод M2 викликано. ID = " << id << ", ПІБ = " << surname_name_patronymic << endl;
        else
            cout << "Метод M2 недоступний.\n";
    }

    void m3()
    {
        if (fm3)
            cout << "Метод M3 викликано. ID = " << id << ", Вага = " << weight << endl;
        else
            cout << "Метод M3 недоступний.\n";
    }

    // Меню доступних методів
    void showAvailableMethods()
    {
        cout << "\nДоступні методи:\n";
        if (fm1) cout << "1. M1\n";
        if (fm2) cout << "2. M2\n";
        if (fm3) cout << "3. M3\n";
        if (!fm1 && !fm2 && !fm3) cout << "Жодного методу не доступно.\n";
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
        cout << "1. Встановити ID (одноразовий)\n";
        cout << "2. Встановити вік\n";
        cout << "3. Встановити вагу\n";
        cout << "4. Встановити ПІБ (Прізвище Ім'я По Батькові)\n";
        cout << "5. Показати доступні методи\n";
        cout << "6. Викликати M1\n";
        cout << "7. Викликати M2\n";
        cout << "8. Викликати M3\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                int val;
                cout << "Введіть ID: ";
                cin >> val;
                obj.setId(val);
                break;
            }
        case 2:
            {
                int val;
                cout << "Введіть вік: ";
                cin >> val;
                obj.setAge(val);
                break;
            }
        case 3:
            {
                double val;
                cout << "Введіть вагу: ";
                cin >> val;
                obj.setWeight(val);
                break;
            }
        case 4:
            {
                string val;
                cout << "Введіть ПІБ: ";
                cin.ignore(); // для коректного зчитування рядка після cin
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
        case 0:
            cout << "Завершення програми.\n";
            return 0;
        default:
            cout << "Невірний вибір.\n";
        }
    }
}
