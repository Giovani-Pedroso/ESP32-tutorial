#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



void printTerminal(void *pvParameter){

    while(1){
    vTaskDelay(500/portTICK_PERIOD_MS);
    printf("Ola, Hola, Hello, Konnichiwa");
    }
}



void app_main(){

    xTaskCreate(printTerminal,//funçao que ira rodar
               "print",//nome para debug
                1024,//memoria alocada
                NULL,
                5,//prioridate
                NULL);

    vTaskDelete(NULL);


}
