//si usas arduino ide comentar esta línea.
//#include <Arduino.h>

// esp32
#include <HTTPClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiManager.h>
#include <WebServer.h>
// lcd i2c
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//esp8266
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266HTTPClient.h>

const char* ssid = "#";
const char* password =  "#";

String ALARMA = "1";

LiquidCrystal_I2C lcd(0x27, 16, 2);

cont int botonPin = 8;
int estadoBoton;

void setup() {
  delay(10);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(500);
    Serial.print(".");
  }
  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());
  pinMode(botonPin, INPUT);
  lcd.begin();
  lcd.createChar(0, customChar);
  lcd.home();
}

void loop() {
  segundoBotonPresionado = false;
  estado = digitalRead(pinBoton);
  
  while (estado == HIGH && segundoBotonPresionado == false) {
    ALERTA();
    digitalWrite(pinLed, HIGH);
    delay(500);
    digitalWrite(pinLed, LOW);
    delay(500);
    
    if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
    HTTPClient http;
    String datos_a_enviar = ALARMA

    http.begin("#");        //Indicamos el destino
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); //Preparamos el header text/plain si solo vamos a enviar texto plano sin un paradigma llave:valor.

    int codigo_respuesta = http.POST(datos_a_enviar);   //Enviamos el post pasándole, los datos que queremos enviar. (esta función nos devuelve un código que guardamos en un int)

    if(codigo_respuesta>0){
      Serial.println("Código HTTP ► " + String(codigo_respuesta));   //Print return code

      if(codigo_respuesta == 200){
        String cuerpo_respuesta = http.getString();
        Serial.println("El servidor respondió ▼ ");
        Serial.println(cuerpo_respuesta);
      }
    }else{
     Serial.print("Error enviando POST, código: ");
     Serial.println(codigo_respuesta);
    }
    http.end();  //libero recursos
    }else{
     Serial.println("Error en la conexión WIFI");
    }
    delay(2000);
    estado2 = digitalRead(pinBoton);
    
    if (estado2 == HIGH) {
      segundoBotonPresionado = true;
    }
  }
  digitalWrite(pinled2, HIGH);
  delay(1000);
  digitalWrite(pinled2, LOW);
  delay(1000);
}
void ALERTA(){
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("ALERTA");
  lcd.setCursor(0,1);
  lcd.print("ALERTA");
}

