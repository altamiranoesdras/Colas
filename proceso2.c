#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//Estructura mensajes que se reciben
typedef struct s1{
	long Id_Mensaje;
	int operacion;
	float operando1;
	float operando2;
	char operador[1];
	int aproximacion;
}Mensaje1;

//Estructura mensajes enviados
typedef struct s2
{
	long Id_Mensaje;
	float resultado;
	int operacion;
	char Mensaje[10];
} Mensaje2;

int main(){
	system("clear");
	printf("proceso 2 iniciado\n" );
	//printf("=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	
	float p1,p2,p3;
	char aproxStr[2];
	
	key_t Clave1;
	int Id_Cola_Mensajes;
	Mensaje1 Un_Mensaje;
	Mensaje2 sd;
	int contador; 
	
	Clave1 = ftok ("/bin/ls", 33);
	if (Clave1 == (key_t)-1){
		printf("Error al obtener clave para cola mensajes");
		exit(-1);
	}

	Id_Cola_Mensajes = msgget (Clave1, 0600 | IPC_CREAT);
	if (Id_Cola_Mensajes == -1){
		printf("Error al obtener identificador para cola mensajes");
		exit (-1);
	}
	
	do{
		printf("Esperando mensajes...\n");
		
		
	
		msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, 
			sizeof(Un_Mensaje.Id_Mensaje)+sizeof(Un_Mensaje.operacion)+sizeof(Un_Mensaje.operando1)+sizeof(Un_Mensaje.operando2)+sizeof(Un_Mensaje.operacion)+sizeof(Un_Mensaje.aproximacion),
			1, 0);
		
		//si la operacion es salir
		if(Un_Mensaje.operacion==6){
			printf("\nProceso 1 fue detenido!! \n");
			break;
			
		}
		else{
			contador++;
			
			if(Un_Mensaje.aproximacion==1)
				strcpy(aproxStr,"SI");
			else
				strcpy(aproxStr,"NO");
			
			printf("\nMensaje recibido\n");
			printf("Operación: %d \n",Un_Mensaje.operacion);
			printf("Operador 1 = %f\n",Un_Mensaje.operando1);
			printf("Operacion = %s \n",Un_Mensaje.operador);
			printf("Operador 2 = %f\n",Un_Mensaje.operando2);
			printf("Aproximacion = %s\n\n",aproxStr);
			
			p1=Un_Mensaje.operando1;
			p2=Un_Mensaje.operando2;
			
			switch(Un_Mensaje.operacion){
				case 1:
					p3=p1+p2;
					sd.Id_Mensaje=2;
					sd.resultado =p3;
					sd.operacion=1;
					strcpy (sd.Mensaje, "suma");
					
					msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
							sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
							IPC_NOWAIT);
				break;
			
				case 2:
				p3=p1-p2;
				sd.Id_Mensaje=2;
				sd.resultado =p3;
				sd.operacion=2;
				strcpy (sd.Mensaje, "resta");
				
				msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
						sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
						IPC_NOWAIT);
				break;
			
				case 3:
				p3=p1*p2;
				sd.Id_Mensaje=2;
				sd.resultado =p3;
				sd.operacion=3;
				strcpy (sd.Mensaje, "multiplicacion");
				
				msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
						sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
						IPC_NOWAIT);
				
				break;
			
				case 4:
				p3=p1/p2;
				sd.Id_Mensaje=2;
				sd.resultado =p3;
				sd.operacion=4;
				strcpy (sd.Mensaje, "divicion");
				
				msgsnd (Id_Cola_Mensajes, (struct msgbuf *)&sd, 
						sizeof(sd.resultado)+sizeof(sd.operacion)+sizeof(sd.Mensaje), 
						IPC_NOWAIT);
				break;	
			
			}
		
		}

	}while(1);
	

}


