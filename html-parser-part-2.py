from abc import ABC
from html.parser import HTMLParser


# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser, ABC):

    def handle_comment(self, data):
        total_line = len(data.split('\n'))
        if total_line > 1:
            print(">>> Multi-line Comment")
        else:
            print(">>> Single-line Comment")
        if data.strip():
            print(data)

    def handle_data(self, data):
        if data.rstrip():
            print(">>> Data")
            print(data)


# instantiate the parser and fed it some HTML
parser = MyHTMLParser()
N = int(input())
html_string = ""
for i in range(N):
    html_string += input().rstrip()+'\n'

parser.feed(html_string)
parser.close()

