if [ $# -eq 4 ]
then
	echo "This script is not designed for infinite loop"
	return 1
fi

out="$(./philo $@)"

if [ $? -ne 0 ]
then
	return 1
elif [ -n "$(grep died <<< "$out")" ]
then
	cat <<< "$out"
	return 1
fi

for (( i = 1 ; i <= $1; i++ ))
do
	echo "$i has eaten $(grep " $i is eating" <<< "$out" | wc -l | awk '{print $1}') times"
done

echo "total: $(grep "is eating" <<< "$out" | wc -l)"
pbcopy <<< "$out"
