# Read from the file file.txt and output the tenth line to stdout.

# Solution 1
# Note: `head -10 file.txt | tail -1` is wrong when file.txt has less than 10 lines
tail -n +10 file.txt | head -1

# Solution 2
sed -n '10p' file.txt

# Solution 3
count=0
while read line && [ $count -lt 10 ]; do
    let 'count+=1'
    if [ $count -eq 10 ]; then
        echo $line
        exit 0
    fi
done < file.txt
