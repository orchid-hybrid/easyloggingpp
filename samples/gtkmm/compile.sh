## Helper script for build_all.sh

FILE=$1

macro="$macro -D_ELPP_THREAD_SAFE"
macro="$macro -D_ELPP_STL_LOGGING"
macro="$macro -D_ELPP_STACKTRACE_ON_CRASH"

if [ "$2" = "" ];then
  COMPILER=g++
else
  COMPILER=$2
fi

CXX_STD='-std=c++0x -pthread'

if [ "$FILE" = "" ]; then
  echo "Please provide filename to compile"
  exit
fi

echo "Compiling... [$FILE]"

COMPILE_LINE="$COMPILER $FILE `pkg-config --libs --cflags gtkmm-2.4 sigc++-2.0` -o bin/$FILE.bin $macro $CXX_STD -Wall -Wextra -I/usr/include/x86_64-linux-gnu/c++/4.7/"
echo "    $COMPILE_LINE"

$($COMPILE_LINE)

echo "    DONE! [./bin/$FILE.bin]"
echo
echo
