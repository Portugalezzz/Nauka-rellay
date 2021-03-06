#include <Arduino.h>

/*
 * Скетч для управления реле с помощью ардуино
 * Используем реле SONGLE SRD-05VDC
 * Реле ОТКРЫВАЕТСЯ при подаче низкого уровня сигнала (LOW) на управляющий пин.
 * Реле ЗАКРЫВАЕТСЯ при подаче высокого уровня сигнала (HIGH) на управляющий пин.
 * 
 * В данном примере мы просто открываем и закрываем реле раз в 5 секунд.
 * 
 * PIN_RELAY содержит номер пина, к которому подключено реле, которым мы будем управлять 
 * 
 * В функции setup устанавливаем начальное положение реле (закрытое)
 * Если к реле будет подключена нагрузка(например, лампочка), то после запуска скетча она будет включаться и выключаться каждые 5 секунд
 * 
 * Для изменения периода мигания нужно изменить параметр функции delay(): поставив 1000 миллисекунд, выполучите 1 секунду задержки
 * 
 * В реальных проектах реле включается в ответ на обнаружение каких-либо внешних событий через подключение датчиков 
 * 
 */

#define PIN_RELAY 13
#define SECOND_PIN_RELAY 6 // Определяем пин, используемый для подключения реле

// В этой функции определяем первоначальные установки
void setup()
{
  pinMode(PIN_RELAY, OUTPUT); // Объявляем пин реле как выход
  digitalWrite(PIN_RELAY, LOW);
  pinMode(SECOND_PIN_RELAY, OUTPUT); // Объявляем пин реле как выход
  digitalWrite(SECOND_PIN_RELAY, HIGH); // Выключаем реле - посылаем высокий сигнал
}
void loop()
{
  delay(6000);
  digitalWrite(PIN_RELAY, HIGH); // Включаем реле - посылаем низкий уровень сигнала
  digitalWrite(SECOND_PIN_RELAY, LOW); // Отключаем реле - посылаем высокий уровень сигнала
  delay(1000);
  digitalWrite(PIN_RELAY, LOW); // Включаем реле - посылаем низкий уровень сигнала
  digitalWrite(SECOND_PIN_RELAY, HIGH); // Отключаем реле - посылаем высокий уровень сигнала
  
}