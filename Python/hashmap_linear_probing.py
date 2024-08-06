"""
/*****************************************************************************************************************

Implementataion of an hashmap using the linear probing method of open addressing in Python.
Author: Agboola Olamidipupo Favour
Github: https://www.github.com/Olamidipupo-favour
Linkedin: https://www.linkedin.com/in/olamidipupo-agboola-6b3917237/
Portfolio: https://Olamidipupo-favour.github.io/

******************************************************************************************************************/
"""

class HashMap:
    def __init__(self,buckets:int):
        self.__buckets=buckets
        self.__keys=[[None,None] for _ in range(buckets)]

    def hash(self,key:int,m:int)->int:
        return key%3
    
    def add(self,key:int,value:int)->None:
        #add value to hashmap
        index=self.hash(key,self.__buckets)
        if(self.__keys[index][0]==None):
            self.__keys[index][0]=key
            self.__keys[index][1]=value
        else:
            #keep probing linearly.
            while self.__keys[index][0]!=None:
                index+=1
                if(index>=self.__buckets):
                    raise Exception("HashMap is filled up.")
            #once the chain is broken
            self.__keys[index][0]=key
            self.__keys[index][1]=value
    
    def exists(self,key:int)->bool:
        #check if a key exists
        principal_index=self.hash(key,self.__buckets)
        while principal_index<self.__buckets:
            if(key==self.__keys[principal_index][0]):
                return True
            else:
                principal_index+=1
                continue
        return False
    
    def get(self, key:int)->int:
        #return the value 0of a key 
        principal_index=self.hash(key,self.__buckets)
        while principal_index<self.__buckets:
            if(key==self.__keys[principal_index][0]):
                return self.__keys[principal_index][1]
            else:
                principal_index+=1
                continue
        raise Exception("Key not found!")
    
    def remove(self,key:int)->None:
        principal_index=self.hash(key,self.__buckets)
        while self.__keys[principal_index][0]!=key:
            principal_index+=1
            continue
        if(self.__keys[principal_index][0]==key):
            self.__keys[principal_index][0]=None
            self.__keys[principal_index][1]=None
            return
        raise Exception("Key not found!")
    def __str__(self)->str:
        return str(self.__keys)
if __name__=="__main__":
    map=HashMap(10)
    map.add(0,45)
    map.add(12,12)
    #map.remove(12)
    print(map.exists(10))