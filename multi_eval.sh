while read p; do
  echo $p | $1
done < $2
