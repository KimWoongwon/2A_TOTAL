#include <iostream>
using namespace std;

template <typename T1, typename T2>
const T2& Max(const T1& a, const T2& b)
{
    cout << "Max(const T& a, const T& b) �Ϲ�ȭ ���ø� ���� ���" << endl;
    return a > b ? a : b;
}
template <>
const double& Max(const double& a, const double& b)
{
    return a > b ? a : b;
}


int main(void)
{
    double Char1_MP = 300;
    double Char1_SP = 400.25;
    double MaxValue1 = Max<double, double>(Char1_MP, Char1_SP);
    cout << "MP�� SP �� ���� ū ���� " << MaxValue1 << " �Դϴ�." << endl << endl;

    int Char2_MP = 300;
    double Char2_SP = 400.25;
    double MaxValue2 = Max<int,double>(Char2_MP, Char2_SP);
    cout << "MP�� SP �� ���� ū ���� " << MaxValue2 << " �Դϴ�." << endl << endl;
}
