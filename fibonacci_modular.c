/**
 * @file fibonacci.c
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

#include <stdio.h>

/**
 * @brief Get the periodo pisano object
 * 
 * @param m 
 * @return long long int 
 */

long long int get_periodo_pisano(long long int m) {
	long long a = 0, b = 1, c = 1, i = 0;
	while(i < (m * m)) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
        i++;
    }
    return -1;
}

/**
 * @brief Calculate the fibonacci sequence
 * 
 * @param n 
 * @param m 
 * @return long long int 
 */

long long int fibonacci_sequence(long long n, long long m) {
    long long int i=1, n1=0, n2=1, fn;
    n = n%get_periodo_pisano(m);
    fn=n;
    while (i<n) {
        fn = (n1+n2)%m;
        n1=n2;
        n2=fn;
        i++;
    }
    return fn%m;
}

/**
 * @brief 
 * 
 * @param void
 * @return int 
 */

int main(void) {
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    printf("%lld",fibonacci_sequence(n,m));
    return 0;
}
