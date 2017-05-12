#ifndef MICADENACLASICA_H
#define MICADENACLASICA_H

int longitud_cadena(const char *cadena);
bool palindromo_rec (const char *cad);
int compara_cadenas(const char *cad1, const char *cad2);
char copiar_cadena(char *cad1, const char *cad2);
char encadenar_cadena(char *cad1, const char *cad2);
char subcadena(char *cad1, const char *cad2, int inicio, int longitud);
void invertir_cadena(char *cad1, const char *cad2);
void vaciar_cadenas(char *cad1, char *cad2);

#endif
