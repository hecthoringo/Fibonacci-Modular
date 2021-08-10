/**
 * @file fibonacci.cpp
 * @author Hector Valencia (contacto@hecthoringo.com)
 * @website https://www.hecthoringo.com
 * @brief Escribe un programa que dados dos enteros n y M encuentre *Fn***mod***M*
 *        LIMITES   0  <= n <= 1000000000 1 <= m <= 200000
 *        ENTRADA   Los dos enteros n y M separados por un espacio(y en ese órden)
 *                  Línea 1: 9 20
 *        SALIDA    Un solo entero representando *Fn***mod***M*
 *                  Línea 1: 14
 *
 * @version 1.0
 * @date
 * @copyright hecthoringo
 * 
 */

#include <iostream>

/**
 * @brief Get the periodo pisano object
 * 
 * @param m 
 * @return long long 
 */

long long get_periodo_pisano(long long m) {
	int i;
    long long a=0, b=1, c=a+b;
    for (i=0;i<m*m;i++) {
        c = (a + b)%m;
        a = b;
        b = c;
        if (a==0 && b==1) {
		return i+1;
		}
    }
    return -1;
}

/**
 * @brief Calculate the fibonacci sequence
 * 
 * @param n 
 * @param m 
 * @return long long 
 */

long long fibonacci_sequence(long long n, long long m) {
    long long remainder = n%get_periodo_pisano(m);
    long long first=0;
    long long second=1;

    long long res=remainder;

    for (int i=1;i<remainder;i++) {
        res = (first+second)%m;
        first=second;
        second=res;
    }
    return res%m;
}

/**
 * @brief 
 * 
 * @param void
 * @return int 
 */

int main(void) {
    long long n,m;
    std::cin >> n >> m;
    std::cout << fibonacci_sequence(n, m) << '\n';
    return 0;
}
