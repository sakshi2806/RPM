#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "soc/rtc_wdt.h"
#include "esp_task_wdt.h"
#define ir 4
int count = 0;
int a_data_c, a_data_p;
long ts = 0;
long te;
float rpm;
int data_flag = 0;


TaskHandle_t Task1, Task2;


void codeForTask1(void* parameter) {

  vTaskSuspend(NULL);
  for (;;) {
    esp_task_wdt_init(1, false);
    a_data_c = digitalRead(ir);
    if ((a_data_c == 1) && (a_data_p == 0)) {
      count++;
    }
    if (count == 4) {
      te = micros();
      rpm = (60000000.00 / (te - ts));
      data_flag = 1;
      vTaskResume(Task2);
      ts = te;
      count = 0;
    }
    a_data_p = a_data_c;
    //delay(1);
  }
}

void codeForTask2(void* parameter) {
  vTaskSuspend(NULL);
  for (;;) {
    esp_task_wdt_init(1, false);

    if (data_flag == 1) {
      Serial.println(rpm);
      data_flag = 0;
      vTaskSuspend(NULL);
    }
  }
}


void setup() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(codeForTask1, "led1Task", 10000, NULL, 1, &Task1, 0);
  delay(500);  // needed to start-up task1
  xTaskCreatePinnedToCore(codeForTask2, "led2Task", 10000, NULL, 1, &Task2, 1);
  vTaskResume(Task1);
}

void loop() {
  delay(10000);
}
