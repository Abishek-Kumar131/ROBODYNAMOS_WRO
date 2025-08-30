// ########### Box Detection Function ############################################################################################################ //

void box_detection()
{
  motor_forward(normal_speed);
   // Check if data available on serial port
    if((far == 1) && (Serial.available() > 0))  
    { 
      ab = Serial.read();
      serial_count++;
    }
    else
    {
      ab = 'n';
      buffer_limit();  //[*]
    }

    if((ab == '1') && (far == 1)) // Red Box
    {
      rgb_led(0, 0, 0); 
      rgb_led(255, 0, 0);
      rbox_count++;

        motor_backward(220);
        delay(1500);
        motor_forward(220);
        moveServoTo(right_turn_angle); // Right Turn
        delay(2000);
        moveServoTo(left_turn_angle);  // Left Turn
        delay(2000);
        moveServoTo(servo_center);
        rgb_led(0, 0, 0);

        //Event - 1
        // moveServoTo(right_turn_angle); 
        // delay(1500);
        // moveServoTo(left_turn_angle); 
        // delay(1500);
        // moveServoTo(servo_center);

     

      buffer_limit(); //[*]
    } 

    if((ab == '2') && (far == 1)) // Green Box
    {
      rgb_led(0, 0, 0); 
      rgb_led(0, 255, 0); 
      gbox_count++;

      motor_backward(220);
      delay(1500);
      motor_forward(220);
      moveServoTo(left_turn_angle);  // Left Turn
      delay(2000);
      moveServoTo(right_turn_angle); // Right Turn
      delay(2000);
      moveServoTo(servo_center);

      // moveServoTo(left_turn_angle); 
      // delay(1500);
      // moveServoTo(right_turn_angle); 
      // delay(1500);
      // moveServoTo(servo_center);

      rgb_led(0, 0, 0); 

      buffer_limit(); //[*]
    }
            
}
