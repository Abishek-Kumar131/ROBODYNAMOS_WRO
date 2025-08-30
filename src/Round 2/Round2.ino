// ########### Round 2 - Obstacle Challenge Main File ############################################################################################################ //

// Global Variables
int line_chk_count = 12;  // 3 Laps - 12 count, 1 Lap - 4 count.
int line_count = 0;// 12

int normal_speed = 210;//pwm
int turn_speed = 230;//pwm
int turn_delay = 2000;//ms

const int blue_line_thold = 8000; //Blue Color Temp value
const int orange_line_thold = 3000; //Orange Color Temp value

bool left_right_arc_turn = 1;
bool left_right_r_turn = 0;

int fus_box_dist = 30;

// Servo Angles
int servo_center = 100;//deg
int left_turn_angle = servo_center - 20; //80 deg
int right_turn_angle = servo_center + 20;//120 deg

bool lt_st_count = 0;
bool rt_st_count = 0;
int rbox_count = 0;
int gbox_count = 0;

#define DPDT_Push_Button_Pin 34

int col_val, start_col, colour_line; // colour_line = 1 ->> Orange // colour_line = 3 ->> Blue
int f_us, f1_us, f2_us, b_us, l_us, r_us, fusa, far;

bool COLOR_LOCK = 1;//1 Initial True state.
bool LOGIC_LOCK = 1;//1 Initial True state.
bool DPDT_STATE = 0;//0 Initial False state.

char ab;
int serial_count;
bool bd_lock = 1;

const int bufferSize = 1;  
char abd[bufferSize];  

int abdRead;
char red_value = '1';
char green_value = '2';

void loop() 
{
  
  DPDT_STATE = digitalRead(DPDT_Push_Button_Pin);

  get_US_Values(f_us, f1_us, f2_us, b_us, l_us, r_us);

  far = fus_array();

  col_val = get_CS_Values();

  color_line_fun(); // color line pickup

  
  if (DPDT_STATE == 1) 
  { 
    if (LOGIC_LOCK == 1) 
    { 
      box_detection();

      if (col_val != 0)
      {
        color_logic_fun();
      }
      else if (col_val == 0)
      {
        side_us_logic_fun();
      }   

    }
      
  }else{
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
