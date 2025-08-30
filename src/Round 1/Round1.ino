// ########### Round 1 - Open Challenge Main File ############################################################################################################ //

// Global Variables
int line_chk_count = 12;  // 3 Laps - 12 count, 1 Lap - 4 count.
int line_count = 0;// 12

// Bot Speeds
int normal_speed = 230;//pwm
int turn_speed = 245;//pwm
int turn_delay = 2000;//ms

int fus_slow_speed = 200;//pwm
int fus_slow_dist = 130;//cm

// Servo Angles
int servo_center = 100;//deg
int left_turn_angle = servo_center - 25; //80 deg
int right_turn_angle = servo_center + 25;//120 deg

const int blue_line_thold = 8000; //Blue Color Temp value
const int orange_line_thold = 3000; //Orange Color Temp value

bool COLOR_LOCK = 1;
bool lt_st_count = 0;
bool rt_st_count = 0;

bool left_right_arc_turn = 1;
bool left_right_r_turn = 0;

#define DPDT_Push_Button_Pin 34

int col_val, start_col, colour_line;  // colour_line = 1 ->> Orange // colour_line = 3 ->> Blue
int f_us, f1_us, f2_us, b_us, l_us, r_us, fusa, far;

bool LOGIC_LOCK = 1; //1 True state.
bool DPDT_STATE = 0; //0 False state.

void loop() {
  
  DPDT_STATE = digitalRead(DPDT_Push_Button_Pin);

  US_Values(f_us, f1_us, f2_us, b_us, l_us, r_us);

  col_val = front_colour_sensor();

  color_line_fun(); // color line pickup

  
  if (DPDT_STATE == 1) 
  { 
    if (LOGIC_LOCK == 1) 
    { 
      if (col_val != 0)
      {
        color_logic_fun();
      }
      else if (col_val == 0)
      {
        side_us_logic_fun();
      }   
    }     
  }
  else
  {
    bot_shutdown();
  }

  if (line_count == line_chk_count) 
  {
    end_stop();
    bot_shutdown();
    LOGIC_LOCK = 0;
    line_count = 0; 
  }   

}
