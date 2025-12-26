//---Codigo 1: ligando led---//

//---Função Principal---//
void setup() 
{
 //Configura a GPIO15 como saída
 pinMode(15,OUTPUT); 
}
//---Loop Infinito---//
void loop() 
{
 //"Liga" a GPIO15
 digitalWrite(15,HIGH);
 //Pausa o programa
 delay(400);
 //"Liga" a GPIO15
 digitalWrite(15,LOW);
 //Pausa o programa
 delay(400);
}