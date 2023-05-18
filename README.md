# Ascensor
Primer parcial

![Circuit design Swanky Inari-Gogo _ Tinkercad - Google Chrome 20_4_2023 20_21_12 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/ed979e49-ee34-48d3-bc89-53a80d067382)

# Circuito del prototipo
compuesto por una resistencia de 220ohm, un display 7 segmentos que informa el piso actual, dos diodos led que informan el estado del mismo y tres botones para las opeaciones que desee el usuario

![Editing ascensor_README md at main · bautista-escalante_ascensor · GitHub - Google Chrome 15_5_2023 18_46_48 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/b46b2634-a429-4126-8e5d-d4dbd049bc02)

### ¿por que una sola resistencia? ¿y las demas?
_en este caso la resistencia esta en serie a cada uno de los diodos ya que todos usan un lado negativo_

# Codigo
  * se definen los pines, contadores y __funciones__ 
  * se declara como salida los pines correspondientes a los led y a el display 7 segmentos
  * se declara como entrada a los pines correspondientes a los pulsadores 
 ``` cpp 
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
 ```

# funciones

### Operar botonera
 esta funcion evalua el boton que el usuario presiono y ejecuta la funcion correspondiente 
``` cpp 
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
```

### Parar sistema
esta funcion corresponde al tercer boton, frena el asensor e informa el estado no deja hacer otra operacion hasta que el boton pulsado de nuevo
``` cpp
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
```

### Encender display 
esta funcion enciende el numero que le pasamos por parametro en el display 7 segmentos 
``` cpp 
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
  
```

tiene 10 case este ultimo es un mensaje de error 
``` cpp
   case 10:
    	//error
    	digitalWrite(A, HIGH);
    	digitalWrite(G, HIGH);  		
     digitalWrite(E, HIGH);
    	digitalWrite(D, HIGH);
     digitalWrite(F, HIGH);
```

### Validar pisos 
verifica que efectivamente este entre el piso 0 y 9 de lo contrario imforma un error en el monitor 
``` cpp 
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
```

### Encender led 
esta funcion enciende un led segun el numero uqe le pasemos por parametro 
``` cpp
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
```

### Apagar
esta funcion apaga todos los leds de el display 7 segmentos y los leds de informe 
``` cpp 
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
```

# Link del proyecto

[https://www.tinkercad.com/things/8MaoRmXMj6S-ascensor/editel](https://www.tinkercad.com/things/8MaoRmXMj6S)



