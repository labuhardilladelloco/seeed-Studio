#include <bluefruit.h>
String nombre;

void setup() {
  Serial.begin(115200);
  //while ( !Serial ) delay(10); 

  Serial.println("Ejemplo de distancia con smartwatch. lbdl");
  Serial.println("------------------------------------");
 
  //Inicializar Bluefruit con conexiones máximas como Periféricos = 0, central = 1
  // El uso de SRAM requerido aumentará drásticamente con la cantidad de conexiones
  Bluefruit.begin(0, 1);
  Bluefruit.setTxPower(4);    // Consulte bluefruit.h para conocer los valores admitidos
  Bluefruit.setName("lbdl");
  Bluefruit.setConnLedInterval(250);
  Bluefruit.Scanner.setRxCallback(scan_callback);
  Bluefruit.Scanner.restartOnDisconnect(true);

  BLEUuid uuid = BLEUuid(0xFEE0);              //Uuid de mi SmartWatch (0xFEE0) modificar por el vuestro.
  Bluefruit.Scanner.filterUuid(uuid);          // solo invoque la devolución de llamada si detecta el servicio bleuart con el uuid definido
  Bluefruit.Scanner.setInterval(100, 100);     // en unidades de 0,625 ms
  Bluefruit.Scanner.useActiveScan(true);       // Solicitar datos de respuesta de escaneo
  Bluefruit.Scanner.start(0);                  // 0 = No dejar de escanear después de n segundos

  Serial.println("Escaneando ...");
}

void scan_callback(ble_gap_evt_adv_report_t* report)
{

    Serial.print("SmartWatch RSSI --> ");
    Serial.println(report->rssi);
    
    if(report->rssi >= -40){
      analogWrite(A0,LOW); 
      analogWrite(A1,LOW);
      analogWrite(A2,255); //Azul
    }
    
    if(report->rssi < -40 && report->rssi >= -50){
      analogWrite(A0,LOW);
      analogWrite(A1,255); //Verde
      analogWrite(A2,LOW);
    }
    
    if(report->rssi < -50){
      analogWrite(A0,255); //Rojo
      analogWrite(A1,LOW);
      analogWrite(A2,LOW);
    }
    
  // Necesitamos llamar a Scanner resume() para continuar escaneando
  Bluefruit.Scanner.resume();
}







void loop() 
{

}
