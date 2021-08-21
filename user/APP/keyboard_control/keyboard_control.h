#ifndef KEYBOARD_CONTROL_H
#define KEYBOARD_CONTROL_H

#include "remote_control.h"

#define Time_Start 20//跑多少次触发
#define Time_END 50000//如果超多少则再次触发

typedef struct
{
	uint8_t press_l;
	uint8_t press_r;
	
	uint8_t key_w;
	uint8_t key_s;
	uint8_t key_a;
	uint8_t key_d;
	
	uint8_t key_shift;
	uint8_t key_control;
	
	uint8_t key_q;
	uint8_t key_e;
	uint8_t key_r;
	uint8_t key_f;
	uint8_t key_g;
	uint8_t key_z;
	uint8_t key_x;
	uint8_t key_c;
	uint8_t key_v;
	uint8_t key_b;
	
}key_board_t;

typedef struct
{
	uint16_t press_l;
	uint16_t press_r;
	
	uint16_t key_w;
	uint16_t key_s;
	uint16_t key_a;
	uint16_t key_d;
	
	uint16_t key_shift;
	uint16_t key_control;
	
	uint16_t key_q;
	uint16_t key_e;
	uint16_t key_r;
	uint16_t key_f;
	uint16_t key_g;
	uint16_t key_z;
	uint16_t key_x;
	uint16_t key_c;
	uint16_t key_v;
	uint16_t key_b;
	
}Time_t;

typedef struct
{
	uint8_t press_l;
	uint8_t press_r;
	
	uint8_t key_w;
	uint8_t key_s;
	uint8_t key_a;
	uint8_t key_d;
	
	uint8_t key_shift;
	uint8_t key_control;
	
	uint8_t key_q;
	uint8_t key_e;
	uint8_t key_r;
	uint8_t key_f;
	uint8_t key_g;
	uint8_t key_z;
	uint8_t key_x;
	uint8_t key_c;
	uint8_t key_v;
	uint8_t key_b;
	
}key_board_flag_t;

extern key_board_flag_t key_board_flag;

void keyboard_flag_scan(void);

#endif
