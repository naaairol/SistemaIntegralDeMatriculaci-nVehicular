#ifndef MATRICULA_H
#define MATRICULA_H
#include "registrar_vehiculos_propietario.h"


typedef struct {
	int tipo;
	int cilindraje;
	int estado;
	int avaluo;
	float valor_matricula;
	float descuento_multas;
	float recargo_multas;
}Matriculas;

//Funcion para registrar la matriculacion y su valor a pagar
float matriculacion_vehicular(Matriculas *m);

//Funcion para generar un comprobante en la pantalla
void generar_comprobante(const Propietario *p, const Vehiculo *v, const Matriculas *m);

//Funcion para generar un comprobante en un archivo .txt
void generar_comprobante_archivo(const Propietario *p, const Vehiculo *v, const Matriculas *m);


#endif
