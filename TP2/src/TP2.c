/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : TP2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "Employee.h"

#define EMPLEADOS_LEN 100


int main(void) {
	Employee Array[EMPLEADOS_LEN];
	int option;
	int indiceAuxiliar;
	int idEmpleado =0;
	int auxiliarId;
	int auxOrder;
	float promedioSalarios;
	int sumaAuxiliar;

	if(emp_initEmployees(Array, EMPLEADOS_LEN)==0)
	{
		printf("Array inicializado correctamente. \n\n");
	}


	emp_addEmployeesForzada(Array, EMPLEADOS_LEN,&idEmpleado, "Roberto", "Ferrero", 10, 1, 0);
	emp_addEmployeesForzada(Array, EMPLEADOS_LEN,&idEmpleado, "Roberto", "Ferrero", 20, 2, 1);
	emp_addEmployeesForzada(Array, EMPLEADOS_LEN,&idEmpleado, "Macarena", "Ferrero", 30, 3, 2);


	do
	{
		if(!utn_getNumero(&option, "1.Alta emplado\n2.Modificar empleado\n3.Baja empleado\n4.Informar\n5.Salir\n", "Opción inválida\n", 1, 5, 2))
		{
			switch(option)
			{
			case 1:
				indiceAuxiliar = emp_getEmptyIndex(Array, EMPLEADOS_LEN);
				if(indiceAuxiliar >=0)
				{
					if(!emp_addEmployees(Array, EMPLEADOS_LEN, indiceAuxiliar, &idEmpleado))
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				emp_printEmployees(Array, EMPLEADOS_LEN);
				if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea modificar\n", "ID incorrecto\n", 0, 10000, 2))
				{
					indiceAuxiliar = emp_findEmployeeById(Array, EMPLEADOS_LEN, auxiliarId);
					if(indiceAuxiliar>= 0 && emp_modificarArray(Array, EMPLEADOS_LEN, indiceAuxiliar)==0)
					{
						printf("Mofificacion realizada con exito\n\n");
					}
					else
					{
						printf("ID no encontrado\n\n");
					}
				}
				break;
			case 3:
				emp_printEmployees(Array, EMPLEADOS_LEN);
				if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea eliminar\n", "ID incorrecto\n", 0, 10000, 2))
				{
					indiceAuxiliar = emp_findEmployeeById(Array, EMPLEADOS_LEN, auxiliarId);
					if(indiceAuxiliar>= 0 && emp_removeEmployee(Array, EMPLEADOS_LEN, auxiliarId)==0)
					{
						printf("Eliminación realizada con exito\n\n");
					}
					else
					{
						printf("ID no encontrado\n\n");
					}
				}
				break;
			case 4:
				if(!utn_getNumero(&auxOrder, "Desea imprimir:\n0.Forma Ascendente\n1.Forma descendente\n", "Opcion incorrecta\n", 0, 1, 2))
				{
				emp_sortEmployees(Array, EMPLEADOS_LEN, auxOrder);
				printf("\n\nListado por APELLIDO Y SECTOR\n\n");
				emp_printEmployees(Array, EMPLEADOS_LEN);
				}
				sumaAuxiliar = emp_promediarSalarios(Array, EMPLEADOS_LEN, &promedioSalarios);
				printf("\nLa suma total de los salarios es %d y el promedio es %.2f\n", sumaAuxiliar, promedioSalarios);
				printf("\nLos empleados que igual o superan el promedio son:\n");
				emp_imprimirEmpleadosSuperanPromedio(Array, EMPLEADOS_LEN);
				break;
			}
		}
	}while(option != 5);




	return EXIT_SUCCESS;
}
