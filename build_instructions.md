# Build and model conversion instructions

## Convert a quantized tflite file to C source

On your PC, after generating a quantized_model.tflite file (full-integer quantization), run:

  xxd -i quantized_model.tflite > model_data.cc

Then move model_data.cc into the project's src/ folder (replace the placeholder).

## Typical TensorFlow Lite quantization snippet

```python
import tensorflow as tf

def representative_data_gen():
    for _ in range(100):
        # yield a single input sample as a numpy array with shape (1, ...)
        yield [input_sample]

converter = tf.lite.TFLiteConverter.from_saved_model('saved_model_dir')
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.representative_dataset = representative_data_gen
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

tflite_model = converter.convert()
open('quantized_model.tflite','wb').write(tflite_model)
```

## Compile/Flash
1. Import project into STM32CubeIDE (or copy src/ into generated project).
2. Add TFLite-Micro sources and required headers into the project.
3. Set compiler flags for Cortex-M7 FPU:
   -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16 -O3
4. Build and flash using the IDE.
