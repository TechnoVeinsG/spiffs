#ifndef __SPIFFS_EEPROM_H__
#define __SPIFFS_EEPROM_H__

#include <EEPROM.h>

#define NAME_SIZE         100
#define DEFAULT_GENDER    0
#define DEFAULT_USERNAME  "テクノべインズ"

typedef struct {
  int gender;
  char username[NAME_SIZE + 1];
} EEPROM_Person;

typedef struct {
  EEPROM_Person person;
} EEPROM_struct;

/* EEPROMから一括して読み出す */
void getEEPROM(void);
/* EEPROMに一括して書き出す */
void setEEPROM(void);
/* EEPROMデータをJSON形式で返す */
String getEepromJson(void);

#endif
