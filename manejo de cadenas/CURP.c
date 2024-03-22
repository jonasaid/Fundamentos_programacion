#include <stdio.h> /*fgets*/
#include <string.h> /*strlen, strncmp, strcpy, strtok*/
#include <ctype.h>/*toupper, tolower*/


/*Se crea una estructura con typedef y la nombramos como CURP
Dentro de la estructura tenemos 10 apuntadores a caracteres con
memoria estatica (vectores) y uno de tipo char. Todas ellas, nos
ayudaran a trabajar con las funciones que resuleven los problemas
propuestos y por supuesto para crear el CURP*/
typedef struct
{
    char nombreCompleto[255];
    char nombre1[255];
    char apellido1[255];
    char apellido2[255];

    char fechaNacimiento[12];
    char fechaDia[3];
    char fechaMes[3];
    char fechaYear[3];
    char sexo;

    char estado[50];
    char estadoConvertido[3];
} CURP;

/*introducirNombre, no regresa nada, pero recibe una variable de tipo apuntador a CURP 
Se introduce y lee el nombre, se separa y se determina cual es el nombre, primer y segundo apellido
los valores de dichas variables se guardan en los campos correspondientes*/
void introducirNombre(CURP *curp)
{
    printf("\n1. Nombre (nombre1 nombre2 ... apellido1 apellido2): ");
    fgets(curp->nombreCompleto, 256, stdin);

    const char separacion[2] = " ";

    char *tokens[255];
    char *token;
    int numeroTokens = 0;
    token = strtok(curp->nombreCompleto, separacion);
    while (token != NULL)
    {
        tokens[numeroTokens] = token;
        token = strtok(NULL, separacion);
        numeroTokens++;
    }
    strcpy(curp->nombre1, tokens[0]);
    strcpy(curp->apellido1, tokens[numeroTokens - 2]);
    strcpy(curp->apellido2, tokens[numeroTokens - 1]);
    return;
}

/*intoducirFecha, no regresa nada y recibe un parametro de tipo apuntador a CURP
Se introduce y lee la fecha, se secciona por dia mes y año, posteriormente se gaurdan en
los campos correspondientes, a la sepraracion del año todavía se le hacen modificaciones para
que me de los 2 digitos que interesan y se guarda en el campo correspondiente*/
void introducirFecha(CURP *curp)
{
    printf("\n2. Fecha de nacimiento (introduce con el siguiente formato: DD-MM-YYYY: ");
    const char separacion[2] = "-";
    char fecha[12];
    char year[6];
    fgets(fecha, 12, stdin);
    strcpy(curp->fechaDia, strtok(fecha, separacion));
    strcpy(curp->fechaMes, strtok(NULL, separacion));
    strcpy(year, strtok(NULL, separacion));
    curp->fechaYear[0] = year[2];
    curp->fechaYear[1] = year[3];
    curp->fechaYear[2] = '\0';
}

/*introducirSexo, no regresamos nada y recibimos como parametro un apuntador a CURP 
se introduce, lee y guarda el sexo en el campo correspondiente.*/
void introducirSexo(CURP *curp)
{
    printf("\n3. Sexo: (H Hombre, M mujer): ");
    fgets(&(curp->sexo), 3, stdin);
}

