#include <stdio.h> 
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
#include <stdlib.h> 
#include "matricula.h"
#include "registrar_vehiculos_propietario.h"

//Función para realizar la matriculación vehicular
float matriculacion_vehicular(Matriculas *m){
	
	//variables para menu
	int opcion;
	char entrada_usuario[5];
	int entrada_valida;
	
	//variables para acumular el valor de matricula
	float valor = 0.0f;
	float descuento = 0.0f;
	float recargo = 0.0f;
	
	// --------- 1. Verificación de revisión vehicular anual --------- //
	do {
		printf("Cumplio con las 3 revisiones anuales? (1=Si / 0=No): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1;
		
		// Validar que no sea vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR: La entrada no puede estar vacia. ");
		} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			opcion = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
		} else {
			entrada_valida = 0;
			printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
		}
		if (!entrada_valida) {
			printf("Intente de nuevo.\n\n");
		}
	} while (!entrada_valida);
	
	if (opcion == 0) { // Si no cumplió las revisiones
		printf("\nNo es posible matricular el vehiculo. No cumple con las revisiones anuales.\n");
		getchar(); // Pausa para que el usuario lea el mensaje
	
		return 0; // Termina la función sin procesar la matrícula
	}
	system("cls");
	
	
	// --------- 2. Tipo de vehiculo --------- //
	do {
		printf("Tipo de vehiculo:\n"
		" 0) Particular\n 1) Publico\n 2) Comercial\n 3) Gubernamental\n> ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0; // Elimina el salto de línea
		
		//Asumiendo que la entrada es válida en principio
		entrada_valida = 1; 
		
		// Validar que no sea vacía
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR. La opcion no puede estar vacia. ");
		}
		// Validar que sea un solo dígito y que esté en el rango 0-3
		else if (strlen(entrada_usuario) == 1 && isdigit((unsigned char)entrada_usuario[0])) {
			opcion = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
			
			if (opcion < 0 || opcion > 3) {
				entrada_valida = 0;
				printf("ERROR. Opcion invalida. ");
			} else {
				m->tipo = opcion; // Asigna la opción validada
			}
		}
		// Si no cumple las condiciones anteriores
		else {
			entrada_valida = 0;
			printf("ERROR. Ingrese un numero del 0 al 3. ");
		}
		
		if (!entrada_valida) {
			printf("Intente nuevamente.\n\n");
		}
		
	} while (!entrada_valida);
	
	//Tarifas dependiendo del tipo de vehiculo 
	switch (m->tipo) {
	case 0: 
		valor += 120.0f; break; // Particular
	case 1: 
		valor += 200.0f; break; // Publico
	case 2: 
		valor += 300.0f; break; // Comercial
	case 3: 
		valor += 0.0f; break;   // Gubernamental
	}
	system("cls");
	
	// --------- 3. Cilindraje --------- //
	do {
		printf("El cilindraje de su vehiculo es mayor o igual a 2000 cm3? (1=Si / 0=No): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
		
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0;
		
		entrada_valida = 1;
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR: La entrada no puede estar vacia. ");
		} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			m->cilindraje = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
		} else {
			entrada_valida = 0;
			printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
		}
		if (!entrada_valida) {
			printf("Intente de nuevo.\n\n");
		}
	} while (!entrada_valida);
	
	if (m->cilindraje == 1) valor += 80.0f; /* recargo directo */
	system("cls");
	
	// --------- 4. Vehículo nuevo --------- //
	do {
		printf("Su Vehiculo es NUEVO? (1=Si / 0=Usado): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);
	
		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0;
		
		entrada_valida = 1;
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR: La entrada no puede estar vacia. ");
		} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			m->estado = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
		} else {
			entrada_valida = 0;
			printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
		}
		if (!entrada_valida) {
			printf("Intente de nuevo.\n\n");
		}
	} while (!entrada_valida);
	
	if (m->estado == 1) valor += 100.0f; // recargo directo
	system("cls");
	
	// --------- 5. Avalúo --------- //
	do {
		printf("El avaluo de su vehiculo es mayor o igual a $10 000? (1=Si / 0=No): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);

		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0;
		
		entrada_valida = 1;
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR: La entrada no puede estar vacia. ");
		} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			m->avaluo = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
		} else {
			entrada_valida = 0;
			printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
		}
		if (!entrada_valida) {
			printf("Intente de nuevo.\n\n");
		}
	} while (!entrada_valida);
	
	if (m->avaluo == 1) valor += 150.0f; /* recargo directo */
	system("cls");
	
	// --------- 6. Multas y descuentos/recargos ---------//
	do {
		printf("¿Tiene multas pendientes? (1=Si / 0=No): ");
		fgets(entrada_usuario, sizeof(entrada_usuario), stdin);

		entrada_usuario[strcspn(entrada_usuario, "\n")] = 0;
		
		entrada_valida = 1;
		if (strlen(entrada_usuario) == 0) {
			entrada_valida = 0;
			printf("ERROR: La entrada no puede estar vacia. ");
		} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
			opcion = atoi(entrada_usuario); // Asigna entrada_usuario a opcion
		} else {
			entrada_valida = 0;
			printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
		}
		if (!entrada_valida) {
			printf("Intente de nuevo.\n\n");
		}
	} while (!entrada_valida);
	
	if (opcion == 1) { // Si tiene multas pendientes
		int retraso_pago; // Variable local para el pago retrasado
		do {
			printf("Pago sus multas despues de la fecha limite? (1=Si / 0=No): ");
			fgets(entrada_usuario, sizeof(entrada_usuario), stdin);

			entrada_usuario[strcspn(entrada_usuario, "\n")] = 0;
			
			entrada_valida = 1; // Reinicia para la nueva validación
			if (strlen(entrada_usuario) == 0) {
				entrada_valida = 0;
				printf("ERROR: La entrada no puede estar vacia. ");
			} else if (strlen(entrada_usuario) == 1 && (entrada_usuario[0] == '1' || entrada_usuario[0] == '0')) {
				retraso_pago = atoi(entrada_usuario);
			} else {
				entrada_valida = 0;
				printf("ERROR: Por favor, ingrese solo 1 (Si) o 0 (No). ");
			}
			if (!entrada_valida) {
				printf("Intente de nuevo.\n\n");
			}
		} while (!entrada_valida);
		
		if (retraso_pago == 1) {
			recargo = valor * 0.10f; // 10% de recargo por pago atrasado
			printf("Se aplico un recargo del 10%% por retraso en el pago de multas.\n");
			getchar(); // Pausa para que el usuario lea el mensaje
		} else {
			descuento = valor * 0.05f; // 5% de descuento por pago puntual
			printf("Se aplico un descuento del 5%% por pago puntual de multas.\n");
			getchar(); // Pausa para que el usuario lea el mensaje
		}
	} else { // Si no tiene multas
		descuento = valor * 0.10f; // 10% de descuento si no tiene multas
		printf("Se aplico un descuento del 10%% por no tener multas pendientes.\n");
		getchar(); // Pausa para que el usuario lea el mensaje
	}
	system("cls");
	
	
	// Valor final de la matricula
	m->descuento_multas = descuento;
	m->recargo_multas = recargo;
	
	valor = valor - descuento + recargo;
	m->valor_matricula = valor;
	
	return valor;
}


