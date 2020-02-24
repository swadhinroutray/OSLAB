echo "Input array of files"
read -a array
echo ${array[@]}

for ((j=0;j<${#array[@]};j++))
do
rm -i ${array[$j]}
done
