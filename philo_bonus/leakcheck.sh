if ! make
then
	exit 1
fi

echo going in 
for i in {1..100}
do
	./philo_bonus 4 210 100 100 1
done
