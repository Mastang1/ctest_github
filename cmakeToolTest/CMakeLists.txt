########################################################
#测试cmake macro 和 function区别
#
if (0)
set(var "ABC")

macro(Moo arg)
  message("arg = ${arg}")
  set(arg "abc")
  message("# After change the value of arg.")
  message("arg = ${arg}")
endmacro()
message("=== Call macro ===")
Moo(${var})

function(Foo arg)
  message("arg = ${arg}")
  set(arg "abc")
  message("# After change the value of arg.")
  message("arg = ${arg}")
endfunction()
message("=== Call function ===")
Foo(${var})
endif(0)
########################################################
#
#* * * * * * * * 测试宏
macro(arg_test para1 para2)
        MESSAGE(STATUS ARGC=${ARGC})
        MESSAGE(STATUS ARGV=${ARGV})
        MESSAGE(STATUS ARGN=${ARGN})
        MESSAGE(STATUS ARGV0=${ARGV0})
        MESSAGE(STATUS ARGV1=${ARGV1})
        MESSAGE(STATUS ARGV2=${ARGV2})
endmacro()
 
set(arg_1 1)
set(arg_2 2)
set(arg_3 3)
#* * * * * * * * * * * * * * * * * * * * * * * * *