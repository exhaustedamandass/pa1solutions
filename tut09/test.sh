
g++ -Wall -pedantic -Wextra $1

x=0

while [ "$x" -le 1 ];
do  
    echo $x
    ./a.out < "ENG/`printf %04d $x`_in.txt" > "ENG/tmp.txt"

    diff "ENG/tmp.txt" "ENG/`printf %04d $x`_out.txt"

    

    if [ $? -ne 0 ];
    then
        echo different
        exit 1
    fi

    rm "ENG/tmp.txt"
     x=$((x+1))
done

rm a.out
