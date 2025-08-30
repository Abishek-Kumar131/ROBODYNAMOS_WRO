// ########### Front Ultrasonic Array Function ############################################################################################################ //

int fus_array()
{
  if(((f_us <= fus_box_dist) && (f_us != 0)) || 
    ((f1_us <= fus_box_dist) && (f1_us != 0)) || 
    ((f2_us <= fus_box_dist) && (f2_us != 0)) ) { fusa = 1; }

  else{fusa = 0;}

  return fusa;
}
