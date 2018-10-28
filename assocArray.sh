#K=baz
#MYMAP[$K]=quux
#declare -A MYMAP=( [foo a]=bar [baz b]=quux )
#$ echo "${!MYMAP[@]}"   
#echo "${!MYMAP[@]}"    # Use a variable as key to put a value into an associative array
declare -A names
names=(
    [John]=Doe
    [Jane]=Doe
    [Jim]=Smith
    [Angela]=Merkel
)

declare -A mapa

for i in $(cat ./wordFreq.txt)
do
	
	mapa[$i]="0"

done


for i in $(cat ./wordFreq.txt)
do
    count=${mapa[$i]}
    mapa[$i]="0$count"
    	
done


for i in "${!mapa[@]}"
do
    word=$i
    count=${mapa[$i]}
    echo "$word : $count" >> countedWords.txt
done

egrep '.*' countedWords.txt -h -o \
| sed -r 's/ : [0]+//' \
| sort -k2 -r \
| egrep '.*' -n \
 


