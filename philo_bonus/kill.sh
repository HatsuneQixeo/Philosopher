if [ $# -eq 0 ]
then
	echo "This script kill every processes found with given argument as the process name"
	exit 1
elif [ $# -gt 1 ]
then
	echo "Too many arguements"
	exit 1
fi

name="$1"
process=$(ps | grep -v grep | grep -v kill.sh | grep "$name")

if [ -z "$process" ]
then
	echo "No existing process: $name"
	exit 1
fi
# echo PROCESS: $process

pid=$(echo "$process" | awk '{print $1}')
# echo PID: $pid

kill $pid
if [ $? -eq 0 ]
then
	echo "Killed$(echo $pid | wc -w) processes"
else
	echo 'Something went wrong with kill'
fi
