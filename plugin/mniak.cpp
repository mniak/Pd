#include "m_pd.h"  
import <string>;

// std::string generateWord();

import muslib;

static t_class *mniak_class;  
 
typedef struct _mniak {  
  t_object x_obj;
} t_mniak;  
 
void mniak_bang(t_mniak *x)  
{
  (void)x; // silence unused variable warning
  post(generateWord().c_str());
}  
 
void *mniak_new(void)  
{  
  t_mniak *x = (t_mniak *)pd_new(mniak_class);  
  return (void *)x;  
}  


extern "C" {
  void mniak_setup(void);
}

void mniak_setup(void) {  
  mniak_class = class_new(
      gensym("mniak"), 
      (t_newmethod)mniak_new, 
      NULL, 
      sizeof(t_mniak), 
      CLASS_DEFAULT, 
      (t_atomtype)0);  
  class_addbang(mniak_class, mniak_bang);  
}

