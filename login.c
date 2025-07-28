#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Funcion para detectar espacios
bool contiene_espacios(const char *s) {
	return strchr(s, ' ') != NULL;
}

// Función para verificar usuario y contraseña con archivos
int verificar_credenciales(const char *usuario, const char *clave) {
	
	//Variables para verificar la existencia de credenciales en el archivo
	char usuario_archivo[50], clave_archivo[50];
	
	//Abre el archivio de usuarios en modo lectura. Si no lo encuentra, lo indica
	FILE *archivo = fopen("usuarios.txt", "r");
	if (archivo == NULL) {
		printf("ERROR. No se pudo abrir el archivo de usuarios.\n");
		return 0;
	}

	//Verifica las credenciales ingresadas por el usuario
	while (fscanf(archivo, "%49s %49s", usuario_archivo, clave_archivo) == 2) {
		if (strcmp(usuario, usuario_archivo) == 0 && strcmp(clave, clave_archivo) == 0) {
			fclose(archivo);
			return 1; //Credenciales correctas
		}
	}
	
	fclose(archivo);
	return 0; //No se encontró coincidencia, contraseña incorrecta
}


// Función para verificar si un usuario ya existe
int usuario_existe(const char *usuario) {
	
	//Variables para verificar la existencia de credenciales en el archivo
	char usuario_archivo[50], clave_archivo[50];
	
	//Abre el archivio de usuarios en modo lectura. Si no lo encuentra, lo indica
	FILE *archivo = fopen("usuarios.txt", "r");
	if (archivo == NULL) {
		printf("ERROR. No se pudo abrir el archivo de usuarios.\n");
		return 0; 
	}
	
	//Verifica la existencia de las credenciales ingresadas
	while (fscanf(archivo, "%49s %49s", usuario_archivo, clave_archivo) == 2) {
		if (strcmp(usuario_archivo, usuario) == 0) {
			fclose(archivo);
			return 1; // Usuario ya registrado
		}
	}
	
	fclose(archivo);
	return 0; // Usuario no encontrado
}

// Función para registrar un nuevo usuario en el archivo
int registrar_usuario(const char *usuario, const char *clave) {
	
	// Validar espacios en usuario y clave
	if (contiene_espacios(usuario)) {
		printf("ERROR: El nombre de usuario no puede contener espacios.\n");
		system("cls");
		return 0;
	}
	if (contiene_espacios(clave)) {
		printf("ERROR: La clave no puede contener espacios.\n");
		system("cls");
		return 0;
	}
	
	if (usuario_existe(usuario)) {
		return 0; // El usuario ya existe
	}
	
	//Abre el archivio de usuarios en modo de ajuntar. Si no lo encuentra, lo indica y lo crea
	FILE *archivo = fopen("usuarios.txt", "a");
	if (archivo == NULL) {
		printf("ERROR. No se encuentra el archivo de usuarios.\n");
		return 0;
	}
	
	fprintf(archivo, "%s %s\n", usuario, clave);
	fclose(archivo);
	return 1; // Registro exitoso
}
