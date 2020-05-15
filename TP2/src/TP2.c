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
	Employee arrayEmp[EMPLEADOS_LEN];
	int option;
	int indiceAuxiliar;
	int idEmpleado =0;
	int auxiliarId;
	int auxOrder;
	float promedioSalarios;
	int sumaAuxiliar;
	int i;


	if(emp_initEmployees(arrayEmp, EMPLEADOS_LEN)==0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	emp_addEmployeesForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "Roberto", "Ferrero", 15.700, 1, 0);
	emp_addEmployeesForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "Macarena", "Ferrero", 17.700, 2, 1);
	emp_addEmployeesForzada(arrayEmp, EMPLEADOS_LEN, &idEmpleado, "Silvia", "Dutra", 13.900, 3, 2);



	do
	{
		if(!utn_getNumero(&option, "1.Alta emplado\n2.Modificar empleado\n3.Baja empleado\n4.Informar\n5.Salir\n", "Opción inválida\n", 1, 5, 2))
		{
			switch(option)
			{
			case 1:
				indiceAuxiliar = emp_getEmptyIndex(arrayEmp, EMPLEADOS_LEN);
				if(indiceAuxiliar >=0)
				{
					if(!emp_addEmployees(arrayEmp, EMPLEADOS_LEN, indiceAuxiliar, &idEmpleado))
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

					if(arrayEmp[i].isEmpty ==0)
					{
						for(i=0;i<EMPLEADOS_LEN;i++)
						{

						emp_printEmployees(arrayEmp, EMPLEADOS_LEN);
						if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea modificar\n", "ID incorrecto\n", 0, 10000, 2))
						{
							indiceAuxiliar = emp_findEmployeeById(arrayEmp, EMPLEADOS_LEN, auxiliarId);
							if(indiceAuxiliar>= 0 && emp_modificarArray(arrayEmp, EMPLEADOS_LEN, indiceAuxiliar)==0)
							{
								printf("Mofificacion realizada con exito\n\n");
							}
							else
							{
								printf("ID no encontrado\n\n");
							}
						}
						}
					}
					else
					{
						printf("\nNo hay clientes cargados\n");
					}

				break;
			case 3:
				if(arrayEmp[i].isEmpty ==0)
				{
					for(i=0;i<EMPLEADOS_LEN;i++)
					{
					emp_printEmployees(arrayEmp, EMPLEADOS_LEN);
					if(!utn_getNumero(&auxiliarId, "Ingrese el ID que desea eliminar\n", "ID incorrecto\n", 0, 10000, 2))
					{
						indiceAuxiliar = emp_findEmployeeById(arrayEmp, EMPLEADOS_LEN, auxiliarId);
						if(indiceAuxiliar>= 0 && emp_removeEmployee(arrayEmp, EMPLEADOS_LEN, auxiliarId)==0)
						{
							printf("Eliminación realizada con exito\n\n");
						}
						else
						{
							printf("ID no encontrado\n\n");
						}
					}
					}
				}
				else
				{
					printf("\nNo hay clientes cargados\n");
				}
				break;
			case 4:
				if(arrayEmp[i].isEmpty ==0)
				{
					for(i=0;i<EMPLEADOS_LEN;i++)
					{

					if(!utn_getNumero(&auxOrder, "Desea imprimir:\n0.Forma Ascendente\n1.Forma descendente\n", "Opcion incorrecta\n", 0, 1, 2))
					{
					emp_sortEmployees(arrayEmp, EMPLEADOS_LEN, auxOrder);
					printf("\n\nListado por APELLIDO Y SECTOR\n\n");
					emp_printEmployees(arrayEmp, EMPLEADOS_LEN);
					}
					sumaAuxiliar = emp_promediarSalarios(arrayEmp, EMPLEADOS_LEN, &promedioSalarios);
					printf("\nLa suma total de los salarios es %d y el promedio es %.2f\n", sumaAuxiliar, promedioSalarios);
					printf("\nLos empleados que igual o superan el promedio son:\n");
					emp_imprimirEmpleadosSuperanPromedio(arrayEmp, EMPLEADOS_LEN);
					break;
					}
					}
				else
				{
					printf("\nNo hay clientes cargados\n");
				}
			}
		}
	}while(option != 5);




	return EXIT_SUCCESS;
}
