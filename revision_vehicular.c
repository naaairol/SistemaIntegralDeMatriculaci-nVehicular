#include <stdio.h> 
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
#include <stdlib.h> 
#include "Revision_Vehicular.h"



void revision_vehicular(Revision *r){
	int entrada_valida;
	char entrada_usuario[10];
	
	// ----- 1. Verificacion del sistema de gases con su reespectivo validador
	do {
		printf("El sistema de emision de gases de su vehiculo es optimo? (1=Si / 0=No): ");

		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		//Validar que la entrada no esté vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente. ");
		}
		//Validar que la entrada sea de un solo carácter y que sea 1 o 0
		else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			// Si es '1', asigna true; si es '0', asigna false
			r->gases = (entrada_usuario[0] == '1');
		}
		// Si no cumple las condiciones anteriores, es una entrada inválida
		else {
			entrada_valida = 0;
			printf("ERROR. Por favor, ingrese solo 1 (Si) o 0 (No).");
		}
		
		if (!entrada_valida) {
			printf("Intente nuevamente.\n");
		}
		
	} while (!entrada_valida);
	system("cls");
	
	// ----- 2. Verificacion del sistema de suspension con su reespectivo validador
	do {
		printf("El sistema de suspension de su vehiculo es optimo? (1=Si / 0=No): ");

		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		//Validar que la entrada no esté vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente. ");
		}
		//Validar que la entrada sea de un solo carácter y que sea 1 o 0
		else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			// Si es '1', asigna true; si es '0', asigna false
			r->suspension = (entrada_usuario[0] == '1');
		}
		// Si no cumple las condiciones anteriores, es una entrada inválida
		else {
			entrada_valida = 0;
			printf("ERROR. Por favor, ingrese solo 1 (Si) o 0 (No).");
		}
		
		if (!entrada_valida) {
			printf("Intente nuevamente.\n");
		}
		
	} while (!entrada_valida);
	system("cls");
	
	// ----- 3. del sistema de frenos con su reespectivo validador
	do {
		printf("El sistema de frenos de su vehiculo es optimo? (1=Si / 0=No): ");

		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		//Validar que la entrada no esté vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente. ");
		}
		//Validar que la entrada sea de un solo carácter y que sea 1 o 0
		else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			// Si es '1', asigna true; si es '0', asigna false
			r->frenos = (entrada_usuario[0] == '1');
		}
		// Si no cumple las condiciones anteriores, es una entrada inválida
		else {
			entrada_valida = 0;
			printf("ERROR. Por favor, ingrese solo 1 (Si) o 0 (No).");
		}
		
		if (!entrada_valida) {
			printf("Intente nuevamente.\n");
		}
		
	} while (!entrada_valida);
	system("cls");
	
	
	// ----- 4. Verificacion del sistema de luces con su reespectivo validador
	do {
		printf("El sistema de luces de su vehiculo es optimo? (1=Si / 0=No): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		//Validar que la entrada no esté vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR. No puede dejar este espacio vacio. Intente nuevamente. ");
		}
		//Validar que la entrada sea de un solo carácter y que sea 1 o 0
		else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			// Si es '1', asigna true; si es '0', asigna false
			r->luces = (entrada_usuario[0] == '1');
		}
		// Si no cumple las condiciones anteriores, es una entrada inválida
		else {
			entrada_valida = 0;
			printf("ERROR. Por favor, ingrese solo 1 (Si) o 0 (No).");
		}
		
		if (!entrada_valida) {
			printf("Intente nuevamente.\n");
		}
		
	} while (!entrada_valida);
	system("cls");
}
