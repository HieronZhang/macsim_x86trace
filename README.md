Please use Pin 3.13  (version number 56759) for the current trace generator 

How to generate x86 traces
  1. do make (copy libzlib.a in the location )
 (optional)
  1. Simpoint - Mostly we use SimPoint (PinPoint). Follow instruction
     in $PINHOME/source/tools/PinPoints

  2. Otherwise - Fix trace generator module based on your needs. Then,
     pin -t trace_generator.so -- $BIN $ARGS

     [1] Install Pin  (https://software.intel.com/content/www/us/en/develop/articles/pin-a-dynamic-binary-instrumentation-tool.html)
     
     [2] go to macsim/tools/x86_trace_generator directory
     
     [3] export PIN_ROOT and PIN_HOME as the root directory of your pin install and copy libzlib.a
     into $PIN_ROOT/intel64/lib/ and $PIN_ROOT/extras/xed-intel64/lib
     
     [4] make
     
     [5] pin -t obj-intel64/trace_generator.so - $BIN $ARGS 
