class node:
    def __init__(self,value:int=None,next:'node'=None):
        self.value=value
        self.next=next
    
    def push_front(self,value:int):
        new_node=node(value)
        self.next=new_node
        return new_node
    

    def __repr__(self):
        data=self.next
        str_=""
        while(data.next!=None):
            str_+=f"<-> {data.value}"
        return str_
class linkedList:
    def __init__(self):
        self.latest_node=node()
        ...
    def push_front(self,value:int):
        
if(__name__=="__main__"):
    test_node=node()
    test_node.push_front(12)
    print(test_node)