if [ $# -eq 4 ]
then
	echo "This script is not designed for infinite loop"
	exit 1
fi

output=$(./philo $1 $2 $3 $4 $5)

if [ $? -ne 0 ]
then
	for line in "$output"
	do
		echo "$line"
	done
	exit 1
fi

if [ $# -eq 5 ]
then
	total=$(echo "$output" | grep eating | wc -l)
	mean=$(($total / $1))
	echo "Total meal eaten: $total"
	if [ $mean -eq $5 ]
	then
		echo "Everybody has eaten $5 times"
	else
		echo "The average(mean) of meal eaten is $mean"
	fi
fi

