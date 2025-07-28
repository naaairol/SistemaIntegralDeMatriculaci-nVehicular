#ifndef LOGIN_H
#define LOGIN_H

// Función para verificar usuario y contraseña en el archivo
int verificar_credenciales(const char *usuario, const char *clave);

// Función para registrar un nuevo usuario
int registrar_usuario(const char *usuario, const char *clave);

// Función para verificar si un usuario ya existe
int usuario_existe(const char *usuario);

// Funcion para detectar espacios
bool contiene_espacios(const char *s);

#endif
