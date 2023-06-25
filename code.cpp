// C++ code
//ramon bautista escalante
#define A 4
#define B 5
#define C 8
#define D 7
#define E 6
#define F 3
#define G 2
#define boton1 A0
#define boton2 A1
#define boton3 A2
#define ledPausa 12
#define ledAccion 13
int contador=0; 
void ValidarPisos();
void EncenderDisplay(int numero);
void Apagar();
void EncenderLed(int led);
void operarBotonera();
void PararSistema(); 
void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(ledAccion, OUTPUT);
  pinMode(ledPausa, OUTPUT);
  
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  Serial.begin(9600);
}
void loop()
{
    ValidarPisos();
   	PararSistema();
    operarBotonera();
}
void EncenderDisplay(int numero)
{
  switch(numero)
  {
     case 0:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
    	digitalWrite(F, HIGH);
    	break; 
  	case 1:
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
    	break;
    case 2:
        digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 3:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);  		
        digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 4:
    	digitalWrite(B, HIGH);
    	digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 5:
    	digitalWrite(A, HIGH);
    	digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 6:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
     	digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 7:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	break;
    case 8:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;
    case 9:
    	digitalWrite(A, HIGH);
    	digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;  
    case 10:
    	//error
    	digitalWrite(A, HIGH);
    	digitalWrite(G, HIGH);  		
        digitalWrite(E, HIGH);
    	digitalWrite(D, HIGH);
        digitalWrite(F, HIGH);
  	}
  }
void Apagar()
{
    digitalWrite(A ,LOW);  
    digitalWrite(B, LOW);
    digitalWrite(C,LOW);  
    digitalWrite(D, LOW);
    digitalWrite(E,LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(ledAccion,LOW);
    digitalWrite(ledPausa,LOW);
}
void EncenderLed(int led)
{
  if (led==1)
  {
  	digitalWrite(ledAccion, HIGH);
  }
  if (led==2)
  {
  	digitalWrite(ledPausa, HIGH);
  }
}
void operarBotonera()
 {
	int sube =analogRead(boton1);
  	int baja = analogRead(boton2);
    if (sube!=LOW )
    {
      contador++;
      Serial.println("en movimiento");
      delay(200);
      EncenderDisplay(contador);
  	  Serial.println("sube");
      PararSistema();
      EncenderLed(1);
      delay(3000);
      Apagar();
    }
    else if (baja!=LOW )
    {
      PararSistema();
      Serial.println("en movimiento");
      contador--; 
      delay(200);
      EncenderDisplay(contador);
      Serial.println("baja");
      EncenderLed(1);
      delay(3000);
      Apagar();
    }  
 }	
void ValidarPisos()
{
  while (contador<0 || contador>9) 
  {
    if (contador<0) 
    {
      Apagar();
      EncenderDisplay(10);
      EncenderLed(2);
      Serial.println("error. el piso seleccionado no existe, suba");
      delay(1000); 
      contador++;
    }
    else
    {
      Apagar();
      EncenderDisplay(10);
      EncenderLed(2);
      Serial.println("error. el piso seleccionado no existe, baje");
      contador--;
    }
  }
}
void PararSistema()
{
  	 int pausa = analogRead(boton3);
	 while (pausa!=LOW) 
      {
// para que vuelva a funcionar debe precionarse 2 seg el boton3
        Serial.println("sin movimiento"); 
        Serial.println("pausado"); 
        EncenderLed(2); 
        delay(1000);  
        delay(200); 
        int boton= analogRead(boton3);
      	delay(10);
        if (boton!=LOW)
        {
           Apagar();  
           Serial.println("activado para su servicio. elige una operacion");
          delay(1000);
     	   break; 
        }
    }   	   
}
