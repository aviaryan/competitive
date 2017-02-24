$regex = '^[a-zA-Z]+|([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\2\s+\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\3\s+\2\s+\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\4\s+\3\s+\2\s+\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\5\s+\4\s+\3\s+\2\s+\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\6\s+\5\s+\4\s+\3\s+\2\s+\1|([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+)\s+([a-zA-Z]+\s+)?\7\s+\6\s+\5\s+\4\s+\3\s+\2\s+\1$';


$regex = '^([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+|)?\s*([a-zA-Z]+\s+)?\7\s*\6\s*\5\s*\4\s*\3\s*\2\s*\1$';
# $regex = '^a|b$';
$test = <STDIN> ;
if($test =~ /$regex/){
    print "true";
} else {
    print "false";
}