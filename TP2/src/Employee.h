#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define NAME_LEN 50
#define LASTNAME_LEN 20

typedef struct
{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int sector;
	int isEmpty;
	int id;
}Employee;

int emp_imprimir(Employee* auxProducto);
int emp_initEmployees(Employee* array,int limite);
int emp_addEmployees(Employee* list,int len, int indice, int* id);
int emp_addEmployeesForzada(Employee* list, int len, int* id, char name[],char lastName[],float salary,int sector, int indice);
int emp_getEmptyIndex(Employee* array,int limite);
int emp_printEmployees(Employee* list,int length);
int emp_findEmployeeById(Employee* list, int len, int id);
int emp_modificarArray(Employee* array,int limite, int indice);
int emp_removeEmployee(Employee* array,int limite, int indice);
int emp_sortEmployees(Employee* list, int len, int order);
int emp_promediarSalarios(Employee* list, int len, float* promedioSalario);
int emp_imprimirEmpleadosSuperanPromedio(Employee* list, int len);


#endif /* EMPLOYEE_H_ */
