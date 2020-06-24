#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int archivoCargado = 0;
    Employee* auxEmployee;
    int auxIndice;
    int contadorAux;
    LinkedList* sublista;
    LinkedList* sublistaII;
    int to;
    int from;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        	utn_getNumero(&option,"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
        						  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
        						  "3. Alta de empleado\n"
        						  "4. Modificar datos de empleado\n"
        						  "5. Baja de empleado\n"
        						  "6. Listar empleados\n"
        						  "7. Ordenar empleados por nombre\n"
        						  "8. Ordenar empleados por ID\n"
        						  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
        						  "10. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
        						  "11. Buscar empleado\n"
        						  "12. Clonar lista\n"
        						  "13. Crear sublista\n"
        						  "14. Corroborar sublista\n"
        						  "15. Filtrar por más de 300 horas trabajadas\n"
        						  "16. El sueldo más alto\n"
        						  "17. Liquidación total mensual\n"
        						  "18. Salir\n",
    							  "Opción inválida\n",
    							  1,18,2);
            switch(option)
            {
                case 1:
                	if(archivoCargado == 0)
                	{
						if(!controller_loadFromText("data.csv",listaEmpleados))
						{
							archivoCargado = 1;
						}
                	}
                	else
                	{
                		printf("Archivo ya cargado\n");
                	}
                    break;
                case 2:
                	if(archivoCargado == 0)
                	{
						controller_loadFromBinary("data.dat",listaEmpleados);
						archivoCargado = 1;
                    }
                	else
					{
						printf("Archivo ya cargado\n");
					}
                    break;
                case 3:
                	controller_addEmployee(listaEmpleados);
                    break;
                case 4:
                	controller_editEmployee(listaEmpleados);
                    break;
                case 5:
                	controller_removeEmployee(listaEmpleados);
                    break;
                case 6:
                	controller_ListEmployee(listaEmpleados);
                    break;
                case 7:
                	controller_sortEmployee(listaEmpleados);
                    break;
                case 8:
                	controller_sortEmployeebyID(listaEmpleados);
                    break;
                case 9:
                	controller_saveAsBinary("data.dat",listaEmpleados);
                    break;
                case 10:
                	controller_saveAsText("data.csv",listaEmpleados);
                	break;
                case 11:
                	utn_getNumero(&to,"Ingrese ID\n","ID incorrecto\n",0,ll_len(listaEmpleados),2);
                	auxEmployee = ll_get(listaEmpleados,to-1);
                	controller_containsElemento(listaEmpleados,auxEmployee);
					auxIndice = ll_indexOf(listaEmpleados,auxEmployee);
					if(auxIndice != -1)
					{
						printf("El empleado se encuentra en el indice %d\n", auxIndice);
						employee_imprimir(auxEmployee);
					}
                	break;
                case 12:
                	if(ll_clone(listaEmpleados) != NULL)
                	{
                		printf("Lista clonada\n");
                		sublista = ll_clone(listaEmpleados);
                		ll_map(sublista,employee_imprimirGral);
                	}
                	break;
                case 13:
                	if(!utn_getNumero(&from,"Ingrese desde donde quiere crear la sublista\n"
                					,"Valor incorecto\n", 0, ll_len(listaEmpleados),2) &&
									!utn_getNumero(&to,"Ingrese hasta donde quiere crear la sublista\n"
									,"Valor incorecto\n", 0, ll_len(listaEmpleados),2))
                	{
						sublistaII = ll_subList(listaEmpleados,from-1,to);
						if(sublistaII != NULL)
						{
						ll_map(sublistaII,employee_imprimirGral);
						contadorAux = ll_count(sublistaII,calcularElementos);
						printf("Sublista creada\n");
						printf("Hay %d empleados seleccionados\n\n",contadorAux);
						}
                	}
                	break;
                case 14:
                	if(ll_containsAll(listaEmpleados,sublistaII)==1)
                	{
                		printf("Los elementos de sublista están contenidos\n\n");
                	}
                	else if(ll_containsAll(listaEmpleados,sublistaII)==0)
                	{
                		printf("Al menos un elemento no está contenido\n");
                	}
                	else
                	{
                		printf("La lista es NULL\n");
                	}
                	break;
                case 15:
                	sublista = ll_filter(listaEmpleados,calcularElementosHsMayoresA);
                	if(sublista != NULL)
                	{
                		ll_map(sublista,employee_imprimirGral);
                		printf("Lista filtrada\n");
                		contadorAux = ll_count(listaEmpleados,calcularElementosHsMayoresA);
                		printf("Hay %d empleados que superan las 300 hs. trabajadas\n",contadorAux);
                	}
                	break;
                case 16:
                	auxIndice = ll_reduce(listaEmpleados,compararSueldoPorValor);
                	ll_map(listaEmpleados,employee_imprimirGral);
                	printf("El mayor sueldo es %d\n",auxIndice);

                	break;
                case 17:
					contadorAux = ll_countAcumulador(listaEmpleados,calcularEmpleadosLiquidacion);
					printf("Liquidacion total mensual: $%d\n\n",contadorAux);
					break;
            }
        }while(option != 18);
    return 0;
}

