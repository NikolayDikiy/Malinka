#include <Q2HX711.h>

const byte hx711_data_pin = 3; //Данные с усилителя
const byte hx711_clock_pin = 2; //Тактовый генератор для усилителя
const int analogOutPin = 9; //Аналоговый вывод на индикатор
int outputValue = 0; //Значения для аналогового индикатора

Q2HX711 hx711(hx711_data_pin, hx711_clock_pin); //Запускаем усилитель

void setup() {
  Serial.begin(9600);
}

//float count = 0;
//long val = 0;
long weight = 0;


void loop() {
  //Функция усреднения значений для калибровки
  //count = count + 1;
  //val = ((count-1)/count) * val + (1/count) * hx711.read();
  //zero: 8461555
  //5kg: 9814711
  //scale: 274.06f
  //val = constrain(hx711.read(), 8461554, 9818710);
  //delay(2);
  //weight = map(val, 8461555, 9818711, 0, 5000); //Считаем вес

  //Старый метод вычисления веса
  weight = (hx711.read() - 8461555) / 272.56;
  //weight = constrain(weight, 0, 5000);
  //weight = 0.5 * weight + 0.5 * count;
  
  outputValue = map(weight, 0, 5000, 0, 255); //Считаем значения для аналогового индикатора
  outputValue = constrain(outputValue, 0 ,255);
  analogWrite(analogOutPin, outputValue); //Выводим на аналоговый индикатор 0-5В
/*
  //Выводим данные в COM порт
  Serial.print("HX711 Value: ");
  Serial.print(hx711.read());
  //Serial.print(" Val: ");
  //Serial.print(val);
  Serial.print(" Weight: ");
  Serial.print(weight);
  Serial.print("g outputValue: ");
  Serial.println(outputValue);*/
}
