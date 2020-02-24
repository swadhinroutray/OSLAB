grep "^ ex: \| .ex:" file1.txt | sed "s/ex:/EXAMPLE/g" file1.txt >> file2.txt
