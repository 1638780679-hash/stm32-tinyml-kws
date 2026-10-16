# Cubemx / CubeIDE settings for NUCLEO-F746ZG

Follow these recommended settings when creating the STM32CubeMX .ioc for this project.

1. MCU/Board: NUCLEO-F746ZG
2. Clock: keep default but ensure HCLK high enough (216 MHz if using full speed).
3. Peripherals:
   - SAI or I2S peripheral (depending on microphone): Configure as Receiver (Slave) for I2S input.
   - DMA for RX stream: enable Circular mode, enable TC and HT interrupts (for ping-pong buffering).
   - USART1: 115200 8N1 for printf logging (enable "USART1 global" and associated GPIO TX pin).
   - GPIO: configure a user LED pin as output.
4. Middleware: none required.
5. NVIC: ensure DMA IRQ priority is high enough.
6. Generate code for STM32CubeIDE.

Notes:
- If you use an INMP441 (I2S) microphone, configure the peripheral as I2S Rx mapped to the proper pins (check your breakout wiring).
- For PDM microphones you might use DFSDM or SAI depending on the part — adapt accordingly.
