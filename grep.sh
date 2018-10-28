egrep '<td>[a-zA-Z]+\s*[a-zA-Z]+</td><td>[0-9]{1,3}/[0-9]{4}</td>' nastava*.html -h -o \
| sed -r 's/<td>//g' \
| sed -r 's/<\/td>/ /g' \
| sed -r 's/([a-zA-Z]+) ([a-zA-Z]+)/\2 \1/' \
| sed -r 's/([0-9]{1,3})\/[0-9]{2}([0-9]{2})/mi\2\1/' \
| sort -k2 \
| egrep '.*' -n \
