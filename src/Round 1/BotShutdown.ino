// ########### Bot Shutdown Function ############################################################################################################ //

void bot_shutdown()
{
  motor_stop();
  moveServoTo(servo_center);
  rgb_led(0, 0, 0);
}
