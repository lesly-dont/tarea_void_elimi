// TAREA VOID "ELIMINACION"	
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void abrir();
void ingresar();
void buscar_indice();
void modificar();
void buscar_codigo();
void eliminar();
main (){
	abrir();
	ingresar();
	buscar_indice();
	modificar();
	buscar_codigo();
	eliminar();
}
void abrir(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");;
	}
	Estudiante estudiante;
	int registro = 0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________________________"<<endl;
	cout<<" id  "<<"  Codigo"<<"  Nombres     "<<"Apellidos      "<<"Telefono"<<endl;
	do{
		cout<<"___________________________________________________________"<<endl;
		cout<<registro<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		registro+=1;
	} while (feof(archivo) ==0);
	cout<<endl;
	fclose(archivo);
}
void ingresar(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{	
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese Los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese Los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea Agregar Otro Nombre (s/n):";
		cin>>continuar;
	} while(continuar=='s'||continuar=='S');
	fclose(archivo);
	abrir();
}
void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos = 0;
	cout<<"Que registros dese visualizar (id): ";
	cin>>pos;
	fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombres: "<<estudiante.nombres<<endl;
	cout<<"Apellidos: "<<estudiante.apellidos<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	
}
void modificar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	string nombre,apellido;
	Estudiante estudiante;
	int id = 0;
	cout<<"Que registros dese modificar (id): ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingres Nuevo Codigo: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"Ingres Nuevo Nombres: ";
	getline(cin,nombre);
	strcpy(estudiante.nombres,nombre.c_str());
	cout<<"Ingres Nuevo Apellidos: ";
	getline(cin,apellido);
	strcpy(estudiante.apellidos,apellido.c_str());
	cout<<"Ingres Nuevo Telefono: ";
	cin>>estudiante.telefono;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	abrir();
}
void buscar_codigo(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int	 indice=0,pos=0,cod= 0;
	cout<<"Buscar Codigo:";
	cin>>cod;
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		if (estudiante.codigo ==cod){
			pos = indice;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		indice+=1;
	} while (feof(archivo)==0);
	cout<<"____"<<pos<<"_______"<<endl;
	fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombres: "<<estudiante.nombres<<endl;
	cout<<"Apellidos: "<<estudiante.apellidos<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	fclose(archivo);	
}
void eliminar(){
    FILE *archivo =fopen(nombe_archivo,"r+b");
    FILE * temporal =fopen(temp, "wb");
    if (archivo==NULL || temporal == NULL){
    	cout<<"EL ARCHIVO NO EXISTE."<<endl;
	}
    cout<<"Ingrese codigo:";
    int id;
    cin>>id;
    char a;
    cout<<"Desea continuar con la eliminacion?"<<endl;
    fflush(stdin);
    cin>>a;
    if (a == 'S' || a == 's'){
    	Estudiante estudiante;
    	fread(&estudiante, sizeof(Estudiante),1, archivo);
        while(!feof(archivo))
	    {
	        if (estudiante.codigo != id){
	        	fwrite(&estudiante, sizeof(Estudiante), 1,archivo);
	        	fwrite(&estudiante, sizeof(Estudiante), 1, temporal);
			}
	    }
	}
	cout<<"Estudiante eliminado"<<endl;
	fclose(archivo);
	fclose(temporal);
	remove("archivo.dat");
	rename("temporal.dat", "archivo.dat");
	abrir_estudiante();
	

}
