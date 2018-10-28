egrep '.*' desetaLinija.txt -h -o \
| egrep '.*' -n \
| egrep '^10:.*$' \
| sed -r 's/10:/''/'
