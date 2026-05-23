
#!/bin/bash
filesdir=$1
searchstr=$2


if [ "$#" -lt 2 ]
then
	echo "Insufficient arguments "
	exit 1
else
	if [ ! -d "$filesdir" ]
	then
		echo $filesdir "is not a directory"
		exit 1
	else
		x=$(find "$filesdir" -type f | wc -l)
		y=$(grep -r "$searchstr" "$filesdir" | wc -l)

		echo "The number of files are $x and the number of matching lines  are $y"
	fi

fi
