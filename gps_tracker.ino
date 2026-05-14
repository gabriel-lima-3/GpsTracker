#include <TinyGPS++.h>
#include <math.h>

#define GPS_BAUDRATE 9600

TinyGPSPlus gps;

// Coordenada de destino
const double DEST_LAT = -1.452993170517731;
const double DEST_LNG = -48.49474005125091;

// Fórmula de Haversine para calcular distância entre 2 coordenadas
double haversine(double lat1, double lon1, double lat2, double lon2) {
  const double R = 6371.0; // raio da Terra em km
  double dLat = radians(lat2 - lat1);
  double dLon = radians(lon2 - lon1);
  lat1 = radians(lat1);
  lat2 = radians(lat2);

  double a = sin(dLat / 2) * sin(dLat / 2) +
             sin(dLon / 2) * sin(dLon / 2) * cos(lat1) * cos(lat2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  return R * c; // distância em km
}

void setup() {
  Serial.begin(9600);
  Serial2.begin(GPS_BAUDRATE, SERIAL_8N1, 4, 2);

  Serial.println(F("ESP32 - GPS module"));
}

void loop() {
  if (Serial2.available() > 0) {
    if (gps.encode(Serial2.read())) {
      if (gps.location.isValid()) {
        double lat = gps.location.lat();
        double lng = gps.location.lng();

        Serial.print(F("- latitude: "));
        Serial.println(lat, 8);

        Serial.print(F("- longitude: "));
        Serial.println(lng, 8);

        Serial.print(F("- altitude: "));
        if (gps.altitude.isValid())
          Serial.println(gps.altitude.meters(), 2);
        else
          Serial.println(F("INVALID"));

        Serial.print(F("- speed: "));
        if (gps.speed.isValid()) {
          double speed = gps.speed.kmph();
          Serial.print(speed, 2);
          Serial.println(F(" km/h"));

          // Cálculo de distância até o destino
          double distancia = haversine(lat, lng, DEST_LAT, DEST_LNG);
          Serial.print(F("- distância até o destino: "));
          Serial.print(distancia, 2);    
          Serial.println(F(" km"));      
          

          // Cálculo do tempo estimado (em minutos e segundos)
          if (speed > 0) {
            double tempo_horas = distancia / speed;
            double tempo_min = tempo_horas * 60.0;

            int minutos = (int)tempo_min;
            int segundos = (int)((tempo_min - minutos) * 60);

            Serial.print(F("- tempo estimado até o destino: "));
            Serial.print(minutos);
            Serial.print(F(" min "));
            Serial.print(segundos);
            Serial.println(F(" s"));
          } else {
            Serial.println(F("- velocidade zero: impossível estimar tempo"));
          }
        } else {
          Serial.println(F("INVALID"));
        }

        Serial.print(F("- GPS date&time: "));
        if (gps.date.isValid() && gps.time.isValid()) {
          Serial.print(gps.date.year());
          Serial.print(F("-"));
          Serial.print(gps.date.month());
          Serial.print(F("-"));
          Serial.print(gps.date.day());
          Serial.print(F(" "));
          Serial.print(gps.time.hour());
          Serial.print(F(":"));
          Serial.print(gps.time.minute());
          Serial.print(F(":"));
          Serial.println(gps.time.second());
        } else {
          Serial.println(F("INVALID"));
        }

        Serial.println();
      } else {
        Serial.println(F("- location: INVALID"));
      }
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS data received: check wiring"));
  }


}
