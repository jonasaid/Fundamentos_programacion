char* inicializarNuevaCadena (char* vectorC){
    char *cadena;
    cadena = (char *) malloc(sizeof(char) * (strlen(vectorC)));
    return cadena;
}

int main(){
    char* valorUsuario[255];
    inicializarNuevaCadena(valorUsuario);
    return 0;
}