egrep '^[0-9]{2}.[0-9]{2}.[0-9]{2}\s(mi1[0-9]{4})\s([A-Z][a-z]+ [A-Z][a-z]+)\s([0-9].[0-9]{2}|1[0-4].[0-9]{2})\s([0-9]{1,2}.[0-9]{2})\s([0-9]{1,2}.[0-9]{2})\s([a-z0-9]{2,4})$' *.txt -h -o \
| sort -k 3 \
| sed -r 's/^[0-9]{2}.[0-9]{2}.[0-9]{2}\s(mi1[0-9]{4})\s([A-Z][a-z]+ [A-Z][a-z]+)\s([0-9].[0-9]{2}|1[0-4].[0-9]{2})\s([0-9]{1,2}.[0-9]{2})\s([0-9]{1,2}.[0-9]{2})\s([a-z0-9]{2,4})$/\2 \1 \6 \5 \4/' \

