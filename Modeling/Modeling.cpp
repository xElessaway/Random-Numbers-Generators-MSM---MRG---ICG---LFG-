#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

void msm();
void icg();
void mrg();
void lfg();


void menu();
string pluszero(int number);

int main()
{
    menu();
}
void menu() {
    int Option;
    system("CLS");
    system("color E4");
    cout << " =========================\n";
    cout << "| WELCOME TO RNGs PROGRAM |\n";
    cout << " ===============================================\n";
    cout << "| [1] Inversive Congruentail generator(ICG)     |\n";
    cout << "| [2] Multiple recursive generator(MRG)         |\n";
    cout << "| [3] Lagged Fibonacci generator(LFG)           |\n";
    cout << "| [4] Mid-Square method(MSM)                    |\n";
    cout << " ===============================================\n";
    cout << "| OPTION : ";
    cin >> Option;
    while (Option > 4 || Option < 0) {
        cout << "| Wrong Option, Again: ";
        cin >> Option;
    }
    switch (Option)
    {
    case 1:
        icg();
    case 2:
        mrg();
    case 3:
        lfg();
    case 4:
        msm();
    default:
        break;
    }
}
string pluszero(int number) {
    string sum;
    while (to_string(number).length() < 8) {
        if (to_string(number).length() == 7) {
            sum = "0" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 6) {
            sum = "00" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 5) {
            sum = "000" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 4) {
            sum = "0000" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 3) {
            sum = "00000" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 2) {
            sum = "000000" + to_string(number);
            return sum;
        }
        else if (to_string(number).length() == 1) {
            sum = "0000000" + to_string(number);
            return sum;
        }
    }
}
void msm() {
    int Option, squared_number, squared, new_number, rootsqrt, numbers_of_generators, counter = 1;
    string hold, sliced;
    list<string> generated_list;
    system("CLS");
    cout << " ============================= \n";
    cout << "| Welcome to our MSM Algorithm |\n";
    cout << "| ============================ |\n";
    cout << "| Do you want back to menu ?   |\n| [1] Yes                      |\n| [2] No                       |\n| Option: ";
    cin >> Option;
    while (Option > 2) {
        cout << "| Wrong Option, Enter Wrong Option Please: ";
        cin >> Option;
    }
    if (Option == 1) {
        menu();
    }
    else if (Option == 2) {
        system("CLS");
        cout << " =========================================== \n";
        cout << "|          Enter The Number: ";
        cin >> squared_number;
        cout << "| How many number of generated you want : ";
        cin >> numbers_of_generators;
        squared = pow(squared_number, 2);
        if (to_string(squared).length() < 8) {

            generated_list.push_back(pluszero(squared));
        }
        else {
            generated_list.push_back(to_string(squared));
        }
        for (auto const& i : generated_list) {
            sliced = i.substr(2, 4);
            if (sliced == "0000" || generated_list.size() == numbers_of_generators) {
                break;
            }
            new_number = pow(stoi(sliced), 2);
            hold = to_string(new_number);
            if (hold.length() < 8) {
                generated_list.push_back(pluszero(new_number));
            }
            else {
                generated_list.push_back(hold);
            }
        }
        cout << " =========================================== \n";
        cout << "| #No         Zi          Ui        Zi*Z    |\n";
        for (auto const& i : generated_list) {
            sliced = "0." + i.substr(2, 4);
            rootsqrt = sqrt(stoi(i));
            cout << "| " << counter << "         " << rootsqrt << "       " << sliced << "    " << i << "   |\n";
            ++counter;
        }
        cout << " =========================================== \n";
        cout << " ============================= \n";
        cout << "| Do you want back to menu ?  |\n| [1] Yes                     |\n| [2] No                      |\n| Option: ";
        cin >> Option;
        while (Option > 2) {
            cout << "| Wrong Option, Enter Wrong Option Please: ";
            cin >> Option;
        }
        if (Option == 1) {
            menu();
        }
        else {
            msm();
        }
    }


}

void icg() {
    int Option;
    float sum, a, m, x, generated_numbers, new_number;
    string hold, sliced;
    list<string> generated_list;
    system("CLS");
    cout << " ============================= \n";
    cout << "| Welcome to our ICG Algorithm |\n";
    cout << "| ============================ |\n";
    cout << "| Do you want back to menu ?   |\n| [1] Yes                      |\n| [2] No                       |\n| Option: ";
    cin >> Option;
    while (Option > 2) {
        cout << "| Wrong Option, Enter Wrong Option Please: ";
        cin >> Option;
    }
    if (Option == 1) {
        menu();
    }
    else if (Option == 2) {
        cout << "| Enter A = ";
        cin >> a;
        cout << "| Enter X = ";
        cin >> x;
        while (x == 0) {
            cout << "| Wrong, X cannot be 0 enter again X = ";
            cin >> x;
        }
        cout << "| Enter M = ";
        cin >> m;
        cout << "| How Many numbers you want to generate : ";
        cin >> generated_numbers;
        sum = fmod((a / x), m);
        hold = to_string(sum);
        generated_list.push_back(hold.substr(0, 5));
        cout << " ============================= \n";
        for (auto const& i : generated_list) {
            sliced = i.substr(0, 5);
            sum = fmod((a / stof(sliced)), m);
            hold = to_string(sum);
            generated_list.push_back(hold.substr(0, 5));
            if (generated_list.size() - 1 == generated_numbers) {
                for (auto const& i : generated_list) {
                    cout << "| GENERATED: " << i << "|     Rn:" << stof(i) / m << "\n\n";
                }
                break;
            }
        }
        cout << " ============================= \n";
        cout << "| Do you want back to menu ?  |\n| [1] Yes                     |\n| [2] No                      |\n| Option: ";
        cin >> Option;
        while (Option > 2) {
            cout << "| Wrong Option, Enter Wrong Option Please: ";
            cin >> Option;
        }
        if (Option == 1) {
            menu();
        }
        else {
            icg();
        }
    }
}


