egrep '^([a-zA-Z]+\s*[a-zA-Z]*\s*[a-zA-Z]*), ([a-zA-Z]+), (1[0-9]{2}), [0-9]+, ([0-9]{4})-([0-9]{4}), (.*)$' rezultati.csv -h -o \
| sed -r 's/^([a-zA-Z]+\s*[a-zA-Z]*\s*[a-zA-Z]*), ([a-zA-Z]+), (1[0-9]{2}), [0-9]+, ([0-9]{4})-([0-9]{4}), /\1 (\2) [\4-\5] /' \
| sed -r 's/, /->/g' \
