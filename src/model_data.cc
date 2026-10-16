/* model_data.cc - placeholder for model binary converted to C array
 * Replace this with: xxd -i quantized_model.tflite > src/model_data.cc
 */

#include <cstdint>

extern const unsigned char g_model_data[];
extern const unsigned int g_model_data_len;

const unsigned char g_model_data[] = { 0x20, 0x00, 0x00, 0x00 };
const unsigned int g_model_data_len = sizeof(g_model_data);
