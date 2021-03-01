#include "mbed.h"
#include <chrono>
#include <cstdio>

#define TX PA_9
#define RX PA_10
#define BAUDRATE 9600

#define LED3 PB_5
#define LED2 PB_4

#define BTN1 PA_1
#define BTN2 PA_2

using namespace std::chrono_literals;
using namespace std::chrono;

static BufferedSerial uart(TX, RX, BAUDRATE);
static DigitalOut led2(LED2);
static DigitalOut led3(LED3);

static DigitalIn btn1(BTN1);
static DigitalIn btn2(BTN2);
FileHandle *mbed::mbed_override_console(int fd) { return &uart; }

int main() {
  //  float c = 0;
  //  uart.set_blocking(false);
  //  char buf[] = {'T', 'i', 'c', 'k'};
  Timer t;
  t.start();
  int elapsed = 0;
  float koef = 0.5;
  int count = 0;
  while (true) {
    elapsed = duration_cast<milliseconds>(t.elapsed_time()).count();
    if (elapsed >= 120) {
      count++;
      t.reset();
      led2 = !led2;
    }
    if (count == 2) {
      led3 = !led3;
      count = 0;
    }
  }
}

// printf("Tick %f\n", c);
// c += 0.1;

// printf("Please enter value: \n");
// scanf("%f", &c);
// printf("Value is: %f\n", c);
// ThisThread::sleep_for(1s);

// if (uart.readable()){
//     char s = ' ';
//     uart.read(&s, 1);
//     uart.write(&s, 1);
// }

// uart.write(&buf, sizeof(buf));
// ThisThread::sleep_for(1s);
