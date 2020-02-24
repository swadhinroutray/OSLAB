echo "Input basic and TA"
read basic ta
#GS=` expr $basic + $ta `
#EX=` expr 0.1 \* $basic `
#re=` expr $GS + $EX `
re=$(echo "$basic + $ta + 0.1 * $basic"|bc)
echo "$re"
