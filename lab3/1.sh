echo "Input filename"
read filename
	if [ -d "$filename" ]; then 
	echo "Directory"
	else
	echo "File"
fi



