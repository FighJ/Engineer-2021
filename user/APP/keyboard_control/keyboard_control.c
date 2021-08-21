#include "keyboard_control.h"

key_board_t key_board;
key_board_flag_t key_board_flag;
Time_t Time;

void keyboard_flag_scan(void)
{
	if (rc_ctrl.mouse.press_l)
  {
		if (Time.press_l < Time_END)
    {
      Time.press_l++;
    }
  }
  else
  {
    Time.press_l = 0;
  }
	if(Time.press_l == Time_Start)
	{
	  key_board_flag.press_l =! key_board_flag.press_l;
	}
	
	
	if (rc_ctrl.mouse.press_r)
  {
		if (Time.press_r < Time_END)
    {
      Time.press_r++;
    }
  }
  else
  {
    Time.press_r = 0;
  }
	if(Time.press_r == Time_Start)
	{
	  key_board_flag.press_r =! key_board_flag.press_r;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_W)
  {
		if (Time.key_w < Time_END)
    {
      Time.key_w++;
    }
  }
  else
  {
    Time.key_w = 0;
  }
	if(Time.key_w == Time_Start)
	{
	  key_board_flag.key_w = !key_board_flag.key_w;
		
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_S)
  {
		if (Time.key_s < Time_END)
    {
      Time.key_s++;
    }
  }
  else
  {
    Time.key_s = 0;
  }
	if(Time.key_s == Time_Start)
	{
	  key_board_flag.key_s =! key_board_flag.key_s;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_A)
  {
		if (Time.key_a < Time_END)
    {
      Time.key_a++;
    }
  }
  else
  {
    Time.key_a = 0;
  }
	if(Time.key_a == Time_Start)
	{
	  key_board_flag.key_a =! key_board_flag.key_a;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_D)
  {
		if (Time.key_d < Time_END)
    {
      Time.key_d++;
    }
  }
  else
  {
    Time.key_d = 0;
  }
	if(Time.key_d == Time_Start)
	{
	  key_board_flag.key_d =! key_board_flag.key_d;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_SHIFT)
  {
		if (Time.key_shift < Time_END)
    {
      Time.key_shift++;
    }
  }
  else
  {
    Time.key_shift = 0;
  }
	if(Time.key_shift == Time_Start)
	{
	  key_board_flag.key_shift =! key_board_flag.key_shift;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_CTRL)
  {
		if (Time.key_control < Time_END)
    {
      Time.key_control++;
    }
  }
  else
  {
    Time.key_control = 0;
  }
	if(Time.key_control == Time_Start)
	{
	  key_board_flag.key_control =! key_board_flag.key_control;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_Q)
  {
		if (Time.key_q < Time_END)
    {
      Time.key_q++;
    }
  }
  else
  {
    Time.key_q = 0;
  }
	if(Time.key_q == Time_Start)
	{
	  key_board_flag.key_q =! key_board_flag.key_q;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_E)
  {
		if (Time.key_e < Time_END)
    {
      Time.key_e++;
    }
  }
  else
  {
    Time.key_e = 0;
  }
	if(Time.key_e == Time_Start)
	{
	  key_board_flag.key_e =! key_board_flag.key_e;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_R)
  {
		if (Time.key_r < Time_END)
    {
      Time.key_r++;
    }
  }
  else
  {
    Time.key_r = 0;
  }
	if(Time.key_r == Time_Start)
	{
	  key_board_flag.key_r =! key_board_flag.key_r;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_F)
  {
		if (Time.key_f < Time_END)
    {
      Time.key_f++;
    }
  }
  else
  {
    Time.key_f = 0;
  }
	if(Time.key_f == Time_Start)
	{
	  key_board_flag.key_f =! key_board_flag.key_f;
	}
	
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_G)
  {
		if (Time.key_g < Time_END)
    {
      Time.key_g++;
    }
  }
  else
  {
    Time.key_g = 0;
  }
	if(Time.key_g == Time_Start)
	{
	  key_board_flag.key_g =! key_board_flag.key_g;
	}
	

	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_Z)
  {
		if (Time.key_z < Time_END)
    {
      Time.key_z++;
    }
  }
  else
  {
    Time.key_z = 0;
  }
	if(Time.key_z == Time_Start)
	{
	  key_board_flag.key_z =! key_board_flag.key_z;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_X)
  {
		if (Time.key_x < Time_END)
    {
      Time.key_x++;
    }
  }
  else
  {
    Time.key_x = 0;
  }
	if(Time.key_x == Time_Start)
	{
	  key_board_flag.key_x =! key_board_flag.key_x;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_C)
  {
		if (Time.key_c < Time_END)
    {
      Time.key_c++;
    }
  }
  else
  {
    Time.key_c = 0;
  }
	if(Time.key_c == Time_Start)
	{
	  key_board_flag.key_c =! key_board_flag.key_c;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_V)
  {
		if (Time.key_v < Time_END)
    {
      Time.key_v++;
    }
  }
  else
  {
    Time.key_v = 0;
  }
	if(Time.key_v == Time_Start)
	{
	  key_board_flag.key_v =! key_board_flag.key_v;
	}
	
	if (rc_ctrl.key.v & KEY_PRESSED_OFFSET_B)
  {
		if (Time.key_b < Time_END)
    {
      Time.key_b++;
    }
  }
  else
  {
    Time.key_b = 0;
  }
	if(Time.key_b == Time_Start)
	{
	  key_board_flag.key_b =! key_board_flag.key_b;
	}
}
