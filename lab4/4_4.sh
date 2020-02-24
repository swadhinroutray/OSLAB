echo "Enter a file "
read name
echo "1. word count 2.Line Count 3. Char count "
read choice

case $choice in 
1)wc $name -w;;
2)wc $name -l;;
3)wc $name -c;; 
esac
