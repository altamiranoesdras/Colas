#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//Estructura mensajes enviados
typedef struct s1{
	long Id_Mensaje;
	int operacion;
	float operando1;
	float operando2;
	char operador[1];
	int aproximacion;
}Mensaje1;

//Estructura mensajes que se reciben
typedef struct s2
{
	long Id_Mensaje;
	float resultado;
	int operador;
	char Mensaje[10];
} Mensaje2;


int main(){

	int opcion,n;
	int p3;
	float p1,p2;
	key_t Clave1;
	int Id_Cola_Mensajes;
	Mensaje1 Un_Mensaje;
	Mensaje2 respuesta;

	//obtiene clave  para la cola
	Clave1 = ftok ("/bin/ls", 33);
	if (Clave1 == (key_t)-1){
		printf("Error al obtener clave para cola mensajes");
		exit(-1);
	}
    // creamos la cola de mensajes
	Id_Cola_Mensajes = msgget (Clave1, 0600 | IPC_CREAT);
	if (Id_Cola_Mensajes == -1){
		printf("Error al obtener identificador para cola mensajes");
		exit (-1);
	}	
	
	do{
	
		system("clear");
		
		printf("\nUltima operacion: %f %s %f \n",Un_Mensaje.operando1,Un_Mensaje.operador,Un_Mensaje.operando2);			
		
		printf("\nMENU\n");
		printf("-_-_-_-_-_-_-_-_-_-\n");
		printf("1) SUMA \n");
		printf("2) RESTA \n");
		printf("3) MULTIPLICACION \n");
		printf("4) DIVICION \n");
		printf("5) MOSTRAR RESULTADOS \n");
		printf("6) SALIR \n");
		printf("-_-_-_-_-_-_-_-_-_-\n\n");

		printf("elige tu opcion : ");
		scanf("%d",&opcion);
		Un_Mensaje.operacion = opcion;
		
		switch(opcion){

			case 1 :
				system("clear");
				printf(" SUMA \n");
				strcpy (Un_Mensaje.operador, "+");
			break;


			case 2 :
				system("clear");
				printf("RESTA \n");
				strcpy (Un_Mensaje.operador, "-");
			break;


			case 3 :
				system("clear");
				printf("MULTIPLICACIÓN \n");
				strcpy (Un_Mensaje.operador, "*");
			break;


			case 4 :
				system("clear");
				printf("DIVICIÓN \n");
				strcpy (Un_Mensaje.operador, "/");
			break;
			
			
			case 5 :		
				system("clear");
				printf(" VER RESULTADOS \n\n");
				printf(" ingrese el no de resultados que desea ver:  \n");
				scanf("%d",&n);
				
				//msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&respuesta,sizeof(respuesta.resultado) + sizeof(respuesta.Mensaje) +sizeof(respuesta.operador), 2, 0);
				
				int i;
				for(i=0;i<=n;i++){
					printf("No. %d ",i);
					printf(" Mensage: %s ",respuesta.Mensaje);
					printf(" Resultado = %f \n",respuesta.resultado);
					
				}
				
				
				printf("\n\n");
				
			break;

			case 6:
				system("clear");
				p1=0;p2=0;p3=0;
				strcpy (Un_Mensaje.operador, "s");
				
			break;
			
			default:
				system("clear");
				printf("OPCION NO VALIDA");
			
		}
		
		if(opcion!=6){
			printf("ingrese operando 1 : "); scanf("%f",&p1);
			printf("ingrese operando 2 : "); scanf("%f",&p2);
			printf("desea aproximar 1 = si 2 = no  : "); scanf("%d",&p3);
		}
		// se llenan los datos del mensaje
		Un_Mensaje.Id_Mensaje = 1;
		Un_Mensaje.operando1 = p1;
		Un_Mensaje.operando2 = p2;
		Un_Mensaje.aproximacion = p3;
		
		//se envia el mensaje
		msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
		sizeof(Un_Mensaje.Id_Mensaje)+sizeof(Un_Mensaje.operando1)+sizeof(Un_Mensaje.operando2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.operador), 
		IPC_NOWAIT);

	}while(opcion!=6);

}

