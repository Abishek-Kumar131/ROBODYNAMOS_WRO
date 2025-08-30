// ########### Buffer Limit Function ############################################################################################################ //

void buffer_limit()
{
  while(Serial.available() > 0)
  {
    abdRead = Serial.readBytesUntil(red_value, abd, bufferSize);
    abdRead = Serial.readBytesUntil(green_value, abd, bufferSize);
    
    abd[abdRead] = '\0';
  }

}
