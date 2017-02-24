from html.parser import HTMLParser

# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print("Start :", tag)
        for attr in attrs:
        	print('->', attr[0], '>', attr[1])
    def handle_endtag(self, tag):
        print("End   :", tag)
    def handle_startendtag(self, tag, attrs):
        print("Empty :", tag)
        for attr in attrs:
        	print('->', attr[0], '>', attr[1])

# instantiate the parser and fed it some HTML
n = int(input())
s = ''
for i in range(n): s += input() + '\n'

parser = MyHTMLParser()
parser.feed(s)