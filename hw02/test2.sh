
g++ -Wall -pedantic -Wextra $1

x=0

while [ "$x" -le 16 ];
do  
    echo $x
    ./a.out < "custom/`printf %03d $x`_in.txt" > "custom/tmp.txt"

    diff "custom/tmp.txt" "custom/`printf %03d $x`_out.txt"

    

    if [ $? -ne 0 ];
    then
        echo different
        exit 1
    fi

    rm "custom/tmp.txt"
     x=$((x+1))
done

rm a.out
