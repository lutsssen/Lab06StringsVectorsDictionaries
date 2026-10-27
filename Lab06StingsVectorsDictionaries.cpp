/***************************************
*Автор: Луцаев Владислав Николаевич    *
*Строки, векторы, словари              *
*Группа: ПИ-261                        *
*Вариант: 14                           *
***************************************/

#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

int main() {
    char choice;

    cout << "Choose task (A, B, C, D): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Task A
    if (choice == 'A' || choice == 'a') {
        string s;
        getline(cin, s);

        if (s.length() > 200) {
            cout << "INVALID";
            return 0;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                s[i] = '*';
            }
        }

        if (s.length() == 0) {
            cout << "EMPTY";
        }
        else {
            cout << s;
        }
    }

    // Task B
    else if (choice == 'B' || choice == 'b') {
        int n;
        cin >> n;

        if (n < 0 || n > 100) {
            cout << "INVALID";
            return 0;
        }

        int a[100];
        int count = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] < -1000 || a[i] > 1000) {
                cout << "INVALID";
                return 0;
            }
        }

        if (n == 0) {
            cout << "EMPTY";
            return 0;
        }

        int minimum = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] < minimum) {
                minimum = a[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] != minimum) {
                if (count > 0) {
                    cout << " ";
                }
                cout << a[i];
                count++;
            }
        }

        if (count == 0) {
            cout << "EMPTY";
        }
    }

    // Task C
    else if (choice == 'C' || choice == 'c') {
        int n;
        cin >> n;

        if (n < 0 || n > 100) {
            cout << "INVALID";
            return 0;
        }

        map<string, int> values;

        for (int i = 0; i < n; i++) {
            string key;
            int value;

            cin >> key >> value;
            values[key] = value;
        }

        int threshold;
        cin >> threshold;

        map<string, int> result;
        map<string, int>::iterator it;

        for (it = values.begin(); it != values.end(); ++it) {
            if (it->second >= threshold) {
                result[it->first] = it->second;
            }
        }

        if (result.begin() == result.end()) {
            cout << "EMPTY";
        }
        else {
            for (it = result.begin(); it != result.end(); ++it) {
                cout << it->first << " " << it->second << "\n";
            }
        }
    }

    // Task D
    else if (choice == 'D' || choice == 'd') {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (n < 0 || n > 100) {
            cout << "INVALID";
            return 0;
        }

        string clubs[100];
        int counts[100];
        int clubCount = 0;

        for (int i = 0; i < n; i++) {
            string name;
            string club;

            getline(cin, name);
            getline(cin, club);

            if (name == "" || club == "") {
                cout << "INVALID";
                return 0;
            }

            int position = -1;

            for (int j = 0; j < clubCount; j++) {
                if (clubs[j] == club) {
                    position = j;
                    break;
                }
            }

            if (position == -1) {
                clubs[clubCount] = club;
                counts[clubCount] = 1;
                clubCount++;
            }
            else {
                counts[position]++;
            }
        }

        if (clubCount == 0) {
            cout << "EMPTY";
            return 0;
        }

        for (int i = 0; i < clubCount - 1; i++) {
            for (int j = i + 1; j < clubCount; j++) {
                if (counts[j] > counts[i] ||
                    (counts[j] == counts[i] &&
                        clubs[j] < clubs[i])) {

                    int tempCount = counts[i];
                    counts[i] = counts[j];
                    counts[j] = tempCount;

                    string tempClub = clubs[i];
                    clubs[i] = clubs[j];
                    clubs[j] = tempClub;
                }
            }
        }

        for (int i = 0; i < clubCount; i++) {
            cout << clubs[i] << " " << counts[i] << "\n";
        }
    }

    else {
        cout << "INVALID";
    }

    return 0;
}