/*convertirCadenaMinuscula, recibe un apuntador a caracter y regresa un apuntador a caracter
Se recibe una cadena y la funcion la regresa toda en minusculas.*/
char *convertirCadenaMinuscula(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

 /*introducirEntidadFederativa, regresa un entero, y recibe como parametros un apuntador a CURP
 Se introduce la entidad federativa, si es correcta me regresa la breviacion correspondiente, sino es correcta 
 regresa un -1*/
int introducirEntidadFederativa(CURP *curp)
{
    printf("\n4. Introduce entidad federativa: ");
    fgets(curp->estado, 52, stdin);

    char *entidadFederativaMinusculas;
    entidadFederativaMinusculas = convertirCadenaMinuscula(curp->estado);
    int numeroCaracteres = strlen(entidadFederativaMinusculas);

    if (strncmp(entidadFederativaMinusculas, "aguascalientes\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "AS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "baja california\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "BC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "baja california sur\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "BS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "campeche\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "CC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "coahuila\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "CL\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "colima\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "CM\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "chiapas\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "CS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "chihuahua\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "CH\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "durango\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "DG\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "distrito federal\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "DF\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "guanajuato\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "GT\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "guerrero\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "GR\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "hidalgo\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "HG\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "jalisco\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "JC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "mexico\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "MC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "michoacan\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "MN\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "morelos\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "MS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "nayarit\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "NT\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "nuevo leon\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "NL\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "oaxaca\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "OC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "puebla\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "PL\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "queretaro\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "QT\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "quintana roo\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "QR\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "san luis potosi\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "SP\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "sinaloa\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "SL\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "sonora\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "SR\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "tabasco\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "TC\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "tamaulipas\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "TS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "tlaxcala\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "TL\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "veracruz\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "VZ\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "yucatan\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "YN\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "zacatecas\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "ZS\0");
        return 0;
    }
    else if (strncmp(entidadFederativaMinusculas, "nacido en el extranjero\n", numeroCaracteres) == 0)
    {
        strcpy(curp->estadoConvertido, "NE\0");
        return 0;
    }
    printf("intenta de nuevo: ");
    return -1;
}

/*extraerConsonante, regresa un caracter y recibe un apuntador a caracter y un entero
Me permite saber cual es la n consonante en una cadena y me regresa la consonante, si no existe 
la consonante deseada regresa un espacio.*/
char extraerConsonante(char *cadena, int posicion)
{
    int numeroConsonantes = 1;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        char actual = tolower(cadena[i]);
        if (actual != 'a' && actual != 'e' && actual != 'i' && actual != 'o' && actual != 'u')
        {
            if (numeroConsonantes == posicion)
            {
                return actual;
            }
            numeroConsonantes++;
        }
    }
    return ' ';
}


/*crearCurp, regresa nada y recibe un apuntador a CURP
Imprime todos los elmentos que se requieren para el CURP*/
void crearCurp(CURP *curp)
{
    printf("%c", toupper(curp->apellido1[0]));
    printf("%c", toupper(curp->apellido1[1]));
    printf("%c", toupper(curp->apellido2[0]));
    printf("%c", toupper(curp->nombre1[0]));
    printf("%s", curp->fechaYear);
    printf("%s", curp->fechaMes);
    printf("%s", curp->fechaDia);
    printf("%c", toupper(curp->sexo));
    printf("%s", curp->estadoConvertido);

    char primerLetra = tolower(curp->apellido1[0]);
    if (primerLetra == 'a' || primerLetra == 'e' || primerLetra == 'i' || primerLetra == 'o' || primerLetra == 'u')
    {
        printf("%c", toupper(extraerConsonante(curp->apellido1, 1)));
    }
    else
    {
        printf("%c", toupper(extraerConsonante(curp->apellido1, 2)));
    }

    primerLetra = tolower(curp->apellido2[0]);
    if (primerLetra == 'a' || primerLetra == 'e' || primerLetra == 'i' || primerLetra == 'o' || primerLetra == 'u')
    {
        printf("%c", toupper(extraerConsonante(curp->apellido2, 1)));
    }
    else
    {
        printf("%c", toupper(extraerConsonante(curp->apellido2, 2)));
    }

    primerLetra = tolower(curp->nombre1[0]);
    if (primerLetra == 'a' || primerLetra == 'e' || primerLetra == 'i' || primerLetra == 'o' || primerLetra == 'u')
    {
        printf("%c", toupper(extraerConsonante(curp->nombre1, 1)));
    }
    else
    {
        printf("%c", toupper(extraerConsonante(curp->nombre1, 2)));
    }

    printf("%s", "00");
}

int main()
{
    CURP usuario;
    printf("\n\t\t:::Datos del usuario:::");
    introducirNombre(&usuario);
    introducirFecha(&usuario);
    introducirSexo(&usuario);
    /*Aquí se verifica que la entidad federativa introducida
    haya sido la correcta*/
    int error = 0;
    do {
        error = introducirEntidadFederativa(&usuario);
    } while (error != 0);
    /*Aquí se imprime el CURP*/
    crearCurp(&usuario);

    return 0;
}

