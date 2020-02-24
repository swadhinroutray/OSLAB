for f in *.text; do 
 mv -- "$f" "${f%.text}.txt"
done
