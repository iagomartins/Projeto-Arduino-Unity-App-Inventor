#include <SoftwareSerial.h>
SoftwareSerial Serial_2(8, 7);// RX, TX
char entrada = '0';
int tempo=5;

void setup() {
        Serial.begin(9600);     // abre a porta serial a 9600 bps
        Serial_2.begin(9600);            
        }

void loop() {

        //Lista de entradas

        
       // comunica com o BT e recebe um valor lido a/A, b/B, c/C ou d/D                
        if (Serial_2.available() > 0)
        {
                //lê o dado
                entrada = Serial_2.read();                
               //retorna pelo BT o valor recebido               
                Serial_2.print(entrada);
                //Lista de entradas
        if (entrada=='g')
        {
           Serial.write('g');
           delay(tempo);
           Serial.flush();
        }
        if (entrada=='e')
        {
           Serial.write('e');
           delay(tempo);
           Serial.flush();
        }  
        if (entrada=='r')
        {
           Serial.write('r');
           delay(tempo);
           Serial.flush();
        }  
        if (entrada=='c')
        {
           Serial.write('c');
           delay(tempo);
           Serial.flush();
        }              
        }
}
