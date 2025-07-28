#ifndef LOGIN_H
#define LOGIN_H

// Funci�n para verificar usuario y contrase�a en el archivo
int verificar_credenciales(const char *usuario, const char *clave);

// Funci�n para registrar un nuevo usuario
int registrar_usuario(const char *usuario, const char *clave);

// Funci�n para verificar si un usuario ya existe
int usuario_existe(const char *usuario);

// Funcion para detectar espacios
bool contiene_espacios(const char *s);

#endif
