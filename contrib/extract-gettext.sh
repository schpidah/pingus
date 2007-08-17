#!/bin/sh

OUTPUTFILE="/tmp/leveltexts.txt"
TMPFILE=`tempfile`

if [ -e $OUTPUTFILE ]; then
    echo "$OUTPUTFILE exist, move it out of the way please."
    exit 1;
else
    echo "### Levelnames and description, automatically  extracted from levelfiles" > $OUTPUTFILE
    echo "" >> $OUTPUTFILE

    for filename in ../data/levels/tutorial/*.xml; do
        echo "Extracting text from $filename"
        shortname=`basename $filename`
        xalan \
            -PARAM filename "'$shortname'" \
            -IN $filename \
            -OUT $TMPFILE \
            -TEXT \
            -Q \
            -XSL extract-gettext.xsl
        cat $TMPFILE >> $OUTPUTFILE
    done

    echo "### EOF ###" >> $OUTPUTFILE
fi

# EOF #