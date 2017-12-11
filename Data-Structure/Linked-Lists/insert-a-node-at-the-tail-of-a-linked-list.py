"""
 Insert Node at the end of a linked list 
 head pointer input could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node
 
 return back the head of the linked list in the below method
"""

# def Insert(head, data):
#     node = Node(data)
#     while (head.next):
#         head = head.next
#     head.next = node
#     return head

def Insert(head, data):
    if head == None:
        return Node(data, None)
    else:
        if head.next == None:
            head.next = Node(data,None)
        else:
            Insert(head.next,data)
        return head
  
  
  
  
  

