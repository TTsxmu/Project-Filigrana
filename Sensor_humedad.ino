/*******************************************************************************************************
  Autor: Samuel B
  Versión: v0.1.0 - Lectura para 3 sensores
           v0.0.0 - Piloto 
********************************************************************************************************/

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Definir el pin al que está conectado el DHT11
#define DHT1PIN 33
#define DHT2PIN 14
#define DHT3PIN 32

// Seleccionar el tipo de sensor DHT
#define DHTTYPE DHT11

// Crear una instancia del sensor DHT
DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);
DHT dht3(DHT3PIN, DHTTYPE);

float hum1, hum2, hum3;
float temp1, temp2, temp3;
int s1flt, s2flt, s3flt;

void setup() {

  Serial.begin(115200);

// Imprime una secuencia de carga 
  Serial.print("Inicializando sensores "); Serial.print(".");  delay(300); Serial.print(".");  delay(300); Serial.print(".");  delay(300); Serial.println(""); delay(100);

// Iniciar sensores DHT
  dht1.begin(); dht2.begin(); dht3.begin(); 
}

void loop() {

  hum1 = dht1.readHumidity();
  temp1 = dht1.readTemperature();

  hum2 = dht2.readHumidity();       
  temp2 = dht2.readTemperature();

  hum3 = dht3.readHumidity();       
  temp3 = dht3.readTemperature();

//--------------------------------------------------
  if (isnan(temp1) || isnan(hum1))      s1flt= 1;
  if (!(isnan(temp1) || isnan(hum1)))   s1flt= 0;
//--------------------------------------------------
  if (isnan(temp2) || isnan(hum2))      s2flt= 1;
  if (!(isnan(temp2) || isnan(hum2)))   s2flt= 0;
//--------------------------------------------------
  if (isnan(temp3) || isnan(hum3))      s3flt= 1;
  if (!(isnan(temp3) || isnan(hum3)))   s3flt= 0;
//--------------------------------------------------

// Humedad: 00.00%  (TAB \t)  Temperatura: 00.00%
// Sensor 1
  if (s1flt == 0){ Serial.print("Humedad 1º: "); Serial.print(hum1); Serial.print("%\tTemperatura 1º: "); Serial.print(temp1); Serial.println(" °C"); }
  if (s1flt == 1){ Serial.println("Error al leer del sensor DHT1"); }
// Sensor 2
  if (s2flt == 0){ Serial.print("Humedad 2º: "); Serial.print(hum2); Serial.print("%\tTemperatura 2º: "); Serial.print(temp2); Serial.println(" °C"); }
  if (s2flt == 1){ Serial.println("Error al leer del sensor DHT2"); }
// Sensor 3
  if (s3flt == 0){ Serial.print("Humedad 3º: "); Serial.print(hum3); Serial.print("%\tTemperatura 3º: "); Serial.print(temp3); Serial.println(" °C"); }
  if (s3flt == 1){ Serial.println("Error al leer del sensor DHT3"); }
// Separador
  Serial.println("--------------------------------------------------------------------");

// Esperar 5 segundos entre lecturas (el DHT11 tiene una tasa de muestreo lenta)
  delay(5000);
}
