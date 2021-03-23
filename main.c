/*******************************************************
* João Gaspar                           23 março 2021
*
* Cálculo das funções trignométricas elementares pelas
* séries de Taylor
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <math.h> /* Biblioteca com funções matemátcas - no presente caso utiliza-se para estudar resultados da função seno */

/***** Protótipos de funções *****/

void factorial(int i, float * fact);
void potencia(float x, int i, float * pot);
float seno(int n, float x);
float cosseno(int n, float x);
float tangente(int n, float x);

/****** Main ******/

int main(){

    int n;
    float x;

    printf("Introduza um angulo (x): ");
    scanf("%f", &x);

    printf("Numero de termos para calcular a serie (n): ");
    scanf("%d", &n);


    printf("\nsen(%.4f, %d) = %.2f", x, n, seno(n, x));

    printf("\n\ncos(%.4f, %d) = %.2f", x, n, cosseno(n, x));

    printf("\n\ntg(%.4f, %d) = %.2f\n", x, n, tangente(n, x));

    return 0;
}

/****** Função para a tangente ******/

float tangente(int n, float x){

    int i;
    float fact = 1.0;
    float pot = 1.0;
    float sinal = -1.0;
    float valor = 0.0;

    for(i=0; n>0; n--, i=i+2){
            
        potencia(x, i, &pot);
        sinal = -sinal;

        valor = valor + sinal * (pot / i);
    }

    return valor;

}

/****** Função para o cosseno ******/

float cosseno(int n, float x){

    int i;
    float fact = 1.0;
    float pot = 1.0;
    float sinal = -1.0;
    float valor = 0.0;

    for(i=0; n>0; n--, i=i+2){

        factorial(i, &fact);
        potencia(x, i, &pot);
        sinal = -sinal;

        valor = valor + sinal * (pot / fact);
    }

    return valor;
}

/****** Função para o seno ******/

float seno(int n, float x){

    int i;
    float fact = 1.0;
    float pot = 1.0;
    float sinal = -1.0;
    float valor = 0.0;

    for(i=1; n>0; n--, i=i+2){

        factorial(i, &fact);
        potencia(x, i, &pot);
        sinal = -sinal;

        valor = valor + sinal * (pot / fact);
    }
    return valor;
}

/****** fatorial de i ******/

void factorial(int i, float * fact){
    *fact = 1;
    if(i==0){
        *fact = 1;
        return;
    }
    while(i > 0){
        *fact = *fact * i;
        i--;
    }
}

/****** potencia de x elevado a i ******/

void potencia(float x, int i, float * pot){
    *pot = 1;
    if(i==0){
        *pot = 1;
        return;
    }
    while(i>0){
        *pot = *pot * x;
        i--;
    }
}
