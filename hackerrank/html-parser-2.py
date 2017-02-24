from html.parser import HTMLParser

# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        if data.strip():
            if data.find('\n') != -1:
                print('>>> Multi-line Comment')
            else:
                print(">>> Single-line Comment")
            print(data)
    def handle_data(self, data):
        if data.strip():
            print('>>> Data')
            print(data)

# instantiate the parser and fed it some HTML
n = int(input())
s = ''
for i in range(n): s += input() + '\n'

parser = MyHTMLParser()
parser.feed(s)