void mrg() {
    int Option, number_of_multipliers, numbers_of_generators;
    float a, x, m, sum, mod;
    string hold, sliced;
    vector<string> first_list, second_list;
    system("CLS");
    cout << " ============================= \n";
    cout << "| Welcome to our MRG Algorithm |\n";
    cout << "| ============================ |\n";
    cout << "| Do you want back to menu ?   |\n| [1] Yes                      |\n| [2] No                       |\n| Option: ";
    cin >> Option;
    while (Option > 2) {
        cout << "| Wrong Option, Enter Wrong Option Please: ";
        cin >> Option;
    }
    if (Option == 1) {
        menu();
    }
    else if (Option == 2) {
        cout << "| Enter Number of multipliers : ";
        cin >> number_of_multipliers;
        for (int i = 0; i < number_of_multipliers; i++) {
            cout << "| a" << i + 1 << " = ";
            cin >> a;
            hold = to_string(a);
            first_list.push_back(hold);
        }
        for (int i = 0; i < number_of_multipliers; i++) {
            cout << "| x" << i + 1 << " = ";
            cin >> x;
            hold = to_string(x);
            second_list.push_back(hold);
        }
        cout << "| M : ";
        cin >> m;
        cout << "| How Many numbers you want to generate : ";
        cin >> numbers_of_generators;
        int counter = 0;
        while (counter < numbers_of_generators - 2) {
            sum = (stof(first_list[0]) * stof(second_list[counter])) +
                (stof(first_list[1]) * stof(second_list[counter + 1])) +
                (stof(first_list[2]) * stof(second_list[counter + 2]));
            mod = fmod(sum, m);
            sliced = to_string(mod);
            second_list.push_back(sliced);
            counter++;
        }
        cout << " ============================= \n";
        for (auto const& i : second_list) {
            cout << "| GENERATED : " << stof(i) << "        Rn: " << stof(i) / m << " | \n";
        }
        cout << " ============================= \n";
        cout << "| Do you want back to menu ?  |\n| [1] Yes                     |\n| [2] No                      |\n| Option: ";
        cin >> Option;
        while (Option > 2) {
            cout << "| Wrong Option, Enter Wrong Option Please: ";
            cin >> Option;
        }
        if (Option == 1) {
            menu();
        }
        else {
            mrg();
        }
    }
}
void lfg() {
    int Option, numbers_of_generators, sum, operation;
    float mod, first_number, Second_number, m;
    string hold, sliced;
    vector<string> first_list, second_list;
    system("CLS");
    cout << " ============================= \n";
    cout << "| Welcome to our LFG Algorithm |\n";
    cout << "| ============================ |\n";
    cout << "| Do you want back to menu ?   |\n| [1] Yes                      |\n| [2] No                       |\n| Option: ";
    cin >> Option;
    while (Option > 2) {
        cout << "| Wrong Option, Enter Wrong Option Please: ";
        cin >> Option;
    }
    if (Option == 1) {
        menu();
    }
    else if (Option == 2) {
        cout << "| X0 = ";
        cin >> first_number;
        first_list.push_back(to_string(first_number));
        cout << "| X1 = ";
        cin >> Second_number;
        second_list.push_back(to_string(Second_number));
        cout << "| M = ";
        cin >> m;
        cout << "| How many number of generated you want : ";
        cin >> numbers_of_generators;
        cout << "| Please Select The Operation \n| [1] Addition +\n| [2] Subtract -\n| [3] Multiply *\n| [4] Divide /\n| Option : ";
        cin >> operation;
        while (operation > 4) {
            cout << "| Wrong Operation number, again : ";
            cin >> operation;
        }
        int counter = 0;
        if (operation == 1) {
            while (counter < numbers_of_generators - 1) {
                sum = (stof(second_list[counter]) + stof(first_list[counter]));
                mod = fmod(sum, m);
                second_list.push_back(to_string(mod));
                first_list.push_back(second_list[counter]);
                counter++;
            }
        }
        else if (operation == 2) {
            while (counter < numbers_of_generators - 1) {
                sum = (stof(second_list[counter]) - stof(first_list[counter]));
                mod = fmod(sum, m);
                second_list.push_back(to_string(mod));
                first_list.push_back(second_list[counter]);
                counter++;
            }
        }
        else if (operation == 3) {
            while (counter < numbers_of_generators - 1) {
                sum = (stof(second_list[counter]) * stof(first_list[counter]));
                mod = fmod(sum, m);
                second_list.push_back(to_string(mod));
                first_list.push_back(second_list[counter]);
                counter++;
            }
        }
        else if (operation == 4) {
            while (counter < numbers_of_generators - 1) {
                sum = (stof(second_list[counter]) / stof(first_list[counter]));
                mod = fmod(sum, m);
                second_list.push_back(to_string(mod));
                first_list.push_back(second_list[counter]);
                counter++;
            }
        }
        cout << " ============================ \n";
        for (auto const& i : second_list) {
            cout << "|      GENERATED : " << stof(i) << "       Rn:"<<stof(i)/m<<" | \n";
        }
        cout << " ============================ \n";
        cout << "| Do you want back to menu ?  |\n| [1] Yes                     |\n| [2] No                      |\n| Option: ";
        cin >> Option;
        while (Option > 2) {
            cout << "| Wrong Option, Enter Wrong Option Please: ";
            cin >> Option;
        }
        if (Option == 1) {
            menu();
        }
        else {
            lfg();
        }
    }
}