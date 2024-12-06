Please use Pin 3.13  (version number 56759) for the current trace generator 

The modified trace generator tool is located in tools/x86_trace_generator

How to generate x86 traces

     [1] Install Pin  (https://software.intel.com/content/www/us/en/develop/articles/pin-a-dynamic-binary-instrumentation-tool.html)
     
     [2] go to macsim/tools/x86_trace_generator directory
     
     [3] export PIN_ROOT and PIN_HOME as the root directory of your pin install and copy libzlib.a
     into $PIN_ROOT/intel64/lib/ and $PIN_ROOT/extras/xed-intel64/lib
     
     [4] make
     
     [5] pin -t obj-intel64/trace_generator.so - $BIN $ARGS 
