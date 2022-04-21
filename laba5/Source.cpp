#include"Header.h"

void create(vector<ORDER>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << "ORDER # " << 1 + i << endl;
        cout << "расчетный счет плательщика : "; cin >> a[i].PLAT;
        cout << "расчетный счет получателя : "; cin >> a[i].POL;
        cout << "перечисляемая сумма в рублях : "; cin >> a[i].SUMMA;
    }
}

void sort_array(vector<ORDER>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int k = i; k < a.size(); k++) {
            if (a[i].PLAT > a[k].PLAT) {
                ORDER b = a[i];
                a[i] = a[k];
                a[k] = b;
            }
        }
    }
}
void print_array(vector<ORDER>& a) {
    cout << endl << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << "ORDER # " << 1 + i << endl;
        cout << "расчетный счет плательщика : " << a[i].PLAT << endl;
        cout << "расчетный счет получателя : " << a[i].POL << endl;
        cout << "перечисляемая сумма в рублях : " << a[i].SUMMA << endl;
    }
}

bool findPLAT(vector<ORDER>& a, const string& find) {
    double sum = 0;
    bool check = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].PLAT == find) {
            check = true;
            sum += a[i].SUMMA;
        }
    }
    if (check) {
        cout << "сумма, снятая с расчетного счета плательщика : " << sum << endl;
        return true;
    }
    else {
        cout << "такого расчетного счета не существует, попробуйте снова ";
        return false;
    }
}

void function1() {
    int N;
    cout << "количество ORDER : "; cin >> N;
    vector<ORDER> SPISOK(N);
    create(SPISOK);
    sort_array(SPISOK);
    print_array(SPISOK);
    cout << endl << endl;

    while (true) {
        string find;
        cout << "введите номер расчетного счета для получения информации или 0 для выхода : "; cin >> find;
        if (find == "0") break;
        else findPLAT(SPISOK, find);
    }
}

void create2(vector<STATEMENT>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << "студент # " << i + 1 << endl;
        cout << "Введите ФИО : "; cin >> a[i].SURNAME >> a[i].NAME >> a[i].PATR;
        while (true) {
            cout << "Введите результат 3 экзаменов : "; cin >> a[i].grade1 >> a[i].grade2 >> a[i].grade3;
            if (a[i].grade1 >= 0 and a[i].grade1 <= 10 and a[i].grade2 >= 0 and a[i].grade2 <= 10 and
                a[i].grade3 >= 0 and a[i].grade3 <= 10) {
                break;
            }
            else cout << "оценка за экзамен не может быть меньше 0 или больше 10, введите еще раз " << endl;
        }

    }
}

void print_array2(vector<STATEMENT>& a, const double& average) {
    cout << endl;
    cout << "студенты имеющие балл выше среднего по школе : " << endl;
    for (int k = 0; k < a.size(); k++) {
        double average_k = (a[k].grade1 + a[k].grade2 + a[k].grade3) / 3;
        if (average <= average_k) {
            cout << a[k].SURNAME << " " << a[k].NAME << " " << a[k].PATR << " -  средний балл : " << average_k << endl;
        }
        else break;
    }
}


double average_grade(vector<STATEMENT>& a) {
    double average = 0;
    for (int i = 0; i < a.size(); i++) {
        average += a[i].grade1 + a[i].grade2 + a[i].grade3;
    }
    average = average / (a.size() * 3.0);
    return average;
}

void sort2(vector<STATEMENT>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int k = i; k < a.size(); k++) {
            double average_i = (a[i].grade1 + a[i].grade2 + a[i].grade3) / 3;
            double average_k = (a[k].grade1 + a[k].grade2 + a[k].grade3) / 3;
            if (average_i < average_k) {
                STATEMENT s = a[i];
                a[i] = a[k];
                a[k] = s;
            }

        }
    }
}

void print_array3(vector<STATEMENT>& a) {
    cout << endl << endl;
    for (int k = 0; k < a.size(); k++) {
        cout << a[k].SURNAME << " " << a[k].NAME << " " << a[k].PATR << " : " << a[k].grade1 << " " << a[k].grade2 << " " << a[k].grade3 << endl;
    }
}

void function2() {
    int N;
    cout << "введите количество студентов : "; cin >> N;
    vector<STATEMENT> student(N);
    create2(student);
    double average = average_grade(student);
    cout << endl << "средний балл по университету : " << average << endl;
    sort2(student);
    print_array3(student);
    print_array2(student, average);

}