//Funcion para generar el comprobante de pago una vez realizada la matriculación vehicular
void generar_comprobante(const Propietario *p, const Vehiculo *v, const Matriculas *m){
	
	printf("\n========== COMPROBANTE DE PAGO ==========\n");
	printf("Propietario:\n");
	printf("  Nombres   : %s\n", p->nombres);
	printf("  Apellidos : %s\n", p->apellidos);
	printf("  Cedula    : %s\n", p->cedula);
	printf("  Ciudad    : %s\n\n", p->ciudad);
	
	printf("Vehiculo:\n");
	printf("  Placa     : %s\n", v->placa);
	printf("  Marca     : %s\n", v->marca);
	printf("  Modelo    : %s\n", v->modelo);
	printf("  Anio      : %d\n\n", v->anio);
	
	printf("Cargos de Matriculacion:\n");
	printf("  Valor Base          : $%.2f\n", m->valor_matricula + m->descuento_multas - m->recargo_multas);
	printf("  Descuento aplicado  : $%.2f\n", m->descuento_multas);
	printf("  Recargo aplicado    : $%.2f\n", m->recargo_multas);
	printf("  Valor final a pagar : $%.2f\n", m->valor_matricula);
	printf("Realice el pago en puntos autorizados con el numero de placa.\n");
	printf("==========================================\n");
}
	

//Función para guardar el comprobante de pago en un archivo txt
void generar_comprobante_archivo(const Propietario *p, const Vehiculo *v, const Matriculas *m) {
	FILE *archivo = fopen("comprobante.txt", "a");
	if (archivo == NULL) {
		printf("Error al crear el archivo comprobante.txt\n");
		return;
	}
	
	fprintf(archivo, "========== COMPROBANTE DE PAGO ==========\n");
	fprintf(archivo, "Propietario:\n");
	fprintf(archivo, "  Nombres   : %s\n", p->nombres);
	fprintf(archivo, "  Apellidos : %s\n", p->apellidos);
	fprintf(archivo, "  Cedula    : %s\n", p->cedula);
	fprintf(archivo, "  Ciudad    : %s\n\n", p->ciudad);
	
	fprintf(archivo, "Vehiculo:\n");
	fprintf(archivo, "  Placa     : %s\n", v->placa);
	fprintf(archivo, "  Marca     : %s\n", v->marca);
	fprintf(archivo, "  Modelo    : %s\n", v->modelo);
	fprintf(archivo, "  Anio      : %d\n\n", v->anio);
	
	fprintf(archivo, "Cargos de Matriculacion:\n");
	fprintf(archivo, "  Valor Base          : $%.2f\n", m->valor_matricula + m->descuento_multas - m->recargo_multas);
	fprintf(archivo, "  Descuento aplicado  : $%.2f\n", m->descuento_multas);
	fprintf(archivo, "  Recargo aplicado    : $%.2f\n", m->recargo_multas);
	fprintf(archivo, "  Valor final a pagar : $%.2f\n", m->valor_matricula);
	fprintf(archivo, "Realice el pago en puntos autorizados con el numero de placa.\n");
	fprintf(archivo, "=========================================\n");
	
	fclose(archivo);
	printf("\nComprobante generado en comprobante.txt\n");
	printf("\n");
}	
