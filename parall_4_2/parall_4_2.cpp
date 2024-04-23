// parall_4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <random>

using namespace std;


int main()
{
    int k, N;
    cout << "Input count point (N): ";
    cin >> N;
    cout << "Input count tread (k): ";
    cin >> k;
    int sum = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);

#pragma omp parallel num_threads(k)  reduction(+:sum)
    {
        int temp = 0;
        int id = omp_get_thread_num();
        for (int i = id + 1; i <= N; i += k) {
            double x = dis(gen); 
            double y = dis(gen);
            if (x * x + y * y <= 1)
                temp++;
        }

#pragma omp critical
        {
            sum += temp;
        } 
    }

    double pi_estimate = 4.0 * sum / N;
    cout << "calculate pi = " << pi_estimate;
    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
