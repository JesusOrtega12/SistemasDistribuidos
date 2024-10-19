/* Archivo calculadora.x */
struct entradas{
	double x;
	double y;
};
program CALCULADORA_PROG{
 version CAL_VERS{
 double SUMA(entradas) = 1;
 double RESTA(entradas) = 2;
 double MULTIPLICACION(entradas) = 3;
 double DIVISION(entradas) = 4;
} = 1;
} = 0x31111111;
