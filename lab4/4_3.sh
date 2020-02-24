echo "Input the Strings"

read -a array
echo ${array[@]}

for each in ${array[@]}
do
echo $each
done|sort
