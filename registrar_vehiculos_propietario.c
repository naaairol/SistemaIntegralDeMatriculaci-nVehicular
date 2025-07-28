//Aqui desarrollas las funciones
#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
#include "registrar_vehiculos_propietario.h"

//Funcion para registrar propietario 
void registro_propietario(Propietario *p){
	//Variable para verificar si el usuario ingresa datos permitidos
	int entrada_valida;
	
	//Registro de los nombres del propietario con su respectivo validador de entrada
	do{
		printf("Ingrese los nombres del propietario del vehiculo: ");
		fgets(p->nombres, sizeof(p->nombres), stdin);
		p->nombres[strcspn(p->nombres, "\n")] = 0;  // Elimina el salto de línea que deja fgets
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida=1;
		
		//Validar que la entrada de nombre no esté vacía 
		if (strlen(p->nombres) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		} else {
			// Validar que contenga solo letras y espacios
			for (int i = 0; p->nombres[i] != '\0'; i++) {
				// isalpha espera un int, por eso el cast "unsigned char"
				if (!isalpha((unsigned char)p->nombres[i]) && p->nombres[i] != ' ') {
					entrada_valida = 0;
					printf("ERROR. Ingrese solo palabras en este espacio. Intente nuevamente.\n");
					break; // Salir del bucle si se encuentra un caracter inválido
				}
			}
		}
		
		{
			// Validar número de nombres (debe ser exactamente 2)
			int palabras = 0;
			char temp[50];
			strcpy(temp, p->nombres);
			char *tok = strtok(temp, " ");
			while (tok) {
				palabras++;
				tok = strtok(NULL, " ");
			}
			if (palabras != 2) {
				entrada_valida = 0;
				printf("ERROR. Debe ingresar exactamente dos nombres (ej. Juan Carlos). Intente nuevamente.\n");
			}
		}
			
	} while (!entrada_valida);
	system ("cls");
	
	//Registro de los apellidos del propietario con su respectivo validador de entrada
	do{
		printf("Ingrese los apellidos del propietario del vehiculo: ");
		fgets(p->apellidos, sizeof(p->apellidos), stdin);
		p->apellidos[strcspn(p->apellidos, "\n")] = 0;  // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida=1;
	
		//Validar que la entrada de nombre no esté vacía 
		if (strlen(p->apellidos) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		} else {
			// Validar que contenga solo letras y espacios
			for (int i = 0; p->apellidos[i] != '\0'; i++) {
				// isalpha espera un int, por eso el cast "unsigned char"
				if (!isalpha((unsigned char)p->apellidos[i]) && p->apellidos[i] != ' ') {
					entrada_valida = 0;
					printf("ERROR. Ingrese solo palabras en este espacio. Intente nuevamente.\n");
					break; // Salir del bucle for si se encuentra un caracter inválido
				}
			}
		}
		{
			// Validar número de apellidos (debe ser exactamente 2)
			int palabras = 0;
			char temp2[50];
			strcpy(temp2, p->apellidos);
			char *tok2 = strtok(temp2, " ");
			while (tok2) {
				palabras++;
				tok2 = strtok(NULL, " ");
			}
			if (palabras != 2) {
				entrada_valida = 0;
				printf("ERROR. Debe ingresar exactamente dos apellidos (ej. Perez Lopez). Intente nuevamente.\n");
			}
		}
	
	} while (!entrada_valida);
	system ("cls");
	
	//Registro del DNI del usuario con su respectivo validador
	do {
		printf("Ingrese el numero de cedula del propietario: ");
		fgets(p->cedula, sizeof(p->cedula), stdin);
		p->cedula[strcspn(p->cedula, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1;
		
		// Validar que no sea vacía
		if (strlen(p->cedula) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		}
		// Validar longitud exacta de 10 dígitos
		else if (strlen(p->cedula) != 10) {
			entrada_valida = 0;
			printf("ERROR. La cedula debe contener exactamente 10 digitos. Intente nuevamente.\n");
		}
		// Validar que solo contenga dígitos
		else {
			for (int i = 0; p->cedula[i] != '\0'; i++) {
				// isdigit() verifica si el carácter es un dígito (0-9)
				if (!isdigit((unsigned char)p->cedula[i])) {
					entrada_valida = 0;
					printf("ERROR. Este espacio no puede contener caracteres. Intente nuevamente.\n");
					break; // Salir del bucle si se encuentra un carácter no numérico
				}
			}
		}
	} while (!entrada_valida);
	system("cls");
	
	//Registro de la ciudad de residencia del propietario con su respectivo validador
	do {
		printf("Ingrese la ciudad de residencia del propietario: ");
		fgets(p->ciudad, sizeof(p->ciudad), stdin);
		p->ciudad[strcspn(p->ciudad, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1;
		
		// Valida que la entrada de ciudad no este vacia
		if (strlen(p->ciudad) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		} else {
			// Valida que solo contenga letras
			for (int i = 0; p->ciudad[i] != '\0'; i++) {
				if (!isalpha((unsigned char)p->ciudad[i]) && p->ciudad[i] != ' ') {
					entrada_valida = 0;
					printf("ERROR. Este espacio no puede contener numeros. Intente nuevamente.\n");
					break;
				}
			}
		}
	} while (!entrada_valida);
	system("cls");
}
	
//Funcion para registrar vehiculo 
void registro_vehiculo(Vehiculo *v, const Vehiculo vehiculos[], int numVehiculos){
	//Variable para verificar si el usuario ingresa datos permitidos
	int entrada_valida;
	int anio_temporal;
	char buffer_anio[10];
	
	//Registrar la placa dle vehiculo con su respectivo validador.
	do {
		printf("Ingrese la placa del vehiculo a matricular: (ej. PBT/4194): ");
		fgets(v->placa, sizeof(v->placa), stdin);
		v->placa[strcspn(v->placa, "\n")] = 0; // Elimina el salto de línea que deja fgets
		
		// Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		// Validar que no sea vacía
		if (strlen(v->placa) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		}
		// Validar longitud exacta de 8 caracteres (PBT/4194 tiene 8)
		else if (strlen(v->placa) != 8) {
			entrada_valida = 0;
			printf("ERROR. La placa debe contener exactamente 8 caracteres (ej. PBT/4194). Intente nuevamente.\n");
		}
		// Validar formato específico 
		else {
			// Comprobar las primeras 3 letras (deben ser mayúsculas)
			for (int i = 0; i < 3; i++) {
				// isalpha() verifica si es una letra y isupper() verifica si es mayúscula
				if (!isalpha((unsigned char)v->placa[i]) || !isupper((unsigned char)v->placa[i])) {
					entrada_valida = 0;
					printf("ERROR. Los primeros 3 caracteres de la placa deben ser letras MAYUSCULAS. Intente nuevamente.\n");
					break; // Salir del buclesi se encuentra un error
				}
			}
			
			// Si las primeras 3 letras son válidas, verificar el slash
			if (entrada_valida && v->placa[3] != '/') {
				entrada_valida = 0;
				printf("ERROR. Debe utilizar el slash, '/', como separador. Intente nuevamente.\n");
			}
			
			// Si el slash es válido, comprobar los últimos 4 dígitos.
			if (entrada_valida) {
				for (int i = 4; i < 8; i++) {
					// isdigit() verifica si es un dígito (0-9)
					if (!isdigit((unsigned char)v->placa[i])) {
						entrada_valida = 0;
						printf("ERROR: Los ultimos 4 caracteres de la placa deben ser digitos numericos. Intente nuevamente.\n");
						break; // Salir del bucle for si se encuentra un error
					}
				}
			}
		}
		// --- Validación de duplicado ---
		if (entrada_valida &&
			buscar_vehiculo(vehiculos, numVehiculos, v->placa) != -1)
		{
			printf("ERROR. La placa \"%s\" ya está registrada. Intente otra.\n\n",
				   v->placa);
			entrada_valida = 0;
		}
		
		if (!entrada_valida) {
			printf("\n"); // Añadir un salto de línea para separar el error de la siguiente solicitud
		}
	} while (!entrada_valida);
	system("cls");
	
	
	//Registrar la marca del vehiculo con su respectivo validador
	do {
		printf("Ingrese la marca del vehiculo a matricular: ");
		fgets(v->marca, sizeof(v->marca), stdin);
		v->marca[strcspn(v->marca, "\n")] = 0;  // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1;
		
		// Valida que la entrada de ciudad no este vacia
		if (strlen(v->marca) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		} else {
			// Valida que solo contenga letras
			for (int i = 0; v->marca[i] != '\0'; i++) {
				if (!isalpha((unsigned char)v->marca[i]) && v->marca[i] != ' ') {
					entrada_valida = 0;
					printf("ERROR. Este espacio no puede contener numeros. Intente nuevamente.\n");
					break;
				}
			}
		}
	} while (!entrada_valida);
	system("cls");
	
	
	//Registrar el modelo del vehiculo con su respectivo validador
	do {
		printf("Ingrese el modelo del vehiculo a matricular: ");
		fgets(v->modelo, sizeof(v->modelo), stdin);
		v->modelo[strcspn(v->modelo, "\n")] = 0;    // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1;
		
		// Valida que la entrada de ciudad no este vacia
		if (strlen(v->modelo) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		}
	} while (!entrada_valida);
	system("cls");

	//Registar el anio del vehiculo con su respectivo validador
	do {
		printf("Ingrese el anio del vehiculo a matricular: ");
		//Lee la entrada como cadena y almacena en buffer_anio
		fgets(buffer_anio, sizeof(buffer_anio), stdin);
		buffer_anio[strcspn(buffer_anio, "\n")] = 0; // Elimina el salto de línea
		
		// Asumimos que la entrada es válida al principio
		entrada_valida = 1; 
		
		// Valida que la entrada no este vacia
		if (strlen(buffer_anio) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente.\n");
		}
		// Valida que la longitud sea exactamente 4
		else if (strlen(buffer_anio) != 4) {
			entrada_valida = 0;
			printf("ERROR. No puede ingresar anios distintos de 4 digitos. Intente nuevamente.\n");
		}
		// Validar que solo contenga dígitos
		else {
			for (int i = 0; buffer_anio[i] != '\0'; i++) {
				if (!isdigit((unsigned char)buffer_anio[i])) {
					entrada_valida = 0;
					printf("ERROR. Este espacio no puede contener caracteres.Intente nuevamente.\n");
					break; // Salir del bucle si se encuentra un carácter no numérico
				}
			}
			
			//Si la cadena es valida hasta este momento, convertir y validar el rango
			if (entrada_valida) {
				anio_temporal = atoi(buffer_anio); // Convierte la cadena a entero
				
				// Definir los límites del rango, no se pueden matricular vehiculos mayores al anio 2025
				const int ANIO_MINIMO = 1950;
				const int ANIO_MAXIMO = 2025;
				
				// Validar que el año esté dentro del rango especificado
				if (anio_temporal < ANIO_MINIMO || anio_temporal > ANIO_MAXIMO) {
					entrada_valida = 0;
					printf("ERROR. El anio debe estar entre %d y %d. Intente nuevamente.\n", ANIO_MINIMO, ANIO_MAXIMO);
				} else {
					// Tras todo esto, se asigna a la estructura
					v->anio = anio_temporal;
				}
			}
		}
		
		if (!entrada_valida) {
			printf("\n"); // Salto de linea para mejor visivilidad
		}
		
	} while (!entrada_valida); // Repetir mientras la entrada no sea válida
	system("cls");
	system("cls");
}

//Funcion para buscar vehiculo por placa
int buscar_vehiculo(const Vehiculo v[], int n, const char *placa_buscada){
	for (int i = 0; i < n; ++i){
		if (strcmp(v[i].placa, placa_buscada) == 0){
			return i; //Vehiculo encontrado (Devuelve 0 cuando las cadenas son identicas)
		}
	}
	return -1; // No se encontro esa placa
}

//Función para mostrar todos los vehiculos matriculados
void mostrar_matriculados(Propietario p[], Vehiculo v[], int num_vehiculos) {
	
	printf("==== LISTADO DE VEHICULOS MATRICULADOS ====\n");
	if (num_vehiculos==0){
		printf("Todavia no se ha matriculado ningun vehiculo.\n");
	}
	for (int i = 0; i < num_vehiculos; i++) {
		printf("Placa: %s\n", v[i].placa);
		printf("Propietario: %s %s\n", p[i].apellidos, p[i].nombres);
	}
}

