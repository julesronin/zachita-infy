#include <iostream>
#include <cmath>

using namespace std;

long long ab(long long q, long long n, long long p)
{
    long long num;
    num = pow(q,n);
    num = num % p;
    return num;
}

int main()
{
    long long q, p, a, b, A, B;
    setlocale(LC_ALL, "Rus");
    cout << "Введите зачения двух открытых ключей: \n";
    cout << "q = ";
    cin >> q;
    cout << "p = ";
    cin >> p;
    cout << "Секретный ключ Алисы: \n";
    cin >> a;
    cout << "Секретный ключ Боба: \n";
    cin >> b;
    cout << "Боб и Алиса открыто передают полученные результаты после вычислений: \n";
    A = ab(q, a, p);
    B = ab(q, b, p);
    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    long long A1 = ab(B, a, p);
    long long B1 = ab(A, b, p);
    if (A1 == B1)
    {
        cout << "Общий секретный ключ: " << A1 << " \n";
    }
}