from abc import ABC
from html.parser import HTMLParser


# create a subclass and override the handler methods
class MyHTMLParser(HTMLParser, ABC):
    def handle_starttag(self, tag, attrs):
        print(tag)
        if attrs:
            for i in range(len(attrs)):
                print("-> " + attrs[i][0] + " > " + str(attrs[i][1]))

    def handle_startendtag(self, tag, attrs):
        print(tag)
        if attrs:
            for i in range(len(attrs)):
                print("-> " + attrs[i][0] + " > " + str(attrs[i][1]))


# instantiate the parser and fed it some HTML
parser = MyHTMLParser()
N = int(input())
html_string = ""
for i in range(N):
    html_string += input().rstrip()+'\n'

parser.feed(html_string)
parser.close()

