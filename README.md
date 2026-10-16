# STM32 TinyML Keyword Spotting — NUCLEO-F746ZG (Engineering Skeleton)

This repository contains a runnable engineering skeleton for running a TinyML keyword-spotting demo on the NUCLEO-F746ZG board. It includes example firmware source files (main.c, audio.c), a placeholder model_data.cc, CubeMX/CubeIDE integration instructions, and build/flash guidance.

This skeleton is intended as a starting point — you still need to add the TensorFlow Lite for Microcontrollers sources (or an ST-provided integration), and replace the placeholder model with a quantized .tflite converted to a C array (model_data.cc).

Quick start
1. Clone the repo:
   git clone https://github.com/1638780679-hash/stm32-tinyml-kws.git
2. Open STM32CubeIDE and create/import a NUCLEO-F746ZG project. Follow stm32cube/README_CubeMX.md for recommended .ioc settings.
3. Copy files from src/ into the STM32CubeIDE project (or replace the auto-generated main.c/audio.c).
4. Add TensorFlow Lite Micro source files (see tflite/README.md) and set compiler options (Cortex-M7, FPU, -O3).
5. Convert your quantized model to a C array and replace src/model_data.cc (see build_instructions.md).
6. Build, flash, open serial at 115200, and test with an I2S MEMS microphone.

If you want, I can also push a pre-converted small quantized demo model into the repo (public) or add the minimal tflite-micro sources into a vendor/ folder. Reply and I'll add them.
