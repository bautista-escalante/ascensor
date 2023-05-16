# Ascensor
Primer parcial

![Circuit design Swanky Inari-Gogo _ Tinkercad - Google Chrome 20_4_2023 20_21_12 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/ed979e49-ee34-48d3-bc89-53a80d067382)

# Circuito del prototipo
compuesto por un display 7 segmentos que informa el piso actual, dos diodos led que informan el estado del mismo y tres botones para las opeaciones que desee el usuario

![Editing ascensor_README md at main · bautista-escalante_ascensor · GitHub - Google Chrome 15_5_2023 18_46_48 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/b46b2634-a429-4126-8e5d-d4dbd049bc02)

# Codigo
  * se definen los pines, contadores y __funciones__ 
  * se declara como salida los pines correspondientes a los led y a el display 7 segmentos
  * se declara como entrada a los pines correspondientes a los pulsadores 

![sketch_apr1b _ Arduino IDE 2 0 5-nightly-20230401 15_5_2023 19_05_07 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/c769bd69-b281-4f09-9779-05a4d2801ad5)

# funciones

### Operar botonera
 esta funcion evalua el boton que el usuario presiono y ejecuta la funcion correspondiente 

![operar botonera (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/7ebaccbb-c782-4600-8f5c-23839750d2d5)

### Parar sistema
esta funcion corresponde al tercer boton, frena el asensor e informa el estado no deja hacer otra operacion hasta que el boton pulsado de nuevo

![parar sistema (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/14c5854c-86d7-48cc-9fa4-f53c23437c65)

### Encender display 
esta funcion enciende el numero que le pasamos por parametro en el display 7 segmentos 

![encender display (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/ebfabdd4-ca45-4eaf-831e-5584ab71ca57)

tiene 10 case este ultimo es un mensaje de error 

![case 10](https://github.com/bautista-escalante/ascensor/assets/123372673/27fbe103-888b-4e11-ad36-6380586644b6)

### Validar pisos 
verifica que efectivamente este entre el piso 0 y 9 de lo contrario imforma un error en el monitor 

![sketch_apr1b _ Arduino IDE 2 0 5-nightly-20230401 15_5_2023 19_02_58 (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/5dfe970a-24a8-4c28-bb2e-2b9f6c11e9bc)

### Encender led 
esta funcion enciende un led segun el numero uqe le pasemos por parametro 

![encenderled (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/7af02c50-7aa7-4d2f-834e-1e16302f16c8)

### Apagar
esta funcion apaga todos los leds de el display 7 segmentos y los leds de informe 

![apagar (2)](https://github.com/bautista-escalante/ascensor/assets/123372673/e55c1e6e-050f-4185-92e5-902b732c31d0)

# Link del proyecto

https://www.tinkercad.com/things/8MaoRmXMj6S-ascensor/editel



