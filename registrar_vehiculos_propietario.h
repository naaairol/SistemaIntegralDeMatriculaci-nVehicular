//Aqui defines las funciones y declaras la struct

#ifndef REGISTRARVEHICULOS_PROPIETARIO_H
#define REGISTRARVEHICULOS_PROPIETARIO_H

typedef struct {
	char nombres[50];
	char apellidos[50];
	char cedula[20];
	char ciudad[30];
}Propietario;

typedef struct {
	char placa[10];
	char marca[15];
	char modelo[15];
	int anio;
}Vehiculo;

//Funcion para el registro de propietario
void registro_propietario(Propietario *p);

//Funcion para el registro de vehiculo
void registro_vehiculo(Vehiculo *v, const Vehiculo vehiculos[], int num_vehiculos);

//Funcion para buscar vehiculos por su placa
int buscar_vehiculo(const Vehiculo v[], int n, const char *placa_buscada);

//Funcion para mostrar el listado de vehiculos matriculados
void mostrar_matriculados(Propietario p[], Vehiculo v[], int num_vehiculos);

#endif
