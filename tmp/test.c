#include <stdio.h>
#include <RTI.hh>

int main(int argc,char **argv)
      {
             RTI::RTIambassador rtiAmb;

                if (RTI_MAJOR_VERSION!=1 ||
                                RTI_MINOR_VERSION!=3)
                         { printf("(%d.%d.%d) ",
                                          RTI_MAJOR_VERSION,RTI_MINOR_VERSION,0);
                                  return 1;
                                       }
                   return 0;

                     }

