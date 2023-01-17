#include <iostream>
#include <vector>

using namespace std;

enum Scheinwert {
    FUENF = 5,
    ZEHN = 10,
    ZWANZIG = 20,
    FUENFZIG = 50,
    HUNDERT = 100,
    ZWEIHUNDERT = 200,
    FUENFHUNDERT = 500
};

int auszahlen(int betrag, vector<Scheinwert >& scheine)
{
    while (betrag > 0) {
        if (betrag >= FUENFHUNDERT) {
            betrag -= FUENFHUNDERT;
            scheine.emplace_back(FUENFHUNDERT);
        }
        else if (betrag >= ZWEIHUNDERT) {
            betrag -= ZWEIHUNDERT;
            scheine.emplace_back(ZWEIHUNDERT);
        }
        else if (betrag >= HUNDERT) {
            betrag -= HUNDERT;
            scheine.emplace_back(HUNDERT);
        }
        else if (betrag >= FUENFZIG) {
            betrag -= FUENFZIG;
            scheine.emplace_back(FUENFZIG);
        }
        else if (betrag >= ZWANZIG) {
            betrag -= ZWANZIG;
            scheine.emplace_back(ZWANZIG);
        }
        else if (betrag >= ZEHN) {
            betrag -= ZEHN;
            scheine.emplace_back(ZEHN);
        }
        else if (betrag >= FUENF) {
            betrag -= FUENF;
            scheine.emplace_back(FUENF);
        }
    }
    return betrag;
}

int main()
{
    int betrag;
    vector<Scheinwert > scheine;

    cout << "Bitte geben Sie den Betrag ein: ";
    cin >> betrag;

    if (betrag % FUENF || betrag > 10000) {
        cout << "Der Betrag muss ein Vielfaches von 5 sein und kann nicht mehr als 10.000 Euro betragen.";
        return 0;
    }

    auszahlen(betrag, scheine);

    for (size_t i = 0; i < scheine.size(); ++i)
    {
        switch (scheine[i])
        {
        case FUENF:
            cout << "Die Banknote 5 Euro wurde ausgegeben" << endl;
            break;
        case ZEHN:
            cout << "Die Banknote 10 Euro wurde ausgegeben" << endl;
            break;
        case ZWANZIG:
            cout << "Die Banknote 20 Euro wurde ausgegeben" << endl;
            break;
        case FUENFZIG:
            cout << "Die Banknote 50 Euro wurde ausgegeben" << endl;
            break;
        case HUNDERT:
            cout << "Die Banknote 100 Euro wurde ausgegeben" << endl;
            break;
        case ZWEIHUNDERT:
            cout << "Die Banknote 200 Euro wurde ausgegeben" << endl;
            break;
        case FUENFHUNDERT:
            cout << "Die Banknote 500 Euro wurde ausgegeben" << endl;
            break;
        default:
            cout << "Ungültige Banknote!" << endl;
            break;
        }
    }

    return 0;
}
