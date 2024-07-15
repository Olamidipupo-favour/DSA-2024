"""
/*****************************************************************************************************************

Implementataion of a linked list in Python.
Author: Agboola Olamidipupo Favour
Github: https://www.github.com/Olamidipupo-favour
Linkedin: https://www.linkedin.com/in/olamidipupo-agboola-6b3917237/
Portfolio: https://Olamidipupo-favour.github.io/

******************************************************************************************************************/
"""
class node:
    def __init__(self,value:int=None,head:'node'=None,tail:'node'=None):
        self.value=value
        self.head=head
        self.tail=tail
    
    
class linkedList:
    def __init__(self):
        self.__node=None

    def push_front(self,value:int)->None:
        if(self.__node==None):
            self.__node=node(value)
        
        else:
            new_node=node(value,tail=self.__node)
            self.__node=new_node
        
    
    def push_back(self, value:int)->None:
        pass

    def pop_front(self)->int:
        if(self.__node==None):
            raise Exception()
        popped=self.__node.value
        self.__node=self.__node.tail
        return popped
    
    def __str__(self):
        if(self.__node==None):
            return "[]"
        str_="["
        curr_node=self.__node
        while curr_node !=None:
            str_+=f"{str(curr_node.value)},"
            curr_node=curr_node.tail
        str_+="]"
        return str_
        
    def __len__(self):
        if(self.__node==None):
            return 0
        i=0
        curr_node=self.__node
        while(curr_node!=None):
            i+=1
            curr_node=curr_node.tail
        return i
if(__name__=="__main__"):
    test_list=linkedList()
    test_list.push_front(1)
    test_list.push_front(2)
    test_list.push_front(3)
    test_list.push_front(4)
    test_list.push_front(5)
    test_list.push_front(6)
    print(test_list.pop_front())