#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>


// estructura enviar mensaje de menu
typedef struct s1
{
	long Id_Mensaje;
	float operador1;
	float operador2;
	int operacion;
	int aproximacion;
	char Mensaje[10];
}Mensaje1;

// estructura recibir mensaje del proceso


typedef struct s2
{
	long Id_Mensaje;
	float resultado;
	int operacion;
	char Mensaje[10];
} Mensaje2;


int main(){

	int opcion,a,n;
	int p3,od;
	float p1,p2;
	key_t Clave1;
	int Id_Cola_Mensajes;
	Mensaje1 Un_Mensaje;
	Mensaje2 respuesta;

	
	do{
	
	//obtiene clave  para la cola
	Clave1 = ftok ("/bin/ls", 33);
	if (Clave1 == (key_t)-1)
	{
		printf("Error al obtener clave para cola mensajes");
		exit(-1);
	}
    // creamos la cola de mensajes
	Id_Cola_Mensajes = msgget (Clave1, 0600 | IPC_CREAT);
	if (Id_Cola_Mensajes == -1)
	{
		printf("Error al obtener identificador para cola mensajes");
		exit (-1);
	}	
		
		
		system("clear");
		printf("   MENU    \n\n");
		printf("1) SUMA \n");
		printf("2) RESTA \n");
		printf("3) MULTIPLICACION \n");
		printf("4) DIVICION \n");
		printf("5) MOSTRAR N CANTIDAD DE RESULTADOS \n");
		printf("6) SALIR \n");
		printf("-_-_-_-_-_-_-_-_-_-\n");
		printf("elige tu opcion : ");
		scanf("%d",&opcion);
		
		switch(opcion){

			case 1 :
			system("clear");
			printf(" SUMA \n");
			printf("ingrese operando 1 : ");scanf("%f",& p1);
			printf("ingrese operando 2 : ");scanf("%f",& p2);
			printf("desea aproximar 1 = si 2 = no  : ");scanf("%d\n\n",& p3);
			printf("operando 1 : %f  , operando 2 : %f , aproximara : %d",p1,p2,p3);			
			// se llenan los datos del mensaje
			Un_Mensaje.Id_Mensaje = 1;
			Un_Mensaje.operacion = opcion;
			Un_Mensaje.operador1 = p1;
			Un_Mensaje.operador2 = p2;
			Un_Mensaje.aproximacion = p3 ;
			strcpy (Un_Mensaje.Mensaje, "suma");
			//se envia el mensaje
			msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.operador1)+sizeof(Un_Mensaje.operador2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.Mensaje)+sizeof(Un_Mensaje.operacion), 
			IPC_NOWAIT);

			
			getchar();
			break;


			case 2 :

			system("clear");
			printf(" RESTA \n");
			printf("ingrese operando 1 : ");scanf("%f",& p1);
			printf("ingrese operando 2 : ");scanf("%f",& p2);
			printf("desea aproximar 1 = si 2 = no  : ");scanf("%d\n\n",& p3);
			printf("operando 1 : %f  , operando 2 : %f , aproximara : %d",p1,p2,p3);	
			// se llenan los datos del mensaje
			Un_Mensaje.Id_Mensaje = 1;
			Un_Mensaje.operacion = opcion;
			Un_Mensaje.operador1 = p1;
			Un_Mensaje.operador2 = p2;
			Un_Mensaje.aproximacion = p3 ;
			strcpy (Un_Mensaje.Mensaje, "RESTA");
			//se envia el mensaje
			msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.operador1)+sizeof(Un_Mensaje.operador2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.Mensaje)+sizeof(Un_Mensaje.operacion), 
			IPC_NOWAIT);

			break;


			case 3 :

			system("clear");
			printf(" MULTIPLICACION \n");
			printf("ingrese operando 1 : ");scanf("%f",& p1);
			printf("ingrese operando 2 : ");scanf("%f",& p2);
			printf("desea aproximar 1 = si 2 = no  : ");scanf("%d\n\n",& p3);
			printf("operando 1 : %f  , operando 2 : %f , aproximara : %d",p1,p2,p3);	
			// se llenan los datos del mensaje
			Un_Mensaje.Id_Mensaje = 1;
			Un_Mensaje.operacion = opcion;
			Un_Mensaje.operador1 = p1;
			Un_Mensaje.operador2 = p2;
			Un_Mensaje.aproximacion = p3 ;
			strcpy (Un_Mensaje.Mensaje, "MULTIPLICACION");
			//se envia el mensaje
			msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.operador1)+sizeof(Un_Mensaje.operador2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.Mensaje)+sizeof(Un_Mensaje.operacion), 
			IPC_NOWAIT);

			break;


			case 4 :

			system("clear");
			printf(" DIVICION \n");
			printf("ingrese operando 1 : ");scanf("%f",& p1);
			printf("ingrese operando 2 : ");scanf("%f",& p2);
			printf("desea aproximar 1 = si 2 = no  : ");scanf("%d\n\n",& p3);
			printf("operando 1 : %f  , operando 2 : %f , aproximara : %d",p1,p2,p3);	
			// se llenan los datos del mensaje
			Un_Mensaje.Id_Mensaje = 1;
			Un_Mensaje.operacion = opcion;
			Un_Mensaje.operador1 = p1;
			Un_Mensaje.operador2 = p2;
			Un_Mensaje.aproximacion = p3 ;
			strcpy (Un_Mensaje.Mensaje, "DIVICION");
			//se envia el mensaje
			msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.operador1)+sizeof(Un_Mensaje.operador2)+sizeof(Un_Mensaje.aproximacion)+sizeof(Un_Mensaje.Mensaje)+sizeof(Un_Mensaje.operacion), 
			IPC_NOWAIT);

			break;
			
			
			case 5 :
			
		
			system("clear");
			printf(" VER RESULTADOS \n\n");
			printf(" ingrese el no de resultados que desea ver:  \n");
		    scanf("%d",&n);
			
			msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&respuesta,
			sizeof(respuesta.resultado) + sizeof(respuesta.Mensaje) +sizeof(respuesta.operacion), 
			2, 0);
			
			
			
			/*int i;
			for(i=0;i<=n;i++){
			
				
			}*/
			break;

			case 6:
			
			break;
			
			 default:
				system("clear");
				printf("OPCION NO VALIDA");
				a =getchar();
			
			
		}

	}while(opcion!=6);

}
