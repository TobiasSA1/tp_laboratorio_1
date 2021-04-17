#ifndef FUNCIONES_H_
#define FUNCIONES_H_



/*
*
*\brief Pide que ingreses un valor y lo valida por si es 0
*\param A, va a ser donde se guarden los numeros que ingrese el usuario
*\return Retorna el valor del numero ingresado
*
*/
float pedirNumero(float A);
/*
*
*\brief Suma dos numeros
*\param A, es un numero a sumar
*\param B, es el otro numero a sumar
*\return Retorna la suma entre ambos
*
*/
float OperacionSuma(float A,float B);
/*
*
*\brief Resta dos numeros
*\param A, es un numero a restar
*\param B, es el otro numero a restar
*\return Retorna la resta entre ambos
*
*/
float OperacionResta(float A,float B);
/*
*
*\brief Divide dos numeros
*\param A, es un numero a multiplicar
*\param B, es el otro numero a multiplicar
*\return Retorna la multiplicacion entre ambos
*
*/
float OperacionMultiplicacion(float A,float B);
/*
*
*\brief Divide dos numeros
*\param A, es el divisor
*\param B, es el dividendo
*\return Retorna la division entre ambos
*
*/
float OperacionDivision(float A,float B);

/*
*
*\brief Toma el valor ingresado por el usuario y realiza un factorial
*\param A, es el numero a realizar dicha operacion
*\return retorna el valor de los factoriales
*
*/
float OperacionFactorial(float num);

/*
*
*\brief Muesta el menu por pantalla y pide una opcion
*\param A, Es el operando A elegido que se muestra siempre
*\param B, Es el operando B elegido que se muestra siempre
*\param
*\return retorna la opcion elegida
*/
int menu(float A,float B);


#endif /* FUNCIONES_H_ */
