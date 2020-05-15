/*
 * Empleado.c
 *
 *  Created on: May 05, 2020
 *      Author: Macarena
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "utn.h"



/**
 * \brief Imprime el array de empleados
 * \param list Array de empleados a ser impreso
 * \param length Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_printEmployees(Employee* list,int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		respuesta = 0;
		for(i=0;i<length;i++)
		{
			if(list[i].isEmpty != 1)
			{
				printf("Id: %8d- %8s - %8s - Salario: %8.2f Sector: %8d\n",	list[i].id,
																		list[i].name,
																		list[i].lastName,
																		list[i].salary,
																		list[i].sector);
			}
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param list Array de empleados a ser inicializado
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_initEmployees(Employee* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta Forzada a un empleado
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Id a ser actualizada
 * \param name Nombre a ser asignado al empleado
 * \param lastName Apellido a ser asignado al empleado
 * \param salary Salario a ser asignado al empleado
 * \param sector Sector a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice)
{
	int respuesta = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && id != NULL && name != NULL && lastName != NULL && salary >= 0 && sector >=0 && indice >=0)
	{
			strncpy(bufferEmployee.name,name,NAME_LEN);
			strncpy(bufferEmployee.lastName,lastName,LASTNAME_LEN);
			respuesta = 0;
			bufferEmployee.salary = salary;
			bufferEmployee.sector = sector;
			bufferEmployee.isEmpty = 0;
			bufferEmployee.id = *id;
			list[indice] = bufferEmployee;
			(*id)++;
	}
	return respuesta;
}


/**
 * \brief Da de alta a un empleado
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Puntero Id a dar de alta
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */


int emp_addEmployees(Employee* list,int len, int indice, int* id)
{
	int respuesta = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmployee.lastName,LASTNAME_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nSalario?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"Ingrese sector\n","Sector incorrecto\n",0,100,2)==0)
		{
			respuesta = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[indice] = bufferEmployee;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Employee* list,int len, int indice)
{
	int respuesta = -1;
	Employee auxiliar;
	int opcion;
	if(list != NULL && len > 0 && indice < len)
	{
	do
	{
		if(!utn_getNumero(&opcion, "\nIngrese el valor que desea modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n", "Opcion incorrecta\n", 1, 5, 2))
		{
			switch(opcion)
			{
			case 1:
				utn_getNombre(auxiliar.name, NAME_LEN, "Ingrese nombre empleado:\n", "Valor inválido\n", 2);
				strncpy(list[indice].name,auxiliar.name, NAME_LEN);
				printf("El nombre se modificó correctamente\n");
				break;
			case 2:
				utn_getDescripcion(auxiliar.lastName, LASTNAME_LEN, "Ingrese Apellido:\n", "Valor inválido\n", 2);
				strncpy(list[indice].lastName,auxiliar.lastName, LASTNAME_LEN);
				printf("El apellido se modificó correctamente\n");
				break;
			case 3:
				utn_getNumeroFlotante(&auxiliar.salary, "Ingrese salario:\n", "Valor inválido\n", 0, 100000, 2);
				list[indice].salary = auxiliar.salary;
				printf("El salario se modificó correctamente\n");
				break;
			case 4:
				utn_getNumero(&auxiliar.sector, "Ingrese sector:\n", "Valor inválido\n", 0, 10, 2);
				list[indice].sector = auxiliar.sector;
				printf("El sector se modificó correctamente\n");
				break;
			}
			respuesta = 0;
			list[indice].isEmpty = 0;

		}
	}while(opcion !=5);

	}

	return respuesta;
}
/**
 * \brief Elimina una posicion del array
 * \param list Array de empleados a ser modificado
 * \param len Limite del array de empleados
 * \param id id a ser eliminada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_removeEmployee(Employee* list, int len, int id)
{
	int respuesta = -1;
	int auxIndice;
	if(list != NULL && len > 0 && id < len)
	{
		auxIndice = emp_findEmployeeById(list, len, id);
		respuesta = 0;
		list[auxIndice].isEmpty = 1;
	}
	return respuesta;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param list Array de empleados
* \param len int Tamaño del array
* \param id int id del array a encontrar
* \return int Return (-1) si no encuentra el valor buscado sino, retorna el indice donde se encuentra el valor buscado
*
*/
int emp_findEmployeeById(Employee* list, int len, int id)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].id==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}



/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Employee* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de empleados por apellido y sector
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * 'param order indica 1 para ordenar ascendente o 0 para ordenar desendente
 * \return Retorna 0 si pudo o -1 (ERROR)
 *
 */
int emp_sortEmployees(Employee* list, int len, int order)
{
	int respuesta = -1;
	int i;
	int flagSwap;
	Employee auxiliar;
	int auxiliarCmp;
	if(list != NULL && len > 0 && (order == 0 || order == 1))
	{
		respuesta = 0;
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if(	 (auxiliarCmp > 0 && order == 1) ||
					(auxiliarCmp == 0 && list[i].sector < list[i+1].sector && order == 1) )
				{
					flagSwap = 1;


					auxiliar = list[i];
					list[i] = list[i+1];
					list[i+1]= auxiliar;
				}
				if(	 (auxiliarCmp < 0 && order == 0) ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector && order == 0) )
				{
					flagSwap = 1;
					auxiliar = list[i+1];
					list[i+1] = list[i];
					list[i]= auxiliar;
				}
			}
			len--;
		}while(flagSwap);
	}
	return respuesta;
}



/** \brief Suma todos los salarios y devuelve el promedio
* \param list Array de empleados
* \param len int Tamaño del array
* \param promedioSalario Puntero donde será guardado el promedio
* \return int Return (-1) ERROR, sino la suma de los salarios
*
*/
int emp_promediarSalarios(Employee* list, int len, float* promedioSalario)
{
    int retorno=-1;
    int i;
    float sumaSalarios=0;
    int contador=0;
    float AuxSalarios;
    if(list!= NULL && len>=0 && promedioSalario != NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
            	sumaSalarios = sumaSalarios + list[i].salary;
                contador++;
            }
        }
        AuxSalarios = sumaSalarios / contador;
        retorno = sumaSalarios;
        *promedioSalario = AuxSalarios;
    }
    return retorno;
}



/** \brief Imprime los empleados que sumperan el salario promedio
* \param list Array de empleados
* \param len int Tamaño del array
* \return int Return (-1) ERROR, o 0 si salió bien
*
*/
int emp_imprimirEmpleadosSuperanPromedio(Employee* list, int len)
{
    int retorno=-1;
    int i;
    float auxPromedio;
    if(list != NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
        	emp_promediarSalarios(list, len, &auxPromedio);
            if(list[i].isEmpty==0 && list[i].salary >= auxPromedio)
            {
            	printf("Id: %8d- %8s - %8s - Salario: %8.2f Sector: %8d\n",	list[i].id,
																			list[i].name,
																			list[i].lastName,
																			list[i].salary,
																			list[i].sector);
            	retorno =0;
            }
        }
    }
    return retorno;
}


