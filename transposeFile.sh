declare -A matrica
IFS=$'\n' 
a=0
b=0
for j in $(cat ./transpose.txt)   #name age
do
    IFS=" "
    ((b=0))
    for i in $(echo $j) 
    do
	matrica[$a,$b]=$i
	((b++))
    done

    ((a++))
 
done


for ((c=0;c<b;c++))
do
	for ((v=0;v<a;v++))
	do
		
		if (($c == $b-1 && $v==$a-1))
        then
		    echo -n "${matrica[$v,$c]}"
        else
            echo  -n "${matrica[$v,$c]} "
        fi
		
	done
	
	echo ""
done


