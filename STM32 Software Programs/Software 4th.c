#include <stdint.h>
#include <stdio.h>

void byte_to_bit(uint8_t in[8], uint8_t *out)
{
  for (int i=0; i<8; i++){
	if(in[7-i]){
	  *out |= (1<<i);
	}else{
	  *out &= ~(1<<i);
	}
  }
}
void bit_to_byte(uint8_t *in, uint8_t out[8])
{
  for (int i=0; i<8; i++){
  	out[7-i] = *in+i & 1;
  }
}

int main() {
    uint8_t in[8] = {1, 0, 1, 0, 1, 0, 1, 0}; // 输入数组
    uint8_t out = 0; // 输出字节
    
    uint8_t in2 = 170; // 输入字节
    uint8_t out2[8] = {0}; // 输出数组 

    byte_to_bit(in, &out);
    bit_to_byte(&in2, out2);

    printf("Output byte: \n%u\n", out); // 输出结果

	printf("Output array:\n");
	for (int i=0; i<8; i++){
		printf("%d ", out2[i]);
	}

    return 0;
}