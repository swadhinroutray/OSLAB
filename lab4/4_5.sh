echo "Input Pattern"
read pattern
echo "1.Search 2.Delete Occurences 3. Exit"
read ch
echo "Input filename"
read name
case $ch in 
1)grep $pattern $name | wc -l ;;
2) `sed /$pattern/d $name >> file1.txt` ;;
3)exit 1;;
esac
