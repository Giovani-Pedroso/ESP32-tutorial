#include <stdio.h>
#include"freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void pisca_task(void *pvParameter){

    gpio_pad_select_gpio(GPIO_NUM_12);//configura o pino como gpio
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_OUTPUT);//pino como saida
    printf("okok pisca pisca\n");
    uint8_t cnt=0;

    while(1){
        gpio_set_level(GPIO_NUM_12, cnt%2);//seta o nivel logico
        cnt++;
        vTaskDelay(1000/portTICK_PERIOD_MS);//delay que nao trava o programa
        printf("ok\n");
    }
}

void app_main() {
    xTaskCreate(pisca_task, "arefa_pisca",1024,NULL,5,NULL);//cria task
    printf("começou\n");

}
