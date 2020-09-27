//Definição dos pin's responsáveis pelos respectivos Push Buttons
const int botA = A3; // esquerda
const int botB = A2; // direita
const int botC = A1;  // cima
const int botD = A0;  // baixo

const int joyN = 3; // norte
const int joyS = 4; //sul
const int joyL = 2;  //leste
const int joyO = 5;  //oeste

const int ledR = 13; // esquerda
const int ledY = 12; // direita
const int ledG = 11;  // cima
const int ledB = 10;  // baixo

char bytelido;
int espera=10;

void setup()
{
   Serial.begin(9600);
   pinMode(botA, INPUT);
   pinMode(botB, INPUT);
   pinMode(botC, INPUT);
   pinMode(botD, INPUT);

   pinMode(joyN, INPUT);
   pinMode(joyS, INPUT);
   pinMode(joyL, INPUT);
   pinMode(joyO, INPUT);




   pinMode(ledR, OUTPUT);
   pinMode(ledY, OUTPUT);
   pinMode(ledG, OUTPUT);
   pinMode(ledB, OUTPUT);

   // I M P O R T A N T E
// para garantir que inicia com alto, ou não pressionado
// lembrar que quando em zero significa pressionado !!!

   digitalWrite(botA, HIGH);
   digitalWrite(botB, HIGH);
   digitalWrite(botC, HIGH);
   digitalWrite(botD, HIGH);

   digitalWrite(joyN, HIGH);
   digitalWrite(joyS, HIGH);
   digitalWrite(joyL, HIGH);
   digitalWrite(joyO, HIGH);
}

//Método de Leitura Constante do Estado dos Push Butons
void loop()
{
   if(digitalRead(botA) == LOW)
   {
      Serial.write('a');
      Serial.flush();
      delay(espera);
   }
   
   if(digitalRead(botB) == LOW)
   {
      Serial.write('b');
      Serial.flush();
      delay(espera);
   }
   if(digitalRead(botC) == LOW)
   {
      Serial.write('c');
      Serial.flush();
      delay(espera);
   }
   if(digitalRead(botD) == LOW)
   {
      Serial.write('d');
      Serial.flush();
      delay(espera);
   }

 if(digitalRead(joyN) == LOW)
   {
      Serial.write('n');
      Serial.flush();
      delay(espera);
   }
   
   if(digitalRead(joyS) == LOW)
   {
      Serial.write('s');
      Serial.flush();
      delay(espera);
   }
   if(digitalRead(joyL) == LOW)
   {
      Serial.write('l');
      Serial.flush();
      delay(espera);
   }
   if(digitalRead(joyO) == LOW)
   {
      Serial.write('o');
      Serial.flush();
      delay(espera);
   }



if (Serial.available()>0)
{   
   bytelido=Serial.read();

       if (bytelido=='r'){
       digitalWrite(ledR, 1);       
       digitalWrite(ledY, 0);       
       digitalWrite(ledG, 0);       
       digitalWrite(ledB, 0);       
   }
       if (bytelido=='g'){
       digitalWrite(ledR, 0);       
       digitalWrite(ledY, 0);       
       digitalWrite(ledG, 1);       
       digitalWrite(ledB, 0);       
   }
       if (bytelido=='b'){
       digitalWrite(ledR, 0);       
       digitalWrite(ledY, 0);       
       digitalWrite(ledG, 0);       
       digitalWrite(ledB, 1);       
   }
       if (bytelido=='y'){
       digitalWrite(ledR, 0);       
       digitalWrite(ledY, 1);       
       digitalWrite(ledG, 0);       
       digitalWrite(ledB, 0);       
   }
       if (bytelido=='x'){
       digitalWrite(ledR, 0);       
       digitalWrite(ledY, 0);       
       digitalWrite(ledG, 0);       
       digitalWrite(ledB, 0);       
   }

       if (bytelido=='a'){
       digitalWrite(ledR, 1);       
       digitalWrite(ledY, 1);       
       digitalWrite(ledG, 1);       
       digitalWrite(ledB, 1);       
   }
 }
}
