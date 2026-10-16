# TFLite-Micro integration notes

This repository intentionally does NOT include the full TensorFlow Lite Micro source tree. For licensing and size reasons, add the TFLM sources yourself or use an STM example integration (ST often provides an X-CUBE-AI or TFLite integration package).

Minimal steps to integrate tflite-micro into the project:
1. Clone the tflite-micro repo on your machine:
   git clone https://github.com/tensorflow/tflite-micro.git
2. Identify the minimal set of files you need:
   - tensorflow/lite/micro/*.cc, *.h
   - tensorflow/lite/micro/kernels/*.cc (only the ops your model requires)
   - third_party/flatbuffers/include/flatbuffers
   - tensorflow/lite/schema/*.h
   - Any reference kernels required by your model
3. Copy those files into an "external/tflite_micro" folder in the STM32 project and add the folder to the project includes.
4. Configure compiler flags for Cortex-M7 with FPU (e.g. -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16).
5. Consider using ST's Cube.AI or pre-built ST packages if available — they sometimes integrate TFLM with optimized kernels (CMSIS-NN).

If you want, I can add a minimal subset of TFLM kernel sources to this repo (optionally using CMSIS-NN).