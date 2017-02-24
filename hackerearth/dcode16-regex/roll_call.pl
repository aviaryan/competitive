# Enter regular expression here. Regex must be in one line only.
# [a-zA-Z]+\s*
$regex = '^ ( W+ | (W+)\s*(W+\s*)?\1 | (W+)\s*(W+)\s*(W+\s*)?\2\s*\1 | (W+)\s*(W+)\s*(W+)\s*(W+\s*)?\3\s*\2\s*\1 |
 (W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+\s*)?\4\s*\3\s*\2\s*\1 | (W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+\s*)?\5\s*\4\s*\3\s*\2\s*\1 | 
 (W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+\s*)?\6\s*\5\s*\4\s*\3\s*\2\s*\1 | (W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+)\s*(W+\s*)?\7\s*\6\s*\5\s*\4\s*\3\s*\2\s*\1 ) $';
$test = <STDIN> ;
if($test =~ /$regex/){
    print "true";
} else {
    print "false";
}