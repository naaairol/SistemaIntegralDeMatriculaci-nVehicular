#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "registrar_vehiculos_propietario.h"
#include "revision_vehicular.h"
#include "matricula.h"
#include "login.h"


//Prototipos
int verificar_credenciales(const char *usuario, const char *clave);
void menu_login(char *usuario, char *clave);
void mostrar_menu(); 
void menu_apertura();
void menu_registro();
void menu_login(char *usuario, char *clave);
void mostrar_matriculados();


//Contador para el registro de vehiculos matriculados (GLOBAL)
int num_vehiculos = 0; 

//Incio del programa
int main(){
	
	//Declaracion de arreglos para cada tipo de estructura utilizada
	Propietario propietarios[100];
	Vehiculo vehiculos[100];
	Revision revisiones[100];
	Matriculas mats[100];
	
	//Declaracion de variables para el login del usuario
	char usuario[50], clave[50];
	
	//Variable para controlar el menu principal y el login
	int opcion, opcion_inicial;
	
	//Variable booleana para login inicializada
	bool salida=false;

	//Apertura y login del usuario
	do {
		system("cls");
		
		//Bienvenida al usuario y login
		menu_apertura();
		scanf("%d", &opcion_inicial);
		getchar();
		
		//Segun seleccione el usuario
		switch (opcion_inicial) {
		case 1: 
			// Iniciar Sesion
			system("cls");
			// Pide usuario y clave
			menu_login(usuario, clave);
			
			// Bucle de validación y verificación
			while (!salida) {
				system("cls");
				
				// 1) Validar que usuario no tenga espacios
				if (contiene_espacios(usuario)) {
					printf("ERROR: El nombre de usuario no puede contener espacios.\n\n");
					menu_login(usuario, clave);
					continue;
				}
				// 2) Validar que clave no tenga espacios
				if (contiene_espacios(clave)) {
					printf("ERROR: La clave no puede contener espacios.\n\n");
					menu_login(usuario, clave);
					continue;
				}
				// 3) Verificar credenciales en el archivo
				if (verificar_credenciales(usuario, clave)) {
					printf("\nAcceso concedido! Presione ENTER para ingresar al sistema...");
					getchar();
					salida = true;  // sale del bucle
				} else {
					system("cls");
					printf("Acceso denegado! Usuario o clave incorrectos.\n\n");
					menu_login(usuario, clave);
				}
			}
			break;
		case 2: 
			//Registrarse
			system("cls");
			menu_registro();
			break;
		case 3: 
			//Salir del sistema
			printf("Gracias por utilizar nuestros servicios.\n");
			printf("Usted esta saliendo del sistema...\n");
			return 0;
		default:
			printf("Opcion invalida. Intente nuevamente...\n");
			getchar();
		}
	} while(opcion_inicial!= 3 && !salida); 
	
	system("cls");
	
	//Bucle principal para la ejecucion de las opciones del sistema
	do {
		mostrar_menu(); // Muestra el menú en pantalla
		
		printf("Ingrese una opcion para continuar: ");
		scanf("%d",&opcion);
		getchar();// Limpia el buffer
		system ("cls");
		
		// Selecciona la acción a realizar según la opción ingresada
		switch (opcion){
		case 1: 
			//Registro de los datos del propietario
			registro_propietario(&propietarios[num_vehiculos]); 
			
			//Registro de los datos del vehiculo
			registro_vehiculo(&vehiculos[num_vehiculos], vehiculos, num_vehiculos);
			
			//Requisitos a cumplir para realizar la matriculacion
			revision_vehicular(&revisiones[num_vehiculos]);
			
			int aprobadas =
				       revisiones[num_vehiculos].gases      +
				       revisiones[num_vehiculos].suspension +
				       revisiones[num_vehiculos].frenos     +
				       revisiones[num_vehiculos].luces;
			
			if (aprobadas >= 4) {
				//En caso de que cumpla con todas las revisiones, se permite matricular
				float total = matriculacion_vehicular(&mats[num_vehiculos]);
				
				if (total > 0) {
					//Muestra el valor a pagar por la matricula
					printf("Valor a pagar por matricula: $%.2f\n", total);
					printf("\nVehiculo matriculado exitosamente.\n");
					printf("Presione ENTER para generar su comprobante...");
					getchar();
					
					//Generacion del comprobante
					generar_comprobante(&propietarios[num_vehiculos], &vehiculos[num_vehiculos], &mats[num_vehiculos]);
					generar_comprobante_archivo(&propietarios[num_vehiculos], &vehiculos[num_vehiculos], &mats[num_vehiculos]);
					
					printf("\nPresione ENTER para regresar al menu...");
					getchar();
					system("cls");
					
					//Aumenta el contador del numero de vehiculos registrados
					++num_vehiculos;
				} else {
					printf("\nPresione ENTER para regresar al menu...");
					getchar();
					system("cls");
				}
			} else {
				//Si no cumple con los 4 requisitos no se permite la matriculación
				printf("No cumple con los requisitos necesarios para matricular el vehiculo.\n");
				printf("\nPresione ENTER para volver al menu principal.");
				getchar();
				system("cls");
			}
			
			break;
		case 2: {
			char placa_buscada[10];
			int entrada_valida = 0;
			
			do {
				system("cls");
				printf("===== BUSCAR VEHICULO =====\n");
				
				// 1) leo la placa (incluye posibles espacios, luego la recorto)
				printf("Ingrese la placa a buscar (ej. PBT/4194): ");
				if (fgets(placa_buscada, sizeof(placa_buscada), stdin) == NULL) {
					printf("Error leyendo la placa.\n");
					continue;
				}
				placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
				
				// 2) validaciones sobre placaBuscada
				entrada_valida = 1;  // hasta ahora todo bien
				
				// 2.1) No vacía
				if (strlen(placa_buscada) == 0) {
					printf("ERROR: No puede dejar este espacio vacío.\n");
					entrada_valida = 0;
				}
				// 2.2) Longitud exacta de 8
				else if (strlen(placa_buscada) != 8) {
					printf("ERROR: La placa debe tener 8 caracteres (ej. PBT/4194).\n");
					entrada_valida = 0;
				}
				// 2.3) Formato: 3 mayúsculas, '/', 4 dígitos
				else {
					// 3 letras mayúsculas
					for (int i = 0; i < 3 && entrada_valida; i++) {
						if (!isalpha((unsigned char)placa_buscada[i]) ||
							!isupper((unsigned char)placa_buscada[i])) {
							printf("ERROR: Carácter %d debe ser letra MAYÚSCULA.\n", i+1);
							entrada_valida = 0;
						}
					}
					// el slash
					if (entrada_valida && placa_buscada[3] != '/') {
						printf("ERROR: Debe usar '/' en la posición 4.\n");
						entrada_valida = 0;
					}
					// 4 dígitos finales
					for (int i = 4; i < 8 && entrada_valida; i++) {
						if (!isdigit((unsigned char)placa_buscada[i])) {
							printf("ERROR: Carácter %d debe ser dígito.\n", i+1);
							entrada_valida = 0;
						}
					}
				}
				
				if (!entrada_valida) {
					printf("Presione ENTER para intentar de nuevo...");
					getchar();  // pausa
				}
			} while (!entrada_valida);
			
			// 3) ya validada, busca el vehículo
			int indice = buscar_vehiculo(vehiculos, num_vehiculos, placa_buscada);
			if (indice != -1) {
				printf("\n==== VEHICULO ENCONTRADO ====\n");
				printf("Placa : %s\n",  vehiculos[indice].placa);
				printf("Marca : %s\n",  vehiculos[indice].marca);
				printf("Modelo: %s\n",  vehiculos[indice].modelo);
				printf("Año   : %d\n",  vehiculos[indice].anio);
				printf("Valor : $%.2f\n\n", mats[indice].valor_matricula);
			} else {
				printf("\nNo existe un vehiculo matriculado con la placa %s\n\n", placa_buscada);
			}
			
			printf("Presione ENTER para regresar al menú...");
			getchar();
			system("cls");
			break;
		}
		case 3:
			
				mostrar_matriculados(propietarios, vehiculos, num_vehiculos);
				printf("\nPresione ENTER para volver al menu principal.");
				getchar();
				system("cls");
				
			break;
		case 4:
			// Finaliza la ejecucion del programa
			printf("Gracias por utilizar nuestros servicios.\n");
			printf("Usted esta saliendo del sistema...\n");
			break; 
		default:
			// Opción inválida, solicita intentar de nuevo
			printf("Opcion invalida. Intente nuevamente...\n");
		}
	} while(opcion != 4); // El menú se repite hasta que el usuario elija salir
	
	return 0;
	
}
	
	// Función para mostrar el menú principal de opciones al usuario
	void mostrar_menu() {
		printf("==== SISTEMA DE MATRICULACION VEHICULAR ====\n");
		printf("1. Registrar y matricular un nuevo vehiculo.\n");
		printf("2. Buscar un vehiculo matriculado.\n");
		printf("3. Mostrar los vehiculos matriculados.\n");
		printf("4. Salir.\n");
		printf("---------------------------------------------\n");
	}
	
	// Función para el inicio de sesión por parte del usuario
	void menu_login(char *usuario, char *clave) {
		// Limpia buffer previo
		fflush(stdin);
		
		printf("===== INICIO DE SESION =====\n");
		printf("Por favor, identifiquese para utilizar el sistema\n");
		
		// Lee usuario completo con posibles espacios
		printf("Usuario: ");
		if (fgets(usuario, 50, stdin) == NULL) return;
		usuario[strcspn(usuario, "\n")] = '\0';  //quita el salto de linea
		
		// Lee clave completo con posibles espacios
		printf("Clave: ");
		if (fgets(clave, 50, stdin) == NULL) return;
		clave[strcspn(clave, "\n")] = '\0';
	}
	
	// Función de apertura del sistema, primera pantalla en mostrarse
	void menu_apertura(){
		printf("===== SISTEMA DE MATRICULACION VEHICULAR =====\n");
		printf("Bienvenido al sistema de matriculacion vehicular integral.\n");
		printf("1. Iniciar sesion.\n");
		printf("2. Registrarse.\n");
		printf("3. Salir\n");
		printf("-----------------------\n");
		printf("Seleccione una opcion: ");
	}

	// Función para registrar un nuevo usuario
	void menu_registro() {
		char usuario[50], clave[50];
		
		printf("===== REGISTRO DE NUEVO USUARIO =====\n");
		
		printf("Ingrese un nombre de usuario: ");
		if (fgets(usuario, 50, stdin) == NULL) return;
		usuario[strcspn(usuario, "\n")] = '\0';  // quita '\n' final
		
		printf("Ingrese una clave: ");
		if (fgets(clave, 50, stdin) == NULL) return;
		clave[strcspn(clave, "\n")] = '\0';
		
		if (registrar_usuario(usuario, clave)) {
			printf("Credenciales registradas exitosamente. Ahora puede iniciar sesion.\n");
		} else {
			printf("ERROR. El usuario ya existe o no se pudo registrar.\n");
		}
		
		printf("Presione ENTER para continuar...");
		getchar();
		getchar();
	}

