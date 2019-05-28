#include "spiffs.h"

const IPAddress ip(192, 168, 5, 1);
const IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(HTTPD_PORT);
EEPROM_struct eeprom;

void setup() {
  
  Serial.begin(9600);
  while(!Serial) {
    ; // シリアルポートの準備ができるのを待つ
  }

  // SPIFFS 初期設定
  SPIFFS.begin();

  // EEPROM 初期設定
  EEPROM.begin(sizeof(eeprom));

  // EEPROMに保存された性別・名前をRAMに読み込む
  getEEPROM();

  // Wi-Fi接続
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, ip, subnet);  
  WiFi.softAP(WIFI_SSID, WIFI_PWD, WIFI_CHANNEL);
  Serial.print(F("Wi-Fi SSID: "));Serial.println(WIFI_SSID);
  Serial.print(F("Wi-Fi Password: "));Serial.println(WIFI_PWD);
  Serial.print(F("AP IP address: "));Serial.println(WiFi.softAPIP().toString());

  // HTTP 初期設定
  setupHttpd();

}

void loop() {

  // クライアントからの要求を処理
  server.handleClient();
  
}
